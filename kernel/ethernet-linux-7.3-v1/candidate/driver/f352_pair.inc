/* SPDX-License-Identifier: GPL-2.0-only */
static void f352_link_work(struct work_struct *work)
{
 struct qtn_topaz_emac *emac=container_of(to_delayed_work(work),struct qtn_topaz_emac,link_work);
 u32 speed,value;bool full;int ret;
 if(!READ_ONCE(emac->link_polling))return;
 /* ndo_stop holds RTNL while cancelling this worker: never wait on RTNL. */
 if(!rtnl_trylock())goto again;
 if(!netif_running(emac->ndev)||!READ_ONCE(emac->link_polling))goto unlock;
 ret=qtn_emac_phy_decode(emac,emac->phy_addr,&speed,&full);
 if(ret){emac->phy_link_valid=false;netif_carrier_off(emac->ndev);goto unlock;}
 if(!emac->phy_link_valid||speed!=emac->active_speed||full!=emac->active_full_duplex){
  /* OEM emac_lib_adjust_speed changes only this MAC and its GMII field. */
  emac->active_speed=speed;emac->active_full_duplex=full;
  qtn_emac_program_gmii_clock(emac);
  value=qtn_emac_read(emac,QTN_EMAC_MAC_GLOBAL_CTRL);
  value&=~(QTN_EMAC_MAC_SPEED_MASK|QTN_EMAC_MAC_FULL_DUPLEX);
  value|=speed==1000?QTN_EMAC_MAC_SPEED_1000:(speed==100?QTN_EMAC_MAC_SPEED_100:QTN_EMAC_MAC_SPEED_10);
  if(full)value|=QTN_EMAC_MAC_FULL_DUPLEX;
  qtn_emac_write(emac,QTN_EMAC_MAC_GLOBAL_CTRL,value);
 }
 emac->phy_link_valid=true;netif_carrier_on(emac->ndev);
unlock:
 rtnl_unlock();
again:
 if(READ_ONCE(emac->link_polling))schedule_delayed_work(&emac->link_work,msecs_to_jiffies(500));
}

static ssize_t lyoko_emac_port_stats_show(struct device *dev,
 struct device_attribute *attr,char *buf)
{return qtn_emac_stats(to_net_dev(dev),buf);}
static DEVICE_ATTR_RO(lyoko_emac_port_stats);

