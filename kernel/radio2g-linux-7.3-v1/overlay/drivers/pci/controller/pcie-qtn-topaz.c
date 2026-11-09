// SPDX-License-Identifier: GPL-2.0-only
/*
 * PCIe root complex support for Quantenna Topaz/QSR1000.
 *
 * The OEM 2.6.35 driver treated the endpoint configuration aperture as a
 * 32-bit-only window at 0xcf000000.  This port deliberately preserves the
 * link, iATU and BAR setup established by Bootbase.  It registers a modern
 * PCI host bridge only after the existing link state is coherent.
 */

#include <linux/bitfield.h>
#include <linux/irq.h>
#include <linux/irqdomain.h>
#include <linux/sizes.h>
#include <linux/delay.h>
#include <linux/io.h>
#include <linux/module.h>
#include <linux/of.h>
#include <linux/of_pci.h>
#include <linux/pci.h>
#include <linux/platform_device.h>
#include <linux/iopoll.h>
#include <linux/spinlock.h>

#define TOPAZ_SYSCTL_CSR		0x014
#define TOPAZ_SYSCTL_PCIE_STAT		0x17c

#define TOPAZ_CSR_PCIE_DLINK		BIT(8)
#define TOPAZ_CSR_PCIE_PHYLINK		BIT(9)
#define TOPAZ_CSR_PCIE_RESET_REQ	BIT(11)
#define TOPAZ_CSR_PCIE_FATAL_ERR	BIT(15)
#define TOPAZ_CSR_PCIE_LINKS		(TOPAZ_CSR_PCIE_DLINK | \
					 TOPAZ_CSR_PCIE_PHYLINK)

#define TOPAZ_PCIE_LINKUP_MASK		GENMASK(2, 0)
#define TOPAZ_PCIE_LINKUP_VALUE		GENMASK(2, 0)
#define TOPAZ_PCIE_CFG_BYTES_PER_FN	0x100
#define TOPAZ_PCIE_MAX_SLOT		1
#define TOPAZ_PCIE_BAR0			0x10

struct topaz_pcie {
	struct device *dev;
	void __iomem *cfg;
	void __iomem *sysctl;
	int irq;
	raw_spinlock_t cfg_lock;
};

static int topaz_pcie_wait_link(struct topaz_pcie *pcie)
{
	u32 csr;
	u32 stat;
	int ret;

	/* Match the OEM pcibios.c contract: TOPAZ_PCIE_STAT[2:0] is the
	 * authoritative RC endpoint-up indication.  The SYSCTL CSR link bits
	 * are not used by the OEM scanner and are only retained as telemetry.
	 */
	ret = readl_poll_timeout(pcie->sysctl + TOPAZ_SYSCTL_PCIE_STAT, stat,
				 (stat & TOPAZ_PCIE_LINKUP_MASK) ==
				 TOPAZ_PCIE_LINKUP_VALUE, 1000, 1000000);
	csr = readl(pcie->sysctl + TOPAZ_SYSCTL_CSR);
	dev_info(pcie->dev, "PCIe state csr=%08x stat=%08x\n", csr, stat);
	if (ret)
		return ret;
	if (csr & (TOPAZ_CSR_PCIE_RESET_REQ | TOPAZ_CSR_PCIE_FATAL_ERR))
		return -EIO;

	return 0;
}

static void __iomem *topaz_pcie_map_bus(struct pci_bus *bus,
					unsigned int devfn, int where)
{
	struct topaz_pcie *pcie = bus->sysdata;

	if (bus->number != 0 || PCI_SLOT(devfn) > TOPAZ_PCIE_MAX_SLOT)
		return NULL;
	if (where < 0 || where >= TOPAZ_PCIE_CFG_BYTES_PER_FN)
		return NULL;

	return pcie->cfg + (devfn << 8) + where;
}

static int topaz_pcie_read_config(struct pci_bus *bus, unsigned int devfn,
				  int where, int size, u32 *value)
{
	void __iomem *addr;
	u32 word;

	if ((size != 1 && size != 2 && size != 4) ||
	    (where & (size - 1)) ||
	    where + size > TOPAZ_PCIE_CFG_BYTES_PER_FN)
		return PCIBIOS_BAD_REGISTER_NUMBER;

	addr = topaz_pcie_map_bus(bus, devfn, where & ~3);
	if (!addr) {
		*value = ~0U;
		return PCIBIOS_DEVICE_NOT_FOUND;
	}

	word = readl(addr);
	if (size == 1)
		*value = (word >> (8 * (where & 3))) & 0xff;
	else if (size == 2)
		*value = (word >> (8 * (where & 2))) & 0xffff;
	else
		*value = word;

	return PCIBIOS_SUCCESSFUL;
}

static int topaz_pcie_write_config(struct pci_bus *bus, unsigned int devfn,
				   int where, int size, u32 value)
{
	struct topaz_pcie *pcie = bus->sysdata;
	void __iomem *addr;
	unsigned long flags;
	u32 shift;
	u32 mask;
	u32 word;
	u32 bar0;

	if ((size != 1 && size != 2 && size != 4) ||
	    (where & (size - 1)) ||
	    where + size > TOPAZ_PCIE_CFG_BYTES_PER_FN)
		return PCIBIOS_BAD_REGISTER_NUMBER;

	addr = topaz_pcie_map_bus(bus, devfn, where & ~3);
	if (!addr)
		return PCIBIOS_DEVICE_NOT_FOUND;

	raw_spin_lock_irqsave(&pcie->cfg_lock, flags);
	if (size != 4) {
		shift = 8 * (where & 3);
		mask = (size == 1 ? 0xffU : 0xffffU) << shift;
		word = (readl(addr) & ~mask) | ((value << shift) & mask);
	} else {
		word = value;
	}

	/* Preserve the 32-bit config-write workaround from the OEM host. */
	if ((uintptr_t)addr & BIT(2)) {
		bar0 = readl(pcie->cfg + TOPAZ_PCIE_BAR0);
		writel(word, pcie->cfg + TOPAZ_PCIE_BAR0);
		writel(word, addr);
		writel(bar0, pcie->cfg + TOPAZ_PCIE_BAR0);
	} else {
		writel(word, addr);
	}
	raw_spin_unlock_irqrestore(&pcie->cfg_lock, flags);

	return PCIBIOS_SUCCESSFUL;
}

static struct pci_ops topaz_pcie_ops = {
	.map_bus = topaz_pcie_map_bus,
	.read = topaz_pcie_read_config,
	.write = topaz_pcie_write_config,
};

static int topaz_pcie_map_irq(const struct pci_dev *pdev, u8 slot, u8 pin)
{
	struct pci_host_bridge *bridge = pci_find_host_bridge(pdev->bus);
	struct topaz_pcie *pcie = pci_host_bridge_priv(bridge);

	return pcie->irq;
}

static int topaz_pcie_probe(struct platform_device *pdev)
{
	struct device *dev = &pdev->dev;
	struct pci_host_bridge *bridge;
	struct topaz_pcie *pcie;
	struct resource *cfg_res;
	struct resource *sysctl_res;
	int irq;
	int ret;
	struct irq_data *irqdata;

	/*
	 * Resolve the parent IRQ before devm_pci_alloc_host_bridge().  The latter
	 * parses and requests the DT PCI windows.  If platform_get_irq() defers
	 * after that allocation, a second probe sees our own 0xc0000000 window as
	 * busy and fails permanently with -EBUSY instead of completing the defer.
	 */
	irq = platform_get_irq(pdev, 0);
	if (irq < 0)
		return dev_err_probe(dev, irq, "failed to map preserved INTx IRQ\n");

	irqdata = irq_get_irq_data(irq);
	if (!irqdata || irqdata->hwirq != 28 || !irqdata->domain ||
	    !of_device_is_compatible(irq_domain_get_of_node(irqdata->domain),
	                             "snps,arc700-intc"))
		return -EINVAL;

	bridge = devm_pci_alloc_host_bridge(dev, sizeof(*pcie));
	if (!bridge)
		return -ENOMEM;

	pcie = pci_host_bridge_priv(bridge);
	pcie->dev = dev;
	raw_spin_lock_init(&pcie->cfg_lock);

	cfg_res = platform_get_resource_byname(pdev, IORESOURCE_MEM, "config");
	sysctl_res = platform_get_resource_byname(pdev, IORESOURCE_MEM,
						  "sysctl");
	if (!cfg_res || !sysctl_res)
		return dev_err_probe(dev, -EINVAL,
				     "missing config or sysctl resource\n");
	if (cfg_res->start != 0xcf000000 || resource_size(cfg_res) != SZ_64K ||
	    sysctl_res->start != 0xe0000000 || resource_size(sysctl_res) != 0x200)
		return dev_err_probe(dev, -EINVAL,
				     "register resource is too small\n");

	pcie->cfg = devm_pci_remap_cfg_resource(dev, cfg_res);
	if (IS_ERR(pcie->cfg))
		return PTR_ERR(pcie->cfg);

	/* SYS_CTL is shared with the interrupt controller and diagnostics. */
	pcie->sysctl = devm_ioremap(dev, sysctl_res->start,
				    resource_size(sysctl_res));
	if (!pcie->sysctl)
		return -ENOMEM;

	ret = topaz_pcie_wait_link(pcie);
	if (ret)
		return dev_err_probe(dev, ret,
				     "PCIe endpoint did not reach OEM link-up state\n");

	pcie->irq = irq;

	bridge->sysdata = pcie;
	bridge->ops = &topaz_pcie_ops;
	/* All legacy INTx pins converge on the preserved Topaz IRQ28 route. */
	bridge->map_irq = topaz_pcie_map_irq;
	bridge->swizzle_irq = pci_common_swizzle;
	bridge->preserve_config = 1;
	bridge->no_ext_tags = 1;

	platform_set_drvdata(pdev, bridge);
	ret = pci_host_probe(bridge);
	if (ret)
		return dev_err_probe(dev, ret, "PCI host probe failed\n");

	dev_info(dev,
		 "registered Bootbase-preserving host bridge, INTx IRQ %d\n",
		 pcie->irq);
	return 0;
}

static const struct of_device_id topaz_pcie_of_match[] = {
	{ .compatible = "qtn,topaz-pcie-host" },
	{ }
};
MODULE_DEVICE_TABLE(of, topaz_pcie_of_match);

static struct platform_driver topaz_pcie_driver = {
	.driver = {
		.name = "qtn-topaz-pcie",
		.of_match_table = topaz_pcie_of_match,
		.suppress_bind_attrs = true,
	},
	.probe = topaz_pcie_probe,
};
builtin_platform_driver(topaz_pcie_driver);

MODULE_AUTHOR("OpenMitraStar project");
MODULE_DESCRIPTION("Quantenna Topaz Bootbase-preserving PCIe host bridge");
MODULE_LICENSE("GPL");