static int f352_create_port(void *context,unsigned index)
{
 struct f352_pair *pair=context;struct device *dev=pair->dev;
 struct qtn_topaz_emac *emac;struct net_device *ndev;int ret;
 ndev=alloc_netdev(sizeof(*emac),"eth%d",NET_NAME_ENUM,qtn_emac_setup);
 if(!ndev)return -ENOMEM;
 SET_NETDEV_DEV(ndev,dev);emac=netdev_priv(ndev);emac->dev=dev;emac->ndev=ndev;emac->pair=pair;
 spin_lock_init(&emac->tx_lock);INIT_DELAYED_WORK(&emac->irq_poll_work,qtn_emac_irq_poll_work);
 INIT_DELAYED_WORK(&emac->link_work,f352_link_work);netif_napi_add_weight(ndev,&emac->napi,qtn_emac_poll,QTN_TOPAZ_EMAC_NAPI_WEIGHT);
 emac->ports[0]=pair->ports[index];emac->port_count=1;emac->active_port=0;
 emac->regs=emac->ports[0].regs;emac->irq=emac->ports[0].irq;emac->mac_id=emac->ports[0].mac_id;emac->phy_addr=emac->ports[0].phy_addr;
 emac->mdio_regs=pair->ports[1].regs;emac->sysctl_regs=pair->sysctl_regs;
 emac->phy_autoneg=true;emac->fixed_speed=1000;emac->irq_poll_fallback=true;
 ndev->irq=emac->irq;eth_hw_addr_set(ndev,pair->addresses[index]);
 ret=qtn_emac_alloc_rings(emac);if(ret)goto napi;
 ret=register_netdev(ndev);if(ret)goto rings;
 ret=device_create_file(&ndev->dev,&dev_attr_lyoko_emac_port_stats);if(ret)goto unregister;
 pair->ndev[index]=ndev;return 0;
unregister:
 unregister_netdev(ndev);
rings:
 qtn_emac_free_rings(emac);
napi:
 netif_napi_del(&emac->napi);free_netdev(ndev);return ret;
}
static void f352_destroy_port(void *context,unsigned index)
{
 struct f352_pair *pair=context;struct net_device *ndev=pair->ndev[index];struct qtn_topaz_emac *emac;
 if(!ndev)return;
 emac=netdev_priv(ndev);device_remove_file(&ndev->dev,&dev_attr_lyoko_emac_port_stats);
 unregister_netdev(ndev);WRITE_ONCE(emac->link_polling,false);cancel_delayed_work_sync(&emac->link_work);
 cancel_delayed_work_sync(&emac->irq_poll_work);qtn_emac_free_rings(emac);netif_napi_del(&emac->napi);free_netdev(ndev);pair->ndev[index]=NULL;
}
static int qtn_emac_probe(struct platform_device *pdev)
{
 static const char *const names[2]={"emac1","emac0"};
 static const u32 bases[2]={QTN_TOPAZ_EMAC1_BASE,QTN_TOPAZ_EMAC0_BASE};
 static const u32 irqs[2]={QTN_TOPAZ_IRQ_EMAC1,QTN_TOPAZ_IRQ_EMAC0};
 struct device *dev=&pdev->dev;struct resource *res;struct f352_pair *pair;
 struct f352_lifecycle ops;u8 address[ETH_ALEN];struct irq_data *irqdata;u32 ids[2],phys[2],reset;unsigned i;int ret;
 if(!of_machine_is_compatible("mitrastar,hgw-500bna-qcv2")||!of_property_read_bool(dev->of_node,"qtn,eth73-dual-direct"))return -ENODEV;
 if(of_property_read_u32_array(dev->of_node,"qtn,phy-addresses",phys,2)||of_property_read_u32_array(dev->of_node,"qtn,mac-ids",ids,2))return -EINVAL;
 if(ids[0]!=1||ids[1]!=0||phys[0]!=3||phys[1]!=1)return -EINVAL;
 pair=devm_kzalloc(dev,sizeof(*pair),GFP_KERNEL);if(!pair)return -ENOMEM;
 pair->dev=dev;mutex_init(&pair->mdio_lock);spin_lock_init(&pair->clock_lock);
 ret=of_get_mac_address(dev->of_node,address);
 if(ret)return ret;
 if(!is_valid_ether_addr(address))return -EINVAL;
 ether_addr_copy(pair->addresses[0],address);
 ret=f352_secondary_mac(pair->addresses[0],pair->addresses[1]);if(ret)return ret;
 /* OEM shared MDIO is on MAC0. Validate all DT tuples before any MMIO. */
 for(i=0;i<2;i++){
  res=platform_get_resource_byname(pdev,IORESOURCE_MEM,names[i]);
  if(!res||res->start!=bases[i]||resource_size(res)!=0x400)return -EINVAL;
  ret=platform_get_irq_byname(pdev,names[i]);if(ret<0)return ret;
  irqdata=irq_get_irq_data(ret);
  if(!irqdata||irqdata->hwirq!=irqs[i]||!irqdata->domain||
     !of_device_is_compatible(irq_domain_get_of_node(irqdata->domain),"snps,arc700-intc"))return -EINVAL;
  pair->ports[i].irq=ret;pair->ports[i].mac_id=ids[i];pair->ports[i].phy_addr=phys[i];
 }
 pair->sysctl_regs=devm_ioremap(dev,QTN_TOPAZ_SYSCTL_BASE,0x100);if(!pair->sysctl_regs)return -ENOMEM;
 /* OEM ruby_arasan_emac_ahb.h requires ENET0+ENET1 released before MAC1.
  * We observe the Bootbase handoff, never reset NETSS/IOSS/PHY globally here. */
 reset=readl(pair->sysctl_regs+4);
 if((reset&(BIT(9)|BIT(12)))!=(BIT(9)|BIT(12)))return -EBUSY;
 for(i=0;i<2;i++){
  res=platform_get_resource_byname(pdev,IORESOURCE_MEM,names[i]);
  pair->ports[i].regs=devm_ioremap_resource(dev,res);if(IS_ERR(pair->ports[i].regs))return PTR_ERR(pair->ports[i].regs);
  /* CONFIG is the OEM first permitted register; other writes may hang while
   * its soft-reset bit is set. Refuse, do not infer a working second MAC. */
  if(readl(pair->ports[i].regs+QTN_EMAC_DMA_CONFIG)&QTN_EMAC_DMA_CONFIG_SOFT_RESET)return -EBUSY;
 }
 ret=dma_set_mask_and_coherent(dev,DMA_BIT_MASK(32));if(ret)return ret;
 ops.ctx=pair;ops.create=f352_create_port;ops.destroy=f352_destroy_port;
 ret=f352_register_pair(&ops);if(ret)return ret;
 platform_set_drvdata(pdev,pair->ndev[0]);
 ret=device_create_file(dev,&dev_attr_lyoko_emac_stats);
 if(ret){f352_unregister_pair(&ops);platform_set_drvdata(pdev,NULL);return ret;}
 dev_info(dev,"F352 two independent direct-DMA netdevs; MAC1/PHY3 and MAC0/PHY1; no TQE forwarding\n");return 0;
}
static void qtn_emac_remove(struct platform_device *pdev)
{
 struct net_device *ndev=platform_get_drvdata(pdev);struct qtn_topaz_emac *emac;struct f352_lifecycle ops;
 if(!ndev)return;
 emac=netdev_priv(ndev);ops.ctx=emac->pair;ops.create=f352_create_port;ops.destroy=f352_destroy_port;
 device_remove_file(&pdev->dev,&dev_attr_lyoko_emac_stats);f352_unregister_pair(&ops);platform_set_drvdata(pdev,NULL);
}
