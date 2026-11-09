# Todos los comentarios de las fuentes originales

Este documento conserva los comentarios literales de todos los archivos C, cabeceras, Makefile y Kconfig de `original/`, con archivo y líneas de procedencia. Incluye las fuentes upstream y las fuentes del port disponibles. No resume ni reescribe los comentarios.

Los binarios compilados no conservan los comentarios originales. La cobertura corresponde a los archivos importados; no atribuye comentarios a fuentes históricas ausentes ni al pseudocódigo recuperado con REA.

Archivos examinados: 79. Comentarios: 3630.

El índice JSON conserva offsets de byte, contenido literal y SHA-256; `original/` conserva los bytes completos.

## 1. original/kernel-api/linux-5.10.260/include/linux/device.h:1

Líneas 1–1; tipo `line`.

```text
// SPDX-License-Identifier: GPL-2.0
```

## 2. original/kernel-api/linux-5.10.260/include/linux/device.h:2

Líneas 2–10; tipo `block`.

```text
/*
 * device.h - generic, centralized driver model
 *
 * Copyright (c) 2001-2003 Patrick Mochel <mochel@osdl.org>
 * Copyright (c) 2004-2009 Greg Kroah-Hartman <gregkh@suse.de>
 * Copyright (c) 2008-2009 Novell Inc.
 *
 * See Documentation/driver-api/driver-model/ for more information.
 */
```

## 3. original/kernel-api/linux-5.10.260/include/linux/device.h:50

Líneas 50–62; tipo `block`.

```text
/**
 * struct subsys_interface - interfaces to device functions
 * @name:       name of the device function
 * @subsys:     subsytem of the devices to attach to
 * @node:       the list of functions registered at the subsystem
 * @add_dev:    device hookup to device function handler
 * @remove_dev: device hookup to device function handler
 *
 * Simple interfaces attached to a subsystem. Multiple interfaces can
 * attach to a subsystem and its devices. Unlike drivers, they do not
 * exclusively claim or control devices. Interfaces usually represent
 * a specific functionality of a subsystem/class of devices.
 */
```

## 4. original/kernel-api/linux-5.10.260/include/linux/device.h:79

Líneas 79–87; tipo `block`.

```text
/*
 * The type of device, "struct device" is embedded in. A class
 * or bus can contain devices of different types
 * like "partitions" and "disks", "mouse" and "event".
 * This identifies the device type and carries type-specific
 * information, equivalent to the kobj_type of a kobject.
 * If "name" is specified, the uevent will contain it in
 * the DEVTYPE variable.
 */
```

## 5. original/kernel-api/linux-5.10.260/include/linux/device.h:99

Líneas 99–99; tipo `block`.

```text
/* interface for exporting device attributes */
```

## 6. original/kernel-api/linux-5.10.260/include/linux/device.h:165

Líneas 165–165; tipo `block`.

```text
/* device resource management */
```

## 7. original/kernel-api/linux-5.10.260/include/linux/device.h:202

Líneas 202–202; tipo `block`.

```text
/* devres group */
```

## 8. original/kernel-api/linux-5.10.260/include/linux/device.h:208

Líneas 208–208; tipo `block`.

```text
/* managed devm_k.alloc/kfree for device drivers */
```

## 9. original/kernel-api/linux-5.10.260/include/linux/device.h:253

Líneas 253–253; tipo `block`.

```text
/* allows to add/remove a custom action to devres stack */
```

## 10. original/kernel-api/linux-5.10.260/include/linux/device.h:270

Líneas 270–280; tipo `block`.

```text
/**
 * devm_alloc_percpu - Resource-managed alloc_percpu
 * @dev: Device to allocate per-cpu memory for
 * @type: Type to allocate per-cpu memory for
 *
 * Managed alloc_percpu. Per-cpu memory allocated with this function is
 * automatically freed on driver detach.
 *
 * RETURNS:
 * Pointer to allocated memory on success, NULL on failure.
 */
```

## 11. original/kernel-api/linux-5.10.260/include/linux/device.h:290

Líneas 290–293; tipo `block`.

```text
/*
	 * a low level driver may set these to teach IOMMU code about
	 * sg limitations.
	 */
```

## 12. original/kernel-api/linux-5.10.260/include/linux/device.h:299

Líneas 299–307; tipo `block`.

```text
/**
 * enum device_link_state - Device link states.
 * @DL_STATE_NONE: The presence of the drivers is not being tracked.
 * @DL_STATE_DORMANT: None of the supplier/consumer drivers is present.
 * @DL_STATE_AVAILABLE: The supplier driver is present, but the consumer is not.
 * @DL_STATE_CONSUMER_PROBE: The consumer is probing (supplier driver present).
 * @DL_STATE_ACTIVE: Both the supplier and consumer drivers are present.
 * @DL_STATE_SUPPLIER_UNBIND: The supplier driver is unbinding.
 */
```

## 13. original/kernel-api/linux-5.10.260/include/linux/device.h:317

Líneas 317–328; tipo `block`.

```text
/*
 * Device link flags.
 *
 * STATELESS: The core will not remove this link automatically.
 * AUTOREMOVE_CONSUMER: Remove the link automatically on consumer driver unbind.
 * PM_RUNTIME: If set, the runtime PM framework will use this link.
 * RPM_ACTIVE: Run pm_runtime_get_sync() on the supplier during link creation.
 * AUTOREMOVE_SUPPLIER: Remove the link automatically on supplier driver unbind.
 * AUTOPROBE_CONSUMER: Probe consumer driver automatically after supplier binds.
 * MANAGED: The core tracks presence of supplier/consumer drivers (internal).
 * SYNC_STATE_ONLY: Link only affects sync_state() behavior.
 */
```

## 14. original/kernel-api/linux-5.10.260/include/linux/device.h:338

Líneas 338–344; tipo `block`.

```text
/**
 * enum dl_dev_state - Device driver presence tracking information.
 * @DL_DEV_NO_DRIVER: There is no driver attached to the device.
 * @DL_DEV_PROBING: A driver is probing.
 * @DL_DEV_DRIVER_BOUND: The driver has been bound to the device.
 * @DL_DEV_UNBINDING: The driver is unbinding from the device.
 */
```

## 15. original/kernel-api/linux-5.10.260/include/linux/device.h:352

Líneas 352–360; tipo `block`.

```text
/**
 * enum device_removable - Whether the device is removable. The criteria for a
 * device to be classified as removable is determined by its subsystem or bus.
 * @DEVICE_REMOVABLE_NOT_SUPPORTED: This attribute is not supported for this
 *				    device (default).
 * @DEVICE_REMOVABLE_UNKNOWN:  Device location is Unknown.
 * @DEVICE_FIXED: Device is not removable by the user.
 * @DEVICE_REMOVABLE: Device is removable by the user.
 */
```

## 16. original/kernel-api/linux-5.10.260/include/linux/device.h:362

Líneas 362–362; tipo `block`.

```text
/* must be 0 */
```

## 17. original/kernel-api/linux-5.10.260/include/linux/device.h:368

Líneas 368–378; tipo `block`.

```text
/**
 * struct dev_links_info - Device data related to device links.
 * @suppliers: List of links to supplier devices.
 * @consumers: List of links to consumer devices.
 * @needs_suppliers: Hook to global list of devices waiting for suppliers.
 * @defer_hook: Hook to global list of devices that have deferred sync_state or
 *		deferred fw_devlink.
 * @need_for_probe: If needs_suppliers is on a list, this indicates if the
 *		    suppliers are needed for probe or not.
 * @status: Driver status information.
 */
```

## 18. original/kernel-api/linux-5.10.260/include/linux/device.h:388

Líneas 388–397; tipo `block`.

```text
/**
 * enum struct_device_flags - Flags in struct device
 *
 * Each flag should have a set of accessor functions created via
 * __create_dev_flag_accessors() for each access.
 *
 * @DEV_FLAG_READY_TO_PROBE: If set then device_add() has finished enough
 *		initialization that probe could be called.
 * @DEV_FLAG_COUNT: Number of defined struct_device_flags.
 */
```

## 19. original/kernel-api/linux-5.10.260/include/linux/device.h:404

Líneas 404–498; tipo `block`.

```text
/**
 * struct device - The basic device structure
 * @parent:	The device's "parent" device, the device to which it is attached.
 * 		In most cases, a parent device is some sort of bus or host
 * 		controller. If parent is NULL, the device, is a top-level device,
 * 		which is not usually what you want.
 * @p:		Holds the private data of the driver core portions of the device.
 * 		See the comment of the struct device_private for detail.
 * @kobj:	A top-level, abstract class from which other classes are derived.
 * @init_name:	Initial name of the device.
 * @type:	The type of device.
 * 		This identifies the device type and carries type-specific
 * 		information.
 * @mutex:	Mutex to synchronize calls to its driver.
 * @lockdep_mutex: An optional debug lock that a subsystem can use as a
 * 		peer lock to gain localized lockdep coverage of the device_lock.
 * @bus:	Type of bus device is on.
 * @driver:	Which driver has allocated this
 * @platform_data: Platform data specific to the device.
 * 		Example: For devices on custom boards, as typical of embedded
 * 		and SOC based hardware, Linux often uses platform_data to point
 * 		to board-specific structures describing devices and how they
 * 		are wired.  That can include what ports are available, chip
 * 		variants, which GPIO pins act in what additional roles, and so
 * 		on.  This shrinks the "Board Support Packages" (BSPs) and
 * 		minimizes board-specific #ifdefs in drivers.
 * @driver_data: Private pointer for driver specific info.
 * @links:	Links to suppliers and consumers of this device.
 * @power:	For device power management.
 *		See Documentation/driver-api/pm/devices.rst for details.
 * @pm_domain:	Provide callbacks that are executed during system suspend,
 * 		hibernation, system resume and during runtime PM transitions
 * 		along with subsystem-level and driver-level callbacks.
 * @em_pd:	device's energy model performance domain
 * @pins:	For device pin management.
 *		See Documentation/driver-api/pinctl.rst for details.
 * @msi_list:	Hosts MSI descriptors
 * @msi_domain: The generic MSI domain this device is using.
 * @numa_node:	NUMA node this device is close to.
 * @dma_ops:    DMA mapping operations for this device.
 * @dma_mask:	Dma mask (if dma'ble device).
 * @coherent_dma_mask: Like dma_mask, but for alloc_coherent mapping as not all
 * 		hardware supports 64-bit addresses for consistent allocations
 * 		such descriptors.
 * @bus_dma_limit: Limit of an upstream bridge or bus which imposes a smaller
 *		DMA limit than the device itself supports.
 * @dma_range_map: map for DMA memory ranges relative to that of RAM
 * @dma_parms:	A low level driver may set these to teach IOMMU code about
 * 		segment limitations.
 * @dma_pools:	Dma pools (if dma'ble device).
 * @dma_mem:	Internal for coherent mem override.
 * @cma_area:	Contiguous memory area for dma allocations
 * @archdata:	For arch-specific additions.
 * @of_node:	Associated device tree node.
 * @fwnode:	Associated device node supplied by platform firmware.
 * @devt:	For creating the sysfs "dev".
 * @id:		device instance
 * @devres_lock: Spinlock to protect the resource of the device.
 * @devres_head: The resources list of the device.
 * @knode_class: The node used to add the device to the class list.
 * @class:	The class of the device.
 * @groups:	Optional attribute groups.
 * @release:	Callback to free the device after all references have
 * 		gone away. This should be set by the allocator of the
 * 		device (i.e. the bus driver that discovered the device).
 * @iommu_group: IOMMU group the device belongs to.
 * @iommu:	Per device generic IOMMU runtime data
 * @removable:  Whether the device can be removed from the system. This
 *              should be set by the subsystem / bus driver that discovered
 *              the device.
 *
 * @offline_disabled: If set, the device is permanently online.
 * @offline:	Set after successful invocation of bus type's .offline().
 * @of_node_reused: Set if the device-tree node is shared with an ancestor
 *              device.
 * @state_synced: The hardware state of this device has been synced to match
 *		  the software state of this device by calling the driver/bus
 *		  sync_state() callback.
 * @dma_coherent: this particular device is dma coherent, even if the
 *		architecture supports non-coherent devices.
 * @dma_ops_bypass: If set to %true then the dma_ops are bypassed for the
 *		streaming DMA operations (->map_* / ->unmap_* / ->sync_*),
 *		and optionall (if the coherent mask is large enough) also
 *		for dma allocations.  This flag is managed by the dma ops
 *		instance from ->dma_supported.
 * @flags:	DEV_FLAG_XXX flags. Use atomic bitfield operations to modify.
 *
 * At the lowest level, every device in a Linux system is represented by an
 * instance of struct device. The device structure contains the information
 * that the device model core needs to model the system. Most subsystems,
 * however, track additional information about the devices they host. As a
 * result, it is rare for devices to be represented by bare device structures;
 * instead, that structure, like kobject structures, is usually embedded within
 * a higher-level representation of the device.
 */
```

## 20. original/kernel-api/linux-5.10.260/include/linux/device.h:505

Líneas 505–505; tipo `block`.

```text
/* initial name of the device */
```

## 21. original/kernel-api/linux-5.10.260/include/linux/device.h:508

Líneas 508–508; tipo `block`.

```text
/* type of bus device is on */
```

## 22. original/kernel-api/linux-5.10.260/include/linux/device.h:509

Líneas 509–510; tipo `block`.

```text
/* which driver has allocated this
					   device */
```

## 23. original/kernel-api/linux-5.10.260/include/linux/device.h:511

Líneas 511–512; tipo `block`.

```text
/* Platform specific data, device
					   core doesn't touch it */
```

## 24. original/kernel-api/linux-5.10.260/include/linux/device.h:513

Líneas 513–514; tipo `block`.

```text
/* Driver data, set and get with
					   dev_set_drvdata/dev_get_drvdata */
```

## 25. original/kernel-api/linux-5.10.260/include/linux/device.h:518

Líneas 518–520; tipo `block`.

```text
/* mutex to synchronize calls to
					 * its driver.
					 */
```

## 26. original/kernel-api/linux-5.10.260/include/linux/device.h:543

Líneas 543–543; tipo `block`.

```text
/* dma mask (if dma'able device) */
```

## 27. original/kernel-api/linux-5.10.260/include/linux/device.h:544

Líneas 544–548; tipo `block`.

```text
/* Like dma_mask, but for
					     alloc_coherent mappings as
					     not all hardware supports
					     64 bit addresses for consistent
					     allocations such descriptors. */
```

## 28. original/kernel-api/linux-5.10.260/include/linux/device.h:549

Líneas 549–549; tipo `block`.

```text
/* upstream dma constraint */
```

## 29. original/kernel-api/linux-5.10.260/include/linux/device.h:554

Líneas 554–554; tipo `block`.

```text
/* dma pools (if dma'ble) */
```

## 30. original/kernel-api/linux-5.10.260/include/linux/device.h:557

Líneas 557–558; tipo `block`.

```text
/* internal for coherent mem
					     override */
```

## 31. original/kernel-api/linux-5.10.260/include/linux/device.h:561

Líneas 561–562; tipo `block`.

```text
/* contiguous memory area for dma
					   allocations */
```

## 32. original/kernel-api/linux-5.10.260/include/linux/device.h:564

Líneas 564–564; tipo `block`.

```text
/* arch specific additions */
```

## 33. original/kernel-api/linux-5.10.260/include/linux/device.h:567

Líneas 567–567; tipo `block`.

```text
/* associated device tree node */
```

## 34. original/kernel-api/linux-5.10.260/include/linux/device.h:568

Líneas 568–568; tipo `block`.

```text
/* firmware device node */
```

## 35. original/kernel-api/linux-5.10.260/include/linux/device.h:571

Líneas 571–571; tipo `block`.

```text
/* NUMA node this device is close to */
```

## 36. original/kernel-api/linux-5.10.260/include/linux/device.h:573

Líneas 573–573; tipo `block`.

```text
/* dev_t, creates the sysfs "dev" */
```

## 37. original/kernel-api/linux-5.10.260/include/linux/device.h:574

Líneas 574–574; tipo `block`.

```text
/* device instance */
```

## 38. original/kernel-api/linux-5.10.260/include/linux/device.h:580

Líneas 580–580; tipo `block`.

```text
/* optional groups */
```

## 39. original/kernel-api/linux-5.10.260/include/linux/device.h:630

Líneas 630–643; tipo `block`.

```text
/**
 * struct device_link - Device link representation.
 * @supplier: The device on the supplier end of the link.
 * @s_node: Hook to the supplier device's list of links to consumers.
 * @consumer: The device on the consumer end of the link.
 * @c_node: Hook to the consumer device's list of links to suppliers.
 * @link_dev: device used to expose link details in sysfs
 * @status: The state of the link (with respect to the presence of drivers).
 * @flags: Link flags.
 * @rpm_active: Whether or not the consumer device is runtime-PM-active.
 * @kref: Count repeated addition of the same link.
 * @rm_work: Work structure used for removing the link.
 * @supplier_preactivated: Supplier has been made active before consumer probe.
 */
```

## 40. original/kernel-api/linux-5.10.260/include/linux/device.h:655

Líneas 655–655; tipo `block`.

```text
/* Owned by consumer probe. */
```

## 41. original/kernel-api/linux-5.10.260/include/linux/device.h:663

Líneas 663–667; tipo `block`.

```text
/**
 * device_iommu_mapped - Returns true when the device DMA is translated
 *			 by an IOMMU
 * @dev: Device to perform the check on
 */
```

## 42. original/kernel-api/linux-5.10.260/include/linux/device.h:673

Líneas 673–673; tipo `block`.

```text
/* Get the wakeup routines, which depend on struct device */
```

## 43. original/kernel-api/linux-5.10.260/include/linux/device.h:678

Líneas 678–678; tipo `block`.

```text
/* Use the init name until the kobject becomes available */
```

## 44. original/kernel-api/linux-5.10.260/include/linux/device.h:685

Líneas 685–691; tipo `block`.

```text
/**
 * dev_bus_name - Return a device's bus/class name, if at all possible
 * @dev: struct device to get the bus/class name of
 *
 * Will return the name of the bus/class the device is attached to.  If it is
 * not attached to a bus/class, an empty string will be returned.
 */
```

## 45. original/kernel-api/linux-5.10.260/include/linux/device.h:870

Líneas 870–872; tipo `block`.

```text
/*
 * High level routines for use by the bus drivers
 */
```

## 46. original/kernel-api/linux-5.10.260/include/linux/device.h:921

Líneas 921–923; tipo `block`.

```text
/*
 * Root device objects for grouping under /sys/devices
 */
```

## 47. original/kernel-api/linux-5.10.260/include/linux/device.h:926

Líneas 926–926; tipo `block`.

```text
/* This is a macro to avoid include problems with THIS_MODULE */
```

## 48. original/kernel-api/linux-5.10.260/include/linux/device.h:937

Líneas 937–940; tipo `block`.

```text
/*
 * Manual binding of a device to driver. See drivers/base/bus.c
 * for information on use.
 */
```

## 49. original/kernel-api/linux-5.10.260/include/linux/device.h:950

Líneas 950–952; tipo `block`.

```text
/*
 * Easy functions for dynamically creating devices on the fly
 */
```

## 50. original/kernel-api/linux-5.10.260/include/linux/device.h:992

Líneas 992–996; tipo `block`.

```text
/*
 * Platform "fixup" functions - allow the platform to have their say
 * about devices and actions that the general device layer doesn't
 * know about.
 */
```

## 51. original/kernel-api/linux-5.10.260/include/linux/device.h:997

Líneas 997–997; tipo `block`.

```text
/* Notify platform of device discovery */
```

## 52. original/kernel-api/linux-5.10.260/include/linux/device.h:1003

Líneas 1003–1006; tipo `block`.

```text
/*
 * get_device - atomically increment the reference count for the device.
 *
 */
```

## 53. original/kernel-api/linux-5.10.260/include/linux/device.h:1020

Líneas 1020–1020; tipo `block`.

```text
/* drivers/base/power/shutdown.c */
```

## 54. original/kernel-api/linux-5.10.260/include/linux/device.h:1023

Líneas 1023–1023; tipo `block`.

```text
/* debugging and troubleshooting/diagnostic helpers. */
```

## 55. original/kernel-api/linux-5.10.260/include/linux/device.h:1026

Líneas 1026–1026; tipo `block`.

```text
/* Device links interface. */
```

## 56. original/kernel-api/linux-5.10.260/include/linux/device.h:1035

Líneas 1035–1035; tipo `block`.

```text
/* Create alias, so I can be autoloaded. */
```

## 57. original/kernel-api/linux-5.10.260/include/linux/device.h:1047

Líneas 1047–1047; tipo `block`.

```text
/* _DEVICE_H_ */
```

## 58. original/kernel-api/linux-5.10.260/include/linux/device/driver.h:1

Líneas 1–1; tipo `line`.

```text
// SPDX-License-Identifier: GPL-2.0
```

## 59. original/kernel-api/linux-5.10.260/include/linux/device/driver.h:2

Líneas 2–12; tipo `block`.

```text
/*
 * The driver-specific portions of the driver model
 *
 * Copyright (c) 2001-2003 Patrick Mochel <mochel@osdl.org>
 * Copyright (c) 2004-2009 Greg Kroah-Hartman <gregkh@suse.de>
 * Copyright (c) 2008-2009 Novell Inc.
 * Copyright (c) 2012-2019 Greg Kroah-Hartman <gregkh@linuxfoundation.org>
 * Copyright (c) 2012-2019 Linux Foundation
 *
 * See Documentation/driver-api/driver-model/ for more information.
 */
```

## 60. original/kernel-api/linux-5.10.260/include/linux/device/driver.h:22

Líneas 22–43; tipo `block`.

```text
/**
 * enum probe_type - device driver probe type to try
 *	Device drivers may opt in for special handling of their
 *	respective probe routines. This tells the core what to
 *	expect and prefer.
 *
 * @PROBE_DEFAULT_STRATEGY: Used by drivers that work equally well
 *	whether probed synchronously or asynchronously.
 * @PROBE_PREFER_ASYNCHRONOUS: Drivers for "slow" devices which
 *	probing order is not essential for booting the system may
 *	opt into executing their probes asynchronously.
 * @PROBE_FORCE_SYNCHRONOUS: Use this to annotate drivers that need
 *	their probe routines to run synchronously with driver and
 *	device registration (with the exception of -EPROBE_DEFER
 *	handling - re-probing always ends up being done asynchronously).
 *
 * Note that the end goal is to switch the kernel to use asynchronous
 * probing by default, so annotating drivers with
 * %PROBE_PREFER_ASYNCHRONOUS is a temporary measure that allows us
 * to speed up boot process while we are validating the rest of the
 * drivers.
 */
```

## 61. original/kernel-api/linux-5.10.260/include/linux/device/driver.h:50

Líneas 50–94; tipo `block`.

```text
/**
 * struct device_driver - The basic device driver structure
 * @name:	Name of the device driver.
 * @bus:	The bus which the device of this driver belongs to.
 * @owner:	The module owner.
 * @mod_name:	Used for built-in modules.
 * @suppress_bind_attrs: Disables bind/unbind via sysfs.
 * @probe_type:	Type of the probe (synchronous or asynchronous) to use.
 * @of_match_table: The open firmware table.
 * @acpi_match_table: The ACPI match table.
 * @probe:	Called to query the existence of a specific device,
 *		whether this driver can work with it, and bind the driver
 *		to a specific device.
 * @sync_state:	Called to sync device state to software state after all the
 *		state tracking consumers linked to this device (present at
 *		the time of late_initcall) have successfully bound to a
 *		driver. If the device has no consumers, this function will
 *		be called at late_initcall_sync level. If the device has
 *		consumers that are never bound to a driver, this function
 *		will never get called until they do.
 * @remove:	Called when the device is removed from the system to
 *		unbind a device from this driver.
 * @shutdown:	Called at shut-down time to quiesce the device.
 * @suspend:	Called to put the device to sleep mode. Usually to a
 *		low power state.
 * @resume:	Called to bring a device from sleep mode.
 * @groups:	Default attributes that get created by the driver core
 *		automatically.
 * @dev_groups:	Additional attributes attached to device instance once the
 *		it is bound to the driver.
 * @pm:		Power management operations of the device which matched
 *		this driver.
 * @coredump:	Called when sysfs entry is written to. The device driver
 *		is expected to call the dev_coredump API resulting in a
 *		uevent.
 * @p:		Driver core's private data, no one other than the driver
 *		core can touch this.
 *
 * The device driver-model tracks all of the drivers known to the system.
 * The main reason for this tracking is to enable the driver core to match
 * up drivers with new devices. Once drivers are known objects within the
 * system, however, a number of other things become possible. Device drivers
 * can export information and configuration variables that are independent
 * of any specific device.
 */
```

## 62. original/kernel-api/linux-5.10.260/include/linux/device/driver.h:100

Líneas 100–100; tipo `block`.

```text
/* used for built-in modules */
```

## 63. original/kernel-api/linux-5.10.260/include/linux/device/driver.h:102

Líneas 102–102; tipo `block`.

```text
/* disables bind/unbind via sysfs */
```

## 64. original/kernel-api/linux-5.10.260/include/linux/device/driver.h:132

Líneas 132–132; tipo `block`.

```text
/* sysfs interface for exporting driver attributes */
```

## 65. original/kernel-api/linux-5.10.260/include/linux/device/driver.h:164

Líneas 164–169; tipo `block`.

```text
/**
 * driver_find_device_by_name - device iterator for locating a particular device
 * of a specific name.
 * @drv: the driver we're iterating
 * @name: name of the device to match
 */
```

## 66. original/kernel-api/linux-5.10.260/include/linux/device/driver.h:176

Líneas 176–181; tipo `block`.

```text
/**
 * driver_find_device_by_of_node- device iterator for locating a particular device
 * by of_node pointer.
 * @drv: the driver we're iterating
 * @np: of_node pointer to match.
 */
```

## 67. original/kernel-api/linux-5.10.260/include/linux/device/driver.h:189

Líneas 189–194; tipo `block`.

```text
/**
 * driver_find_device_by_fwnode- device iterator for locating a particular device
 * by fwnode pointer.
 * @drv: the driver we're iterating
 * @fwnode: fwnode pointer to match.
 */
```

## 68. original/kernel-api/linux-5.10.260/include/linux/device/driver.h:202

Líneas 202–207; tipo `block`.

```text
/**
 * driver_find_device_by_devt- device iterator for locating a particular device
 * by devt.
 * @drv: the driver we're iterating
 * @devt: devt pointer to match.
 */
```

## 69. original/kernel-api/linux-5.10.260/include/linux/device/driver.h:221

Líneas 221–226; tipo `block`.

```text
/**
 * driver_find_device_by_acpi_dev : device iterator for locating a particular
 * device matching the ACPI_COMPANION device.
 * @drv: the driver we're iterating
 * @adev: ACPI_COMPANION device to match.
 */
```

## 70. original/kernel-api/linux-5.10.260/include/linux/device/driver.h:246

Líneas 246–259; tipo `block`.

```text
/**
 * module_driver() - Helper macro for drivers that don't do anything
 * special in module init/exit. This eliminates a lot of boilerplate.
 * Each module may only use this macro once, and calling it replaces
 * module_init() and module_exit().
 *
 * @__driver: driver name
 * @__register: register function for this driver type
 * @__unregister: unregister function for this driver type
 * @...: Additional arguments to be passed to __register and __unregister.
 *
 * Use this macro to construct bus specific macros for registering
 * drivers, and do not use it on its own.
 */
```

## 71. original/kernel-api/linux-5.10.260/include/linux/device/driver.h:272

Líneas 272–286; tipo `block`.

```text
/**
 * builtin_driver() - Helper macro for drivers that don't do anything
 * special in init and have no exit. This eliminates some boilerplate.
 * Each driver may only use this macro once, and calling it replaces
 * device_initcall (or in some cases, the legacy __initcall).  This is
 * meant to be a direct parallel of module_driver() above but without
 * the __exit stuff that is not used for builtin cases.
 *
 * @__driver: driver name
 * @__register: register function for this driver type
 * @...: Additional arguments to be passed to __register
 *
 * Use this macro to construct bus specific macros for registering
 * drivers, and do not use it on its own.
 */
```

## 72. original/kernel-api/linux-5.10.260/include/linux/device/driver.h:294

Líneas 294–294; tipo `block`.

```text
/* _DEVICE_DRIVER_H_ */
```

## 73. original/kernel-api/linux-5.10.260/include/linux/module.h:1

Líneas 1–1; tipo `block`.

```text
/* SPDX-License-Identifier: GPL-2.0-only */
```

## 74. original/kernel-api/linux-5.10.260/include/linux/module.h:2

Líneas 2–7; tipo `block`.

```text
/*
 * Dynamic loading of modules into the kernel.
 *
 * Rewritten by Richard Henderson <rth@tamu.edu> Dec 1996
 * Rewritten again by Rusty Russell, 2002
 */
```

## 75. original/kernel-api/linux-5.10.260/include/linux/module.h:33

Líneas 33–33; tipo `block`.

```text
/* Not Yet Implemented */
```

## 76. original/kernel-api/linux-5.10.260/include/linux/module.h:76

Líneas 76–76; tipo `block`.

```text
/* These are either module local, or the kernel's dummy ones. */
```

## 77. original/kernel-api/linux-5.10.260/include/linux/module.h:81

Líneas 81–88; tipo `block`.

```text
/**
 * module_init() - driver initialization entry point
 * @x: function to be run at kernel boot time or module insertion
 *
 * module_init() will either be called during do_initcalls() (if
 * builtin) or at module insertion time (if a module).  There can only
 * be one per module.
 */
```

## 78. original/kernel-api/linux-5.10.260/include/linux/module.h:91

Líneas 91–100; tipo `block`.

```text
/**
 * module_exit() - driver exit entry point
 * @x: function to be run when driver is removed
 *
 * module_exit() will wrap the driver clean-up code
 * with cleanup_module() when used with rmmod when
 * the driver is a module.  If the driver is statically
 * compiled into the kernel, module_exit() has no effect.
 * There can only be one per module.
 */
```

## 79. original/kernel-api/linux-5.10.260/include/linux/module.h:103

Líneas 103–103; tipo `block`.

```text
/* MODULE */
```

## 80. original/kernel-api/linux-5.10.260/include/linux/module.h:105

Líneas 105–111; tipo `block`.

```text
/*
 * In most cases loadable modules do not need custom
 * initcall levels. There are still some valid cases where
 * a driver may be needed early if built in, and does not
 * matter when built as a loadable module. Like bus
 * snooping debug drivers.
 */
```

## 81. original/kernel-api/linux-5.10.260/include/linux/module.h:130

Líneas 130–130; tipo `block`.

```text
/* Each module must use one module_init(). */
```

## 82. original/kernel-api/linux-5.10.260/include/linux/module.h:136

Líneas 136–136; tipo `block`.

```text
/* This is only required if you want to be unloadable. */
```

## 83. original/kernel-api/linux-5.10.260/include/linux/module.h:144

Líneas 144–145; tipo `block`.

```text
/* This means "can be init if no module support, otherwise module load
   may call it." */
```

## 84. original/kernel-api/linux-5.10.260/include/linux/module.h:160

Líneas 160–160; tipo `block`.

```text
/*CONFIG_MODULES*/
```

## 85. original/kernel-api/linux-5.10.260/include/linux/module.h:162

Líneas 162–162; tipo `block`.

```text
/* Generic info of form tag = "info" */
```

## 86. original/kernel-api/linux-5.10.260/include/linux/module.h:165

Líneas 165–165; tipo `block`.

```text
/* For userspace: you can also call me... */
```

## 87. original/kernel-api/linux-5.10.260/include/linux/module.h:168

Líneas 168–170; tipo `block`.

```text
/* Soft module dependencies. See man modprobe.d for details.
 * Example: MODULE_SOFTDEP("pre: module-foo module-bar post: module-baz")
 */
```

## 88. original/kernel-api/linux-5.10.260/include/linux/module.h:173

Líneas 173–176; tipo `block`.

```text
/*
 * MODULE_FILE is used for generating modules.builtin
 * So, make it no-op when this is being built as a module
 */
```

## 89. original/kernel-api/linux-5.10.260/include/linux/module.h:183

Líneas 183–226; tipo `block`.

```text
/*
 * The following license idents are currently accepted as indicating free
 * software modules
 *
 *	"GPL"				[GNU Public License v2]
 *	"GPL v2"			[GNU Public License v2]
 *	"GPL and additional rights"	[GNU Public License v2 rights and more]
 *	"Dual BSD/GPL"			[GNU Public License v2
 *					 or BSD license choice]
 *	"Dual MIT/GPL"			[GNU Public License v2
 *					 or MIT license choice]
 *	"Dual MPL/GPL"			[GNU Public License v2
 *					 or Mozilla license choice]
 *
 * The following other idents are available
 *
 *	"Proprietary"			[Non free products]
 *
 * Both "GPL v2" and "GPL" (the latter also in dual licensed strings) are
 * merely stating that the module is licensed under the GPL v2, but are not
 * telling whether "GPL v2 only" or "GPL v2 or later". The reason why there
 * are two variants is a historic and failed attempt to convey more
 * information in the MODULE_LICENSE string. For module loading the
 * "only/or later" distinction is completely irrelevant and does neither
 * replace the proper license identifiers in the corresponding source file
 * nor amends them in any way. The sole purpose is to make the
 * 'Proprietary' flagging work and to refuse to bind symbols which are
 * exported with EXPORT_SYMBOL_GPL when a non free module is loaded.
 *
 * In the same way "BSD" is not a clear license information. It merely
 * states, that the module is licensed under one of the compatible BSD
 * license variants. The detailed and correct license information is again
 * to be found in the corresponding source files.
 *
 * There are dual licensed components, but when running with Linux it is the
 * GPL that is relevant so this is a non issue. Similarly LGPL linked with GPL
 * is a GPL combined work.
 *
 * This exists for several reasons
 * 1.	So modinfo can show license info for users wanting to vet their setup
 *	is free
 * 2.	So the community can ignore bug reports including proprietary modules
 * 3.	So vendors can do likewise based on their own policies
 */
```

## 90. original/kernel-api/linux-5.10.260/include/linux/module.h:229

Líneas 229–232; tipo `block`.

```text
/*
 * Author(s), use "Name <email>" or just "Name", for multiple
 * authors use multiple MODULE_AUTHOR() statements/lines.
 */
```

## 91. original/kernel-api/linux-5.10.260/include/linux/module.h:235

Líneas 235–235; tipo `block`.

```text
/* What your module does. */
```

## 92. original/kernel-api/linux-5.10.260/include/linux/module.h:239

Líneas 239–239; tipo `block`.

```text
/* Creates an alias so file2alias.c can find device table. */
```

## 93. original/kernel-api/linux-5.10.260/include/linux/module.h:243

Líneas 243–243; tipo `block`.

```text
/* !MODULE */
```

## 94. original/kernel-api/linux-5.10.260/include/linux/module.h:247

Líneas 247–262; tipo `block`.

```text
/* Version of form [<epoch>:]<version>[-<extra-version>].
 * Or for CVS/RCS ID version, everything but the number is stripped.
 * <epoch>: A (small) unsigned integer which allows you to start versions
 * anew. If not mentioned, it's zero.  eg. "2:1.0" is after
 * "1:2.0".

 * <version>: The <version> may contain only alphanumerics and the
 * character `.'.  Ordered by numeric sort for numeric parts,
 * ascii sort for ascii parts (as per RPM or DEB algorithm).

 * <extraversion>: Like <version>, but inserted for local
 * customizations, eg "rh3" or "rusty1".

 * Using this automatically adds a checksum of the .c files and the
 * local headers in "srcversion".
 */
```

## 95. original/kernel-api/linux-5.10.260/include/linux/module.h:285

Líneas 285–287; tipo `block`.

```text
/* Optional firmware file (or files) needed by the module
 * format is simply firmware file name.  Multiple firmware
 * files require multiple MODULE_FIRMWARE() specifiers */
```

## 96. original/kernel-api/linux-5.10.260/include/linux/module.h:296

Líneas 296–296; tipo `block`.

```text
/* for sysctl */
```

## 97. original/kernel-api/linux-5.10.260/include/linux/module.h:297

Líneas 297–297; tipo `block`.

```text
/* Get/put a kernel symbol (calls must be symmetric) */
```

## 98. original/kernel-api/linux-5.10.260/include/linux/module.h:302

Líneas 302–302; tipo `block`.

```text
/* modules using other modules: kdb wants to see this. */
```

## 99. original/kernel-api/linux-5.10.260/include/linux/module.h:310

Líneas 310–310; tipo `block`.

```text
/* Normal state. */
```

## 100. original/kernel-api/linux-5.10.260/include/linux/module.h:311

Líneas 311–311; tipo `block`.

```text
/* Full formed, running module_init. */
```

## 101. original/kernel-api/linux-5.10.260/include/linux/module.h:312

Líneas 312–312; tipo `block`.

```text
/* Going away. */
```

## 102. original/kernel-api/linux-5.10.260/include/linux/module.h:313

Líneas 313–313; tipo `block`.

```text
/* Still setting it up. */
```

## 103. original/kernel-api/linux-5.10.260/include/linux/module.h:322

Líneas 322–322; tipo `block`.

```text
/* The actual code + data. */
```

## 104. original/kernel-api/linux-5.10.260/include/linux/module.h:324

Líneas 324–324; tipo `block`.

```text
/* Total size. */
```

## 105. original/kernel-api/linux-5.10.260/include/linux/module.h:326

Líneas 326–326; tipo `block`.

```text
/* The size of the executable code.  */
```

## 106. original/kernel-api/linux-5.10.260/include/linux/module.h:328

Líneas 328–328; tipo `block`.

```text
/* Size of RO section of the module (text+rodata) */
```

## 107. original/kernel-api/linux-5.10.260/include/linux/module.h:330

Líneas 330–330; tipo `block`.

```text
/* Size of RO after init section */
```

## 108. original/kernel-api/linux-5.10.260/include/linux/module.h:339

Líneas 339–339; tipo `block`.

```text
/* Only touch one cacheline for common rbtree-for-core-layout case. */
```

## 109. original/kernel-api/linux-5.10.260/include/linux/module.h:364

Líneas 364–364; tipo `block`.

```text
/* Member of list of modules */
```

## 110. original/kernel-api/linux-5.10.260/include/linux/module.h:367

Líneas 367–367; tipo `block`.

```text
/* Unique handle for this module */
```

## 111. original/kernel-api/linux-5.10.260/include/linux/module.h:370

Líneas 370–370; tipo `block`.

```text
/* Sysfs stuff. */
```

## 112. original/kernel-api/linux-5.10.260/include/linux/module.h:377

Líneas 377–377; tipo `block`.

```text
/* Exported symbols */
```

## 113. original/kernel-api/linux-5.10.260/include/linux/module.h:382

Líneas 382–382; tipo `block`.

```text
/* Kernel parameters. */
```

## 114. original/kernel-api/linux-5.10.260/include/linux/module.h:389

Líneas 389–389; tipo `block`.

```text
/* GPL-only exported symbols. */
```

## 115. original/kernel-api/linux-5.10.260/include/linux/module.h:396

Líneas 396–396; tipo `block`.

```text
/* unused exported symbols. */
```

## 116. original/kernel-api/linux-5.10.260/include/linux/module.h:401

Líneas 401–401; tipo `block`.

```text
/* GPL-only, unused exported symbols. */
```

## 117. original/kernel-api/linux-5.10.260/include/linux/module.h:408

Líneas 408–408; tipo `block`.

```text
/* Signature was verified. */
```

## 118. original/kernel-api/linux-5.10.260/include/linux/module.h:414

Líneas 414–414; tipo `block`.

```text
/* symbols that will be GPL-only in the near future. */
```

## 119. original/kernel-api/linux-5.10.260/include/linux/module.h:419

Líneas 419–419; tipo `block`.

```text
/* Exception table */
```

## 120. original/kernel-api/linux-5.10.260/include/linux/module.h:423

Líneas 423–423; tipo `block`.

```text
/* Startup function. */
```

## 121. original/kernel-api/linux-5.10.260/include/linux/module.h:426

Líneas 426–426; tipo `block`.

```text
/* Core layout: rbtree is accessed frequently, so keep together. */
```

## 122. original/kernel-api/linux-5.10.260/include/linux/module.h:430

Líneas 430–430; tipo `block`.

```text
/* Arch-specific module values */
```

## 123. original/kernel-api/linux-5.10.260/include/linux/module.h:433

Líneas 433–433; tipo `block`.

```text
/* same bits as kernel:taint_flags */
```

## 124. original/kernel-api/linux-5.10.260/include/linux/module.h:436

Líneas 436–436; tipo `block`.

```text
/* Support for BUG */
```

## 125. original/kernel-api/linux-5.10.260/include/linux/module.h:443

Líneas 443–443; tipo `block`.

```text
/* Protected by RCU and/or module_mutex: use rcu_dereference() */
```

## 126. original/kernel-api/linux-5.10.260/include/linux/module.h:447

Líneas 447–447; tipo `block`.

```text
/* Section attributes */
```

## 127. original/kernel-api/linux-5.10.260/include/linux/module.h:450

Líneas 450–450; tipo `block`.

```text
/* Notes attributes */
```

## 128. original/kernel-api/linux-5.10.260/include/linux/module.h:454

Líneas 454–455; tipo `block`.

```text
/* The command line arguments (may be mangled).  People like
	   keeping pointers to this stuff */
```

## 129. original/kernel-api/linux-5.10.260/include/linux/module.h:459

Líneas 459–459; tipo `block`.

```text
/* Per-cpu data. */
```

## 130. original/kernel-api/linux-5.10.260/include/linux/module.h:508

Líneas 508–508; tipo `block`.

```text
/* Is this a livepatch module? */
```

## 131. original/kernel-api/linux-5.10.260/include/linux/module.h:511

Líneas 511–511; tipo `block`.

```text
/* Elf information */
```

## 132. original/kernel-api/linux-5.10.260/include/linux/module.h:516

Líneas 516–516; tipo `block`.

```text
/* What modules depend on me? */
```

## 133. original/kernel-api/linux-5.10.260/include/linux/module.h:518

Líneas 518–518; tipo `block`.

```text
/* What modules do I depend on? */
```

## 134. original/kernel-api/linux-5.10.260/include/linux/module.h:521

Líneas 521–521; tipo `block`.

```text
/* Destruction function. */
```

## 135. original/kernel-api/linux-5.10.260/include/linux/module.h:533

Líneas 533–533; tipo `block`.

```text
/* Constructor functions. */
```

## 136. original/kernel-api/linux-5.10.260/include/linux/module.h:556

Líneas 556–558; tipo `block`.

```text
/* FIXME: It'd be nice to isolate modules during init, too, so they
   aren't used before they (may) fail.  But presently too much code
   (IDE & SCSI) require entry into the module during init.*/
```

## 137. original/kernel-api/linux-5.10.260/include/linux/module.h:590

Líneas 590–590; tipo `block`.

```text
/* Search for module by name: must be in a RCU-sched critical section. */
```

## 138. original/kernel-api/linux-5.10.260/include/linux/module.h:604

Líneas 604–605; tipo `block`.

```text
/* Returns 0 and fills in value, defined and namebuf, or -ERANGE if
   symnum out of range. */
```

## 139. original/kernel-api/linux-5.10.260/include/linux/module.h:609

Líneas 609–609; tipo `block`.

```text
/* Look for this name: can be of form module:name. */
```

## 140. original/kernel-api/linux-5.10.260/include/linux/module.h:622

Líneas 622–623; tipo `block`.

```text
/* Sometimes we know we already have a refcount, and it's easier not
   to handle the error case (which only happens with rmmod --wait). */
```

## 141. original/kernel-api/linux-5.10.260/include/linux/module.h:626

Líneas 626–627; tipo `block`.

```text
/* This is the Right Way to get a module: if it fails, it's being removed,
 * so pretend it's not there. */
```

## 142. original/kernel-api/linux-5.10.260/include/linux/module.h:632

Líneas 632–632; tipo `block`.

```text
/*!CONFIG_MODULE_UNLOAD*/
```

## 143. original/kernel-api/linux-5.10.260/include/linux/module.h:646

Líneas 646–646; tipo `block`.

```text
/* CONFIG_MODULE_UNLOAD */
```

## 144. original/kernel-api/linux-5.10.260/include/linux/module.h:648

Líneas 648–648; tipo `block`.

```text
/* This is a #define so the string doesn't get put in every .o file */
```

## 145. original/kernel-api/linux-5.10.260/include/linux/module.h:655

Líneas 655–655; tipo `block`.

```text
/* Dereference module function descriptor */
```

## 146. original/kernel-api/linux-5.10.260/include/linux/module.h:658

Líneas 658–660; tipo `block`.

```text
/* For kallsyms to ask for address resolution.  namebuf should be at
 * least KSYM_NAME_LEN long: a pointer to namebuf is returned if
 * found, otherwise NULL. */
```

## 147. original/kernel-api/linux-5.10.260/include/linux/module.h:684

Líneas 684–684; tipo `block`.

```text
/* !CONFIG_LIVEPATCH */
```

## 148. original/kernel-api/linux-5.10.260/include/linux/module.h:689

Líneas 689–689; tipo `block`.

```text
/* CONFIG_LIVEPATCH */
```

## 149. original/kernel-api/linux-5.10.260/include/linux/module.h:694

Líneas 694–694; tipo `block`.

```text
/* !CONFIG_MODULES... */
```

## 150. original/kernel-api/linux-5.10.260/include/linux/module.h:743

Líneas 743–743; tipo `block`.

```text
/* Get/put a kernel symbol (calls should be symmetric) */
```

## 151. original/kernel-api/linux-5.10.260/include/linux/module.h:763

Líneas 763–763; tipo `block`.

```text
/* For kallsyms to ask for address resolution.  NULL means not found. */
```

## 152. original/kernel-api/linux-5.10.260/include/linux/module.h:797

Líneas 797–797; tipo `block`.

```text
/* no events will happen anyway, so this can always succeed */
```

## 153. original/kernel-api/linux-5.10.260/include/linux/module.h:826

Líneas 826–826; tipo `block`.

```text
/* Dereference module function descriptor */
```

## 154. original/kernel-api/linux-5.10.260/include/linux/module.h:833

Líneas 833–833; tipo `block`.

```text
/* CONFIG_MODULES */
```

## 155. original/kernel-api/linux-5.10.260/include/linux/module.h:839

Líneas 839–839; tipo `block`.

```text
/* CONFIG_SYSFS */
```

## 156. original/kernel-api/linux-5.10.260/include/linux/module.h:843

Líneas 843–843; tipo `block`.

```text
/* BELOW HERE ALL THESE ARE OBSOLETE AND WILL VANISH */
```

## 157. original/kernel-api/linux-5.10.260/include/linux/module.h:852

Líneas 852–852; tipo `block`.

```text
/* !CONFIG_GENERIC_BUG */
```

## 158. original/kernel-api/linux-5.10.260/include/linux/module.h:860

Líneas 860–860; tipo `block`.

```text
/* CONFIG_GENERIC_BUG */
```

## 159. original/kernel-api/linux-5.10.260/include/linux/module.h:876

Líneas 876–876; tipo `block`.

```text
/* !CONFIG_MODULE_SIG */
```

## 160. original/kernel-api/linux-5.10.260/include/linux/module.h:881

Líneas 881–881; tipo `block`.

```text
/* CONFIG_MODULE_SIG */
```

## 161. original/kernel-api/linux-5.10.260/include/linux/module.h:894

Líneas 894–894; tipo `block`.

```text
/* CONFIG_MODULES && CONFIG_KALLSYMS */
```

## 162. original/kernel-api/linux-5.10.260/include/linux/module.h:896

Líneas 896–896; tipo `block`.

```text
/* _LINUX_MODULE_H */
```

## 163. original/kernel-api/linux-5.10.260/include/linux/moduleparam.h:1

Líneas 1–1; tipo `block`.

```text
/* SPDX-License-Identifier: GPL-2.0 */
```

## 164. original/kernel-api/linux-5.10.260/include/linux/moduleparam.h:4

Líneas 4–4; tipo `block`.

```text
/* (C) Copyright 2001, 2002 Rusty Russell IBM Corporation */
```

## 165. original/kernel-api/linux-5.10.260/include/linux/moduleparam.h:9

Líneas 9–10; tipo `block`.

```text
/* You can override this manually, but generally this should match the
   module name. */
```

## 166. original/kernel-api/linux-5.10.260/include/linux/moduleparam.h:12

Líneas 12–12; tipo `block`.

```text
/* empty */
```

## 167. original/kernel-api/linux-5.10.260/include/linux/moduleparam.h:13

Líneas 13–13; tipo `block`.

```text
/* empty */
```

## 168. original/kernel-api/linux-5.10.260/include/linux/moduleparam.h:16

Líneas 16–16; tipo `block`.

```text
/* We cannot use MODULE_PARAM_PREFIX because some modules override it. */
```

## 169. original/kernel-api/linux-5.10.260/include/linux/moduleparam.h:20

Líneas 20–20; tipo `block`.

```text
/* Chosen so that structs with an unsigned long line up. */
```

## 170. original/kernel-api/linux-5.10.260/include/linux/moduleparam.h:31

Líneas 31–32; tipo `block`.

```text
/* One for each parameter, describing how to use it.  Some files do
   multiple of these per line, so can't just use MODULE_INFO. */
```

## 171. original/kernel-api/linux-5.10.260/include/linux/moduleparam.h:38

Líneas 38–42; tipo `block`.

```text
/*
 * Flags available for kernel_param_ops
 *
 * NOARG - the parameter allows for no argument (foo instead of foo=1)
 */
```

## 172. original/kernel-api/linux-5.10.260/include/linux/moduleparam.h:48

Líneas 48–48; tipo `block`.

```text
/* How the ops should behave */
```

## 173. original/kernel-api/linux-5.10.260/include/linux/moduleparam.h:50

Líneas 50–50; tipo `block`.

```text
/* Returns 0, or -errno.  arg is in kp->arg. */
```

## 174. original/kernel-api/linux-5.10.260/include/linux/moduleparam.h:52

Líneas 52–52; tipo `block`.

```text
/* Returns length written or -errno.  Buffer is 4k (ie. be short!) */
```

## 175. original/kernel-api/linux-5.10.260/include/linux/moduleparam.h:54

Líneas 54–54; tipo `block`.

```text
/* Optional function to free kp->arg when module unloaded. */
```

## 176. original/kernel-api/linux-5.10.260/include/linux/moduleparam.h:58

Líneas 58–63; tipo `block`.

```text
/*
 * Flags available for kernel_param
 *
 * UNSAFE - the parameter is dangerous and setting it will taint the kernel
 * HWPARAM - Hardware param not permitted in lockdown mode
 */
```

## 177. original/kernel-api/linux-5.10.260/include/linux/moduleparam.h:85

Líneas 85–85; tipo `block`.

```text
/* Special one for strings we want to copy into */
```

## 178. original/kernel-api/linux-5.10.260/include/linux/moduleparam.h:91

Líneas 91–91; tipo `block`.

```text
/* Special one for arrays */
```

## 179. original/kernel-api/linux-5.10.260/include/linux/moduleparam.h:101

Líneas 101–125; tipo `block`.

```text
/**
 * module_param - typesafe helper for a module/cmdline parameter
 * @name: the variable to alter, and exposed parameter name.
 * @type: the type of the parameter
 * @perm: visibility in sysfs.
 *
 * @name becomes the module parameter, or (prefixed by KBUILD_MODNAME and a
 * ".") the kernel commandline parameter.  Note that - is changed to _, so
 * the user can use "foo-bar=1" even for variable "foo_bar".
 *
 * @perm is 0 if the variable is not to appear in sysfs, or 0444
 * for world-readable, 0644 for root-writable, etc.  Note that if it
 * is writable, you may need to use kernel_param_lock() around
 * accesses (esp. charp, which can be kfreed when it changes).
 *
 * The @type is simply pasted to refer to a param_ops_##type and a
 * param_check_##type: for convenience many standard types are provided but
 * you can create your own by defining those variables.
 *
 * Standard types are:
 *	byte, hexint, short, ushort, int, uint, long, ulong
 *	charp: a character pointer
 *	bool: a bool, values 0/1, y/n, Y/N.
 *	invbool: the above, only sense-reversed (N = true).
 */
```

## 180. original/kernel-api/linux-5.10.260/include/linux/moduleparam.h:129

Líneas 129–134; tipo `block`.

```text
/**
 * module_param_unsafe - same as module_param but taints kernel
 * @name: the variable to alter, and exposed parameter name.
 * @type: the type of the parameter
 * @perm: visibility in sysfs.
 */
```

## 181. original/kernel-api/linux-5.10.260/include/linux/moduleparam.h:138

Líneas 138–148; tipo `block`.

```text
/**
 * module_param_named - typesafe helper for a renamed module/cmdline parameter
 * @name: a valid C identifier which is the parameter name.
 * @value: the actual lvalue to alter.
 * @type: the type of the parameter
 * @perm: visibility in sysfs.
 *
 * Usually it's a good idea to have variable names and user-exposed names the
 * same, but that's harder if the variable must be non-static or is inside a
 * structure.  This allows exposure under a different name.
 */
```

## 182. original/kernel-api/linux-5.10.260/include/linux/moduleparam.h:154

Líneas 154–160; tipo `block`.

```text
/**
 * module_param_named_unsafe - same as module_param_named but taints kernel
 * @name: a valid C identifier which is the parameter name.
 * @value: the actual lvalue to alter.
 * @type: the type of the parameter
 * @perm: visibility in sysfs.
 */
```

## 183. original/kernel-api/linux-5.10.260/include/linux/moduleparam.h:166

Líneas 166–174; tipo `block`.

```text
/**
 * module_param_cb - general callback for a module/cmdline parameter
 * @name: a valid C identifier which is the parameter name.
 * @ops: the set & get operations for this parameter.
 * @arg: args for @ops
 * @perm: visibility in sysfs.
 *
 * The ops can have NULL set or get functions.
 */
```

## 184. original/kernel-api/linux-5.10.260/include/linux/moduleparam.h:184

Líneas 184–193; tipo `block`.

```text
/**
 * core_param_cb - general callback for a module/cmdline parameter
 *                 to be evaluated before core initcall level
 * @name: a valid C identifier which is the parameter name.
 * @ops: the set & get operations for this parameter.
 * @arg: args for @ops
 * @perm: visibility in sysfs.
 *
 * The ops can have NULL set or get functions.
 */
```

## 185. original/kernel-api/linux-5.10.260/include/linux/moduleparam.h:197

Líneas 197–206; tipo `block`.

```text
/**
 * postcore_param_cb - general callback for a module/cmdline parameter
 *                     to be evaluated before postcore initcall level
 * @name: a valid C identifier which is the parameter name.
 * @ops: the set & get operations for this parameter.
 * @arg: args for @ops
 * @perm: visibility in sysfs.
 *
 * The ops can have NULL set or get functions.
 */
```

## 186. original/kernel-api/linux-5.10.260/include/linux/moduleparam.h:210

Líneas 210–219; tipo `block`.

```text
/**
 * arch_param_cb - general callback for a module/cmdline parameter
 *                 to be evaluated before arch initcall level
 * @name: a valid C identifier which is the parameter name.
 * @ops: the set & get operations for this parameter.
 * @arg: args for @ops
 * @perm: visibility in sysfs.
 *
 * The ops can have NULL set or get functions.
 */
```

## 187. original/kernel-api/linux-5.10.260/include/linux/moduleparam.h:223

Líneas 223–232; tipo `block`.

```text
/**
 * subsys_param_cb - general callback for a module/cmdline parameter
 *                   to be evaluated before subsys initcall level
 * @name: a valid C identifier which is the parameter name.
 * @ops: the set & get operations for this parameter.
 * @arg: args for @ops
 * @perm: visibility in sysfs.
 *
 * The ops can have NULL set or get functions.
 */
```

## 188. original/kernel-api/linux-5.10.260/include/linux/moduleparam.h:236

Líneas 236–245; tipo `block`.

```text
/**
 * fs_param_cb - general callback for a module/cmdline parameter
 *               to be evaluated before fs initcall level
 * @name: a valid C identifier which is the parameter name.
 * @ops: the set & get operations for this parameter.
 * @arg: args for @ops
 * @perm: visibility in sysfs.
 *
 * The ops can have NULL set or get functions.
 */
```

## 189. original/kernel-api/linux-5.10.260/include/linux/moduleparam.h:249

Líneas 249–258; tipo `block`.

```text
/**
 * device_param_cb - general callback for a module/cmdline parameter
 *                   to be evaluated before device initcall level
 * @name: a valid C identifier which is the parameter name.
 * @ops: the set & get operations for this parameter.
 * @arg: args for @ops
 * @perm: visibility in sysfs.
 *
 * The ops can have NULL set or get functions.
 */
```

## 190. original/kernel-api/linux-5.10.260/include/linux/moduleparam.h:262

Líneas 262–271; tipo `block`.

```text
/**
 * late_param_cb - general callback for a module/cmdline parameter
 *                 to be evaluated before late initcall level
 * @name: a valid C identifier which is the parameter name.
 * @ops: the set & get operations for this parameter.
 * @arg: args for @ops
 * @perm: visibility in sysfs.
 *
 * The ops can have NULL set or get functions.
 */
```

## 191. original/kernel-api/linux-5.10.260/include/linux/moduleparam.h:275

Líneas 275–278; tipo `block`.

```text
/* On alpha, ia64 and ppc64 relocations to global data cannot go into
   read-only sections (which is part of respective UNIX ABI on these
   platforms). So 'const' makes no sense and even causes compile failures
   with some compilers. */
```

## 192. original/kernel-api/linux-5.10.260/include/linux/moduleparam.h:285

Líneas 285–285; tipo `block`.

```text
/* This is the fundamental function for registering boot/module parameters. */
```

## 193. original/kernel-api/linux-5.10.260/include/linux/moduleparam.h:295

Líneas 295–295; tipo `block`.

```text
/* Obsolete - use module_param_cb() */
```

## 194. original/kernel-api/linux-5.10.260/include/linux/moduleparam.h:315

Líneas 315–326; tipo `block`.

```text
/**
 * core_param - define a historical core kernel parameter.
 * @name: the name of the cmdline and sysfs parameter (often the same as var)
 * @var: the variable
 * @type: the type of the parameter
 * @perm: visibility in sysfs
 *
 * core_param is just like module_param(), but cannot be modular and
 * doesn't add a prefix (such as "printk.").  This is for compatibility
 * with __setup(), and it makes sense as truly core parameters aren't
 * tied to the particular file they're in.
 */
```

## 195. original/kernel-api/linux-5.10.260/include/linux/moduleparam.h:331

Líneas 331–337; tipo `block`.

```text
/**
 * core_param_unsafe - same as core_param but taints kernel
 * @name: the name of the cmdline and sysfs parameter (often the same as var)
 * @var: the variable
 * @type: the type of the parameter
 * @perm: visibility in sysfs
 */
```

## 196. original/kernel-api/linux-5.10.260/include/linux/moduleparam.h:343

Líneas 343–343; tipo `block`.

```text
/* !MODULE */
```

## 197. original/kernel-api/linux-5.10.260/include/linux/moduleparam.h:345

Líneas 345–354; tipo `block`.

```text
/**
 * module_param_string - a char array parameter
 * @name: the name of the parameter
 * @string: the string variable
 * @len: the maximum length of the string, incl. terminator
 * @perm: visibility in sysfs.
 *
 * This actually copies the string when it's set (unlike type charp).
 * @len is usually just sizeof(string).
 */
```

## 198. original/kernel-api/linux-5.10.260/include/linux/moduleparam.h:363

Líneas 363–370; tipo `block`.

```text
/**
 * parameq - checks if two parameter names match
 * @name1: parameter name 1
 * @name2: parameter name 2
 *
 * Returns true if the two parameter names are equal.
 * Dashes (-) are considered equal to underscores (_).
 */
```

## 199. original/kernel-api/linux-5.10.260/include/linux/moduleparam.h:373

Líneas 373–380; tipo `block`.

```text
/**
 * parameqn - checks if two parameter names match
 * @name1: parameter name 1
 * @name2: parameter name 2
 * @n: the length to compare
 *
 * Similar to parameq(), except it compares @n characters.
 */
```

## 200. original/kernel-api/linux-5.10.260/include/linux/moduleparam.h:383

Líneas 383–383; tipo `block`.

```text
/* Called on module insert or kernel boot */
```

## 201. original/kernel-api/linux-5.10.260/include/linux/moduleparam.h:394

Líneas 394–394; tipo `block`.

```text
/* Called by module remove. */
```

## 202. original/kernel-api/linux-5.10.260/include/linux/moduleparam.h:402

Líneas 402–402; tipo `block`.

```text
/* !CONFIG_SYSFS */
```

## 203. original/kernel-api/linux-5.10.260/include/linux/moduleparam.h:404

Líneas 404–404; tipo `block`.

```text
/* All the helper functions */
```

## 204. original/kernel-api/linux-5.10.260/include/linux/moduleparam.h:405

Líneas 405–406; tipo `block`.

```text
/* The macros to do compile-time type checking stolen from Jakub
   Jelinek, who IIRC came up with this idea for the 2.4 module init code. */
```

## 205. original/kernel-api/linux-5.10.260/include/linux/moduleparam.h:463

Líneas 463–463; tipo `block`.

```text
/* We used to allow int as well as bool.  We're taking that away! */
```

## 206. original/kernel-api/linux-5.10.260/include/linux/moduleparam.h:472

Líneas 472–472; tipo `block`.

```text
/* getter is the same as for the regular bool */
```

## 207. original/kernel-api/linux-5.10.260/include/linux/moduleparam.h:480

Líneas 480–480; tipo `block`.

```text
/* An int, which can only be set like a bool (though it shows as an int). */
```

## 208. original/kernel-api/linux-5.10.260/include/linux/moduleparam.h:486

Líneas 486–498; tipo `block`.

```text
/**
 * module_param_array - a parameter which is an array of some type
 * @name: the name of the array variable
 * @type: the type, as per module_param()
 * @nump: optional pointer filled in with the number written
 * @perm: visibility in sysfs
 *
 * Input and output are as comma-separated values.  Commas inside values
 * don't work properly (eg. an array of charp).
 *
 * ARRAY_SIZE(@name) is used to determine the number of elements in the
 * array, so the definition must be visible.
 */
```

## 209. original/kernel-api/linux-5.10.260/include/linux/moduleparam.h:502

Líneas 502–512; tipo `block`.

```text
/**
 * module_param_array_named - renamed parameter which is an array of some type
 * @name: a valid C identifier which is the parameter name
 * @array: the name of the array variable
 * @type: the type, as per module_param()
 * @nump: optional pointer filled in with the number written
 * @perm: visibility in sysfs
 *
 * This exposes a different name than the actual variable name.  See
 * module_param_named() for why this might be necessary.
 */
```

## 210. original/kernel-api/linux-5.10.260/include/linux/moduleparam.h:526

Líneas 526–526; tipo `block`.

```text
/* Module parameter configures an I/O port */
```

## 211. original/kernel-api/linux-5.10.260/include/linux/moduleparam.h:527

Líneas 527–527; tipo `block`.

```text
/* Module parameter configures an I/O mem address */
```

## 212. original/kernel-api/linux-5.10.260/include/linux/moduleparam.h:528

Líneas 528–528; tipo `block`.

```text
/* Module parameter could be either, depending on other option */
```

## 213. original/kernel-api/linux-5.10.260/include/linux/moduleparam.h:529

Líneas 529–529; tipo `block`.

```text
/* Module parameter configures an IRQ */
```

## 214. original/kernel-api/linux-5.10.260/include/linux/moduleparam.h:530

Líneas 530–530; tipo `block`.

```text
/* Module parameter configures a DMA channel */
```

## 215. original/kernel-api/linux-5.10.260/include/linux/moduleparam.h:531

Líneas 531–531; tipo `block`.

```text
/* Module parameter configures a DMA buffer address */
```

## 216. original/kernel-api/linux-5.10.260/include/linux/moduleparam.h:532

Líneas 532–532; tipo `block`.

```text
/* Module parameter configures some other value */
```

## 217. original/kernel-api/linux-5.10.260/include/linux/moduleparam.h:535

Líneas 535–546; tipo `block`.

```text
/**
 * module_param_hw_named - A parameter representing a hw parameters
 * @name: a valid C identifier which is the parameter name.
 * @value: the actual lvalue to alter.
 * @type: the type of the parameter
 * @hwtype: what the value represents (enum hwparam_type)
 * @perm: visibility in sysfs.
 *
 * Usually it's a good idea to have variable names and user-exposed names the
 * same, but that's harder if the variable must be non-static or is inside a
 * structure.  This allows exposure under a different name.
 */
```

## 218. original/kernel-api/linux-5.10.260/include/linux/moduleparam.h:558

Líneas 558–571; tipo `block`.

```text
/**
 * module_param_hw_array - A parameter representing an array of hw parameters
 * @name: the name of the array variable
 * @type: the type, as per module_param()
 * @hwtype: what the value represents (enum hwparam_type)
 * @nump: optional pointer filled in with the number written
 * @perm: visibility in sysfs
 *
 * Input and output are as comma-separated values.  Commas inside values
 * don't work properly (eg. an array of charp).
 *
 * ARRAY_SIZE(@name) is used to determine the number of elements in the
 * array, so the definition must be visible.
 */
```

## 219. original/kernel-api/linux-5.10.260/include/linux/moduleparam.h:592

Líneas 592–592; tipo `block`.

```text
/* for exporting parameters in /sys/module/.../parameters */
```

## 220. original/kernel-api/linux-5.10.260/include/linux/moduleparam.h:614

Líneas 614–614; tipo `block`.

```text
/* _LINUX_MODULE_PARAMS_H */
```

## 221. original/kernel-api/linux-5.10.260/include/linux/pci.h:1

Líneas 1–1; tipo `block`.

```text
/* SPDX-License-Identifier: GPL-2.0 */
```

## 222. original/kernel-api/linux-5.10.260/include/linux/pci.h:2

Líneas 2–22; tipo `block`.

```text
/*
 *	pci.h
 *
 *	PCI defines and function prototypes
 *	Copyright 1994, Drew Eckhardt
 *	Copyright 1997--1999 Martin Mares <mj@ucw.cz>
 *
 *	PCI Express ASPM defines and function prototypes
 *	Copyright (c) 2007 Intel Corp.
 *		Zhang Yanmin (yanmin.zhang@intel.com)
 *		Shaohua Li (shaohua.li@intel.com)
 *
 *	For more information, please consult the following manuals (look at
 *	http://www.pcisig.com/ for how to get them):
 *
 *	PCI BIOS Specification
 *	PCI Local Bus Specification
 *	PCI to PCI Bridge Specification
 *	PCI Express Specification
 *	PCI System Design Guide
 */
```

## 223. original/kernel-api/linux-5.10.260/include/linux/pci.h:52

Líneas 52–63; tipo `block`.

```text
/*
 * The PCI interface treats multi-function devices as independent
 * devices.  The slot/function address of each device is encoded
 * in a single byte as follows:
 *
 *	7:3 = slot
 *	2:0 = function
 *
 * PCI_DEVFN(), PCI_SLOT(), and PCI_FUNC() are defined in uapi/linux/pci.h.
 * In the interest of not exposing interfaces to user-space unnecessarily,
 * the following kernel-only defines are being added here.
 */
```

## 224. original/kernel-api/linux-5.10.260/include/linux/pci.h:65

Líneas 65–65; tipo `block`.

```text
/* return bus from PCI devid = ((u16)bus_number) << 8) | devfn */
```

## 225. original/kernel-api/linux-5.10.260/include/linux/pci.h:68

Líneas 68–68; tipo `block`.

```text
/* pci_slot represents a physical slot */
```

## 226. original/kernel-api/linux-5.10.260/include/linux/pci.h:70

Líneas 70–70; tipo `block`.

```text
/* Bus this slot is on */
```

## 227. original/kernel-api/linux-5.10.260/include/linux/pci.h:71

Líneas 71–71; tipo `block`.

```text
/* Node in list of slots */
```

## 228. original/kernel-api/linux-5.10.260/include/linux/pci.h:72

Líneas 72–72; tipo `block`.

```text
/* Hotplug info (move here) */
```

## 229. original/kernel-api/linux-5.10.260/include/linux/pci.h:73

Líneas 73–73; tipo `block`.

```text
/* PCI_SLOT(pci_dev->devfn) */
```

## 230. original/kernel-api/linux-5.10.260/include/linux/pci.h:82

Líneas 82–82; tipo `block`.

```text
/* File state for mmap()s on /proc/bus/pci/X/Y */
```

## 231. original/kernel-api/linux-5.10.260/include/linux/pci.h:88

Líneas 88–88; tipo `block`.

```text
/* For PCI devices, the region numbers are assigned this way: */
```

## 232. original/kernel-api/linux-5.10.260/include/linux/pci.h:90

Líneas 90–90; tipo `block`.

```text
/* #0-5: standard PCI resources */
```

## 233. original/kernel-api/linux-5.10.260/include/linux/pci.h:94

Líneas 94–94; tipo `block`.

```text
/* #6: expansion ROM resource */
```

## 234. original/kernel-api/linux-5.10.260/include/linux/pci.h:97

Líneas 97–97; tipo `block`.

```text
/* Device-specific resources */
```

## 235. original/kernel-api/linux-5.10.260/include/linux/pci.h:103

Líneas 103–103; tipo `block`.

```text
/* PCI-to-PCI (P2P) bridge windows */
```

## 236. original/kernel-api/linux-5.10.260/include/linux/pci.h:108

Líneas 108–108; tipo `block`.

```text
/* CardBus bridge windows */
```

## 237. original/kernel-api/linux-5.10.260/include/linux/pci.h:114

Líneas 114–114; tipo `block`.

```text
/* Total number of bridge resources for P2P and CardBus */
```

## 238. original/kernel-api/linux-5.10.260/include/linux/pci.h:117

Líneas 117–117; tipo `block`.

```text
/* Resources assigned to buses behind the bridge */
```

## 239. original/kernel-api/linux-5.10.260/include/linux/pci.h:122

Líneas 122–122; tipo `block`.

```text
/* Total resources associated with a PCI device */
```

## 240. original/kernel-api/linux-5.10.260/include/linux/pci.h:125

Líneas 125–125; tipo `block`.

```text
/* Preserve this for compatibility */
```

## 241. original/kernel-api/linux-5.10.260/include/linux/pci.h:129

Líneas 129–139; tipo `block`.

```text
/**
 * enum pci_interrupt_pin - PCI INTx interrupt values
 * @PCI_INTERRUPT_UNKNOWN: Unknown or unassigned interrupt
 * @PCI_INTERRUPT_INTA: PCI INTA pin
 * @PCI_INTERRUPT_INTB: PCI INTB pin
 * @PCI_INTERRUPT_INTC: PCI INTC pin
 * @PCI_INTERRUPT_INTD: PCI INTD pin
 *
 * Corresponds to values for legacy PCI INTx interrupts, as can be found in the
 * PCI_INTERRUPT_PIN register.
 */
```

## 242. original/kernel-api/linux-5.10.260/include/linux/pci.h:148

Líneas 148–148; tipo `block`.

```text
/* The number of legacy PCI INTx interrupts */
```

## 243. original/kernel-api/linux-5.10.260/include/linux/pci.h:151

Líneas 151–155; tipo `block`.

```text
/*
 * Reading from a device that doesn't respond typically returns ~0.  A
 * successful read from a device may also return ~0, so you need additional
 * information to reliably identify errors.
 */
```

## 244. original/kernel-api/linux-5.10.260/include/linux/pci.h:160

Líneas 160–163; tipo `block`.

```text
/*
 * pci_power_t values must match the bits in the Capabilities PME_Support
 * and Control/Status PowerState fields in the Power Management capability.
 */
```

## 245. original/kernel-api/linux-5.10.260/include/linux/pci.h:174

Líneas 174–174; tipo `block`.

```text
/* Remember to update this when the list above changes! */
```

## 246. original/kernel-api/linux-5.10.260/include/linux/pci.h:182

Líneas 182–188; tipo `block`.

```text
/**
 * typedef pci_channel_state_t
 *
 * The pci_channel state describes connectivity between the CPU and
 * the PCI device.  If some PCI bus between here and the PCI device
 * has crashed or locked up, this info is reflected here.
 */
```

## 247. original/kernel-api/linux-5.10.260/include/linux/pci.h:192

Líneas 192–192; tipo `block`.

```text
/* I/O channel is in normal state */
```

## 248. original/kernel-api/linux-5.10.260/include/linux/pci.h:195

Líneas 195–195; tipo `block`.

```text
/* I/O to channel is blocked */
```

## 249. original/kernel-api/linux-5.10.260/include/linux/pci.h:198

Líneas 198–198; tipo `block`.

```text
/* PCI card is dead */
```

## 250. original/kernel-api/linux-5.10.260/include/linux/pci.h:205

Líneas 205–205; tipo `block`.

```text
/* Reset is NOT asserted (Use to deassert reset) */
```

## 251. original/kernel-api/linux-5.10.260/include/linux/pci.h:208

Líneas 208–208; tipo `block`.

```text
/* Use #PERST to reset PCIe device */
```

## 252. original/kernel-api/linux-5.10.260/include/linux/pci.h:211

Líneas 211–211; tipo `block`.

```text
/* Use PCIe Hot Reset to reset device */
```

## 253. original/kernel-api/linux-5.10.260/include/linux/pci.h:217

Líneas 217–217; tipo `block`.

```text
/* INTX_DISABLE in PCI_COMMAND register disables MSI too */
```

## 254. original/kernel-api/linux-5.10.260/include/linux/pci.h:219

Líneas 219–219; tipo `block`.

```text
/* Device configuration is irrevocably lost if disabled into D3 */
```

## 255. original/kernel-api/linux-5.10.260/include/linux/pci.h:221

Líneas 221–221; tipo `block`.

```text
/* Provide indication device is assigned by a Virtual Machine Manager */
```

## 256. original/kernel-api/linux-5.10.260/include/linux/pci.h:223

Líneas 223–223; tipo `block`.

```text
/* Flag for quirk use to store if quirk-specific ACS is enabled */
```

## 257. original/kernel-api/linux-5.10.260/include/linux/pci.h:225

Líneas 225–225; tipo `block`.

```text
/* Use a PCIe-to-PCI bridge alias even if !pci_is_pcie */
```

## 258. original/kernel-api/linux-5.10.260/include/linux/pci.h:227

Líneas 227–227; tipo `block`.

```text
/* Do not use bus resets for device */
```

## 259. original/kernel-api/linux-5.10.260/include/linux/pci.h:229

Líneas 229–229; tipo `block`.

```text
/* Do not use PM reset even if device advertises NoSoftRst- */
```

## 260. original/kernel-api/linux-5.10.260/include/linux/pci.h:231

Líneas 231–231; tipo `block`.

```text
/* Get VPD from function 0 VPD */
```

## 261. original/kernel-api/linux-5.10.260/include/linux/pci.h:233

Líneas 233–233; tipo `block`.

```text
/* A non-root bridge where translation occurs, stop alias search here */
```

## 262. original/kernel-api/linux-5.10.260/include/linux/pci.h:235

Líneas 235–235; tipo `block`.

```text
/* Do not use FLR even if device advertises PCI_AF_CAP */
```

## 263. original/kernel-api/linux-5.10.260/include/linux/pci.h:237

Líneas 237–237; tipo `block`.

```text
/* Don't use Relaxed Ordering for TLPs directed at this device */
```

## 264. original/kernel-api/linux-5.10.260/include/linux/pci.h:239

Líneas 239–239; tipo `block`.

```text
/* Device does honor MSI masking despite saying otherwise */
```

## 265. original/kernel-api/linux-5.10.260/include/linux/pci.h:256

Líneas 256–256; tipo `block`.

```text
/* Values from Link Status register, PCIe r3.1, sec 7.8.8 */
```

## 266. original/kernel-api/linux-5.10.260/include/linux/pci.h:269

Líneas 269–269; tipo `block`.

```text
/* See matching string table in pci_speed_string() */
```

## 267. original/kernel-api/linux-5.10.260/include/linux/pci.h:320

Líneas 320–320; tipo `block`.

```text
/* The pci_dev structure describes PCI devices */
```

## 268. original/kernel-api/linux-5.10.260/include/linux/pci.h:322

Líneas 322–322; tipo `block`.

```text
/* Node in per-bus list */
```

## 269. original/kernel-api/linux-5.10.260/include/linux/pci.h:323

Líneas 323–323; tipo `block`.

```text
/* Bus this device is on */
```

## 270. original/kernel-api/linux-5.10.260/include/linux/pci.h:324

Líneas 324–324; tipo `block`.

```text
/* Bus this device bridges to */
```

## 271. original/kernel-api/linux-5.10.260/include/linux/pci.h:326

Líneas 326–326; tipo `block`.

```text
/* Hook for sys-specific extension */
```

## 272. original/kernel-api/linux-5.10.260/include/linux/pci.h:327

Líneas 327–327; tipo `block`.

```text
/* Device entry in /proc/bus/pci */
```

## 273. original/kernel-api/linux-5.10.260/include/linux/pci.h:328

Líneas 328–328; tipo `block`.

```text
/* Physical slot this device is in */
```

## 274. original/kernel-api/linux-5.10.260/include/linux/pci.h:330

Líneas 330–330; tipo `block`.

```text
/* Encoded device & function index */
```

## 275. original/kernel-api/linux-5.10.260/include/linux/pci.h:335

Líneas 335–335; tipo `block`.

```text
/* 3 bytes: (base,sub,prog-if) */
```

## 276. original/kernel-api/linux-5.10.260/include/linux/pci.h:336

Líneas 336–336; tipo `block`.

```text
/* PCI revision, low byte of class word */
```

## 277. original/kernel-api/linux-5.10.260/include/linux/pci.h:337

Líneas 337–337; tipo `block`.

```text
/* PCI header type (`multi' flag masked out) */
```

## 278. original/kernel-api/linux-5.10.260/include/linux/pci.h:339

Líneas 339–339; tipo `block`.

```text
/* AER capability offset */
```

## 279. original/kernel-api/linux-5.10.260/include/linux/pci.h:340

Líneas 340–340; tipo `block`.

```text
/* AER stats for this device */
```

## 280. original/kernel-api/linux-5.10.260/include/linux/pci.h:343

Líneas 343–343; tipo `block`.

```text
/* RCEC cached endpoint association */
```

## 281. original/kernel-api/linux-5.10.260/include/linux/pci.h:345

Líneas 345–345; tipo `block`.

```text
/* PCIe Device Capabilities */
```

## 282. original/kernel-api/linux-5.10.260/include/linux/pci.h:346

Líneas 346–346; tipo `block`.

```text
/* PCIe capability offset */
```

## 283. original/kernel-api/linux-5.10.260/include/linux/pci.h:347

Líneas 347–347; tipo `block`.

```text
/* MSI capability offset */
```

## 284. original/kernel-api/linux-5.10.260/include/linux/pci.h:348

Líneas 348–348; tipo `block`.

```text
/* MSI-X capability offset */
```

## 285. original/kernel-api/linux-5.10.260/include/linux/pci.h:349

Líneas 349–349; tipo `block`.

```text
/* PCIe Max Payload Size Supported */
```

## 286. original/kernel-api/linux-5.10.260/include/linux/pci.h:350

Líneas 350–350; tipo `block`.

```text
/* Config register controlling ROM */
```

## 287. original/kernel-api/linux-5.10.260/include/linux/pci.h:351

Líneas 351–351; tipo `block`.

```text
/* Interrupt pin this device uses */
```

## 288. original/kernel-api/linux-5.10.260/include/linux/pci.h:352

Líneas 352–352; tipo `block`.

```text
/* Cached PCIe Capabilities Register */
```

## 289. original/kernel-api/linux-5.10.260/include/linux/pci.h:353

Líneas 353–353; tipo `block`.

```text
/* Mask of enabled devfn aliases */
```

## 290. original/kernel-api/linux-5.10.260/include/linux/pci.h:355

Líneas 355–355; tipo `block`.

```text
/* Driver bound to this device */
```

## 291. original/kernel-api/linux-5.10.260/include/linux/pci.h:356

Líneas 356–360; tipo `block`.

```text
/* Mask of the bits of bus address this
					   device implements.  Normally this is
					   0xffffffff.  You only need to change
					   this if your device has broken DMA
					   or supports 64-bit transfers.  */
```

## 292. original/kernel-api/linux-5.10.260/include/linux/pci.h:364

Líneas 364–366; tipo `block`.

```text
/* Current operating state. In ACPI,
					   this is D0-D3, D0 being fully
					   functional, and D3 being off. */
```

## 293. original/kernel-api/linux-5.10.260/include/linux/pci.h:367

Líneas 367–367; tipo `block`.

```text
/* Supports Immediate Readiness */
```

## 294. original/kernel-api/linux-5.10.260/include/linux/pci.h:368

Líneas 368–368; tipo `block`.

```text
/* PM capability offset */
```

## 295. original/kernel-api/linux-5.10.260/include/linux/pci.h:369

Líneas 369–370; tipo `block`.

```text
/* Bitmask of states from which PME#
					   can be generated */
```

## 296. original/kernel-api/linux-5.10.260/include/linux/pci.h:371

Líneas 371–371; tipo `block`.

```text
/* Poll device's PME status bit */
```

## 297. original/kernel-api/linux-5.10.260/include/linux/pci.h:372

Líneas 372–372; tipo `block`.

```text
/* Low power state D1 is supported */
```

## 298. original/kernel-api/linux-5.10.260/include/linux/pci.h:373

Líneas 373–373; tipo `block`.

```text
/* Low power state D2 is supported */
```

## 299. original/kernel-api/linux-5.10.260/include/linux/pci.h:374

Líneas 374–374; tipo `block`.

```text
/* D1 and D2 are forbidden */
```

## 300. original/kernel-api/linux-5.10.260/include/linux/pci.h:375

Líneas 375–375; tipo `block`.

```text
/* D3cold is forbidden */
```

## 301. original/kernel-api/linux-5.10.260/include/linux/pci.h:376

Líneas 376–376; tipo `block`.

```text
/* Allow D3 for bridge */
```

## 302. original/kernel-api/linux-5.10.260/include/linux/pci.h:377

Líneas 377–377; tipo `block`.

```text
/* D3cold is allowed by user */
```

## 303. original/kernel-api/linux-5.10.260/include/linux/pci.h:378

Líneas 378–379; tipo `block`.

```text
/* Disallow turning off io/mem
						   decoding during BAR sizing */
```

## 304. original/kernel-api/linux-5.10.260/include/linux/pci.h:381

Líneas 381–384; tipo `block`.

```text
/* Whether go through runtime
						   D3cold, not set for devices
						   powered on/off by the
						   corresponding bridge */
```

## 305. original/kernel-api/linux-5.10.260/include/linux/pci.h:385

Líneas 385–385; tipo `block`.

```text
/* Internal: Skip bus-level PM */
```

## 306. original/kernel-api/linux-5.10.260/include/linux/pci.h:386

Líneas 386–386; tipo `block`.

```text
/* Ignore hotplug events */
```

## 307. original/kernel-api/linux-5.10.260/include/linux/pci.h:387

Líneas 387–389; tipo `block`.

```text
/* SlotCtl indicators
						      controlled exclusively by
						      user sysfs */
```

## 308. original/kernel-api/linux-5.10.260/include/linux/pci.h:390

Líneas 390–391; tipo `block`.

```text
/* Need to clear Retrain Link
						   bit manually */
```

## 309. original/kernel-api/linux-5.10.260/include/linux/pci.h:392

Líneas 392–392; tipo `block`.

```text
/* D3hot->D0 transition time in ms */
```

## 310. original/kernel-api/linux-5.10.260/include/linux/pci.h:393

Líneas 393–393; tipo `block`.

```text
/* D3cold->D0 transition time in ms */
```

## 311. original/kernel-api/linux-5.10.260/include/linux/pci.h:396

Líneas 396–396; tipo `block`.

```text
/* ASPM link state */
```

## 312. original/kernel-api/linux-5.10.260/include/linux/pci.h:397

Líneas 397–398; tipo `block`.

```text
/* Latency Tolerance Reporting
					   supported from root to here */
```

## 313. original/kernel-api/linux-5.10.260/include/linux/pci.h:399

Líneas 399–399; tipo `block`.

```text
/* L1SS Capability pointer */
```

## 314. original/kernel-api/linux-5.10.260/include/linux/pci.h:401

Líneas 401–401; tipo `block`.

```text
/* End-to-End TLP Prefix */
```

## 315. original/kernel-api/linux-5.10.260/include/linux/pci.h:403

Líneas 403–403; tipo `block`.

```text
/* Current connectivity state */
```

## 316. original/kernel-api/linux-5.10.260/include/linux/pci.h:404

Líneas 404–404; tipo `block`.

```text
/* Generic device interface */
```

## 317. original/kernel-api/linux-5.10.260/include/linux/pci.h:406

Líneas 406–406; tipo `block`.

```text
/* Size of config space */
```

## 318. original/kernel-api/linux-5.10.260/include/linux/pci.h:408

Líneas 408–411; tipo `block`.

```text
/*
	 * Instead of touching interrupt line and base address registers
	 * directly, use the values stored here. They might be different!
	 */
```

## 319. original/kernel-api/linux-5.10.260/include/linux/pci.h:413

Líneas 413–413; tipo `block`.

```text
/* I/O and memory regions + expansion ROMs */
```

## 320. original/kernel-api/linux-5.10.260/include/linux/pci.h:415

Líneas 415–415; tipo `block`.

```text
/* Skip attaching driver */
```

## 321. original/kernel-api/linux-5.10.260/include/linux/pci.h:417

Líneas 417–417; tipo `block`.

```text
/* Subtractive decode bridge */
```

## 322. original/kernel-api/linux-5.10.260/include/linux/pci.h:418

Líneas 418–418; tipo `block`.

```text
/* Bridge has I/O window */
```

## 323. original/kernel-api/linux-5.10.260/include/linux/pci.h:419

Líneas 419–419; tipo `block`.

```text
/* Bridge has pref mem window */
```

## 324. original/kernel-api/linux-5.10.260/include/linux/pci.h:420

Líneas 420–420; tipo `block`.

```text
/* Pref mem window is 64-bit */
```

## 325. original/kernel-api/linux-5.10.260/include/linux/pci.h:421

Líneas 421–421; tipo `block`.

```text
/* Multi-function device */
```

## 326. original/kernel-api/linux-5.10.260/include/linux/pci.h:423

Líneas 423–423; tipo `block`.

```text
/* Is busmaster */
```

## 327. original/kernel-api/linux-5.10.260/include/linux/pci.h:424

Líneas 424–424; tipo `block`.

```text
/* May not use MSI */
```

## 328. original/kernel-api/linux-5.10.260/include/linux/pci.h:425

Líneas 425–425; tipo `block`.

```text
/* May only use 32-bit MSIs */
```

## 329. original/kernel-api/linux-5.10.260/include/linux/pci.h:426

Líneas 426–426; tipo `block`.

```text
/* Config space access blocked */
```

## 330. original/kernel-api/linux-5.10.260/include/linux/pci.h:427

Líneas 427–427; tipo `block`.

```text
/* Generates false positive parity */
```

## 331. original/kernel-api/linux-5.10.260/include/linux/pci.h:428

Líneas 428–428; tipo `block`.

```text
/* Needs IRQ rerouting variant */
```

## 332. original/kernel-api/linux-5.10.260/include/linux/pci.h:431

Líneas 431–431; tipo `block`.

```text
/* ARI forwarding */
```

## 333. original/kernel-api/linux-5.10.260/include/linux/pci.h:432

Líneas 432–432; tipo `block`.

```text
/* Address Translation Svc */
```

## 334. original/kernel-api/linux-5.10.260/include/linux/pci.h:433

Líneas 433–433; tipo `block`.

```text
/* Process Address Space ID */
```

## 335. original/kernel-api/linux-5.10.260/include/linux/pci.h:434

Líneas 434–434; tipo `block`.

```text
/* Page Request Interface */
```

## 336. original/kernel-api/linux-5.10.260/include/linux/pci.h:436

Líneas 436–436; tipo `block`.

```text
/* Requires fundamental reset */
```

## 337. original/kernel-api/linux-5.10.260/include/linux/pci.h:443

Líneas 443–443; tipo `block`.

```text
/* SHPC owned by shpchp */
```

## 338. original/kernel-api/linux-5.10.260/include/linux/pci.h:444

Líneas 444–444; tipo `block`.

```text
/* Thunderbolt controller */
```

## 339. original/kernel-api/linux-5.10.260/include/linux/pci.h:445

Líneas 445–451; tipo `block`.

```text
/*
	 * Devices marked being untrusted are the ones that can potentially
	 * execute DMA attacks and similar. They are typically connected
	 * through external ports such as Thunderbolt but not limited to
	 * that. When an IOMMU is enabled they should be getting full
	 * mappings to make sure they cannot access arbitrary memory.
	 */
```

## 340. original/kernel-api/linux-5.10.260/include/linux/pci.h:453

Líneas 453–457; tipo `block`.

```text
/*
	 * Info from the platform, e.g., ACPI or device tree, may mark a
	 * device as "external-facing".  An external-facing device is
	 * itself internal but devices downstream from it are external.
	 */
```

## 341. original/kernel-api/linux-5.10.260/include/linux/pci.h:459

Líneas 459–459; tipo `block`.

```text
/* INTx masking can't be used */
```

## 342. original/kernel-api/linux-5.10.260/include/linux/pci.h:460

Líneas 460–460; tipo `block`.

```text
/* Intel bridge 1K I/O windows */
```

## 343. original/kernel-api/linux-5.10.260/include/linux/pci.h:462

Líneas 462–462; tipo `block`.

```text
/* Broken BARs; ignore them */
```

## 344. original/kernel-api/linux-5.10.260/include/linux/pci.h:463

Líneas 463–463; tipo `block`.

```text
/* Device probing in progress */
```

## 345. original/kernel-api/linux-5.10.260/include/linux/pci.h:464

Líneas 464–464; tipo `block`.

```text
/* Device capable of reporting link active */
```

## 346. original/kernel-api/linux-5.10.260/include/linux/pci.h:465

Líneas 465–465; tipo `block`.

```text
/* Don't scan for VFs after IOV enablement */
```

## 347. original/kernel-api/linux-5.10.260/include/linux/pci.h:466

Líneas 466–466; tipo `block`.

```text
/* No PCI_COMMAND_MEMORY */
```

## 348. original/kernel-api/linux-5.10.260/include/linux/pci.h:467

Líneas 467–467; tipo `block`.

```text
/* ROM BAR disable broken */
```

## 349. original/kernel-api/linux-5.10.260/include/linux/pci.h:469

Líneas 469–469; tipo `block`.

```text
/* pci_enable_device has been called */
```

## 350. original/kernel-api/linux-5.10.260/include/linux/pci.h:471

Líneas 471–471; tipo `block`.

```text
/* Config space saved at suspend time */
```

## 351. original/kernel-api/linux-5.10.260/include/linux/pci.h:473

Líneas 473–473; tipo `block`.

```text
/* Attribute descriptor for sysfs ROM entry */
```

## 352. original/kernel-api/linux-5.10.260/include/linux/pci.h:474

Líneas 474–474; tipo `block`.

```text
/* Display of ROM attribute enabled? */
```

## 353. original/kernel-api/linux-5.10.260/include/linux/pci.h:475

Líneas 475–475; tipo `block`.

```text
/* sysfs file for resources */
```

## 354. original/kernel-api/linux-5.10.260/include/linux/pci.h:476

Líneas 476–476; tipo `block`.

```text
/* sysfs file for WC mapping of resources */
```

## 355. original/kernel-api/linux-5.10.260/include/linux/pci.h:479

Líneas 479–479; tipo `block`.

```text
/* No compl for some cmds */
```

## 356. original/kernel-api/linux-5.10.260/include/linux/pci.h:497

Líneas 497–497; tipo `block`.

```text
/* PF: SR-IOV info */
```

## 357. original/kernel-api/linux-5.10.260/include/linux/pci.h:498

Líneas 498–498; tipo `block`.

```text
/* VF: related PF */
```

## 358. original/kernel-api/linux-5.10.260/include/linux/pci.h:500

Líneas 500–500; tipo `block`.

```text
/* ATS Capability offset */
```

## 359. original/kernel-api/linux-5.10.260/include/linux/pci.h:501

Líneas 501–501; tipo `block`.

```text
/* ATS Smallest Translation Unit */
```

## 360. original/kernel-api/linux-5.10.260/include/linux/pci.h:504

Líneas 504–504; tipo `block`.

```text
/* PRI Capability offset */
```

## 361. original/kernel-api/linux-5.10.260/include/linux/pci.h:505

Líneas 505–505; tipo `block`.

```text
/* Number of PRI requests allocated */
```

## 362. original/kernel-api/linux-5.10.260/include/linux/pci.h:506

Líneas 506–506; tipo `block`.

```text
/* PRG Response PASID Required */
```

## 363. original/kernel-api/linux-5.10.260/include/linux/pci.h:509

Líneas 509–509; tipo `block`.

```text
/* PASID Capability offset */
```

## 364. original/kernel-api/linux-5.10.260/include/linux/pci.h:515

Líneas 515–515; tipo `block`.

```text
/* ACS Capability offset */
```

## 365. original/kernel-api/linux-5.10.260/include/linux/pci.h:516

Líneas 516–516; tipo `block`.

```text
/* Physical address if not from BAR */
```

## 366. original/kernel-api/linux-5.10.260/include/linux/pci.h:517

Líneas 517–517; tipo `block`.

```text
/* Length if not from BAR */
```

## 367. original/kernel-api/linux-5.10.260/include/linux/pci.h:518

Líneas 518–518; tipo `block`.

```text
/* Driver name to force a match */
```

## 368. original/kernel-api/linux-5.10.260/include/linux/pci.h:520

Líneas 520–520; tipo `block`.

```text
/* Private flags for the PCI driver */
```

## 369. original/kernel-api/linux-5.10.260/include/linux/pci.h:542

Líneas 542–549; tipo `block`.

```text
/*
 * Currently in ACPI spec, for each PCI host bridge, PCI Segment
 * Group number is limited to a 16-bit value, therefore (int)-1 is
 * not a valid PCI domain number, and can be used as a sentinel
 * value indicating ->domain_nr is not set by the driver (and
 * CONFIG_PCI_DOMAINS_GENERIC=y archs will set it with
 * pci_bus_find_domain_nr()).
 */
```

## 370. original/kernel-api/linux-5.10.260/include/linux/pci.h:554

Líneas 554–554; tipo `block`.

```text
/* Root bus */
```

## 371. original/kernel-api/linux-5.10.260/include/linux/pci.h:560

Líneas 560–560; tipo `block`.

```text
/* resource_entry */
```

## 372. original/kernel-api/linux-5.10.260/include/linux/pci.h:561

Líneas 561–561; tipo `block`.

```text
/* dma ranges resource list */
```

## 373. original/kernel-api/linux-5.10.260/include/linux/pci.h:562

Líneas 562–562; tipo `block`.

```text
/* Platform IRQ swizzler */
```

## 374. original/kernel-api/linux-5.10.260/include/linux/pci.h:567

Líneas 567–567; tipo `block`.

```text
/* For entire hierarchy */
```

## 375. original/kernel-api/linux-5.10.260/include/linux/pci.h:568

Líneas 568–568; tipo `block`.

```text
/* No Extended Tags */
```

## 376. original/kernel-api/linux-5.10.260/include/linux/pci.h:569

Líneas 569–569; tipo `block`.

```text
/* No Increase MRRS */
```

## 377. original/kernel-api/linux-5.10.260/include/linux/pci.h:570

Líneas 570–570; tipo `block`.

```text
/* OS may use PCIe AER */
```

## 378. original/kernel-api/linux-5.10.260/include/linux/pci.h:571

Líneas 571–571; tipo `block`.

```text
/* OS may use PCIe hotplug */
```

## 379. original/kernel-api/linux-5.10.260/include/linux/pci.h:572

Líneas 572–572; tipo `block`.

```text
/* OS may use SHPC hotplug */
```

## 380. original/kernel-api/linux-5.10.260/include/linux/pci.h:573

Líneas 573–573; tipo `block`.

```text
/* OS may use PCIe PME */
```

## 381. original/kernel-api/linux-5.10.260/include/linux/pci.h:574

Líneas 574–574; tipo `block`.

```text
/* OS may use PCIe LTR */
```

## 382. original/kernel-api/linux-5.10.260/include/linux/pci.h:575

Líneas 575–575; tipo `block`.

```text
/* OS may use PCIe DPC */
```

## 383. original/kernel-api/linux-5.10.260/include/linux/pci.h:576

Líneas 576–576; tipo `block`.

```text
/* Preserve FW resource setup */
```

## 384. original/kernel-api/linux-5.10.260/include/linux/pci.h:577

Líneas 577–577; tipo `block`.

```text
/* Enable root bus sizing */
```

## 385. original/kernel-api/linux-5.10.260/include/linux/pci.h:579

Líneas 579–579; tipo `block`.

```text
/* Resource alignment requirements */
```

## 386. original/kernel-api/linux-5.10.260/include/linux/pci.h:612

Líneas 612–617; tipo `block`.

```text
/*
 * The first PCI_BRIDGE_RESOURCE_NUM PCI bus resources (those that correspond
 * to P2P or CardBus bridge windows) go in a table.  Additional ones (for
 * buses below host bridges or subtractive decode bridges) go in the list.
 * Use pci_bus_for_each_resource() to iterate through all the resources.
 */
```

## 387. original/kernel-api/linux-5.10.260/include/linux/pci.h:619

Líneas 619–624; tipo `block`.

```text
/*
 * PCI_SUBTRACTIVE_DECODE means the bridge forwards the window implicitly
 * and there's no way to program the bridge with the details of the window.
 * This does not apply to ACPI _CRS windows, even with the _DEC subtractive-
 * decode bit set, because they are explicit and can be programmed with _SRS.
 */
```

## 388. original/kernel-api/linux-5.10.260/include/linux/pci.h:633

Líneas 633–633; tipo `block`.

```text
/* These bits of resource flags tell us the PCI region flags */
```

## 389. original/kernel-api/linux-5.10.260/include/linux/pci.h:636

Líneas 636–636; tipo `block`.

```text
/* Node in list of buses */
```

## 390. original/kernel-api/linux-5.10.260/include/linux/pci.h:637

Líneas 637–637; tipo `block`.

```text
/* Parent bus this bridge is on */
```

## 391. original/kernel-api/linux-5.10.260/include/linux/pci.h:638

Líneas 638–638; tipo `block`.

```text
/* List of child buses */
```

## 392. original/kernel-api/linux-5.10.260/include/linux/pci.h:639

Líneas 639–639; tipo `block`.

```text
/* List of devices on this bus */
```

## 393. original/kernel-api/linux-5.10.260/include/linux/pci.h:640

Líneas 640–640; tipo `block`.

```text
/* Bridge device as seen by parent */
```

## 394. original/kernel-api/linux-5.10.260/include/linux/pci.h:641

Líneas 641–642; tipo `block`.

```text
/* List of slots on this bus;
					   protected by pci_slot_mutex */
```

## 395. original/kernel-api/linux-5.10.260/include/linux/pci.h:644

Líneas 644–644; tipo `block`.

```text
/* Address space routed to this bus */
```

## 396. original/kernel-api/linux-5.10.260/include/linux/pci.h:645

Líneas 645–645; tipo `block`.

```text
/* Bus numbers routed to this bus */
```

## 397. original/kernel-api/linux-5.10.260/include/linux/pci.h:647

Líneas 647–647; tipo `block`.

```text
/* Configuration access functions */
```

## 398. original/kernel-api/linux-5.10.260/include/linux/pci.h:648

Líneas 648–648; tipo `block`.

```text
/* MSI controller */
```

## 399. original/kernel-api/linux-5.10.260/include/linux/pci.h:649

Líneas 649–649; tipo `block`.

```text
/* Hook for sys-specific extension */
```

## 400. original/kernel-api/linux-5.10.260/include/linux/pci.h:650

Líneas 650–650; tipo `block`.

```text
/* Directory entry in /proc/bus/pci */
```

## 401. original/kernel-api/linux-5.10.260/include/linux/pci.h:652

Líneas 652–652; tipo `block`.

```text
/* Bus number */
```

## 402. original/kernel-api/linux-5.10.260/include/linux/pci.h:653

Líneas 653–653; tipo `block`.

```text
/* Number of primary bridge */
```

## 403. original/kernel-api/linux-5.10.260/include/linux/pci.h:654

Líneas 654–654; tipo `block`.

```text
/* enum pci_bus_speed */
```

## 404. original/kernel-api/linux-5.10.260/include/linux/pci.h:655

Líneas 655–655; tipo `block`.

```text
/* enum pci_bus_speed */
```

## 405. original/kernel-api/linux-5.10.260/include/linux/pci.h:662

Líneas 662–662; tipo `block`.

```text
/* Manage NO_ISA/FBB/et al behaviors */
```

## 406. original/kernel-api/linux-5.10.260/include/linux/pci.h:663

Líneas 663–663; tipo `block`.

```text
/* Inherited by child buses */
```

## 407. original/kernel-api/linux-5.10.260/include/linux/pci.h:666

Líneas 666–666; tipo `block`.

```text
/* Legacy I/O for this bus */
```

## 408. original/kernel-api/linux-5.10.260/include/linux/pci.h:667

Líneas 667–667; tipo `block`.

```text
/* Legacy mem */
```

## 409. original/kernel-api/linux-5.10.260/include/linux/pci.h:669

Líneas 669–669; tipo `block`.

```text
/* warned about RW1C config write */
```

## 410. original/kernel-api/linux-5.10.260/include/linux/pci.h:679

Líneas 679–686; tipo `block`.

```text
/*
 * Returns true if the PCI bus is root (behind host-PCI bridge),
 * false otherwise
 *
 * Some code assumes that "bus->self == NULL" means that bus is a root bus.
 * This is incorrect because "virtual" buses added for SR-IOV (via
 * virtfn_add_bus()) have "bus->self == NULL" but are not root buses.
 */
```

## 411. original/kernel-api/linux-5.10.260/include/linux/pci.h:692

Líneas 692–698; tipo `block`.

```text
/**
 * pci_is_bridge - check if the PCI device is a bridge
 * @dev: PCI device
 *
 * Return true if the PCI device is bridge whether it has subordinate
 * or not.
 */
```

## 412. original/kernel-api/linux-5.10.260/include/linux/pci.h:727

Líneas 727–727; tipo `block`.

```text
/* Error values that may be returned by PCI functions */
```

## 413. original/kernel-api/linux-5.10.260/include/linux/pci.h:736

Líneas 736–736; tipo `block`.

```text
/* Translate above to generic errno for passing back through non-PCI code */
```

## 414. original/kernel-api/linux-5.10.260/include/linux/pci.h:740

Líneas 740–740; tipo `block`.

```text
/* Assume already errno */
```

## 415. original/kernel-api/linux-5.10.260/include/linux/pci.h:760

Líneas 760–760; tipo `block`.

```text
/* Low-level architecture-dependent routines */
```

## 416. original/kernel-api/linux-5.10.260/include/linux/pci.h:770

Líneas 770–773; tipo `block`.

```text
/*
 * ACPI needs to be able to access PCI config space before we've done a
 * PCI bus scan and created pci_bus structures.
 */
```

## 417. original/kernel-api/linux-5.10.260/include/linux/pci.h:791

Líneas 791–791; tipo `block`.

```text
/* Protects list, index */
```

## 418. original/kernel-api/linux-5.10.260/include/linux/pci.h:792

Líneas 792–792; tipo `block`.

```text
/* For IDs added at runtime */
```

## 419. original/kernel-api/linux-5.10.260/include/linux/pci.h:796

Líneas 796–801; tipo `block`.

```text
/*
 * PCI Error Recovery System (PCI-ERS).  If a PCI device driver provides
 * a set of callbacks in struct pci_error_handlers, that device driver
 * will be notified of PCI bus errors, and will be driven to recovery
 * when an error occurs.
 */
```

## 420. original/kernel-api/linux-5.10.260/include/linux/pci.h:806

Líneas 806–806; tipo `block`.

```text
/* No result/none/not supported in device driver */
```

## 421. original/kernel-api/linux-5.10.260/include/linux/pci.h:809

Líneas 809–809; tipo `block`.

```text
/* Device driver can recover without slot reset */
```

## 422. original/kernel-api/linux-5.10.260/include/linux/pci.h:812

Líneas 812–812; tipo `block`.

```text
/* Device driver wants slot to be reset */
```

## 423. original/kernel-api/linux-5.10.260/include/linux/pci.h:815

Líneas 815–815; tipo `block`.

```text
/* Device has completely failed, is unrecoverable */
```

## 424. original/kernel-api/linux-5.10.260/include/linux/pci.h:818

Líneas 818–818; tipo `block`.

```text
/* Device driver is fully recovered and operational */
```

## 425. original/kernel-api/linux-5.10.260/include/linux/pci.h:821

Líneas 821–821; tipo `block`.

```text
/* No AER capabilities registered for the driver */
```

## 426. original/kernel-api/linux-5.10.260/include/linux/pci.h:825

Líneas 825–825; tipo `block`.

```text
/* PCI bus error event callbacks */
```

## 427. original/kernel-api/linux-5.10.260/include/linux/pci.h:827

Líneas 827–827; tipo `block`.

```text
/* PCI bus error detected on this device */
```

## 428. original/kernel-api/linux-5.10.260/include/linux/pci.h:831

Líneas 831–831; tipo `block`.

```text
/* MMIO has been re-enabled, but not DMA */
```

## 429. original/kernel-api/linux-5.10.260/include/linux/pci.h:834

Líneas 834–834; tipo `block`.

```text
/* PCI slot has been reset */
```

## 430. original/kernel-api/linux-5.10.260/include/linux/pci.h:837

Líneas 837–837; tipo `block`.

```text
/* PCI function reset prepare or completed */
```

## 431. original/kernel-api/linux-5.10.260/include/linux/pci.h:841

Líneas 841–841; tipo `block`.

```text
/* Device driver may resume normal operations */
```

## 432. original/kernel-api/linux-5.10.260/include/linux/pci.h:848

Líneas 848–888; tipo `block`.

```text
/**
 * struct pci_driver - PCI driver structure
 * @node:	List of driver structures.
 * @name:	Driver name.
 * @id_table:	Pointer to table of device IDs the driver is
 *		interested in.  Most drivers should export this
 *		table using MODULE_DEVICE_TABLE(pci,...).
 * @probe:	This probing function gets called (during execution
 *		of pci_register_driver() for already existing
 *		devices or later if a new device gets inserted) for
 *		all PCI devices which match the ID table and are not
 *		"owned" by the other drivers yet. This function gets
 *		passed a "struct pci_dev \*" for each device whose
 *		entry in the ID table matches the device. The probe
 *		function returns zero when the driver chooses to
 *		take "ownership" of the device or an error code
 *		(negative number) otherwise.
 *		The probe function always gets called from process
 *		context, so it can sleep.
 * @remove:	The remove() function gets called whenever a device
 *		being handled by this driver is removed (either during
 *		deregistration of the driver or when it's manually
 *		pulled out of a hot-pluggable slot).
 *		The remove function always gets called from process
 *		context, so it can sleep.
 * @suspend:	Put device into low power state.
 * @resume:	Wake device from low power state.
 *		(Please see Documentation/power/pci.rst for descriptions
 *		of PCI Power Management and the related functions.)
 * @shutdown:	Hook into reboot_notifier_list (kernel/sys.c).
 *		Intended to stop any idling DMA operations.
 *		Useful for enabling wake-on-lan (NIC) or changing
 *		the power state of a device before reboot.
 *		e.g. drivers/net/e100.c.
 * @sriov_configure: Optional driver callback to allow configuration of
 *		number of VFs to enable via sysfs "sriov_numvfs" file.
 * @err_handler: See Documentation/PCI/pci-error-recovery.rst
 * @groups:	Sysfs attribute groups.
 * @driver:	Driver model structure.
 * @dynids:	List of dynamically added device IDs.
 */
```

## 433. original/kernel-api/linux-5.10.260/include/linux/pci.h:892

Líneas 892–892; tipo `block`.

```text
/* Must be non-NULL for probe to be called */
```

## 434. original/kernel-api/linux-5.10.260/include/linux/pci.h:893

Líneas 893–893; tipo `block`.

```text
/* New device inserted */
```

## 435. original/kernel-api/linux-5.10.260/include/linux/pci.h:894

Líneas 894–894; tipo `block`.

```text
/* Device removed (NULL if not a hot-plug capable driver) */
```

## 436. original/kernel-api/linux-5.10.260/include/linux/pci.h:895

Líneas 895–895; tipo `block`.

```text
/* Device suspended */
```

## 437. original/kernel-api/linux-5.10.260/include/linux/pci.h:896

Líneas 896–896; tipo `block`.

```text
/* Device woken up */
```

## 438. original/kernel-api/linux-5.10.260/include/linux/pci.h:898

Líneas 898–898; tipo `block`.

```text
/* On PF */
```

## 439. original/kernel-api/linux-5.10.260/include/linux/pci.h:907

Líneas 907–915; tipo `block`.

```text
/**
 * PCI_DEVICE - macro used to describe a specific PCI device
 * @vend: the 16 bit PCI Vendor ID
 * @dev: the 16 bit PCI Device ID
 *
 * This macro is used to create a struct pci_device_id that matches a
 * specific device.  The subvendor and subdevice fields will be set to
 * PCI_ANY_ID.
 */
```

## 440. original/kernel-api/linux-5.10.260/include/linux/pci.h:920

Líneas 920–929; tipo `block`.

```text
/**
 * PCI_DEVICE_SUB - macro used to describe a specific PCI device with subsystem
 * @vend: the 16 bit PCI Vendor ID
 * @dev: the 16 bit PCI Device ID
 * @subvend: the 16 bit PCI Subvendor ID
 * @subdev: the 16 bit PCI Subdevice ID
 *
 * This macro is used to create a struct pci_device_id that matches a
 * specific device with subsystem information.
 */
```

## 441. original/kernel-api/linux-5.10.260/include/linux/pci.h:934

Líneas 934–942; tipo `block`.

```text
/**
 * PCI_DEVICE_CLASS - macro used to describe a specific PCI device class
 * @dev_class: the class, subclass, prog-if triple for this device
 * @dev_class_mask: the class mask for this device
 *
 * This macro is used to create a struct pci_device_id that matches a
 * specific PCI class.  The vendor, device, subvendor, and subdevice
 * fields will be set to PCI_ANY_ID.
 */
```

## 442. original/kernel-api/linux-5.10.260/include/linux/pci.h:948

Líneas 948–957; tipo `block`.

```text
/**
 * PCI_VDEVICE - macro used to describe a specific PCI device in short form
 * @vend: the vendor name
 * @dev: the 16 bit PCI Device ID
 *
 * This macro is used to create a struct pci_device_id that matches a
 * specific PCI device.  The subvendor, and subdevice fields will be set
 * to PCI_ANY_ID. The macro allows the next field to follow as the device
 * private data.
 */
```

## 443. original/kernel-api/linux-5.10.260/include/linux/pci.h:962

Líneas 962–971; tipo `block`.

```text
/**
 * PCI_DEVICE_DATA - macro used to describe a specific PCI device in very short form
 * @vend: the vendor name (without PCI_VENDOR_ID_ prefix)
 * @dev: the device name (without PCI_DEVICE_ID_<vend>_ prefix)
 * @data: the driver data to be filled
 *
 * This macro is used to create a struct pci_device_id that matches a
 * specific PCI device.  The subvendor, and subdevice fields will be set
 * to PCI_ANY_ID.
 */
```

## 444. original/kernel-api/linux-5.10.260/include/linux/pci.h:978

Líneas 978–978; tipo `block`.

```text
/* Ignore firmware setup */
```

## 445. original/kernel-api/linux-5.10.260/include/linux/pci.h:979

Líneas 979–979; tipo `block`.

```text
/* Reassign all bus numbers */
```

## 446. original/kernel-api/linux-5.10.260/include/linux/pci.h:980

Líneas 980–980; tipo `block`.

```text
/* Use existing setup */
```

## 447. original/kernel-api/linux-5.10.260/include/linux/pci.h:981

Líneas 981–981; tipo `block`.

```text
/* Don't do ISA alignment */
```

## 448. original/kernel-api/linux-5.10.260/include/linux/pci.h:982

Líneas 982–982; tipo `block`.

```text
/* Enable domains in /proc */
```

## 449. original/kernel-api/linux-5.10.260/include/linux/pci.h:983

Líneas 983–983; tipo `block`.

```text
/* ... except domain 0 */
```

## 450. original/kernel-api/linux-5.10.260/include/linux/pci.h:984

Líneas 984–984; tipo `block`.

```text
/* Scan all, not just dev 0 */
```

## 451. original/kernel-api/linux-5.10.260/include/linux/pci.h:987

Líneas 987–987; tipo `block`.

```text
/* Allow legacy interrupts */
```

## 452. original/kernel-api/linux-5.10.260/include/linux/pci.h:988

Líneas 988–988; tipo `block`.

```text
/* Allow MSI interrupts */
```

## 453. original/kernel-api/linux-5.10.260/include/linux/pci.h:989

Líneas 989–989; tipo `block`.

```text
/* Allow MSI-X interrupts */
```

## 454. original/kernel-api/linux-5.10.260/include/linux/pci.h:990

Líneas 990–990; tipo `block`.

```text
/* Auto-assign affinity */
```

## 455. original/kernel-api/linux-5.10.260/include/linux/pci.h:992

Líneas 992–992; tipo `block`.

```text
/* These external functions are only available when PCI support is enabled */
```

## 456. original/kernel-api/linux-5.10.260/include/linux/pci.h:1005

Líneas 1005–1005; tipo `block`.

```text
/* Don't touch MPS at all */
```

## 457. original/kernel-api/linux-5.10.260/include/linux/pci.h:1006

Líneas 1006–1006; tipo `block`.

```text
/* Ensure MPS matches upstream bridge */
```

## 458. original/kernel-api/linux-5.10.260/include/linux/pci.h:1007

Líneas 1007–1007; tipo `block`.

```text
/* Use largest MPS boot-time devices support */
```

## 459. original/kernel-api/linux-5.10.260/include/linux/pci.h:1008

Líneas 1008–1008; tipo `block`.

```text
/* Use MPS and MRRS for best performance */
```

## 460. original/kernel-api/linux-5.10.260/include/linux/pci.h:1009

Líneas 1009–1009; tipo `block`.

```text
/* Set MPS = 128 for all devices */
```

## 461. original/kernel-api/linux-5.10.260/include/linux/pci.h:1016

Líneas 1016–1017; tipo `block`.

```text
/* Do NOT directly access these two variables, unless you are arch-specific PCI
 * code, or PCI core code. */
```

## 462. original/kernel-api/linux-5.10.260/include/linux/pci.h:1018

Líneas 1018–1018; tipo `block`.

```text
/* List of all known PCI buses */
```

## 463. original/kernel-api/linux-5.10.260/include/linux/pci.h:1019

Líneas 1019–1019; tipo `block`.

```text
/* Some device drivers need know if PCI is initiated */
```

## 464. original/kernel-api/linux-5.10.260/include/linux/pci.h:1028

Líneas 1028–1028; tipo `block`.

```text
/* Architecture-specific versions may override this (weak) */
```

## 465. original/kernel-api/linux-5.10.260/include/linux/pci.h:1031

Líneas 1031–1031; tipo `block`.

```text
/* Used only when drivers/pci/setup.c is used */
```

## 466. original/kernel-api/linux-5.10.260/include/linux/pci.h:1036

Líneas 1036–1036; tipo `block`.

```text
/* Weak but can be overridden by arch */
```

## 467. original/kernel-api/linux-5.10.260/include/linux/pci.h:1039

Líneas 1039–1039; tipo `block`.

```text
/* Generic PCI functions used internally */
```

## 468. original/kernel-api/linux-5.10.260/include/linux/pci.h:1095

Líneas 1095–1095; tipo `block`.

```text
/* Generic PCI functions exported to card drivers */
```

## 469. original/kernel-api/linux-5.10.260/include/linux/pci.h:1182

Líneas 1182–1182; tipo `block`.

```text
/* User-space driven config access */
```

## 470. original/kernel-api/linux-5.10.260/include/linux/pci.h:1199

Líneas 1199–1202; tipo `block`.

```text
/*
	 * INTx masking is supported if PCI_COMMAND_INTX_DISABLE is
	 * writable and no quirk has marked the feature broken.
	 */
```

## 471. original/kernel-api/linux-5.10.260/include/linux/pci.h:1272

Líneas 1272–1272; tipo `block`.

```text
/* ROM control related routines */
```

## 472. original/kernel-api/linux-5.10.260/include/linux/pci.h:1278

Líneas 1278–1278; tipo `block`.

```text
/* Power management related routines */
```

## 473. original/kernel-api/linux-5.10.260/include/linux/pci.h:1308

Líneas 1308–1308; tipo `block`.

```text
/* For use by arch with custom probe code */
```

## 474. original/kernel-api/linux-5.10.260/include/linux/pci.h:1312

Líneas 1312–1312; tipo `block`.

```text
/* Functions for PCI Hotplug drivers to use */
```

## 475. original/kernel-api/linux-5.10.260/include/linux/pci.h:1319

Líneas 1319–1319; tipo `block`.

```text
/* Vital Product Data routines */
```

## 476. original/kernel-api/linux-5.10.260/include/linux/pci.h:1324

Líneas 1324–1324; tipo `block`.

```text
/* Helper functions for low-level code (drivers/pci/setup-[bus,res].c) */
```

## 477. original/kernel-api/linux-5.10.260/include/linux/pci.h:1350

Líneas 1350–1350; tipo `block`.

```text
/* drivers/pci/bus.c */
```

## 478. original/kernel-api/linux-5.10.260/include/linux/pci.h:1362

Líneas 1362–1362; tipo `block`.

```text
/* Temporary until new and working PCI SBR API in place */
```

## 479. original/kernel-api/linux-5.10.260/include/linux/pci.h:1403

Líneas 1403–1403; tipo `block`.

```text
/* Proper probing supporting hot-pluggable devices */
```

## 480. original/kernel-api/linux-5.10.260/include/linux/pci.h:1407

Líneas 1407–1407; tipo `block`.

```text
/* pci_register_driver() must be a macro so KBUILD_MODNAME can be expanded */
```

## 481. original/kernel-api/linux-5.10.260/include/linux/pci.h:1413

Líneas 1413–1420; tipo `block`.

```text
/**
 * module_pci_driver() - Helper macro for registering a PCI driver
 * @__pci_driver: pci_driver struct
 *
 * Helper macro for PCI drivers which do not do anything special in module
 * init/exit. This eliminates a lot of boilerplate. Each module may only
 * use this macro once, and calling it replaces module_init() and module_exit()
 */
```

## 482. original/kernel-api/linux-5.10.260/include/linux/pci.h:1424

Líneas 1424–1431; tipo `block`.

```text
/**
 * builtin_pci_driver() - Helper macro for registering a PCI driver
 * @__pci_driver: pci_driver struct
 *
 * Helper macro for PCI drivers which do not do anything special in their
 * init code. This eliminates a lot of boilerplate. Each driver may only
 * use this macro once, and calling it replaces device_initcall(...)
 */
```

## 483. original/kernel-api/linux-5.10.260/include/linux/pci.h:1460

Líneas 1460–1465; tipo `block`.

```text
/*
 * Virtual interrupts allow for more interrupts to be allocated
 * than the device has interrupts for. These are not programmed
 * into the device's MSI-X table and must be handled by some
 * other driver means.
 */
```

## 484. original/kernel-api/linux-5.10.260/include/linux/pci.h:1471

Líneas 1471–1471; tipo `block`.

```text
/* kmem_cache style wrapper around pci_alloc_consistent() */
```

## 485. original/kernel-api/linux-5.10.260/include/linux/pci.h:1485

Líneas 1485–1485; tipo `block`.

```text
/* Kernel uses to write allocated vector */
```

## 486. original/kernel-api/linux-5.10.260/include/linux/pci.h:1486

Líneas 1486–1486; tipo `block`.

```text
/* Driver uses to specify entry, OS writes */
```

## 487. original/kernel-api/linux-5.10.260/include/linux/pci.h:1558

Líneas 1558–1573; tipo `block`.

```text
/**
 * pci_irqd_intx_xlate() - Translate PCI INTx value to an IRQ domain hwirq
 * @d: the INTx IRQ domain
 * @node: the DT node for the device whose interrupt we're translating
 * @intspec: the interrupt specifier data from the DT
 * @intsize: the number of entries in @intspec
 * @out_hwirq: pointer at which to write the hwirq number
 * @out_type: pointer at which to write the interrupt type
 *
 * Translate a PCI INTx interrupt number from device tree in the range 1-4, as
 * stored in the standard PCI_INTERRUPT_PIN register, to a value in the range
 * 0-3 suitable for use in a 4 entry IRQ domain. That is, subtract one from the
 * INTx value to obtain the hwirq number.
 *
 * Returns 0 on success, or -EINVAL if the interrupt specifier is out of range.
 */
```

## 488. original/kernel-api/linux-5.10.260/include/linux/pci.h:1641

Líneas 1641–1645; tipo `block`.

```text
/*
 * PCI domain support.  Sometimes called PCI segment (eg by ACPI),
 * a PCI domain is defined to be a set of PCI buses which share
 * configuration space.
 */
```

## 489. original/kernel-api/linux-5.10.260/include/linux/pci.h:1652

Líneas 1652–1652; tipo `block`.

```text
/* CONFIG_PCI_DOMAINS */
```

## 490. original/kernel-api/linux-5.10.260/include/linux/pci.h:1654

Líneas 1654–1658; tipo `block`.

```text
/*
 * Generic implementation for PCI domain support. If your
 * architecture does not need custom management of PCI
 * domains then this implementation will be used
 */
```

## 491. original/kernel-api/linux-5.10.260/include/linux/pci.h:1674

Líneas 1674–1674; tipo `block`.

```text
/* Some architectures require additional setup to direct VGA traffic */
```

## 492. original/kernel-api/linux-5.10.260/include/linux/pci.h:1707

Líneas 1707–1707; tipo `block`.

```text
/* CONFIG_PCI is not enabled */
```

## 493. original/kernel-api/linux-5.10.260/include/linux/pci.h:1714

Líneas 1714–1717; tipo `block`.

```text
/*
 * If the system does not have PCI, clearly these return errors.  Define
 * these as simple inline functions to avoid hair in drivers.
 */
```

## 494. original/kernel-api/linux-5.10.260/include/linux/pci.h:1774

Líneas 1774–1774; tipo `block`.

```text
/* Power management related routines */
```

## 495. original/kernel-api/linux-5.10.260/include/linux/pci.h:1838

Líneas 1838–1838; tipo `block`.

```text
/* CONFIG_PCI */
```

## 496. original/kernel-api/linux-5.10.260/include/linux/pci.h:1848

Líneas 1848–1848; tipo `block`.

```text
/* Include architecture-dependent settings and functions */
```

## 497. original/kernel-api/linux-5.10.260/include/linux/pci.h:1852

Líneas 1852–1863; tipo `block`.

```text
/* These two functions provide almost identical functionality. Depending
 * on the architecture, one will be implemented as a wrapper around the
 * other (in drivers/pci/mmap.c).
 *
 * pci_mmap_resource_range() maps a specific BAR, and vm->vm_pgoff
 * is expected to be an offset within that region.
 *
 * pci_mmap_page_range() is the legacy architecture-specific interface,
 * which accepts a "user visible" resource address converted by
 * pci_resource_to_user(), as used in the legacy mmap() interface in
 * /proc/bus/pci/.
 */
```

## 498. original/kernel-api/linux-5.10.260/include/linux/pci.h:1886

Líneas 1886–1889; tipo `block`.

```text
/*
 * These helpers provide future and backwards compatibility
 * for accessing popular PCI BAR info
 */
```

## 499. original/kernel-api/linux-5.10.260/include/linux/pci.h:1901

Líneas 1901–1905; tipo `block`.

```text
/*
 * Similar to the helpers above, these manipulate per-pci_dev
 * driver-specific data.  They are really just a wrapper around
 * the generic device structure functions of these calls.
 */
```

## 500. original/kernel-api/linux-5.10.260/include/linux/pci.h:1925

Líneas 1925–1930; tipo `block`.

```text
/*
 * The world is not perfect and supplies us with broken PCI devices.
 * For at least a part of these bugs we need a work-around, so both
 * generic (drivers/pci/quirks.c) and per-architecture code can define
 * fixup hooks to be called for particular buggy devices.
 */
```

## 501. original/kernel-api/linux-5.10.260/include/linux/pci.h:1933

Líneas 1933–1933; tipo `block`.

```text
/* Or PCI_ANY_ID */
```

## 502. original/kernel-api/linux-5.10.260/include/linux/pci.h:1934

Líneas 1934–1934; tipo `block`.

```text
/* Or PCI_ANY_ID */
```

## 503. original/kernel-api/linux-5.10.260/include/linux/pci.h:1935

Líneas 1935–1935; tipo `block`.

```text
/* Or PCI_ANY_ID */
```

## 504. original/kernel-api/linux-5.10.260/include/linux/pci.h:1936

Líneas 1936–1936; tipo `block`.

```text
/* should be 0, 8, 16 */
```

## 505. original/kernel-api/linux-5.10.260/include/linux/pci.h:1945

Líneas 1945–1945; tipo `block`.

```text
/* Before probing BARs */
```

## 506. original/kernel-api/linux-5.10.260/include/linux/pci.h:1946

Líneas 1946–1946; tipo `block`.

```text
/* After reading configuration header */
```

## 507. original/kernel-api/linux-5.10.260/include/linux/pci.h:1947

Líneas 1947–1947; tipo `block`.

```text
/* Final phase of device fixups */
```

## 508. original/kernel-api/linux-5.10.260/include/linux/pci.h:1948

Líneas 1948–1948; tipo `block`.

```text
/* pci_enable_device() time */
```

## 509. original/kernel-api/linux-5.10.260/include/linux/pci.h:1949

Líneas 1949–1949; tipo `block`.

```text
/* pci_device_resume() */
```

## 510. original/kernel-api/linux-5.10.260/include/linux/pci.h:1950

Líneas 1950–1950; tipo `block`.

```text
/* pci_device_suspend() */
```

## 511. original/kernel-api/linux-5.10.260/include/linux/pci.h:1951

Líneas 1951–1951; tipo `block`.

```text
/* pci_device_resume_early() */
```

## 512. original/kernel-api/linux-5.10.260/include/linux/pci.h:1952

Líneas 1952–1952; tipo `block`.

```text
/* pci_device_suspend_late() */
```

## 513. original/kernel-api/linux-5.10.260/include/linux/pci.h:1970

Líneas 1970–1970; tipo `block`.

```text
/* Anonymous variables would be nice... */
```

## 514. original/kernel-api/linux-5.10.260/include/linux/pci.h:2052

Líneas 2052–2052; tipo `block`.

```text
/* No PCI PCI DMA */
```

## 515. original/kernel-api/linux-5.10.260/include/linux/pci.h:2057

Líneas 2057–2057; tipo `block`.

```text
/* Need low latency setting */
```

## 516. original/kernel-api/linux-5.10.260/include/linux/pci.h:2058

Líneas 2058–2058; tipo `block`.

```text
/* No PCI to AGP DMA */
```

## 517. original/kernel-api/linux-5.10.260/include/linux/pci.h:2065

Líneas 2065–2065; tipo `block`.

```text
/* Architecture-specific versions may override these (weak) */
```

## 518. original/kernel-api/linux-5.10.260/include/linux/pci.h:2112

Líneas 2112–2112; tipo `block`.

```text
/* Arch may override these (weak) */
```

## 519. original/kernel-api/linux-5.10.260/include/linux/pci.h:2158

Líneas 2158–2168; tipo `block`.

```text
/**
 * pci_pcie_cap - get the saved PCIe capability offset
 * @dev: PCI device
 *
 * PCIe capability offset is calculated at PCI device initialization
 * time and saved in the data structure. This function returns saved
 * PCIe capability offset. Using this instead of pci_find_capability()
 * reduces unnecessary search in the PCI configuration space. If you
 * need to calculate PCIe capability offset from raw device for some
 * reasons, please use pci_find_capability() instead.
 */
```

## 520. original/kernel-api/linux-5.10.260/include/linux/pci.h:2174

Líneas 2174–2179; tipo `block`.

```text
/**
 * pci_is_pcie - check if the PCI device is PCI Express capable
 * @dev: PCI device
 *
 * Returns: true if the PCI device is PCI Express capable, false otherwise.
 */
```

## 521. original/kernel-api/linux-5.10.260/include/linux/pci.h:2185

Líneas 2185–2188; tipo `block`.

```text
/**
 * pcie_caps_reg - get the PCIe Capabilities Register
 * @dev: PCI device
 */
```

## 522. original/kernel-api/linux-5.10.260/include/linux/pci.h:2194

Líneas 2194–2197; tipo `block`.

```text
/**
 * pci_pcie_type - get the PCIe device/port type
 * @dev: PCI device
 */
```

## 523. original/kernel-api/linux-5.10.260/include/linux/pci.h:2203

Líneas 2203–2209; tipo `block`.

```text
/**
 * pcie_find_root_port - Get the PCIe root port device
 * @dev: PCI device
 *
 * Traverse up the parent chain and return the PCIe Root Port PCI Device
 * for a given PCI/PCIe Device.
 */
```

## 524. original/kernel-api/linux-5.10.260/include/linux/pci.h:2233

Líneas 2233–2233; tipo `block`.

```text
/* Large Resource Data Type */
```

## 525. original/kernel-api/linux-5.10.260/include/linux/pci.h:2236

Líneas 2236–2236; tipo `block`.

```text
/* Large Resource Data Type Tag Item Names */
```

## 526. original/kernel-api/linux-5.10.260/include/linux/pci.h:2237

Líneas 2237–2237; tipo `block`.

```text
/* Identifier String */
```

## 527. original/kernel-api/linux-5.10.260/include/linux/pci.h:2238

Líneas 2238–2238; tipo `block`.

```text
/* Read-Only Data */
```

## 528. original/kernel-api/linux-5.10.260/include/linux/pci.h:2239

Líneas 2239–2239; tipo `block`.

```text
/* Read-Write Data */
```

## 529. original/kernel-api/linux-5.10.260/include/linux/pci.h:2245

Líneas 2245–2245; tipo `block`.

```text
/* Small Resource Data Type Tag Item Names */
```

## 530. original/kernel-api/linux-5.10.260/include/linux/pci.h:2246

Líneas 2246–2246; tipo `block`.

```text
/* End */
```

## 531. original/kernel-api/linux-5.10.260/include/linux/pci.h:2265

Líneas 2265–2270; tipo `block`.

```text
/**
 * pci_vpd_lrdt_size - Extracts the Large Resource Data Type length
 * @lrdt: Pointer to the beginning of the Large Resource Data Type tag
 *
 * Returns the extracted Large Resource Data Type length.
 */
```

## 532. original/kernel-api/linux-5.10.260/include/linux/pci.h:2276

Líneas 2276–2281; tipo `block`.

```text
/**
 * pci_vpd_lrdt_tag - Extracts the Large Resource Data Type Tag Item
 * @lrdt: Pointer to the beginning of the Large Resource Data Type tag
 *
 * Returns the extracted Large Resource Data Type Tag item.
 */
```

## 533. original/kernel-api/linux-5.10.260/include/linux/pci.h:2287

Líneas 2287–2292; tipo `block`.

```text
/**
 * pci_vpd_srdt_size - Extracts the Small Resource Data Type length
 * @srdt: Pointer to the beginning of the Small Resource Data Type tag
 *
 * Returns the extracted Small Resource Data Type length.
 */
```

## 534. original/kernel-api/linux-5.10.260/include/linux/pci.h:2298

Líneas 2298–2303; tipo `block`.

```text
/**
 * pci_vpd_srdt_tag - Extracts the Small Resource Data Type Tag Item
 * @srdt: Pointer to the beginning of the Small Resource Data Type tag
 *
 * Returns the extracted Small Resource Data Type Tag Item.
 */
```

## 535. original/kernel-api/linux-5.10.260/include/linux/pci.h:2309

Líneas 2309–2314; tipo `block`.

```text
/**
 * pci_vpd_info_field_size - Extracts the information field length
 * @info_field: Pointer to the beginning of an information field header
 *
 * Returns the extracted information field length.
 */
```

## 536. original/kernel-api/linux-5.10.260/include/linux/pci.h:2320

Líneas 2320–2329; tipo `block`.

```text
/**
 * pci_vpd_find_tag - Locates the Resource Data Type tag provided
 * @buf: Pointer to buffered vpd data
 * @off: The offset into the buffer at which to begin the search
 * @len: The length of the vpd buffer
 * @rdt: The Resource Data Type to search for
 *
 * Returns the index where the Resource Data Type was found or
 * -ENOENT otherwise.
 */
```

## 537. original/kernel-api/linux-5.10.260/include/linux/pci.h:2332

Líneas 2332–2341; tipo `block`.

```text
/**
 * pci_vpd_find_info_keyword - Locates an information field keyword in the VPD
 * @buf: Pointer to buffered vpd data
 * @off: The offset into the buffer at which to begin the search
 * @len: The length of the buffer area, relative to off, in which to search
 * @kw: The keyword to search for
 *
 * Returns the index where the information field keyword was found or
 * -ENOENT otherwise.
 */
```

## 538. original/kernel-api/linux-5.10.260/include/linux/pci.h:2345

Líneas 2345–2345; tipo `block`.

```text
/* PCI <-> OF binding helpers */
```

## 539. original/kernel-api/linux-5.10.260/include/linux/pci.h:2351

Líneas 2351–2351; tipo `block`.

```text
/* Arch may override this (weak) */
```

## 540. original/kernel-api/linux-5.10.260/include/linux/pci.h:2354

Líneas 2354–2354; tipo `block`.

```text
/* CONFIG_OF */
```

## 541. original/kernel-api/linux-5.10.260/include/linux/pci.h:2357

Líneas 2357–2357; tipo `block`.

```text
/* CONFIG_OF */
```

## 542. original/kernel-api/linux-5.10.260/include/linux/pci.h:2395

Líneas 2395–2395; tipo `block`.

```text
/* Helper functions for operation of device flag */
```

## 543. original/kernel-api/linux-5.10.260/include/linux/pci.h:2409

Líneas 2409–2414; tipo `block`.

```text
/**
 * pci_ari_enabled - query ARI forwarding status
 * @bus: the PCI bus
 *
 * Returns true if ARI forwarding is enabled.
 */
```

## 544. original/kernel-api/linux-5.10.260/include/linux/pci.h:2420

Líneas 2420–2427; tipo `block`.

```text
/**
 * pci_is_thunderbolt_attached - whether device is on a Thunderbolt daisy chain
 * @pdev: PCI device to check
 *
 * Walk upwards from @pdev and check for each encountered bridge if it's part
 * of a Thunderbolt controller.  Reaching the host bridge means @pdev is not
 * Thunderbolt-attached.  (But rather soldered to the mainboard usually.)
 */
```

## 545. original/kernel-api/linux-5.10.260/include/linux/pci.h:2446

Líneas 2446–2446; tipo `block`.

```text
/* Provide the legacy pci_dma_* API */
```

## 546. original/kernel-api/linux-5.10.260/include/linux/pci.h:2475

Líneas 2475–2475; tipo `block`.

```text
/* LINUX_PCI_H */
```

## 547. original/kernel-api/linux-5.10.260/include/linux/pm.h:1

Líneas 1–1; tipo `block`.

```text
/* SPDX-License-Identifier: GPL-2.0-or-later */
```

## 548. original/kernel-api/linux-5.10.260/include/linux/pm.h:2

Líneas 2–6; tipo `block`.

```text
/*
 *  pm.h - Power management interface
 *
 *  Copyright (C) 2000 Andrew Henroid
 */
```

## 549. original/kernel-api/linux-5.10.260/include/linux/pm.h:19

Líneas 19–21; tipo `block`.

```text
/*
 * Callbacks for platform drivers to implement.
 */
```

## 550. original/kernel-api/linux-5.10.260/include/linux/pm.h:25

Líneas 25–25; tipo `block`.

```text
/* we have a circular dep with device.h */
```

## 551. original/kernel-api/linux-5.10.260/include/linux/pm.h:36

Líneas 36–36; tipo `block`.

```text
/* CONFIG_VT_CONSOLE_SLEEP */
```

## 552. original/kernel-api/linux-5.10.260/include/linux/pm.h:38

Líneas 38–40; tipo `block`.

```text
/*
 * Device power management
 */
```

## 553. original/kernel-api/linux-5.10.260/include/linux/pm.h:45

Líneas 45–45; tipo `block`.

```text
/* = "power" */
```

## 554. original/kernel-api/linux-5.10.260/include/linux/pm.h:54

Líneas 54–277; tipo `block`.

```text
/**
 * struct dev_pm_ops - device PM callbacks.
 *
 * @prepare: The principal role of this callback is to prevent new children of
 *	the device from being registered after it has returned (the driver's
 *	subsystem and generally the rest of the kernel is supposed to prevent
 *	new calls to the probe method from being made too once @prepare() has
 *	succeeded).  If @prepare() detects a situation it cannot handle (e.g.
 *	registration of a child already in progress), it may return -EAGAIN, so
 *	that the PM core can execute it once again (e.g. after a new child has
 *	been registered) to recover from the race condition.
 *	This method is executed for all kinds of suspend transitions and is
 *	followed by one of the suspend callbacks: @suspend(), @freeze(), or
 *	@poweroff().  If the transition is a suspend to memory or standby (that
 *	is, not related to hibernation), the return value of @prepare() may be
 *	used to indicate to the PM core to leave the device in runtime suspend
 *	if applicable.  Namely, if @prepare() returns a positive number, the PM
 *	core will understand that as a declaration that the device appears to be
 *	runtime-suspended and it may be left in that state during the entire
 *	transition and during the subsequent resume if all of its descendants
 *	are left in runtime suspend too.  If that happens, @complete() will be
 *	executed directly after @prepare() and it must ensure the proper
 *	functioning of the device after the system resume.
 *	The PM core executes subsystem-level @prepare() for all devices before
 *	starting to invoke suspend callbacks for any of them, so generally
 *	devices may be assumed to be functional or to respond to runtime resume
 *	requests while @prepare() is being executed.  However, device drivers
 *	may NOT assume anything about the availability of user space at that
 *	time and it is NOT valid to request firmware from within @prepare()
 *	(it's too late to do that).  It also is NOT valid to allocate
 *	substantial amounts of memory from @prepare() in the GFP_KERNEL mode.
 *	[To work around these limitations, drivers may register suspend and
 *	hibernation notifiers to be executed before the freezing of tasks.]
 *
 * @complete: Undo the changes made by @prepare().  This method is executed for
 *	all kinds of resume transitions, following one of the resume callbacks:
 *	@resume(), @thaw(), @restore().  Also called if the state transition
 *	fails before the driver's suspend callback: @suspend(), @freeze() or
 *	@poweroff(), can be executed (e.g. if the suspend callback fails for one
 *	of the other devices that the PM core has unsuccessfully attempted to
 *	suspend earlier).
 *	The PM core executes subsystem-level @complete() after it has executed
 *	the appropriate resume callbacks for all devices.  If the corresponding
 *	@prepare() at the beginning of the suspend transition returned a
 *	positive number and the device was left in runtime suspend (without
 *	executing any suspend and resume callbacks for it), @complete() will be
 *	the only callback executed for the device during resume.  In that case,
 *	@complete() must be prepared to do whatever is necessary to ensure the
 *	proper functioning of the device after the system resume.  To this end,
 *	@complete() can check the power.direct_complete flag of the device to
 *	learn whether (unset) or not (set) the previous suspend and resume
 *	callbacks have been executed for it.
 *
 * @suspend: Executed before putting the system into a sleep state in which the
 *	contents of main memory are preserved.  The exact action to perform
 *	depends on the device's subsystem (PM domain, device type, class or bus
 *	type), but generally the device must be quiescent after subsystem-level
 *	@suspend() has returned, so that it doesn't do any I/O or DMA.
 *	Subsystem-level @suspend() is executed for all devices after invoking
 *	subsystem-level @prepare() for all of them.
 *
 * @suspend_late: Continue operations started by @suspend().  For a number of
 *	devices @suspend_late() may point to the same callback routine as the
 *	runtime suspend callback.
 *
 * @resume: Executed after waking the system up from a sleep state in which the
 *	contents of main memory were preserved.  The exact action to perform
 *	depends on the device's subsystem, but generally the driver is expected
 *	to start working again, responding to hardware events and software
 *	requests (the device itself may be left in a low-power state, waiting
 *	for a runtime resume to occur).  The state of the device at the time its
 *	driver's @resume() callback is run depends on the platform and subsystem
 *	the device belongs to.  On most platforms, there are no restrictions on
 *	availability of resources like clocks during @resume().
 *	Subsystem-level @resume() is executed for all devices after invoking
 *	subsystem-level @resume_noirq() for all of them.
 *
 * @resume_early: Prepare to execute @resume().  For a number of devices
 *	@resume_early() may point to the same callback routine as the runtime
 *	resume callback.
 *
 * @freeze: Hibernation-specific, executed before creating a hibernation image.
 *	Analogous to @suspend(), but it should not enable the device to signal
 *	wakeup events or change its power state.  The majority of subsystems
 *	(with the notable exception of the PCI bus type) expect the driver-level
 *	@freeze() to save the device settings in memory to be used by @restore()
 *	during the subsequent resume from hibernation.
 *	Subsystem-level @freeze() is executed for all devices after invoking
 *	subsystem-level @prepare() for all of them.
 *
 * @freeze_late: Continue operations started by @freeze().  Analogous to
 *	@suspend_late(), but it should not enable the device to signal wakeup
 *	events or change its power state.
 *
 * @thaw: Hibernation-specific, executed after creating a hibernation image OR
 *	if the creation of an image has failed.  Also executed after a failing
 *	attempt to restore the contents of main memory from such an image.
 *	Undo the changes made by the preceding @freeze(), so the device can be
 *	operated in the same way as immediately before the call to @freeze().
 *	Subsystem-level @thaw() is executed for all devices after invoking
 *	subsystem-level @thaw_noirq() for all of them.  It also may be executed
 *	directly after @freeze() in case of a transition error.
 *
 * @thaw_early: Prepare to execute @thaw().  Undo the changes made by the
 *	preceding @freeze_late().
 *
 * @poweroff: Hibernation-specific, executed after saving a hibernation image.
 *	Analogous to @suspend(), but it need not save the device's settings in
 *	memory.
 *	Subsystem-level @poweroff() is executed for all devices after invoking
 *	subsystem-level @prepare() for all of them.
 *
 * @poweroff_late: Continue operations started by @poweroff().  Analogous to
 *	@suspend_late(), but it need not save the device's settings in memory.
 *
 * @restore: Hibernation-specific, executed after restoring the contents of main
 *	memory from a hibernation image, analogous to @resume().
 *
 * @restore_early: Prepare to execute @restore(), analogous to @resume_early().
 *
 * @suspend_noirq: Complete the actions started by @suspend().  Carry out any
 *	additional operations required for suspending the device that might be
 *	racing with its driver's interrupt handler, which is guaranteed not to
 *	run while @suspend_noirq() is being executed.
 *	It generally is expected that the device will be in a low-power state
 *	(appropriate for the target system sleep state) after subsystem-level
 *	@suspend_noirq() has returned successfully.  If the device can generate
 *	system wakeup signals and is enabled to wake up the system, it should be
 *	configured to do so at that time.  However, depending on the platform
 *	and device's subsystem, @suspend() or @suspend_late() may be allowed to
 *	put the device into the low-power state and configure it to generate
 *	wakeup signals, in which case it generally is not necessary to define
 *	@suspend_noirq().
 *
 * @resume_noirq: Prepare for the execution of @resume() by carrying out any
 *	operations required for resuming the device that might be racing with
 *	its driver's interrupt handler, which is guaranteed not to run while
 *	@resume_noirq() is being executed.
 *
 * @freeze_noirq: Complete the actions started by @freeze().  Carry out any
 *	additional operations required for freezing the device that might be
 *	racing with its driver's interrupt handler, which is guaranteed not to
 *	run while @freeze_noirq() is being executed.
 *	The power state of the device should not be changed by either @freeze(),
 *	or @freeze_late(), or @freeze_noirq() and it should not be configured to
 *	signal system wakeup by any of these callbacks.
 *
 * @thaw_noirq: Prepare for the execution of @thaw() by carrying out any
 *	operations required for thawing the device that might be racing with its
 *	driver's interrupt handler, which is guaranteed not to run while
 *	@thaw_noirq() is being executed.
 *
 * @poweroff_noirq: Complete the actions started by @poweroff().  Analogous to
 *	@suspend_noirq(), but it need not save the device's settings in memory.
 *
 * @restore_noirq: Prepare for the execution of @restore() by carrying out any
 *	operations required for thawing the device that might be racing with its
 *	driver's interrupt handler, which is guaranteed not to run while
 *	@restore_noirq() is being executed.  Analogous to @resume_noirq().
 *
 * @runtime_suspend: Prepare the device for a condition in which it won't be
 *	able to communicate with the CPU(s) and RAM due to power management.
 *	This need not mean that the device should be put into a low-power state.
 *	For example, if the device is behind a link which is about to be turned
 *	off, the device may remain at full power.  If the device does go to low
 *	power and is capable of generating runtime wakeup events, remote wakeup
 *	(i.e., a hardware mechanism allowing the device to request a change of
 *	its power state via an interrupt) should be enabled for it.
 *
 * @runtime_resume: Put the device into the fully active state in response to a
 *	wakeup event generated by hardware or at the request of software.  If
 *	necessary, put the device into the full-power state and restore its
 *	registers, so that it is fully operational.
 *
 * @runtime_idle: Device appears to be inactive and it might be put into a
 *	low-power state if all of the necessary conditions are satisfied.
 *	Check these conditions, and return 0 if it's appropriate to let the PM
 *	core queue a suspend request for the device.
 *
 * Several device power state transitions are externally visible, affecting
 * the state of pending I/O queues and (for drivers that touch hardware)
 * interrupts, wakeups, DMA, and other hardware state.  There may also be
 * internal transitions to various low-power modes which are transparent
 * to the rest of the driver stack (such as a driver that's ON gating off
 * clocks which are not in active use).
 *
 * The externally visible transitions are handled with the help of callbacks
 * included in this structure in such a way that, typically, two levels of
 * callbacks are involved.  First, the PM core executes callbacks provided by PM
 * domains, device types, classes and bus types.  They are the subsystem-level
 * callbacks expected to execute callbacks provided by device drivers, although
 * they may choose not to do that.  If the driver callbacks are executed, they
 * have to collaborate with the subsystem-level callbacks to achieve the goals
 * appropriate for the given system transition, given transition phase and the
 * subsystem the device belongs to.
 *
 * All of the above callbacks, except for @complete(), return error codes.
 * However, the error codes returned by @resume(), @thaw(), @restore(),
 * @resume_noirq(), @thaw_noirq(), and @restore_noirq(), do not cause the PM
 * core to abort the resume transition during which they are returned.  The
 * error codes returned in those cases are only printed to the system logs for
 * debugging purposes.  Still, it is recommended that drivers only return error
 * codes from their resume methods in case of an unrecoverable failure (i.e.
 * when the device being handled refuses to resume and becomes unusable) to
 * allow the PM core to be modified in the future, so that it can avoid
 * attempting to handle devices that failed to resume and their children.
 *
 * It is allowed to unregister devices while the above callbacks are being
 * executed.  However, a callback routine MUST NOT try to unregister the device
 * it was called for, although it may unregister children of that device (for
 * example, if it detects that a child was unplugged while the system was
 * asleep).
 *
 * There also are callbacks related to runtime power management of devices.
 * Again, as a rule these callbacks are executed by the PM core for subsystems
 * (PM domains, device types, classes and bus types) and the subsystem-level
 * callbacks are expected to invoke the driver callbacks.  Moreover, the exact
 * actions to be performed by a device driver's callbacks generally depend on
 * the platform and subsystem the device belongs to.
 *
 * Refer to Documentation/power/runtime_pm.rst for more information about the
 * role of the @runtime_suspend(), @runtime_resume() and @runtime_idle()
 * callbacks in device runtime power management.
 */
```

## 555. original/kernel-api/linux-5.10.260/include/linux/pm.h:361

Líneas 361–364; tipo `block`.

```text
/*
 * Use this if you want to use the same suspend and resume callbacks for suspend
 * to RAM and hibernation.
 */
```

## 556. original/kernel-api/linux-5.10.260/include/linux/pm.h:370

Líneas 370–382; tipo `block`.

```text
/*
 * Use this for defining a set of PM operations to be used in all situations
 * (system suspend, hibernation or runtime PM).
 * NOTE: In general, system suspend callbacks, .suspend() and .resume(), should
 * be different from the corresponding runtime PM callbacks, .runtime_suspend(),
 * and .runtime_resume(), because .runtime_suspend() always works on an already
 * quiescent device, while .suspend() should assume that the device may be doing
 * something when it is called (it should ensure that the device will be
 * quiescent after it has returned).  Therefore it's better to point the "late"
 * suspend and "early" resume callback pointers, .suspend_late() and
 * .resume_early(), to the same routines as .runtime_suspend() and
 * .runtime_resume(), respectively (and analogously for hibernation).
 */
```

## 557. original/kernel-api/linux-5.10.260/include/linux/pm.h:389

Líneas 389–389; tipo `block`.

```text
/* Deprecated. Use DEFINE_SIMPLE_DEV_PM_OPS() instead. */
```

## 558. original/kernel-api/linux-5.10.260/include/linux/pm.h:395

Líneas 395–395; tipo `block`.

```text
/* Deprecated. Use DEFINE_UNIVERSAL_DEV_PM_OPS() instead. */
```

## 559. original/kernel-api/linux-5.10.260/include/linux/pm.h:405

Líneas 405–455; tipo `block`.

```text
/*
 * PM_EVENT_ messages
 *
 * The following PM_EVENT_ messages are defined for the internal use of the PM
 * core, in order to provide a mechanism allowing the high level suspend and
 * hibernation code to convey the necessary information to the device PM core
 * code:
 *
 * ON		No transition.
 *
 * FREEZE	System is going to hibernate, call ->prepare() and ->freeze()
 *		for all devices.
 *
 * SUSPEND	System is going to suspend, call ->prepare() and ->suspend()
 *		for all devices.
 *
 * HIBERNATE	Hibernation image has been saved, call ->prepare() and
 *		->poweroff() for all devices.
 *
 * QUIESCE	Contents of main memory are going to be restored from a (loaded)
 *		hibernation image, call ->prepare() and ->freeze() for all
 *		devices.
 *
 * RESUME	System is resuming, call ->resume() and ->complete() for all
 *		devices.
 *
 * THAW		Hibernation image has been created, call ->thaw() and
 *		->complete() for all devices.
 *
 * RESTORE	Contents of main memory have been restored from a hibernation
 *		image, call ->restore() and ->complete() for all devices.
 *
 * RECOVER	Creation of a hibernation image or restoration of the main
 *		memory contents from a hibernation image has failed, call
 *		->thaw() and ->complete() for all devices.
 *
 * The following PM_EVENT_ messages are defined for internal use by
 * kernel subsystems.  They are never issued by the PM core.
 *
 * USER_SUSPEND		Manual selective suspend was issued by userspace.
 *
 * USER_RESUME		Manual selective resume was issued by userspace.
 *
 * REMOTE_WAKEUP	Remote-wakeup request was received from the device.
 *
 * AUTO_SUSPEND		Automatic (device idle) runtime suspend was
 *			initiated by the subsystem.
 *
 * AUTO_RESUME		Automatic (device needed) runtime resume was
 *			requested by a driver.
 */
```

## 560. original/kernel-api/linux-5.10.260/include/linux/pm.h:501

Líneas 501–522; tipo `block`.

```text
/*
 * Device run-time power management status.
 *
 * These status labels are used internally by the PM core to indicate the
 * current status of a device with respect to the PM core operations.  They do
 * not reflect the actual power state of the device or its status as seen by the
 * driver.
 *
 * RPM_ACTIVE		Device is fully operational.  Indicates that the device
 *			bus type's ->runtime_resume() callback has completed
 *			successfully.
 *
 * RPM_SUSPENDED	Device bus type's ->runtime_suspend() callback has
 *			completed successfully.  The device is regarded as
 *			suspended.
 *
 * RPM_RESUMING		Device bus type's ->runtime_resume() callback is being
 *			executed.
 *
 * RPM_SUSPENDING	Device bus type's ->runtime_suspend() callback is being
 *			executed.
 */
```

## 561. original/kernel-api/linux-5.10.260/include/linux/pm.h:531

Líneas 531–544; tipo `block`.

```text
/*
 * Device run-time power management request types.
 *
 * RPM_REQ_NONE		Do nothing.
 *
 * RPM_REQ_IDLE		Run the device bus type's ->runtime_idle() callback
 *
 * RPM_REQ_SUSPEND	Run the device bus type's ->runtime_suspend() callback
 *
 * RPM_REQ_AUTOSUSPEND	Same as RPM_REQ_SUSPEND, but not until the device has
 *			been inactive for as long as power.autosuspend_delay
 *
 * RPM_REQ_RESUME	Run the device bus type's ->runtime_resume() callback
 */
```

## 562. original/kernel-api/linux-5.10.260/include/linux/pm.h:569

Líneas 569–581; tipo `block`.

```text
/*
 * Driver flags to control system suspend/resume behavior.
 *
 * These flags can be set by device drivers at the probe time.  They need not be
 * cleared by the drivers as the driver core will take care of that.
 *
 * NO_DIRECT_COMPLETE: Do not apply direct-complete optimization to the device.
 * SMART_PREPARE: Take the driver ->prepare callback return value into account.
 * SMART_SUSPEND: Avoid resuming the device from runtime suspend.
 * MAY_SKIP_RESUME: Allow driver "noirq" and "early" callbacks to be skipped.
 *
 * See Documentation/driver-api/pm/devices.rst for details.
 */
```

## 563. original/kernel-api/linux-5.10.260/include/linux/pm.h:591

Líneas 591–591; tipo `block`.

```text
/* Owned by the PM core */
```

## 564. original/kernel-api/linux-5.10.260/include/linux/pm.h:592

Líneas 592–592; tipo `block`.

```text
/* Owned by the PM core */
```

## 565. original/kernel-api/linux-5.10.260/include/linux/pm.h:593

Líneas 593–593; tipo `block`.

```text
/* Ditto */
```

## 566. original/kernel-api/linux-5.10.260/include/linux/pm.h:597

Líneas 597–597; tipo `block`.

```text
/* Owned by the PM core */
```

## 567. original/kernel-api/linux-5.10.260/include/linux/pm.h:598

Líneas 598–598; tipo `block`.

```text
/* Owned by the PM core */
```

## 568. original/kernel-api/linux-5.10.260/include/linux/pm.h:607

Líneas 607–607; tipo `block`.

```text
/* Owned by the PM core */
```

## 569. original/kernel-api/linux-5.10.260/include/linux/pm.h:608

Líneas 608–608; tipo `block`.

```text
/* Owned by the PM core */
```

## 570. original/kernel-api/linux-5.10.260/include/linux/pm.h:609

Líneas 609–609; tipo `block`.

```text
/* Set by subsystems */
```

## 571. original/kernel-api/linux-5.10.260/include/linux/pm.h:643

Líneas 643–643; tipo `block`.

```text
/* Owned by the subsystem. */
```

## 572. original/kernel-api/linux-5.10.260/include/linux/pm.h:651

Líneas 651–664; tipo `block`.

```text
/**
 * struct dev_pm_domain - power management domain representation.
 *
 * @ops: Power management operations associated with this domain.
 * @start: Called when a user needs to start the device via the domain.
 * @detach: Called when removing a device from the domain.
 * @activate: Called before executing probe routines for bus types and drivers.
 * @sync: Called after successful driver probe.
 * @dismiss: Called after unsuccessful driver probe and after driver removal.
 *
 * Power domains provide callbacks that are executed during system suspend,
 * hibernation, system resume and during runtime PM transitions instead of
 * subsystem-level and driver-level callbacks.
 */
```

## 573. original/kernel-api/linux-5.10.260/include/linux/pm.h:674

Líneas 674–678; tipo `block`.

```text
/*
 * The PM_EVENT_ messages are also used by drivers implementing the legacy
 * suspend framework, based on the ->suspend() and ->resume() callbacks common
 * for suspend and hibernation transitions, according to the rules below.
 */
```

## 574. original/kernel-api/linux-5.10.260/include/linux/pm.h:680

Líneas 680–680; tipo `block`.

```text
/* Necessary, because several drivers use PM_EVENT_PRETHAW */
```

## 575. original/kernel-api/linux-5.10.260/include/linux/pm.h:683

Líneas 683–726; tipo `block`.

```text
/*
 * One transition is triggered by resume(), after a suspend() call; the
 * message is implicit:
 *
 * ON		Driver starts working again, responding to hardware events
 *		and software requests.  The hardware may have gone through
 *		a power-off reset, or it may have maintained state from the
 *		previous suspend() which the driver will rely on while
 *		resuming.  On most platforms, there are no restrictions on
 *		availability of resources like clocks during resume().
 *
 * Other transitions are triggered by messages sent using suspend().  All
 * these transitions quiesce the driver, so that I/O queues are inactive.
 * That commonly entails turning off IRQs and DMA; there may be rules
 * about how to quiesce that are specific to the bus or the device's type.
 * (For example, network drivers mark the link state.)  Other details may
 * differ according to the message:
 *
 * SUSPEND	Quiesce, enter a low power device state appropriate for
 *		the upcoming system state (such as PCI_D3hot), and enable
 *		wakeup events as appropriate.
 *
 * HIBERNATE	Enter a low power device state appropriate for the hibernation
 *		state (eg. ACPI S4) and enable wakeup events as appropriate.
 *
 * FREEZE	Quiesce operations so that a consistent image can be saved;
 *		but do NOT otherwise enter a low power device state, and do
 *		NOT emit system wakeup events.
 *
 * PRETHAW	Quiesce as if for FREEZE; additionally, prepare for restoring
 *		the system from a snapshot taken after an earlier FREEZE.
 *		Some drivers will need to reset their hardware state instead
 *		of preserving it, to ensure that it's never mistaken for the
 *		state which that earlier snapshot had set up.
 *
 * A minimally power-aware driver treats all messages as SUSPEND, fully
 * reinitializes its device during resume() -- whether or not it was reset
 * during the suspend/resume cycle -- and can't issue wakeup events.
 *
 * More power-aware drivers may also use low power states at runtime as
 * well as during system sleep states like PM_SUSPEND_STANDBY.  They may
 * be able to use wakeup events to exit from runtime low-power states,
 * or from system low-power states such as standby or suspend-to-RAM.
 */
```

## 576. original/kernel-api/linux-5.10.260/include/linux/pm.h:779

Líneas 779–779; tipo `block`.

```text
/* !CONFIG_PM_SLEEP */
```

## 577. original/kernel-api/linux-5.10.260/include/linux/pm.h:820

Líneas 820–820; tipo `block`.

```text
/* !CONFIG_PM_SLEEP */
```

## 578. original/kernel-api/linux-5.10.260/include/linux/pm.h:822

Líneas 822–822; tipo `block`.

```text
/* How to reorder dpm_list after device_move() */
```

## 579. original/kernel-api/linux-5.10.260/include/linux/pm.h:830

Líneas 830–830; tipo `block`.

```text
/* _LINUX_PM_H */
```

## 580. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/Kconfig:1

Líneas 1–1; tipo `hash`.

```text
# SPDX-License-Identifier: GPL-2.0-only
```

## 581. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/Makefile:1

Líneas 1–1; tipo `hash`.

```text
# SPDX-License-Identifier: GPL-2.0
```

## 582. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/base.c:1

Líneas 1–1; tipo `line`.

```text
// SPDX-License-Identifier: GPL-2.0
```

## 583. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/base.c:2

Líneas 2–2; tipo `block`.

```text
/* Copyright(c) 2009-2012  Realtek Corporation.*/
```

## 584. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/base.c:16

Líneas 16–34; tipo `block`.

```text
/*
 *NOTICE!!!: This file will be very big, we should
 *keep it clear under following roles:
 *
 *This file include following parts, so, if you add new
 *functions into this file, please check which part it
 *should includes. or check if you should add new part
 *for this file:
 *
 *1) mac80211 init functions
 *2) tx information functions
 *3) functions called by core.c
 *4) wq & timer callback functions
 *5) frame process functions
 *6) IOT functions
 *7) sysfs functions
 *8) vif functions
 *9) ...
 */
```

## 585. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/base.c:36

Líneas 36–40; tipo `block`.

```text
/*********************************************************
 *
 * mac80211 init functions
 *
 *********************************************************/
```

## 586. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/base.c:136

Líneas 136–136; tipo `block`.

```text
/* IEEE80211_AC_BE */
```

## 587. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/base.c:137

Líneas 137–137; tipo `block`.

```text
/* IEEE80211_AC_BK */
```

## 588. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/base.c:138

Líneas 138–138; tipo `block`.

```text
/* IEEE80211_AC_BK */
```

## 589. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/base.c:139

Líneas 139–139; tipo `block`.

```text
/* IEEE80211_AC_BE */
```

## 590. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/base.c:140

Líneas 140–140; tipo `block`.

```text
/* IEEE80211_AC_VI */
```

## 591. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/base.c:141

Líneas 141–141; tipo `block`.

```text
/* IEEE80211_AC_VI */
```

## 592. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/base.c:142

Líneas 142–142; tipo `block`.

```text
/* IEEE80211_AC_VO */
```

## 593. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/base.c:143

Líneas 143–143; tipo `block`.

```text
/* IEEE80211_AC_VO */
```

## 594. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/base.c:167

Líneas 167–170; tipo `block`.

```text
/*
	 *Maximum length of AMPDU that the STA can receive.
	 *Length = 2 ^ (13 + max_ampdu_length_exp) - 1 (octets)
	 */
```

## 595. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/base.c:173

Líneas 173–173; tipo `block`.

```text
/*Minimum MPDU start spacing , */
```

## 596. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/base.c:178

Líneas 178–186; tipo `block`.

```text
/*hw->wiphy->bands[NL80211_BAND_2GHZ]
	 *base on ant_num
	 *rx_mask: RX mask
	 *if rx_ant = 1 rx_mask[0]= 0xff;==>MCS0-MCS7
	 *if rx_ant = 2 rx_mask[1]= 0xff;==>MCS8-MCS15
	 *if rx_ant >= 3 rx_mask[2]= 0xff;
	 *if BW_40 rx_mask[4]= 0x01;
	 *highest supported RX rate
	 */
```

## 597. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/base.c:306

Líneas 306–306; tipo `block`.

```text
/* 1: 2.4 G bands */
```

## 598. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/base.c:307

Líneas 307–307; tipo `block`.

```text
/* <1> use  mac->bands as mem for hw->wiphy->bands */
```

## 599. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/base.c:310

Líneas 310–311; tipo `block`.

```text
/* <2> set hw->wiphy->bands[NL80211_BAND_2GHZ]
		 * to default value(1T1R) */
```

## 600. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/base.c:315

Líneas 315–315; tipo `block`.

```text
/* <3> init ht cap base on ant_num */
```

## 601. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/base.c:318

Líneas 318–318; tipo `block`.

```text
/* <4> set mac->sband to wiphy->sband */
```

## 602. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/base.c:321

Líneas 321–321; tipo `block`.

```text
/* 2: 5 G bands */
```

## 603. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/base.c:322

Líneas 322–322; tipo `block`.

```text
/* <1> use  mac->bands as mem for hw->wiphy->bands */
```

## 604. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/base.c:325

Líneas 325–326; tipo `block`.

```text
/* <2> set hw->wiphy->bands[NL80211_BAND_5GHZ]
		 * to default value(1T1R) */
```

## 605. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/base.c:330

Líneas 330–330; tipo `block`.

```text
/* <3> init ht cap base on ant_num */
```

## 606. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/base.c:334

Líneas 334–334; tipo `block`.

```text
/* <4> set mac->sband to wiphy->sband */
```

## 607. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/base.c:338

Líneas 338–338; tipo `block`.

```text
/* <1> use  mac->bands as mem for hw->wiphy->bands */
```

## 608. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/base.c:341

Líneas 341–342; tipo `block`.

```text
/* <2> set hw->wiphy->bands[NL80211_BAND_2GHZ]
			 * to default value(1T1R) */
```

## 609. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/base.c:347

Líneas 347–347; tipo `block`.

```text
/* <3> init ht cap base on ant_num */
```

## 610. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/base.c:350

Líneas 350–350; tipo `block`.

```text
/* <4> set mac->sband to wiphy->sband */
```

## 611. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/base.c:353

Líneas 353–353; tipo `block`.

```text
/* <1> use  mac->bands as mem for hw->wiphy->bands */
```

## 612. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/base.c:356

Líneas 356–357; tipo `block`.

```text
/* <2> set hw->wiphy->bands[NL80211_BAND_5GHZ]
			 * to default value(1T1R) */
```

## 613. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/base.c:362

Líneas 362–362; tipo `block`.

```text
/* <3> init ht cap base on ant_num */
```

## 614. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/base.c:366

Líneas 366–366; tipo `block`.

```text
/* <4> set mac->sband to wiphy->sband */
```

## 615. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/base.c:373

Líneas 373–373; tipo `block`.

```text
/* <5> set hw caps */
```

## 616. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/base.c:382

Líneas 382–382; tipo `block`.

```text
/* swlps or hwlps has been set in diff chip in init_sw_vars */
```

## 617. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/base.c:407

Líneas 407–407; tipo `block`.

```text
/* TODO: Correct this value for our hw */
```

## 618. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/base.c:410

Líneas 410–410; tipo `block`.

```text
/* hw->max_rates = 1; */
```

## 619. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/base.c:413

Líneas 413–413; tipo `block`.

```text
/* wowlan is not supported by kernel if CONFIG_PM is not defined */
```

## 620. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/base.c:428

Líneas 428–428; tipo `block`.

```text
/* <6> mac address */
```

## 621. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/base.c:452

Líneas 452–452; tipo `block`.

```text
/* <1> timer */
```

## 622. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/base.c:456

Líneas 456–456; tipo `block`.

```text
/* <2> work queue */
```

## 623. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/base.c:498

Líneas 498–498; tipo `block`.

```text
/*set init state to on */
```

## 624. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/base.c:529

Líneas 529–529; tipo `block`.

```text
/* <1> init mac80211 */
```

## 625. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/base.c:533

Líneas 533–533; tipo `block`.

```text
/* <2> rate control register */
```

## 626. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/base.c:536

Líneas 536–539; tipo `block`.

```text
/*
	 * <3> init CRDA must come after init
	 * mac80211 hw  in _rtl_init_mac80211.
	 */
```

## 627. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/base.c:545

Líneas 545–545; tipo `block`.

```text
/* <4> locks */
```

## 628. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/base.c:560

Líneas 560–560; tipo `block`.

```text
/* <5> init list */
```

## 629. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/base.c:568

Líneas 568–568; tipo `block`.

```text
/* <6> init deferred work */
```

## 630. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/base.c:600

Líneas 600–604; tipo `block`.

```text
/*********************************************************
 *
 * tx information functions
 *
 *********************************************************/
```

## 631. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/base.c:614

Líneas 614–614; tipo `block`.

```text
/* 1M can only use Long Preamble. 11B spec */
```

## 632. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/base.c:681

Líneas 681–681; tipo `block`.

```text
/* Common Settings */
```

## 633. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/base.c:690

Líneas 690–690; tipo `block`.

```text
/* Use CTS-to-SELF in protection mode. */
```

## 634. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/base.c:695

Líneas 695–695; tipo `block`.

```text
/* Use RTS-CTS in protection mode. */
```

## 635. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/base.c:815

Líneas 815–815; tipo `block`.

```text
/* TODO we will differentiate adhoc and station future  */
```

## 636. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/base.c:822

Líneas 822–822; tipo `block`.

```text
/* use sta_entry->ratr_index */
```

## 637. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/base.c:883

Líneas 883–883; tipo `block`.

```text
/*use legency rate, shall use 20MHz */
```

## 638. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/base.c:961

Líneas 961–985; tipo `block`.

```text
/* mac80211's rate_idx is like this:
 *
 * 2.4G band:rx_status->band == NL80211_BAND_2GHZ
 *
 * B/G rate:
 * (rx_status->flag & RX_FLAG_HT) = 0,
 * DESC_RATE1M-->DESC_RATE54M ==> idx is 0-->11,
 *
 * N rate:
 * (rx_status->flag & RX_FLAG_HT) = 1,
 * DESC_RATEMCS0-->DESC_RATEMCS15 ==> idx is 0-->15
 *
 * 5G band:rx_status->band == NL80211_BAND_5GHZ
 * A rate:
 * (rx_status->flag & RX_FLAG_HT) = 0,
 * DESC_RATE6M-->DESC_RATE54M ==> idx is 0-->7,
 *
 * N rate:
 * (rx_status->flag & RX_FLAG_HT) = 1,
 * DESC_RATEMCS0-->DESC_RATEMCS15 ==> idx is 0-->15
 *
 * VHT rates:
 * DESC_RATEVHT1SS_MCS0-->DESC_RATEVHT1SS_MCS9 ==> idx is 0-->9
 * DESC_RATEVHT2SS_MCS0-->DESC_RATEVHT2SS_MCS9 ==> idx is 0-->9
 */
```

## 639. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/base.c:1201

Líneas 1201–1201; tipo `block`.

```text
/* HT MCS0-15 */
```

## 640. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/base.c:1205

Líneas 1205–1205; tipo `block`.

```text
/* VHT MCS0-9, NSS */
```

## 641. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/base.c:1213

Líneas 1213–1213; tipo `block`.

```text
/* legacy */
```

## 642. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/base.c:1220

Líneas 1220–1220; tipo `block`.

```text
/* check 5G band */
```

## 643. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/base.c:1255

Líneas 1255–1259; tipo `block`.

```text
/*
		 *we set data rate INX 0
		 *in rtl_rc.c   if skb is special data or
		 *mgt which need low data rate.
		 */
```

## 644. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/base.c:1261

Líneas 1261–1264; tipo `block`.

```text
/*
		 *So tcb_desc->hw_rate is just used for
		 *special data and mgt frames
		 */
```

## 645. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/base.c:1273

Líneas 1273–1279; tipo `block`.

```text
/*
			 *because hw will nerver use hw_rate
			 *when tcb_desc->use_driver_rate = false
			 *so we never set highest N rate here,
			 *and N rate will all be controlled by FW
			 *when tcb_desc->use_driver_rate = false
			 */
```

## 646. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/base.c:1336

Líneas 1336–1336; tipo `block`.

```text
/* Dul mac */
```

## 647. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/base.c:1479

Líneas 1479–1479; tipo `block`.

```text
/*WEP_IV_LEN*/
```

## 648. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/base.c:1482

Líneas 1482–1482; tipo `block`.

```text
/*TKIP_IV_LEN*/
```

## 649. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/base.c:1485

Líneas 1485–1485; tipo `block`.

```text
/*CCMP_HDR_LEN;*/
```

## 650. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/base.c:1498

Líneas 1498–1498; tipo `block`.

```text
/*should call before software enc*/
```

## 651. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/base.c:1525

Líneas 1525–1527; tipo `block`.

```text
/* 68 : UDP BOOTP client
				 * 67 : UDP BOOTP server
				 */
```

## 652. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/base.c:1545

Líneas 1545–1545; tipo `block`.

```text
/* EAPOL is seens as in-4way */
```

## 653. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/base.c:1562

Líneas 1562–1564; tipo `block`.

```text
/* TODO: Handle any IPv6 cases that need special handling.
		 * For now, always return false
		 */
```

## 654. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/base.c:1625

Líneas 1625–1628; tipo `block`.

```text
/* SW_DEFINE[11:8] are reserved (driver fills zeros)
	 * SW_DEFINE[7:2] are used by driver
	 * SW_DEFINE[1:0] are reserved for firmware (driver fills zeros)
	 */
```

## 655. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/base.c:1701

Líneas 1701–1701; tipo `block`.

```text
/* 3 sec. (timeout) seen as acked */
```

## 656. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/base.c:1730

Líneas 1730–1730; tipo `block`.

```text
/* AIFS = AIFSN * slot time + SIFS */
```

## 657. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/base.c:1756

Líneas 1756–1760; tipo `block`.

```text
/*********************************************************
 *
 * functions called by core.c
 *
 *********************************************************/
```

## 658. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/base.c:1904

Líneas 1904–1908; tipo `block`.

```text
/*********************************************************
 *
 * wq & timer callback functions
 *
 *********************************************************/
```

## 659. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/base.c:1909

Líneas 1909–1909; tipo `block`.

```text
/* this function is used for roaming */
```

## 660. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/base.c:1921

Líneas 1921–1921; tipo `block`.

```text
/* check if this really is a beacon */
```

## 661. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/base.c:1926

Líneas 1926–1926; tipo `block`.

```text
/* min. beacon length + FCS_LEN */
```

## 662. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/base.c:1930

Líneas 1930–1930; tipo `block`.

```text
/* and only beacons from the associated BSSID, please */
```

## 663. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/base.c:1978

Líneas 1978–1978; tipo `block`.

```text
/* 180 seconds */
```

## 664. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/base.c:2005

Líneas 2005–2005; tipo `block`.

```text
/* check if it is scanning */
```

## 665. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/base.c:2009

Líneas 2009–2009; tipo `block`.

```text
/* check if this really is a beacon */
```

## 666. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/base.c:2074

Líneas 2074–2074; tipo `block`.

```text
/* <1> Determine if action frame is allowed */
```

## 667. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/base.c:2082

Líneas 2082–2084; tipo `block`.

```text
/* <2> to check if traffic busy, if
	 * busytraffic we don't change channel
	 */
```

## 668. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/base.c:2086

Líneas 2086–2086; tipo `block`.

```text
/* (1) get aver_rx_cnt_inperiod & aver_tx_cnt_inperiod */
```

## 669. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/base.c:2106

Líneas 2106–2106; tipo `block`.

```text
/* (2) check traffic busy */
```

## 670. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/base.c:2115

Líneas 2115–2115; tipo `block`.

```text
/* Higher Tx/Rx data. */
```

## 671. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/base.c:2120

Líneas 2120–2120; tipo `block`.

```text
/* Extremely high Rx data. */
```

## 672. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/base.c:2125

Líneas 2125–2125; tipo `block`.

```text
/* check every tid's tx traffic */
```

## 673. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/base.c:2146

Líneas 2146–2146; tipo `block`.

```text
/* PS is controlled by coex. */
```

## 674. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/base.c:2187

Líneas 2187–2187; tipo `block`.

```text
/* <3> DM */
```

## 675. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/base.c:2191

Líneas 2191–2191; tipo `block`.

```text
/* <4> roaming */
```

## 676. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/base.c:2201

Líneas 2201–2203; tipo `block`.

```text
/* if we can't recv beacon for 10s,
			 * we should reconnect this AP
			 */
```

## 677. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/base.c:2228

Líneas 2228–2228; tipo `block`.

```text
/* <6> scan list */
```

## 678. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/base.c:2231

Líneas 2231–2231; tipo `block`.

```text
/* <7> check ack queue */
```

## 679. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/base.c:2284

Líneas 2284–2284; tipo `block`.

```text
/* enqueue */
```

## 680. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/base.c:2291

Líneas 2291–2291; tipo `block`.

```text
/* wake up wq */
```

## 681. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/base.c:2351

Líneas 2351–2351; tipo `block`.

```text
/* dequeue a task */
```

## 682. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/base.c:2358

Líneas 2358–2358; tipo `block`.

```text
/* do it */
```

## 683. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/base.c:2370

Líneas 2370–2370; tipo `block`.

```text
/* free */
```

## 684. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/base.c:2384

Líneas 2384–2388; tipo `block`.

```text
/*********************************************************
 *
 * frame process functions
 *
 *********************************************************/
```

## 685. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/base.c:2408

Líneas 2408–2408; tipo `block`.

```text
/* when we use 2 rx ants we send IEEE80211_SMPS_OFF */
```

## 686. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/base.c:2409

Líneas 2409–2409; tipo `block`.

```text
/* when we use 1 rx ant we send IEEE80211_SMPS_STATIC */
```

## 687. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/base.c:2418

Líneas 2418–2418; tipo `block`.

```text
/* 27 = header + category + action + smps mode */
```

## 688. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/base.c:2433

Líneas 2433–2433; tipo `block`.

```text
/* 0 */
```

## 689. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/base.c:2434

Líneas 2434–2434; tipo `block`.

```text
/* 4 */
```

## 690. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/base.c:2437

Líneas 2437–2437; tipo `block`.

```text
/* 1 */
```

## 691. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/base.c:2437

Líneas 2437–2437; tipo `block`.

```text
/*MIMO_PS_NOLIMIT*/
```

## 692. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/base.c:2439

Líneas 2439–2439; tipo `block`.

```text
/* 0 */
```

## 693. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/base.c:2441

Líneas 2441–2441; tipo `block`.

```text
/* 2 */
```

## 694. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/base.c:2441

Líneas 2441–2441; tipo `block`.

```text
/*MIMO_PS_STATIC*/
```

## 695. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/base.c:2443

Líneas 2443–2443; tipo `block`.

```text
/* 1 */
```

## 696. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/base.c:2445

Líneas 2445–2445; tipo `block`.

```text
/* 3 */
```

## 697. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/base.c:2445

Líneas 2445–2445; tipo `block`.

```text
/*MIMO_PS_DYNAMIC*/
```

## 698. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/base.c:2447

Líneas 2447–2447; tipo `block`.

```text
/* 3 */
```

## 699. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/base.c:2485

Líneas 2485–2485; tipo `block`.

```text
/* this is a type = mgmt * stype = action frame */
```

## 700. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/base.c:2491

Líneas 2491–2491; tipo `block`.

```text
/* rtlpriv->cfg->ops->update_rate_tbl(hw, sta, 0, true); */
```

## 701. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/base.c:2532

Líneas 2532–2536; tipo `block`.

```text
/* because mac80211 have issues when can receive del ba
 * so here we just make a fake del_ba if we receive a ba_req
 * but rx_agg was opened to let mac80211 release some ba
 * related resources, so please this del_ba for tx
 */
```

## 702. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/base.c:2545

Líneas 2545–2545; tipo `block`.

```text
/* 27 = header + category + action + smps mode */
```

## 703. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/base.c:2559

Líneas 2559–2559; tipo `block`.

```text
/* bit 11 initiator */
```

## 704. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/base.c:2560

Líneas 2560–2560; tipo `block`.

```text
/* bit 15:12 TID number */
```

## 705. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/base.c:2569

Líneas 2569–2573; tipo `block`.

```text
/*********************************************************
 *
 * IOT functions
 *
 *********************************************************/
```

## 706. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/base.c:2671

Líneas 2671–2671; tipo `block`.

```text
/* check if this really is a beacon */
```

## 707. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/base.c:2675

Líneas 2675–2675; tipo `block`.

```text
/* min. beacon length + FCS_LEN */
```

## 708. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/base.c:2679

Líneas 2679–2679; tipo `block`.

```text
/* and only beacons from the associated BSSID, please */
```

## 709. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/base.c:2739

Líneas 2739–2739; tipo `block`.

```text
/* add debugfs */
```

## 710. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/base.c:2747

Líneas 2747–2747; tipo `block`.

```text
/*RC*/
```

## 711. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/base.c:2750

Líneas 2750–2750; tipo `block`.

```text
/* remove debugfs */
```

## 712. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/base.h:1

Líneas 1–1; tipo `block`.

```text
/* SPDX-License-Identifier: GPL-2.0 */
```

## 713. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/base.h:2

Líneas 2–2; tipo `block`.

```text
/* Copyright(c) 2009-2012  Realtek Corporation.*/
```

## 714. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/base.h:26

Líneas 26–26; tipo `block`.

```text
/* Mbps */
```

## 715. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/base.h:27

Líneas 27–27; tipo `block`.

```text
/* Mbps */
```

## 716. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/base.h:29

Líneas 29–29; tipo `block`.

```text
/* Mbps */
```

## 717. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/base.h:30

Líneas 30–30; tipo `block`.

```text
/* Mbps */
```

## 718. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/base.h:31

Líneas 31–31; tipo `block`.

```text
/* Mbps */
```

## 719. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/base.h:32

Líneas 32–32; tipo `block`.

```text
/* Mbps */
```

## 720. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/base.h:34

Líneas 34–34; tipo `block`.

```text
/* Mbps */
```

## 721. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/base.h:35

Líneas 35–35; tipo `block`.

```text
/* Mbps */
```

## 722. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/base.h:36

Líneas 36–36; tipo `block`.

```text
/* Mbps */
```

## 723. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/base.h:37

Líneas 37–37; tipo `block`.

```text
/* Mbps */
```

## 724. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/btcoexist/Makefile:1

Líneas 1–1; tipo `hash`.

```text
# SPDX-License-Identifier: GPL-2.0
```

## 725. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/btcoexist/halbt_precomp.h:1

Líneas 1–1; tipo `block`.

```text
/* SPDX-License-Identifier: GPL-2.0 */
```

## 726. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/btcoexist/halbt_precomp.h:2

Líneas 2–2; tipo `block`.

```text
/* Copyright(c) 2007-2011  Realtek Corporation.*/
```

## 727. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/btcoexist/halbt_precomp.h:6

Líneas 6–8; tipo `block`.

```text
/*************************************************************
 * include files
 *************************************************************/
```

## 728. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/btcoexist/halbt_precomp.h:19

Líneas 19–19; tipo `block`.

```text
/* Interface type */
```

## 729. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/btcoexist/halbt_precomp.h:64

Líneas 64–64; tipo `block`.

```text
/* __HALBT_PRECOMP_H__ */
```

## 730. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/btcoexist/halbtc8192e2ant.c:1

Líneas 1–1; tipo `line`.

```text
// SPDX-License-Identifier: GPL-2.0
```

## 731. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/btcoexist/halbtc8192e2ant.c:2

Líneas 2–2; tipo `block`.

```text
/* Copyright(c) 2012  Realtek Corporation.*/
```

## 732. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/btcoexist/halbtc8192e2ant.c:4

Líneas 4–6; tipo `block`.

```text
/**************************************************************
 *   include files
 **************************************************************/
```

## 733. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/btcoexist/halbtc8192e2ant.c:8

Líneas 8–10; tipo `block`.

```text
/**************************************************************
 *   Global variables, these are static variables
 **************************************************************/
```

## 734. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/btcoexist/halbtc8192e2ant.c:25

Líneas 25–27; tipo `block`.

```text
/**************************************************************
 *   local function proto type if needed
 **************************************************************/
```

## 735. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/btcoexist/halbtc8192e2ant.c:28

Líneas 28–30; tipo `block`.

```text
/**************************************************************
 *   local function start with btc8192e2ant_
 **************************************************************/
```

## 736. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/btcoexist/halbtc8192e2ant.c:167

Líneas 167–167; tipo `block`.

```text
/* This function check if bt is disabled */
```

## 737. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/btcoexist/halbtc8192e2ant.c:216

Líneas 216–216; tipo `block`.

```text
/* normal mode */
```

## 738. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/btcoexist/halbtc8192e2ant.c:218

Líneas 218–218; tipo `block`.

```text
/* enable 2ss */
```

## 739. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/btcoexist/halbtc8192e2ant.c:220

Líneas 220–220; tipo `block`.

```text
/* disable 2ss */
```

## 740. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/btcoexist/halbtc8192e2ant.c:222

Líneas 222–222; tipo `block`.

```text
/* disable cck 1/2 */
```

## 741. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/btcoexist/halbtc8192e2ant.c:224

Líneas 224–224; tipo `block`.

```text
/* enable 2ss */
```

## 742. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/btcoexist/halbtc8192e2ant.c:226

Líneas 226–226; tipo `block`.

```text
/* disable 2ss */
```

## 743. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/btcoexist/halbtc8192e2ant.c:228

Líneas 228–228; tipo `block`.

```text
/* disable cck 1/2/5.5, ofdm 6/9/12/18/24, mcs 0/1/2/3/4 */
```

## 744. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/btcoexist/halbtc8192e2ant.c:230

Líneas 230–230; tipo `block`.

```text
/* enable 2ss */
```

## 745. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/btcoexist/halbtc8192e2ant.c:232

Líneas 232–232; tipo `block`.

```text
/* disable 2ss */
```

## 746. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/btcoexist/halbtc8192e2ant.c:261

Líneas 261–261; tipo `block`.

```text
/* normal mode */
```

## 747. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/btcoexist/halbtc8192e2ant.c:299

Líneas 299–299; tipo `block`.

```text
/* normal mode */
```

## 748. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/btcoexist/halbtc8192e2ant.c:303

Líneas 303–303; tipo `block`.

```text
/* retry limit = 8 */
```

## 749. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/btcoexist/halbtc8192e2ant.c:322

Líneas 322–322; tipo `block`.

```text
/* normal mode */
```

## 750. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/btcoexist/halbtc8192e2ant.c:326

Líneas 326–326; tipo `block`.

```text
/* AMPDU time = 0x38 * 32us */
```

## 751. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/btcoexist/halbtc8192e2ant.c:363

Líneas 363–365; tipo `block`.

```text
/*********************************************
	 *	Rx Aggregation related setting
	 *********************************************/
```

## 752. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/btcoexist/halbtc8192e2ant.c:368

Líneas 368–368; tipo `block`.

```text
/* decide BT control aggregation buf size or not */
```

## 753. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/btcoexist/halbtc8192e2ant.c:371

Líneas 371–373; tipo `block`.

```text
/* aggregation buf size, only work
	 * when BT control Rx aggregation size.
	 */
```

## 754. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/btcoexist/halbtc8192e2ant.c:375

Líneas 375–375; tipo `block`.

```text
/* real update aggregation setting */
```

## 755. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/btcoexist/halbtc8192e2ant.c:408

Líneas 408–408; tipo `block`.

```text
/* reset counter */
```

## 756. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/btcoexist/halbtc8192e2ant.c:419

Líneas 419–419; tipo `block`.

```text
/* trigger */
```

## 757. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/btcoexist/halbtc8192e2ant.c:474

Líneas 474–474; tipo `block`.

```text
/* work around for HS mode. */
```

## 758. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/btcoexist/halbtc8192e2ant.c:480

Líneas 480–480; tipo `block`.

```text
/* check if Sco only */
```

## 759. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/btcoexist/halbtc8192e2ant.c:489

Líneas 489–489; tipo `block`.

```text
/* check if A2dp only */
```

## 760. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/btcoexist/halbtc8192e2ant.c:498

Líneas 498–498; tipo `block`.

```text
/* check if Pan only */
```

## 761. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/btcoexist/halbtc8192e2ant.c:507

Líneas 507–507; tipo `block`.

```text
/* check if Hid only */
```

## 762. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/btcoexist/halbtc8192e2ant.c:729

Líneas 729–731; tipo `block`.

```text
/* There are several type of dacswing
	 * 0x18/ 0x10/ 0xc/ 0x8/ 0x4/ 0x6
	 */
```

## 763. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/btcoexist/halbtc8192e2ant.c:856

Líneas 856–856; tipo `block`.

```text
/* Shrink RF Rx LPF corner */
```

## 764. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/btcoexist/halbtc8192e2ant.c:862

Líneas 862–864; tipo `block`.

```text
/* Resume RF Rx LPF corner
		 * After initialized, we can use coex_dm->btRf0x1eBackup
		 */
```

## 765. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/btcoexist/halbtc8192e2ant.c:962

Líneas 962–962; tipo `block`.

```text
/* BB AGC Gain Table */
```

## 766. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/btcoexist/halbtc8192e2ant.c:1114

Líneas 1114–1114; tipo `block`.

```text
/* function enable */
```

## 767. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/btcoexist/halbtc8192e2ant.c:1311

Líneas 1311–1311; tipo `block`.

```text
/* disable PS tdma */
```

## 768. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/btcoexist/halbtc8192e2ant.c:1328

Líneas 1328–1328; tipo `block`.

```text
/* update pre state */
```

## 769. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/btcoexist/halbtc8192e2ant.c:1349

Líneas 1349–1349; tipo `block`.

```text
/* switch ofdm path */
```

## 770. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/btcoexist/halbtc8192e2ant.c:1353

Líneas 1353–1353; tipo `block`.

```text
/* switch cck patch */
```

## 771. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/btcoexist/halbtc8192e2ant.c:1366

Líneas 1366–1366; tipo `block`.

```text
/* set rx 1ss or 2ss */
```

## 772. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/btcoexist/halbtc8192e2ant.c:1391

Líneas 1391–1391; tipo `block`.

```text
/* fw all off */
```

## 773. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/btcoexist/halbtc8192e2ant.c:1396

Líneas 1396–1396; tipo `block`.

```text
/* sw all off */
```

## 774. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/btcoexist/halbtc8192e2ant.c:1400

Líneas 1400–1400; tipo `block`.

```text
/* hw all off */
```

## 775. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/btcoexist/halbtc8192e2ant.c:1406

Líneas 1406–1406; tipo `block`.

```text
/* force to reset coex mechanism */
```

## 776. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/btcoexist/halbtc8192e2ant.c:1670

Líneas 1670–1670; tipo `block`.

```text
/* accquire the BT TRx retry count from BT_Info byte2 */
```

## 777. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/btcoexist/halbtc8192e2ant.c:1678

Líneas 1678–1678; tipo `block`.

```text
/* no retry in the last 2-second duration */
```

## 778. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/btcoexist/halbtc8192e2ant.c:1738

Líneas 1738–1741; tipo `block`.

```text
/* if current PsTdma not match with
	 * the recorded one (when scan, dhcp...),
	 * then we have to adjust it back to the previous record one.
	 */
```

## 779. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/btcoexist/halbtc8192e2ant.c:1764

Líneas 1764–1764; tipo `block`.

```text
/* SCO only or SCO+PAN(HS) */
```

## 780. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/btcoexist/halbtc8192e2ant.c:1797

Líneas 1797–1797; tipo `block`.

```text
/* sw mechanism */
```

## 781. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/btcoexist/halbtc8192e2ant.c:1859

Líneas 1859–1859; tipo `block`.

```text
/* sw mechanism */
```

## 782. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/btcoexist/halbtc8192e2ant.c:1920

Líneas 1920–1920; tipo `block`.

```text
/* sw mechanism */
```

## 783. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/btcoexist/halbtc8192e2ant.c:1950

Líneas 1950–1950; tipo `block`.

```text
/* A2DP only / PAN(EDR) only/ A2DP+PAN(HS) */
```

## 784. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/btcoexist/halbtc8192e2ant.c:2009

Líneas 2009–2009; tipo `block`.

```text
/* sw mechanism */
```

## 785. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/btcoexist/halbtc8192e2ant.c:2068

Líneas 2068–2068; tipo `block`.

```text
/* sw mechanism */
```

## 786. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/btcoexist/halbtc8192e2ant.c:2128

Líneas 2128–2128; tipo `block`.

```text
/* sw mechanism */
```

## 787. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/btcoexist/halbtc8192e2ant.c:2159

Líneas 2159–2159; tipo `block`.

```text
/* PAN(HS) only */
```

## 788. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/btcoexist/halbtc8192e2ant.c:2217

Líneas 2217–2217; tipo `block`.

```text
/* PAN(EDR)+A2DP */
```

## 789. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/btcoexist/halbtc8192e2ant.c:2249

Líneas 2249–2249; tipo `block`.

```text
/* sw mechanism	*/
```

## 790. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/btcoexist/halbtc8192e2ant.c:2311

Líneas 2311–2311; tipo `block`.

```text
/* sw mechanism */
```

## 791. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/btcoexist/halbtc8192e2ant.c:2341

Líneas 2341–2341; tipo `block`.

```text
/* HID+A2DP+PAN(EDR) */
```

## 792. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/btcoexist/halbtc8192e2ant.c:2373

Líneas 2373–2373; tipo `block`.

```text
/* sw mechanism */
```

## 793. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/btcoexist/halbtc8192e2ant.c:2432

Líneas 2432–2432; tipo `block`.

```text
/* sw mechanism */
```

## 794. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/btcoexist/halbtc8192e2ant.c:2566

Líneas 2566–2566; tipo `block`.

```text
/* btc8192e2ant_coex_all_off(btcoexist); */
```

## 795. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/btcoexist/halbtc8192e2ant.c:2584

Líneas 2584–2584; tipo `block`.

```text
/* backup rf 0x1e value */
```

## 796. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/btcoexist/halbtc8192e2ant.c:2601

Líneas 2601–2601; tipo `block`.

```text
/* antenna sw ctrl to bt */
```

## 797. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/btcoexist/halbtc8192e2ant.c:2613

Líneas 2613–2613; tipo `block`.

```text
/* antenna switch control parameter */
```

## 798. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/btcoexist/halbtc8192e2ant.c:2616

Líneas 2616–2616; tipo `block`.

```text
/* coex parameters */
```

## 799. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/btcoexist/halbtc8192e2ant.c:2618

Líneas 2618–2618; tipo `block`.

```text
/* 0x790[5:0] = 0x5 */
```

## 800. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/btcoexist/halbtc8192e2ant.c:2624

Líneas 2624–2624; tipo `block`.

```text
/* enable counter statistics */
```

## 801. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/btcoexist/halbtc8192e2ant.c:2627

Líneas 2627–2627; tipo `block`.

```text
/* enable PTA */
```

## 802. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/btcoexist/halbtc8192e2ant.c:2629

Líneas 2629–2629; tipo `block`.

```text
/* enable mailbox interface */
```

## 803. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/btcoexist/halbtc8192e2ant.c:2634

Líneas 2634–2634; tipo `block`.

```text
/* enable PTA I2C mailbox */
```

## 804. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/btcoexist/halbtc8192e2ant.c:2639

Líneas 2639–2639; tipo `block`.

```text
/* enable bt clock when wifi is disabled. */
```

## 805. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/btcoexist/halbtc8192e2ant.c:2643

Líneas 2643–2643; tipo `block`.

```text
/* enable bt clock when suspend. */
```

## 806. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/btcoexist/halbtc8192e2ant.c:2649

Líneas 2649–2651; tipo `block`.

```text
/************************************************************
 *   extern function start with ex_btc8192e2ant_
 ************************************************************/
```

## 807. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/btcoexist/halbtc8192e2ant.c:2778

Líneas 2778–2778; tipo `block`.

```text
/* Sw mechanism	*/
```

## 808. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/btcoexist/halbtc8192e2ant.c:2792

Líneas 2792–2792; tipo `block`.

```text
/* Fw mechanism	*/
```

## 809. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/btcoexist/halbtc8192e2ant.c:2806

Líneas 2806–2806; tipo `block`.

```text
/* Hw setting */
```

## 810. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/btcoexist/halbtc8192e2ant.c:2949

Líneas 2949–2949; tipo `block`.

```text
/* only 2.4G we need to inform bt the chnl mask */
```

## 811. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/btcoexist/halbtc8192e2ant.c:3017

Líneas 3017–3017; tipo `block`.

```text
/* [3:0] */
```

## 812. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/btcoexist/halbtc8192e2ant.c:3027

Líneas 3027–3029; tipo `block`.

```text
/* Here we need to resend some wifi info to BT
		 * because bt is reset and loss of the info.
		 */
```

## 813. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/btcoexist/halbtc8192e2ant.c:3055

Líneas 3055–3057; tipo `block`.

```text
/* BT already NOT ignore Wlan active,
			 * do nothing here.
			 */
```

## 814. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/btcoexist/halbtc8192e2ant.c:3068

Líneas 3068–3068; tipo `block`.

```text
/* check BIT2 first ==> check if bt is under inquiry or page scan */
```

## 815. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/btcoexist/halbtc8192e2ant.c:3074

Líneas 3074–3074; tipo `block`.

```text
/* set link exist status */
```

## 816. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/btcoexist/halbtc8192e2ant.c:3081

Líneas 3081–3081; tipo `block`.

```text
/* connection exists */
```

## 817. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/btcoexist/halbtc8192e2ant.h:1

Líneas 1–1; tipo `block`.

```text
/* SPDX-License-Identifier: GPL-2.0 */
```

## 818. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/btcoexist/halbtc8192e2ant.h:2

Líneas 2–2; tipo `block`.

```text
/* Copyright(c) 2012  Realtek Corporation.*/
```

## 819. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/btcoexist/halbtc8192e2ant.h:4

Líneas 4–6; tipo `block`.

```text
/*****************************************************************
 *   The following is for 8192E 2Ant BT Co-exist definition
 *****************************************************************/
```

## 820. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/btcoexist/halbtc8192e2ant.h:52

Líneas 52–52; tipo `block`.

```text
/* fw mechanism */
```

## 821. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/btcoexist/halbtc8192e2ant.h:70

Líneas 70–70; tipo `block`.

```text
/* sw mechanism */
```

## 822. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/btcoexist/halbtc8192e2ant.h:94

Líneas 94–94; tipo `block`.

```text
/* Auto Rate Fallback Retry cnt */
```

## 823. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/btcoexist/halbtc8192e2ant.h:95

Líneas 95–95; tipo `block`.

```text
/* Auto Rate Fallback Retry cnt */
```

## 824. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/btcoexist/halbtc8192e2ant.h:99

Líneas 99–99; tipo `block`.

```text
/* algorithm related */
```

## 825. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/btcoexist/halbtc8192e2ant.h:143

Líneas 143–145; tipo `block`.

```text
/****************************************************************
 *    The following is interface which will notify coex module.
 ****************************************************************/
```

## 826. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/btcoexist/halbtc8723b1ant.c:1

Líneas 1–1; tipo `line`.

```text
// SPDX-License-Identifier: GPL-2.0
```

## 827. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/btcoexist/halbtc8723b1ant.c:2

Líneas 2–2; tipo `block`.

```text
/* Copyright(c) 2012  Realtek Corporation.*/
```

## 828. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/btcoexist/halbtc8723b1ant.c:4

Líneas 4–12; tipo `block`.

```text
/***************************************************************
 * Description:
 *
 * This file is for RTL8723B Co-exist mechanism
 *
 * History
 * 2012/11/15 Cosa first check in.
 *
 ***************************************************************/
```

## 829. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/btcoexist/halbtc8723b1ant.c:14

Líneas 14–16; tipo `block`.

```text
/***************************************************************
 * include files
 ***************************************************************/
```

## 830. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/btcoexist/halbtc8723b1ant.c:18

Líneas 18–20; tipo `block`.

```text
/***************************************************************
 * Global variables, these are static variables
 ***************************************************************/
```

## 831. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/btcoexist/halbtc8723b1ant.c:35

Líneas 35–37; tipo `block`.

```text
/***************************************************************
 * local function proto type if needed
 ***************************************************************/
```

## 832. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/btcoexist/halbtc8723b1ant.c:38

Líneas 38–40; tipo `block`.

```text
/***************************************************************
 * local function start with halbtc8723b1ant_
 ***************************************************************/
```

## 833. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/btcoexist/halbtc8723b1ant.c:63

Líneas 63–63; tipo `block`.

```text
/* normal mode */
```

## 834. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/btcoexist/halbtc8723b1ant.c:101

Líneas 101–101; tipo `block`.

```text
/* normal mode */
```

## 835. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/btcoexist/halbtc8723b1ant.c:105

Líneas 105–105; tipo `block`.

```text
/* retry limit = 8 */
```

## 836. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/btcoexist/halbtc8723b1ant.c:124

Líneas 124–124; tipo `block`.

```text
/* normal mode */
```

## 837. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/btcoexist/halbtc8723b1ant.c:128

Líneas 128–128; tipo `block`.

```text
/* AMPDU timw = 0x38 * 32us */
```

## 838. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/btcoexist/halbtc8723b1ant.c:145

Líneas 145–145; tipo `block`.

```text
/* normal mode */
```

## 839. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/btcoexist/halbtc8723b1ant.c:148

Líneas 148–148; tipo `block`.

```text
/* disable cck 1/2 */
```

## 840. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/btcoexist/halbtc8723b1ant.c:152

Líneas 152–152; tipo `block`.

```text
/* disable cck 1/2/5.5, ofdm 6/9/12/18/24, mcs 0/1/2/3/4 */
```

## 841. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/btcoexist/halbtc8723b1ant.c:175

Líneas 175–177; tipo `block`.

```text
/**********************************************
	 *	Rx Aggregation related setting
	 **********************************************/
```

## 842. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/btcoexist/halbtc8723b1ant.c:180

Líneas 180–180; tipo `block`.

```text
/* decide BT control aggregation buf size or not  */
```

## 843. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/btcoexist/halbtc8723b1ant.c:183

Líneas 183–185; tipo `block`.

```text
/* aggregation buf size, only work
	 * when BT control Rx aggregation size.
	 */
```

## 844. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/btcoexist/halbtc8723b1ant.c:187

Líneas 187–187; tipo `block`.

```text
/* real update aggregation setting  */
```

## 845. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/btcoexist/halbtc8723b1ant.c:197

Líneas 197–197; tipo `block`.

```text
/* trigger */
```

## 846. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/btcoexist/halbtc8723b1ant.c:230

Líneas 230–230; tipo `block`.

```text
/* reset counter */
```

## 847. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/btcoexist/halbtc8723b1ant.c:233

Líneas 233–243; tipo `block`.

```text
/* This part is for wifi FW and driver to update BT's status as
	 * disabled.
	 *
	 * The flow is as the following
	 * 1. disable BT
	 * 2. if all BT Tx/Rx counter = 0, after 6 sec we query bt info
	 * 3. Because BT will not rsp from mailbox, so wifi fw will know BT is
	 * disabled
	 *
	 * 4. FW will rsp c2h for BT that driver will know BT is disabled.
	 */
```

## 848. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/btcoexist/halbtc8723b1ant.c:296

Líneas 296–296; tipo `block`.

```text
/* reset counter */
```

## 849. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/btcoexist/halbtc8723b1ant.c:390

Líneas 390–390; tipo `block`.

```text
/* work around for HS mode. */
```

## 850. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/btcoexist/halbtc8723b1ant.c:396

Líneas 396–396; tipo `block`.

```text
/* check if Sco only */
```

## 851. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/btcoexist/halbtc8723b1ant.c:403

Líneas 403–403; tipo `block`.

```text
/* check if A2dp only */
```

## 852. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/btcoexist/halbtc8723b1ant.c:410

Líneas 410–410; tipo `block`.

```text
/* check if Pan only */
```

## 853. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/btcoexist/halbtc8723b1ant.c:417

Líneas 417–417; tipo `block`.

```text
/* check if Hid only */
```

## 854. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/btcoexist/halbtc8723b1ant.c:460

Líneas 460–460; tipo `block`.

```text
/* opCode, 0x6= Retry_Penalty */
```

## 855. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/btcoexist/halbtc8723b1ant.c:464

Líneas 464–464; tipo `block`.

```text
/* normal rate except MCS7/6/5, OFDM54/48/36 */
```

## 856. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/btcoexist/halbtc8723b1ant.c:466

Líneas 466–466; tipo `block`.

```text
/* MCS7 or OFDM54 */
```

## 857. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/btcoexist/halbtc8723b1ant.c:467

Líneas 467–467; tipo `block`.

```text
/* MCS6 or OFDM48 */
```

## 858. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/btcoexist/halbtc8723b1ant.c:468

Líneas 468–468; tipo `block`.

```text
/* MCS5 or OFDM36 */
```

## 859. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/btcoexist/halbtc8723b1ant.c:637

Líneas 637–637; tipo `block`.

```text
/* function enable */
```

## 860. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/btcoexist/halbtc8723b1ant.c:786

Líneas 786–786; tipo `block`.

```text
/* [31:16] = fw ver, [15:0] = fw sub ver */
```

## 861. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/btcoexist/halbtc8723b1ant.c:793

Líneas 793–793; tipo `block`.

```text
/* WiFi TRx Mask on */
```

## 862. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/btcoexist/halbtc8723b1ant.c:796

Líneas 796–798; tipo `block`.

```text
/* remove due to interrupt is disabled that polling c2h will
		 * fail and delay 100ms.
		 */
```

## 863. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/btcoexist/halbtc8723b1ant.c:801

Líneas 801–801; tipo `block`.

```text
/* Use H2C to set GNT_BT to HIGH */
```

## 864. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/btcoexist/halbtc8723b1ant.c:806

Líneas 806–806; tipo `block`.

```text
/* set grant_bt to high */
```

## 865. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/btcoexist/halbtc8723b1ant.c:809

Líneas 809–809; tipo `block`.

```text
/* set wlan_act control by PTA */
```

## 866. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/btcoexist/halbtc8723b1ant.c:812

Líneas 812–812; tipo `block`.

```text
/* BT select s0/s1 is controlled by BT */
```

## 867. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/btcoexist/halbtc8723b1ant.c:820

Líneas 820–820; tipo `block`.

```text
/* Use H2C to set GNT_BT to HIGH */
```

## 868. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/btcoexist/halbtc8723b1ant.c:825

Líneas 825–825; tipo `block`.

```text
/* set grant_bt to high */
```

## 869. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/btcoexist/halbtc8723b1ant.c:828

Líneas 828–828; tipo `block`.

```text
/* set wlan_act to always low */
```

## 870. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/btcoexist/halbtc8723b1ant.c:834

Líneas 834–834; tipo `block`.

```text
/* BT select s0/s1 is controlled by BT */
```

## 871. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/btcoexist/halbtc8723b1ant.c:838

Líneas 838–838; tipo `block`.

```text
/* BT select s0/s1 is controlled by WiFi */
```

## 872. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/btcoexist/halbtc8723b1ant.c:842

Líneas 842–844; tipo `block`.

```text
/* 0x4c[24:23]=00, Set Antenna control by BT_RFE_CTRL
		 * BT Vendor 0xac=0xf002
		 */
```

## 873. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/btcoexist/halbtc8723b1ant.c:850

Líneas 850–850; tipo `block`.

```text
/* Use H2C to set GNT_BT to LOW */
```

## 874. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/btcoexist/halbtc8723b1ant.c:858

Líneas 858–858; tipo `block`.

```text
/* BT calibration check */
```

## 875. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/btcoexist/halbtc8723b1ant.c:878

Líneas 878–878; tipo `block`.

```text
/* set grant_bt to PTA */
```

## 876. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/btcoexist/halbtc8723b1ant.c:883

Líneas 883–883; tipo `block`.

```text
/* set wlan_act control by PTA */
```

## 877. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/btcoexist/halbtc8723b1ant.c:889

Líneas 889–889; tipo `block`.

```text
/* BT select s0/s1 is controlled by WiFi */
```

## 878. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/btcoexist/halbtc8723b1ant.c:894

Líneas 894–896; tipo `block`.

```text
/* 0x4c[23] = 0, 0x4c[24] = 1
			 * Antenna control by WL/BT
			 */
```

## 879. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/btcoexist/halbtc8723b1ant.c:902

Líneas 902–902; tipo `block`.

```text
/* fixed internal switch S1->WiFi, S0->BT */
```

## 880. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/btcoexist/halbtc8723b1ant.c:907

Líneas 907–907; tipo `block`.

```text
/* tell firmware "no antenna inverse" */
```

## 881. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/btcoexist/halbtc8723b1ant.c:909

Líneas 909–909; tipo `block`.

```text
/* ext switch type */
```

## 882. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/btcoexist/halbtc8723b1ant.c:914

Líneas 914–914; tipo `block`.

```text
/* tell firmware "antenna inverse" */
```

## 883. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/btcoexist/halbtc8723b1ant.c:916

Líneas 916–916; tipo `block`.

```text
/* ext switch type */
```

## 884. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/btcoexist/halbtc8723b1ant.c:925

Líneas 925–925; tipo `block`.

```text
/* ext switch setting */
```

## 885. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/btcoexist/halbtc8723b1ant.c:959

Líneas 959–961; tipo `block`.

```text
/* 0x4c[23] = 1, 0x4c[24] = 0,
			 * Antenna control by 0x64
			 */
```

## 886. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/btcoexist/halbtc8723b1ant.c:967

Líneas 967–967; tipo `block`.

```text
/* Fix Ext switch Main->S1, Aux->S0 */
```

## 887. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/btcoexist/halbtc8723b1ant.c:973

Líneas 973–973; tipo `block`.

```text
/* tell firmware "no antenna inverse" */
```

## 888. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/btcoexist/halbtc8723b1ant.c:975

Líneas 975–975; tipo `block`.

```text
/* internal switch type */
```

## 889. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/btcoexist/halbtc8723b1ant.c:980

Líneas 980–980; tipo `block`.

```text
/* tell firmware "antenna inverse" */
```

## 890. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/btcoexist/halbtc8723b1ant.c:982

Líneas 982–982; tipo `block`.

```text
/* internal switch type */
```

## 891. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/btcoexist/halbtc8723b1ant.c:991

Líneas 991–991; tipo `block`.

```text
/* internal switch setting */
```

## 892. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/btcoexist/halbtc8723b1ant.c:1087

Líneas 1087–1089; tipo `block`.

```text
/* Native power save TDMA, only for A2DP-only case
			 * 1/2/9/11 while wifi noisy threshold > 30
			 */
```

## 893. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/btcoexist/halbtc8723b1ant.c:1091

Líneas 1091–1091; tipo `block`.

```text
/* no null-pkt */
```

## 894. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/btcoexist/halbtc8723b1ant.c:1093

Líneas 1093–1093; tipo `block`.

```text
/* no tx-pause at BT-slot */
```

## 895. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/btcoexist/halbtc8723b1ant.c:1095

Líneas 1095–1095; tipo `block`.

```text
/* 0x778 = d/1 toggle, no dynamic slot */
```

## 896. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/btcoexist/halbtc8723b1ant.c:1098

Líneas 1098–1098; tipo `block`.

```text
/* null-pkt */
```

## 897. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/btcoexist/halbtc8723b1ant.c:1100

Líneas 1100–1100; tipo `block`.

```text
/* tx-pause at BT-slot */
```

## 898. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/btcoexist/halbtc8723b1ant.c:1102

Líneas 1102–1102; tipo `block`.

```text
/* 0x778 = d/1 toggle, dynamic slot */
```

## 899. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/btcoexist/halbtc8723b1ant.c:1107

Líneas 1107–1107; tipo `block`.

```text
/* null-pkt */
```

## 900. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/btcoexist/halbtc8723b1ant.c:1109

Líneas 1109–1109; tipo `block`.

```text
/* tx-pause at BT-slot */
```

## 901. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/btcoexist/halbtc8723b1ant.c:1111

Líneas 1111–1111; tipo `block`.

```text
/* 0x778 = d/1 toggle, no dynamic slot */
```

## 902. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/btcoexist/halbtc8723b1ant.c:1113

Líneas 1113–1113; tipo `block`.

```text
/* native power save case */
```

## 903. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/btcoexist/halbtc8723b1ant.c:1114

Líneas 1114–1114; tipo `block`.

```text
/* no null-pkt */
```

## 904. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/btcoexist/halbtc8723b1ant.c:1116

Líneas 1116–1116; tipo `block`.

```text
/* no tx-pause at BT-slot */
```

## 905. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/btcoexist/halbtc8723b1ant.c:1118

Líneas 1118–1118; tipo `block`.

```text
/* 0x778 = d/1 toggle, no dynamic slot */
```

## 906. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/btcoexist/halbtc8723b1ant.c:1120

Líneas 1120–1120; tipo `block`.

```text
/* psTdmaByte4Va is not define for 0x778 = d/1, 1/1 case */
```

## 907. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/btcoexist/halbtc8723b1ant.c:1123

Líneas 1123–1123; tipo `block`.

```text
/* if (bt_link_info->slave_role) */
```

## 908. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/btcoexist/halbtc8723b1ant.c:1125

Líneas 1125–1125; tipo `block`.

```text
/* 0x778 = 0x1 at wifi slot (no blocking BT Low-Pri pkts) */
```

## 909. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/btcoexist/halbtc8723b1ant.c:1129

Líneas 1129–1129; tipo `block`.

```text
/* set antenna control by SW	 */
```

## 910. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/btcoexist/halbtc8723b1ant.c:1131

Líneas 1131–1131; tipo `block`.

```text
/* set antenna no toggle, control by antenna diversity */
```

## 911. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/btcoexist/halbtc8723b1ant.c:1305

Líneas 1305–1310; tipo `block`.

```text
/* SoftAP only with no sta associated,BT disable ,TDMA
			 * mode for power saving
			 *
			 * here softap mode screen off will cost 70-80mA for
			 * phone
			 */
```

## 912. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/btcoexist/halbtc8723b1ant.c:1316

Líneas 1316–1316; tipo `block`.

```text
/* for 1-Ant translate to 2-Ant	 */
```

## 913. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/btcoexist/halbtc8723b1ant.c:1385

Líneas 1385–1385; tipo `block`.

```text
/* disable PS tdma */
```

## 914. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/btcoexist/halbtc8723b1ant.c:1387

Líneas 1387–1387; tipo `block`.

```text
/* PTA Control */
```

## 915. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/btcoexist/halbtc8723b1ant.c:1397

Líneas 1397–1397; tipo `block`.

```text
/* Software control, Antenna at BT side */
```

## 916. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/btcoexist/halbtc8723b1ant.c:1401

Líneas 1401–1401; tipo `block`.

```text
/* 2-Ant, 0x778=3, antenna control by ant diversity */
```

## 917. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/btcoexist/halbtc8723b1ant.c:1412

Líneas 1412–1412; tipo `block`.

```text
/* update pre state */
```

## 918. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/btcoexist/halbtc8723b1ant.c:1423

Líneas 1423–1425; tipo `block`.

```text
/*  0: no change, +1: increase WiFi duration,
	 * -1: decrease WiFi duration
	 */
```

## 919. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/btcoexist/halbtc8723b1ant.c:1467

Líneas 1467–1467; tipo `block`.

```text
/* acquire the BT TRx retry count from BT_Info byte2 */
```

## 920. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/btcoexist/halbtc8723b1ant.c:1476

Líneas 1476–1476; tipo `block`.

```text
/* no retry in the last 2-second duration */
```

## 921. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/btcoexist/halbtc8723b1ant.c:1485

Líneas 1485–1487; tipo `block`.

```text
/* if retry count during continuous n*2 seconds
				 * is 0, enlarge WiFi duration
				 */
```

## 922. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/btcoexist/halbtc8723b1ant.c:1497

Líneas 1497–1497; tipo `block`.

```text
/* <=3 retry in the last 2-second duration */
```

## 923. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/btcoexist/halbtc8723b1ant.c:1505

Líneas 1505–1507; tipo `block`.

```text
/* if continuous 2 retry count(every 2 seconds)
				 * >0 and < 3, reduce WiFi duration
				 */
```

## 924. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/btcoexist/halbtc8723b1ant.c:1509

Líneas 1509–1509; tipo `block`.

```text
/* avoid loop between the two levels */
```

## 925. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/btcoexist/halbtc8723b1ant.c:1515

Líneas 1515–1518; tipo `block`.

```text
/* maximum of m = 20 ' will recheck if
					 * need to adjust wifi duration in
					 * maximum time interval 120 seconds
					 */
```

## 926. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/btcoexist/halbtc8723b1ant.c:1530

Líneas 1530–1532; tipo `block`.

```text
/* retry count > 3, once retry count > 3, to reduce
			 * WiFi duration
			 */
```

## 927. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/btcoexist/halbtc8723b1ant.c:1534

Líneas 1534–1534; tipo `block`.

```text
/* to avoid loop between the two levels */
```

## 928. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/btcoexist/halbtc8723b1ant.c:1540

Líneas 1540–1543; tipo `block`.

```text
/* maximum of m = 20 ' will recheck if need to
				 * adjust wifi duration in maximum time interval
				 * 120 seconds
				 */
```

## 929. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/btcoexist/halbtc8723b1ant.c:1587

Líneas 1587–1587; tipo `block`.

```text
/* recover to previous adjust type */
```

## 930. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/btcoexist/halbtc8723b1ant.c:1602

Líneas 1602–1602; tipo `block`.

```text
/* already under LPS state */
```

## 931. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/btcoexist/halbtc8723b1ant.c:1604

Líneas 1604–1604; tipo `block`.

```text
/* keep state under LPS, do nothing. */
```

## 932. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/btcoexist/halbtc8723b1ant.c:1606

Líneas 1606–1606; tipo `block`.

```text
/* will leave LPS state, turn off psTdma first */
```

## 933. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/btcoexist/halbtc8723b1ant.c:1611

Líneas 1611–1611; tipo `block`.

```text
/* NO PS state */
```

## 934. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/btcoexist/halbtc8723b1ant.c:1613

Líneas 1613–1613; tipo `block`.

```text
/* will enter LPS state, turn off psTdma first */
```

## 935. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/btcoexist/halbtc8723b1ant.c:1617

Líneas 1617–1617; tipo `block`.

```text
/* keep state under NO PS state, do nothing. */
```

## 936. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/btcoexist/halbtc8723b1ant.c:1630

Líneas 1630–1630; tipo `block`.

```text
/* recover to original 32k low power setting */
```

## 937. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/btcoexist/halbtc8723b1ant.c:1641

Líneas 1641–1641; tipo `block`.

```text
/* when coex force to enter LPS, do not enter 32k low power */
```

## 938. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/btcoexist/halbtc8723b1ant.c:1645

Líneas 1645–1645; tipo `block`.

```text
/* power save must executed before psTdma */
```

## 939. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/btcoexist/halbtc8723b1ant.c:1667

Líneas 1667–1667; tipo `block`.

```text
/* check if BT is disabled */
```

## 940. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/btcoexist/halbtc8723b1ant.c:1711

Líneas 1711–1715; tipo `block`.

```text
/*****************************************************
 *
 *	Non-Software Coex Mechanism start
 *
 *****************************************************/
```

## 941. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/btcoexist/halbtc8723b1ant.c:1770

Líneas 1770–1770; tipo `block`.

```text
/* SCO/HID/A2DP busy */
```

## 942. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/btcoexist/halbtc8723b1ant.c:1811

Líneas 1811–1811; tipo `block`.

```text
/* tdma and coex table */
```

## 943. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/btcoexist/halbtc8723b1ant.c:1816

Líneas 1816–1816; tipo `block`.

```text
/* HID */
```

## 944. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/btcoexist/halbtc8723b1ant.c:1833

Líneas 1833–1833; tipo `block`.

```text
/* HID */
```

## 945. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/btcoexist/halbtc8723b1ant.c:1837

Líneas 1837–1837; tipo `block`.

```text
/* A2DP */
```

## 946. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/btcoexist/halbtc8723b1ant.c:1854

Líneas 1854–1854; tipo `block`.

```text
/* A2DP + PAN(OPP,FTP), HID + A2DP + PAN(OPP,FTP) */
```

## 947. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/btcoexist/halbtc8723b1ant.c:1859

Líneas 1859–1859; tipo `block`.

```text
/* HID + A2DP */
```

## 948. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/btcoexist/halbtc8723b1ant.c:1866

Líneas 1866–1866; tipo `block`.

```text
/* PAN(OPP,FTP), HID + PAN(OPP,FTP) */
```

## 949. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/btcoexist/halbtc8723b1ant.c:1871

Líneas 1871–1871; tipo `block`.

```text
/* BT no-profile busy (0x9) */
```

## 950. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/btcoexist/halbtc8723b1ant.c:1880

Líneas 1880–1880; tipo `block`.

```text
/* power save state */
```

## 951. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/btcoexist/halbtc8723b1ant.c:1884

Líneas 1884–1884; tipo `block`.

```text
/* tdma and coex table */
```

## 952. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/btcoexist/halbtc8723b1ant.c:1899

Líneas 1899–1899; tipo `block`.

```text
/* tdma and coex table */
```

## 953. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/btcoexist/halbtc8723b1ant.c:1937

Líneas 1937–1937; tipo `block`.

```text
/* tdma and coex table */
```

## 954. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/btcoexist/halbtc8723b1ant.c:1960

Líneas 1960–1960; tipo `block`.

```text
/* tdma and coex table */
```

## 955. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/btcoexist/halbtc8723b1ant.c:1999

Líneas 1999–1999; tipo `block`.

```text
/* no special packet process for both WiFi and BT very busy */
```

## 956. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/btcoexist/halbtc8723b1ant.c:2007

Líneas 2007–2007; tipo `block`.

```text
/* tdma and coex table */
```

## 957. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/btcoexist/halbtc8723b1ant.c:2062

Líneas 2062–2062; tipo `block`.

```text
/* power save state */
```

## 958. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/btcoexist/halbtc8723b1ant.c:2071

Líneas 2071–2071; tipo `block`.

```text
/* busy */
```

## 959. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/btcoexist/halbtc8723b1ant.c:2074

Líneas 2074–2076; tipo `block`.

```text
/* no force LPS, no PS-TDMA,
					 * use pure TDMA
					 */
```

## 960. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/btcoexist/halbtc8723b1ant.c:2097

Líneas 2097–2097; tipo `block`.

```text
/* tdma and coex table */
```

## 961. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/btcoexist/halbtc8723b1ant.c:2296

Líneas 2296–2296; tipo `block`.

```text
/* wifi LPS/Busy */
```

## 962. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/btcoexist/halbtc8723b1ant.c:2301

Líneas 2301–2301; tipo `block`.

```text
/* force coex mechanism to reset */
```

## 963. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/btcoexist/halbtc8723b1ant.c:2304

Líneas 2304–2304; tipo `block`.

```text
/* sw all off */
```

## 964. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/btcoexist/halbtc8723b1ant.c:2320

Líneas 2320–2320; tipo `block`.

```text
/* 0xf0[15:12] --> Chip Cut information */
```

## 965. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/btcoexist/halbtc8723b1ant.c:2323

Líneas 2323–2323; tipo `block`.

```text
/* enable TBTT interrupt */
```

## 966. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/btcoexist/halbtc8723b1ant.c:2326

Líneas 2326–2326; tipo `block`.

```text
/* 0x790[5:0] = 0x5 */
```

## 967. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/btcoexist/halbtc8723b1ant.c:2329

Líneas 2329–2329; tipo `block`.

```text
/* Enable counter statistics */
```

## 968. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/btcoexist/halbtc8723b1ant.c:2335

Líneas 2335–2335; tipo `block`.

```text
/* Antenna config */
```

## 969. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/btcoexist/halbtc8723b1ant.c:2343

Líneas 2343–2343; tipo `block`.

```text
/* PTA parameter */
```

## 970. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/btcoexist/halbtc8723b1ant.c:2355

Líneas 2355–2357; tipo `block`.

```text
/**************************************************************
 * extern function start with ex_btc8723b1ant_
 **************************************************************/
```

## 971. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/btcoexist/halbtc8723b1ant.c:2373

Líneas 2373–2373; tipo `block`.

```text
/* enable BB, REG_SYS_FUNC_EN such that we can write 0x948 correctly. */
```

## 972. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/btcoexist/halbtc8723b1ant.c:2377

Líneas 2377–2377; tipo `block`.

```text
/* set GRAN_BT = 1 */
```

## 973. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/btcoexist/halbtc8723b1ant.c:2379

Líneas 2379–2379; tipo `block`.

```text
/* set WLAN_ACT = 0 */
```

## 974. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/btcoexist/halbtc8723b1ant.c:2382

Líneas 2382–2391; tipo `block`.

```text
/* S0 or S1 setting and Local register setting(By the setting fw can get
	 * ant number, S0/S1, ... info)
	 *
	 * Local setting bit define
	 *	BIT0: "0" for no antenna inverse; "1" for antenna inverse
	 *	BIT1: "0" for internal switch; "1" for external switch
	 *	BIT2: "0" for one antenna; "1" for two antenna
	 * NOTE: here default all internal switch and 1-antenna ==> BIT1=0 and
	 * BIT2 = 0
	 */
```

## 975. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/btcoexist/halbtc8723b1ant.c:2393

Líneas 2393–2393; tipo `block`.

```text
/* fixed at S0 for USB interface */
```

## 976. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/btcoexist/halbtc8723b1ant.c:2396

Líneas 2396–2396; tipo `block`.

```text
/* antenna inverse */
```

## 977. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/btcoexist/halbtc8723b1ant.c:2401

Líneas 2401–2401; tipo `block`.

```text
/* for PCIE and SDIO interface, we check efuse 0xc3[6] */
```

## 978. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/btcoexist/halbtc8723b1ant.c:2403

Líneas 2403–2403; tipo `block`.

```text
/* set to S1 */
```

## 979. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/btcoexist/halbtc8723b1ant.c:2408

Líneas 2408–2408; tipo `block`.

```text
/* set to S0 */
```

## 980. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/btcoexist/halbtc8723b1ant.c:2410

Líneas 2410–2410; tipo `block`.

```text
/* antenna inverse */
```

## 981. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/btcoexist/halbtc8723b1ant.c:2582

Líneas 2582–2582; tipo `block`.

```text
/* Sw mechanism	*/
```

## 982. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/btcoexist/halbtc8723b1ant.c:2598

Líneas 2598–2598; tipo `block`.

```text
/* Fw mechanism	*/
```

## 983. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/btcoexist/halbtc8723b1ant.c:2618

Líneas 2618–2618; tipo `block`.

```text
/* Hw setting */
```

## 984. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/btcoexist/halbtc8723b1ant.c:2727

Líneas 2727–2727; tipo `block`.

```text
/* set PTA control */
```

## 985. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/btcoexist/halbtc8723b1ant.c:2778

Líneas 2778–2778; tipo `block`.

```text
/* Force antenna setup for no scan result issue */
```

## 986. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/btcoexist/halbtc8723b1ant.c:2830

Líneas 2830–2830; tipo `block`.

```text
/* non-connected scan */
```

## 987. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/btcoexist/halbtc8723b1ant.c:2833

Líneas 2833–2833; tipo `block`.

```text
/* wifi is connected */
```

## 988. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/btcoexist/halbtc8723b1ant.c:2839

Líneas 2839–2839; tipo `block`.

```text
/* non-connected scan */
```

## 989. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/btcoexist/halbtc8723b1ant.c:2865

Líneas 2865–2865; tipo `block`.

```text
/* Force antenna setup for no scan result issue */
```

## 990. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/btcoexist/halbtc8723b1ant.c:2909

Líneas 2909–2909; tipo `block`.

```text
/* non-connected scan */
```

## 991. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/btcoexist/halbtc8723b1ant.c:2932

Líneas 2932–2932; tipo `block`.

```text
/* Force antenna setup for no scan result issue */
```

## 992. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/btcoexist/halbtc8723b1ant.c:2939

Líneas 2939–2939; tipo `block`.

```text
/* Set CCK Tx/Rx high Pri except 11b mode */
```

## 993. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/btcoexist/halbtc8723b1ant.c:2942

Líneas 2942–2942; tipo `block`.

```text
/* CCK Tx */
```

## 994. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/btcoexist/halbtc8723b1ant.c:2944

Líneas 2944–2944; tipo `block`.

```text
/* CCK Rx */
```

## 995. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/btcoexist/halbtc8723b1ant.c:2947

Líneas 2947–2947; tipo `block`.

```text
/* CCK Tx */
```

## 996. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/btcoexist/halbtc8723b1ant.c:2949

Líneas 2949–2949; tipo `block`.

```text
/* CCK Rx */
```

## 997. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/btcoexist/halbtc8723b1ant.c:2965

Líneas 2965–2965; tipo `block`.

```text
/* CCK Tx */
```

## 998. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/btcoexist/halbtc8723b1ant.c:2966

Líneas 2966–2966; tipo `block`.

```text
/* CCK Rx */
```

## 999. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/btcoexist/halbtc8723b1ant.c:2971

Líneas 2971–2971; tipo `block`.

```text
/* only 2.4G we need to inform bt the chnl mask */
```

## 1000. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/btcoexist/halbtc8723b1ant.c:3026

Líneas 3026–3028; tipo `block`.

```text
/* if APR PKT > 10 after connect, do not go to
				 * ActionWifiConnectedSpecificPacket(btcoexist)
				 */
```

## 1001. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/btcoexist/halbtc8723b1ant.c:3105

Líneas 3105–3105; tipo `block`.

```text
/* if 0xff, it means BT is under WHCK test */
```

## 1002. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/btcoexist/halbtc8723b1ant.c:3112

Líneas 3112–3112; tipo `block`.

```text
/* [3:0] */
```

## 1003. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/btcoexist/halbtc8723b1ant.c:3142

Líneas 3142–3144; tipo `block`.

```text
/* BT into is responded by BT FW and BT RF REG
			 * 0x3C != 0x15 => Need to switch BT TRx Mask
			 */
```

## 1004. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/btcoexist/halbtc8723b1ant.c:3150

Líneas 3150–3150; tipo `block`.

```text
/* BT TRx Mask lock 0x2c[0], 0x30[0] = 0 */
```

## 1005. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/btcoexist/halbtc8723b1ant.c:3157

Líneas 3157–3159; tipo `block`.

```text
/* Here we need to resend some wifi info to BT
		 * because bt is reset and loss of the info.
		 */
```

## 1006. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/btcoexist/halbtc8723b1ant.c:3183

Líneas 3183–3183; tipo `block`.

```text
/* BT already NOT ignore Wlan active, do nothing here.*/
```

## 1007. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/btcoexist/halbtc8723b1ant.c:3187

Líneas 3187–3187; tipo `block`.

```text
/* BT auto report already enabled, do nothing */
```

## 1008. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/btcoexist/halbtc8723b1ant.c:3196

Líneas 3196–3196; tipo `block`.

```text
/* check BIT2 first ==> check if bt is under inquiry or page scan */
```

## 1009. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/btcoexist/halbtc8723b1ant.c:3204

Líneas 3204–3204; tipo `block`.

```text
/* set link exist status */
```

## 1010. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/btcoexist/halbtc8723b1ant.c:3214

Líneas 3214–3214; tipo `block`.

```text
/* connection exists */
```

## 1011. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/btcoexist/halbtc8723b1ant.c:3254

Líneas 3254–3254; tipo `block`.

```text
/* Add Hi-Pri Tx/Rx counter to avoid false detection */
```

## 1012. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/btcoexist/halbtc8723b1ant.c:3276

Líneas 3276–3278; tipo `block`.

```text
/* mask profile bit for connect-ilde identification
	 * ( for CSR case: A2DP idle --> 0x41)
	 */
```

## 1013. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/btcoexist/halbtc8723b1ant.c:3285

Líneas 3285–3285; tipo `block`.

```text
/* connection exists but no busy */
```

## 1014. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/btcoexist/halbtc8723b1ant.c:3394

Líneas 3394–3399; tipo `block`.

```text
/* Driver do not leave IPS/LPS when driver is going to sleep, so
		 * BTCoexistence think wifi is still under IPS/LPS
		 *
		 * BT should clear UnderIPS/UnderLPS state to avoid mismatch
		 * state after wakeup.
		 */
```

## 1015. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/btcoexist/halbtc8723b1ant.h:1

Líneas 1–1; tipo `block`.

```text
/* SPDX-License-Identifier: GPL-2.0 */
```

## 1016. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/btcoexist/halbtc8723b1ant.h:2

Líneas 2–2; tipo `block`.

```text
/* Copyright(c) 2012  Realtek Corporation.*/
```

## 1017. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/btcoexist/halbtc8723b1ant.h:4

Líneas 4–6; tipo `block`.

```text
/**********************************************************************
 * The following is for 8723B 1ANT BT Co-exist definition
 **********************************************************************/
```

## 1018. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/btcoexist/halbtc8723b1ant.h:66

Líneas 66–66; tipo `block`.

```text
/* hw setting */
```

## 1019. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/btcoexist/halbtc8723b1ant.h:69

Líneas 69–69; tipo `block`.

```text
/* fw mechanism */
```

## 1020. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/btcoexist/halbtc8723b1ant.h:86

Líneas 86–86; tipo `block`.

```text
/* sw mechanism */
```

## 1021. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/btcoexist/halbtc8723b1ant.h:99

Líneas 99–99; tipo `block`.

```text
/* Auto Rate Fallback Retry cnt */
```

## 1022. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/btcoexist/halbtc8723b1ant.h:100

Líneas 100–100; tipo `block`.

```text
/* Auto Rate Fallback Retry cnt */
```

## 1023. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/btcoexist/halbtc8723b1ant.h:104

Líneas 104–104; tipo `block`.

```text
/* algorithm related */
```

## 1024. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/btcoexist/halbtc8723b1ant.h:179

Líneas 179–181; tipo `block`.

```text
/*************************************************************************
 * The following is interface which will notify coex module.
 *************************************************************************/
```

## 1025. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/btcoexist/halbtc8723b2ant.c:1

Líneas 1–1; tipo `line`.

```text
// SPDX-License-Identifier: GPL-2.0
```

## 1026. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/btcoexist/halbtc8723b2ant.c:2

Líneas 2–2; tipo `block`.

```text
/* Copyright(c) 2012  Realtek Corporation.*/
```

## 1027. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/btcoexist/halbtc8723b2ant.c:4

Líneas 4–12; tipo `block`.

```text
/***************************************************************
 * Description:
 *
 * This file is for RTL8723B Co-exist mechanism
 *
 * History
 * 2012/11/15 Cosa first check in.
 *
 **************************************************************/
```

## 1028. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/btcoexist/halbtc8723b2ant.c:13

Líneas 13–15; tipo `block`.

```text
/**************************************************************
 * include files
 **************************************************************/
```

## 1029. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/btcoexist/halbtc8723b2ant.c:17

Líneas 17–19; tipo `block`.

```text
/**************************************************************
 * Global variables, these are static variables
 **************************************************************/
```

## 1030. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/btcoexist/halbtc8723b2ant.c:34

Líneas 34–36; tipo `block`.

```text
/**************************************************************
 * local function proto type if needed
 **************************************************************/
```

## 1031. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/btcoexist/halbtc8723b2ant.c:37

Líneas 37–39; tipo `block`.

```text
/**************************************************************
 * local function start with btc8723b2ant_
 **************************************************************/
```

## 1032. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/btcoexist/halbtc8723b2ant.c:231

Líneas 231–231; tipo `block`.

```text
/* ============================================ */
```

## 1033. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/btcoexist/halbtc8723b2ant.c:232

Líneas 232–232; tipo `block`.

```text
/*	Rx Aggregation related setting		*/
```

## 1034. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/btcoexist/halbtc8723b2ant.c:233

Líneas 233–233; tipo `block`.

```text
/* ============================================ */
```

## 1035. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/btcoexist/halbtc8723b2ant.c:236

Líneas 236–236; tipo `block`.

```text
/* decide BT control aggregation buf size or not */
```

## 1036. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/btcoexist/halbtc8723b2ant.c:239

Líneas 239–239; tipo `block`.

```text
/* aggregate buf size, only work when BT control Rx aggregate size */
```

## 1037. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/btcoexist/halbtc8723b2ant.c:241

Líneas 241–241; tipo `block`.

```text
/* real update aggregation setting */
```

## 1038. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/btcoexist/halbtc8723b2ant.c:287

Líneas 287–287; tipo `block`.

```text
/* reset counter */
```

## 1039. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/btcoexist/halbtc8723b2ant.c:323

Líneas 323–323; tipo `block`.

```text
/* reset counter */
```

## 1040. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/btcoexist/halbtc8723b2ant.c:335

Líneas 335–335; tipo `block`.

```text
/* trigger */
```

## 1041. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/btcoexist/halbtc8723b2ant.c:403

Líneas 403–403; tipo `block`.

```text
/* work around for HS mode. */
```

## 1042. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/btcoexist/halbtc8723b2ant.c:409

Líneas 409–409; tipo `block`.

```text
/* check if Sco only */
```

## 1043. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/btcoexist/halbtc8723b2ant.c:416

Líneas 416–416; tipo `block`.

```text
/* check if A2dp only */
```

## 1044. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/btcoexist/halbtc8723b2ant.c:423

Líneas 423–423; tipo `block`.

```text
/* check if Pan only */
```

## 1045. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/btcoexist/halbtc8723b2ant.c:430

Líneas 430–430; tipo `block`.

```text
/* check if Hid only */
```

## 1046. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/btcoexist/halbtc8723b2ant.c:639

Líneas 639–641; tipo `block`.

```text
/* There are several type of dacswing
	 * 0x18/ 0x10/ 0xc/ 0x8/ 0x4/ 0x6
	 */
```

## 1047. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/btcoexist/halbtc8723b2ant.c:751

Líneas 751–751; tipo `block`.

```text
/* op_code, 0x6 = Retry_Penalty */
```

## 1048. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/btcoexist/halbtc8723b2ant.c:755

Líneas 755–755; tipo `block`.

```text
/* normal rate except MCS7/6/5, OFDM54/48/36 */
```

## 1049. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/btcoexist/halbtc8723b2ant.c:757

Líneas 757–757; tipo `block`.

```text
/* MCS7 or OFDM54 */
```

## 1050. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/btcoexist/halbtc8723b2ant.c:758

Líneas 758–758; tipo `block`.

```text
/* MCS6 or OFDM48 */
```

## 1051. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/btcoexist/halbtc8723b2ant.c:759

Líneas 759–759; tipo `block`.

```text
/* MCS5 or OFDM36 */
```

## 1052. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/btcoexist/halbtc8723b2ant.c:992

Líneas 992–992; tipo `block`.

```text
/* function enable */
```

## 1053. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/btcoexist/halbtc8723b2ant.c:1113

Líneas 1113–1113; tipo `block`.

```text
/* Use H2C to set GNT_BT to High to avoid A2DP click */
```

## 1054. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/btcoexist/halbtc8723b2ant.c:1123

Líneas 1123–1123; tipo `block`.

```text
/* WiFi TRx Mask off */
```

## 1055. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/btcoexist/halbtc8723b2ant.c:1128

Líneas 1128–1128; tipo `block`.

```text
/* tell firmware "no antenna inverse" */
```

## 1056. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/btcoexist/halbtc8723b2ant.c:1131

Líneas 1131–1131; tipo `block`.

```text
/* tell firmware "antenna inverse" */
```

## 1057. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/btcoexist/halbtc8723b2ant.c:1136

Líneas 1136–1136; tipo `block`.

```text
/* ext switch type */
```

## 1058. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/btcoexist/halbtc8723b2ant.c:1139

Líneas 1139–1139; tipo `block`.

```text
/* int switch type */
```

## 1059. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/btcoexist/halbtc8723b2ant.c:1145

Líneas 1145–1145; tipo `block`.

```text
/* Use H2C to set GNT_BT to "Control by PTA"*/
```

## 1060. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/btcoexist/halbtc8723b2ant.c:1154

Líneas 1154–1154; tipo `block`.

```text
/* ext switch setting */
```

## 1061. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/btcoexist/halbtc8723b2ant.c:1157

Líneas 1157–1157; tipo `block`.

```text
/* 0x4c[23] = 0, 0x4c[24] = 1 Ant controlled by WL/BT */
```

## 1062. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/btcoexist/halbtc8723b2ant.c:1164

Líneas 1164–1164; tipo `block`.

```text
/* fixed internal switch S1->WiFi, S0->BT */
```

## 1063. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/btcoexist/halbtc8723b2ant.c:1172

Líneas 1172–1172; tipo `block`.

```text
/* ext switch main at wifi */
```

## 1064. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/btcoexist/halbtc8723b2ant.c:1177

Líneas 1177–1177; tipo `block`.

```text
/* ext switch aux at wifi */
```

## 1065. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/btcoexist/halbtc8723b2ant.c:1183

Líneas 1183–1183; tipo `block`.

```text
/* internal switch */
```

## 1066. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/btcoexist/halbtc8723b2ant.c:1185

Líneas 1185–1185; tipo `block`.

```text
/* 0x4c[23] = 0, 0x4c[24] = 1 Ant controlled by WL/BT */
```

## 1067. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/btcoexist/halbtc8723b2ant.c:1192

Líneas 1192–1192; tipo `block`.

```text
/* fixed ext switch, S1->Main, S0->Aux */
```

## 1068. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/btcoexist/halbtc8723b2ant.c:1196

Líneas 1196–1196; tipo `block`.

```text
/* fixed internal switch S1->WiFi, S0->BT */
```

## 1069. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/btcoexist/halbtc8723b2ant.c:1200

Líneas 1200–1200; tipo `block`.

```text
/* fixed internal switch S0->WiFi, S1->BT */
```

## 1070. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/btcoexist/halbtc8723b2ant.c:1232

Líneas 1232–1232; tipo `block`.

```text
/* for WiFi RSSI low or BT RSSI low */
```

## 1071. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/btcoexist/halbtc8723b2ant.c:1283

Líneas 1283–1283; tipo `block`.

```text
/* 0x778 = 0x1 at wifi slot (no blocking BT Low-Pri pkts) */
```

## 1072. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/btcoexist/halbtc8723b2ant.c:1449

Líneas 1449–1449; tipo `block`.

```text
/* disable PS tdma */
```

## 1073. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/btcoexist/halbtc8723b2ant.c:1466

Líneas 1466–1466; tipo `block`.

```text
/* update pre state */
```

## 1074. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/btcoexist/halbtc8723b2ant.c:1479

Líneas 1479–1479; tipo `block`.

```text
/* already under LPS state */
```

## 1075. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/btcoexist/halbtc8723b2ant.c:1481

Líneas 1481–1481; tipo `block`.

```text
/* keep state under LPS, do nothing. */
```

## 1076. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/btcoexist/halbtc8723b2ant.c:1483

Líneas 1483–1483; tipo `block`.

```text
/* will leave LPS state, turn off psTdma first */
```

## 1077. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/btcoexist/halbtc8723b2ant.c:1487

Líneas 1487–1487; tipo `block`.

```text
/* NO PS state */
```

## 1078. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/btcoexist/halbtc8723b2ant.c:1489

Líneas 1489–1489; tipo `block`.

```text
/* will enter LPS state, turn off psTdma first */
```

## 1079. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/btcoexist/halbtc8723b2ant.c:1492

Líneas 1492–1492; tipo `block`.

```text
/* keep state under NO PS state, do nothing. */
```

## 1080. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/btcoexist/halbtc8723b2ant.c:1504

Líneas 1504–1504; tipo `block`.

```text
/* recover to original 32k low power setting */
```

## 1081. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/btcoexist/halbtc8723b2ant.c:1516

Líneas 1516–1516; tipo `block`.

```text
/* when coex force to enter LPS, do not enter 32k low power */
```

## 1082. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/btcoexist/halbtc8723b2ant.c:1520

Líneas 1520–1520; tipo `block`.

```text
/* power save must executed before psTdma */
```

## 1083. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/btcoexist/halbtc8723b2ant.c:1537

Líneas 1537–1537; tipo `block`.

```text
/* fw all off */
```

## 1084. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/btcoexist/halbtc8723b2ant.c:1543

Líneas 1543–1543; tipo `block`.

```text
/* sw all off */
```

## 1085. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/btcoexist/halbtc8723b2ant.c:1546

Líneas 1546–1546; tipo `block`.

```text
/* hw all off */
```

## 1086. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/btcoexist/halbtc8723b2ant.c:1553

Líneas 1553–1553; tipo `block`.

```text
/* force to reset coex mechanism*/
```

## 1087. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/btcoexist/halbtc8723b2ant.c:1645

Líneas 1645–1645; tipo `block`.

```text
/* office environment */
```

## 1088. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/btcoexist/halbtc8723b2ant.c:1654

Líneas 1654–1654; tipo `block`.

```text
/* sw all off */
```

## 1089. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/btcoexist/halbtc8723b2ant.c:1785

Líneas 1785–1785; tipo `block`.

```text
/*0: no change, +1: increase WiFi duration, -1: decrease WiFi duration*/
```

## 1090. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/btcoexist/halbtc8723b2ant.c:1897

Líneas 1897–1897; tipo `block`.

```text
/*accquire the BT TRx retry count from BT_Info byte2*/
```

## 1091. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/btcoexist/halbtc8723b2ant.c:1911

Líneas 1911–1911; tipo `block`.

```text
/* no retry in the last 2-second duration*/
```

## 1092. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/btcoexist/halbtc8723b2ant.c:1920

Líneas 1920–1922; tipo `block`.

```text
/* if retry count during continuous n*2
				 * seconds is 0, enlarge WiFi duration
				 */
```

## 1093. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/btcoexist/halbtc8723b2ant.c:1930

Líneas 1930–1930; tipo `block`.

```text
/* <=3 retry in the last 2-second duration*/
```

## 1094. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/btcoexist/halbtc8723b2ant.c:1939

Líneas 1939–1941; tipo `block`.

```text
/* if continuous 2 retry count(every 2
				 * seconds) >0 and < 3, reduce WiFi duration
				 */
```

## 1095. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/btcoexist/halbtc8723b2ant.c:1943

Líneas 1943–1943; tipo `block`.

```text
/* avoid loop between the two levels */
```

## 1096. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/btcoexist/halbtc8723b2ant.c:1949

Líneas 1949–1952; tipo `block`.

```text
/* maximum of m = 20 ' will recheck if
					 * need to adjust wifi duration in
					 * maximum time interval 120 seconds
					 */
```

## 1097. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/btcoexist/halbtc8723b2ant.c:1964

Líneas 1964–1966; tipo `block`.

```text
/* retry count > 3, once retry count > 3, to reduce
			 *  WiFi duration
			 */
```

## 1098. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/btcoexist/halbtc8723b2ant.c:1968

Líneas 1968–1968; tipo `block`.

```text
/* to avoid loop between the two levels */
```

## 1099. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/btcoexist/halbtc8723b2ant.c:1974

Líneas 1974–1977; tipo `block`.

```text
/* maximum of m = 20 ' will recheck if need to
				 * adjust wifi duration in maximum time interval
				 * 120 seconds
				 */
```

## 1100. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/btcoexist/halbtc8723b2ant.c:2742

Líneas 2742–2744; tipo `block`.

```text
/* if current PsTdma not match with the recorded one (scan, dhcp, ...),
	 * then we have to adjust it back to the previous recorded one.
	 */
```

## 1101. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/btcoexist/halbtc8723b2ant.c:2764

Líneas 2764–2764; tipo `block`.

```text
/* SCO only or SCO+PAN(HS) */
```

## 1102. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/btcoexist/halbtc8723b2ant.c:2789

Líneas 2789–2789; tipo `block`.

```text
/* for SCO quality at 11b/g mode */
```

## 1103. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/btcoexist/halbtc8723b2ant.c:2792

Líneas 2792–2792; tipo `block`.

```text
/* for SCO quality & wifi performance balance at 11n mode */
```

## 1104. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/btcoexist/halbtc8723b2ant.c:2795

Líneas 2795–2795; tipo `block`.

```text
/* for voice quality */
```

## 1105. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/btcoexist/halbtc8723b2ant.c:2798

Líneas 2798–2798; tipo `block`.

```text
/* sw mechanism */
```

## 1106. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/btcoexist/halbtc8723b2ant.c:2831

Líneas 2831–2831; tipo `block`.

```text
/* for HID at 11b/g mode */
```

## 1107. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/btcoexist/halbtc8723b2ant.c:2834

Líneas 2834–2834; tipo `block`.

```text
/* for HID quality & wifi performance balance at 11n mode */
```

## 1108. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/btcoexist/halbtc8723b2ant.c:2845

Líneas 2845–2845; tipo `block`.

```text
/* sw mechanism */
```

## 1109. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/btcoexist/halbtc8723b2ant.c:2852

Líneas 2852–2852; tipo `block`.

```text
/* A2DP only / PAN(EDR) only/ A2DP+PAN(HS) */
```

## 1110. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/btcoexist/halbtc8723b2ant.c:2867

Líneas 2867–2867; tipo `block`.

```text
/* define the office environment */
```

## 1111. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/btcoexist/halbtc8723b2ant.c:2868

Líneas 2868–2868; tipo `block`.

```text
/* driver don't know AP num in Linux, so we will never enter this if */
```

## 1112. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/btcoexist/halbtc8723b2ant.c:2877

Líneas 2877–2877; tipo `block`.

```text
/* sw mechanism */
```

## 1113. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/btcoexist/halbtc8723b2ant.c:2916

Líneas 2916–2916; tipo `block`.

```text
/* sw mechanism */
```

## 1114. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/btcoexist/halbtc8723b2ant.c:2963

Líneas 2963–2963; tipo `block`.

```text
/* sw mechanism */
```

## 1115. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/btcoexist/halbtc8723b2ant.c:3014

Líneas 3014–3014; tipo `block`.

```text
/* sw mechanism */
```

## 1116. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/btcoexist/halbtc8723b2ant.c:3025

Líneas 3025–3025; tipo `block`.

```text
/* PAN(HS) only */
```

## 1117. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/btcoexist/halbtc8723b2ant.c:3063

Líneas 3063–3063; tipo `block`.

```text
/* PAN(EDR) + A2DP */
```

## 1118. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/btcoexist/halbtc8723b2ant.c:3109

Líneas 3109–3109; tipo `block`.

```text
/* sw mechanism	*/
```

## 1119. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/btcoexist/halbtc8723b2ant.c:3172

Líneas 3172–3172; tipo `block`.

```text
/* sw mechanism */
```

## 1120. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/btcoexist/halbtc8723b2ant.c:3182

Líneas 3182–3182; tipo `block`.

```text
/* HID + A2DP + PAN(EDR) */
```

## 1121. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/btcoexist/halbtc8723b2ant.c:3232

Líneas 3232–3232; tipo `block`.

```text
/* sw mechanism */
```

## 1122. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/btcoexist/halbtc8723b2ant.c:3272

Líneas 3272–3272; tipo `block`.

```text
/* only 802.11N mode we have to dec bt power to 4 degree */
```

## 1123. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/btcoexist/halbtc8723b2ant.c:3274

Líneas 3274–3274; tipo `block`.

```text
/* need to check ap Number of Not */
```

## 1124. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/btcoexist/halbtc8723b2ant.c:3320

Líneas 3320–3320; tipo `block`.

```text
/* sw mechanism */
```

## 1125. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/btcoexist/halbtc8723b2ant.c:3335

Líneas 3335–3335; tipo `block`.

```text
/* sw all off */
```

## 1126. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/btcoexist/halbtc8723b2ant.c:3338

Líneas 3338–3338; tipo `block`.

```text
/* hw all off */
```

## 1127. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/btcoexist/halbtc8723b2ant.c:3390

Líneas 3390–3390; tipo `block`.

```text
/* for P2P */
```

## 1128. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/btcoexist/halbtc8723b2ant.c:3501

Líneas 3501–3501; tipo `block`.

```text
/* set wlan_act to low */
```

## 1129. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/btcoexist/halbtc8723b2ant.c:3504

Líneas 3504–3504; tipo `block`.

```text
/* WiFi standby while GNT_BT 0 -> 1 */
```

## 1130. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/btcoexist/halbtc8723b2ant.c:3509

Líneas 3509–3509; tipo `block`.

```text
/* Use H2C to set GNT_BT to HIGH */
```

## 1131. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/btcoexist/halbtc8723b2ant.c:3519

Líneas 3519–3519; tipo `block`.

```text
/* BT select s0/s1 is controlled by BT */
```

## 1132. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/btcoexist/halbtc8723b2ant.c:3522

Líneas 3522–3522; tipo `block`.

```text
/* BT select s0/s1 is controlled by WiFi */
```

## 1133. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/btcoexist/halbtc8723b2ant.c:3526

Líneas 3526–3528; tipo `block`.

```text
/*********************************************************************
 *  extern function start with ex_btc8723b2ant_
 *********************************************************************/
```

## 1134. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/btcoexist/halbtc8723b2ant.c:3539

Líneas 3539–3539; tipo `block`.

```text
/* 0x790[5:0] = 0x5 */
```

## 1135. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/btcoexist/halbtc8723b2ant.c:3545

Líneas 3545–3545; tipo `block`.

```text
/* Antenna config */
```

## 1136. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/btcoexist/halbtc8723b2ant.c:3550

Líneas 3550–3550; tipo `block`.

```text
/* PTA parameter */
```

## 1137. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/btcoexist/halbtc8723b2ant.c:3553

Líneas 3553–3553; tipo `block`.

```text
/* Enable counter statistics */
```

## 1138. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/btcoexist/halbtc8723b2ant.c:3554

Líneas 3554–3554; tipo `block`.

```text
/* 0x76e[3] = 1, WLAN_ACT controlled by PTA */
```

## 1139. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/btcoexist/halbtc8723b2ant.c:3569

Líneas 3569–3569; tipo `block`.

```text
/* enable BB, REG_SYS_FUNC_EN such that we can write 0x948 correctly */
```

## 1140. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/btcoexist/halbtc8723b2ant.c:3576

Líneas 3576–3576; tipo `block`.

```text
/* fixed at S0 for USB interface */
```

## 1141. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/btcoexist/halbtc8723b2ant.c:3579

Líneas 3579–3579; tipo `block`.

```text
/* for PCIE and SDIO interface, we check efuse 0xc3[6] */
```

## 1142. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/btcoexist/halbtc8723b2ant.c:3581

Líneas 3581–3581; tipo `block`.

```text
/* set to S1 */
```

## 1143. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/btcoexist/halbtc8723b2ant.c:3584

Líneas 3584–3584; tipo `block`.

```text
/* set to S0 */
```

## 1144. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/btcoexist/halbtc8723b2ant.c:3595

Líneas 3595–3595; tipo `block`.

```text
/* Set BIT2 by default since it's 2ant case */
```

## 1145. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/btcoexist/halbtc8723b2ant.c:3597

Líneas 3597–3608; tipo `block`.

```text
/**
	 * S0 or S1 setting and Local register setting(By this fw can get
	 * ant number, S0/S1, ... info)
	 *
	 * Local setting bit define
	 *	BIT0: "0" : no antenna inverse; "1" : antenna inverse
	 *	BIT1: "0" : internal switch; "1" : external switch
	 *	BIT2: "0" : one antenna; "1" : two antennas
	 *
	 * NOTE: here default all internal switch and 1-antenna ==> BIT1=0 and
	 * BIT2 = 0
	 */
```

## 1146. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/btcoexist/halbtc8723b2ant.c:3610

Líneas 3610–3610; tipo `block`.

```text
/* fixed at S0 for USB interface */
```

## 1147. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/btcoexist/halbtc8723b2ant.c:3611

Líneas 3611–3611; tipo `block`.

```text
/* antenna inverse */
```

## 1148. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/btcoexist/halbtc8723b2ant.c:3614

Líneas 3614–3614; tipo `block`.

```text
/* for PCIE and SDIO interface, we check efuse 0xc3[6] */
```

## 1149. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/btcoexist/halbtc8723b2ant.c:3617

Líneas 3617–3617; tipo `block`.

```text
/* set to S0 */
```

## 1150. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/btcoexist/halbtc8723b2ant.c:3618

Líneas 3618–3618; tipo `block`.

```text
/* antenna inverse */
```

## 1151. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/btcoexist/halbtc8723b2ant.c:3742

Líneas 3742–3742; tipo `block`.

```text
/* Sw mechanism	*/
```

## 1152. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/btcoexist/halbtc8723b2ant.c:3753

Líneas 3753–3753; tipo `block`.

```text
/* Fw mechanism	*/
```

## 1153. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/btcoexist/halbtc8723b2ant.c:3766

Líneas 3766–3766; tipo `block`.

```text
/* Hw setting */
```

## 1154. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/btcoexist/halbtc8723b2ant.c:3939

Líneas 3939–3939; tipo `block`.

```text
/* only 2.4G we need to inform bt the chnl mask */
```

## 1155. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/btcoexist/halbtc8723b2ant.c:4042

Líneas 4042–4044; tipo `block`.

```text
/* Here we need to resend some wifi info to BT
		 * because BT is reset and loss of the info.
		 */
```

## 1156. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/btcoexist/halbtc8723b2ant.c:4066

Líneas 4066–4066; tipo `block`.

```text
/* BT already NOT ignore Wlan active, do nothing here.*/
```

## 1157. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/btcoexist/halbtc8723b2ant.c:4075

Líneas 4075–4075; tipo `block`.

```text
/* check BIT2 first ==> check if bt is under inquiry or page scan */
```

## 1158. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/btcoexist/halbtc8723b2ant.c:4082

Líneas 4082–4082; tipo `block`.

```text
/* set link exist status */
```

## 1159. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/btcoexist/halbtc8723b2ant.c:4089

Líneas 4089–4089; tipo `block`.

```text
/* connection exists */
```

## 1160. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/btcoexist/halbtc8723b2ant.c:4125

Líneas 4125–4125; tipo `block`.

```text
/* connection exists but no busy */
```

## 1161. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/btcoexist/halbtc8723b2ant.c:4184

Líneas 4184–4189; tipo `block`.

```text
/* Driver do not leave IPS/LPS when driver is going to sleep, so
		 * BTCoexistence think wifi is still under IPS/LPS
		 *
		 * BT should clear UnderIPS/UnderLPS state to avoid mismatch
		 * state after wakeup.
		 */
```

## 1162. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/btcoexist/halbtc8723b2ant.c:4212

Líneas 4212–4214; tipo `block`.

```text
/* Antenna config to set 0x765 = 0x0 (GNT_BT control by
			 * PTA) after initial
			 */
```

## 1163. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/btcoexist/halbtc8723b2ant.c:4228

Líneas 4228–4230; tipo `block`.

```text
/* for some BT speakers that High-Priority pkts appear before
		 * playing, this will cause HID exist
		 */
```

## 1164. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/btcoexist/halbtc8723b2ant.h:1

Líneas 1–1; tipo `block`.

```text
/* SPDX-License-Identifier: GPL-2.0 */
```

## 1165. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/btcoexist/halbtc8723b2ant.h:2

Líneas 2–2; tipo `block`.

```text
/* Copyright(c) 2012  Realtek Corporation.*/
```

## 1166. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/btcoexist/halbtc8723b2ant.h:7

Líneas 7–9; tipo `block`.

```text
/************************************************************************
 * The following is for 8723B 2Ant BT Co-exist definition
 ************************************************************************/
```

## 1167. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/btcoexist/halbtc8723b2ant.h:21

Líneas 21–21; tipo `block`.

```text
/* WiFi RSSI Threshold for 2-Ant TDMA/1-Ant PS-TDMA translation */
```

## 1168. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/btcoexist/halbtc8723b2ant.h:23

Líneas 23–23; tipo `block`.

```text
/* BT RSSI Threshold for 2-Ant TDMA/1-Ant PS-TDMA translation */
```

## 1169. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/btcoexist/halbtc8723b2ant.h:59

Líneas 59–59; tipo `block`.

```text
/* fw mechanism */
```

## 1170. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/btcoexist/halbtc8723b2ant.h:77

Líneas 77–77; tipo `block`.

```text
/* sw mechanism */
```

## 1171. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/btcoexist/halbtc8723b2ant.h:101

Líneas 101–101; tipo `block`.

```text
/* algorithm related */
```

## 1172. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/btcoexist/halbtc8723b2ant.h:160

Líneas 160–162; tipo `block`.

```text
/*********************************************************************
 * The following is interface which will notify coex module.
 *********************************************************************/
```

## 1173. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/btcoexist/halbtc8821a1ant.c:1

Líneas 1–1; tipo `line`.

```text
// SPDX-License-Identifier: GPL-2.0
```

## 1174. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/btcoexist/halbtc8821a1ant.c:2

Líneas 2–2; tipo `block`.

```text
/* Copyright(c) 2012  Realtek Corporation.*/
```

## 1175. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/btcoexist/halbtc8821a1ant.c:4

Líneas 4–12; tipo `block`.

```text
/**************************************************************
 * Description:
 *
 * This file is for RTL8821A Co-exist mechanism
 *
 * History
 * 2012/11/15 Cosa first check in.
 *
 **************************************************************/
```

## 1176. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/btcoexist/halbtc8821a1ant.c:14

Líneas 14–16; tipo `block`.

```text
/**************************************************************
 * include files
 **************************************************************/
```

## 1177. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/btcoexist/halbtc8821a1ant.c:18

Líneas 18–20; tipo `block`.

```text
/**************************************************************
 * Global variables, these are static variables
 **************************************************************/
```

## 1178. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/btcoexist/halbtc8821a1ant.c:37

Líneas 37–41; tipo `block`.

```text
/**************************************************************
 * local function proto type if needed
 *
 * local function start with btc8821a1ant_
 **************************************************************/
```

## 1179. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/btcoexist/halbtc8821a1ant.c:245

Líneas 245–245; tipo `block`.

```text
/* normal mode */
```

## 1180. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/btcoexist/halbtc8821a1ant.c:283

Líneas 283–283; tipo `block`.

```text
/* normal mode */
```

## 1181. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/btcoexist/halbtc8821a1ant.c:287

Líneas 287–287; tipo `block`.

```text
/* retry limit = 8 */
```

## 1182. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/btcoexist/halbtc8821a1ant.c:305

Líneas 305–305; tipo `block`.

```text
/* normal mode */
```

## 1183. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/btcoexist/halbtc8821a1ant.c:309

Líneas 309–309; tipo `block`.

```text
/* AMPDU time = 0x38 * 32us */
```

## 1184. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/btcoexist/halbtc8821a1ant.c:326

Líneas 326–326; tipo `block`.

```text
/* normal mode */
```

## 1185. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/btcoexist/halbtc8821a1ant.c:329

Líneas 329–329; tipo `block`.

```text
/* disable cck 1/2 */
```

## 1186. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/btcoexist/halbtc8821a1ant.c:333

Líneas 333–333; tipo `block`.

```text
/* disable cck 1/2/5.5, ofdm 6/9/12/18/24, mcs 0/1/2/3/4 */
```

## 1187. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/btcoexist/halbtc8821a1ant.c:354

Líneas 354–354; tipo `block`.

```text
/* Rx Aggregation related setting */
```

## 1188. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/btcoexist/halbtc8821a1ant.c:357

Líneas 357–357; tipo `block`.

```text
/* decide BT control aggregation buf size or not */
```

## 1189. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/btcoexist/halbtc8821a1ant.c:360

Líneas 360–360; tipo `block`.

```text
/* aggregation buf size, only work when BT control Rx agg size */
```

## 1190. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/btcoexist/halbtc8821a1ant.c:362

Líneas 362–362; tipo `block`.

```text
/* real update aggregation setting */
```

## 1191. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/btcoexist/halbtc8821a1ant.c:387

Líneas 387–387; tipo `block`.

```text
/* reset counter */
```

## 1192. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/btcoexist/halbtc8821a1ant.c:398

Líneas 398–398; tipo `block`.

```text
/* trigger */
```

## 1193. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/btcoexist/halbtc8821a1ant.c:420

Líneas 420–420; tipo `block`.

```text
/* work around for HS mode */
```

## 1194. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/btcoexist/halbtc8821a1ant.c:426

Líneas 426–426; tipo `block`.

```text
/* check if Sco only */
```

## 1195. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/btcoexist/halbtc8821a1ant.c:435

Líneas 435–435; tipo `block`.

```text
/* check if A2dp only */
```

## 1196. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/btcoexist/halbtc8821a1ant.c:444

Líneas 444–444; tipo `block`.

```text
/* check if Pan only */
```

## 1197. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/btcoexist/halbtc8821a1ant.c:453

Líneas 453–453; tipo `block`.

```text
/* check if Hid only */
```

## 1198. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/btcoexist/halbtc8821a1ant.c:652

Líneas 652–652; tipo `block`.

```text
/* opCode, 0x6= Retry_Penalty*/
```

## 1199. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/btcoexist/halbtc8821a1ant.c:656

Líneas 656–656; tipo `block`.

```text
/* normal rate except MCS7/6/5, OFDM54/48/36 */
```

## 1200. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/btcoexist/halbtc8821a1ant.c:658

Líneas 658–658; tipo `block`.

```text
/* MCS7 or OFDM54 */
```

## 1201. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/btcoexist/halbtc8821a1ant.c:659

Líneas 659–659; tipo `block`.

```text
/* MCS6 or OFDM48 */
```

## 1202. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/btcoexist/halbtc8821a1ant.c:660

Líneas 660–660; tipo `block`.

```text
/* MCS5 or OFDM36 */
```

## 1203. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/btcoexist/halbtc8821a1ant.c:787

Líneas 787–787; tipo `block`.

```text
/* function enable */
```

## 1204. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/btcoexist/halbtc8821a1ant.c:927

Líneas 927–927; tipo `block`.

```text
/* 0x4c[23] = 0, 0x4c[24] = 1  Antenna control by WL/BT */
```

## 1205. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/btcoexist/halbtc8821a1ant.c:937

Líneas 937–939; tipo `block`.

```text
/* tell firmware "antenna inverse"
			 * WRONG firmware antenna control code, need fw to fix
			 */
```

## 1206. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/btcoexist/halbtc8821a1ant.c:945

Líneas 945–947; tipo `block`.

```text
/* tell firmware "no antenna inverse"
			 * WRONG firmware antenna control code, need fw to fix
			 */
```

## 1207. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/btcoexist/halbtc8821a1ant.c:954

Líneas 954–956; tipo `block`.

```text
/* 0x4c[24:23] = 00, Set Antenna control
		 * by BT_RFE_CTRL BT Vendor 0xac = 0xf002
		 */
```

## 1208. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/btcoexist/halbtc8821a1ant.c:962

Líneas 962–962; tipo `block`.

```text
/* 0x765 = 0x18 */
```

## 1209. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/btcoexist/halbtc8821a1ant.c:965

Líneas 965–965; tipo `block`.

```text
/* 0x765 = 0x0 */
```

## 1210. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/btcoexist/halbtc8821a1ant.c:969

Líneas 969–969; tipo `block`.

```text
/* ext switch setting */
```

## 1211. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/btcoexist/halbtc8821a1ant.c:1180

Líneas 1180–1185; tipo `block`.

```text
/* SoftAP only with no sta associated, BT disable, TDMA
			 * mode for power saving
			 *
			 * here softap mode screen off will cost 70-80mA for
			 * phone
			 */
```

## 1212. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/btcoexist/halbtc8821a1ant.c:1203

Líneas 1203–1203; tipo `block`.

```text
/* disable PS tdma */
```

## 1213. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/btcoexist/halbtc8821a1ant.c:1206

Líneas 1206–1206; tipo `block`.

```text
/* PTA Control */
```

## 1214. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/btcoexist/halbtc8821a1ant.c:1214

Líneas 1214–1214; tipo `block`.

```text
/* Software control, Antenna at BT side */
```

## 1215. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/btcoexist/halbtc8821a1ant.c:1221

Líneas 1221–1221; tipo `block`.

```text
/* Software control, Antenna at WiFi side */
```

## 1216. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/btcoexist/halbtc8821a1ant.c:1228

Líneas 1228–1228; tipo `block`.

```text
/* under 5G */
```

## 1217. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/btcoexist/halbtc8821a1ant.c:1240

Líneas 1240–1240; tipo `block`.

```text
/* update pre state */
```

## 1218. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/btcoexist/halbtc8821a1ant.c:1317

Líneas 1317–1317; tipo `block`.

```text
/* already under LPS state */
```

## 1219. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/btcoexist/halbtc8821a1ant.c:1319

Líneas 1319–1319; tipo `block`.

```text
/* keep state under LPS, do nothing */
```

## 1220. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/btcoexist/halbtc8821a1ant.c:1321

Líneas 1321–1321; tipo `block`.

```text
/* will leave LPS state, turn off psTdma first */
```

## 1221. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/btcoexist/halbtc8821a1ant.c:1325

Líneas 1325–1325; tipo `block`.

```text
/* NO PS state*/
```

## 1222. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/btcoexist/halbtc8821a1ant.c:1327

Líneas 1327–1327; tipo `block`.

```text
/* will enter LPS state, turn off psTdma first */
```

## 1223. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/btcoexist/halbtc8821a1ant.c:1330

Líneas 1330–1330; tipo `block`.

```text
/* keep state under NO PS state, do nothing */
```

## 1224. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/btcoexist/halbtc8821a1ant.c:1342

Líneas 1342–1342; tipo `block`.

```text
/* recover to original 32k low power setting */
```

## 1225. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/btcoexist/halbtc8821a1ant.c:1353

Líneas 1353–1353; tipo `block`.

```text
/* when coex force to enter LPS, do not enter 32k low power */
```

## 1226. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/btcoexist/halbtc8821a1ant.c:1357

Líneas 1357–1357; tipo `block`.

```text
/* power save must executed before psTdma */
```

## 1227. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/btcoexist/halbtc8821a1ant.c:1384

Líneas 1384–1388; tipo `block`.

```text
/***********************************************
 *
 *	Software Coex Mechanism start
 *
 ***********************************************/
```

## 1228. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/btcoexist/halbtc8821a1ant.c:1390

Líneas 1390–1390; tipo `block`.

```text
/* SCO only or SCO+PAN(HS) */
```

## 1229. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/btcoexist/halbtc8821a1ant.c:1401

Líneas 1401–1401; tipo `block`.

```text
/* A2DP only / PAN(EDR) only/ A2DP+PAN(HS) */
```

## 1230. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/btcoexist/halbtc8821a1ant.c:1417

Líneas 1417–1417; tipo `block`.

```text
/* PAN(HS) only */
```

## 1231. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/btcoexist/halbtc8821a1ant.c:1423

Líneas 1423–1423; tipo `block`.

```text
/* PAN(EDR)+A2DP */
```

## 1232. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/btcoexist/halbtc8821a1ant.c:1434

Líneas 1434–1434; tipo `block`.

```text
/* HID+A2DP+PAN(EDR) */
```

## 1233. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/btcoexist/halbtc8821a1ant.c:1445

Líneas 1445–1449; tipo `block`.

```text
/***********************************************
 *
 *	Non-Software Coex Mechanism start
 *
 ***********************************************/
```

## 1234. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/btcoexist/halbtc8821a1ant.c:1456

Líneas 1456–1456; tipo `block`.

```text
/* tdma and coex table */
```

## 1235. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/btcoexist/halbtc8821a1ant.c:1492

Líneas 1492–1492; tipo `block`.

```text
/* tdma and coex table */
```

## 1236. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/btcoexist/halbtc8821a1ant.c:1533

Líneas 1533–1533; tipo `block`.

```text
/* SCO/HID-only busy */
```

## 1237. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/btcoexist/halbtc8821a1ant.c:1539

Líneas 1539–1539; tipo `block`.

```text
/* A2DP+HID busy */
```

## 1238. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/btcoexist/halbtc8821a1ant.c:1562

Líneas 1562–1562; tipo `block`.

```text
/* tdma and coex table */
```

## 1239. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/btcoexist/halbtc8821a1ant.c:1578

Líneas 1578–1578; tipo `block`.

```text
/* HID */
```

## 1240. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/btcoexist/halbtc8821a1ant.c:1584

Líneas 1584–1584; tipo `block`.

```text
/* A2DP */
```

## 1241. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/btcoexist/halbtc8821a1ant.c:1596

Líneas 1596–1596; tipo `block`.

```text
/* for low BT RSSI */
```

## 1242. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/btcoexist/halbtc8821a1ant.c:1603

Líneas 1603–1603; tipo `block`.

```text
/* HID+A2DP */
```

## 1243. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/btcoexist/halbtc8821a1ant.c:1610

Líneas 1610–1610; tipo `block`.

```text
/*for low BT RSSI*/
```

## 1244. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/btcoexist/halbtc8821a1ant.c:1619

Líneas 1619–1619; tipo `block`.

```text
/* PAN(OPP, FTP), HID+PAN(OPP, FTP) */
```

## 1245. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/btcoexist/halbtc8821a1ant.c:1626

Líneas 1626–1626; tipo `block`.

```text
/* A2DP+PAN(OPP, FTP), HID+A2DP+PAN(OPP, FTP) */
```

## 1246. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/btcoexist/halbtc8821a1ant.c:1640

Líneas 1640–1640; tipo `block`.

```text
/* power save state */
```

## 1247. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/btcoexist/halbtc8821a1ant.c:1643

Líneas 1643–1643; tipo `block`.

```text
/* tdma and coex table */
```

## 1248. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/btcoexist/halbtc8821a1ant.c:1654

Líneas 1654–1654; tipo `block`.

```text
/* tdma and coex table */
```

## 1249. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/btcoexist/halbtc8821a1ant.c:1686

Líneas 1686–1686; tipo `block`.

```text
/* power save state */
```

## 1250. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/btcoexist/halbtc8821a1ant.c:1690

Líneas 1690–1690; tipo `block`.

```text
/* tdma and coex table */
```

## 1251. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/btcoexist/halbtc8821a1ant.c:1719

Líneas 1719–1719; tipo `block`.

```text
/* tdma and coex table */
```

## 1252. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/btcoexist/halbtc8821a1ant.c:1772

Líneas 1772–1772; tipo `block`.

```text
/* power save state*/
```

## 1253. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/btcoexist/halbtc8821a1ant.c:1780

Líneas 1780–1780; tipo `block`.

```text
/* A2DP */
```

## 1254. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/btcoexist/halbtc8821a1ant.c:1792

Líneas 1792–1792; tipo `block`.

```text
/* tdma and coex table */
```

## 1255. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/btcoexist/halbtc8821a1ant.c:1889

Líneas 1889–1889; tipo `block`.

```text
/*btc8821a1ant_coex_all_off(btcoexist);*/
```

## 1256. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/btcoexist/halbtc8821a1ant.c:2021

Líneas 2021–2021; tipo `block`.

```text
/* wifi LPS/Busy */
```

## 1257. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/btcoexist/halbtc8821a1ant.c:2028

Líneas 2028–2030; tipo `block`.

```text
/* force to reset coex mechanism
	 * sw all off
	 */
```

## 1258. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/btcoexist/halbtc8821a1ant.c:2060

Líneas 2060–2060; tipo `block`.

```text
/* 0x790[5:0] = 0x5 */
```

## 1259. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/btcoexist/halbtc8821a1ant.c:2068

Líneas 2068–2068; tipo `block`.

```text
/* Antenna config */
```

## 1260. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/btcoexist/halbtc8821a1ant.c:2075

Líneas 2075–2075; tipo `block`.

```text
/* PTA parameter */
```

## 1261. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/btcoexist/halbtc8821a1ant.c:2078

Líneas 2078–2080; tipo `block`.

```text
/* Enable counter statistics
	 * 0x76e[3] =1, WLAN_Act control by PTA
	 */
```

## 1262. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/btcoexist/halbtc8821a1ant.c:2086

Líneas 2086–2088; tipo `block`.

```text
/**************************************************************
 * extern function start with ex_btc8821a1ant_
 **************************************************************/
```

## 1263. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/btcoexist/halbtc8821a1ant.c:2238

Líneas 2238–2238; tipo `block`.

```text
/* Sw mechanism*/
```

## 1264. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/btcoexist/halbtc8821a1ant.c:2253

Líneas 2253–2253; tipo `block`.

```text
/* Fw mechanism */
```

## 1265. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/btcoexist/halbtc8821a1ant.c:2272

Líneas 2272–2272; tipo `block`.

```text
/* Hw setting */
```

## 1266. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/btcoexist/halbtc8821a1ant.c:2368

Líneas 2368–2368; tipo `block`.

```text
/* set PTA control */
```

## 1267. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/btcoexist/halbtc8821a1ant.c:2426

Líneas 2426–2426; tipo `block`.

```text
/* Force antenna setup for no scan result issue */
```

## 1268. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/btcoexist/halbtc8821a1ant.c:2467

Líneas 2467–2467; tipo `block`.

```text
/* non-connected scan */
```

## 1269. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/btcoexist/halbtc8821a1ant.c:2470

Líneas 2470–2470; tipo `block`.

```text
/* wifi is connected */
```

## 1270. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/btcoexist/halbtc8821a1ant.c:2477

Líneas 2477–2477; tipo `block`.

```text
/* non-connected scan */
```

## 1271. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/btcoexist/halbtc8821a1ant.c:2549

Líneas 2549–2549; tipo `block`.

```text
/* non-connected scan */
```

## 1272. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/btcoexist/halbtc8821a1ant.c:2586

Líneas 2586–2586; tipo `block`.

```text
/* only 2.4G we need to inform bt the chnl mask */
```

## 1273. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/btcoexist/halbtc8821a1ant.c:2685

Líneas 2685–2687; tipo `block`.

```text
/* if APR PKT > 10 after connect, do not go to
				 * btc8821a1ant_act_wifi_conn_sp_pkt
				 */
```

## 1274. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/btcoexist/halbtc8821a1ant.c:2735

Líneas 2735–2735; tipo `block`.

```text
/* [3:0] */
```

## 1275. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/btcoexist/halbtc8821a1ant.c:2749

Líneas 2749–2751; tipo `block`.

```text
/* BT into is responded by BT FW and BT RF REG 0x3C !=
			 * 0x15 => Need to switch BT TRx Mask
			 */
```

## 1276. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/btcoexist/halbtc8821a1ant.c:2758

Líneas 2758–2760; tipo `block`.

```text
/* Here we need to resend some wifi info to BT
		 * because bt is reset and lost the info
		 */
```

## 1277. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/btcoexist/halbtc8821a1ant.c:2787

Líneas 2787–2787; tipo `block`.

```text
/* check BIT2 first ==> check if bt is under inquiry or page scan */
```

## 1278. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/btcoexist/halbtc8821a1ant.c:2793

Líneas 2793–2793; tipo `block`.

```text
/* set link exist status */
```

## 1279. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/btcoexist/halbtc8821a1ant.c:2801

Líneas 2801–2801; tipo `block`.

```text
/* connection exists */
```

## 1280. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/btcoexist/halbtc8821a1ant.c:2823

Líneas 2823–2825; tipo `block`.

```text
/* mask profile bit for connect-ilde identification
	 * (for CSR case: A2DP idle --> 0x41)
	 */
```

## 1281. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/btcoexist/halbtc8821a1ant.c:2833

Líneas 2833–2833; tipo `block`.

```text
/* connection exists but no busy */
```

## 1282. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/btcoexist/halbtc8821a1ant.c:2912

Líneas 2912–2914; tipo `block`.

```text
/* BT should clear UnderIPS/UnderLPS state to avoid mismatch
		 * state after wakeup.
		 */
```

## 1283. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/btcoexist/halbtc8821a1ant.h:1

Líneas 1–1; tipo `block`.

```text
/* SPDX-License-Identifier: GPL-2.0 */
```

## 1284. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/btcoexist/halbtc8821a1ant.h:2

Líneas 2–2; tipo `block`.

```text
/* Copyright(c) 2012  Realtek Corporation.*/
```

## 1285. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/btcoexist/halbtc8821a1ant.h:4

Líneas 4–7; tipo `block`.

```text
/*===========================================
 * The following is for 8821A 1ANT BT Co-exist definition
 *===========================================
 */
```

## 1286. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/btcoexist/halbtc8821a1ant.h:65

Líneas 65–65; tipo `block`.

```text
/* fw mechanism */
```

## 1287. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/btcoexist/halbtc8821a1ant.h:82

Líneas 82–82; tipo `block`.

```text
/* sw mechanism */
```

## 1288. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/btcoexist/halbtc8821a1ant.h:93

Líneas 93–93; tipo `block`.

```text
/* Auto Rate Fallback Retry cnt */
```

## 1289. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/btcoexist/halbtc8821a1ant.h:95

Líneas 95–95; tipo `block`.

```text
/* Auto Rate Fallback Retry cnt */
```

## 1290. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/btcoexist/halbtc8821a1ant.h:100

Líneas 100–100; tipo `block`.

```text
/* algorithm related */
```

## 1291. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/btcoexist/halbtc8821a1ant.h:147

Líneas 147–150; tipo `block`.

```text
/*===========================================
 * The following is interface which will notify coex module.
 *===========================================
 */
```

## 1292. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/btcoexist/halbtc8821a2ant.c:1

Líneas 1–1; tipo `line`.

```text
// SPDX-License-Identifier: GPL-2.0
```

## 1293. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/btcoexist/halbtc8821a2ant.c:2

Líneas 2–2; tipo `block`.

```text
/* Copyright(c) 2012  Realtek Corporation.*/
```

## 1294. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/btcoexist/halbtc8821a2ant.c:4

Líneas 4–13; tipo `block`.

```text
/************************************************************
 * Description:
 *
 * This file is for RTL8821A Co-exist mechanism
 *
 * History
 * 2012/08/22 Cosa first check in.
 * 2012/11/14 Cosa Revise for 8821A 2Ant out sourcing.
 *
 ************************************************************/
```

## 1295. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/btcoexist/halbtc8821a2ant.c:15

Líneas 15–17; tipo `block`.

```text
/************************************************************
 * include files
 ************************************************************/
```

## 1296. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/btcoexist/halbtc8821a2ant.c:19

Líneas 19–21; tipo `block`.

```text
/************************************************************
 * Global variables, these are static variables
 ************************************************************/
```

## 1297. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/btcoexist/halbtc8821a2ant.c:36

Líneas 36–40; tipo `block`.

```text
/************************************************************
 * local function proto type if needed
 *
 * local function start with btc8821a2ant_
 ************************************************************/
```

## 1298. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/btcoexist/halbtc8821a2ant.c:234

Líneas 234–234; tipo `block`.

```text
/* Rx Aggregation related setting */
```

## 1299. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/btcoexist/halbtc8821a2ant.c:237

Líneas 237–237; tipo `block`.

```text
/* decide BT control aggregation buf size or not */
```

## 1300. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/btcoexist/halbtc8821a2ant.c:240

Líneas 240–240; tipo `block`.

```text
/* aggregation buf size, works when BT control Rx aggregation size */
```

## 1301. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/btcoexist/halbtc8821a2ant.c:242

Líneas 242–242; tipo `block`.

```text
/* real update aggregation setting */
```

## 1302. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/btcoexist/halbtc8821a2ant.c:283

Líneas 283–283; tipo `block`.

```text
/* reset counter */
```

## 1303. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/btcoexist/halbtc8821a2ant.c:319

Líneas 319–319; tipo `block`.

```text
/* reset counter */
```

## 1304. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/btcoexist/halbtc8821a2ant.c:331

Líneas 331–331; tipo `block`.

```text
/* trigger */
```

## 1305. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/btcoexist/halbtc8821a2ant.c:394

Líneas 394–394; tipo `block`.

```text
/* work around for HS mode. */
```

## 1306. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/btcoexist/halbtc8821a2ant.c:400

Líneas 400–400; tipo `block`.

```text
/* check if Sco only */
```

## 1307. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/btcoexist/halbtc8821a2ant.c:407

Líneas 407–407; tipo `block`.

```text
/* check if A2dp only */
```

## 1308. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/btcoexist/halbtc8821a2ant.c:414

Líneas 414–414; tipo `block`.

```text
/* check if Pan only */
```

## 1309. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/btcoexist/halbtc8821a2ant.c:421

Líneas 421–421; tipo `block`.

```text
/* check if Hid only */
```

## 1310. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/btcoexist/halbtc8821a2ant.c:623

Líneas 623–625; tipo `block`.

```text
/* There are several type of dacswing
	 * 0x18/ 0x10/ 0xc/ 0x8/ 0x4/ 0x6
	 */
```

## 1311. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/btcoexist/halbtc8821a2ant.c:708

Líneas 708–708; tipo `block`.

```text
/* opCode, 0x6 = Retry_Penalty */
```

## 1312. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/btcoexist/halbtc8821a2ant.c:712

Líneas 712–712; tipo `block`.

```text
/* normal rate except MCS7/6/5, OFDM54/48/36 */
```

## 1313. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/btcoexist/halbtc8821a2ant.c:714

Líneas 714–714; tipo `block`.

```text
/* MCS7 or OFDM54 */
```

## 1314. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/btcoexist/halbtc8821a2ant.c:716

Líneas 716–716; tipo `block`.

```text
/* MCS6 or OFDM48 */
```

## 1315. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/btcoexist/halbtc8821a2ant.c:718

Líneas 718–718; tipo `block`.

```text
/* MCS5 or OFDM36 */
```

## 1316. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/btcoexist/halbtc8821a2ant.c:968

Líneas 968–968; tipo `block`.

```text
/* function enable */
```

## 1317. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/btcoexist/halbtc8821a2ant.c:1083

Líneas 1083–1083; tipo `block`.

```text
/*  0x4c[23] = 0, 0x4c[24] = 1  Antenna control by WL/BT */
```

## 1318. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/btcoexist/halbtc8821a2ant.c:1092

Líneas 1092–1094; tipo `block`.

```text
/* tell firmware "antenna inverse"  ==> WRONG firmware
			 * antenna control code ==>need fw to fix
			 */
```

## 1319. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/btcoexist/halbtc8821a2ant.c:1100

Líneas 1100–1102; tipo `block`.

```text
/* tell firmware "no antenna inverse" ==> WRONG firmware
			 * antenna control code ==>need fw to fix
			 */
```

## 1320. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/btcoexist/halbtc8821a2ant.c:1110

Líneas 1110–1110; tipo `block`.

```text
/* ext switch setting */
```

## 1321. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/btcoexist/halbtc8821a2ant.c:1136

Líneas 1136–1136; tipo `block`.

```text
/* for WiFi RSSI low or BT RSSI low */
```

## 1322. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/btcoexist/halbtc8821a2ant.c:1325

Líneas 1325–1325; tipo `block`.

```text
/* disable PS tdma */
```

## 1323. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/btcoexist/halbtc8821a2ant.c:1342

Líneas 1342–1342; tipo `block`.

```text
/* update pre state */
```

## 1324. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/btcoexist/halbtc8821a2ant.c:1356

Líneas 1356–1356; tipo `block`.

```text
/* already under LPS state */
```

## 1325. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/btcoexist/halbtc8821a2ant.c:1358

Líneas 1358–1358; tipo `block`.

```text
/* keep state under LPS, do nothing */
```

## 1326. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/btcoexist/halbtc8821a2ant.c:1360

Líneas 1360–1360; tipo `block`.

```text
/* will leave LPS state, turn off psTdma first */
```

## 1327. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/btcoexist/halbtc8821a2ant.c:1364

Líneas 1364–1364; tipo `block`.

```text
/* NO PS state */
```

## 1328. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/btcoexist/halbtc8821a2ant.c:1366

Líneas 1366–1366; tipo `block`.

```text
/* will enter LPS state, turn off psTdma first */
```

## 1329. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/btcoexist/halbtc8821a2ant.c:1369

Líneas 1369–1369; tipo `block`.

```text
/* keep state under NO PS state, do nothing */
```

## 1330. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/btcoexist/halbtc8821a2ant.c:1381

Líneas 1381–1381; tipo `block`.

```text
/* recover to original 32k low power setting */
```

## 1331. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/btcoexist/halbtc8821a2ant.c:1393

Líneas 1393–1393; tipo `block`.

```text
/* when coex force to enter LPS, do not enter 32k low power */
```

## 1332. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/btcoexist/halbtc8821a2ant.c:1397

Líneas 1397–1397; tipo `block`.

```text
/* power save must executed before psTdma */
```

## 1333. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/btcoexist/halbtc8821a2ant.c:1414

Líneas 1414–1414; tipo `block`.

```text
/* fw all off */
```

## 1334. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/btcoexist/halbtc8821a2ant.c:1420

Líneas 1420–1420; tipo `block`.

```text
/* sw all off */
```

## 1335. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/btcoexist/halbtc8821a2ant.c:1424

Líneas 1424–1424; tipo `block`.

```text
/* hw all off */
```

## 1336. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/btcoexist/halbtc8821a2ant.c:1436

Líneas 1436–1436; tipo `block`.

```text
/* force to reset coex mechanism */
```

## 1337. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/btcoexist/halbtc8821a2ant.c:1531

Líneas 1531–1531; tipo `block`.

```text
/* define the office environment */
```

## 1338. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/btcoexist/halbtc8821a2ant.c:1540

Líneas 1540–1540; tipo `block`.

```text
/* sw all off */
```

## 1339. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/btcoexist/halbtc8821a2ant.c:1559

Líneas 1559–1559; tipo `block`.

```text
/* sw all off */
```

## 1340. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/btcoexist/halbtc8821a2ant.c:1703

Líneas 1703–1706; tipo `block`.

```text
/* 0 : no change
	  * +1: increase WiFi duration
	  * -1: decrease WiFi duration
	  */
```

## 1341. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/btcoexist/halbtc8821a2ant.c:1802

Líneas 1802–1802; tipo `block`.

```text
/* accquire the BT TRx retry count from BT_Info byte2 */
```

## 1342. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/btcoexist/halbtc8821a2ant.c:1813

Líneas 1813–1813; tipo `block`.

```text
/* no retry in the last 2-second duration */
```

## 1343. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/btcoexist/halbtc8821a2ant.c:1821

Líneas 1821–1823; tipo `block`.

```text
/* if (retry count == 0) for 2*n seconds,
				 * make WiFi duration wider
				 */
```

## 1344. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/btcoexist/halbtc8821a2ant.c:1833

Líneas 1833–1833; tipo `block`.

```text
/* <=3 retry in the last 2-second duration */
```

## 1345. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/btcoexist/halbtc8821a2ant.c:1841

Líneas 1841–1843; tipo `block`.

```text
/* if retry count < 3 for 2*2 seconds,
				 * shrink wifi duration
				 */
```

## 1346. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/btcoexist/halbtc8821a2ant.c:1845

Líneas 1845–1845; tipo `block`.

```text
/* avoid bounce in two levels */
```

## 1347. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/btcoexist/halbtc8821a2ant.c:1848

Líneas 1848–1850; tipo `block`.

```text
/* m max value is 20, max time is 120 second,
				 * recheck if adjust WiFi duration.
				 */
```

## 1348. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/btcoexist/halbtc8821a2ant.c:1863

Líneas 1863–1865; tipo `block`.

```text
/* retry count > 3, if retry count > 3 happens once,
			 * shrink WiFi duration
			 */
```

## 1349. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/btcoexist/halbtc8821a2ant.c:1867

Líneas 1867–1867; tipo `block`.

```text
/* avoid bounce in two levels */
```

## 1350. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/btcoexist/halbtc8821a2ant.c:1870

Líneas 1870–1872; tipo `block`.

```text
/* m max value is 20, max time is 120 second,
			 * recheck if adjust WiFi duration.
			 */
```

## 1351. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/btcoexist/halbtc8821a2ant.c:2587

Líneas 2587–2590; tipo `block`.

```text
/* if current PsTdma not match with the recorded one
	 * (when scan, dhcp...), then we have to adjust it back to
	 * the previous recorded one.
	 */
```

## 1352. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/btcoexist/halbtc8821a2ant.c:2612

Líneas 2612–2612; tipo `block`.

```text
/* SCO only or SCO+PAN(HS)*/
```

## 1353. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/btcoexist/halbtc8821a2ant.c:2635

Líneas 2635–2635; tipo `block`.

```text
/* for SCO quality at 11b/g mode */
```

## 1354. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/btcoexist/halbtc8821a2ant.c:2638

Líneas 2638–2638; tipo `block`.

```text
/* for SCO quality & wifi performance balance at 11n mode */
```

## 1355. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/btcoexist/halbtc8821a2ant.c:2653

Líneas 2653–2653; tipo `block`.

```text
/* for voice quality */
```

## 1356. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/btcoexist/halbtc8821a2ant.c:2656

Líneas 2656–2656; tipo `block`.

```text
/* sw mechanism */
```

## 1357. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/btcoexist/halbtc8821a2ant.c:2708

Líneas 2708–2708; tipo `block`.

```text
/* for HID at 11b/g mode */
```

## 1358. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/btcoexist/halbtc8821a2ant.c:2711

Líneas 2711–2711; tipo `block`.

```text
/* for HID quality & wifi performance balance at 11n mode */
```

## 1359. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/btcoexist/halbtc8821a2ant.c:2719

Líneas 2719–2719; tipo `block`.

```text
/* sw mechanism */
```

## 1360. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/btcoexist/halbtc8821a2ant.c:2733

Líneas 2733–2733; tipo `block`.

```text
/* sw mechanism */
```

## 1361. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/btcoexist/halbtc8821a2ant.c:2749

Líneas 2749–2749; tipo `block`.

```text
/* A2DP only / PAN(EDR) only/ A2DP+PAN(HS) */
```

## 1362. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/btcoexist/halbtc8821a2ant.c:2780

Líneas 2780–2780; tipo `block`.

```text
/* sw mechanism */
```

## 1363. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/btcoexist/halbtc8821a2ant.c:2823

Líneas 2823–2823; tipo `block`.

```text
/* sw mechanism */
```

## 1364. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/btcoexist/halbtc8821a2ant.c:2887

Líneas 2887–2887; tipo `block`.

```text
/* sw mechanism */
```

## 1365. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/btcoexist/halbtc8821a2ant.c:2956

Líneas 2956–2956; tipo `block`.

```text
/* sw mechanism */
```

## 1366. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/btcoexist/halbtc8821a2ant.c:2987

Líneas 2987–2987; tipo `block`.

```text
/* PAN(HS) only */
```

## 1367. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/btcoexist/halbtc8821a2ant.c:3043

Líneas 3043–3043; tipo `block`.

```text
/* PAN(EDR)+A2DP */
```

## 1368. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/btcoexist/halbtc8821a2ant.c:3090

Líneas 3090–3090; tipo `block`.

```text
/* sw mechanism	 */
```

## 1369. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/btcoexist/halbtc8821a2ant.c:3139

Líneas 3139–3139; tipo `block`.

```text
/* for HID at 11b/g mode */
```

## 1370. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/btcoexist/halbtc8821a2ant.c:3143

Líneas 3143–3143; tipo `block`.

```text
/* for HID quality & wifi performance balance at 11n mode */
```

## 1371. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/btcoexist/halbtc8821a2ant.c:3150

Líneas 3150–3150; tipo `block`.

```text
/* fw mechanism */
```

## 1372. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/btcoexist/halbtc8821a2ant.c:3159

Líneas 3159–3159; tipo `block`.

```text
/* sw mechanism */
```

## 1373. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/btcoexist/halbtc8821a2ant.c:3174

Líneas 3174–3174; tipo `block`.

```text
/* fw mechanism */
```

## 1374. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/btcoexist/halbtc8821a2ant.c:3182

Líneas 3182–3182; tipo `block`.

```text
/* sw mechanism */
```

## 1375. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/btcoexist/halbtc8821a2ant.c:3198

Líneas 3198–3198; tipo `block`.

```text
/* HID+A2DP+PAN(EDR) */
```

## 1376. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/btcoexist/halbtc8821a2ant.c:3244

Líneas 3244–3244; tipo `block`.

```text
/* sw mechanism */
```

## 1377. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/btcoexist/halbtc8821a2ant.c:3300

Líneas 3300–3300; tipo `block`.

```text
/* only 802.11N mode we have to dec bt power to 4 degree */
```

## 1378. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/btcoexist/halbtc8821a2ant.c:3334

Líneas 3334–3334; tipo `block`.

```text
/* sw mechanism */
```

## 1379. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/btcoexist/halbtc8821a2ant.c:3369

Líneas 3369–3369; tipo `block`.

```text
/* sw all off */
```

## 1380. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/btcoexist/halbtc8821a2ant.c:3373

Líneas 3373–3373; tipo `block`.

```text
/* hw all off */
```

## 1381. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/btcoexist/halbtc8821a2ant.c:3432

Líneas 3432–3432; tipo `block`.

```text
/* for P2P */
```

## 1382. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/btcoexist/halbtc8821a2ant.c:3541

Líneas 3541–3541; tipo `block`.

```text
/* set wlan_act to low */
```

## 1383. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/btcoexist/halbtc8821a2ant.c:3544

Líneas 3544–3544; tipo `block`.

```text
/* WiFi goto standby while GNT_BT 0-->1 */
```

## 1384. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/btcoexist/halbtc8821a2ant.c:3548

Líneas 3548–3548; tipo `block`.

```text
/* Use H2C to set GNT_BT to HIGH */
```

## 1385. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/btcoexist/halbtc8821a2ant.c:3556

Líneas 3556–3558; tipo `block`.

```text
/**************************************************************
 * extern function start with ex_btc8821a2ant_
 **************************************************************/
```

## 1386. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/btcoexist/halbtc8821a2ant.c:3567

Líneas 3567–3567; tipo `block`.

```text
/* backup rf 0x1e value */
```

## 1387. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/btcoexist/halbtc8821a2ant.c:3571

Líneas 3571–3571; tipo `block`.

```text
/* 0x790[5:0] = 0x5 */
```

## 1388. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/btcoexist/halbtc8821a2ant.c:3577

Líneas 3577–3577; tipo `block`.

```text
/* Antenna config */
```

## 1389. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/btcoexist/halbtc8821a2ant.c:3581

Líneas 3581–3581; tipo `block`.

```text
/* PTA parameter */
```

## 1390. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/btcoexist/halbtc8821a2ant.c:3584

Líneas 3584–3584; tipo `block`.

```text
/* Enable counter statistics */
```

## 1391. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/btcoexist/halbtc8821a2ant.c:3585

Líneas 3585–3585; tipo `block`.

```text
/* 0x76e[3] = 1, WLAN_Act control by PTA */
```

## 1392. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/btcoexist/halbtc8821a2ant.c:3594

Líneas 3594–3594; tipo `block`.

```text
/* Set BIT2 by default since it's 2ant case */
```

## 1393. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/btcoexist/halbtc8821a2ant.c:3596

Líneas 3596–3606; tipo `block`.

```text
/**
	 * S0 or S1 setting and Local register setting(By the setting fw can get
	 * ant number, S0/S1, ... info)
	 *
	 * Local setting bit define
	 *	BIT0: "0" for no antenna inverse; "1" for antenna inverse
	 *	BIT1: "0" for internal switch; "1" for external switch
	 *	BIT2: "0" for one antenna; "1" for two antenna
	 * NOTE: here default all internal switch and 1-antenna ==> BIT1=0 and
	 * BIT2=0
	 */
```

## 1394. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/btcoexist/halbtc8821a2ant.c:3608

Líneas 3608–3608; tipo `block`.

```text
/* fixed at S0 for USB interface */
```

## 1395. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/btcoexist/halbtc8821a2ant.c:3609

Líneas 3609–3609; tipo `block`.

```text
/* antenna inverse */
```

## 1396. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/btcoexist/halbtc8821a2ant.c:3612

Líneas 3612–3612; tipo `block`.

```text
/* for PCIE and SDIO interface, we check efuse 0xc3[6] */
```

## 1397. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/btcoexist/halbtc8821a2ant.c:3615

Líneas 3615–3615; tipo `block`.

```text
/* set to S0 */
```

## 1398. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/btcoexist/halbtc8821a2ant.c:3616

Líneas 3616–3616; tipo `block`.

```text
/* antenna inverse */
```

## 1399. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/btcoexist/halbtc8821a2ant.c:3743

Líneas 3743–3743; tipo `block`.

```text
/* Sw mechanism*/
```

## 1400. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/btcoexist/halbtc8821a2ant.c:3751

Líneas 3751–3751; tipo `block`.

```text
/* Fw mechanism*/
```

## 1401. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/btcoexist/halbtc8821a2ant.c:3766

Líneas 3766–3766; tipo `block`.

```text
/* Hw setting*/
```

## 1402. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/btcoexist/halbtc8821a2ant.c:3829

Líneas 3829–3829; tipo `block`.

```text
/* Tx mgnt queue hang or not, 0x41b should = 0xf, ex: 0xd ==>hang*/
```

## 1403. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/btcoexist/halbtc8821a2ant.c:3917

Líneas 3917–3917; tipo `block`.

```text
/* only 2.4G we need to inform bt the chnl mask */
```

## 1404. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/btcoexist/halbtc8821a2ant.c:4002

Líneas 4002–4002; tipo `block`.

```text
/* [3:0] */
```

## 1405. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/btcoexist/halbtc8821a2ant.c:4016

Líneas 4016–4018; tipo `block`.

```text
/* BT into is responded by BT FW and BT RF REG 0x3C !=
			 * 0x01 => Need to switch BT TRx Mask
			 */
```

## 1406. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/btcoexist/halbtc8821a2ant.c:4025

Líneas 4025–4027; tipo `block`.

```text
/* Here we need to resend some wifi info to BT
		 * because bt is reset and loss of the info
		 */
```

## 1407. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/btcoexist/halbtc8821a2ant.c:4061

Líneas 4061–4063; tipo `block`.

```text
/* BT already NOT ignore Wlan active, do nothing
				 * here.
				 */
```

## 1408. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/btcoexist/halbtc8821a2ant.c:4075

Líneas 4075–4075; tipo `block`.

```text
/* check BIT2 first ==> check if bt is under inquiry or page scan*/
```

## 1409. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/btcoexist/halbtc8821a2ant.c:4081

Líneas 4081–4081; tipo `block`.

```text
/* set link exist status */
```

## 1410. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/btcoexist/halbtc8821a2ant.c:4088

Líneas 4088–4088; tipo `block`.

```text
/* connection exists */
```

## 1411. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/btcoexist/halbtc8821a2ant.c:4123

Líneas 4123–4123; tipo `block`.

```text
/* connection exists but no busy */
```

## 1412. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/btcoexist/halbtc8821a2ant.c:4200

Líneas 4200–4202; tipo `block`.

```text
/* Antenna config to set 0x765 = 0x0 (GNT_BT control by
			 * PTA) after initial
			 */
```

## 1413. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/btcoexist/halbtc8821a2ant.h:1

Líneas 1–1; tipo `block`.

```text
/* SPDX-License-Identifier: GPL-2.0 */
```

## 1414. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/btcoexist/halbtc8821a2ant.h:2

Líneas 2–2; tipo `block`.

```text
/* Copyright(c) 2012  Realtek Corporation.*/
```

## 1415. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/btcoexist/halbtc8821a2ant.h:4

Líneas 4–7; tipo `block`.

```text
/*===========================================
 * The following is for 8821A 2Ant BT Co-exist definition
 *===========================================
*/
```

## 1416. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/btcoexist/halbtc8821a2ant.h:19

Líneas 19–19; tipo `block`.

```text
/* WiFi RSSI Threshold for 2-Ant TDMA/1-Ant PS-TDMA translation */
```

## 1417. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/btcoexist/halbtc8821a2ant.h:21

Líneas 21–21; tipo `block`.

```text
/* BT RSSI Threshold for 2-Ant TDMA/1-Ant PS-TDMA translation */
```

## 1418. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/btcoexist/halbtc8821a2ant.h:57

Líneas 57–57; tipo `block`.

```text
/* fw mechanism */
```

## 1419. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/btcoexist/halbtc8821a2ant.h:75

Líneas 75–75; tipo `block`.

```text
/* sw mechanism */
```

## 1420. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/btcoexist/halbtc8821a2ant.h:99

Líneas 99–99; tipo `block`.

```text
/* algorithm related */
```

## 1421. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/btcoexist/halbtc8821a2ant.h:149

Líneas 149–152; tipo `block`.

```text
/*===========================================
 *	The following is interface which will notify coex module.
 *===========================================
 */
```

## 1422. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/btcoexist/halbtc8822bwifionly.c:1

Líneas 1–1; tipo `line`.

```text
// SPDX-License-Identifier: GPL-2.0
```

## 1423. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/btcoexist/halbtc8822bwifionly.c:2

Líneas 2–2; tipo `block`.

```text
/* Copyright(c) 2016-2017  Realtek Corporation.*/
```

## 1424. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/btcoexist/halbtc8822bwifionly.c:8

Líneas 8–8; tipo `block`.

```text
/*BB control*/
```

## 1425. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/btcoexist/halbtc8822bwifionly.c:10

Líneas 10–10; tipo `block`.

```text
/*SW control*/
```

## 1426. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/btcoexist/halbtc8822bwifionly.c:12

Líneas 12–12; tipo `block`.

```text
/*antenna mux switch */
```

## 1427. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/btcoexist/halbtc8822bwifionly.c:18

Líneas 18–18; tipo `block`.

```text
/*switch to WL side controller and gnt_wl gnt_bt debug signal */
```

## 1428. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/btcoexist/halbtc8822bwifionly.c:20

Líneas 20–20; tipo `block`.

```text
/*gnt_wl=1 , gnt_bt=0*/
```

## 1429. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/btcoexist/halbtc8822bwifionly.h:1

Líneas 1–1; tipo `block`.

```text
/* SPDX-License-Identifier: GPL-2.0 */
```

## 1430. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/btcoexist/halbtc8822bwifionly.h:2

Líneas 2–2; tipo `block`.

```text
/* Copyright(c) 2016-2017  Realtek Corporation.*/
```

## 1431. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/btcoexist/halbtcoutsrc.c:1

Líneas 1–1; tipo `line`.

```text
// SPDX-License-Identifier: GPL-2.0
```

## 1432. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/btcoexist/halbtcoutsrc.c:2

Líneas 2–2; tipo `block`.

```text
/* Copyright(c) 2007-2013  Realtek Corporation.*/
```

## 1433. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/btcoexist/halbtcoutsrc.c:6

Líneas 6–8; tipo `block`.

```text
/***************************************************
 *		Debug related function
 ***************************************************/
```

## 1434. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/btcoexist/halbtcoutsrc.c:43

Líneas 43–45; tipo `block`.

```text
/***************************************************
 *		helper function
 ***************************************************/
```

## 1435. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/btcoexist/halbtcoutsrc.c:194

Líneas 194–194; tipo `block`.

```text
/* before h2c to avoid race condition */
```

## 1436. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/btcoexist/halbtcoutsrc.c:199

Líneas 199–201; tipo `block`.

```text
/* fill req_num by op_code, and rtl_btc_btmpinfo_notify() use it
	 * to know message type
	 */
```

## 1437. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/btcoexist/halbtcoutsrc.c:244

Líneas 244–244; tipo `block`.

```text
/* Set OperVer */
```

## 1438. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/btcoexist/halbtcoutsrc.c:245

Líneas 245–245; tipo `block`.

```text
/* Set ReqNum */
```

## 1439. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/btcoexist/halbtcoutsrc.c:249

Líneas 249–249; tipo `block`.

```text
/* wait? */
```

## 1440. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/btcoexist/halbtcoutsrc.c:264

Líneas 264–264; tipo `block`.

```text
/* timeout */
```

## 1441. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/btcoexist/halbtcoutsrc.c:288

Líneas 288–288; tipo `block`.

```text
/* FIXME: Context is unclear. Is it allowed to block? */
```

## 1442. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/btcoexist/halbtcoutsrc.c:310

Líneas 310–310; tipo `block`.

```text
/* FIXME: Context is unclear. Is it allowed to block? */
```

## 1443. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/btcoexist/halbtcoutsrc.c:322

Líneas 322–322; tipo `block`.

```text
/* FIXME: Context is unclear. Is it allowed to block? */
```

## 1444. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/btcoexist/halbtcoutsrc.c:334

Líneas 334–334; tipo `block`.

```text
/* FIXME: Context is unclear. Is it allowed to block? */
```

## 1445. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/btcoexist/halbtcoutsrc.c:356

Líneas 356–356; tipo `block`.

```text
/* TODO: original/leave 32k low power */
```

## 1446. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/btcoexist/halbtcoutsrc.c:367

Líneas 367–370; tipo `block`.

```text
/* To void continuous deleteBA=>addBA=>deleteBA=>addBA
	 * This function is not allowed to continuous called
	 * It can only be called after 8 seconds
	 */
```

## 1447. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/btcoexist/halbtcoutsrc.c:374

Líneas 374–374; tipo `block`.

```text
/* over 8 seconds you can execute this function again. */
```

## 1448. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/btcoexist/halbtcoutsrc.c:418

Líneas 418–418; tipo `block`.

```text
/* cmd_buffer[0] and [1] is filled by halbtc_send_bt_mp_operation() */
```

## 1449. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/btcoexist/halbtcoutsrc.c:434

Líneas 434–434; tipo `block`.

```text
/* cmd_buffer[0] and [1] is filled by halbtc_send_bt_mp_operation() */
```

## 1450. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/btcoexist/halbtcoutsrc.c:451

Líneas 451–451; tipo `block`.

```text
/* cmd_buffer[0] and [1] is filled by halbtc_send_bt_mp_operation() */
```

## 1451. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/btcoexist/halbtcoutsrc.c:465

Líneas 465–465; tipo `block`.

```text
/* cmd_buffer[0] and [1] is filled by halbtc_send_bt_mp_operation() */
```

## 1452. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/btcoexist/halbtcoutsrc.c:478

Líneas 478–478; tipo `block`.

```text
/* cmd_buffer[0] and [1] is filled by halbtc_send_bt_mp_operation() */
```

## 1453. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/btcoexist/halbtcoutsrc.c:488

Líneas 488–491; tipo `block`.

```text
/* return value:
	 * [31:16] => connected port number
	 * [15:0]  => port connected bit define
	 */
```

## 1454. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/btcoexist/halbtcoutsrc.c:502

Líneas 502–502; tipo `block`.

```text
/* AP & ADHOC & MESH */
```

## 1455. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/btcoexist/halbtcoutsrc.c:507

Líneas 507–507; tipo `block`.

```text
/* TODO: P2P Connected Status */
```

## 1456. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/btcoexist/halbtcoutsrc.c:694

Líneas 694–694; tipo `block`.

```text
/************* 1Ant **************/
```

## 1457. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/btcoexist/halbtcoutsrc.c:719

Líneas 719–719; tipo `block`.

```text
/* set some bool type variables. */
```

## 1458. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/btcoexist/halbtcoutsrc.c:747

Líneas 747–747; tipo `block`.

```text
/* set some u1Byte type variables. */
```

## 1459. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/btcoexist/halbtcoutsrc.c:755

Líneas 755–755; tipo `block`.

```text
/* the following are some action which will be triggered */
```

## 1460. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/btcoexist/halbtcoutsrc.c:763

Líneas 763–763; tipo `block`.

```text
/* 1Ant */
```

## 1461. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/btcoexist/halbtcoutsrc.c:775

Líneas 775–775; tipo `block`.

```text
/* the following are some action which will be triggered  */
```

## 1462. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/btcoexist/halbtcoutsrc.c:799

Líneas 799–799; tipo `block`.

```text
/*wait for 8812/8821*/
```

## 1463. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/btcoexist/halbtcoutsrc.c:888

Líneas 888–888; tipo `block`.

```text
/* power status	 */
```

## 1464. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/btcoexist/halbtcoutsrc.c:889

Líneas 889–889; tipo `block`.

```text
/*TODO*/
```

## 1465. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/btcoexist/halbtcoutsrc.c:892

Líneas 892–892; tipo `block`.

```text
/*TODO*/
```

## 1466. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/btcoexist/halbtcoutsrc.c:908

Líneas 908–910; tipo `block`.

```text
/************************************************************
 *		IO related function
 ************************************************************/
```

## 1467. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/btcoexist/halbtcoutsrc.c:951

Líneas 951–951; tipo `block`.

```text
/*if not "double word" write*/
```

## 1468. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/btcoexist/halbtcoutsrc.c:1044

Líneas 1044–1044; tipo `block`.

```text
/* port id [2:0] = 0 */
```

## 1469. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/btcoexist/halbtcoutsrc.c:1069

Líneas 1069–1069; tipo `block`.

```text
/* cmd_buffer[0] and [1] is filled by halbtc_send_bt_mp_operation() */
```

## 1470. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/btcoexist/halbtcoutsrc.c:1075

Líneas 1075–1075; tipo `block`.

```text
/* cmd_buffer[0] and [1] is filled by halbtc_send_bt_mp_operation() */
```

## 1471. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/btcoexist/halbtcoutsrc.c:1149

Líneas 1149–1149; tipo `block`.

```text
/* cmd_buffer[0] and [1] is filled by halbtc_send_bt_mp_operation() */
```

## 1472. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/btcoexist/halbtcoutsrc.c:1153

Líneas 1153–1153; tipo `block`.

```text
/* need wait completion to return correct value */
```

## 1473. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/btcoexist/halbtcoutsrc.c:1163

Líneas 1163–1163; tipo `block`.

```text
/* cmd_buffer[0] and [1] is filled by halbtc_send_bt_mp_operation() */
```

## 1474. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/btcoexist/halbtcoutsrc.c:1167

Líneas 1167–1167; tipo `block`.

```text
/* need wait completion to return correct value */
```

## 1475. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/btcoexist/halbtcoutsrc.c:1177

Líneas 1177–1177; tipo `block`.

```text
/* cmd_buffer[0] and [1] is filled by halbtc_send_bt_mp_operation() */
```

## 1476. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/btcoexist/halbtcoutsrc.c:1181

Líneas 1181–1181; tipo `block`.

```text
/* need wait completion to return correct value */
```

## 1477. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/btcoexist/halbtcoutsrc.c:1196

Líneas 1196–1196; tipo `block`.

```text
/* cmd_buffer[0] and [1] is filled by halbtc_send_bt_mp_operation() */
```

## 1478. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/btcoexist/halbtcoutsrc.c:1204

Líneas 1204–1204; tipo `block`.

```text
/* cmd_buffer[0] and [1] is filled by halbtc_send_bt_mp_operation() */
```

## 1479. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/btcoexist/halbtcoutsrc.c:1212

Líneas 1212–1212; tipo `block`.

```text
/* cmd_buffer[0] and [1] is filled by halbtc_send_bt_mp_operation() */
```

## 1480. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/btcoexist/halbtcoutsrc.c:1224

Líneas 1224–1226; tipo `block`.

```text
/*****************************************************************
 *         Extern functions called by other module
 *****************************************************************/
```

## 1481. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/btcoexist/halbtcoutsrc.c:1361

Líneas 1361–1361; tipo `block`.

```text
/* set default antenna position to main  port */
```

## 1482. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/btcoexist/halbtcoutsrc.c:1433

Líneas 1433–1433; tipo `block`.

```text
/* 8723A has no this function */
```

## 1483. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/btcoexist/halbtcoutsrc.c:1768

Líneas 1768–1771; tipo `block`.

```text
/* currently only 1ant we have to do the notification,
	 * once pnp is notified to sleep state, we have to leave LPS that
	 * we can sleep normally.
	 */
```

## 1484. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/btcoexist/halbtcoutsrc.c:1939

Líneas 1939–1939; tipo `block`.

```text
/* Currently used by 8723b only, S0 or S1 */
```

## 1485. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/btcoexist/halbtcoutsrc.h:1

Líneas 1–1; tipo `block`.

```text
/* SPDX-License-Identifier: GPL-2.0 */
```

## 1486. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/btcoexist/halbtcoutsrc.h:2

Líneas 2–2; tipo `block`.

```text
/* Copyright(c) 2009-2012  Realtek Corporation.*/
```

## 1487. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/btcoexist/halbtcoutsrc.h:40

Líneas 40–40; tipo `block`.

```text
/* single Antenna definition */
```

## 1488. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/btcoexist/halbtcoutsrc.h:46

Líneas 46–46; tipo `block`.

```text
/* dual Antenna definition */
```

## 1489. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/btcoexist/halbtcoutsrc.h:49

Líneas 49–49; tipo `block`.

```text
/* coupler Antenna definition */
```

## 1490. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/btcoexist/halbtcoutsrc.h:87

Líneas 87–87; tipo `block`.

```text
/* following is for BTC_MSG_INTERFACE */
```

## 1491. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/btcoexist/halbtcoutsrc.h:91

Líneas 91–91; tipo `block`.

```text
/* following is for BTC_ALGORITHM */
```

## 1492. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/btcoexist/halbtcoutsrc.h:103

Líneas 103–103; tipo `block`.

```text
/* following is for wifi link status */
```

## 1493. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/btcoexist/halbtcoutsrc.h:128

Líneas 128–128; tipo `block`.

```text
/* The following is some board information */
```

## 1494. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/btcoexist/halbtcoutsrc.h:130

Líneas 130–130; tipo `block`.

```text
/* pg ant number */
```

## 1495. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/btcoexist/halbtcoutsrc.h:131

Líneas 131–131; tipo `block`.

```text
/* ant number for btdm */
```

## 1496. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/btcoexist/halbtcoutsrc.h:133

Líneas 133–133; tipo `block`.

```text
/* current used for 8723b only, 1=>s0,  0=>s1 */
```

## 1497. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/btcoexist/halbtcoutsrc.h:204

Líneas 204–204; tipo `block`.

```text
/* Self is SoftAP */
```

## 1498. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/btcoexist/halbtcoutsrc.h:211

Líneas 211–211; tipo `block`.

```text
/* for 8723b-d cut large current issue */
```

## 1499. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/btcoexist/halbtcoutsrc.h:232

Líneas 232–232; tipo `block`.

```text
/* type bool */
```

## 1500. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/btcoexist/halbtcoutsrc.h:256

Líneas 256–256; tipo `block`.

```text
/* type s4Byte */
```

## 1501. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/btcoexist/halbtcoutsrc.h:260

Líneas 260–260; tipo `block`.

```text
/* type u32 */
```

## 1502. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/btcoexist/halbtcoutsrc.h:275

Líneas 275–275; tipo `block`.

```text
/* type u1Byte */
```

## 1503. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/btcoexist/halbtcoutsrc.h:284

Líneas 284–284; tipo `block`.

```text
/* for 1Ant */
```

## 1504. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/btcoexist/halbtcoutsrc.h:288

Líneas 288–288; tipo `block`.

```text
/* for test mode */
```

## 1505. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/btcoexist/halbtcoutsrc.h:300

Líneas 300–300; tipo `block`.

```text
/* type bool */
```

## 1506. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/btcoexist/halbtcoutsrc.h:311

Líneas 311–311; tipo `block`.

```text
/* type u1Byte */
```

## 1507. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/btcoexist/halbtcoutsrc.h:316

Líneas 316–316; tipo `block`.

```text
/* type trigger some action */
```

## 1508. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/btcoexist/halbtcoutsrc.h:322

Líneas 322–322; tipo `block`.

```text
/********* for 1Ant **********/
```

## 1509. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/btcoexist/halbtcoutsrc.h:323

Líneas 323–323; tipo `block`.

```text
/* type bool */
```

## 1510. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/btcoexist/halbtcoutsrc.h:325

Líneas 325–325; tipo `block`.

```text
/* type u1Byte */
```

## 1511. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/btcoexist/halbtcoutsrc.h:331

Líneas 331–331; tipo `block`.

```text
/* type trigger some action */
```

## 1512. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/btcoexist/halbtcoutsrc.h:342

Líneas 342–342; tipo `block`.

```text
/* BT Coex related */
```

## 1513. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/btcoexist/halbtcoutsrc.h:346

Líneas 346–346; tipo `block`.

```text
/***************************/
```

## 1514. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/btcoexist/halbtcoutsrc.h:553

Líneas 553–553; tipo `block`.

```text
/* the following is for 1Ant solution */
```

## 1515. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/btcoexist/halbtcoutsrc.h:577

Líneas 577–577; tipo `block`.

```text
/* stack hci version */
```

## 1516. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/btcoexist/halbtcoutsrc.h:648

Líneas 648–648; tipo `block`.

```text
/* 4 bits only */
```

## 1517. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/btcoexist/halbtcoutsrc.h:664

Líneas 664–664; tipo `block`.

```text
/* make sure only one adapter can bind the data context  */
```

## 1518. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/btcoexist/halbtcoutsrc.h:666

Líneas 666–666; tipo `block`.

```text
/* default adapter */
```

## 1519. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/btcoexist/halbtcoutsrc.h:669

Líneas 669–669; tipo `block`.

```text
/* some bt info referenced by non-bt module */
```

## 1520. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/btcoexist/halbtcoutsrc.h:675

Líneas 675–677; tipo `block`.

```text
/* boolean variables to replace BT_AUTO_REPORT_ONLY_XXXXY_ZANT
	 * configuration parameters
	 */
```

## 1521. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/btcoexist/halbtcoutsrc.h:690

Líneas 690–690; tipo `block`.

```text
/* function pointers - io related */
```

## 1522. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/btcoexist/halbtcoutsrc.h:797

Líneas 797–797; tipo `block`.

```text
/* The following are used by wifi_only case */
```

## 1523. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/btcoexist/rtl_btc.c:1

Líneas 1–1; tipo `line`.

```text
// SPDX-License-Identifier: GPL-2.0
```

## 1524. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/btcoexist/rtl_btc.c:2

Líneas 2–2; tipo `block`.

```text
/* Copyright(c) 2009-2013  Realtek Corporation.*/
```

## 1525. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/btcoexist/rtl_btc.c:172

Líneas 172–174; tipo `block`.

```text
/* move ant_num, bt_type and single_ant_path to
	 * exhalbtc_bind_bt_coex_withadapter()
	 */
```

## 1526. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/btcoexist/rtl_btc.c:224

Líneas 224–226; tipo `block`.

```text
/* In some situation, it doesn't scan after leaving IPS, and
		 * this will cause btcoex in wrong state.
		 */
```

## 1527. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/btcoexist/rtl_btc.c:292

Líneas 292–292; tipo `block`.

```text
/*rtl_bt_dm_monitor();*/
```

## 1528. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/btcoexist/rtl_btc.c:331

Líneas 331–331; tipo `block`.

```text
/* not response from BT FW then exit*/
```

## 1529. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/btcoexist/rtl_btc.c:332

Líneas 332–332; tipo `block`.

```text
/* C2H_TRIG_BY_BT_FW = 1 */
```

## 1530. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/btcoexist/rtl_btc.c:338

Líneas 338–338; tipo `block`.

```text
/* BT Firmware version response */
```

## 1531. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/btcoexist/rtl_btc.c:436

Líneas 436–436; tipo `block`.

```text
/* It seems 'bt_disabled' is never be initialized or set. */
```

## 1532. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/btcoexist/rtl_btc.h:1

Líneas 1–1; tipo `block`.

```text
/* SPDX-License-Identifier: GPL-2.0 */
```

## 1533. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/btcoexist/rtl_btc.h:2

Líneas 2–2; tipo `block`.

```text
/* Copyright(c) 2009-2010  Realtek Corporation.*/
```

## 1534. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/cam.c:1

Líneas 1–1; tipo `line`.

```text
// SPDX-License-Identifier: GPL-2.0
```

## 1535. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/cam.c:2

Líneas 2–2; tipo `block`.

```text
/* Copyright(c) 2009-2012  Realtek Corporation.*/
```

## 1536. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/cam.c:32

Líneas 32–32; tipo `block`.

```text
/* 0-1 config + mac, 2-5 fill 128key,6-7 are reserved */
```

## 1537. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/cam.c:268

Líneas 268–268; tipo `block`.

```text
/* Does STA already exist? */
```

## 1538. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/cam.c:274

Líneas 274–274; tipo `block`.

```text
/* Get a free CAM entry. */
```

## 1539. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/cam.c:305

Líneas 305–305; tipo `block`.

```text
/* Does STA already exist? */
```

## 1540. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/cam.c:311

Líneas 311–311; tipo `block`.

```text
/* Remove from HW Security CAM */
```

## 1541. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/cam.h:1

Líneas 1–1; tipo `block`.

```text
/* SPDX-License-Identifier: GPL-2.0 */
```

## 1542. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/cam.h:2

Líneas 2–2; tipo `block`.

```text
/* Copyright(c) 2009-2012  Realtek Corporation.*/
```

## 1543. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/core.c:1

Líneas 1–1; tipo `line`.

```text
// SPDX-License-Identifier: GPL-2.0
```

## 1544. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/core.c:2

Líneas 2–2; tipo `block`.

```text
/* Copyright(c) 2009-2012  Realtek Corporation.*/
```

## 1545. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/core.c:17

Líneas 17–17; tipo `block`.

```text
/* Band 1 */
```

## 1546. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/core.c:18

Líneas 18–18; tipo `block`.

```text
/* Band 2 */
```

## 1547. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/core.c:19

Líneas 19–19; tipo `block`.

```text
/* Band 3 */
```

## 1548. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/core.c:20

Líneas 20–20; tipo `block`.

```text
/* Band 3 */
```

## 1549. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/core.c:21

Líneas 21–21; tipo `block`.

```text
/* Band 3 */
```

## 1550. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/core.c:22

Líneas 22–22; tipo `block`.

```text
/* Band 4 */
```

## 1551. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/core.c:23

Líneas 23–23; tipo `block`.

```text
/* Band 4 */
```

## 1552. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/core.c:128

Líneas 128–128; tipo `block`.

```text
/*mutex for start & stop is must here. */
```

## 1553. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/core.c:160

Líneas 160–163; tipo `block`.

```text
/* here is must, because adhoc do stop and start,
	 * but stop with RFOFF may cause something wrong,
	 * like adhoc TP
	 */
```

## 1554. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/core.c:168

Líneas 168–168; tipo `block`.

```text
/* if wowlan supported, DON'T clear connected info */
```

## 1555. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/core.c:175

Líneas 175–175; tipo `block`.

```text
/* reset sec info */
```

## 1556. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/core.c:300

Líneas 300–300; tipo `block`.

```text
/*disable cck rate for p2p*/
```

## 1557. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/core.c:327

Líneas 327–327; tipo `block`.

```text
/* Free beacon resources */
```

## 1558. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/core.c:338

Líneas 338–341; tipo `block`.

```text
/*
	 *Note: We assume NL80211_IFTYPE_UNSPECIFIED as
	 *NO LINK for our hardware.
	 */
```

## 1559. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/core.c:452

Líneas 452–452; tipo `block`.

```text
/* 1. unicast? multicast? or broadcast? */
```

## 1560. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/core.c:463

Líneas 463–463; tipo `block`.

```text
/* 2. translate mask_from_os to mask_for_hw */
```

## 1561. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/core.c:465

Líneas 465–484; tipo `block`.

```text
/******************************************************************************
 * pattern from OS uses 'ethenet frame', like this:

		   |    6   |    6   |   2  |     20    |  Variable  |	4  |
		   |--------+--------+------+-----------+------------+-----|
		   |    802.3 Mac Header    | IP Header | TCP Packet | FCS |
		   |   DA   |   SA   | Type |

 * BUT, packet catched by our HW is in '802.11 frame', begin from LLC,

	|     24 or 30      |    6   |   2  |     20    |  Variable  |  4  |
	|-------------------+--------+------+-----------+------------+-----|
	| 802.11 MAC Header |       LLC     | IP Header | TCP Packet | FCS |
			    | Others | Tpye |

 * Therefore, we need translate mask_from_OS to mask_to_hw.
 * We should left-shift mask by 6 bits, then set the new bit[0~5] = 0,
 * because new mask[0~5] means 'SA', but our HW packet begins from LLC,
 * bit[0~5] corresponds to first 6 Bytes in LLC, they just don't match.
 ******************************************************************************/
```

## 1562. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/core.c:486

Líneas 486–486; tipo `block`.

```text
/* Shift 6 bits */
```

## 1563. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/core.c:492

Líneas 492–492; tipo `block`.

```text
/* Set bit 0-5 to zero */
```

## 1564. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/core.c:504

Líneas 504–507; tipo `block`.

```text
/* To get the wake up pattern from the mask.
		 * We do not count first 12 bits which means
		 * DA[6] and SA[6] in the pattern to match HW design.
		 */
```

## 1565. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/core.c:518

Líneas 518–518; tipo `block`.

```text
/* 3. calculate crc */
```

## 1566. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/core.c:523

Líneas 523–523; tipo `block`.

```text
/* 4. write crc & mask_for_hw to hw */
```

## 1567. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/core.c:540

Líneas 540–540; tipo `block`.

```text
/* to resolve s4 can not wake up*/
```

## 1568. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/core.c:567

Líneas 567–567; tipo `block`.

```text
/* to resovle s4 can not wake up*/
```

## 1569. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/core.c:592

Líneas 592–592; tipo `block`.

```text
/* BIT(2)*/
```

## 1570. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/core.c:597

Líneas 597–597; tipo `block`.

```text
/*For IPS */
```

## 1571. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/core.c:604

Líneas 604–607; tipo `block`.

```text
/*
		 *although rfoff may not cause by ips, but we will
		 *check the reason in set_rf_power_state function
		 */
```

## 1572. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/core.c:612

Líneas 612–612; tipo `block`.

```text
/*For LPS */
```

## 1573. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/core.c:619

Líneas 619–625; tipo `block`.

```text
/* sleep here is must, or we may recv the beacon and
			 * cause mac80211 into wrong ps state, this will cause
			 * power save nullfunc send fail, and further cause
			 * pkt loss, So sleep must quickly but not immediatly
			 * because that will cause nullfunc send by mac80211
			 * fail, and cause pkt loss, we have tested that 5mA
			 * is worked very well */
```

## 1574. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/core.c:640

Líneas 640–642; tipo `block`.

```text
/* brought up everything changes (changed == ~0) indicates first
		 * open, so use our default value instead of that of wiphy.
		 */
```

## 1575. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/core.c:658

Líneas 658–658; tipo `block`.

```text
/* channel_type is for 20&40M */
```

## 1576. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/core.c:672

Líneas 672–680; tipo `block`.

```text
/*
		 *because we should back channel to
		 *current_network.chan in in scanning,
		 *So if set_chan == current_network.chan
		 *we should set it.
		 *because mac80211 tell us wrong bw40
		 *info for cisco1253 bw20, so we modify
		 *it here based on UPPER & LOWER
		 */
```

## 1577. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/core.c:726

Líneas 726–726; tipo `block`.

```text
/* SC */
```

## 1578. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/core.c:735

Líneas 735–735; tipo `block`.

```text
/* SC */
```

## 1579. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/core.c:743

Líneas 743–743; tipo `block`.

```text
/*wide channel */
```

## 1580. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/core.c:748

Líneas 748–748; tipo `block`.

```text
/* SC */
```

## 1581. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/core.c:756

Líneas 756–756; tipo `block`.

```text
/*wide channel */
```

## 1582. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/core.c:772

Líneas 772–779; tipo `block`.

```text
/* In scanning, when before we offchannel we may send a ps=1
		 * null to AP, and then we may send a ps = 0 null to AP quickly,
		 * but first null may have caused AP to put lots of packet to
		 * hw tx buffer. These packets must be tx'd before we go off
		 * channel so we must delay more time to let AP flush these
		 * packets before going offchannel, or dis-association or
		 * delete BA will be caused by AP
		 */
```

## 1583. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/core.c:809

Líneas 809–809; tipo `block`.

```text
/*TODO: we disable broadcase now, so enable here */
```

## 1584. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/core.c:839

Líneas 839–842; tipo `block`.

```text
/* if ssid not set to hw don't check bssid
	 * here just used for linked scanning, & linked
	 * and nolink check bssid is set in set network_type
	 */
```

## 1585. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/core.c:923

Líneas 923–923; tipo `block`.

```text
/*disable cck rate for p2p*/
```

## 1586. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/core.c:980

Líneas 980–983; tipo `block`.

```text
/*
 *for mac80211 VO = 0, VI = 1, BE = 2, BK = 3
 *for rtl819x  BE = 0, BK = 1, VI = 2, VO = 3
 */
```

## 1587. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/core.c:1042

Líneas 1042–1042; tipo `block`.

```text
/*start hw beacon interrupt. */
```

## 1588. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/core.c:1043

Líneas 1043–1043; tipo `block`.

```text
/*rtlpriv->cfg->ops->set_bcn_reg(hw); */
```

## 1589. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/core.c:1074

Líneas 1074–1074; tipo `block`.

```text
/*TODO: reference to enum ieee80211_bss_change */
```

## 1590. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/core.c:1083

Líneas 1083–1086; tipo `block`.

```text
/* we should reset all sec info & cam
			 * before set cam after linked, we should not
			 * reset in disassoc, that will cause tkip->wep
			 * fail because some flag will be wrong */
```

## 1591. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/core.c:1087

Líneas 1087–1087; tipo `block`.

```text
/* reset sec info */
```

## 1592. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/core.c:1089

Líneas 1089–1090; tipo `block`.

```text
/* reset cam to fix wep fail issue
			 * when change from wpa to wep */
```

## 1593. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/core.c:1143

Líneas 1143–1143; tipo `block`.

```text
/* to avoid AP Disassociation caused by inactivity */
```

## 1594. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/core.c:1188

Líneas 1188–1190; tipo `block`.

```text
/* For FW LPS:
		 * To tell firmware we have connected or disconnected
		 */
```

## 1595. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/core.c:1302

Líneas 1302–1303; tipo `block`.

```text
/* just station need it, because ibss & ap mode will
		 * set in sta_add, and will be NULL here */
```

## 1596. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/core.c:1314

Líneas 1314–1319; tipo `block`.

```text
/*
			 * for cisco 1252 bw20 it's wrong
			 * if (ht_cap & IEEE80211_HT_CAP_SUP_WIDTH_20_40) {
			 *	mac->bw_40 = true;
			 * }
			 * */
```

## 1597. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/core.c:1326

Líneas 1326–1327; tipo `block`.

```text
/* for 5G must << RATE_6M_INDEX = 4,
			 * because 5G have no cck rate*/
```

## 1598. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/core.c:1459

Líneas 1459–1459; tipo `block`.

```text
/* Dul mac */
```

## 1599. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/core.c:1481

Líneas 1481–1481; tipo `block`.

```text
/* p2p will use 1/6/11 to scan */
```

## 1600. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/core.c:1487

Líneas 1487–1487; tipo `block`.

```text
/* Dul mac */
```

## 1601. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/core.c:1493

Líneas 1493–1493; tipo `block`.

```text
/* fix fwlps issue */
```

## 1602. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/core.c:1524

Líneas 1524–1524; tipo `block`.

```text
/*User disabled HW-crypto */
```

## 1603. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/core.c:1526

Líneas 1526–1526; tipo `block`.

```text
/* To support IBSS, use sw-crypto for GTK */
```

## 1604. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/core.c:1538

Líneas 1538–1538; tipo `block`.

```text
/* <1> get encryption alg */
```

## 1605. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/core.c:1558

Líneas 1558–1560; tipo `block`.

```text
/* HW don't support CMAC encryption,
		 * use software CMAC encryption
		 */
```

## 1606. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/core.c:1576

Líneas 1576–1576; tipo `block`.

```text
/* <2> get key_idx */
```

## 1607. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/core.c:1580

Líneas 1580–1580; tipo `block`.

```text
/* <3> if pairwise key enable_hw_sec */
```

## 1608. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/core.c:1583

Líneas 1583–1590; tipo `block`.

```text
/* wep always be group key, but there are two conditions:
	 * 1) wep only: is just for wep enc, in this condition
	 * rtlpriv->sec.pairwise_enc_algorithm == NO_ENCRYPTION
	 * will be true & enable_hw_sec will be set when wep
	 * ke setting.
	 * 2) wep(group) + AES(pairwise): some AP like cisco
	 * may use it, in this condition enable_hw_sec will not
	 * be set when wep key setting */
```

## 1609. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/core.c:1591

Líneas 1591–1592; tipo `block`.

```text
/* we must reset sec_info after lingked before set key,
	 * or some flag will be wrong*/
```

## 1610. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/core.c:1616

Líneas 1616–1616; tipo `block`.

```text
/* <4> set key based on cmd */
```

## 1611. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/core.c:1622

Líneas 1622–1622; tipo `block`.

```text
/* Pairwise key with an assigned MAC address. */
```

## 1612. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/core.c:1625

Líneas 1625–1625; tipo `block`.

```text
/*set local buf about wep key. */
```

## 1613. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/core.c:1630

Líneas 1630–1630; tipo `block`.

```text
/* group key */
```

## 1614. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/core.c:1633

Líneas 1633–1633; tipo `block`.

```text
/* group key */
```

## 1615. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/core.c:1635

Líneas 1635–1635; tipo `block`.

```text
/*set local buf about group key. */
```

## 1616. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/core.c:1640

Líneas 1640–1640; tipo `block`.

```text
/* pairwise key */
```

## 1617. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/core.c:1650

Líneas 1650–1650; tipo `block`.

```text
/* Pairwise key with an assigned MAC address. */
```

## 1618. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/core.c:1652

Líneas 1652–1652; tipo `block`.

```text
/*set local buf about pairwise key. */
```

## 1619. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/core.c:1663

Líneas 1663–1663; tipo `block`.

```text
/* <5> tell mac80211 do something: */
```

## 1620. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/core.c:1664

Líneas 1664–1664; tipo `block`.

```text
/*must use sw generate IV, or can not work !!!!. */
```

## 1621. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/core.c:1669

Líneas 1669–1669; tipo `block`.

```text
/*use software CCMP encryption for management frames (MFP) */
```

## 1622. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/core.c:1676

Líneas 1676–1676; tipo `block`.

```text
/*set local buf about wep key. */
```

## 1623. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/core.c:1685

Líneas 1685–1689; tipo `block`.

```text
/*
		 *mac80211 will delete entrys one by one,
		 *so don't use rtl_cam_reset_all_entry
		 *or clear all entry here.
		 */
```

## 1624. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/core.c:1690

Líneas 1690–1690; tipo `block`.

```text
/* wait 500ms for TX ack */
```

## 1625. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/core.c:1716

Líneas 1716–1716; tipo `block`.

```text
/*if Radio On return true here */
```

## 1626. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/core.c:1735

Líneas 1735–1738; tipo `block`.

```text
/* this function is called by mac80211 to flush tx buffer
 * before switch channle or power save, or tx buffer packet
 * maybe send after offchannel or rf sleep, this may cause
 * dis-association by AP */
```

## 1627. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/core.c:1750

Líneas 1750–1755; tipo `block`.

```text
/*	Description:
 *		This routine deals with the Power Configuration CMD
 *		 parsing for RTL8723/RTL8188E Series IC.
 *	Assumption:
 *		We should follow specific format that was released from HW SD.
 */
```

## 1628. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/core.c:1793

Líneas 1793–1793; tipo `block`.

```text
/*Read the value from system register*/
```

## 1629. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/core.c:1799

Líneas 1799–1799; tipo `block`.

```text
/*Write the value back to sytem register*/
```

## 1630. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/core.c:1865

Líneas 1865–1865; tipo `block`.

```text
/*this is wrong, fill_tx_cmddesc needs update*/
```

## 1631. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/core.h:1

Líneas 1–1; tipo `block`.

```text
/* SPDX-License-Identifier: GPL-2.0 */
```

## 1632. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/core.h:2

Líneas 2–2; tipo `block`.

```text
/* Copyright(c) 2009-2012  Realtek Corporation.*/
```

## 1633. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/debug.c:1

Líneas 1–1; tipo `line`.

```text
// SPDX-License-Identifier: GPL-2.0
```

## 1634. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/debug.c:2

Líneas 2–2; tipo `block`.

```text
/* Copyright(c) 2009-2012  Realtek Corporation.*/
```

## 1635. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/debug.c:202

Líneas 202–202; tipo `block`.

```text
/* This dump the current register page */
```

## 1636. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/debug.c:210

Líneas 210–210; tipo `block`.

```text
/* polling bit, and No Write enable, and address  */
```

## 1637. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/debug.c:214

Líneas 214–214; tipo `block`.

```text
/* Check polling bit is clear */
```

## 1638. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/debug.c:286

Líneas 286–286; tipo `block`.

```text
/* write BB/MAC register */
```

## 1639. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/debug.c:303

Líneas 303–303; tipo `block`.

```text
/*printk("error write length=%d", len);*/
```

## 1640. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/debug.c:324

Líneas 324–324; tipo `block`.

```text
/* idx 0: cmd */
```

## 1641. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/debug.h:1

Líneas 1–1; tipo `block`.

```text
/* SPDX-License-Identifier: GPL-2.0 */
```

## 1642. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/debug.h:2

Líneas 2–2; tipo `block`.

```text
/* Copyright(c) 2009-2012  Realtek Corporation.*/
```

## 1643. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/debug.h:7

Líneas 7–9; tipo `block`.

```text
/*--------------------------------------------------------------
			Debug level
--------------------------------------------------------------*/
```

## 1644. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/debug.h:10

Líneas 10–17; tipo `block`.

```text
/*
 *Fatal bug.
 *For example, Tx/Rx/IO locked up,
 *memory access violation,
 *resource allocation failed,
 *unexpected HW behavior, HW BUG
 *and so on.
 */
```

## 1645. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/debug.h:18

Líneas 18–18; tipo `block`.

```text
/*#define DBG_EMERG			0 */
```

## 1646. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/debug.h:20

Líneas 20–24; tipo `block`.

```text
/*
 *Abnormal, rare, or unexpeted cases.
 *For example, Packet/IO Ctl canceled,
 *device suprisely unremoved and so on.
 */
```

## 1647. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/debug.h:27

Líneas 27–32; tipo `block`.

```text
/*
 *Normal case driver developer should
 *open, we can see link status like
 *assoc/AddBA/DHCP/adapter start and
 *so on basic and useful infromations.
 */
```

## 1648. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/debug.h:35

Líneas 35–42; tipo `block`.

```text
/*
 *Normal case with useful information
 *about current SW or HW state.
 *For example, Tx/Rx descriptor to fill,
 *Tx/Rx descriptor completed status,
 *SW protocol state change, dynamic
 *mechanism state change and so on.
 */
```

## 1649. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/debug.h:45

Líneas 45–48; tipo `block`.

```text
/*
 *Normal case with detail execution
 *flow or information.
 */
```

## 1650. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/debug.h:51

Líneas 51–53; tipo `block`.

```text
/*--------------------------------------------------------------
		Define the rt_trace components
--------------------------------------------------------------*/
```

## 1651. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/debug.h:56

Líneas 56–56; tipo `block`.

```text
/*For init/deinit */
```

## 1652. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/debug.h:57

Líneas 57–57; tipo `block`.

```text
/*For Rx. */
```

## 1653. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/debug.h:58

Líneas 58–58; tipo `block`.

```text
/*For Tx. */
```

## 1654. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/debug.h:59

Líneas 59–59; tipo `block`.

```text
/*For MLME. */
```

## 1655. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/debug.h:60

Líneas 60–60; tipo `block`.

```text
/*For Scan. */
```

## 1656. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/debug.h:61

Líneas 61–61; tipo `block`.

```text
/*For interrupt Related. */
```

## 1657. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/debug.h:62

Líneas 62–62; tipo `block`.

```text
/*For LED. */
```

## 1658. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/debug.h:63

Líneas 63–63; tipo `block`.

```text
/*For sec. */
```

## 1659. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/debug.h:64

Líneas 64–64; tipo `block`.

```text
/*For beacon. */
```

## 1660. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/debug.h:65

Líneas 65–65; tipo `block`.

```text
/*For rate. */
```

## 1661. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/debug.h:66

Líneas 66–66; tipo `block`.

```text
/*For rx desc. */
```

## 1662. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/debug.h:67

Líneas 67–67; tipo `block`.

```text
/*For DIG */
```

## 1663. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/debug.h:68

Líneas 68–68; tipo `block`.

```text
/*For Tx power */
```

## 1664. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/debug.h:69

Líneas 69–69; tipo `block`.

```text
/*For High Power Mechanism */
```

## 1665. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/debug.h:70

Líneas 70–70; tipo `block`.

```text
/*For lps/ips/aspm. */
```

## 1666. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/debug.h:71

Líneas 71–71; tipo `block`.

```text
/*For TX POWER TRACKING */
```

## 1667. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/debug.h:73

Líneas 73–73; tipo `block`.

```text
/*For SW Antenna Switch */
```

## 1668. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/debug.h:74

Líneas 74–74; tipo `block`.

```text
/*For RF. */
```

## 1669. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/debug.h:75

Líneas 75–75; tipo `block`.

```text
/*For EDCA TURBO. */
```

## 1670. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/debug.h:84

Líneas 84–84; tipo `block`.

```text
/* reuse of this bit is OK */
```

## 1671. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/debug.h:89

Líneas 89–91; tipo `block`.

```text
/*--------------------------------------------------------------
		Define the rt_print components
--------------------------------------------------------------*/
```

## 1672. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/debug.h:92

Líneas 92–92; tipo `block`.

```text
/* Define EEPROM and EFUSE  check module bit*/
```

## 1673. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/debug.h:97

Líneas 97–97; tipo `block`.

```text
/* Define init check for module bit*/
```

## 1674. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/debug.h:103

Líneas 103–103; tipo `block`.

```text
/* Define PHY-BB/RF/MAC check module bit */
```

## 1675. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/debug.h:115

Líneas 115–115; tipo `block`.

```text
/* Define Dynamic Mechanism check module bit --> FDM */
```

## 1676. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/efuse.c:1

Líneas 1–1; tipo `line`.

```text
// SPDX-License-Identifier: GPL-2.0
```

## 1677. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/efuse.c:2

Líneas 2–2; tipo `block`.

```text
/* Copyright(c) 2009-2012  Realtek Corporation.*/
```

## 1678. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/efuse.c:220

Líneas 220–220; tipo `block`.

```text
/* allocate memory for efuse_tbl and efuse_word */
```

## 1679. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/efuse.c:248

Líneas 248–248; tipo `block`.

```text
/*  Check PG header for section num.  */
```

## 1680. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/efuse.c:249

Líneas 249–249; tipo `block`.

```text
/* extended header */
```

## 1681. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/efuse.c:1283

Líneas 1283–1283; tipo `block`.

```text
/* set channel plan to world wide 13 */
```

## 1682. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/efuse.h:1

Líneas 1–1; tipo `block`.

```text
/* SPDX-License-Identifier: GPL-2.0 */
```

## 1683. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/efuse.h:2

Líneas 2–2; tipo `block`.

```text
/* Copyright(c) 2009-2012  Realtek Corporation.*/
```

## 1684. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/pci.c:1

Líneas 1–1; tipo `line`.

```text
// SPDX-License-Identifier: GPL-2.0
```

## 1685. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/pci.c:2

Líneas 2–2; tipo `block`.

```text
/* Copyright(c) 2009-2012  Realtek Corporation.*/
```

## 1686. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/pci.c:59

Líneas 59–59; tipo `block`.

```text
/* Update PCI dependent default settings*/
```

## 1687. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/pci.c:72

Líneas 72–72; tipo `block`.

```text
/*Update PCI ASPM setting */
```

## 1688. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/pci.c:76

Líneas 76–76; tipo `block`.

```text
/*No ASPM */
```

## 1689. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/pci.c:80

Líneas 80–80; tipo `block`.

```text
/*ASPM dynamically enabled/disable. */
```

## 1690. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/pci.c:85

Líneas 85–85; tipo `block`.

```text
/*ASPM with Clock Req dynamically enabled/disable. */
```

## 1691. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/pci.c:91

Líneas 91–93; tipo `block`.

```text
/* Always enable ASPM and Clock Req
		 * from initialization to halt.
		 */
```

## 1692. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/pci.c:100

Líneas 100–102; tipo `block`.

```text
/* Always enable ASPM without Clock Req
		 * from initialization to halt.
		 */
```

## 1693. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/pci.c:111

Líneas 111–111; tipo `block`.

```text
/*Update Radio OFF setting */
```

## 1694. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/pci.c:129

Líneas 129–129; tipo `block`.

```text
/*Set HW definition to determine if it supports ASPM. */
```

## 1695. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/pci.c:132

Líneas 132–132; tipo `block`.

```text
/*Not support ASPM. */
```

## 1696. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/pci.c:136

Líneas 136–136; tipo `block`.

```text
/*Support ASPM. */
```

## 1697. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/pci.c:141

Líneas 141–141; tipo `block`.

```text
/*ASPM value set by chipset. */
```

## 1698. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/pci.c:151

Líneas 151–153; tipo `block`.

```text
/* toshiba aspm issue, toshiba will set aspm selfly
	 * so we should not set aspm in driver
	 */
```

## 1699. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/pci.c:159

Líneas 159–163; tipo `block`.

```text
/* RTL8723BE found on some ASUSTek laptops, such as F441U and
	 * X555UQ with subsystem ID 11ad:1723 are known to output large
	 * amounts of PCIe AER errors during and after boot up, causing
	 * heavy lags, poor network throughput, and occasional lock-ups.
	 */
```

## 1700. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/pci.c:189

Líneas 189–189; tipo `block`.

```text
/* @value is PCI_EXP_LNKCTL_CLKREQ_EN or 0 to enable/disable clk request. */
```

## 1701. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/pci.c:205

Líneas 205–205; tipo `block`.

```text
/*Disable RTL8192SE ASPM & Disable Pci Bridge ASPM*/
```

## 1702. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/pci.c:213

Líneas 213–213; tipo `block`.

```text
/*Retrieve original configuration settings. */
```

## 1703. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/pci.c:233

Líneas 233–233; tipo `block`.

```text
/*for promising device will in L0 state after an I/O. */
```

## 1704. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/pci.c:236

Líneas 236–236; tipo `block`.

```text
/*Set corresponding value. */
```

## 1705. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/pci.c:243

Líneas 243–247; tipo `block`.

```text
/*Enable RTL8192SE ASPM & Enable Pci Bridge ASPM for
 *power saving We should follow the sequence to enable
 *RTL8192SE first then enable Pci Bridge ASPM
 *or the system will show bluescreen.
 */
```

## 1706. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/pci.c:267

Líneas 267–267; tipo `block`.

```text
/*Get ASPM level (with/without Clock Req) */
```

## 1707. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/pci.c:271

Líneas 271–271; tipo `block`.

```text
/*_rtl_pci_platform_switch_device_pci_aspm(dev,*/
```

## 1708. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/pci.c:272

Líneas 272–272; tipo `block`.

```text
/*(priv->ndis_adapter.linkctrl_reg | ASPMLevel)); */
```

## 1709. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/pci.c:317

Líneas 317–317; tipo `block`.

```text
/*Link Control Register */
```

## 1710. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/pci.c:339

Líneas 339–339; tipo `block`.

```text
/*Always enable ASPM & Clock Req. */
```

## 1711. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/pci.c:371

Líneas 371–371; tipo `block`.

```text
/* here open is 4, wep/tkip is 8, aes is 12*/
```

## 1712. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/pci.c:375

Líneas 375–375; tipo `block`.

```text
/* The most skb num is 6 */
```

## 1713. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/pci.c:402

Líneas 402–402; tipo `block`.

```text
/* just for early mode now */
```

## 1714. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/pci.c:416

Líneas 416–416; tipo `block`.

```text
/* we just use em for BE/BK/VI/VO */
```

## 1715. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/pci.c:438

Líneas 438–440; tipo `block`.

```text
/* Some macaddr can't do early mode. like
			 * multicast/broadcast/no_qos data
			 */
```

## 1716. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/pci.c:480

Líneas 480–480; tipo `block`.

```text
/* remove early mode header */
```

## 1717. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/pci.c:495

Líneas 495–498; tipo `block`.

```text
/* for sw LPS, just after NULL skb send out, we can
		 * sure AP knows we are sleeping, we should not let
		 * rf sleep
		 */
```

## 1718. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/pci.c:518

Líneas 518–518; tipo `block`.

```text
/* update tid tx pkt num */
```

## 1719. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/pci.c:528

Líneas 528–528; tipo `block`.

```text
/*info->status.rates[0].count = 1; */
```

## 1720. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/pci.c:571

Líneas 571–571; tipo `block`.

```text
/* just set skb->cb to mapping addr for pci_unmap_single use */
```

## 1721. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/pci.c:583

Líneas 583–583; tipo `block`.

```text
/* skb->cb may be 64 bit address */
```

## 1722. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/pci.c:601

Líneas 601–613; tipo `block`.

```text
/* inorder to receive 8K AMSDU we have set skb to
 * 9100bytes in init rx ring, but if this packet is
 * not a AMSDU, this large packet will be sent to
 * TCP/IP directly, this cause big packet ping fail
 * like: "ping -s 65507", so here we will realloc skb
 * based on the true size of packet, Mac80211
 * Probably will do it better, but does not yet.
 *
 * Some platform will fail when alloc skb sometimes.
 * in this condition, we will send the old skb to
 * mac80211 directly, this will not cause any other
 * issues, but only this packet will be lost by TCP/IP
 */
```

## 1723. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/pci.c:636

Líneas 636–636; tipo `block`.

```text
/*hsisr interrupt handler*/
```

## 1724. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/pci.c:664

Líneas 664–664; tipo `block`.

```text
/*RX NORMAL PKT */
```

## 1725. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/pci.c:669

Líneas 669–669; tipo `block`.

```text
/*rx buffer descriptor */
```

## 1726. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/pci.c:671

Líneas 671–671; tipo `block`.

```text
/*if use new trx flow, it means wifi info */
```

## 1727. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/pci.c:673

Líneas 673–673; tipo `block`.

```text
/*rx pkt */
```

## 1728. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/pci.c:688

Líneas 688–688; tipo `block`.

```text
/* rx descriptor */
```

## 1729. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/pci.c:695

Líneas 695–695; tipo `block`.

```text
/* wait data to be filled by hardware */
```

## 1730. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/pci.c:699

Líneas 699–702; tipo `block`.

```text
/* Reaching this point means: data is filled already
		 * AAAAAAttention !!!
		 * We can NOT access 'skb' before 'pci_unmap_single'
		 */
```

## 1731. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/pci.c:706

Líneas 706–706; tipo `block`.

```text
/* get a new skb - if fail, old one will be reused */
```

## 1732. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/pci.c:737

Líneas 737–737; tipo `block`.

```text
/* handle command packet here */
```

## 1733. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/pci.c:743

Líneas 743–747; tipo `block`.

```text
/* NOTICE This can not be use for mac80211,
		 * this is done in mac80211 code,
		 * if done here sec DHCP will fail
		 * skb_trim(skb, skb->len - 4);
		 */
```

## 1734. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/pci.c:757

Líneas 757–757; tipo `block`.

```text
/*TODO*/
```

## 1735. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/pci.c:759

Líneas 759–759; tipo `block`.

```text
/*TODO*/
```

## 1736. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/pci.c:774

Líneas 774–774; tipo `block`.

```text
/* static bcn for roaming */
```

## 1737. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/pci.c:777

Líneas 777–777; tipo `block`.

```text
/* for sw lps */
```

## 1738. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/pci.c:789

Líneas 789–789; tipo `block`.

```text
/* drop packets with errors or those too short */
```

## 1739. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/pci.c:852

Líneas 852–852; tipo `block`.

```text
/*read ISR: 4/8bytes */
```

## 1740. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/pci.c:855

Líneas 855–855; tipo `block`.

```text
/*Shared IRQ or HW disappeared */
```

## 1741. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/pci.c:859

Líneas 859–859; tipo `block`.

```text
/*<1> beacon related */
```

## 1742. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/pci.c:877

Líneas 877–877; tipo `block`.

```text
/*<2> Tx related */
```

## 1743. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/pci.c:945

Líneas 945–945; tipo `block`.

```text
/*<3> Rx related */
```

## 1744. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/pci.c:962

Líneas 962–962; tipo `block`.

```text
/*<4> fw related*/
```

## 1745. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/pci.c:972

Líneas 972–972; tipo `block`.

```text
/*<5> hsisr related*/
```

## 1746. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/pci.c:973

Líneas 973–977; tipo `block`.

```text
/* Only 8188EE & 8723BE Supported.
	 * If Other ICs Come in, System will corrupt,
	 * because maps[RTL_IMR_HSISR_IND] & maps[MAC_HSISR]
	 * are not initialized
	 */
```

## 1747. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/pci.c:1017

Líneas 1017–1017; tipo `block`.

```text
/*This is for new trx flow*/
```

## 1748. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/pci.c:1037

Líneas 1037–1037; tipo `block`.

```text
/*NB: the beacon data buffer must be 32-bit aligned. */
```

## 1749. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/pci.c:1081

Líneas 1081–1083; tipo `block`.

```text
/*we just alloc 2 desc for beacon queue,
	 *because we just need first desc in hw beacon.
	 */
```

## 1750. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/pci.c:1086

Líneas 1086–1089; tipo `block`.

```text
/*BE queue need more descriptor for performance
	 *consideration or, No more tx desc will happen,
	 *and may cause mac80211 mem leakage.
	 */
```

## 1751. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/pci.c:1093

Líneas 1093–1093; tipo `block`.

```text
/*2048/1024; */
```

## 1752. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/pci.c:1094

Líneas 1094–1094; tipo `block`.

```text
/*64; */
```

## 1753. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/pci.c:1111

Líneas 1111–1111; tipo `block`.

```text
/*Tx/Rx related var */
```

## 1754. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/pci.c:1114

Líneas 1114–1114; tipo `block`.

```text
/*IBSS*/
```

## 1755. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/pci.c:1117

Líneas 1117–1117; tipo `block`.

```text
/*AMPDU*/
```

## 1756. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/pci.c:1120

Líneas 1120–1120; tipo `block`.

```text
/*set sane AMPDU defaults */
```

## 1757. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/pci.c:1124

Líneas 1124–1124; tipo `block`.

```text
/*Retry Limit*/
```

## 1758. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/pci.c:1128

Líneas 1128–1128; tipo `block`.

```text
/*QOS*/
```

## 1759. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/pci.c:1131

Líneas 1131–1131; tipo `block`.

```text
/*task */
```

## 1760. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/pci.c:1150

Líneas 1150–1150; tipo `block`.

```text
/* alloc tx buffer desc for new trx flow*/
```

## 1761. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/pci.c:1170

Líneas 1170–1170; tipo `block`.

```text
/* alloc dma for this ring */
```

## 1762. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/pci.c:1189

Líneas 1189–1189; tipo `block`.

```text
/* init every desc in this ring */
```

## 1763. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/pci.c:1213

Líneas 1213–1213; tipo `block`.

```text
/* alloc dma for this ring */
```

## 1764. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/pci.c:1225

Líneas 1225–1225; tipo `block`.

```text
/* init every desc in this ring */
```

## 1765. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/pci.c:1236

Líneas 1236–1236; tipo `block`.

```text
/* alloc dma for this ring */
```

## 1766. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/pci.c:1248

Líneas 1248–1248; tipo `block`.

```text
/* init every desc in this ring */
```

## 1767. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/pci.c:1271

Líneas 1271–1271; tipo `block`.

```text
/* free every desc in this ring */
```

## 1768. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/pci.c:1289

Líneas 1289–1289; tipo `block`.

```text
/* free dma of this ring */
```

## 1769. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/pci.c:1308

Líneas 1308–1308; tipo `block`.

```text
/* free every desc in this ring */
```

## 1770. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/pci.c:1319

Líneas 1319–1319; tipo `block`.

```text
/* free dma of this ring */
```

## 1771. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/pci.c:1343

Líneas 1343–1345; tipo `block`.

```text
/* rxring_idx 0:RX_MPDU_QUEUE
	 * rxring_idx 1:RX_CMD_QUEUE
	 */
```

## 1772. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/pci.c:1376

Líneas 1376–1376; tipo `block`.

```text
/*free rx rings */
```

## 1773. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/pci.c:1380

Líneas 1380–1380; tipo `block`.

```text
/*free tx rings */
```

## 1774. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/pci.c:1395

Líneas 1395–1395; tipo `block`.

```text
/* rxring_idx 0:RX_MPDU_QUEUE */
```

## 1775. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/pci.c:1396

Líneas 1396–1396; tipo `block`.

```text
/* rxring_idx 1:RX_CMD_QUEUE */
```

## 1776. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/pci.c:1398

Líneas 1398–1401; tipo `block`.

```text
/* force the rx_ring[RX_MPDU_QUEUE/
		 * RX_CMD_QUEUE].idx to the first one
		 *new trx flow, do nothing
		 */
```

## 1777. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/pci.c:1414

Líneas 1414–1414; tipo `block`.

```text
/*clear one entry*/
```

## 1778. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/pci.c:1441

Líneas 1441–1443; tipo `block`.

```text
/*after reset, release previous pending packet,
	 *and force the  tx idx to the first one
	 */
```

## 1779. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/pci.c:1510

Líneas 1510–1510; tipo `block`.

```text
/* maybe every tid should be checked */
```

## 1780. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/pci.c:1662

Líneas 1662–1662; tipo `block`.

```text
/* we just wait 1s for all queues */
```

## 1781. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/pci.c:1736

Líneas 1736–1736; tipo `block`.

```text
/*should be after adapter start and interrupt enable. */
```

## 1782. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/pci.c:1762

Líneas 1762–1764; tipo `block`.

```text
/*should be before disable interrupt&adapter
	 *and will do it immediately.
	 */
```

## 1783. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/pci.c:1786

Líneas 1786–1786; tipo `block`.

```text
/* some things are not needed if firmware not available */
```

## 1784. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/pci.c:1817

Líneas 1817–1822; tipo `block`.

```text
/* PCI ID 0x10ec:0x8192 occurs for both RTL8192E, which uses
	 * r8192e_pci, and RTL8192SE, which uses this driver. If the
	 * revision ID is RTL_PCI_REVISION_ID_8192PCIE (0x01), then
	 * the correct driver is r8192e_pci, thus this routine should
	 * return false.
	 */
```

## 1785. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/pci.c:1929

Líneas 1929–1929; tipo `block`.

```text
/* use new trx flow */
```

## 1786. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/pci.c:1938

Líneas 1938–1938; tipo `block`.

```text
/*find bus info */
```

## 1787. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/pci.c:1943

Líneas 1943–1943; tipo `block`.

```text
/*find bridge info */
```

## 1788. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/pci.c:1945

Líneas 1945–1947; tipo `block`.

```text
/* some ARM have no bridge_pdev and will crash here
	 * so we should check if bridge_pdev is NULL
	 */
```

## 1789. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/pci.c:1949

Líneas 1949–1949; tipo `block`.

```text
/*find bridge info if available */
```

## 1790. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/pci.c:2063

Líneas 2063–2063; tipo `block`.

```text
/* 0x719 Bit5 is DMA64 bit fetch. */
```

## 1791. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/pci.c:2130

Líneas 2130–2130; tipo `block`.

```text
/*proximity init here*/
```

## 1792. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/pci.c:2136

Líneas 2136–2136; tipo `block`.

```text
/* init cfg & intf_ops */
```

## 1793. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/pci.c:2142

Líneas 2142–2142; tipo `block`.

```text
/* MEM map */
```

## 1794. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/pci.c:2153

Líneas 2153–2153; tipo `block`.

```text
/*shared mem start */
```

## 1795. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/pci.c:2168

Líneas 2168–2168; tipo `block`.

```text
/* Disable Clk Request */
```

## 1796. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/pci.c:2170

Líneas 2170–2170; tipo `block`.

```text
/* leave D3 mode */
```

## 1797. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/pci.c:2175

Líneas 2175–2175; tipo `block`.

```text
/* find adapter */
```

## 1798. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/pci.c:2181

Líneas 2181–2181; tipo `block`.

```text
/* Init IO handler */
```

## 1799. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/pci.c:2184

Líneas 2184–2184; tipo `block`.

```text
/*like read eeprom and so on */
```

## 1800. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/pci.c:2194

Líneas 2194–2194; tipo `block`.

```text
/*aspm */
```

## 1801. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/pci.c:2197

Líneas 2197–2197; tipo `block`.

```text
/* Init mac80211 sw */
```

## 1802. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/pci.c:2204

Líneas 2204–2204; tipo `block`.

```text
/* Init PCI sw */
```

## 1803. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/pci.c:2219

Líneas 2219–2219; tipo `block`.

```text
/* add for debug */
```

## 1804. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/pci.c:2222

Líneas 2222–2222; tipo `block`.

```text
/*init rfkill */
```

## 1805. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/pci.c:2223

Líneas 2223–2223; tipo `block`.

```text
/* Init PCI sw */
```

## 1806. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/pci.c:2269

Líneas 2269–2269; tipo `block`.

```text
/* just in case driver is removed before firmware callback */
```

## 1807. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/pci.c:2273

Líneas 2273–2273; tipo `block`.

```text
/* remove form debug */
```

## 1808. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/pci.c:2276

Líneas 2276–2276; tipo `block`.

```text
/*ieee80211_unregister_hw will call ops_stop */
```

## 1809. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/pci.c:2286

Líneas 2286–2286; tipo `block`.

```text
/*deinit rfkill */
```

## 1810. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/pci.c:2317

Líneas 2317–2331; tipo `block`.

```text
/***************************************
 * kernel pci power state define:
 * PCI_D0         ((pci_power_t __force) 0)
 * PCI_D1         ((pci_power_t __force) 1)
 * PCI_D2         ((pci_power_t __force) 2)
 * PCI_D3hot      ((pci_power_t __force) 3)
 * PCI_D3cold     ((pci_power_t __force) 4)
 * PCI_UNKNOWN    ((pci_power_t __force) 5)

 * This function is called when system
 * goes into suspend state mac80211 will
 * call rtl_mac_stop() from the mac80211
 * suspend function first, So there is
 * no need to call hw_disable here.
 ****************************************/
```

## 1811. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/pci.c:2354

Líneas 2354–2354; tipo `block`.

```text
/* CONFIG_PM_SLEEP */
```

## 1812. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/pci.h:1

Líneas 1–1; tipo `block`.

```text
/* SPDX-License-Identifier: GPL-2.0 */
```

## 1813. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/pci.h:2

Líneas 2–2; tipo `block`.

```text
/* Copyright(c) 2009-2012  Realtek Corporation.*/
```

## 1814. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/pci.h:8

Líneas 8–10; tipo `block`.

```text
/* 1: MSDU packet queue,
 * 2: Rx Command Queue
 */
```

## 1815. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/pci.h:15

Líneas 15–15; tipo `block`.

```text
/*64*/
```

## 1816. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/pci.h:32

Líneas 32–32; tipo `block`.

```text
/* In 8822B */
```

## 1817. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/pci.h:51

Líneas 51–51; tipo `block`.

```text
/*PCI Configuration Space Address */
```

## 1818. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/pci.h:52

Líneas 52–52; tipo `block`.

```text
/*PCI Configuration Space Data */
```

## 1819. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/pci.h:63

Líneas 63–63; tipo `block`.

```text
/*8192 PCI-E */
```

## 1820. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/pci.h:64

Líneas 64–64; tipo `block`.

```text
/*8192 SE */
```

## 1821. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/pci.h:65

Líneas 65–65; tipo `block`.

```text
/*8192 SE */
```

## 1822. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/pci.h:66

Líneas 66–66; tipo `block`.

```text
/*8191 SE Crab */
```

## 1823. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/pci.h:67

Líneas 67–67; tipo `block`.

```text
/*8191 SE RE */
```

## 1824. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/pci.h:68

Líneas 68–68; tipo `block`.

```text
/*8191 SE Unicron */
```

## 1825. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/pci.h:69

Líneas 69–69; tipo `block`.

```text
/*8723AE */
```

## 1826. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/pci.h:70

Líneas 70–70; tipo `block`.

```text
/*8190 PCI for Ceraga */
```

## 1827. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/pci.h:71

Líneas 71–71; tipo `block`.

```text
/*8190 Cardbus for Ceraga */
```

## 1828. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/pci.h:72

Líneas 72–72; tipo `block`.

```text
/*8192e PCIE for Ceraga */
```

## 1829. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/pci.h:73

Líneas 73–73; tipo `block`.

```text
/*8192e Express Card for Ceraga */
```

## 1830. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/pci.h:77

Líneas 77–77; tipo `block`.

```text
/*8723e */
```

## 1831. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/pci.h:78

Líneas 78–78; tipo `block`.

```text
/*8192ce */
```

## 1832. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/pci.h:79

Líneas 79–79; tipo `block`.

```text
/*8192ce */
```

## 1833. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/pci.h:80

Líneas 80–80; tipo `block`.

```text
/*8192ce */
```

## 1834. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/pci.h:81

Líneas 81–81; tipo `block`.

```text
/*8192ce */
```

## 1835. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/pci.h:82

Líneas 82–82; tipo `block`.

```text
/*8192ce */
```

## 1836. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/pci.h:83

Líneas 83–83; tipo `block`.

```text
/*8192de */
```

## 1837. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/pci.h:84

Líneas 84–84; tipo `block`.

```text
/*92DE*/
```

## 1838. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/pci.h:85

Líneas 85–85; tipo `block`.

```text
/*8188ee*/
```

## 1839. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/pci.h:86

Líneas 86–86; tipo `block`.

```text
/*8723be*/
```

## 1840. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/pci.h:87

Líneas 87–87; tipo `block`.

```text
/*8192ee*/
```

## 1841. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/pci.h:88

Líneas 88–88; tipo `block`.

```text
/*8821ae*/
```

## 1842. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/pci.h:89

Líneas 89–89; tipo `block`.

```text
/*8812ae*/
```

## 1843. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/pci.h:90

Líneas 90–90; tipo `block`.

```text
/*8822be*/
```

## 1844. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/pci.h:92

Líneas 92–92; tipo `block`.

```text
/*8192 support 16 pages of IO registers*/
```

## 1845. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/pci.h:108

Líneas 108–108; tipo `block`.

```text
/*0b'0000,0001 */
```

## 1846. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/pci.h:109

Líneas 109–109; tipo `block`.

```text
/*0b'0000,0010*/
```

## 1847. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/pci.h:110

Líneas 110–110; tipo `block`.

```text
/*0b'0000,0100*/
```

## 1848. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/pci.h:111

Líneas 111–111; tipo `block`.

```text
/*0b'0000,1000*/
```

## 1849. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/pci.h:112

Líneas 112–112; tipo `block`.

```text
/*0b'0100,0000*/
```

## 1850. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/pci.h:121

Líneas 121–124; tipo `block`.

```text
/* In new TRX flow, Buffer_desc is new concept
 * But TX wifi info == TX descriptor in old flow
 * RX wifi info == RX descriptor in old flow
 */
```

## 1851. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/pci.h:133

Líneas 133–133; tipo `block`.

```text
/*rx buffer desc*/
```

## 1852. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/pci.h:137

Líneas 137–137; tipo `block`.

```text
/*old: rx desc new: rx wifi info*/
```

## 1853. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/pci.h:151

Líneas 151–151; tipo `block`.

```text
/*add for new trx flow*/
```

## 1854. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/pci.h:152

Líneas 152–152; tipo `block`.

```text
/*tx buffer descriptor*/
```

## 1855. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/pci.h:153

Líneas 153–153; tipo `block`.

```text
/*tx bufferd desc dma memory*/
```

## 1856. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/pci.h:154

Líneas 154–154; tipo `block`.

```text
/* current_tx_write_point */
```

## 1857. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/pci.h:155

Líneas 155–155; tipo `block`.

```text
/* current_tx_read_point */
```

## 1858. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/pci.h:163

Líneas 163–163; tipo `block`.

```text
/*add for new trx flow*/
```

## 1859. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/pci.h:164

Líneas 164–164; tipo `block`.

```text
/*rx buffer descriptor*/
```

## 1860. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/pci.h:165

Líneas 165–165; tipo `block`.

```text
/* next_rx_read_point */
```

## 1861. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/pci.h:178

Líneas 178–178; tipo `block`.

```text
/*Tx */
```

## 1862. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/pci.h:183

Líneas 183–183; tipo `block`.

```text
/*Rx */
```

## 1863. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/pci.h:189

Líneas 189–189; tipo `block`.

```text
/*irq */
```

## 1864. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/pci.h:191

Líneas 191–191; tipo `block`.

```text
/* 0-1: normal, 2: unused, 3: h2c */
```

## 1865. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/pci.h:194

Líneas 194–194; tipo `block`.

```text
/*Bcn control register setting */
```

## 1866. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/pci.h:197

Líneas 197–197; tipo `block`.

```text
/*ASPM*/
```

## 1867. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/pci.h:201

Líneas 201–201; tipo `block`.

```text
/*pci-e bridge */
```

## 1868. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/pci.h:203

Líneas 203–203; tipo `block`.

```text
/*pci-e device */
```

## 1869. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/pci.h:205

Líneas 205–207; tipo `block`.

```text
/* If it supports ASPM, Offset[560h] = 0x40,
	 * otherwise Offset[560h] = 0x00.
	 */
```

## 1870. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/pci.h:211

Líneas 211–211; tipo `block`.

```text
/*QOS & EDCA */
```

## 1871. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/pci.h:217

Líneas 217–217; tipo `block`.

```text
/* MSI support */
```

## 1872. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/pci.h:220

Líneas 220–220; tipo `block`.

```text
/* interrupt clear before set */
```

## 1873. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/pci.h:262

Líneas 262–262; tipo `block`.

```text
/* CONFIG_PM_SLEEP */
```

## 1874. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/ps.c:1

Líneas 1–1; tipo `line`.

```text
// SPDX-License-Identifier: GPL-2.0
```

## 1875. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/ps.c:2

Líneas 2–2; tipo `block`.

```text
/* Copyright(c) 2009-2012  Realtek Corporation.*/
```

## 1876. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/ps.c:17

Líneas 17–17; tipo `block`.

```text
/*<1> reset trx ring */
```

## 1877. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/ps.c:25

Líneas 25–25; tipo `block`.

```text
/*<2> Enable Adapter */
```

## 1878. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/ps.c:37

Líneas 37–37; tipo `block`.

```text
/*<3> Enable Interrupt */
```

## 1879. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/ps.c:40

Líneas 40–40; tipo `block`.

```text
/*<enable timer> */
```

## 1880. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/ps.c:51

Líneas 51–51; tipo `block`.

```text
/*<1> Stop all timer */
```

## 1881. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/ps.c:54

Líneas 54–54; tipo `block`.

```text
/*<2> Disable Interrupt */
```

## 1882. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/ps.c:58

Líneas 58–58; tipo `block`.

```text
/*<3> Disable Adapter */
```

## 1883. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/ps.c:74

Líneas 74–77; tipo `block`.

```text
/*Only one thread can change
	 *the RF state at one time, and others
	 *should wait to be executed.
	 */
```

## 1884. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/ps.c:87

Líneas 87–87; tipo `block`.

```text
/* Set RF after the previous action is done.  */
```

## 1885. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/ps.c:91

Líneas 91–93; tipo `block`.

```text
/*Wait too long, return false to avoid
				 *to be stuck here.
				 */
```

## 1886. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/ps.c:217

Líneas 217–225; tipo `block`.

```text
/*
		 *Do not enter IPS in the following conditions:
		 *(1) RF is already OFF or Sleep
		 *(2) swrf_processing (indicates the IPS is still under going)
		 *(3) Connectted (only disconnected can trigger IPS)
		 *(4) IBSS (send Beacon)
		 *(5) AP mode (send Beacon)
		 *(6) monitor mode (rcv packet)
		 */
```

## 1887. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/ps.c:237

Líneas 237–237; tipo `block`.

```text
/* call before RF off */
```

## 1888. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/ps.c:242

Líneas 242–242; tipo `block`.

```text
/*rtl_pci_reset_trx_ring(hw); */
```

## 1889. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/ps.c:252

Líneas 252–255; tipo `block`.

```text
/* because when link with ap, mac80211 will ask us
	 * to disable nic quickly after scan before linking,
	 * this will cause link failed, so we delay 100ms here
	 */
```

## 1890. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/ps.c:260

Líneas 260–262; tipo `block`.

```text
/* NOTICE: any opmode should exc nic_on, or disable without
 * nic_on may something wrong, like adhoc TP
 */
```

## 1891. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/ps.c:282

Líneas 282–282; tipo `block`.

```text
/* call after RF on */
```

## 1892. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/ps.c:292

Líneas 292–292; tipo `block`.

```text
/*for FW LPS*/
```

## 1893. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/ps.c:294

Líneas 294–298; tipo `block`.

```text
/*
 *Determine if we can set Fw into PS mode
 *in current condition.Return TRUE if it
 *can enter PS mode.
 */
```

## 1894. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/ps.c:324

Líneas 324–324; tipo `block`.

```text
/* Change current and default preamble mode.*/
```

## 1895. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/ps.c:341

Líneas 341–341; tipo `block`.

```text
/* Update power save mode configured. */
```

## 1896. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/ps.c:344

Líneas 344–352; tipo `block`.

```text
/*
	 *<FW control LPS>
	 *1. Enter PS mode
	 *   Set RPWM to Fw to turn RF off and send H2C fw_pwrmode
	 *   cmd to set Fw into PS mode.
	 *2. Leave PS mode
	 *   Send H2C fw_pwrmode cmd to Fw to set Fw into Active
	 *   mode and set RPWM to turn RF on.
	 */
```

## 1897. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/ps.c:384

Líneas 384–384; tipo `block`.

```text
/* Reset the power save related parameters. */
```

## 1898. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/ps.c:391

Líneas 391–391; tipo `block`.

```text
/* Interrupt safe routine to enter the leisure power save mode.*/
```

## 1899. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/ps.c:407

Líneas 407–407; tipo `block`.

```text
/*sleep after linked 10s, to let DHCP and 4-way handshake ok enough!! */
```

## 1900. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/ps.c:419

Líneas 419–422; tipo `block`.

```text
/* Don't need to check (ppsc->dot11_psmode == EACTIVE), because
	 * bt_ccoexist may ask to enter lps.
	 * In normal case, this constraint move to rtl_lps_set_psmode().
	 */
```

## 1901. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/ps.c:430

Líneas 430–430; tipo `block`.

```text
/* Interrupt safe routine to leave the leisure power save mode.*/
```

## 1902. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/ps.c:442

Líneas 442–442; tipo `block`.

```text
/*FIX ME */
```

## 1903. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/ps.c:443

Líneas 443–443; tipo `block`.

```text
/*rtlpriv->cfg->ops->enable_interrupt(hw); */
```

## 1904. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/ps.c:461

Líneas 461–461; tipo `block`.

```text
/* For sw LPS*/
```

## 1905. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/ps.c:491

Líneas 491–491; tipo `block`.

```text
/* check if this really is a beacon */
```

## 1906. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/ps.c:495

Líneas 495–495; tipo `block`.

```text
/* min. beacon length + FCS_LEN */
```

## 1907. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/ps.c:499

Líneas 499–499; tipo `block`.

```text
/* and only beacons from the associated BSSID, please */
```

## 1908. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/ps.c:518

Líneas 518–518; tipo `block`.

```text
/* Check whenever the PHY can be turned off again. */
```

## 1909. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/ps.c:520

Líneas 520–520; tipo `block`.

```text
/* 1. What about buffered unicast traffic for our AID? */
```

## 1910. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/ps.c:524

Líneas 524–524; tipo `block`.

```text
/* 2. Maybe the AP wants to send multicast/broadcast data? */
```

## 1911. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/ps.c:528

Líneas 528–530; tipo `block`.

```text
/* unicast will process by mac80211 through
	 * set ~IEEE80211_CONF_PS, So we just check
	 * multicast frames here */
```

## 1912. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/ps.c:532

Líneas 532–533; tipo `block`.

```text
/* back to low-power land. and delay is
		 * prevent null power save frame tx fail */
```

## 1913. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/ps.c:588

Líneas 588–588; tipo `block`.

```text
/*sleep after linked 10s, to let DHCP and 4-way handshake ok enough!! */
```

## 1914. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/ps.c:612

Líneas 612–616; tipo `block`.

```text
/* here is power save alg, when this beacon is DTIM
	 * we will set sleep time to dtim_period * n;
	 * when this beacon is not DTIM, we will set sleep
	 * time to sleep_intv = rtlpriv->psc.dtim_counter or
	 * MAX_SW_LPS_SLEEP_INTV(default set to 5) */
```

## 1915. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/ps.c:630

Líneas 630–632; tipo `block`.

```text
/* this print should always be dtim_conter = 0 &
	 * sleep  = dtim_period, that meaons, we should
	 * awake before every dtim */
```

## 1916. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/ps.c:637

Líneas 637–637; tipo `block`.

```text
/* we tested that 40ms is enough for sw & hw sw delay */
```

## 1917. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/ps.c:688

Líneas 688–688; tipo `block`.

```text
/* we can sleep after ps null send ok */
```

## 1918. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/ps.c:737

Líneas 737–737; tipo `block`.

```text
/*to find noa ie*/
```

## 1919. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/ps.c:783

Líneas 783–785; tipo `block`.

```text
/* Driver should wait LPS entering
					 * CTWindow
					 */
```

## 1920. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/ps.c:832

Líneas 832–832; tipo `block`.

```text
/*to find noa ie*/
```

## 1921. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/ps.c:878

Líneas 878–880; tipo `block`.

```text
/* Driver should wait LPS entering
					 * CTWindow
					 */
```

## 1922. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/ps.c:979

Líneas 979–979; tipo `block`.

```text
/* min. beacon length + FCS_LEN */
```

## 1923. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/ps.c:983

Líneas 983–983; tipo `block`.

```text
/* and only beacons from the associated BSSID, please */
```

## 1924. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/ps.c:987

Líneas 987–987; tipo `block`.

```text
/* check if this really is a beacon */
```

## 1925. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/ps.h:1

Líneas 1–1; tipo `block`.

```text
/* SPDX-License-Identifier: GPL-2.0 */
```

## 1926. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/ps.h:2

Líneas 2–2; tipo `block`.

```text
/* Copyright(c) 2009-2012  Realtek Corporation.*/
```

## 1927. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/pwrseqcmd.h:1

Líneas 1–1; tipo `block`.

```text
/* SPDX-License-Identifier: GPL-2.0 */
```

## 1928. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/pwrseqcmd.h:2

Líneas 2–2; tipo `block`.

```text
/* Copyright(c) 2009-2012  Realtek Corporation.*/
```

## 1929. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/pwrseqcmd.h:8

Líneas 8–11; tipo `block`.

```text
/*---------------------------------------------
 * 3 The value of cmd: 4 bits
 *---------------------------------------------
 */
```

## 1930. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/pwrseqcmd.h:18

Líneas 18–18; tipo `block`.

```text
/* define the base address of each block */
```

## 1931. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/rc.c:1

Líneas 1–1; tipo `line`.

```text
// SPDX-License-Identifier: GPL-2.0
```

## 1932. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/rc.c:2

Líneas 2–2; tipo `block`.

```text
/* Copyright(c) 2009-2012  Realtek Corporation.*/
```

## 1933. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/rc.c:8

Líneas 8–14; tipo `block`.

```text
/*
 *Finds the highest rate index we can use
 *if skb is special data like DHCP/EAPOL, we set should
 *it to lowest rate CCK_1M, otherwise we set rate to
 *highest rate based on wireless mode used for iwconfig
 *show Tx rate.
 */
```

## 1934. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/rc.c:41

Líneas 41–47; tipo `block`.

```text
/*
	 *this rate is no use for true rate, firmware
	 *will control rate at all it just used for
	 *1.show in iwconfig in B/G mode
	 *2.in rtl_get_tcb_desc when we check rate is
	 *      1M we will not use FW rate but user rate.
	 */
```

## 1935. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/rc.c:207

Líneas 207–207; tipo `block`.

```text
/*mac80211 Rate Control callbacks*/
```

## 1936. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/rc.c:230

Líneas 230–230; tipo `block`.

```text
/* Check if aggregation has to be enabled for this tid */
```

## 1937. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/rc.h:1

Líneas 1–1; tipo `block`.

```text
/* SPDX-License-Identifier: GPL-2.0 */
```

## 1938. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/rc.h:2

Líneas 2–2; tipo `block`.

```text
/* Copyright(c) 2009-2012  Realtek Corporation.*/
```

## 1939. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/rc.h:11

Líneas 11–11; tipo `block`.

```text
/* in mac80211 mcs0-mcs15 is idx0-idx15*/
```

## 1940. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/regd.c:1

Líneas 1–1; tipo `line`.

```text
// SPDX-License-Identifier: GPL-2.0
```

## 1941. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/regd.c:2

Líneas 2–2; tipo `block`.

```text
/* Copyright(c) 2009-2012  Realtek Corporation.*/
```

## 1942. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/regd.c:24

Líneas 24–27; tipo `block`.

```text
/*
 *Only these channels all allow active
 *scan on all world regulatory domains
 */
```

## 1943. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/regd.c:31

Líneas 31–34; tipo `block`.

```text
/*
 *We enable active scan on these a case
 *by case basis by regulatory domain
 */
```

## 1944. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/regd.c:44

Líneas 44–44; tipo `block`.

```text
/* 5G chan 36 - chan 64*/
```

## 1945. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/regd.c:47

Líneas 47–47; tipo `block`.

```text
/* 5G chan 100 - chan 165*/
```

## 1946. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/regd.c:50

Líneas 50–50; tipo `block`.

```text
/* 5G chan 149 - chan 165*/
```

## 1947. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/regd.c:157

Líneas 157–164; tipo `block`.

```text
/*
				 *If 11d had a rule for this channel ensure
				 *we enable adhoc/beaconing if it allows us to
				 *use it. Note that we would have disabled it
				 *by applying our static world regdomain by
				 *default during init, prior to calling our
				 *regulatory_hint().
				 */
```

## 1948. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/regd.c:181

Líneas 181–181; tipo `block`.

```text
/* Allows active scan scan on Ch 12 and 13 */
```

## 1949. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/regd.c:194

Líneas 194–197; tipo `block`.

```text
/*
	 *If no country IE has been received always enable active scan
	 *on these channels. This is only done for specific regulatory SKUs
	 */
```

## 1950. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/regd.c:199

Líneas 199–199; tipo `block`.

```text
/* CH 12 */
```

## 1951. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/regd.c:202

Líneas 202–202; tipo `block`.

```text
/* CH 13 */
```

## 1952. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/regd.c:208

Líneas 208–213; tipo `block`.

```text
/*
	 *If a country IE has been recieved check its rule for this
	 *channel first before enabling active scan. The passive scan
	 *would have been enforced by the initial processing of our
	 *custom regulatory domain.
	 */
```

## 1953. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/regd.c:215

Líneas 215–215; tipo `block`.

```text
/* CH 12 */
```

## 1954. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/regd.c:223

Líneas 223–223; tipo `block`.

```text
/* CH 13 */
```

## 1955. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/regd.c:232

Líneas 232–235; tipo `block`.

```text
/*
 *Always apply Radar/DFS rules on
 *freq range 5260 MHz - 5700 MHz
 */
```

## 1956. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/regd.c:252

Líneas 252–262; tipo `block`.

```text
/*
		 *We always enable radar detection/DFS on this
		 *frequency range. Additionally we also apply on
		 *this frequency range:
		 *- If STA mode does not yet have DFS supports disable
		 * active scanning
		 *- If adhoc mode does not support DFS yet then disable
		 * adhoc in the frequency.
		 *- If AP mode does not yet support radar detection/DFS
		 *do not allow AP mode
		 */
```

## 1957. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/regd.c:283

Líneas 283–283; tipo `block`.

```text
/* We always apply this */
```

## 1958. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/regd.c:377

Líneas 377–377; tipo `block`.

```text
/*Error*/
```

## 1959. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/regd.c:392

Líneas 392–392; tipo `block`.

```text
/* init country_code from efuse channel plan */
```

## 1960. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/regd.h:1

Líneas 1–1; tipo `block`.

```text
/* SPDX-License-Identifier: GPL-2.0 */
```

## 1961. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/regd.h:2

Líneas 2–2; tipo `block`.

```text
/* Copyright(c) 2009-2012  Realtek Corporation.*/
```

## 1962. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/regd.h:7

Líneas 7–7; tipo `block`.

```text
/* for kernel 3.14 , both value are changed to IEEE80211_CHAN_NO_IR*/
```

## 1963. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/regd.h:32

Líneas 32–32; tipo `block`.

```text
/*add new channel plan above this line */
```

## 1964. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/rtl8192ee/Makefile:1

Líneas 1–1; tipo `hash`.

```text
# SPDX-License-Identifier: GPL-2.0
```

## 1965. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/rtl8192ee/def.h:1

Líneas 1–1; tipo `block`.

```text
/* SPDX-License-Identifier: GPL-2.0 */
```

## 1966. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/rtl8192ee/def.h:2

Líneas 2–2; tipo `block`.

```text
/* Copyright(c) 2009-2014  Realtek Corporation.*/
```

## 1967. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/rtl8192ee/dm.c:1

Líneas 1–1; tipo `line`.

```text
// SPDX-License-Identifier: GPL-2.0
```

## 1968. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/rtl8192ee/dm.c:2

Líneas 2–2; tipo `block`.

```text
/* Copyright(c) 2009-2014  Realtek Corporation.*/
```

## 1969. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/rtl8192ee/dm.c:74

Líneas 74–74; tipo `block`.

```text
/*reset false alarm counter registers*/
```

## 1970. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/rtl8192ee/dm.c:79

Líneas 79–79; tipo `block`.

```text
/*update ofdm counter*/
```

## 1971. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/rtl8192ee/dm.c:82

Líneas 82–82; tipo `block`.

```text
/*reset CCK CCA counter*/
```

## 1972. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/rtl8192ee/dm.c:85

Líneas 85–85; tipo `block`.

```text
/*reset CCK FA counter*/
```

## 1973. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/rtl8192ee/dm.c:139

Líneas 139–139; tipo `block`.

```text
/* AP,BT */
```

## 1974. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/rtl8192ee/dm.c:305

Líneas 305–308; tipo `block`.

```text
/*It seems the following values are not initialized.
	  *According to Windows code,
	  *these value will only be valid with JAGUAR chips
	  */
```

## 1975. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/rtl8192ee/dm.c:309

Líneas 309–309; tipo `block`.

```text
/* Rx EVM */
```

## 1976. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/rtl8192ee/dm.c:312

Líneas 312–312; tipo `block`.

```text
/* Rx SNR */
```

## 1977. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/rtl8192ee/dm.c:317

Líneas 317–317; tipo `block`.

```text
/* Rx Cfo_Short */
```

## 1978. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/rtl8192ee/dm.c:322

Líneas 322–322; tipo `block`.

```text
/* Rx Cfo_Tail */
```

## 1979. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/rtl8192ee/dm.c:333

Líneas 333–333; tipo `block`.

```text
/* Determine the minimum RSSI  */
```

## 1980. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/rtl8192ee/dm.c:381

Líneas 381–381; tipo `block`.

```text
/* AP & ADHOC & MESH */
```

## 1981. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/rtl8192ee/dm.c:399

Líneas 399–399; tipo `block`.

```text
/* If associated entry is found */
```

## 1982. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/rtl8192ee/dm.c:407

Líneas 407–407; tipo `block`.

```text
/* If associated entry is found */
```

## 1983. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/rtl8192ee/dm.c:417

Líneas 417–417; tipo `block`.

```text
/* Indicate Rx signal strength to FW. */
```

## 1984. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/rtl8192ee/dm.c:475

Líneas 475–475; tipo `block`.

```text
/*not sure*/
```

## 1985. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/rtl8192ee/dm.c:487

Líneas 487–487; tipo `block`.

```text
/*b_bias_on_rx = false;*/
```

## 1986. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/rtl8192ee/dm.c:582

Líneas 582–582; tipo `block`.

```text
/* NIC: 2: sec is below,  1: sec is above */
```

## 1987. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/rtl8192ee/dm.c:597

Líneas 597–599; tipo `block`.

```text
/* Primary channel is above
		 * NOTE: duplicate CTS can remove this condition
		 */
```

## 1988. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/rtl8192ee/dm.c:655

Líneas 655–655; tipo `block`.

```text
/* PrimaryCCA->PriCCA_flag==1 */
```

## 1989. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/rtl8192ee/dm.c:661

Líneas 661–661; tipo `block`.

```text
/* default */
```

## 1990. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/rtl8192ee/dm.c:686

Líneas 686–686; tipo `block`.

```text
/* Disable CFO tracking for BT */
```

## 1991. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/rtl8192ee/dm.c:695

Líneas 695–695; tipo `block`.

```text
/* Reset Crystal Cap */
```

## 1992. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/rtl8192ee/dm.c:827

Líneas 827–832; tipo `block`.

```text
/* Threshold Adjustment:
	 * when RSSI state trends to go up one or two levels,
	 * make sure RSSI is high enough.
	 * Here GoUpGap is added to solve
	 * the boundary's level alternation issue.
	 */
```

## 1993. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/rtl8192ee/dm.c:850

Líneas 850–850; tipo `block`.

```text
/* Decide RATRState by RSSI. */
```

## 1994. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/rtl8192ee/dm.c:992

Líneas 992–992; tipo `block`.

```text
/* collision_state == 0 */
```

## 1995. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/rtl8192ee/dm.c:1020

Líneas 1020–1020; tipo `block`.

```text
/* MCS13~MCS15,  1SS, G-mode */
```

## 1996. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/rtl8192ee/dm.c:1043

Líneas 1043–1043; tipo `block`.

```text
/* collision_state == 0 */
```

## 1997. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/rtl8192ee/dm.h:1

Líneas 1–1; tipo `block`.

```text
/* SPDX-License-Identifier: GPL-2.0 */
```

## 1998. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/rtl8192ee/dm.h:2

Líneas 2–2; tipo `block`.

```text
/* Copyright(c) 2009-2014  Realtek Corporation.*/
```

## 1999. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/rtl8192ee/dm.h:21

Líneas 21–21; tipo `block`.

```text
/*RF REG LIST*/
```

## 2000. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/rtl8192ee/dm.h:35

Líneas 35–35; tipo `block`.

```text
/*BB REG LIST*/
```

## 2001. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/rtl8192ee/dm.h:36

Líneas 36–36; tipo `block`.

```text
/*PAGE 8 */
```

## 2002. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/rtl8192ee/dm.h:54

Líneas 54–54; tipo `block`.

```text
/*PAGE 9*/
```

## 2003. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/rtl8192ee/dm.h:57

Líneas 57–57; tipo `block`.

```text
/*PAGE A*/
```

## 2004. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/rtl8192ee/dm.h:76

Líneas 76–76; tipo `block`.

```text
/*PAGE B */
```

## 2005. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/rtl8192ee/dm.h:82

Líneas 82–82; tipo `block`.

```text
/*PAGE C */
```

## 2006. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/rtl8192ee/dm.h:103

Líneas 103–103; tipo `block`.

```text
/*PAGE D */
```

## 2007. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/rtl8192ee/dm.h:108

Líneas 108–108; tipo `block`.

```text
/*PAGE E */
```

## 2008. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/rtl8192ee/dm.h:141

Líneas 141–141; tipo `block`.

```text
/*MAC REG LIST*/
```

## 2009. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/rtl8192ee/dm.h:155

Líneas 155–155; tipo `block`.

```text
/*DIG Related*/
```

## 2010. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/rtl8192ee/dm.h:202

Líneas 202–202; tipo `block`.

```text
/* Dynamic ATC switch */
```

## 2011. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/rtl8192ee/dm.h:203

Líneas 203–203; tipo `block`.

```text
/* enable */
```

## 2012. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/rtl8192ee/dm.h:204

Líneas 204–204; tipo `block`.

```text
/* disable */
```

## 2013. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/rtl8192ee/dm.h:205

Líneas 205–205; tipo `block`.

```text
/* kHz */
```

## 2014. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/rtl8192ee/dm.h:206

Líneas 206–206; tipo `block`.

```text
/* kHz */
```

## 2015. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/rtl8192ee/dm.h:208

Líneas 208–208; tipo `block`.

```text
/* RSSI Dump Message */
```

## 2016. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/rtl8192ee/fw.c:1

Líneas 1–1; tipo `line`.

```text
// SPDX-License-Identifier: GPL-2.0
```

## 2017. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/rtl8192ee/fw.c:2

Líneas 2–2; tipo `block`.

```text
/* Copyright(c) 2009-2014  Realtek Corporation.*/
```

## 2018. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/rtl8192ee/fw.c:190

Líneas 190–192; tipo `block`.

```text
/* 1. Prevent race condition in setting H2C cmd.
	 * (copy from MgntActSet_RF_State().)
	 */
```

## 2019. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/rtl8192ee/fw.c:223

Líneas 223–223; tipo `block`.

```text
/* 2. Find the last BOX number which has been writen. */
```

## 2020. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/rtl8192ee/fw.c:248

Líneas 248–248; tipo `block`.

```text
/* 3. Check if the box content is empty. */
```

## 2021. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/rtl8192ee/fw.c:281

Líneas 281–283; tipo `block`.

```text
/* If Fw has not read the last
		 * H2C cmd, break and give up this H2C.
		 */
```

## 2022. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/rtl8192ee/fw.c:290

Líneas 290–290; tipo `block`.

```text
/* 4. Fill the H2C cmd into box */
```

## 2023. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/rtl8192ee/fw.c:302

Líneas 302–302; tipo `block`.

```text
/*boxcontent[0] &= ~(BIT(7));*/
```

## 2024. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/rtl8192ee/fw.c:315

Líneas 315–315; tipo `block`.

```text
/*boxcontent[0] |= (BIT(7));*/
```

## 2025. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/rtl8192ee/fw.c:401

Líneas 401–401; tipo `block`.

```text
/* DTIM = (awake_intvl - 1) */
```

## 2026. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/rtl8192ee/fw.c:426

Líneas 426–428; tipo `block`.

```text
/* hw->conf.ps_dtim_period or mac->vif->bss_conf.dtim_period
		 * is only used in swlps.
		 */
```

## 2027. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/rtl8192ee/fw.c:450

Líneas 450–452; tipo `block`.

```text
/* Keep awake interval to 1 to prevent from
				 * decreasing coex performance
				 */
```

## 2028. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/rtl8192ee/fw.c:487

Líneas 487–492; tipo `block`.

```text
/* parm[0]: bit0=0-->Disconnect, bit0=1-->Connect
	 *          bit1=0-->update Media Status to MACID
	 *          bit1=1-->update Media Status from MACID to MACID_End
	 * parm[1]: MACID, if this is INFRA_STA, MacID = 0
	 * parm[2]: MACID_End
	 */
```

## 2029. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/rtl8192ee/fw.c:500

Líneas 500–500; tipo `block`.

```text
/* ->1 */
```

## 2030. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/rtl8192ee/fw.c:503

Líneas 503–503; tipo `block`.

```text
/* ->5 */
```

## 2031. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/rtl8192ee/fw.c:510

Líneas 510–510; tipo `block`.

```text
/* page 0 beacon */
```

## 2032. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/rtl8192ee/fw.c:528

Líneas 528–528; tipo `block`.

```text
/* page 1 beacon */
```

## 2033. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/rtl8192ee/fw.c:546

Líneas 546–546; tipo `block`.

```text
/* page 2  ps-poll */
```

## 2034. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/rtl8192ee/fw.c:564

Líneas 564–564; tipo `block`.

```text
/* page 3  null */
```

## 2035. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/rtl8192ee/fw.c:582

Líneas 582–582; tipo `block`.

```text
/* page 4  probe_resp */
```

## 2036. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/rtl8192ee/fw.c:600

Líneas 600–600; tipo `block`.

```text
/* page 5  probe_resp */
```

## 2037. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/rtl8192ee/fw.c:614

Líneas 614–614; tipo `block`.

```text
/* page 6 qos null data */
```

## 2038. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/rtl8192ee/fw.c:632

Líneas 632–632; tipo `block`.

```text
/* page 7 BT-qos null data */
```

## 2039. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/rtl8192ee/fw.c:671

Líneas 671–674; tipo `block`.

```text
/*---------------------------------------------------------
	 *			(1) beacon
	 *---------------------------------------------------------
	 */
```

## 2040. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/rtl8192ee/fw.c:679

Líneas 679–682; tipo `block`.

```text
/*-------------------------------------------------------
	 *			(2) ps-poll
	 *--------------------------------------------------------
	 */
```

## 2041. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/rtl8192ee/fw.c:690

Líneas 690–693; tipo `block`.

```text
/*--------------------------------------------------------
	 *			(3) null data
	 *---------------------------------------------------------
	 */
```

## 2042. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/rtl8192ee/fw.c:701

Líneas 701–704; tipo `block`.

```text
/*---------------------------------------------------------
	 *			(4) probe response
	 *----------------------------------------------------------
	 */
```

## 2043. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/rtl8192ee/fw.c:712

Líneas 712–715; tipo `block`.

```text
/*---------------------------------------------------------
	 *			(5) QoS null data
	 *----------------------------------------------------------
	 */
```

## 2044. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/rtl8192ee/fw.c:723

Líneas 723–726; tipo `block`.

```text
/*---------------------------------------------------------
	 *			(6) BT QoS null data
	 *----------------------------------------------------------
	 */
```

## 2045. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/rtl8192ee/fw.c:765

Líneas 765–765; tipo `block`.

```text
/*Shoud check FW support p2p or not.*/
```

## 2046. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/rtl8192ee/fw.c:791

Líneas 791–791; tipo `block`.

```text
/* update CTWindow value. */
```

## 2047. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/rtl8192ee/fw.c:797

Líneas 797–797; tipo `block`.

```text
/* hw only support 2 set of NoA */
```

## 2048. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/rtl8192ee/fw.c:799

Líneas 799–799; tipo `block`.

```text
/* To control the register setting for which NOA*/
```

## 2049. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/rtl8192ee/fw.c:805

Líneas 805–805; tipo `block`.

```text
/* config P2P NoA Descriptor Register */
```

## 2050. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/rtl8192ee/fw.c:811

Líneas 811–811; tipo `block`.

```text
/*Get Current TSF value */
```

## 2051. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/rtl8192ee/fw.c:827

Líneas 827–827; tipo `block`.

```text
/* rst p2p circuit */
```

## 2052. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/rtl8192ee/fw.h:1

Líneas 1–1; tipo `block`.

```text
/* SPDX-License-Identifier: GPL-2.0 */
```

## 2053. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/rtl8192ee/fw.h:2

Líneas 2–2; tipo `block`.

```text
/* Copyright(c) 2009-2014  Realtek Corporation.*/
```

## 2054. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/rtl8192ee/fw.h:32

Líneas 32–36; tipo `block`.

```text
/* Fw PS state for RPWM.
*BIT[2:0] = HW state
*BIT[3] = Protocol PS state,  1: register active state, 0: register sleep state
*BIT[4] = sub-state
*/
```

## 2055. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/rtl8192ee/fw.h:43

Líneas 43–43; tipo `block`.

```text
/* 92E RPWM value*/
```

## 2056. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/rtl8192ee/fw.h:44

Líneas 44–44; tipo `block`.

```text
/* BIT[0] = 1: 32k, 0: 40M*/
```

## 2057. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/rtl8192ee/fw.h:45

Líneas 45–45; tipo `block`.

```text
/* 32k */
```

## 2058. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/rtl8192ee/fw.h:46

Líneas 46–46; tipo `block`.

```text
/* 40M */
```

## 2059. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/rtl8192ee/fw.h:59

Líneas 59–59; tipo `block`.

```text
/* For 92E H2C PwrMode Cmd ID 5.*/
```

## 2060. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/rtl8192ee/fw.h:105

Líneas 105–105; tipo `block`.

```text
/*Not defined CTW CMD for P2P yet*/
```

## 2061. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/rtl8192ee/fw.h:139

Líneas 139–139; tipo `block`.

```text
/* _MEDIA_STATUS_RPT_PARM_CMD1 */
```

## 2062. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/rtl8192ee/hw.c:1

Líneas 1–1; tipo `line`.

```text
// SPDX-License-Identifier: GPL-2.0
```

## 2063. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/rtl8192ee/hw.c:2

Líneas 2–2; tipo `block`.

```text
/* Copyright(c) 2009-2014  Realtek Corporation.*/
```

## 2064. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/rtl8192ee/hw.c:229

Líneas 229–229; tipo `block`.

```text
/* RF on */
```

## 2065. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/rtl8192ee/hw.c:237

Líneas 237–237; tipo `block`.

```text
/* RF on */
```

## 2066. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/rtl8192ee/hw.c:256

Líneas 256–256; tipo `block`.

```text
/* RF off */
```

## 2067. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/rtl8192ee/hw.c:264

Líneas 264–264; tipo `block`.

```text
/* RF off */
```

## 2068. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/rtl8192ee/hw.c:336

Líneas 336–336; tipo `block`.

```text
/*Set REG_CR bit 8. DMA beacon by SW.*/
```

## 2069. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/rtl8192ee/hw.c:340

Líneas 340–344; tipo `block`.

```text
/* Disable Hw protection for a time which revserd for Hw sending beacon.
	 * Fix download reserved page packet fail
	 * that access collision with the protection time.
	 * 2010.05.11. Added by tynli.
	 */
```

## 2070. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/rtl8192ee/hw.c:348

Líneas 348–350; tipo `block`.

```text
/* Set FWHW_TXQ_CTRL 0x422[6]=0 to
	 * tell Hw the packet is not a real beacon frame.
	 */
```

## 2071. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/rtl8192ee/hw.c:358

Líneas 358–358; tipo `block`.

```text
/* Clear beacon valid check bit */
```

## 2072. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/rtl8192ee/hw.c:363

Líneas 363–363; tipo `block`.

```text
/* download rsvd page */
```

## 2073. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/rtl8192ee/hw.c:376

Líneas 376–376; tipo `block`.

```text
/* check rsvd page download OK. */
```

## 2074. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/rtl8192ee/hw.c:396

Líneas 396–396; tipo `block`.

```text
/* Enable Bcn */
```

## 2075. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/rtl8192ee/hw.c:750

Líneas 750–750; tipo `block`.

```text
/* 1. 40Mhz crystal source*/
```

## 2076. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/rtl8192ee/hw.c:759

Líneas 759–761; tipo `block`.

```text
/* 2. 92E AFE parameter
	 * MP chip then check version
	 */
```

## 2077. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/rtl8192ee/hw.c:770

Líneas 770–770; tipo `block`.

```text
/* HW Power on sequence */
```

## 2078. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/rtl8192ee/hw.c:779

Líneas 779–779; tipo `block`.

```text
/* Release MAC IO register reset */
```

## 2079. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/rtl8192ee/hw.c:788

Líneas 788–788; tipo `block`.

```text
/* Add for wakeup online */
```

## 2080. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/rtl8192ee/hw.c:793

Líneas 793–793; tipo `block`.

```text
/* Release MAC IO register reset */
```

## 2081. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/rtl8192ee/hw.c:811

Líneas 811–811; tipo `block`.

```text
/* Reported Tx status from HW for rate adaptive.*/
```

## 2082. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/rtl8192ee/hw.c:814

Líneas 814–814; tipo `block`.

```text
/* Set RCR register */
```

## 2083. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/rtl8192ee/hw.c:818

Líneas 818–818; tipo `block`.

```text
/* Set TCR register */
```

## 2084. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/rtl8192ee/hw.c:821

Líneas 821–821; tipo `block`.

```text
/* Set TX/RX descriptor physical address -- HI part */
```

## 2085. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/rtl8192ee/hw.c:846

Líneas 846–846; tipo `block`.

```text
/* Set TX/RX descriptor physical address(from OS API). */
```

## 2086. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/rtl8192ee/hw.c:877

Líneas 877–879; tipo `block`.

```text
/* if we want to support 64 bit DMA, we should set it here,
	 * but now we do not support 64 bit DMA
	 */
```

## 2087. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/rtl8192ee/hw.c:918

Líneas 918–918; tipo `block`.

```text
/*Rx*/
```

## 2088. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/rtl8192ee/hw.c:936

Líneas 936–936; tipo `block`.

```text
/* Init value for RRSR. */
```

## 2089. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/rtl8192ee/hw.c:939

Líneas 939–939; tipo `block`.

```text
/* ARFB table 9 for 11ac 5G 2SS */
```

## 2090. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/rtl8192ee/hw.c:943

Líneas 943–943; tipo `block`.

```text
/* ARFB table 10 for 11ac 5G 1SS */
```

## 2091. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/rtl8192ee/hw.c:947

Líneas 947–947; tipo `block`.

```text
/* Set SLOT time */
```

## 2092. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/rtl8192ee/hw.c:950

Líneas 950–950; tipo `block`.

```text
/* CF-End setting. */
```

## 2093. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/rtl8192ee/hw.c:953

Líneas 953–953; tipo `block`.

```text
/* Set retry limit */
```

## 2094. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/rtl8192ee/hw.c:956

Líneas 956–956; tipo `block`.

```text
/* BAR settings */
```

## 2095. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/rtl8192ee/hw.c:959

Líneas 959–959; tipo `block`.

```text
/* Set Data / Response auto rate fallack retry count */
```

## 2096. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/rtl8192ee/hw.c:965

Líneas 965–965; tipo `block`.

```text
/* Beacon related, for rate adaptive */
```

## 2097. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/rtl8192ee/hw.c:972

Líneas 972–976; tipo `block`.

```text
/* Marked out by Bruce, 2010-09-09.
	 * This register is configured for the 2nd Beacon (multiple BSSID).
	 * We shall disable this register if we only support 1 BSSID.
	 * vivi guess 92d also need this, also 92d now doesnot set this reg
	 */
```

## 2098. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/rtl8192ee/hw.c:979

Líneas 979–979; tipo `block`.

```text
/* TBTT prohibit hold time. Suggested by designer TimChen. */
```

## 2099. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/rtl8192ee/hw.c:980

Líneas 980–980; tipo `block`.

```text
/* 8 ms */
```

## 2100. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/rtl8192ee/hw.c:988

Líneas 988–988; tipo `block`.

```text
/* For Rx TP. Suggested by SD1 Richard. Added by tynli. 2010.04.12.*/
```

## 2101. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/rtl8192ee/hw.c:991

Líneas 991–991; tipo `block`.

```text
/* ACKTO for IOT issue. */
```

## 2102. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/rtl8192ee/hw.c:994

Líneas 994–994; tipo `block`.

```text
/* Set Spec SIFS (used in NAV) */
```

## 2103. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/rtl8192ee/hw.c:998

Líneas 998–998; tipo `block`.

```text
/* Set SIFS for CCK */
```

## 2104. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/rtl8192ee/hw.c:1001

Líneas 1001–1001; tipo `block`.

```text
/* Set SIFS for OFDM */
```

## 2105. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/rtl8192ee/hw.c:1004

Líneas 1004–1004; tipo `block`.

```text
/* Note Data sheet don't define */
```

## 2106. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/rtl8192ee/hw.c:1011

Líneas 1011–1011; tipo `block`.

```text
/* Set Multicast Address. 2009.01.07. by tynli. */
```

## 2107. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/rtl8192ee/hw.c:1143

Líneas 1143–1143; tipo `block`.

```text
/* write reg 0x350 Bit[26]=1. Enable debug port. */
```

## 2108. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/rtl8192ee/hw.c:1148

Líneas 1148–1148; tipo `block`.

```text
/* Suggested by DD Justin_tsai. */
```

## 2109. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/rtl8192ee/hw.c:1151

Líneas 1151–1153; tipo `block`.

```text
/* read reg 0x350 Bit[25] if 1 : RX hang
	 * read reg 0x350 Bit[24] if 1 : TX hang
	 */
```

## 2110. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/rtl8192ee/hw.c:1173

Líneas 1173–1175; tipo `block`.

```text
/* Revise Note: Follow the document "PCIe RX DMA Hang Reset Flow_v03"
	 * released by SD1 Alan.
	 */
```

## 2111. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/rtl8192ee/hw.c:1177

Líneas 1177–1180; tipo `block`.

```text
/* 1. disable register write lock
	 *	write 0x1C bit[1:0] = 2'h0
	 *	write 0xCC bit[2] = 1'b1
	 */
```

## 2112. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/rtl8192ee/hw.c:1188

Líneas 1188–1191; tipo `block`.

```text
/* 2. Check and pause TRX DMA
	 *	write 0x284 bit[18] = 1'b1
	 *	write 0x301 = 0xFF
	 */
```

## 2113. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/rtl8192ee/hw.c:1194

Líneas 1194–1194; tipo `block`.

```text
/* Already pause before the function for another reason. */
```

## 2114. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/rtl8192ee/hw.c:1206

Líneas 1206–1208; tipo `block`.

```text
/* 3. reset TRX function
		 *	write 0x100 = 0x00
		 */
```

## 2115. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/rtl8192ee/hw.c:1212

Líneas 1212–1214; tipo `block`.

```text
/* 4. Reset PCIe DMA
	 *	write 0x003 bit[0] = 0
	 */
```

## 2116. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/rtl8192ee/hw.c:1219

Líneas 1219–1221; tipo `block`.

```text
/* 5. Enable PCIe DMA
	 *	write 0x003 bit[0] = 1
	 */
```

## 2117. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/rtl8192ee/hw.c:1227

Líneas 1227–1229; tipo `block`.

```text
/* 6. enable TRX function
		 *	write 0x100 = 0xFF
		 */
```

## 2118. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/rtl8192ee/hw.c:1232

Líneas 1232–1235; tipo `block`.

```text
/* We should init LLT & RQPN and
		 * prepare Tx/Rx descrptor address later
		 * because MAC function is reset.
		 */
```

## 2119. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/rtl8192ee/hw.c:1238

Líneas 1238–1240; tipo `block`.

```text
/* 7. Restore PCIe autoload down bit
	 *	write 0xF8 bit[17] = 1'b1
	 */
```

## 2120. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/rtl8192ee/hw.c:1245

Líneas 1245–1249; tipo `block`.

```text
/* In MAC power on state, BB and RF maybe in ON state,
	 * if we release TRx DMA here
	 * it will cause packets to be started to Tx/Rx,
	 * so we release Tx/Rx DMA later.
	 */
```

## 2121. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/rtl8192ee/hw.c:1251

Líneas 1251–1254; tipo `block`.

```text
/* 8. release TRX DMA
		 *	write 0x284 bit[18] = 1'b0
		 *	write 0x301 = 0x00
		 */
```

## 2122. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/rtl8192ee/hw.c:1264

Líneas 1264–1266; tipo `block`.

```text
/* 9. lock system register
	 *	write 0xCC bit[2] = 1'b0
	 */
```

## 2123. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/rtl8192ee/hw.c:1308

Líneas 1308–1308; tipo `block`.

```text
/*for Crystal 40 Mhz setting */
```

## 2124. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/rtl8192ee/hw.c:1313

Líneas 1313–1313; tipo `block`.

```text
/*Forced the antenna b to wifi */
```

## 2125. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/rtl8192ee/hw.c:1334

Líneas 1334–1334; tipo `block`.

```text
/*fw related variable initialize */
```

## 2126. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/rtl8192ee/hw.c:1361

Líneas 1361–1361; tipo `block`.

```text
/*---- Set CCK and OFDM Block "ON"----*/
```

## 2127. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/rtl8192ee/hw.c:1365

Líneas 1365–1367; tipo `block`.

```text
/* Must set this,
	 * otherwise the rx sensitivity will be very pool. Maddest
	 */
```

## 2128. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/rtl8192ee/hw.c:1370

Líneas 1370–1370; tipo `block`.

```text
/*Set Hardware(MAC default setting.)*/
```

## 2129. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/rtl8192ee/hw.c:1414

Líneas 1414–1414; tipo `block`.

```text
/*Fixed LDPC rx hang issue. */
```

## 2130. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/rtl8192ee/hw.c:1488

Líneas 1488–1493; tipo `block`.

```text
/* MSR_INFRA == Link in infrastructure network;
	 * MSR_ADHOC == Link in ad hoc network;
	 * Therefore, check link state is necessary.
	 *
	 * MSR_AP == AP mode; link state is not cared here.
	 */
```

## 2131. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/rtl8192ee/hw.c:1560

Líneas 1560–1560; tipo `block`.

```text
/* don't set REG_EDCA_BE_PARAM here because mac80211 will send pkt when scan */
```

## 2132. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/rtl8192ee/hw.c:1571

Líneas 1571–1571; tipo `block`.

```text
/* rtl_write_dword(rtlpriv, REG_EDCA_BE_PARAM, u4b_ac_param); */
```

## 2133. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/rtl8192ee/hw.c:1603

Líneas 1603–1603; tipo `block`.

```text
/*synchronize_irq(rtlpci->pdev->irq);*/
```

## 2134. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/rtl8192ee/hw.c:1616

Líneas 1616–1616; tipo `block`.

```text
/* Run LPS WL RFOFF flow */
```

## 2135. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/rtl8192ee/hw.c:1619

Líneas 1619–1619; tipo `block`.

```text
/* turn off RF */
```

## 2136. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/rtl8192ee/hw.c:1622

Líneas 1622–1622; tipo `block`.

```text
/* ==== Reset digital sequence   ======  */
```

## 2137. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/rtl8192ee/hw.c:1626

Líneas 1626–1626; tipo `block`.

```text
/* Reset MCU  */
```

## 2138. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/rtl8192ee/hw.c:1630

Líneas 1630–1630; tipo `block`.

```text
/* reset MCU ready status */
```

## 2139. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/rtl8192ee/hw.c:1633

Líneas 1633–1633; tipo `block`.

```text
/* HW card disable configuration. */
```

## 2140. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/rtl8192ee/hw.c:1637

Líneas 1637–1637; tipo `block`.

```text
/* Reset MCU IO Wrapper */
```

## 2141. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/rtl8192ee/hw.c:1643

Líneas 1643–1643; tipo `block`.

```text
/* lock ISO/CLK/Power control register */
```

## 2142. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/rtl8192ee/hw.c:1669

Líneas 1669–1669; tipo `block`.

```text
/* after power off we should do iqk again */
```

## 2143. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/rtl8192ee/hw.c:1695

Líneas 1695–1695; tipo `block`.

```text
/*FIX MERGE */
```

## 2144. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/rtl8192ee/hw.c:1794

Líneas 1794–1794; tipo `block`.

```text
/*YJ,add,120316*/
```

## 2145. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/rtl8192ee/hw.c:1801

Líneas 1801–1801; tipo `block`.

```text
/* 2.4G default value */
```

## 2146. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/rtl8192ee/hw.c:1818

Líneas 1818–1818; tipo `block`.

```text
/*5G default value*/
```

## 2147. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/rtl8192ee/hw.c:1843

Líneas 1843–1843; tipo `block`.

```text
/*2.4G default value*/
```

## 2148. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/rtl8192ee/hw.c:1917

Líneas 1917–1917; tipo `block`.

```text
/*5G default value*/
```

## 2149. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/rtl8192ee/hw.c:2118

Líneas 2118–2118; tipo `block`.

```text
/* set channel plan from efuse */
```

## 2150. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/rtl8192ee/hw.c:2120

Líneas 2120–2120; tipo `block`.

```text
/*tx power*/
```

## 2151. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/rtl8192ee/hw.c:2127

Líneas 2127–2127; tipo `block`.

```text
/*board type*/
```

## 2152. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/rtl8192ee/hw.c:2134

Líneas 2134–2134; tipo `block`.

```text
/* ODM_BOARD_BT */
```

## 2153. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/rtl8192ee/hw.c:2139

Líneas 2139–2139; tipo `block`.

```text
/*parse xtal*/
```

## 2154. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/rtl8192ee/hw.c:2144

Líneas 2144–2144; tipo `block`.

```text
/*antenna diversity*/
```

## 2155. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/rtl8192ee/hw.c:2269

Líneas 2269–2269; tipo `block`.

```text
/*u8 mimo_ps = IEEE80211_SMPS_OFF;*/
```

## 2156. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/rtl8192ee/hw.c:2567

Líneas 2567–2567; tipo `block`.

```text
/* 0:Low, 1:High, 2:From Efuse. */
```

## 2157. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/rtl8192ee/hw.c:2569

Líneas 2569–2569; tipo `block`.

```text
/* 0:Idle, 1:None-SCO, 2:SCO, 3:From Counter. */
```

## 2158. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/rtl8192ee/hw.c:2571

Líneas 2571–2571; tipo `block`.

```text
/* 0:Disable BT control A-MPDU, 1:Enable BT control A-MPDU. */
```

## 2159. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/rtl8192ee/hw.c:2591

Líneas 2591–2591; tipo `block`.

```text
/* Turn on AAP (RCR:bit 0) for promicuous mode. */
```

## 2160. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/rtl8192ee/hw.c:2598

Líneas 2598–2598; tipo `block`.

```text
/* Set BIT0 */
```

## 2161. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/rtl8192ee/hw.c:2600

Líneas 2600–2600; tipo `block`.

```text
/* Clear BIT0 */
```

## 2162. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/rtl8192ee/hw.h:1

Líneas 1–1; tipo `block`.

```text
/* SPDX-License-Identifier: GPL-2.0 */
```

## 2163. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/rtl8192ee/hw.h:2

Líneas 2–2; tipo `block`.

```text
/* Copyright(c) 2009-2014  Realtek Corporation.*/
```

## 2164. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/rtl8192ee/led.c:1

Líneas 1–1; tipo `line`.

```text
// SPDX-License-Identifier: GPL-2.0
```

## 2165. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/rtl8192ee/led.c:2

Líneas 2–2; tipo `block`.

```text
/* Copyright(c) 2009-2014  Realtek Corporation.*/
```

## 2166. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/rtl8192ee/led.h:1

Líneas 1–1; tipo `block`.

```text
/* SPDX-License-Identifier: GPL-2.0 */
```

## 2167. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/rtl8192ee/led.h:2

Líneas 2–2; tipo `block`.

```text
/* Copyright(c) 2009-2014  Realtek Corporation.*/
```

## 2168. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/rtl8192ee/phy.c:1

Líneas 1–1; tipo `line`.

```text
// SPDX-License-Identifier: GPL-2.0
```

## 2169. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/rtl8192ee/phy.c:2

Líneas 2–2; tipo `block`.

```text
/* Copyright(c) 2009-2014  Realtek Corporation.*/
```

## 2170. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/rtl8192ee/phy.c:249

Líneas 249–249; tipo `block`.

```text
/*need efuse define*/
```

## 2171. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/rtl8192ee/phy.c:251

Líneas 251–251; tipo `block`.

```text
/*SupportPlatform */
```

## 2172. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/rtl8192ee/phy.c:329

Líneas 329–329; tipo `block`.

```text
/*RF Content: radio_a_txt*/
```

## 2173. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/rtl8192ee/phy.c:339

Líneas 339–339; tipo `block`.

```text
/*RF Content: radio_b_txt*/
```

## 2174. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/rtl8192ee/phy.c:519

Líneas 519–519; tipo `block`.

```text
/* Get the exact value */
```

## 2175. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/rtl8192ee/phy.c:523

Líneas 523–523; tipo `block`.

```text
/* Change the value to a relative value */
```

## 2176. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/rtl8192ee/phy.c:685

Líneas 685–685; tipo `block`.

```text
/*This line is the start line of branch.*/
```

## 2177. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/rtl8192ee/phy.c:686

Líneas 686–686; tipo `block`.

```text
/* to protect READ_NEXT_PAIR not overrun */
```

## 2178. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/rtl8192ee/phy.c:691

Líneas 691–691; tipo `block`.

```text
/*Discard the following pairs*/
```

## 2179. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/rtl8192ee/phy.c:698

Líneas 698–698; tipo `block`.

```text
/* prevent from for-loop += 2*/
```

## 2180. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/rtl8192ee/phy.c:700

Líneas 700–702; tipo `block`.

```text
/* Configure matched pairs and
					 * skip to end of if-else.
					 */
```

## 2181. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/rtl8192ee/phy.c:729

Líneas 729–729; tipo `block`.

```text
/*This line is the start line of branch.*/
```

## 2182. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/rtl8192ee/phy.c:730

Líneas 730–730; tipo `block`.

```text
/* to protect READ_NEXT_PAIR not overrun */
```

## 2183. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/rtl8192ee/phy.c:735

Líneas 735–735; tipo `block`.

```text
/*Discard the following pairs*/
```

## 2184. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/rtl8192ee/phy.c:743

Líneas 743–743; tipo `block`.

```text
/* prevent from for-loop += 2*/
```

## 2185. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/rtl8192ee/phy.c:745

Líneas 745–747; tipo `block`.

```text
/* Configure matched pairs and
					 * skip to end of if-else.
					 */
```

## 2186. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/rtl8192ee/phy.c:914

Líneas 914–914; tipo `block`.

```text
/*This line is the start line of branch.*/
```

## 2187. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/rtl8192ee/phy.c:915

Líneas 915–915; tipo `block`.

```text
/* to protect READ_NEXT_PAIR not overrun */
```

## 2188. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/rtl8192ee/phy.c:920

Líneas 920–920; tipo `block`.

```text
/*Discard the following pairs*/
```

## 2189. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/rtl8192ee/phy.c:927

Líneas 927–927; tipo `block`.

```text
/* prevent from for-loop += 2*/
```

## 2190. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/rtl8192ee/phy.c:929

Líneas 929–931; tipo `block`.

```text
/* Configure matched pairs and
					 * skip to end of if-else.
					 */
```

## 2191. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/rtl8192ee/phy.c:961

Líneas 961–961; tipo `block`.

```text
/*This line is the start line of branch.*/
```

## 2192. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/rtl8192ee/phy.c:962

Líneas 962–962; tipo `block`.

```text
/* to protect READ_NEXT_PAIR not overrun */
```

## 2193. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/rtl8192ee/phy.c:967

Líneas 967–967; tipo `block`.

```text
/*Discard the following pairs*/
```

## 2194. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/rtl8192ee/phy.c:974

Líneas 974–974; tipo `block`.

```text
/* prevent from for-loop += 2*/
```

## 2195. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/rtl8192ee/phy.c:976

Líneas 976–978; tipo `block`.

```text
/* Configure matched pairs and
					 * skip to end of if-else.
					 */
```

## 2196. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/rtl8192ee/phy.c:1236

Líneas 1236–1236; tipo `block`.

```text
/* OFDM-1T*/
```

## 2197. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/rtl8192ee/phy.c:1241

Líneas 1241–1241; tipo `block`.

```text
/* BW20-1S, BW20-2S */
```

## 2198. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/rtl8192ee/phy.c:1247

Líneas 1247–1247; tipo `block`.

```text
/* BW40-1S, BW40-2S */
```

## 2199. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/rtl8192ee/phy.c:1932

Líneas 1932–1932; tipo `block`.

```text
/* path-A IQK setting */
```

## 2200. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/rtl8192ee/phy.c:1933

Líneas 1933–1933; tipo `block`.

```text
/* PA/PAD controlled by 0x0 */
```

## 2201. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/rtl8192ee/phy.c:1946

Líneas 1946–1946; tipo `block`.

```text
/*LO calibration setting*/
```

## 2202. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/rtl8192ee/phy.c:1949

Líneas 1949–1949; tipo `block`.

```text
/*One shot, path A LOK & IQK*/
```

## 2203. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/rtl8192ee/phy.c:1974

Líneas 1974–1974; tipo `block`.

```text
/* PA/PAD controlled by 0x0 */
```

## 2204. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/rtl8192ee/phy.c:1990

Líneas 1990–1990; tipo `block`.

```text
/* LO calibration setting */
```

## 2205. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/rtl8192ee/phy.c:1993

Líneas 1993–1993; tipo `block`.

```text
/*One shot, path B LOK & IQK*/
```

## 2206. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/rtl8192ee/phy.c:2018

Líneas 2018–2018; tipo `block`.

```text
/*Get TXIMR Setting*/
```

## 2207. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/rtl8192ee/phy.c:2019

Líneas 2019–2019; tipo `block`.

```text
/*Modify RX IQK mode table*/
```

## 2208. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/rtl8192ee/phy.c:2027

Líneas 2027–2027; tipo `block`.

```text
/*PA/PAD control by 0x56, and set = 0x0*/
```

## 2209. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/rtl8192ee/phy.c:2031

Líneas 2031–2031; tipo `block`.

```text
/*enter IQK mode*/
```

## 2210. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/rtl8192ee/phy.c:2034

Líneas 2034–2034; tipo `block`.

```text
/*IQK Setting*/
```

## 2211. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/rtl8192ee/phy.c:2038

Líneas 2038–2038; tipo `block`.

```text
/*path a IQK setting*/
```

## 2212. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/rtl8192ee/phy.c:2047

Líneas 2047–2047; tipo `block`.

```text
/*LO calibration Setting*/
```

## 2213. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/rtl8192ee/phy.c:2050

Líneas 2050–2050; tipo `block`.

```text
/*one shot,path A LOK & iqk*/
```

## 2214. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/rtl8192ee/phy.c:2056

Líneas 2056–2056; tipo `block`.

```text
/* Check failed */
```

## 2215. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/rtl8192ee/phy.c:2066

Líneas 2066–2066; tipo `block`.

```text
/*	PA/PAD controlled by 0x0 */
```

## 2216. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/rtl8192ee/phy.c:2075

Líneas 2075–2075; tipo `block`.

```text
/*RX IQK*/
```

## 2217. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/rtl8192ee/phy.c:2076

Líneas 2076–2076; tipo `block`.

```text
/*Modify RX IQK mode table*/
```

## 2218. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/rtl8192ee/phy.c:2085

Líneas 2085–2085; tipo `block`.

```text
/*PA/PAD control by 0x56, and set = 0x0*/
```

## 2219. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/rtl8192ee/phy.c:2089

Líneas 2089–2089; tipo `block`.

```text
/*enter IQK mode*/
```

## 2220. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/rtl8192ee/phy.c:2092

Líneas 2092–2092; tipo `block`.

```text
/*IQK Setting*/
```

## 2221. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/rtl8192ee/phy.c:2095

Líneas 2095–2095; tipo `block`.

```text
/*path a IQK setting*/
```

## 2222. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/rtl8192ee/phy.c:2104

Líneas 2104–2104; tipo `block`.

```text
/*LO calibration Setting*/
```

## 2223. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/rtl8192ee/phy.c:2106

Líneas 2106–2106; tipo `block`.

```text
/*one shot,path A LOK & iqk*/
```

## 2224. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/rtl8192ee/phy.c:2111

Líneas 2111–2111; tipo `block`.

```text
/*Check failed*/
```

## 2225. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/rtl8192ee/phy.c:2115

Líneas 2115–2115; tipo `block`.

```text
/*PA/PAD controlled by 0x0*/
```

## 2226. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/rtl8192ee/phy.c:2116

Líneas 2116–2116; tipo `block`.

```text
/*leave IQK mode*/
```

## 2227. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/rtl8192ee/phy.c:2119

Líneas 2119–2119; tipo `block`.

```text
/*if Tx is OK, check whether Rx is OK*/
```

## 2228. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/rtl8192ee/phy.c:2134

Líneas 2134–2134; tipo `block`.

```text
/*Get TXIMR Setting*/
```

## 2229. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/rtl8192ee/phy.c:2135

Líneas 2135–2135; tipo `block`.

```text
/*Modify RX IQK mode table*/
```

## 2230. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/rtl8192ee/phy.c:2143

Líneas 2143–2143; tipo `block`.

```text
/*PA/PAD all off*/
```

## 2231. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/rtl8192ee/phy.c:2149

Líneas 2149–2149; tipo `block`.

```text
/*IQK Setting*/
```

## 2232. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/rtl8192ee/phy.c:2153

Líneas 2153–2153; tipo `block`.

```text
/*path a IQK setting*/
```

## 2233. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/rtl8192ee/phy.c:2162

Líneas 2162–2162; tipo `block`.

```text
/*LO calibration Setting*/
```

## 2234. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/rtl8192ee/phy.c:2165

Líneas 2165–2165; tipo `block`.

```text
/*one shot,path A LOK & iqk*/
```

## 2235. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/rtl8192ee/phy.c:2171

Líneas 2171–2171; tipo `block`.

```text
/* Check failed */
```

## 2236. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/rtl8192ee/phy.c:2181

Líneas 2181–2181; tipo `block`.

```text
/*	PA/PAD controlled by 0x0 */
```

## 2237. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/rtl8192ee/phy.c:2190

Líneas 2190–2190; tipo `block`.

```text
/*RX IQK*/
```

## 2238. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/rtl8192ee/phy.c:2191

Líneas 2191–2191; tipo `block`.

```text
/*Modify RX IQK mode table*/
```

## 2239. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/rtl8192ee/phy.c:2199

Líneas 2199–2199; tipo `block`.

```text
/*PA/PAD all off*/
```

## 2240. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/rtl8192ee/phy.c:2203

Líneas 2203–2203; tipo `block`.

```text
/*enter IQK mode*/
```

## 2241. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/rtl8192ee/phy.c:2206

Líneas 2206–2206; tipo `block`.

```text
/*IQK Setting*/
```

## 2242. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/rtl8192ee/phy.c:2209

Líneas 2209–2209; tipo `block`.

```text
/*path b IQK setting*/
```

## 2243. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/rtl8192ee/phy.c:2218

Líneas 2218–2218; tipo `block`.

```text
/*LO calibration Setting*/
```

## 2244. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/rtl8192ee/phy.c:2220

Líneas 2220–2220; tipo `block`.

```text
/*one shot,path A LOK & iqk*/
```

## 2245. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/rtl8192ee/phy.c:2225

Líneas 2225–2225; tipo `block`.

```text
/*Check failed*/
```

## 2246. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/rtl8192ee/phy.c:2229

Líneas 2229–2229; tipo `block`.

```text
/*PA/PAD controlled by 0x0*/
```

## 2247. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/rtl8192ee/phy.c:2230

Líneas 2230–2230; tipo `block`.

```text
/*leave IQK mode*/
```

## 2248. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/rtl8192ee/phy.c:2233

Líneas 2233–2233; tipo `block`.

```text
/*if Tx is OK, check whether Rx is OK*/
```

## 2249. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/rtl8192ee/phy.c:2405

Líneas 2405–2405; tipo `block`.

```text
/*, is2t = true*/
```

## 2250. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/rtl8192ee/phy.c:2455

Líneas 2455–2455; tipo `block`.

```text
/*path A TX OK*/
```

## 2251. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/rtl8192ee/phy.c:2459

Líneas 2459–2459; tipo `block`.

```text
/*path A RX OK*/
```

## 2252. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/rtl8192ee/phy.c:2463

Líneas 2463–2463; tipo `block`.

```text
/*path B TX OK*/
```

## 2253. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/rtl8192ee/phy.c:2467

Líneas 2467–2467; tipo `block`.

```text
/*path B RX OK*/
```

## 2254. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/rtl8192ee/phy.c:2513

Líneas 2513–2513; tipo `block`.

```text
/*BB setting*/
```

## 2255. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/rtl8192ee/phy.c:2526

Líneas 2526–2526; tipo `block`.

```text
/* Page B init*/
```

## 2256. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/rtl8192ee/phy.c:2527

Líneas 2527–2527; tipo `block`.

```text
/* IQ calibration setting*/
```

## 2257. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/rtl8192ee/phy.c:2578

Líneas 2578–2578; tipo `block`.

```text
/* Turn Path B ADDA on */
```

## 2258. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/rtl8192ee/phy.c:2581

Líneas 2581–2581; tipo `block`.

```text
/* IQ calibration setting */
```

## 2259. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/rtl8192ee/phy.c:2630

Líneas 2630–2630; tipo `block`.

```text
/* Back to BB mode, load original value */
```

## 2260. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/rtl8192ee/phy.c:2636

Líneas 2636–2636; tipo `block`.

```text
/* Reload ADDA power saving parameters */
```

## 2261. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/rtl8192ee/phy.c:2641

Líneas 2641–2641; tipo `block`.

```text
/* Reload MAC parameters */
```

## 2262. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/rtl8192ee/phy.c:2649

Líneas 2649–2649; tipo `block`.

```text
/* Restore RX initial gain */
```

## 2263. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/rtl8192ee/phy.c:2657

Líneas 2657–2657; tipo `block`.

```text
/* load 0xe30 IQC default value */
```

## 2264. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/rtl8192ee/phy.c:2735

Líneas 2735–2738; tipo `block`.

```text
/* We use the RF definition of MAIN and AUX,
		 * left antenna and right antenna repectively.
		 * Default output at AUX.
		 */
```

## 2265. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/rtl8192ee/phy.c:2895

Líneas 2895–2895; tipo `block`.

```text
/* To Fix BSOD when final_candidate is 0xff */
```

## 2266. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/rtl8192ee/phy.c:2993

Líneas 2993–2993; tipo `block`.

```text
/* 8192eebt */
```

## 2267. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/rtl8192ee/phy.c:3016

Líneas 3016–3016; tipo `block`.

```text
/*rtl_write_byte(rtlpriv, REG_APSD_CTRL, 0x00);*/
```

## 2268. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/rtl8192ee/phy.h:1

Líneas 1–1; tipo `block`.

```text
/* SPDX-License-Identifier: GPL-2.0 */
```

## 2269. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/rtl8192ee/phy.h:2

Líneas 2–2; tipo `block`.

```text
/* Copyright(c) 2009-2014  Realtek Corporation.*/
```

## 2270. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/rtl8192ee/phy.h:7

Líneas 7–9; tipo `block`.

```text
/* MAX_TX_COUNT must always set to 4, otherwise read efuse table sequence
 * will be wrong.
 */
```

## 2271. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/rtl8192ee/pwrseq.c:1

Líneas 1–1; tipo `line`.

```text
// SPDX-License-Identifier: GPL-2.0
```

## 2272. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/rtl8192ee/pwrseq.c:2

Líneas 2–2; tipo `block`.

```text
/* Copyright(c) 2009-2014  Realtek Corporation.*/
```

## 2273. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/rtl8192ee/pwrseq.c:6

Líneas 6–6; tipo `block`.

```text
/* drivers should parse below arrays and do the corresponding actions */
```

## 2274. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/rtl8192ee/pwrseq.c:8

Líneas 8–8; tipo `block`.

```text
/*3 Power on  Array*/
```

## 2275. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/rtl8192ee/pwrseq.c:16

Líneas 16–16; tipo `block`.

```text
/*3Radio off GPIO Array */
```

## 2276. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/rtl8192ee/pwrseq.c:24

Líneas 24–24; tipo `block`.

```text
/*3Card Disable Array*/
```

## 2277. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/rtl8192ee/pwrseq.c:34

Líneas 34–34; tipo `block`.

```text
/*3 Card Enable Array*/
```

## 2278. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/rtl8192ee/pwrseq.c:44

Líneas 44–44; tipo `block`.

```text
/*3Suspend Array*/
```

## 2279. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/rtl8192ee/pwrseq.c:54

Líneas 54–54; tipo `block`.

```text
/*3 Resume Array*/
```

## 2280. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/rtl8192ee/pwrseq.c:64

Líneas 64–64; tipo `block`.

```text
/*3HWPDN Array*/
```

## 2281. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/rtl8192ee/pwrseq.c:74

Líneas 74–74; tipo `block`.

```text
/*3 Enter LPS */
```

## 2282. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/rtl8192ee/pwrseq.c:78

Líneas 78–78; tipo `block`.

```text
/*FW behavior*/
```

## 2283. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/rtl8192ee/pwrseq.c:83

Líneas 83–83; tipo `block`.

```text
/*3 Leave LPS */
```

## 2284. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/rtl8192ee/pwrseq.c:87

Líneas 87–87; tipo `block`.

```text
/*FW behavior*/
```

## 2285. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/rtl8192ee/pwrseq.h:1

Líneas 1–1; tipo `block`.

```text
/* SPDX-License-Identifier: GPL-2.0 */
```

## 2286. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/rtl8192ee/pwrseq.h:2

Líneas 2–2; tipo `block`.

```text
/* Copyright(c) 2009-2014  Realtek Corporation.*/
```

## 2287. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/rtl8192ee/pwrseq.h:8

Líneas 8–29; tipo `block`.

```text
/**
 *	Check document WM-20110607-Paul-RTL8192E_Power_Architecture-R02.vsd
 *	There are 6 HW Power States:
 *	0: POFF--Power Off
 *	1: PDN--Power Down
 *	2: CARDEMU--Card Emulation
 *	3: ACT--Active Mode
 *	4: LPS--Low Power State
 *	5: SUS--Suspend
 *
 *	The transision from different states are defined below
 *	TRANS_CARDEMU_TO_ACT
 *	TRANS_ACT_TO_CARDEMU
 *	TRANS_CARDEMU_TO_SUS
 *	TRANS_SUS_TO_CARDEMU
 *	TRANS_CARDEMU_TO_PDN
 *	TRANS_ACT_TO_LPS
 *	TRANS_LPS_TO_ACT
 *
 *	TRANS_END
 *	PWR SEQ Version: rtl8192E_PwrSeq_V09.h
 */
```

## 2288. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/rtl8192ee/pwrseq.h:42

Líneas 42–42; tipo `block`.

```text
/* format */
```

## 2289. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/rtl8192ee/pwrseq.h:43

Líneas 43–43; tipo `block`.

```text
/* comments here */
```

## 2290. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/rtl8192ee/pwrseq.h:44

Líneas 44–44; tipo `block`.

```text
/* { offset, cut_msk, fab_msk|interface_msk, base|cmd, msk, value },*/
```

## 2291. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/rtl8192ee/pwrseq.h:45

Líneas 45–45; tipo `block`.

```text
/* disable HWPDN 0x04[15]=0*/
```

## 2292. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/rtl8192ee/pwrseq.h:48

Líneas 48–48; tipo `block`.

```text
/* disable SW LPS 0x04[10]=0*/
```

## 2293. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/rtl8192ee/pwrseq.h:51

Líneas 51–51; tipo `block`.

```text
/* disable WL suspend*/
```

## 2294. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/rtl8192ee/pwrseq.h:54

Líneas 54–54; tipo `block`.

```text
/* wait till 0x04[17] = 1    power ready*/
```

## 2295. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/rtl8192ee/pwrseq.h:57

Líneas 57–57; tipo `block`.

```text
/* release WLON reset  0x04[16]=1*/
```

## 2296. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/rtl8192ee/pwrseq.h:60

Líneas 60–60; tipo `block`.

```text
/* polling until return 0*/
```

## 2297. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/rtl8192ee/pwrseq.h:63

Líneas 63–63; tipo `block`.

```text
/**/
```

## 2298. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/rtl8192ee/pwrseq.h:68

Líneas 68–68; tipo `block`.

```text
/* format */
```

## 2299. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/rtl8192ee/pwrseq.h:69

Líneas 69–69; tipo `block`.

```text
/* comments here */
```

## 2300. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/rtl8192ee/pwrseq.h:70

Líneas 70–70; tipo `block`.

```text
/* { offset, cut_msk, fab_msk|interface_msk, base|cmd, msk, value },*/
```

## 2301. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/rtl8192ee/pwrseq.h:71

Líneas 71–71; tipo `block`.

```text
/*0x1F[7:0] = 0 turn off RF*/
```

## 2302. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/rtl8192ee/pwrseq.h:74

Líneas 74–74; tipo `block`.

```text
/*0x4C[23]=0x4E[7]=0, switch DPDT_SEL_P output from register 0x65[2] */
```

## 2303. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/rtl8192ee/pwrseq.h:77

Líneas 77–77; tipo `block`.

```text
/*0x04[9] = 1 turn off MAC by HW state machine*/
```

## 2304. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/rtl8192ee/pwrseq.h:80

Líneas 80–80; tipo `block`.

```text
/*wait till 0x04[9] = 0 polling until return 0 to disable*/
```

## 2305. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/rtl8192ee/pwrseq.h:85

Líneas 85–85; tipo `block`.

```text
/* format */
```

## 2306. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/rtl8192ee/pwrseq.h:86

Líneas 86–86; tipo `block`.

```text
/* comments here */
```

## 2307. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/rtl8192ee/pwrseq.h:87

Líneas 87–87; tipo `block`.

```text
/* { offset, cut_msk, fab_msk|interface_msk, base|cmd, msk, value },*/
```

## 2308. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/rtl8192ee/pwrseq.h:88

Líneas 88–88; tipo `block`.

```text
/*0x04[12:11] = 2b'11 enable WL suspend for PCIe*/
```

## 2309. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/rtl8192ee/pwrseq.h:91

Líneas 91–91; tipo `block`.

```text
/*0x04[12:11] = 2b'01 enable WL suspend*/
```

## 2310. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/rtl8192ee/pwrseq.h:95

Líneas 95–95; tipo `block`.

```text
/*0x04[12:11] = 2b'11 enable WL suspend for PCIe*/
```

## 2311. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/rtl8192ee/pwrseq.h:98

Líneas 98–98; tipo `block`.

```text
/*Set SDIO suspend local register*/
```

## 2312. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/rtl8192ee/pwrseq.h:101

Líneas 101–101; tipo `block`.

```text
/*wait power state to suspend*/
```

## 2313. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/rtl8192ee/pwrseq.h:106

Líneas 106–106; tipo `block`.

```text
/* format */
```

## 2314. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/rtl8192ee/pwrseq.h:107

Líneas 107–107; tipo `block`.

```text
/* comments here */
```

## 2315. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/rtl8192ee/pwrseq.h:108

Líneas 108–108; tipo `block`.

```text
/* { offset, cut_msk, fab_msk|interface_msk, base|cmd, msk, value },*/
```

## 2316. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/rtl8192ee/pwrseq.h:109

Líneas 109–109; tipo `block`.

```text
/*Set SDIO suspend local register*/
```

## 2317. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/rtl8192ee/pwrseq.h:112

Líneas 112–112; tipo `block`.

```text
/*wait power state to suspend*/
```

## 2318. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/rtl8192ee/pwrseq.h:115

Líneas 115–115; tipo `block`.

```text
/*0x04[12:11] = 2b'00 disable WL suspend*/
```

## 2319. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/rtl8192ee/pwrseq.h:120

Líneas 120–120; tipo `block`.

```text
/* format */
```

## 2320. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/rtl8192ee/pwrseq.h:121

Líneas 121–121; tipo `block`.

```text
/* comments here */
```

## 2321. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/rtl8192ee/pwrseq.h:122

Líneas 122–122; tipo `block`.

```text
/* { offset, cut_msk, fab_msk|interface_msk, base|cmd, msk, value },*/
```

## 2322. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/rtl8192ee/pwrseq.h:123

Líneas 123–123; tipo `block`.

```text
/*0x07=0x20 , SOP option to disable BG/MB*/
```

## 2323. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/rtl8192ee/pwrseq.h:126

Líneas 126–126; tipo `block`.

```text
/*Unlock small LDO Register*/
```

## 2324. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/rtl8192ee/pwrseq.h:129

Líneas 129–129; tipo `block`.

```text
/*Disable small LDO*/
```

## 2325. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/rtl8192ee/pwrseq.h:132

Líneas 132–132; tipo `block`.

```text
/*0x04[12:11] = 2b'01 enable WL suspend*/
```

## 2326. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/rtl8192ee/pwrseq.h:136

Líneas 136–136; tipo `block`.

```text
/*0x04[10] = 1, enable SW LPS*/
```

## 2327. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/rtl8192ee/pwrseq.h:139

Líneas 139–139; tipo `block`.

```text
/*Set SDIO suspend local register*/
```

## 2328. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/rtl8192ee/pwrseq.h:142

Líneas 142–142; tipo `block`.

```text
/*wait power state to suspend*/
```

## 2329. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/rtl8192ee/pwrseq.h:147

Líneas 147–147; tipo `block`.

```text
/* format */
```

## 2330. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/rtl8192ee/pwrseq.h:148

Líneas 148–148; tipo `block`.

```text
/* comments here */
```

## 2331. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/rtl8192ee/pwrseq.h:149

Líneas 149–149; tipo `block`.

```text
/* { offset, cut_msk, fab_msk|interface_msk, base|cmd, msk, value },*/
```

## 2332. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/rtl8192ee/pwrseq.h:150

Líneas 150–150; tipo `block`.

```text
/*Set SDIO suspend local register*/
```

## 2333. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/rtl8192ee/pwrseq.h:153

Líneas 153–153; tipo `block`.

```text
/*wait power state to suspend*/
```

## 2334. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/rtl8192ee/pwrseq.h:156

Líneas 156–156; tipo `block`.

```text
/*Enable small LDO*/
```

## 2335. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/rtl8192ee/pwrseq.h:159

Líneas 159–159; tipo `block`.

```text
/*Lock small LDO Register*/
```

## 2336. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/rtl8192ee/pwrseq.h:162

Líneas 162–162; tipo `block`.

```text
/*0x04[12:11] = 2b'00 disable WL suspend*/
```

## 2337. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/rtl8192ee/pwrseq.h:167

Líneas 167–167; tipo `block`.

```text
/* format */
```

## 2338. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/rtl8192ee/pwrseq.h:168

Líneas 168–168; tipo `block`.

```text
/* comments here */
```

## 2339. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/rtl8192ee/pwrseq.h:169

Líneas 169–169; tipo `block`.

```text
/* { offset, cut_msk, fab_msk|interface_msk, base|cmd, msk, value },*/
```

## 2340. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/rtl8192ee/pwrseq.h:170

Líneas 170–170; tipo `block`.

```text
/* 0x04[16] = 0*/
```

## 2341. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/rtl8192ee/pwrseq.h:173

Líneas 173–173; tipo `block`.

```text
/* 0x04[15] = 1*/
```

## 2342. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/rtl8192ee/pwrseq.h:178

Líneas 178–178; tipo `block`.

```text
/* format */
```

## 2343. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/rtl8192ee/pwrseq.h:179

Líneas 179–179; tipo `block`.

```text
/* comments here */
```

## 2344. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/rtl8192ee/pwrseq.h:180

Líneas 180–180; tipo `block`.

```text
/* { offset, cut_msk, fab_msk|interface_msk, base|cmd, msk, value },*/
```

## 2345. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/rtl8192ee/pwrseq.h:181

Líneas 181–181; tipo `block`.

```text
/* 0x04[15] = 0*/
```

## 2346. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/rtl8192ee/pwrseq.h:186

Líneas 186–186; tipo `block`.

```text
/* format */
```

## 2347. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/rtl8192ee/pwrseq.h:187

Líneas 187–187; tipo `block`.

```text
/* comments here */
```

## 2348. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/rtl8192ee/pwrseq.h:188

Líneas 188–188; tipo `block`.

```text
/* { offset, cut_msk, fab_msk|interface_msk, base|cmd, msk, value },*/
```

## 2349. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/rtl8192ee/pwrseq.h:189

Líneas 189–189; tipo `block`.

```text
/*PCIe DMA stop*/
```

## 2350. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/rtl8192ee/pwrseq.h:192

Líneas 192–192; tipo `block`.

```text
/*Tx Pause*/
```

## 2351. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/rtl8192ee/pwrseq.h:195

Líneas 195–195; tipo `block`.

```text
/*Should be zero if no packet is transmitting*/
```

## 2352. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/rtl8192ee/pwrseq.h:198

Líneas 198–198; tipo `block`.

```text
/*Should be zero if no packet is transmitting*/
```

## 2353. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/rtl8192ee/pwrseq.h:201

Líneas 201–201; tipo `block`.

```text
/*Should be zero if no packet is transmitting*/
```

## 2354. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/rtl8192ee/pwrseq.h:204

Líneas 204–204; tipo `block`.

```text
/*Should be zero if no packet is transmitting*/
```

## 2355. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/rtl8192ee/pwrseq.h:207

Líneas 207–207; tipo `block`.

```text
/*CCK and OFDM are disabled,and clock are gated*/
```

## 2356. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/rtl8192ee/pwrseq.h:210

Líneas 210–210; tipo `block`.

```text
/*Delay 1us*/
```

## 2357. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/rtl8192ee/pwrseq.h:213

Líneas 213–213; tipo `block`.

```text
/*Whole BB is reset*/
```

## 2358. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/rtl8192ee/pwrseq.h:216

Líneas 216–216; tipo `block`.

```text
/*Reset MAC TRX*/
```

## 2359. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/rtl8192ee/pwrseq.h:219

Líneas 219–219; tipo `block`.

```text
/*check if removed later*/
```

## 2360. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/rtl8192ee/pwrseq.h:222

Líneas 222–222; tipo `block`.

```text
/*When driver enter Sus/ Disable, enable LOP for BT*/
```

## 2361. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/rtl8192ee/pwrseq.h:225

Líneas 225–225; tipo `block`.

```text
/*Respond TxOK to scheduler*/
```

## 2362. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/rtl8192ee/pwrseq.h:230

Líneas 230–230; tipo `block`.

```text
/* format */
```

## 2363. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/rtl8192ee/pwrseq.h:231

Líneas 231–231; tipo `block`.

```text
/* comments here */
```

## 2364. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/rtl8192ee/pwrseq.h:232

Líneas 232–232; tipo `block`.

```text
/* { offset, cut_msk, fab_msk|interface_msk, base|cmd, msk, value },*/
```

## 2365. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/rtl8192ee/pwrseq.h:233

Líneas 233–233; tipo `block`.

```text
/*SDIO RPWM, For Repeatly In and out, Taggle bit should be changed*/
```

## 2366. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/rtl8192ee/pwrseq.h:236

Líneas 236–236; tipo `block`.

```text
/*USB RPWM*/
```

## 2367. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/rtl8192ee/pwrseq.h:239

Líneas 239–239; tipo `block`.

```text
/*PCIe RPWM*/
```

## 2368. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/rtl8192ee/pwrseq.h:242

Líneas 242–242; tipo `block`.

```text
/*Delay*/
```

## 2369. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/rtl8192ee/pwrseq.h:245

Líneas 245–245; tipo `block`.

```text
/*0x08[4] = 0 switch TSF to 40M*/
```

## 2370. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/rtl8192ee/pwrseq.h:248

Líneas 248–248; tipo `block`.

```text
/*Polling 0x109[7]=0  TSF in 40M*/
```

## 2371. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/rtl8192ee/pwrseq.h:251

Líneas 251–251; tipo `block`.

```text
/*0x101[1] = 1*/
```

## 2372. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/rtl8192ee/pwrseq.h:254

Líneas 254–254; tipo `block`.

```text
/*0x100[7:0] = 0xFF  enable WMAC TRX*/
```

## 2373. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/rtl8192ee/pwrseq.h:257

Líneas 257–257; tipo `block`.

```text
/* 0x02[1:0] = 2b'11 enable BB macro*/
```

## 2374. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/rtl8192ee/pwrseq.h:260

Líneas 260–260; tipo `block`.

```text
/*0x522 = 0*/
```

## 2375. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/rtl8192ee/pwrseq.h:263

Líneas 263–263; tipo `block`.

```text
/*Clear ISR*/
```

## 2376. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/rtl8192ee/pwrseq.h:268

Líneas 268–268; tipo `block`.

```text
/* format */
```

## 2377. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/rtl8192ee/pwrseq.h:269

Líneas 269–269; tipo `block`.

```text
/* comments here */
```

## 2378. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/rtl8192ee/pwrseq.h:270

Líneas 270–270; tipo `block`.

```text
/* { offset, cut_msk, fab_msk|interface_msk, base|cmd, msk, value },*/
```

## 2379. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/rtl8192ee/pwrseq.h:307

Líneas 307–307; tipo `block`.

```text
/* RTL8192EE Power Configuration CMDs for PCIe interface */
```

## 2380. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/rtl8192ee/reg.h:1

Líneas 1–1; tipo `block`.

```text
/* SPDX-License-Identifier: GPL-2.0 */
```

## 2381. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/rtl8192ee/reg.h:2

Líneas 2–2; tipo `block`.

```text
/* Copyright(c) 2009-2014  Realtek Corporation.*/
```

## 2382. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/rtl8192ee/reg.h:106

Líneas 106–111; tipo `block`.

```text
/*-----------------------------------------------------
 *
 *	0x0200h ~ 0x027Fh	TXDMA Configuration
 *
 *-----------------------------------------------------
 */
```

## 2383. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/rtl8192ee/reg.h:121

Líneas 121–126; tipo `block`.

```text
/*-----------------------------------------------------
 *
 *	0x0280h ~ 0x02FFh	RXDMA Configuration
 *
 *-----------------------------------------------------
 */
```

## 2384. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/rtl8192ee/reg.h:137

Líneas 137–142; tipo `block`.

```text
/*-----------------------------------------------------
 *
 *	0x0300h ~ 0x03FFh	PCIe
 *
 *-----------------------------------------------------
 */
```

## 2385. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/rtl8192ee/reg.h:175

Líneas 175–175; tipo `block`.

```text
/*Read Write Point*/
```

## 2386. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/rtl8192ee/reg.h:205

Líneas 205–211; tipo `block`.

```text
/* spec version 11
 *-----------------------------------------------------
 *
 *	0x0400h ~ 0x047Fh	Protocol Configuration
 *
 *-----------------------------------------------------
 */
```

## 2387. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/rtl8192ee/reg.h:256

Líneas 256–261; tipo `block`.

```text
/*-----------------------------------------------------
 *
 *	0x0500h ~ 0x05FFh	EDCA Configuration
 *
 *-----------------------------------------------------
 */
```

## 2388. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/rtl8192ee/reg.h:300

Líneas 300–305; tipo `block`.

```text
/*-----------------------------------------------------
 *
 *	0x0600h ~ 0x07FFh	WMAC Configuration
 *
 *-----------------------------------------------------
 */
```

## 2389. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/rtl8192ee/reg.h:329

Líneas 329–329; tipo `block`.

```text
/* Security*/
```

## 2390. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/rtl8192ee/reg.h:336

Líneas 336–336; tipo `block`.

```text
/* Power*/
```

## 2391. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/rtl8192ee/reg.h:352

Líneas 352–352; tipo `block`.

```text
/* Hardware Port 2*/
```

## 2392. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/rtl8192ee/reg.h:520

Líneas 520–522; tipo `block`.

```text
/*********************************************
*       8192EE IMR/ISR bits
**********************************************/
```

## 2393. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/rtl8192ee/reg.h:524

Líneas 524–524; tipo `block`.

```text
/* IMR DW0(0x0060-0063) Bit 0-31 */
```

## 2394. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/rtl8192ee/reg.h:550

Líneas 550–550; tipo `block`.

```text
/* IMR DW1(0x00B4-00B7) Bit 0-31 */
```

## 2395. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/rtl8192ee/reg.h:1316

Líneas 1316–1316; tipo `block`.

```text
/* PageB(0xB00) */
```

## 2396. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/rtl8192ee/reg.h:1362

Líneas 1362–1362; tipo `block`.

```text
/*Page C*/
```

## 2397. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/rtl8192ee/reg.h:2199

Líneas 2199–2199; tipo `block`.

```text
/* WOL bit information */
```

## 2398. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/rtl8192ee/rf.c:1

Líneas 1–1; tipo `line`.

```text
// SPDX-License-Identifier: GPL-2.0
```

## 2399. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/rtl8192ee/rf.c:2

Líneas 2–2; tipo `block`.

```text
/* Copyright(c) 2009-2014  Realtek Corporation.*/
```

## 2400. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/rtl8192ee/rf.h:1

Líneas 1–1; tipo `block`.

```text
/* SPDX-License-Identifier: GPL-2.0 */
```

## 2401. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/rtl8192ee/rf.h:2

Líneas 2–2; tipo `block`.

```text
/* Copyright(c) 2009-2014  Realtek Corporation.*/
```

## 2402. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/rtl8192ee/sw.c:1

Líneas 1–1; tipo `line`.

```text
// SPDX-License-Identifier: GPL-2.0
```

## 2403. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/rtl8192ee/sw.c:2

Líneas 2–2; tipo `block`.

```text
/* Copyright(c) 2009-2014  Realtek Corporation.*/
```

## 2404. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/rtl8192ee/sw.c:27

Líneas 27–27; tipo `block`.

```text
/*close ASPM for AMD defaultly */
```

## 2405. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/rtl8192ee/sw.c:30

Líneas 30–38; tipo `block`.

```text
/**
	 * ASPM PS mode.
	 * 0 - Disable ASPM,
	 * 1 - Enable ASPM without Clock Req,
	 * 2 - Enable ASPM with Clock Req,
	 * 3 - Alwyas Enable ASPM with Clock Req,
	 * 4 - Always Enable ASPM without Clock Req.
	 * set defult to RTL8192CE:3 RTL8192E:2
	 */
```

## 2406. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/rtl8192ee/sw.c:41

Líneas 41–41; tipo `block`.

```text
/*Setting for PCI-E device */
```

## 2407. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/rtl8192ee/sw.c:44

Líneas 44–44; tipo `block`.

```text
/*Setting for PCI-E bridge */
```

## 2408. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/rtl8192ee/sw.c:47

Líneas 47–54; tipo `block`.

```text
/**
	 * In Hw/Sw Radio Off situation.
	 * 0 - Default,
	 * 1 - From ASPM setting without low Mac Pwr,
	 * 2 - From ASPM setting with low Mac Pwr,
	 * 3 - Bus D3
	 * set default to RTL8192CE:0 RTL8192SE:2
	 */
```

## 2409. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/rtl8192ee/sw.c:57

Líneas 57–63; tipo `block`.

```text
/**
	 * This setting works for those device with
	 * backdoor ASPM setting such as EPHY setting.
	 * 0 - Not support ASPM,
	 * 1 - Support ASPM,
	 * 2 - According to chipset.
	 */
```

## 2410. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/rtl8192ee/sw.c:83

Líneas 83–83; tipo `block`.

```text
/*just 2.4G band*/
```

## 2411. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/rtl8192ee/sw.c:114

Líneas 114–114; tipo `block`.

```text
/* for LPS & IPS */
```

## 2412. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/rtl8192ee/sw.c:123

Líneas 123–125; tipo `block`.

```text
/* for ASPM, you can close aspm through
	 * set const_support_pciaspm = 0
	 */
```

## 2413. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/rtl8192ee/sw.c:135

Líneas 135–135; tipo `block`.

```text
/* for early mode */
```

## 2414. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/rtl8192ee/sw.c:138

Líneas 138–138; tipo `block`.

```text
/*low power */
```

## 2415. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/rtl8192ee/sw.c:141

Líneas 141–141; tipo `block`.

```text
/* for firmware buf */
```

## 2416. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/rtl8192ee/sw.c:148

Líneas 148–148; tipo `block`.

```text
/* request fw */
```

## 2417. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/rtl8192ee/sw.c:176

Líneas 176–176; tipo `block`.

```text
/* get bt coexist status */
```

## 2418. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/rtl8192ee/sw.c:186

Líneas 186–186; tipo `block`.

```text
/*need check*/
```

## 2419. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/rtl8192ee/table.c:1

Líneas 1–1; tipo `line`.

```text
// SPDX-License-Identifier: GPL-2.0
```

## 2420. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/rtl8192ee/table.c:2

Líneas 2–2; tipo `block`.

```text
/* Copyright(c) 2009-2014  Realtek Corporation.*/
```

## 2421. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/rtl8192ee/table.h:1

Líneas 1–1; tipo `block`.

```text
/* SPDX-License-Identifier: GPL-2.0 */
```

## 2422. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/rtl8192ee/table.h:2

Líneas 2–2; tipo `block`.

```text
/* Copyright(c) 2009-2014  Realtek Corporation.*/
```

## 2423. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/rtl8192ee/trx.c:1

Líneas 1–1; tipo `line`.

```text
// SPDX-License-Identifier: GPL-2.0
```

## 2424. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/rtl8192ee/trx.c:2

Líneas 2–2; tipo `block`.

```text
/* Copyright(c) 2009-2014  Realtek Corporation.*/
```

## 2425. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/rtl8192ee/trx.c:44

Líneas 44–44; tipo `block`.

```text
/* Record it for next packet processing */
```

## 2426. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/rtl8192ee/trx.c:54

Líneas 54–54; tipo `block`.

```text
/* CCK Driver info Structure is not the same as OFDM packet. */
```

## 2427. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/rtl8192ee/trx.c:57

Líneas 57–60; tipo `block`.

```text
/* (1)Hardware does not provide RSSI for CCK
		 * (2)PWDB, Average PWDB cacluated by
		 * hardware (for rate adaptive)
		 */
```

## 2428. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/rtl8192ee/trx.c:67

Líneas 67–67; tipo `block`.

```text
/*VGA_idx = 27~2*/
```

## 2429. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/rtl8192ee/trx.c:73

Líneas 73–73; tipo `block`.

```text
/*VGA_idx = 2~0*/
```

## 2430. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/rtl8192ee/trx.c:76

Líneas 76–76; tipo `block`.

```text
/*VGA_idx = 7~5*/
```

## 2431. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/rtl8192ee/trx.c:79

Líneas 79–79; tipo `block`.

```text
/*VGA_idx = 7~4*/
```

## 2432. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/rtl8192ee/trx.c:82

Líneas 82–82; tipo `block`.

```text
/*VGA_idx = 7~0*/
```

## 2433. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/rtl8192ee/trx.c:85

Líneas 85–85; tipo `block`.

```text
/*VGA_idx = 5~0*/
```

## 2434. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/rtl8192ee/trx.c:118

Líneas 118–118; tipo `block`.

```text
/* (3) Get Signal Quality (EVM) */
```

## 2435. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/rtl8192ee/trx.c:139

Líneas 139–139; tipo `block`.

```text
/* (1)Get RSSI for HT rate */
```

## 2436. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/rtl8192ee/trx.c:141

Líneas 141–141; tipo `block`.

```text
/* we will judge RF RX path now. */
```

## 2437. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/rtl8192ee/trx.c:149

Líneas 149–149; tipo `block`.

```text
/* Translate DBM to percentage. */
```

## 2438. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/rtl8192ee/trx.c:156

Líneas 156–158; tipo `block`.

```text
/* (2)PWDB, Average PWDB cacluated by
		 * hardware (for rate adaptive)
		 */
```

## 2439. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/rtl8192ee/trx.c:168

Líneas 168–168; tipo `block`.

```text
/* (3)EVM of HT rate */
```

## 2440. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/rtl8192ee/trx.c:180

Líneas 180–182; tipo `block`.

```text
/* Fill value in RFD, Get the first
				 * spatial stream only
				 */
```

## 2441. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/rtl8192ee/trx.c:203

Líneas 203–205; tipo `block`.

```text
/* UI BSS List signal strength(in percentage),
	 * make it good looking, from 0~100.
	 */
```

## 2442. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/rtl8192ee/trx.c:386

Líneas 386–393; tipo `block`.

```text
/* hw will set status->decrypted true, if it finds the
	 * frame is open data frame or mgmt frame.
	 * So hw will not decryption robust managment frame
	 * for IEEE80211w but still set status->decrypted
	 * true, so here we should set it back to undecrypted
	 * for IEEE80211w frame, and mac80211 sw will help
	 * to decrypt it
	 */
```

## 2443. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/rtl8192ee/trx.c:402

Líneas 402–406; tipo `block`.

```text
/* rate_idx: index of data rate into band's
	 * supported rates or MCS index if HT rates
	 * are use (RX_FLAG_HT)
	 * Notice: this is diff with windows define
	 */
```

## 2444. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/rtl8192ee/trx.c:428

Líneas 428–428; tipo `block`.

```text
/*in Windows, this == Rx_92EE_Interrupt*/
```

## 2445. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/rtl8192ee/trx.c:560

Líneas 560–560; tipo `block`.

```text
/*tx desc size*/
```

## 2446. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/rtl8192ee/trx.c:594

Líneas 594–594; tipo `block`.

```text
/* tx desc addr */
```

## 2447. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/rtl8192ee/trx.c:598

Líneas 598–598; tipo `block`.

```text
/* Reset */
```

## 2448. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/rtl8192ee/trx.c:610

Líneas 610–610; tipo `block`.

```text
/* Clear all status */
```

## 2449. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/rtl8192ee/trx.c:615

Líneas 615–615; tipo `block`.

```text
/* This if needs braces */
```

## 2450. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/rtl8192ee/trx.c:629

Líneas 629–629; tipo `block`.

```text
/* don't using extendsion mode. */
```

## 2451. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/rtl8192ee/trx.c:673

Líneas 673–673; tipo `block`.

```text
/* reserve 8 byte for AMPDU early mode */
```

## 2452. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/rtl8192ee/trx.c:791

Líneas 791–791; tipo `block`.

```text
/*set_tx_desc_pwr_status(pdesc, pwr_status);*/
```

## 2453. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/rtl8192ee/trx.c:792

Líneas 792–792; tipo `block`.

```text
/* Set TxRate and RTSRate in TxDesc  */
```

## 2454. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/rtl8192ee/trx.c:793

Líneas 793–793; tipo `block`.

```text
/* This prevent Tx initial rate of new-coming packets */
```

## 2455. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/rtl8192ee/trx.c:794

Líneas 794–794; tipo `block`.

```text
/* from being overwritten by retried  packet rate.*/
```

## 2456. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/rtl8192ee/trx.c:796

Líneas 796–796; tipo `block`.

```text
/*set_tx_desc_rts_rate(pdesc, 0x08); */
```

## 2457. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/rtl8192ee/trx.c:797

Líneas 797–797; tipo `block`.

```text
/* set_tx_desc_tx_rate(pdesc, 0x0b); */
```

## 2458. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/rtl8192ee/trx.c:807

Líneas 807–807; tipo `block`.

```text
/* tx report */
```

## 2459. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/rtl8192ee/trx.c:910

Líneas 910–910; tipo `block`.

```text
/* make sure tx desc is available by caller */
```

## 2460. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/rtl8192ee/trx.c:1012

Líneas 1012–1012; tipo `block`.

```text
/* don't need to update ring->cur_tx_wp */
```

## 2461. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/rtl8192ee/trx.h:1

Líneas 1–1; tipo `block`.

```text
/* SPDX-License-Identifier: GPL-2.0 */
```

## 2462. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/rtl8192ee/trx.h:2

Líneas 2–2; tipo `block`.

```text
/* Copyright(c) 2009-2014  Realtek Corporation.*/
```

## 2463. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/rtl8192ee/trx.h:142

Líneas 142–142; tipo `block`.

```text
/* Dword 4 */
```

## 2464. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/rtl8192ee/trx.h:163

Líneas 163–163; tipo `block`.

```text
/* Dword 5 */
```

## 2465. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/rtl8192ee/trx.h:184

Líneas 184–184; tipo `block`.

```text
/* Dword 7 */
```

## 2466. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/rtl8192ee/trx.h:190

Líneas 190–190; tipo `block`.

```text
/* Dword 9 */
```

## 2467. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/rtl8192ee/trx.h:196

Líneas 196–196; tipo `block`.

```text
/* Dword 10 */
```

## 2468. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/rtl8192ee/trx.h:202

Líneas 202–202; tipo `block`.

```text
/* Dword 11*/
```

## 2469. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/rtl8192ee/trx.h:243

Líneas 243–243; tipo `block`.

```text
/* TX/RX buffer descriptor */
```

## 2470. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/rtl8192ee/trx.h:245

Líneas 245–245; tipo `block`.

```text
/* for Txfilldescroptor92ee, fill the desc content. */
```

## 2471. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/rtl8192ee/trx.h:287

Líneas 287–287; tipo `block`.

```text
/* Dword 0 */
```

## 2472. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/rtl8192ee/trx.h:303

Líneas 303–303; tipo `block`.

```text
/* Dword 1 */
```

## 2473. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/rtl8192ee/trx.h:309

Líneas 309–309; tipo `block`.

```text
/* Dword 2 */
```

## 2474. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/rtl8192ee/trx.h:319

Líneas 319–319; tipo `block`.

```text
/* RX buffer  */
```

## 2475. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/rtl8192ee/trx.h:321

Líneas 321–321; tipo `block`.

```text
/* DWORD 0 */
```

## 2476. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/rtl8192ee/trx.h:357

Líneas 357–357; tipo `block`.

```text
/* DWORD 1 */
```

## 2477. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/rtl8192ee/trx.h:363

Líneas 363–363; tipo `block`.

```text
/* DWORD 2 */
```

## 2478. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/rtl8192ee/trx.h:463

Líneas 463–463; tipo `block`.

```text
/* TX report 2 format in Rx desc*/
```

## 2479. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/rtl8192ee/trx.h:518

Líneas 518–518; tipo `block`.

```text
/*ex_intf_flg:1;*/
```

## 2480. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/rtl8192ee/trx.h:525

Líneas 525–525; tipo `block`.

```text
/* _BIG_ENDIAN_	*/
```

## 2481. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/rtl8192ee/trx.h:532

Líneas 532–532; tipo `block`.

```text
/*ex_intf_flg:1;*/
```

## 2482. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/stats.c:1

Líneas 1–1; tipo `line`.

```text
// SPDX-License-Identifier: GPL-2.0
```

## 2483. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/stats.c:2

Líneas 2–2; tipo `block`.

```text
/* Copyright(c) 2009-2012  Realtek Corporation.*/
```

## 2484. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/stats.c:162

Líneas 162–162; tipo `block`.

```text
/* adhoc or ap mode */
```

## 2485. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/stats.h:1

Líneas 1–1; tipo `block`.

```text
/* SPDX-License-Identifier: GPL-2.0 */
```

## 2486. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/stats.h:2

Líneas 2–2; tipo `block`.

```text
/* Copyright(c) 2009-2012  Realtek Corporation.*/
```

## 2487. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/stats.h:11

Líneas 11–11; tipo `block`.

```text
/* Rx smooth factor */
```

## 2488. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/usb.c:1

Líneas 1–1; tipo `line`.

```text
// SPDX-License-Identifier: GPL-2.0
```

## 2489. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/usb.c:2

Líneas 2–2; tipo `block`.

```text
/* Copyright(c) 2009-2012  Realtek Corporation.*/
```

## 2490. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/usb.c:29

Líneas 29–29; tipo `block`.

```text
/* free dr */
```

## 2491. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/usb.c:31

Líneas 31–31; tipo `block`.

```text
/* free databuf */
```

## 2492. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/usb.c:51

Líneas 51–51; tipo `block`.

```text
/* write_out */
```

## 2493. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/usb.c:76

Líneas 76–76; tipo `block`.

```text
/* data are already in little-endian order */
```

## 2494. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/usb.c:100

Líneas 100–100; tipo `block`.

```text
/* read_in */
```

## 2495. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/usb.c:107

Líneas 107–107; tipo `block`.

```text
/* firmware download is checksumed, don't retry */
```

## 2496. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/usb.c:138

Líneas 138–138; tipo `block`.

```text
/* n/a */
```

## 2497. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/usb.c:169

Líneas 169–169; tipo `block`.

```text
/* n/a */
```

## 2498. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/usb.c:206

Líneas 206–206; tipo `block`.

```text
/* write_out */
```

## 2499. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/usb.c:242

Líneas 242–242; tipo `block`.

```text
/*	Default aggregation handler. Do nothing and just return the oldest skb.  */
```

## 2500. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/usb.c:353

Líneas 353–353; tipo `block`.

```text
/* usb endpoint mapping */
```

## 2501. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/usb.c:376

Líneas 376–376; tipo `block`.

```text
/* IBSS */
```

## 2502. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/usb.c:379

Líneas 379–379; tipo `block`.

```text
/* AMPDU */
```

## 2503. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/usb.c:383

Líneas 383–383; tipo `block`.

```text
/* set sane AMPDU defaults */
```

## 2504. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/usb.c:387

Líneas 387–387; tipo `block`.

```text
/* QOS */
```

## 2505. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/usb.c:390

Líneas 390–390; tipo `block`.

```text
/* IRQ */
```

## 2506. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/usb.c:391

Líneas 391–391; tipo `block`.

```text
/* HIMR - turn all on */
```

## 2507. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/usb.c:393

Líneas 393–393; tipo `block`.

```text
/* HIMR_EX - turn all on */
```

## 2508. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/usb.c:443

Líneas 443–443; tipo `block`.

```text
/*TODO*/
```

## 2509. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/usb.c:445

Líneas 445–445; tipo `block`.

```text
/*TODO*/
```

## 2510. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/usb.c:457

Líneas 457–457; tipo `block`.

```text
/* static bcn for roaming */
```

## 2511. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/usb.c:485

Líneas 485–485; tipo `block`.

```text
/*TODO*/
```

## 2512. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/usb.c:487

Líneas 487–487; tipo `block`.

```text
/*TODO*/
```

## 2513. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/usb.c:500

Líneas 500–500; tipo `block`.

```text
/* static bcn for roaming */
```

## 2514. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/usb.c:546

Líneas 546–546; tipo `block`.

```text
/* TO DO */
```

## 2515. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/usb.c:560

Líneas 560–560; tipo `block`.

```text
/* make function no-op when possible */
```

## 2516. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/usb.c:565

Líneas 565–565; tipo `block`.

```text
/* alignment calculation as in lbtf_rx() / carl9170_rx_copy_data() */
```

## 2517. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/usb.c:566

Líneas 566–566; tipo `block`.

```text
/* TODO: deduplicate common code, define helper function instead? */
```

## 2518. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/usb.c:573

Líneas 573–575; tipo `block`.

```text
/* Input might be invalid, avoid accessing memory outside
		 * the buffer.
		 */
```

## 2519. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/usb.c:629

Líneas 629–629; tipo `block`.

```text
/* Make sure the payload data is 4 byte aligned. */
```

## 2520. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/usb.c:632

Líneas 632–632; tipo `block`.

```text
/* reserve some space for mac80211's radiotap */
```

## 2521. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/usb.c:644

Líneas 644–644; tipo `block`.

```text
/* disconnect */
```

## 2522. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/usb.c:664

Líneas 664–666; tipo `block`.

```text
/* On some architectures, usb_free_coherent must not be called from
	 * hardirq context. Queue urb to cleanup list.
	 */
```

## 2523. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/usb.c:700

Líneas 700–700; tipo `block`.

```text
/* 1600 == 1514 + max WLAN header + rtk info */
```

## 2524. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/usb.c:744

Líneas 744–744; tipo `block`.

```text
/* Enable software */
```

## 2525. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/usb.c:746

Líneas 746–746; tipo `block`.

```text
/* should after adapter start and interrupt enable. */
```

## 2526. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/usb.c:749

Líneas 749–749; tipo `block`.

```text
/* Start bulk IN */
```

## 2527. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/usb.c:756

Líneas 756–756; tipo `block`.

```text
/*=======================  tx =========================================*/
```

## 2528. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/usb.c:764

Líneas 764–764; tipo `block`.

```text
/* clean up rx stuff. */
```

## 2529. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/usb.c:767

Líneas 767–767; tipo `block`.

```text
/* clean up tx stuff */
```

## 2530. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/usb.c:781

Líneas 781–781; tipo `block`.

```text
/* We may add some struct into struct rtl_usb later. Do deinit here.  */
```

## 2531. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/usb.c:794

Líneas 794–794; tipo `block`.

```text
/* should after adapter start and interrupt enable. */
```

## 2532. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/usb.c:797

Líneas 797–797; tipo `block`.

```text
/* Enable software */
```

## 2533. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/usb.c:800

Líneas 800–800; tipo `block`.

```text
/* free pre-allocated URBs from rtl_usb_start() */
```

## 2534. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/usb.c:853

Líneas 853–853; tipo `block`.

```text
/*  TODO:	statistics */
```

## 2535. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/usb.c:871

Líneas 871–871; tipo `block`.

```text
/* Ignore error and keep issuiing other urbs */
```

## 2536. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/usb.c:1025

Líneas 1025–1025; tipo `block`.

```text
/* this spin lock must be initialized early */
```

## 2537. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/usb.c:1042

Líneas 1042–1042; tipo `block`.

```text
/* init cfg & intf_ops */
```

## 2538. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/usb.c:1046

Líneas 1046–1046; tipo `block`.

```text
/* Init IO handler */
```

## 2539. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/usb.c:1049

Líneas 1049–1049; tipo `block`.

```text
/*like read eeprom and so on */
```

## 2540. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/usb.c:1055

Líneas 1055–1055; tipo `block`.

```text
/* Init mac80211 sw */
```

## 2541. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/usb.c:1101

Líneas 1101–1101; tipo `block`.

```text
/* just in case driver is removed before firmware callback */
```

## 2542. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/usb.c:1104

Líneas 1104–1104; tipo `block`.

```text
/*ieee80211_unregister_hw will call ops_stop */
```

## 2543. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/usb.c:1112

Líneas 1112–1112; tipo `block`.

```text
/*deinit rfkill */
```

## 2544. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/usb.c:1113

Líneas 1113–1113; tipo `block`.

```text
/* rtl_deinit_rfkill(hw); */
```

## 2545. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/usb.h:1

Líneas 1–1; tipo `block`.

```text
/* SPDX-License-Identifier: GPL-2.0 */
```

## 2546. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/usb.h:2

Líneas 2–2; tipo `block`.

```text
/* Copyright(c) 2009-2012  Realtek Corporation.*/
```

## 2547. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/usb.h:20

Líneas 20–20; tipo `block`.

```text
/* max tx queue */
```

## 2548. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/usb.h:21

Líneas 21–21; tipo `block`.

```text
/* max ep number */
```

## 2549. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/usb.h:25

Líneas 25–27; tipo `block`.

```text
/* These definitions shall be consistent with value
	 * returned by skb_get_queue_mapping
	 *------------------------------------*/
```

## 2550. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/usb.h:32

Líneas 32–32; tipo `block`.

```text
/*------------------------------------*/
```

## 2551. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/usb.h:37

Líneas 37–37; tipo `block`.

```text
/* Must be last */
```

## 2552. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/usb.h:60

Líneas 60–60; tipo `block`.

```text
/*  Add suspend/resume later */
```

## 2553. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/usb.h:83

Líneas 83–83; tipo `block`.

```text
/* Bcn control register setting */
```

## 2554. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/usb.h:85

Líneas 85–85; tipo `block`.

```text
/* for 88/92cu card disable */
```

## 2555. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/usb.h:87

Líneas 87–87; tipo `block`.

```text
/*QOS & EDCA */
```

## 2556. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/usb.h:89

Líneas 89–89; tipo `block`.

```text
/* irq  . HIMR,HIMR_EX */
```

## 2557. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/usb.h:95

Líneas 95–95; tipo `block`.

```text
/* Tx */
```

## 2558. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/usb.h:113

Líneas 113–113; tipo `block`.

```text
/* Rx */
```

## 2559. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/usb.h:115

Líneas 115–115; tipo `block`.

```text
/* Bulk IN endpoint number */
```

## 2560. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/usb.h:116

Líneas 116–116; tipo `block`.

```text
/* Bulk IN max buffer size */
```

## 2561. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/usb.h:117

Líneas 117–117; tipo `block`.

```text
/* How many Bulk INs are submitted to host. */
```

## 2562. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/wifi.h:1

Líneas 1–1; tipo `block`.

```text
/* SPDX-License-Identifier: GPL-2.0 */
```

## 2563. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/wifi.h:2

Líneas 2–2; tipo `block`.

```text
/* Copyright(c) 2009-2012  Realtek Corporation.*/
```

## 2564. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/wifi.h:64

Líneas 64–64; tipo `block`.

```text
/* QoS related. */
```

## 2565. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/wifi.h:65

Líneas 65–65; tipo `block`.

```text
/*aci: 0x00	Best Effort*/
```

## 2566. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/wifi.h:66

Líneas 66–66; tipo `block`.

```text
/*aci: 0x01	Background*/
```

## 2567. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/wifi.h:67

Líneas 67–67; tipo `block`.

```text
/*aci: 0x10	Video*/
```

## 2568. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/wifi.h:68

Líneas 68–68; tipo `block`.

```text
/*aci: 0x11	Voice*/
```

## 2569. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/wifi.h:69

Líneas 69–69; tipo `block`.

```text
/*Max: define total number.*/
```

## 2570. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/wifi.h:85

Líneas 85–85; tipo `block`.

```text
/*slot time for 11g. */
```

## 2571. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/wifi.h:89

Líneas 89–89; tipo `block`.

```text
/*related to tcp/ip. */
```

## 2572. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/wifi.h:93

Líneas 93–93; tipo `block`.

```text
/*related with 802.11 frame*/
```

## 2573. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/wifi.h:97

Líneas 97–97; tipo `block`.

```text
/* 14 is the max channel no */
```

## 2574. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/wifi.h:99

Líneas 99–102; tipo `block`.

```text
/* Please refer to
					    *"phy_GetChnlGroup8812A" and
					    * "Hal_ReadTxPowerInfo8812A"
					    */
```

## 2575. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/wifi.h:104

Líneas 104–104; tipo `block`.

```text
/*  ch1~3, 4~9, 10~14 = three groups */
```

## 2576. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/wifi.h:116

Líneas 116–116; tipo `block`.

```text
/* for early mode */
```

## 2577. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/wifi.h:173

Líneas 173–173; tipo `block`.

```text
/* = MAX_RATE_SECTION */
```

## 2578. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/wifi.h:183

Líneas 183–183; tipo `block`.

```text
/* >= TX_PWR_BY_RATE_NUM_SECTION */
```

## 2579. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/wifi.h:184

Líneas 184–184; tipo `block`.

```text
/* MAX_RATE_SECTION */
```

## 2580. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/wifi.h:185

Líneas 185–185; tipo `block`.

```text
/* MAX_RATE_SECTION -1 */
```

## 2581. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/wifi.h:187

Líneas 187–187; tipo `block`.

```text
/* 0:2 seg, 1: 4 seg, 2: 8 seg */
```

## 2582. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/wifi.h:191

Líneas 191–193; tipo `block`.

```text
/* For now, it's just for 8192ee
 * but not OK yet, keep it 0
 */
```

## 2583. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/wifi.h:214

Líneas 214–214; tipo `block`.

```text
/* MIN LEN keeps 13 here */
```

## 2584. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/wifi.h:255

Líneas 255–255; tipo `block`.

```text
/*If only one tx, only BW20 and OFDM are used.*/
```

## 2585. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/wifi.h:266

Líneas 266–266; tipo `block`.

```text
/*If only one tx, only BW20, OFDM, BW80 and BW160 are used.*/
```

## 2586. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/wifi.h:340

Líneas 340–340; tipo `block`.

```text
/* keep it last */
```

## 2587. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/wifi.h:376

Líneas 376–376; tipo `block`.

```text
/*RF state.*/
```

## 2588. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/wifi.h:400

Líneas 400–400; tipo `block`.

```text
/* rflssi_readback */
```

## 2589. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/wifi.h:401

Líneas 401–401; tipo `block`.

```text
/* rflssi_readbackpi */
```

## 2590. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/wifi.h:600

Líneas 600–602; tipo `block`.

```text
/* Ref: 802.11i spec D10.0 7.3.2.25.1
 * Cipher Suites Encryption Algorithms
 */
```

## 2591. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/wifi.h:610

Líneas 610–610; tipo `block`.

```text
/*IEEE802.11w */
```

## 2592. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/wifi.h:675

Líneas 675–675; tipo `block`.

```text
/*reg map */
```

## 2593. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/wifi.h:688

Líneas 688–688; tipo `block`.

```text
/*efuse map */
```

## 2594. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/wifi.h:703

Líneas 703–703; tipo `block`.

```text
/*CAM map */
```

## 2595. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/wifi.h:715

Líneas 715–715; tipo `block`.

```text
/*IMR map */
```

## 2596. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/wifi.h:716

Líneas 716–716; tipo `block`.

```text
/*Beacon DMA Interrupt 6 */
```

## 2597. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/wifi.h:717

Líneas 717–717; tipo `block`.

```text
/*Beacon DMA Interrupt 5 */
```

## 2598. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/wifi.h:718

Líneas 718–718; tipo `block`.

```text
/*Beacon DMA Interrupt 4 */
```

## 2599. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/wifi.h:719

Líneas 719–719; tipo `block`.

```text
/*Beacon DMA Interrupt 3 */
```

## 2600. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/wifi.h:720

Líneas 720–720; tipo `block`.

```text
/*Beacon DMA Interrupt 2 */
```

## 2601. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/wifi.h:721

Líneas 721–721; tipo `block`.

```text
/*Beacon DMA Interrupt 1 */
```

## 2602. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/wifi.h:722

Líneas 722–722; tipo `block`.

```text
/*Beacon Queue DMA OK Interrup 8 */
```

## 2603. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/wifi.h:723

Líneas 723–723; tipo `block`.

```text
/*Beacon Queue DMA OK Interrup 7 */
```

## 2604. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/wifi.h:724

Líneas 724–724; tipo `block`.

```text
/*Beacon Queue DMA OK Interrup 6 */
```

## 2605. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/wifi.h:725

Líneas 725–725; tipo `block`.

```text
/*Beacon Queue DMA OK Interrup 5 */
```

## 2606. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/wifi.h:726

Líneas 726–726; tipo `block`.

```text
/*Beacon Queue DMA OK Interrup 4 */
```

## 2607. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/wifi.h:727

Líneas 727–727; tipo `block`.

```text
/*Beacon Queue DMA OK Interrup 3 */
```

## 2608. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/wifi.h:728

Líneas 728–728; tipo `block`.

```text
/*Beacon Queue DMA OK Interrup 2 */
```

## 2609. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/wifi.h:729

Líneas 729–729; tipo `block`.

```text
/*Beacon Queue DMA OK Interrup 1 */
```

## 2610. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/wifi.h:730

Líneas 730–730; tipo `block`.

```text
/*Timeout interrupt 2 */
```

## 2611. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/wifi.h:731

Líneas 731–731; tipo `block`.

```text
/*Timeout interrupt 1 */
```

## 2612. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/wifi.h:732

Líneas 732–732; tipo `block`.

```text
/*Transmit FIFO Overflow */
```

## 2613. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/wifi.h:733

Líneas 733–733; tipo `block`.

```text
/*Power save time out interrupt */
```

## 2614. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/wifi.h:734

Líneas 734–734; tipo `block`.

```text
/*Beacon DMA Interrupt 0 */
```

## 2615. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/wifi.h:735

Líneas 735–735; tipo `block`.

```text
/*Receive FIFO Overflow */
```

## 2616. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/wifi.h:736

Líneas 736–736; tipo `block`.

```text
/*Receive Descriptor Unavailable */
```

## 2617. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/wifi.h:737

Líneas 737–737; tipo `block`.

```text
/*For 92C,ATIM Window End Interrupt */
```

## 2618. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/wifi.h:738

Líneas 738–738; tipo `block`.

```text
/*H2C Queue DMA OK Interrupt */
```

## 2619. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/wifi.h:739

Líneas 739–739; tipo `block`.

```text
/*Beacon Queue DMA OK Interrup */
```

## 2620. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/wifi.h:740

Líneas 740–740; tipo `block`.

```text
/*High Queue DMA OK Interrupt */
```

## 2621. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/wifi.h:741

Líneas 741–741; tipo `block`.

```text
/*Command Queue DMA OK Interrupt*/
```

## 2622. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/wifi.h:742

Líneas 742–742; tipo `block`.

```text
/*Transmit Beacon OK interrup */
```

## 2623. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/wifi.h:743

Líneas 743–743; tipo `block`.

```text
/*Management Queue DMA OK Interrupt */
```

## 2624. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/wifi.h:744

Líneas 744–744; tipo `block`.

```text
/*For 92C,Transmit Beacon Error Interrupt */
```

## 2625. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/wifi.h:745

Líneas 745–745; tipo `block`.

```text
/*AC_BK DMA OK Interrupt */
```

## 2626. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/wifi.h:746

Líneas 746–746; tipo `block`.

```text
/*AC_BE DMA OK Interrupt */
```

## 2627. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/wifi.h:747

Líneas 747–747; tipo `block`.

```text
/*AC_VI DMA OK Interrupt */
```

## 2628. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/wifi.h:748

Líneas 748–748; tipo `block`.

```text
/*AC_VO DMA Interrupt */
```

## 2629. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/wifi.h:749

Líneas 749–749; tipo `block`.

```text
/*Receive DMA OK Interrupt */
```

## 2630. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/wifi.h:750

Líneas 750–750; tipo `block`.

```text
/*HSISR Interrupt*/
```

## 2631. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/wifi.h:751

Líneas 751–753; tipo `block`.

```text
/*(RTL_IMR_BCNINT | RTL_IMR_TBDOK |
				 * RTL_IMR_TBDER)
				 */
```

## 2632. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/wifi.h:754

Líneas 754–754; tipo `block`.

```text
/*fw interrupt*/
```

## 2633. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/wifi.h:756

Líneas 756–756; tipo `block`.

```text
/*CCK Rates, TxHT = 0 */
```

## 2634. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/wifi.h:762

Líneas 762–762; tipo `block`.

```text
/*OFDM Rates, TxHT = 0 */
```

## 2635. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/wifi.h:782

Líneas 782–782; tipo `block`.

```text
/*keep it last */
```

## 2636. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/wifi.h:786

Líneas 786–786; tipo `block`.

```text
/*Firmware PS mode for control LPS.*/
```

## 2637. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/wifi.h:802

Líneas 802–802; tipo `block`.

```text
/*Active/Continuous access. */
```

## 2638. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/wifi.h:803

Líneas 803–803; tipo `block`.

```text
/*Max power save mode. */
```

## 2639. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/wifi.h:804

Líneas 804–804; tipo `block`.

```text
/*Fast power save mode. */
```

## 2640. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/wifi.h:805

Líneas 805–805; tipo `block`.

```text
/*Auto power save mode. */
```

## 2641. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/wifi.h:808

Líneas 808–808; tipo `block`.

```text
/*LED related.*/
```

## 2642. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/wifi.h:829

Líneas 829–829; tipo `block`.

```text
/*QoS related.*/
```

## 2643. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/wifi.h:830

Líneas 830–830; tipo `block`.

```text
/*acm implementation method.*/
```

## 2644. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/wifi.h:850

Líneas 850–852; tipo `block`.

```text
/* aci/aifsn Field.
 * Ref: WMM spec 2.2.2: WME Parameter Element, p.12.
 */
```

## 2645. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/wifi.h:861

Líneas 861–861; tipo `block`.

```text
/* Field */
```

## 2646. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/wifi.h:864

Líneas 864–864; tipo `block`.

```text
/*mlme related.*/
```

## 2647. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/wifi.h:948

Líneas 948–948; tipo `block`.

```text
/* After 8188E, we use V2 reason define. 88C/8723A use V1 reason. */
```

## 2648. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/wifi.h:981

Líneas 981–981; tipo `block`.

```text
/* use ratr_table_mode_new */
```

## 2649. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/wifi.h:982

Líneas 982–982; tipo `block`.

```text
/* support VHT */
```

## 2650. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/wifi.h:983

Líneas 983–983; tipo `block`.

```text
/* extend FW C2H (e.g. TX REPORT) */
```

## 2651. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/wifi.h:1067

Líneas 1067–1069; tipo `block`.

```text
/*SSID, supported rates, FH params, DS params,
	 * CF params, IBSS params, TIM (if beacon), RSN
	 */
```

## 2652. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/wifi.h:1073

Líneas 1073–1073; tipo `block`.

```text
/*LED related.*/
```

## 2653. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/wifi.h:1074

Líneas 1074–1074; tipo `block`.

```text
/*ledpin Identify how to implement this SW led.*/
```

## 2654. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/wifi.h:1096

Líneas 1096–1096; tipo `block`.

```text
/*array to store values */
```

## 2655. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/wifi.h:1097

Líneas 1097–1097; tipo `block`.

```text
/*index to current array to store */
```

## 2656. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/wifi.h:1098

Líneas 1098–1098; tipo `block`.

```text
/*num of valid elements */
```

## 2657. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/wifi.h:1099

Líneas 1099–1099; tipo `block`.

```text
/*sum of valid elements */
```

## 2658. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/wifi.h:1142

Líneas 1142–1144; tipo `block`.

```text
/*Correct smoothed ss in Dbm, only used
	 * in driver to report real power now.
	 */
```

## 2659. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/wifi.h:1152

Líneas 1152–1154; tipo `block`.

```text
/* Transformed, in dbm. Beautified signal
	 * strength for UI, not correct.
	 */
```

## 2660. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/wifi.h:1226

Líneas 1226–1226; tipo `block`.

```text
/*0 is off, 1 is on */
```

## 2661. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/wifi.h:1229

Líneas 1229–1229; tipo `block`.

```text
/*for P2P PS**/
```

## 2662. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/wifi.h:1244

Líneas 1244–1244; tipo `block`.

```text
/* for P2P GO */
```

## 2663. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/wifi.h:1251

Líneas 1251–1251; tipo `block`.

```text
/* CTWindow and NoA */
```

## 2664. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/wifi.h:1255

Líneas 1255–1255; tipo `block`.

```text
/* indicate p2p ps mode */
```

## 2665. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/wifi.h:1256

Líneas 1256–1256; tipo `block`.

```text
/*  indicate p2p ps state */
```

## 2666. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/wifi.h:1257

Líneas 1257–1257; tipo `block`.

```text
/*  Identifies instance of Notice of Absence timing. */
```

## 2667. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/wifi.h:1258

Líneas 1258–1258; tipo `block`.

```text
/*  Client traffic window. A period of time in TU after TBTT. */
```

## 2668. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/wifi.h:1260

Líneas 1260–1260; tipo `block`.

```text
/*  opportunistic power save. */
```

## 2669. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/wifi.h:1261

Líneas 1261–1261; tipo `block`.

```text
/*  number of NoA descriptor in P2P IE. */
```

## 2670. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/wifi.h:1262

Líneas 1262–1262; tipo `block`.

```text
/*  Count for owner, Type of client. */
```

## 2671. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/wifi.h:1264

Líneas 1264–1266; tipo `block`.

```text
/*  Max duration for owner, preferred or min acceptable duration
	 * for client.
	 */
```

## 2672. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/wifi.h:1268

Líneas 1268–1270; tipo `block`.

```text
/*  Length of interval for owner, preferred or max acceptable intervali
	 * of client.
	 */
```

## 2673. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/wifi.h:1272

Líneas 1272–1272; tipo `block`.

```text
/*  schedule in terms of the lower 4 bytes of the TSF timer. */
```

## 2674. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/wifi.h:1278

Líneas 1278–1278; tipo `block`.

```text
/* 1: Owner, 0: Client */
```

## 2675. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/wifi.h:1315

Líneas 1315–1315; tipo `block`.

```text
/*Radio A/B/C/D */
```

## 2676. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/wifi.h:1331

Líneas 1331–1331; tipo `block`.

```text
/* record for power tracking */
```

## 2677. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/wifi.h:1351

Líneas 1351–1351; tipo `block`.

```text
/* Dual mac */
```

## 2678. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/wifi.h:1360

Líneas 1360–1360; tipo `block`.

```text
/* this is for 88E & 8723A */
```

## 2679. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/wifi.h:1362

Líneas 1362–1362; tipo `block`.

```text
/* MAX_PG_GROUP groups of pwr diff by rates */
```

## 2680. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/wifi.h:1376

Líneas 1376–1376; tipo `block`.

```text
/* the current Tx power level */
```

## 2681. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/wifi.h:1395

Líneas 1395–1395; tipo `block`.

```text
/* pathA / pathB  */
```

## 2682. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/wifi.h:1397

Líneas 1397–1397; tipo `block`.

```text
/*92ee*/
```

## 2683. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/wifi.h:1398

Líneas 1398–1398; tipo `block`.

```text
/* bfsync */
```

## 2684. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/wifi.h:1406

Líneas 1406–1406; tipo `block`.

```text
/*Enable GPIO[9] as WL RF HW PDn source*/
```

## 2685. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/wifi.h:1444

Líneas 1444–1444; tipo `block`.

```text
/* just used for ap adhoc or mesh*/
```

## 2686. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/wifi.h:1458

Líneas 1458–1458; tipo `block`.

```text
/*PCI MEM map */
```

## 2687. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/wifi.h:1459

Líneas 1459–1459; tipo `block`.

```text
/*shared mem end        */
```

## 2688. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/wifi.h:1460

Líneas 1460–1460; tipo `block`.

```text
/*shared mem start */
```

## 2689. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/wifi.h:1462

Líneas 1462–1462; tipo `block`.

```text
/*PCI IO map */
```

## 2690. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/wifi.h:1463

Líneas 1463–1463; tipo `block`.

```text
/*device I/O address */
```

## 2691. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/wifi.h:1490

Líneas 1490–1490; tipo `block`.

```text
/*Probe Beacon management */
```

## 2692. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/wifi.h:1498

Líneas 1498–1498; tipo `block`.

```text
/*using p2p role*/
```

## 2693. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/wifi.h:1501

Líneas 1501–1501; tipo `block`.

```text
/*filters */
```

## 2694. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/wifi.h:1511

Líneas 1511–1511; tipo `block`.

```text
/* early mode */
```

## 2695. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/wifi.h:1512

Líneas 1512–1512; tipo `block`.

```text
/* skb wait queue */
```

## 2696. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/wifi.h:1518

Líneas 1518–1518; tipo `block`.

```text
/*vht support*/
```

## 2697. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/wifi.h:1526

Líneas 1526–1526; tipo `block`.

```text
/*RDG*/
```

## 2698. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/wifi.h:1529

Líneas 1529–1529; tipo `block`.

```text
/*AP*/
```

## 2699. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/wifi.h:1532

Líneas 1532–1532; tipo `block`.

```text
/* 16 bytes mcs for HT rates. */
```

## 2700. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/wifi.h:1533

Líneas 1533–1533; tipo `block`.

```text
/* b/g rates */
```

## 2701. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/wifi.h:1538

Líneas 1538–1538; tipo `block`.

```text
/* wireless mode */
```

## 2702. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/wifi.h:1551

Líneas 1551–1551; tipo `block`.

```text
/*IBSS*/
```

## 2703. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/wifi.h:1554

Líneas 1554–1554; tipo `block`.

```text
/*AMPDU*/
```

## 2704. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/wifi.h:1555

Líneas 1555–1555; tipo `block`.

```text
/*For Min spacing configurations */
```

## 2705. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/wifi.h:1560

Líneas 1560–1560; tipo `block`.

```text
/*QOS & EDCA */
```

## 2706. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/wifi.h:1564

Líneas 1564–1564; tipo `block`.

```text
/* counters */
```

## 2707. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/wifi.h:1629

Líneas 1629–1629; tipo `block`.

```text
/*92c or 92d or 92s and so on */
```

## 2708. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/wifi.h:1632

Líneas 1632–1632; tipo `block`.

```text
/*version of chip */
```

## 2709. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/wifi.h:1633

Líneas 1633–1633; tipo `block`.

```text
/*stop 0, start 1 */
```

## 2710. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/wifi.h:1653

Líneas 1653–1653; tipo `block`.

```text
/*firmware */
```

## 2711. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/wifi.h:1661

Líneas 1661–1661; tipo `block`.

```text
/*Reserve page start offset except beacon in TxQ. */
```

## 2712. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/wifi.h:1666

Líneas 1666–1666; tipo `block`.

```text
/* FW Cmd IO related */
```

## 2713. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/wifi.h:1676

Líneas 1676–1676; tipo `block`.

```text
/**/
```

## 2714. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/wifi.h:1679

Líneas 1679–1679; tipo `block`.

```text
/*AMPDU init min space*/
```

## 2715. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/wifi.h:1680

Líneas 1680–1680; tipo `block`.

```text
/*For Min spacing configurations */
```

## 2716. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/wifi.h:1682

Líneas 1682–1682; tipo `block`.

```text
/* Dual mac */
```

## 2717. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/wifi.h:1684

Líneas 1684–1684; tipo `block`.

```text
/* 0:2.4G, 1:5G */
```

## 2718. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/wifi.h:1687

Líneas 1687–1687; tipo `block`.

```text
/* dual MAC 0--Mac0 1--Mac1 */
```

## 2719. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/wifi.h:1689

Líneas 1689–1689; tipo `block`.

```text
/* just for DualMac S3S4 */
```

## 2720. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/wifi.h:1693

Líneas 1693–1693; tipo `block`.

```text
/* Dual mac*/
```

## 2721. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/wifi.h:1697

Líneas 1697–1699; tipo `block`.

```text
/* True if IMR or IQK  have done
	 * for 2.4G in scan progress
	 */
```

## 2722. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/wifi.h:1706

Líneas 1706–1706; tipo `block`.

```text
/*for 92ee*/
```

## 2723. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/wifi.h:1709

Líneas 1709–1709; tipo `block`.

```text
/*for wowlan*/
```

## 2724. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/wifi.h:1718

Líneas 1718–1718; tipo `block`.

```text
/*Enable GPIO[9] as WL RF HW PDn source*/
```

## 2725. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/wifi.h:1725

Líneas 1725–1725; tipo `block`.

```text
/*default 0 */
```

## 2726. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/wifi.h:1730

Líneas 1730–1730; tipo `block`.

```text
/*Encryption Algorithm for Unicast Packet */
```

## 2727. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/wifi.h:1732

Líneas 1732–1732; tipo `block`.

```text
/*Encryption Algorithm for Brocast/Multicast */
```

## 2728. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/wifi.h:1734

Líneas 1734–1734; tipo `block`.

```text
/*Cam Entry Bitmap */
```

## 2729. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/wifi.h:1737

Líneas 1737–1739; tipo `block`.

```text
/*local Key buffer, indx 0 is for
	 * pairwise key 1-4 is for agoup key.
	 */
```

## 2730. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/wifi.h:1743

Líneas 1743–1745; tipo `block`.

```text
/*The pointer of Pairwise Key,
	 * it always points to KeyBuf[4]
	 */
```

## 2731. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/wifi.h:1783

Líneas 1783–1783; tipo `block`.

```text
/*PHY status for Dynamic Management */
```

## 2732. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/wifi.h:1786

Líneas 1786–1786; tipo `block`.

```text
/*out dm */
```

## 2733. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/wifi.h:1792

Líneas 1792–1792; tipo `block`.

```text
/*out dm */
```

## 2734. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/wifi.h:1814

Líneas 1814–1814; tipo `block`.

```text
/*Tx high power level */
```

## 2735. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/wifi.h:1815

Líneas 1815–1815; tipo `block`.

```text
/*Indicate each dynamic mechanism's status. */
```

## 2736. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/wifi.h:1838

Líneas 1838–1838; tipo `block`.

```text
/* Dynamic ATC switch */
```

## 2737. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/wifi.h:1850

Líneas 1850–1850; tipo `block`.

```text
/*88e tx power tracking*/
```

## 2738. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/wifi.h:1863

Líneas 1863–1863; tipo `block`.

```text
/* DMSP */
```

## 2739. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/wifi.h:1866

Líneas 1866–1866; tipo `block`.

```text
/* DulMac */
```

## 2740. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/wifi.h:1918

Líneas 1918–1918; tipo `block`.

```text
/* for 5GL/5GM/5GH band. */
```

## 2741. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/wifi.h:1925

Líneas 1925–1925; tipo `block`.

```text
/* pathA / pathB */
```

## 2742. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/wifi.h:1929

Líneas 1929–1929; tipo `block`.

```text
/*For power group */
```

## 2743. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/wifi.h:1935

Líneas 1935–1935; tipo `block`.

```text
/*For HT 40MHZ pwr */
```

## 2744. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/wifi.h:1937

Líneas 1937–1937; tipo `block`.

```text
/*For HT 40MHZ pwr */
```

## 2745. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/wifi.h:1940

Líneas 1940–1953; tipo `block`.

```text
/*--------------------------------------------------------*
	 * 8192CE\8192SE\8192DE\8723AE use the following 4 arrays,
	 * other ICs (8188EE\8723BE\8192EE\8812AE...)
	 * define new arrays in Windows code.
	 * BUT, in linux code, we use the same array for all ICs.
	 *
	 * The Correspondance relation between two arrays is:
	 * txpwr_cckdiff[][] == CCK_24G_Diff[][]
	 * txpwr_ht20diff[][] == BW20_24G_Diff[][]
	 * txpwr_ht40diff[][] == BW40_24G_Diff[][]
	 * txpwr_legacyhtdiff[][] == OFDM_24G_Diff[][]
	 *
	 * Sizes of these arrays are decided by the larger ones.
	 */
```

## 2746. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/wifi.h:1966

Líneas 1966–1966; tipo `block`.

```text
/* Band edge enable flag */
```

## 2747. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/wifi.h:1972

Líneas 1972–1972; tipo `block`.

```text
/*ThermalMeter, index 0 for RFIC0, 1 for RFIC1 */
```

## 2748. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/wifi.h:1974

Líneas 1974–1974; tipo `block`.

```text
/* CrystalCap. */
```

## 2749. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/wifi.h:1978

Líneas 1978–1978; tipo `block`.

```text
/*Legacy to HT rate power diff */
```

## 2750. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/wifi.h:1984

Líneas 1984–1984; tipo `block`.

```text
/*channel plan */
```

## 2751. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/wifi.h:2008

Líneas 2008–2011; tipo `block`.

```text
/* just for PCIE ASPM
	 * If it supports ASPM, Offset[560h] = 0x40,
	 * otherwise Offset[560h] = 0x00.
	 */
```

## 2752. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/wifi.h:2015

Líneas 2015–2015; tipo `block`.

```text
/*for LPS */
```

## 2753. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/wifi.h:2016

Líneas 2016–2016; tipo `block`.

```text
/*Power save mode configured. */
```

## 2754. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/wifi.h:2021

Líneas 2021–2021; tipo `block`.

```text
/*For Fw control LPS mode */
```

## 2755. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/wifi.h:2023

Líneas 2023–2023; tipo `block`.

```text
/*Record Fw PS mode status. */
```

## 2756. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/wifi.h:2027

Líneas 2027–2027; tipo `block`.

```text
/*for 32k*/
```

## 2757. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/wifi.h:2029

Líneas 2029–2029; tipo `block`.

```text
/*for IPS */
```

## 2758. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/wifi.h:2034

Líneas 2034–2034; tipo `block`.

```text
/*RF OFF Level */
```

## 2759. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/wifi.h:2038

Líneas 2038–2038; tipo `block`.

```text
/*just for PCIE ASPM */
```

## 2760. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/wifi.h:2043

Líneas 2043–2043; tipo `block`.

```text
/*cur power state */
```

## 2761. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/wifi.h:2045

Líneas 2045–2045; tipo `block`.

```text
/* for SW LPS*/
```

## 2762. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/wifi.h:2061

Líneas 2061–2061; tipo `block`.

```text
/*For P2P PS */
```

## 2763. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/wifi.h:2066

Líneas 2066–2066; tipo `block`.

```text
/* wake up on line */
```

## 2764. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/wifi.h:2070

Líneas 2070–2070; tipo `block`.

```text
/* Used for WOL, indicates the reason for waking event.*/
```

## 2765. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/wifi.h:2080

Líneas 2080–2080; tipo `block`.

```text
/* hw desc rate */
```

## 2766. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/wifi.h:2090

Líneas 2090–2090; tipo `block`.

```text
/*in 0-100 index. */
```

## 2767. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/wifi.h:2091

Líneas 2091–2093; tipo `block`.

```text
/* Real power in dBm for this packet,
	 * no beautification and aggregation.
	 */
```

## 2768. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/wifi.h:2095

Líneas 2095–2095; tipo `block`.

```text
/*in dBm Translate from PWdB */
```

## 2769. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/wifi.h:2096

Líneas 2096–2096; tipo `block`.

```text
/*in 0-100 index. */
```

## 2770. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/wifi.h:2115

Líneas 2115–2115; tipo `block`.

```text
/*in 0~100 index */
```

## 2771. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/wifi.h:2118

Líneas 2118–2118; tipo `block`.

```text
/* per-path's Cfo_short */
```

## 2772. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/wifi.h:2122

Líneas 2122–2122; tipo `block`.

```text
/* per-path's pwdb */
```

## 2773. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/wifi.h:2123

Líneas 2123–2123; tipo `block`.

```text
/* per-path's SNR */
```

## 2774. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/wifi.h:2130

Líneas 2130–2130; tipo `block`.

```text
/*for rssi */
```

## 2775. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/wifi.h:2131

Líneas 2131–2131; tipo `block`.

```text
/*for rx path selection */
```

## 2776. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/wifi.h:2145

Líneas 2145–2145; tipo `block`.

```text
/* count for roaming */
```

## 2777. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/wifi.h:2195

Líneas 2195–2195; tipo `block`.

```text
/* early mode */
```

## 2778. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/wifi.h:2197

Líneas 2197–2197; tipo `block`.

```text
/* The max value by HW */
```

## 2779. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/wifi.h:2208

Líneas 2208–2208; tipo `block`.

```text
/* struct to store contents of interrupt vectors */
```

## 2780. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/wifi.h:2334

Líneas 2334–2334; tipo `block`.

```text
/*com */
```

## 2781. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/wifi.h:2349

Líneas 2349–2349; tipo `block`.

```text
/*pci */
```

## 2782. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/wifi.h:2353

Líneas 2353–2353; tipo `block`.

```text
/*usb */
```

## 2783. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/wifi.h:2357

Líneas 2357–2357; tipo `block`.

```text
/* default: 0,0 */
```

## 2784. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/wifi.h:2359

Líneas 2359–2359; tipo `block`.

```text
/* default: 0 = using hardware encryption */
```

## 2785. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/wifi.h:2362

Líneas 2362–2362; tipo `block`.

```text
/* default: 0 = DBG_EMERG (0)*/
```

## 2786. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/wifi.h:2365

Líneas 2365–2365; tipo `block`.

```text
/* default: 1 = using no linked power save */
```

## 2787. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/wifi.h:2368

Líneas 2368–2368; tipo `block`.

```text
/* default: 1 = using linked sw power save */
```

## 2788. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/wifi.h:2371

Líneas 2371–2371; tipo `block`.

```text
/* default: 1 = using linked fw power save */
```

## 2789. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/wifi.h:2374

Líneas 2374–2376; tipo `block`.

```text
/* default: 0 = not using MSI interrupts mode
	 * submodules should set their own default value
	 */
```

## 2790. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/wifi.h:2379

Líneas 2379–2379; tipo `block`.

```text
/* default: 0 = dma 32 */
```

## 2791. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/wifi.h:2382

Líneas 2382–2382; tipo `block`.

```text
/* default: 1 = enable aspm */
```

## 2792. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/wifi.h:2385

Líneas 2385–2385; tipo `block`.

```text
/* default 0: 1 means disable */
```

## 2793. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/wifi.h:2388

Líneas 2388–2388; tipo `block`.

```text
/* default 0: 1 means do not disable interrupts */
```

## 2794. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/wifi.h:2391

Líneas 2391–2391; tipo `block`.

```text
/* select antenna */
```

## 2795. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/wifi.h:2396

Líneas 2396–2396; tipo `block`.

```text
/* data - rx */
```

## 2796. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/wifi.h:2401

Líneas 2401–2401; tipo `block`.

```text
/* op - rx */
```

## 2797. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/wifi.h:2406

Líneas 2406–2406; tipo `block`.

```text
/* tx */
```

## 2798. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/wifi.h:2413

Líneas 2413–2413; tipo `block`.

```text
/* endpoint mapping */
```

## 2799. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/wifi.h:2428

Líneas 2428–2430; tipo `block`.

```text
/*this map used for some registers or vars
	 * defined int HAL but used in MAIN
	 */
```

## 2800. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/wifi.h:2436

Líneas 2436–2436; tipo `block`.

```text
/* mutex */
```

## 2801. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/wifi.h:2438

Líneas 2438–2438; tipo `block`.

```text
/* mutex for enter/leave IPS */
```

## 2802. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/wifi.h:2439

Líneas 2439–2439; tipo `block`.

```text
/* mutex for enter/leave LPS */
```

## 2803. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/wifi.h:2441

Líneas 2441–2441; tipo `block`.

```text
/*spin lock */
```

## 2804. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/wifi.h:2450

Líneas 2450–2450; tipo `block`.

```text
/* lock for the scan list */
```

## 2805. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/wifi.h:2452

Líneas 2452–2452; tipo `block`.

```text
/*FW clock change */
```

## 2806. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/wifi.h:2455

Líneas 2455–2455; tipo `block`.

```text
/*Dual mac*/
```

## 2807. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/wifi.h:2464

Líneas 2464–2464; tipo `block`.

```text
/*timer */
```

## 2808. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/wifi.h:2468

Líneas 2468–2468; tipo `block`.

```text
/*task */
```

## 2809. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/wifi.h:2472

Líneas 2472–2472; tipo `block`.

```text
/*work queue */
```

## 2810. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/wifi.h:2478

Líneas 2478–2478; tipo `block`.

```text
/* For SW LPS */
```

## 2811. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/wifi.h:2488

Líneas 2488–2488; tipo `block`.

```text
/* add for debug */
```

## 2812. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/wifi.h:2581

Líneas 2581–2581; tipo `block`.

```text
/* 30 seconds */
```

## 2813. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/wifi.h:2597

Líneas 2597–2597; tipo `block`.

```text
/* btc context */
```

## 2814. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/wifi.h:2600

Líneas 2600–2600; tipo `block`.

```text
/* EEPROM BT info. */
```

## 2815. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/wifi.h:2611

Líneas 2611–2611; tipo `block`.

```text
/* 0:on, 1:off */
```

## 2816. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/wifi.h:2612

Líneas 2612–2612; tipo `block`.

```text
/* 0:good, 1:bad */
```

## 2817. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/wifi.h:2613

Líneas 2613–2613; tipo `block`.

```text
/* 0:SW, 1:SW/HW dynamic */
```

## 2818. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/wifi.h:2720

Líneas 2720–2720; tipo `block`.

```text
/* sort by age */
```

## 2819. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/wifi.h:2752

Líneas 2752–2752; tipo `block`.

```text
/* sta entry list for ap adhoc or mesh */
```

## 2820. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/wifi.h:2755

Líneas 2755–2755; tipo `block`.

```text
/* c2hcmd list for kthread level access */
```

## 2821. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/wifi.h:2761

Líneas 2761–2763; tipo `block`.

```text
/* hal_cfg : for diff cards
	 * intf_ops : for diff interrface usb/pcie
	 */
```

## 2822. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/wifi.h:2767

Líneas 2767–2770; tipo `block`.

```text
/* this var will be set by set_bit,
	 * and was used to indicate status of
	 * interface or hardware
	 */
```

## 2823. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/wifi.h:2773

Líneas 2773–2773; tipo `block`.

```text
/* tables for dm */
```

## 2824. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/wifi.h:2781

Líneas 2781–2781; tipo `block`.

```text
/* true if regs saved */
```

## 2825. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/wifi.h:2786

Líneas 2786–2786; tipo `block`.

```text
/* true when entering PS */
```

## 2826. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/wifi.h:2789

Líneas 2789–2792; tipo `block`.

```text
/* intel Proximity, should be alloc mem
	 * in intel Proximity module and can only
	 * be used in intel Proximity mode
	 */
```

## 2827. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/wifi.h:2795

Líneas 2795–2795; tipo `block`.

```text
/*for bt coexist use*/
```

## 2828. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/wifi.h:2798

Líneas 2798–2800; tipo `block`.

```text
/* separate 92ee from other ICs,
	 * 92ee use new trx flow.
	 */
```

## 2829. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/wifi.h:2806

Líneas 2806–2810; tipo `block`.

```text
/* This must be the last item so
	 * that it points to the data allocated
	 * beyond  this structure like:
	 * rtl_pci_priv or rtl_usb_priv
	 */
```

## 2830. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/wifi.h:2820

Líneas 2820–2820; tipo `block`.

```text
/* Bluetooth Co-existence Related */
```

## 2831. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/wifi.h:2869

Líneas 2869–2875; tipo `block`.

```text
/****************************************
 *	mem access macro define start
 *	Call endian free function when
 *	1. Read/write packet content.
 *	2. Before write integer to IO.
 *	3. After read integer from IO.
 ****************************************/
```

## 2832. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/wifi.h:2880

Líneas 2880–2880; tipo `block`.

```text
/* mem access macro define end */
```

## 2833. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/wifi.h:2893

Líneas 2893–2893; tipo `block`.

```text
/*PCI ASPM */
```

## 2834. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/wifi.h:2894

Líneas 2894–2894; tipo `block`.

```text
/*PCI clock request */
```

## 2835. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/wifi.h:2895

Líneas 2895–2895; tipo `block`.

```text
/*PCI D3 mode */
```

## 2836. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/wifi.h:2896

Líneas 2896–2896; tipo `block`.

```text
/*NIC halt, re-initialize hw parameters*/
```

## 2837. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/wifi.h:2898

Líneas 2898–2898; tipo `block`.

```text
/*FW free, re-download the FW */
```

## 2838. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/wifi.h:2899

Líneas 2899–2899; tipo `block`.

```text
/*FW in 32k */
```

## 2839. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/wifi.h:2900

Líneas 2900–2900; tipo `block`.

```text
/*Always enable ASPM and Clock Req in initialization.*/
```

## 2840. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/wifi.h:2902

Líneas 2902–2902; tipo `block`.

```text
/* no matter RFOFF or SLEEP we set PS_ASPM_LEVL*/
```

## 2841. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/wifi.h:2904

Líneas 2904–2904; tipo `block`.

```text
/*When LPS is on, disable 2R if no packet is received or transmittd.*/
```

## 2842. original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/wifi.h:2906

Líneas 2906–2906; tipo `block`.

```text
/*LPS with ASPM */
```

## 2843. original/linux-5.10.260/include/net/mac80211.h:1

Líneas 1–1; tipo `block`.

```text
/* SPDX-License-Identifier: GPL-2.0-only */
```

## 2844. original/linux-5.10.260/include/net/mac80211.h:2

Líneas 2–11; tipo `block`.

```text
/*
 * mac80211 <-> driver interface
 *
 * Copyright 2002-2005, Devicescape Software, Inc.
 * Copyright 2006-2007	Jiri Benc <jbenc@suse.cz>
 * Copyright 2007-2010	Johannes Berg <johannes@sipsolutions.net>
 * Copyright 2013-2014  Intel Mobile Communications GmbH
 * Copyright (C) 2015 - 2017 Intel Deutschland GmbH
 * Copyright (C) 2018 - 2020 Intel Corporation
 */
```

## 2845. original/linux-5.10.260/include/net/mac80211.h:26

Líneas 26–33; tipo `block`.

```text
/**
 * DOC: Introduction
 *
 * mac80211 is the Linux stack for 802.11 hardware that implements
 * only partial functionality in hard- or firmware. This document
 * defines the interface between mac80211 and low-level hardware
 * drivers.
 */
```

## 2846. original/linux-5.10.260/include/net/mac80211.h:35

Líneas 35–47; tipo `block`.

```text
/**
 * DOC: Calling mac80211 from interrupts
 *
 * Only ieee80211_tx_status_irqsafe() and ieee80211_rx_irqsafe() can be
 * called in hardware interrupt context. The low-level driver must not call any
 * other functions in hardware interrupt context. If there is a need for such
 * call, the low-level driver should first ACK the interrupt and perform the
 * IEEE 802.11 code call after this, e.g. from a scheduled workqueue or even
 * tasklet function.
 *
 * NOTE: If the driver opts to use the _irqsafe() functions, it may not also
 *	 use the non-IRQ-safe functions!
 */
```

## 2847. original/linux-5.10.260/include/net/mac80211.h:49

Líneas 49–54; tipo `block`.

```text
/**
 * DOC: Warning
 *
 * If you're reading this document and not the header file itself, it will
 * be incomplete because not all documentation has been converted yet.
 */
```

## 2848. original/linux-5.10.260/include/net/mac80211.h:56

Líneas 56–71; tipo `block`.

```text
/**
 * DOC: Frame format
 *
 * As a general rule, when frames are passed between mac80211 and the driver,
 * they start with the IEEE 802.11 header and include the same octets that are
 * sent over the air except for the FCS which should be calculated by the
 * hardware.
 *
 * There are, however, various exceptions to this rule for advanced features:
 *
 * The first exception is for hardware encryption and decryption offload
 * where the IV/ICV may or may not be generated in hardware.
 *
 * Secondly, when the hardware handles fragmentation, the frame handed to
 * the driver from mac80211 is the MSDU, not the MPDU.
 */
```

## 2849. original/linux-5.10.260/include/net/mac80211.h:73

Líneas 73–86; tipo `block`.

```text
/**
 * DOC: mac80211 workqueue
 *
 * mac80211 provides its own workqueue for drivers and internal mac80211 use.
 * The workqueue is a single threaded workqueue and can only be accessed by
 * helpers for sanity checking. Drivers must ensure all work added onto the
 * mac80211 workqueue should be cancelled on the driver stop() callback.
 *
 * mac80211 will flushed the workqueue upon interface removal and during
 * suspend.
 *
 * All work performed on the mac80211 workqueue must not acquire the RTNL lock.
 *
 */
```

## 2850. original/linux-5.10.260/include/net/mac80211.h:88

Líneas 88–126; tipo `block`.

```text
/**
 * DOC: mac80211 software tx queueing
 *
 * mac80211 provides an optional intermediate queueing implementation designed
 * to allow the driver to keep hardware queues short and provide some fairness
 * between different stations/interfaces.
 * In this model, the driver pulls data frames from the mac80211 queue instead
 * of letting mac80211 push them via drv_tx().
 * Other frames (e.g. control or management) are still pushed using drv_tx().
 *
 * Drivers indicate that they use this model by implementing the .wake_tx_queue
 * driver operation.
 *
 * Intermediate queues (struct ieee80211_txq) are kept per-sta per-tid, with
 * another per-sta for non-data/non-mgmt and bufferable management frames, and
 * a single per-vif queue for multicast data frames.
 *
 * The driver is expected to initialize its private per-queue data for stations
 * and interfaces in the .add_interface and .sta_add ops.
 *
 * The driver can't access the queue directly. To dequeue a frame from a
 * txq, it calls ieee80211_tx_dequeue(). Whenever mac80211 adds a new frame to a
 * queue, it calls the .wake_tx_queue driver op.
 *
 * Drivers can optionally delegate responsibility for scheduling queues to
 * mac80211, to take advantage of airtime fairness accounting. In this case, to
 * obtain the next queue to pull frames from, the driver calls
 * ieee80211_next_txq(). The driver is then expected to return the txq using
 * ieee80211_return_txq().
 *
 * For AP powersave TIM handling, the driver only needs to indicate if it has
 * buffered packets in the driver specific data structures by calling
 * ieee80211_sta_set_buffered(). For frames buffered in the ieee80211_txq
 * struct, mac80211 sets the appropriate TIM PVB bits and calls
 * .release_buffered_frames().
 * In that callback the driver is therefore expected to release its own
 * buffered frames and afterwards also frames from the ieee80211_txq (obtained
 * via the usual ieee80211_tx_dequeue).
 */
```

## 2851. original/linux-5.10.260/include/net/mac80211.h:130

Líneas 130–135; tipo `block`.

```text
/**
 * enum ieee80211_max_queues - maximum number of queues
 *
 * @IEEE80211_MAX_QUEUES: Maximum number of regular device queues.
 * @IEEE80211_MAX_QUEUE_MAP: bitmap with maximum queues set
 */
```

## 2852. original/linux-5.10.260/include/net/mac80211.h:143

Líneas 143–149; tipo `block`.

```text
/**
 * enum ieee80211_ac_numbers - AC numbers as used in mac80211
 * @IEEE80211_AC_VO: voice
 * @IEEE80211_AC_VI: video
 * @IEEE80211_AC_BE: best effort
 * @IEEE80211_AC_BK: background
 */
```

## 2853. original/linux-5.10.260/include/net/mac80211.h:157

Líneas 157–172; tipo `block`.

```text
/**
 * struct ieee80211_tx_queue_params - transmit queue configuration
 *
 * The information provided in this structure is required for QoS
 * transmit queue configuration. Cf. IEEE 802.11 7.3.2.29.
 *
 * @aifs: arbitration interframe space [0..255]
 * @cw_min: minimum contention window [a value of the form
 *	2^n-1 in the range 1..32767]
 * @cw_max: maximum contention window [like @cw_min]
 * @txop: maximum burst time in units of 32 usecs, 0 meaning disabled
 * @acm: is mandatory admission control required for the access category
 * @uapsd: is U-APSD mode enabled for the queue
 * @mu_edca: is the MU EDCA configured
 * @mu_edca_param_rec: MU EDCA Parameter Record for HE
 */
```

## 2854. original/linux-5.10.260/include/net/mac80211.h:191

Líneas 191–199; tipo `block`.

```text
/**
 * enum ieee80211_chanctx_change - change flag for channel context
 * @IEEE80211_CHANCTX_CHANGE_WIDTH: The channel width changed
 * @IEEE80211_CHANCTX_CHANGE_RX_CHAINS: The number of RX chains changed
 * @IEEE80211_CHANCTX_CHANGE_RADAR: radar detection flag changed
 * @IEEE80211_CHANCTX_CHANGE_CHANNEL: switched to another operating channel,
 *	this is used only with channel switching with CSA
 * @IEEE80211_CHANCTX_CHANGE_MIN_WIDTH: The min required channel width changed
 */
```

## 2855. original/linux-5.10.260/include/net/mac80211.h:208

Líneas 208–224; tipo `block`.

```text
/**
 * struct ieee80211_chanctx_conf - channel context that vifs may be tuned to
 *
 * This is the driver-visible part. The ieee80211_chanctx
 * that contains it is visible in mac80211 only.
 *
 * @def: the channel definition
 * @min_def: the minimum channel definition currently required.
 * @rx_chains_static: The number of RX chains that must always be
 *	active on the channel to receive MIMO transmissions
 * @rx_chains_dynamic: The number of RX chains that must be enabled
 *	after RTS/CTS handshake to receive SMPS MIMO transmissions;
 *	this will always be >= @rx_chains_static.
 * @radar_enabled: whether radar detection is enabled on this channel.
 * @drv_priv: data area for driver use, will always be aligned to
 *	sizeof(void *), size is determined in hw information.
 */
```

## 2856. original/linux-5.10.260/include/net/mac80211.h:236

Líneas 236–249; tipo `block`.

```text
/**
 * enum ieee80211_chanctx_switch_mode - channel context switch mode
 * @CHANCTX_SWMODE_REASSIGN_VIF: Both old and new contexts already
 *	exist (and will continue to exist), but the virtual interface
 *	needs to be switched from one to the other.
 * @CHANCTX_SWMODE_SWAP_CONTEXTS: The old context exists but will stop
 *      to exist with this call, the new context doesn't exist but
 *      will be active after this call, the virtual interface switches
 *      from the old to the new (note that the driver may of course
 *      implement this as an on-the-fly chandef switch of the existing
 *      hardware context, but the mac80211 pointer for the old context
 *      will cease to exist and only the new one will later be used
 *      for changes/removal.)
 */
```

## 2857. original/linux-5.10.260/include/net/mac80211.h:255

Líneas 255–266; tipo `block`.

```text
/**
 * struct ieee80211_vif_chanctx_switch - vif chanctx switch information
 *
 * This is structure is used to pass information about a vif that
 * needs to switch from one chanctx to another.  The
 * &ieee80211_chanctx_switch_mode defines how the switch should be
 * done.
 *
 * @vif: the vif that should be switched from old_ctx to new_ctx
 * @old_ctx: the old context to which the vif was assigned
 * @new_ctx: the new context to which the vif must be assigned
 */
```

## 2858. original/linux-5.10.260/include/net/mac80211.h:273

Líneas 273–324; tipo `block`.

```text
/**
 * enum ieee80211_bss_change - BSS change notification flags
 *
 * These flags are used with the bss_info_changed() callback
 * to indicate which BSS parameter changed.
 *
 * @BSS_CHANGED_ASSOC: association status changed (associated/disassociated),
 *	also implies a change in the AID.
 * @BSS_CHANGED_ERP_CTS_PROT: CTS protection changed
 * @BSS_CHANGED_ERP_PREAMBLE: preamble changed
 * @BSS_CHANGED_ERP_SLOT: slot timing changed
 * @BSS_CHANGED_HT: 802.11n parameters changed
 * @BSS_CHANGED_BASIC_RATES: Basic rateset changed
 * @BSS_CHANGED_BEACON_INT: Beacon interval changed
 * @BSS_CHANGED_BSSID: BSSID changed, for whatever
 *	reason (IBSS and managed mode)
 * @BSS_CHANGED_BEACON: Beacon data changed, retrieve
 *	new beacon (beaconing modes)
 * @BSS_CHANGED_BEACON_ENABLED: Beaconing should be
 *	enabled/disabled (beaconing modes)
 * @BSS_CHANGED_CQM: Connection quality monitor config changed
 * @BSS_CHANGED_IBSS: IBSS join status changed
 * @BSS_CHANGED_ARP_FILTER: Hardware ARP filter address list or state changed.
 * @BSS_CHANGED_QOS: QoS for this association was enabled/disabled. Note
 *	that it is only ever disabled for station mode.
 * @BSS_CHANGED_IDLE: Idle changed for this BSS/interface.
 * @BSS_CHANGED_SSID: SSID changed for this BSS (AP and IBSS mode)
 * @BSS_CHANGED_AP_PROBE_RESP: Probe Response changed for this BSS (AP mode)
 * @BSS_CHANGED_PS: PS changed for this BSS (STA mode)
 * @BSS_CHANGED_TXPOWER: TX power setting changed for this interface
 * @BSS_CHANGED_P2P_PS: P2P powersave settings (CTWindow, opportunistic PS)
 *	changed
 * @BSS_CHANGED_BEACON_INFO: Data from the AP's beacon became available:
 *	currently dtim_period only is under consideration.
 * @BSS_CHANGED_BANDWIDTH: The bandwidth used by this interface changed,
 *	note that this is only called when it changes after the channel
 *	context had been assigned.
 * @BSS_CHANGED_OCB: OCB join status changed
 * @BSS_CHANGED_MU_GROUPS: VHT MU-MIMO group id or user position changed
 * @BSS_CHANGED_KEEP_ALIVE: keep alive options (idle period or protected
 *	keep alive) changed.
 * @BSS_CHANGED_MCAST_RATE: Multicast Rate setting changed for this interface
 * @BSS_CHANGED_FTM_RESPONDER: fine timing measurement request responder
 *	functionality changed for this BSS (AP mode).
 * @BSS_CHANGED_TWT: TWT status changed
 * @BSS_CHANGED_HE_OBSS_PD: OBSS Packet Detection status changed.
 * @BSS_CHANGED_HE_BSS_COLOR: BSS Color has changed
 * @BSS_CHANGED_FILS_DISCOVERY: FILS discovery status changed.
 * @BSS_CHANGED_UNSOL_BCAST_PROBE_RESP: Unsolicited broadcast probe response
 *	status changed.
 *
 */
```

## 2859. original/linux-5.10.260/include/net/mac80211.h:359

Líneas 359–359; tipo `block`.

```text
/* when adding here, make sure to change ieee80211_reconfig */
```

## 2860. original/linux-5.10.260/include/net/mac80211.h:362

Líneas 362–366; tipo `block`.

```text
/*
 * The maximum number of IPv4 addresses listed for ARP filtering. If the number
 * of addresses for an interface increase beyond this value, hardware ARP
 * filtering will be disabled.
 */
```

## 2861. original/linux-5.10.260/include/net/mac80211.h:369

Líneas 369–377; tipo `block`.

```text
/**
 * enum ieee80211_event_type - event to be notified to the low level driver
 * @RSSI_EVENT: AP's rssi crossed the a threshold set by the driver.
 * @MLME_EVENT: event related to MLME
 * @BAR_RX_EVENT: a BAR was received
 * @BA_FRAME_TIMEOUT: Frames were released from the reordering buffer because
 *	they timed out. This won't be called for each frame released, but only
 *	once each time the timeout triggers.
 */
```

## 2862. original/linux-5.10.260/include/net/mac80211.h:385

Líneas 385–389; tipo `block`.

```text
/**
 * enum ieee80211_rssi_event_data - relevant when event type is %RSSI_EVENT
 * @RSSI_EVENT_HIGH: AP's rssi went below the threshold set by the driver.
 * @RSSI_EVENT_LOW: AP's rssi went above the threshold set by the driver.
 */
```

## 2863. original/linux-5.10.260/include/net/mac80211.h:395

Líneas 395–398; tipo `block`.

```text
/**
 * struct ieee80211_rssi_event - data attached to an %RSSI_EVENT
 * @data: See &enum ieee80211_rssi_event_data
 */
```

## 2864. original/linux-5.10.260/include/net/mac80211.h:403

Líneas 403–409; tipo `block`.

```text
/**
 * enum ieee80211_mlme_event_data - relevant when event type is %MLME_EVENT
 * @AUTH_EVENT: the MLME operation is authentication
 * @ASSOC_EVENT: the MLME operation is association
 * @DEAUTH_RX_EVENT: deauth received..
 * @DEAUTH_TX_EVENT: deauth sent.
 */
```

## 2865. original/linux-5.10.260/include/net/mac80211.h:417

Líneas 417–422; tipo `block`.

```text
/**
 * enum ieee80211_mlme_event_status - relevant when event type is %MLME_EVENT
 * @MLME_SUCCESS: the MLME operation completed successfully.
 * @MLME_DENIED: the MLME operation was denied by the peer.
 * @MLME_TIMEOUT: the MLME operation timed out.
 */
```

## 2866. original/linux-5.10.260/include/net/mac80211.h:429

Líneas 429–434; tipo `block`.

```text
/**
 * struct ieee80211_mlme_event - data attached to an %MLME_EVENT
 * @data: See &enum ieee80211_mlme_event_data
 * @status: See &enum ieee80211_mlme_event_status
 * @reason: the reason code if applicable
 */
```

## 2867. original/linux-5.10.260/include/net/mac80211.h:441

Líneas 441–446; tipo `block`.

```text
/**
 * struct ieee80211_ba_event - data attached for BlockAck related events
 * @sta: pointer to the &ieee80211_sta to which this event relates
 * @tid: the tid
 * @ssn: the starting sequence number (for %BAR_RX_EVENT)
 */
```

## 2868. original/linux-5.10.260/include/net/mac80211.h:453

Líneas 453–460; tipo `block`.

```text
/**
 * struct ieee80211_event - event to be sent to the driver
 * @type: The event itself. See &enum ieee80211_event_type.
 * @rssi: relevant if &type is %RSSI_EVENT
 * @mlme: relevant if &type is %AUTH_EVENT
 * @ba: relevant if &type is %BAR_RX_EVENT or %BA_FRAME_TIMEOUT
 * @u:union holding the fields above
 */
```

## 2869. original/linux-5.10.260/include/net/mac80211.h:470

Líneas 470–477; tipo `block`.

```text
/**
 * struct ieee80211_mu_group_data - STA's VHT MU-MIMO group data
 *
 * This structure describes the group id data of VHT MU-MIMO
 *
 * @membership: 64 bits array - a bit is set if station is member of the group
 * @position: 2 bits per group id indicating the position in the group
 */
```

## 2870. original/linux-5.10.260/include/net/mac80211.h:483

Líneas 483–490; tipo `block`.

```text
/**
 * struct ieee80211_ftm_responder_params - FTM responder parameters
 *
 * @lci: LCI subelement content
 * @civicloc: CIVIC location subelement content
 * @lci_len: LCI data length
 * @civicloc_len: Civic data length
 */
```

## 2871. original/linux-5.10.260/include/net/mac80211.h:498

Líneas 498–504; tipo `block`.

```text
/**
 * struct ieee80211_fils_discovery - FILS discovery parameters from
 * IEEE Std 802.11ai-2016, Annex C.3 MIB detail.
 *
 * @min_interval: Minimum packet interval in TUs (0 - 10000)
 * @max_interval: Maximum packet interval in TUs (0 - 10000)
 */
```

## 2872. original/linux-5.10.260/include/net/mac80211.h:510

Líneas 510–633; tipo `block`.

```text
/**
 * struct ieee80211_bss_conf - holds the BSS's changing parameters
 *
 * This structure keeps information about a BSS (and an association
 * to that BSS) that can change during the lifetime of the BSS.
 *
 * @htc_trig_based_pkt_ext: default PE in 4us units, if BSS supports HE
 * @multi_sta_back_32bit: supports BA bitmap of 32-bits in Multi-STA BACK
 * @uora_exists: is the UORA element advertised by AP
 * @ack_enabled: indicates support to receive a multi-TID that solicits either
 *	ACK, BACK or both
 * @uora_ocw_range: UORA element's OCW Range field
 * @frame_time_rts_th: HE duration RTS threshold, in units of 32us
 * @he_support: does this BSS support HE
 * @twt_requester: does this BSS support TWT requester (relevant for managed
 *	mode only, set if the AP advertises TWT responder role)
 * @twt_responder: does this BSS support TWT requester (relevant for managed
 *	mode only, set if the AP advertises TWT responder role)
 * @twt_protected: does this BSS support protected TWT frames
 * @assoc: association status
 * @ibss_joined: indicates whether this station is part of an IBSS
 *	or not
 * @ibss_creator: indicates if a new IBSS network is being created
 * @aid: association ID number, valid only when @assoc is true
 * @use_cts_prot: use CTS protection
 * @use_short_preamble: use 802.11b short preamble
 * @use_short_slot: use short slot time (only relevant for ERP)
 * @dtim_period: num of beacons before the next DTIM, for beaconing,
 *	valid in station mode only if after the driver was notified
 *	with the %BSS_CHANGED_BEACON_INFO flag, will be non-zero then.
 * @sync_tsf: last beacon's/probe response's TSF timestamp (could be old
 *	as it may have been received during scanning long ago). If the
 *	HW flag %IEEE80211_HW_TIMING_BEACON_ONLY is set, then this can
 *	only come from a beacon, but might not become valid until after
 *	association when a beacon is received (which is notified with the
 *	%BSS_CHANGED_DTIM flag.). See also sync_dtim_count important notice.
 * @sync_device_ts: the device timestamp corresponding to the sync_tsf,
 *	the driver/device can use this to calculate synchronisation
 *	(see @sync_tsf). See also sync_dtim_count important notice.
 * @sync_dtim_count: Only valid when %IEEE80211_HW_TIMING_BEACON_ONLY
 *	is requested, see @sync_tsf/@sync_device_ts.
 *	IMPORTANT: These three sync_* parameters would possibly be out of sync
 *	by the time the driver will use them. The synchronized view is currently
 *	guaranteed only in certain callbacks.
 * @beacon_int: beacon interval
 * @assoc_capability: capabilities taken from assoc resp
 * @basic_rates: bitmap of basic rates, each bit stands for an
 *	index into the rate table configured by the driver in
 *	the current band.
 * @beacon_rate: associated AP's beacon TX rate
 * @mcast_rate: per-band multicast rate index + 1 (0: disabled)
 * @bssid: The BSSID for this BSS
 * @enable_beacon: whether beaconing should be enabled or not
 * @chandef: Channel definition for this BSS -- the hardware might be
 *	configured a higher bandwidth than this BSS uses, for example.
 * @mu_group: VHT MU-MIMO group membership data
 * @ht_operation_mode: HT operation mode like in &struct ieee80211_ht_operation.
 *	This field is only valid when the channel is a wide HT/VHT channel.
 *	Note that with TDLS this can be the case (channel is HT, protection must
 *	be used from this field) even when the BSS association isn't using HT.
 * @cqm_rssi_thold: Connection quality monitor RSSI threshold, a zero value
 *	implies disabled. As with the cfg80211 callback, a change here should
 *	cause an event to be sent indicating where the current value is in
 *	relation to the newly configured threshold.
 * @cqm_rssi_low: Connection quality monitor RSSI lower threshold, a zero value
 *	implies disabled.  This is an alternative mechanism to the single
 *	threshold event and can't be enabled simultaneously with it.
 * @cqm_rssi_high: Connection quality monitor RSSI upper threshold.
 * @cqm_rssi_hyst: Connection quality monitor RSSI hysteresis
 * @arp_addr_list: List of IPv4 addresses for hardware ARP filtering. The
 *	may filter ARP queries targeted for other addresses than listed here.
 *	The driver must allow ARP queries targeted for all address listed here
 *	to pass through. An empty list implies no ARP queries need to pass.
 * @arp_addr_cnt: Number of addresses currently on the list. Note that this
 *	may be larger than %IEEE80211_BSS_ARP_ADDR_LIST_LEN (the arp_addr_list
 *	array size), it's up to the driver what to do in that case.
 * @qos: This is a QoS-enabled BSS.
 * @idle: This interface is idle. There's also a global idle flag in the
 *	hardware config which may be more appropriate depending on what
 *	your driver/device needs to do.
 * @ps: power-save mode (STA only). This flag is NOT affected by
 *	offchannel/dynamic_ps operations.
 * @ssid: The SSID of the current vif. Valid in AP and IBSS mode.
 * @ssid_len: Length of SSID given in @ssid.
 * @hidden_ssid: The SSID of the current vif is hidden. Only valid in AP-mode.
 * @txpower: TX power in dBm.  INT_MIN means not configured.
 * @txpower_type: TX power adjustment used to control per packet Transmit
 *	Power Control (TPC) in lower driver for the current vif. In particular
 *	TPC is enabled if value passed in %txpower_type is
 *	NL80211_TX_POWER_LIMITED (allow using less than specified from
 *	userspace), whereas TPC is disabled if %txpower_type is set to
 *	NL80211_TX_POWER_FIXED (use value configured from userspace)
 * @p2p_noa_attr: P2P NoA attribute for P2P powersave
 * @allow_p2p_go_ps: indication for AP or P2P GO interface, whether it's allowed
 *	to use P2P PS mechanism or not. AP/P2P GO is not allowed to use P2P PS
 *	if it has associated clients without P2P PS support.
 * @max_idle_period: the time period during which the station can refrain from
 *	transmitting frames to its associated AP without being disassociated.
 *	In units of 1000 TUs. Zero value indicates that the AP did not include
 *	a (valid) BSS Max Idle Period Element.
 * @protected_keep_alive: if set, indicates that the station should send an RSN
 *	protected frame to the AP to reset the idle timer at the AP for the
 *	station.
 * @ftm_responder: whether to enable or disable fine timing measurement FTM
 *	responder functionality.
 * @ftmr_params: configurable lci/civic parameter when enabling FTM responder.
 * @nontransmitted: this BSS is a nontransmitted BSS profile
 * @transmitter_bssid: the address of transmitter AP
 * @bssid_index: index inside the multiple BSSID set
 * @bssid_indicator: 2^bssid_indicator is the maximum number of APs in set
 * @ema_ap: AP supports enhancements of discovery and advertisement of
 *	nontransmitted BSSIDs
 * @profile_periodicity: the least number of beacon frames need to be received
 *	in order to discover all the nontransmitted BSSIDs in the set.
 * @he_oper: HE operation information of the AP we are connected to
 * @he_obss_pd: OBSS Packet Detection parameters.
 * @he_bss_color: BSS coloring settings, if BSS supports HE
 * @fils_discovery: FILS discovery configuration
 * @unsol_bcast_probe_resp_interval: Unsolicited broadcast probe response
 *	interval.
 * @s1g: BSS is S1G BSS (affects Association Request format).
 * @beacon_tx_rate: The configured beacon transmit rate that needs to be passed
 *	to driver when rate control is offloaded to firmware.
 */
```

## 2873. original/linux-5.10.260/include/net/mac80211.h:646

Líneas 646–646; tipo `block`.

```text
/* association related data */
```

## 2874. original/linux-5.10.260/include/net/mac80211.h:650

Líneas 650–650; tipo `block`.

```text
/* erp related data */
```

## 2875. original/linux-5.10.260/include/net/mac80211.h:687

Líneas 687–687; tipo `block`.

```text
/* Multiple BSSID data */
```

## 2876. original/linux-5.10.260/include/net/mac80211.h:706

Líneas 706–804; tipo `block`.

```text
/**
 * enum mac80211_tx_info_flags - flags to describe transmission information/status
 *
 * These flags are used with the @flags member of &ieee80211_tx_info.
 *
 * @IEEE80211_TX_CTL_REQ_TX_STATUS: require TX status callback for this frame.
 * @IEEE80211_TX_CTL_ASSIGN_SEQ: The driver has to assign a sequence
 *	number to this frame, taking care of not overwriting the fragment
 *	number and increasing the sequence number only when the
 *	IEEE80211_TX_CTL_FIRST_FRAGMENT flag is set. mac80211 will properly
 *	assign sequence numbers to QoS-data frames but cannot do so correctly
 *	for non-QoS-data and management frames because beacons need them from
 *	that counter as well and mac80211 cannot guarantee proper sequencing.
 *	If this flag is set, the driver should instruct the hardware to
 *	assign a sequence number to the frame or assign one itself. Cf. IEEE
 *	802.11-2007 7.1.3.4.1 paragraph 3. This flag will always be set for
 *	beacons and always be clear for frames without a sequence number field.
 * @IEEE80211_TX_CTL_NO_ACK: tell the low level not to wait for an ack
 * @IEEE80211_TX_CTL_CLEAR_PS_FILT: clear powersave filter for destination
 *	station
 * @IEEE80211_TX_CTL_FIRST_FRAGMENT: this is a first fragment of the frame
 * @IEEE80211_TX_CTL_SEND_AFTER_DTIM: send this frame after DTIM beacon
 * @IEEE80211_TX_CTL_AMPDU: this frame should be sent as part of an A-MPDU
 * @IEEE80211_TX_CTL_INJECTED: Frame was injected, internal to mac80211.
 * @IEEE80211_TX_STAT_TX_FILTERED: The frame was not transmitted
 *	because the destination STA was in powersave mode. Note that to
 *	avoid race conditions, the filter must be set by the hardware or
 *	firmware upon receiving a frame that indicates that the station
 *	went to sleep (must be done on device to filter frames already on
 *	the queue) and may only be unset after mac80211 gives the OK for
 *	that by setting the IEEE80211_TX_CTL_CLEAR_PS_FILT (see above),
 *	since only then is it guaranteed that no more frames are in the
 *	hardware queue.
 * @IEEE80211_TX_STAT_ACK: Frame was acknowledged
 * @IEEE80211_TX_STAT_AMPDU: The frame was aggregated, so status
 * 	is for the whole aggregation.
 * @IEEE80211_TX_STAT_AMPDU_NO_BACK: no block ack was returned,
 * 	so consider using block ack request (BAR).
 * @IEEE80211_TX_CTL_RATE_CTRL_PROBE: internal to mac80211, can be
 *	set by rate control algorithms to indicate probe rate, will
 *	be cleared for fragmented frames (except on the last fragment)
 * @IEEE80211_TX_INTFL_OFFCHAN_TX_OK: Internal to mac80211. Used to indicate
 *	that a frame can be transmitted while the queues are stopped for
 *	off-channel operation.
 * @IEEE80211_TX_CTL_HW_80211_ENCAP: This frame uses hardware encapsulation
 *	(header conversion)
 * @IEEE80211_TX_INTFL_RETRIED: completely internal to mac80211,
 *	used to indicate that a frame was already retried due to PS
 * @IEEE80211_TX_INTFL_DONT_ENCRYPT: completely internal to mac80211,
 *	used to indicate frame should not be encrypted
 * @IEEE80211_TX_CTL_NO_PS_BUFFER: This frame is a response to a poll
 *	frame (PS-Poll or uAPSD) or a non-bufferable MMPDU and must
 *	be sent although the station is in powersave mode.
 * @IEEE80211_TX_CTL_MORE_FRAMES: More frames will be passed to the
 *	transmit function after the current frame, this can be used
 *	by drivers to kick the DMA queue only if unset or when the
 *	queue gets full.
 * @IEEE80211_TX_INTFL_RETRANSMISSION: This frame is being retransmitted
 *	after TX status because the destination was asleep, it must not
 *	be modified again (no seqno assignment, crypto, etc.)
 * @IEEE80211_TX_INTFL_MLME_CONN_TX: This frame was transmitted by the MLME
 *	code for connection establishment, this indicates that its status
 *	should kick the MLME state machine.
 * @IEEE80211_TX_INTFL_NL80211_FRAME_TX: Frame was requested through nl80211
 *	MLME command (internal to mac80211 to figure out whether to send TX
 *	status to user space)
 * @IEEE80211_TX_CTL_LDPC: tells the driver to use LDPC for this frame
 * @IEEE80211_TX_CTL_STBC: Enables Space-Time Block Coding (STBC) for this
 *	frame and selects the maximum number of streams that it can use.
 * @IEEE80211_TX_CTL_TX_OFFCHAN: Marks this packet to be transmitted on
 *	the off-channel channel when a remain-on-channel offload is done
 *	in hardware -- normal packets still flow and are expected to be
 *	handled properly by the device.
 * @IEEE80211_TX_INTFL_TKIP_MIC_FAILURE: Marks this packet to be used for TKIP
 *	testing. It will be sent out with incorrect Michael MIC key to allow
 *	TKIP countermeasures to be tested.
 * @IEEE80211_TX_CTL_NO_CCK_RATE: This frame will be sent at non CCK rate.
 *	This flag is actually used for management frame especially for P2P
 *	frames not being sent at CCK rate in 2GHz band.
 * @IEEE80211_TX_STATUS_EOSP: This packet marks the end of service period,
 *	when its status is reported the service period ends. For frames in
 *	an SP that mac80211 transmits, it is already set; for driver frames
 *	the driver may set this flag. It is also used to do the same for
 *	PS-Poll responses.
 * @IEEE80211_TX_CTL_USE_MINRATE: This frame will be sent at lowest rate.
 *	This flag is used to send nullfunc frame at minimum rate when
 *	the nullfunc is used for connection monitoring purpose.
 * @IEEE80211_TX_CTL_DONTFRAG: Don't fragment this packet even if it
 *	would be fragmented by size (this is optional, only used for
 *	monitor injection).
 * @IEEE80211_TX_STAT_NOACK_TRANSMITTED: A frame that was marked with
 *	IEEE80211_TX_CTL_NO_ACK has been successfully transmitted without
 *	any errors (like issues specific to the driver/HW).
 *	This flag must not be set for frames that don't request no-ack
 *	behaviour with IEEE80211_TX_CTL_NO_ACK.
 *
 * Note: If you have to add new flags to the enumeration, then don't
 *	 forget to update %IEEE80211_TX_TEMPORARY_FLAGS when necessary.
 */
```

## 2877. original/linux-5.10.260/include/net/mac80211.h:843

Líneas 843–861; tipo `block`.

```text
/**
 * enum mac80211_tx_control_flags - flags to describe transmit control
 *
 * @IEEE80211_TX_CTRL_PORT_CTRL_PROTO: this frame is a port control
 *	protocol frame (e.g. EAP)
 * @IEEE80211_TX_CTRL_PS_RESPONSE: This frame is a response to a poll
 *	frame (PS-Poll or uAPSD).
 * @IEEE80211_TX_CTRL_RATE_INJECT: This frame is injected with rate information
 * @IEEE80211_TX_CTRL_AMSDU: This frame is an A-MSDU frame
 * @IEEE80211_TX_CTRL_FAST_XMIT: This frame is going through the fast_xmit path
 * @IEEE80211_TX_CTRL_SKIP_MPATH_LOOKUP: This frame skips mesh path lookup
 * @IEEE80211_TX_INTCFL_NEED_TXPROCESSING: completely internal to mac80211,
 *	used to indicate that a pending frame requires TX processing before
 *	it can be sent out.
 * @IEEE80211_TX_CTRL_NO_SEQNO: Do not overwrite the sequence number that
 *	has already been assigned to this frame.
 *
 * These flags are used in tx_info->control.flags.
 */
```

## 2878. original/linux-5.10.260/include/net/mac80211.h:873

Líneas 873–876; tipo `block`.

```text
/*
 * This definition is used as a mask to clear all temporary flags, which are
 * set by the tx handlers for each transmission attempt by the mac80211 stack.
 */
```

## 2879. original/linux-5.10.260/include/net/mac80211.h:886

Líneas 886–910; tipo `block`.

```text
/**
 * enum mac80211_rate_control_flags - per-rate flags set by the
 *	Rate Control algorithm.
 *
 * These flags are set by the Rate control algorithm for each rate during tx,
 * in the @flags member of struct ieee80211_tx_rate.
 *
 * @IEEE80211_TX_RC_USE_RTS_CTS: Use RTS/CTS exchange for this rate.
 * @IEEE80211_TX_RC_USE_CTS_PROTECT: CTS-to-self protection is required.
 *	This is set if the current BSS requires ERP protection.
 * @IEEE80211_TX_RC_USE_SHORT_PREAMBLE: Use short preamble.
 * @IEEE80211_TX_RC_MCS: HT rate.
 * @IEEE80211_TX_RC_VHT_MCS: VHT MCS rate, in this case the idx field is split
 *	into a higher 4 bits (Nss) and lower 4 bits (MCS number)
 * @IEEE80211_TX_RC_GREEN_FIELD: Indicates whether this rate should be used in
 *	Greenfield mode.
 * @IEEE80211_TX_RC_40_MHZ_WIDTH: Indicates if the Channel Width should be 40 MHz.
 * @IEEE80211_TX_RC_80_MHZ_WIDTH: Indicates 80 MHz transmission
 * @IEEE80211_TX_RC_160_MHZ_WIDTH: Indicates 160 MHz transmission
 *	(80+80 isn't supported yet)
 * @IEEE80211_TX_RC_DUP_DATA: The frame should be transmitted on both of the
 *	adjacent 20 MHz channels, if the current channel type is
 *	NL80211_CHAN_HT40MINUS or NL80211_CHAN_HT40PLUS.
 * @IEEE80211_TX_RC_SHORT_GI: Short Guard interval should be used for this rate.
 */
```

## 2880. original/linux-5.10.260/include/net/mac80211.h:916

Líneas 916–916; tipo `block`.

```text
/* rate index is an HT/VHT MCS instead of an index */
```

## 2881. original/linux-5.10.260/include/net/mac80211.h:928

Líneas 928–928; tipo `block`.

```text
/* there are 40 bytes if you don't need the rateset to be kept */
```

## 2882. original/linux-5.10.260/include/net/mac80211.h:931

Líneas 931–931; tipo `block`.

```text
/* if you do need the rateset, then you have less space */
```

## 2883. original/linux-5.10.260/include/net/mac80211.h:934

Líneas 934–934; tipo `block`.

```text
/* maximum number of rate stages */
```

## 2884. original/linux-5.10.260/include/net/mac80211.h:937

Líneas 937–937; tipo `block`.

```text
/* maximum number of rate table entries */
```

## 2885. original/linux-5.10.260/include/net/mac80211.h:940

Líneas 940–971; tipo `block`.

```text
/**
 * struct ieee80211_tx_rate - rate selection/status
 *
 * @idx: rate index to attempt to send with
 * @flags: rate control flags (&enum mac80211_rate_control_flags)
 * @count: number of tries in this rate before going to the next rate
 *
 * A value of -1 for @idx indicates an invalid rate and, if used
 * in an array of retry rates, that no more rates should be tried.
 *
 * When used for transmit status reporting, the driver should
 * always report the rate along with the flags it used.
 *
 * &struct ieee80211_tx_info contains an array of these structs
 * in the control information, and it will be filled by the rate
 * control algorithm according to what should be sent. For example,
 * if this array contains, in the format { <idx>, <count> } the
 * information::
 *
 *    { 3, 2 }, { 2, 2 }, { 1, 4 }, { -1, 0 }, { -1, 0 }
 *
 * then this means that the frame should be transmitted
 * up to twice at rate 3, up to twice at rate 2, and up to four
 * times at rate 1 if it doesn't get acknowledged. Say it gets
 * acknowledged by the peer after the fifth attempt, the status
 * information should then contain::
 *
 *   { 3, 2 }, { 2, 2 }, { 1, 1 }, { -1, 0 } ...
 *
 * since it was transmitted twice at rate 3, twice at rate 2
 * and once at rate 1 after which we received an acknowledgement.
 */
```

## 2886. original/linux-5.10.260/include/net/mac80211.h:1000

Líneas 1000–1046; tipo `block`.

```text
/**
 * struct ieee80211_tx_info - skb transmit information
 *
 * This structure is placed in skb->cb for three uses:
 *  (1) mac80211 TX control - mac80211 tells the driver what to do
 *  (2) driver internal use (if applicable)
 *  (3) TX status information - driver tells mac80211 what happened
 *
 * @flags: transmit info flags, defined above
 * @band: the band to transmit on (use for checking for races)
 * @hw_queue: HW queue to put the frame on, skb_get_queue_mapping() gives the AC
 * @ack_frame_id: internal frame ID for TX status, used internally
 * @tx_time_est: TX time estimate in units of 4us, used internally
 * @control: union part for control data
 * @control.rates: TX rates array to try
 * @control.rts_cts_rate_idx: rate for RTS or CTS
 * @control.use_rts: use RTS
 * @control.use_cts_prot: use RTS/CTS
 * @control.short_preamble: use short preamble (CCK only)
 * @control.skip_table: skip externally configured rate table
 * @control.jiffies: timestamp for expiry on powersave clients
 * @control.vif: virtual interface (may be NULL)
 * @control.hw_key: key to encrypt with (may be NULL)
 * @control.flags: control flags, see &enum mac80211_tx_control_flags
 * @control.enqueue_time: enqueue time (for iTXQs)
 * @driver_rates: alias to @control.rates to reserve space
 * @pad: padding
 * @rate_driver_data: driver use area if driver needs @control.rates
 * @status: union part for status data
 * @status.rates: attempted rates
 * @status.ack_signal: ACK signal
 * @status.ampdu_ack_len: AMPDU ack length
 * @status.ampdu_len: AMPDU length
 * @status.antenna: (legacy, kept only for iwlegacy)
 * @status.tx_time: airtime consumed for transmission; note this is only
 *	used for WMM AC, not for airtime fairness
 * @status.is_valid_ack_signal: ACK signal is valid
 * @status.status_driver_data: driver use area
 * @ack: union part for pure ACK data
 * @ack.cookie: cookie for the ACK
 * @driver_data: array of driver_data pointers
 * @ampdu_ack_len: number of acked aggregated frames.
 * 	relevant only if IEEE80211_TX_STAT_AMPDU was set.
 * @ampdu_len: number of aggregated frames.
 * 	relevant only if IEEE80211_TX_STAT_AMPDU was set.
 * @ack_signal: signal strength of the ACK frame
 */
```

## 2887. original/linux-5.10.260/include/net/mac80211.h:1048

Líneas 1048–1048; tipo `block`.

```text
/* common information */
```

## 2888. original/linux-5.10.260/include/net/mac80211.h:1054

Líneas 1054–1054; tipo `block`.

```text
/* 2 free bits */
```

## 2889. original/linux-5.10.260/include/net/mac80211.h:1059

Líneas 1059–1059; tipo `block`.

```text
/* rate control */
```

## 2890. original/linux-5.10.260/include/net/mac80211.h:1068

Líneas 1068–1068; tipo `block`.

```text
/* 2 bytes free */
```

## 2891. original/linux-5.10.260/include/net/mac80211.h:1070

Líneas 1070–1070; tipo `block`.

```text
/* only needed before rate control */
```

## 2892. original/linux-5.10.260/include/net/mac80211.h:1073

Líneas 1073–1073; tipo `block`.

```text
/* NB: vif can be NULL for injected frames */
```

## 2893. original/linux-5.10.260/include/net/mac80211.h:1108

Líneas 1108–1110; tipo `block`.

```text
/* We only have 10 bits in tx_time_est, so store airtime
	 * in increments of 4us and clamp the maximum to 2**12-1
	 */
```

## 2894. original/linux-5.10.260/include/net/mac80211.h:1121

Líneas 1121–1129; tipo `block`.

```text
/**
 * struct ieee80211_tx_status - extended tx status info for rate control
 *
 * @sta: Station that the packet was transmitted for
 * @info: Basic tx status information
 * @skb: Packet skb (can be NULL if not provided by the driver)
 * @rate: The TX rate that was used when sending the packet
 * @free_list: list where processed skbs are stored to be free'd by the driver
 */
```

## 2895. original/linux-5.10.260/include/net/mac80211.h:1138

Líneas 1138–1149; tipo `block`.

```text
/**
 * struct ieee80211_scan_ies - descriptors for different blocks of IEs
 *
 * This structure is used to point to different blocks of IEs in HW scan
 * and scheduled scan. These blocks contain the IEs passed by userspace
 * and the ones generated by mac80211.
 *
 * @ies: pointers to band specific IEs.
 * @len: lengths of band_specific IEs.
 * @common_ies: IEs for all bands (especially vendor specific ones)
 * @common_ie_len: length of the common_ies
 */
```

## 2896. original/linux-5.10.260/include/net/mac80211.h:1168

Líneas 1168–1181; tipo `block`.

```text
/**
 * ieee80211_tx_info_clear_status - clear TX status
 *
 * @info: The &struct ieee80211_tx_info to be cleared.
 *
 * When the driver passes an skb back to mac80211, it must report
 * a number of things in TX status. This function clears everything
 * in the TX status but the rate control information (it does clear
 * the count since you need to fill that in anyway).
 *
 * NOTE: You can only use this function if you do NOT use
 *	 info->driver_data! Use info->rate_driver_data
 *	 instead if you need only the less space that allows.
 */
```

## 2897. original/linux-5.10.260/include/net/mac80211.h:1192

Líneas 1192–1192; tipo `block`.

```text
/* clear the rate counts */
```

## 2898. original/linux-5.10.260/include/net/mac80211.h:1204

Líneas 1204–1296; tipo `block`.

```text
/**
 * enum mac80211_rx_flags - receive flags
 *
 * These flags are used with the @flag member of &struct ieee80211_rx_status.
 * @RX_FLAG_MMIC_ERROR: Michael MIC error was reported on this frame.
 *	Use together with %RX_FLAG_MMIC_STRIPPED.
 * @RX_FLAG_DECRYPTED: This frame was decrypted in hardware.
 * @RX_FLAG_MMIC_STRIPPED: the Michael MIC is stripped off this frame,
 *	verification has been done by the hardware.
 * @RX_FLAG_IV_STRIPPED: The IV and ICV are stripped from this frame.
 *	If this flag is set, the stack cannot do any replay detection
 *	hence the driver or hardware will have to do that.
 * @RX_FLAG_PN_VALIDATED: Currently only valid for CCMP/GCMP frames, this
 *	flag indicates that the PN was verified for replay protection.
 *	Note that this flag is also currently only supported when a frame
 *	is also decrypted (ie. @RX_FLAG_DECRYPTED must be set)
 * @RX_FLAG_DUP_VALIDATED: The driver should set this flag if it did
 *	de-duplication by itself.
 * @RX_FLAG_FAILED_FCS_CRC: Set this flag if the FCS check failed on
 *	the frame.
 * @RX_FLAG_FAILED_PLCP_CRC: Set this flag if the PCLP check failed on
 *	the frame.
 * @RX_FLAG_MACTIME_START: The timestamp passed in the RX status (@mactime
 *	field) is valid and contains the time the first symbol of the MPDU
 *	was received. This is useful in monitor mode and for proper IBSS
 *	merging.
 * @RX_FLAG_MACTIME_END: The timestamp passed in the RX status (@mactime
 *	field) is valid and contains the time the last symbol of the MPDU
 *	(including FCS) was received.
 * @RX_FLAG_MACTIME_PLCP_START: The timestamp passed in the RX status (@mactime
 *	field) is valid and contains the time the SYNC preamble was received.
 * @RX_FLAG_NO_SIGNAL_VAL: The signal strength value is not present.
 *	Valid only for data frames (mainly A-MPDU)
 * @RX_FLAG_AMPDU_DETAILS: A-MPDU details are known, in particular the reference
 *	number (@ampdu_reference) must be populated and be a distinct number for
 *	each A-MPDU
 * @RX_FLAG_AMPDU_LAST_KNOWN: last subframe is known, should be set on all
 *	subframes of a single A-MPDU
 * @RX_FLAG_AMPDU_IS_LAST: this subframe is the last subframe of the A-MPDU
 * @RX_FLAG_AMPDU_DELIM_CRC_ERROR: A delimiter CRC error has been detected
 *	on this subframe
 * @RX_FLAG_AMPDU_DELIM_CRC_KNOWN: The delimiter CRC field is known (the CRC
 *	is stored in the @ampdu_delimiter_crc field)
 * @RX_FLAG_MIC_STRIPPED: The mic was stripped of this packet. Decryption was
 *	done by the hardware
 * @RX_FLAG_ONLY_MONITOR: Report frame only to monitor interfaces without
 *	processing it in any regular way.
 *	This is useful if drivers offload some frames but still want to report
 *	them for sniffing purposes.
 * @RX_FLAG_SKIP_MONITOR: Process and report frame to all interfaces except
 *	monitor interfaces.
 *	This is useful if drivers offload some frames but still want to report
 *	them for sniffing purposes.
 * @RX_FLAG_AMSDU_MORE: Some drivers may prefer to report separate A-MSDU
 *	subframes instead of a one huge frame for performance reasons.
 *	All, but the last MSDU from an A-MSDU should have this flag set. E.g.
 *	if an A-MSDU has 3 frames, the first 2 must have the flag set, while
 *	the 3rd (last) one must not have this flag set. The flag is used to
 *	deal with retransmission/duplication recovery properly since A-MSDU
 *	subframes share the same sequence number. Reported subframes can be
 *	either regular MSDU or singly A-MSDUs. Subframes must not be
 *	interleaved with other frames.
 * @RX_FLAG_RADIOTAP_VENDOR_DATA: This frame contains vendor-specific
 *	radiotap data in the skb->data (before the frame) as described by
 *	the &struct ieee80211_vendor_radiotap.
 * @RX_FLAG_ALLOW_SAME_PN: Allow the same PN as same packet before.
 *	This is used for AMSDU subframes which can have the same PN as
 *	the first subframe.
 * @RX_FLAG_ICV_STRIPPED: The ICV is stripped from this frame. CRC checking must
 *	be done in the hardware.
 * @RX_FLAG_AMPDU_EOF_BIT: Value of the EOF bit in the A-MPDU delimiter for this
 *	frame
 * @RX_FLAG_AMPDU_EOF_BIT_KNOWN: The EOF value is known
 * @RX_FLAG_RADIOTAP_HE: HE radiotap data is present
 *	(&struct ieee80211_radiotap_he, mac80211 will fill in
 *	
 *	 - DATA3_DATA_MCS
 *	 - DATA3_DATA_DCM
 *	 - DATA3_CODING
 *	 - DATA5_GI
 *	 - DATA5_DATA_BW_RU_ALLOC
 *	 - DATA6_NSTS
 *	 - DATA3_STBC
 *	
 *	from the RX info data, so leave those zeroed when building this data)
 * @RX_FLAG_RADIOTAP_HE_MU: HE MU radiotap data is present
 *	(&struct ieee80211_radiotap_he_mu)
 * @RX_FLAG_RADIOTAP_LSIG: L-SIG radiotap data is present
 * @RX_FLAG_NO_PSDU: use the frame only for radiotap reporting, with
 *	the "0-length PSDU" field included there.  The value for it is
 *	in &struct ieee80211_rx_status.  Note that if this value isn't
 *	known the frame shouldn't be reported.
 */
```

## 2899. original/linux-5.10.260/include/net/mac80211.h:1330

Líneas 1330–1342; tipo `block`.

```text
/**
 * enum mac80211_rx_encoding_flags - MCS & bandwidth flags
 *
 * @RX_ENC_FLAG_SHORTPRE: Short preamble was used for this frame
 * @RX_ENC_FLAG_SHORT_GI: Short guard interval was used
 * @RX_ENC_FLAG_HT_GF: This frame was received in a HT-greenfield transmission,
 *	if the driver fills this value it should add
 *	%IEEE80211_RADIOTAP_MCS_HAVE_FMT
 *	to @hw.radiotap_mcs_details to advertise that fact.
 * @RX_ENC_FLAG_LDPC: LDPC was used
 * @RX_ENC_FLAG_STBC_MASK: STBC 2 bit bitmask. 1 - Nss=1, 2 - Nss=2, 3 - Nss=3
 * @RX_ENC_FLAG_BF: packet was beamformed
 */
```

## 2900. original/linux-5.10.260/include/net/mac80211.h:1361

Líneas 1361–1402; tipo `block`.

```text
/**
 * struct ieee80211_rx_status - receive status
 *
 * The low-level driver should provide this information (the subset
 * supported by hardware) to the 802.11 code with each received
 * frame, in the skb's control buffer (cb).
 *
 * @mactime: value in microseconds of the 64-bit Time Synchronization Function
 * 	(TSF) timer when the first data symbol (MPDU) arrived at the hardware.
 * @boottime_ns: CLOCK_BOOTTIME timestamp the frame was received at, this is
 *	needed only for beacons and probe responses that update the scan cache.
 * @device_timestamp: arbitrary timestamp for the device, mac80211 doesn't use
 *	it but can store it and pass it back to the driver for synchronisation
 * @band: the active band when this frame was received
 * @freq: frequency the radio was tuned to when receiving this frame, in MHz
 *	This field must be set for management frames, but isn't strictly needed
 *	for data (other) frames - for those it only affects radiotap reporting.
 * @freq_offset: @freq has a positive offset of 500Khz.
 * @signal: signal strength when receiving this frame, either in dBm, in dB or
 *	unspecified depending on the hardware capabilities flags
 *	@IEEE80211_HW_SIGNAL_*
 * @chains: bitmask of receive chains for which separate signal strength
 *	values were filled.
 * @chain_signal: per-chain signal strength, in dBm (unlike @signal, doesn't
 *	support dB or unspecified units)
 * @antenna: antenna used
 * @rate_idx: index of data rate into band's supported rates or MCS index if
 *	HT or VHT is used (%RX_FLAG_HT/%RX_FLAG_VHT)
 * @nss: number of streams (VHT and HE only)
 * @flag: %RX_FLAG_\*
 * @encoding: &enum mac80211_rx_encoding
 * @bw: &enum rate_info_bw
 * @enc_flags: uses bits from &enum mac80211_rx_encoding_flags
 * @he_ru: HE RU, from &enum nl80211_he_ru_alloc
 * @he_gi: HE GI, from &enum nl80211_he_gi
 * @he_dcm: HE DCM value
 * @rx_flags: internal RX flags for mac80211
 * @ampdu_reference: A-MPDU reference number, must be a different value for
 *	each A-MPDU but the same for each subframe within one A-MPDU
 * @ampdu_delimiter_crc: A-MPDU delimiter CRC
 * @zero_length_psdu_type: radiotap type of the 0-length PSDU
 */
```

## 2901. original/linux-5.10.260/include/net/mac80211.h:1432

Líneas 1432–1454; tipo `block`.

```text
/**
 * struct ieee80211_vendor_radiotap - vendor radiotap data information
 * @present: presence bitmap for this vendor namespace
 *	(this could be extended in the future if any vendor needs more
 *	 bits, the radiotap spec does allow for that)
 * @align: radiotap vendor namespace alignment. This defines the needed
 *	alignment for the @data field below, not for the vendor namespace
 *	description itself (which has a fixed 2-byte alignment)
 *	Must be a power of two, and be set to at least 1!
 * @oui: radiotap vendor namespace OUI
 * @subns: radiotap vendor sub namespace
 * @len: radiotap vendor sub namespace skip length, if alignment is done
 *	then that's added to this, i.e. this is only the length of the
 *	@data field.
 * @pad: number of bytes of padding after the @data, this exists so that
 *	the skb data alignment can be preserved even if the data has odd
 *	length
 * @data: the actual vendor namespace data
 *
 * This struct, including the vendor data, goes into the skb->data before
 * the 802.11 header. It's split up in mac80211 using the align/oui/subns
 * data.
 */
```

## 2902. original/linux-5.10.260/include/net/mac80211.h:1465

Líneas 1465–1487; tipo `block`.

```text
/**
 * enum ieee80211_conf_flags - configuration flags
 *
 * Flags to define PHY configuration options
 *
 * @IEEE80211_CONF_MONITOR: there's a monitor interface present -- use this
 *	to determine for example whether to calculate timestamps for packets
 *	or not, do not use instead of filter flags!
 * @IEEE80211_CONF_PS: Enable 802.11 power save mode (managed mode only).
 *	This is the power save mode defined by IEEE 802.11-2007 section 11.2,
 *	meaning that the hardware still wakes up for beacons, is able to
 *	transmit frames and receive the possible acknowledgment frames.
 *	Not to be confused with hardware specific wakeup/sleep states,
 *	driver is responsible for that. See the section "Powersave support"
 *	for more.
 * @IEEE80211_CONF_IDLE: The device is running, but idle; if the flag is set
 *	the driver should be prepared to handle configuration requests but
 *	may turn the device off as much as possible. Typically, this flag will
 *	be set when an interface is set UP but not associated or scanning, but
 *	it can also be unset in that case when monitor interfaces are active.
 * @IEEE80211_CONF_OFFCHANNEL: The device is currently not on its main
 *	operating channel.
 */
```

## 2903. original/linux-5.10.260/include/net/mac80211.h:1496

Líneas 1496–1509; tipo `block`.

```text
/**
 * enum ieee80211_conf_changed - denotes which configuration changed
 *
 * @IEEE80211_CONF_CHANGE_LISTEN_INTERVAL: the listen interval changed
 * @IEEE80211_CONF_CHANGE_MONITOR: the monitor flag changed
 * @IEEE80211_CONF_CHANGE_PS: the PS flag or dynamic PS timeout changed
 * @IEEE80211_CONF_CHANGE_POWER: the TX power changed
 * @IEEE80211_CONF_CHANGE_CHANNEL: the channel/channel_type changed
 * @IEEE80211_CONF_CHANGE_RETRY_LIMITS: retry limits changed
 * @IEEE80211_CONF_CHANGE_IDLE: Idle flag changed
 * @IEEE80211_CONF_CHANGE_SMPS: Spatial multiplexing powersave mode changed
 *	Note that this is only valid if channel contexts are not used,
 *	otherwise each channel context has the number of chains listed.
 */
```

## 2904. original/linux-5.10.260/include/net/mac80211.h:1521

Líneas 1521–1529; tipo `block`.

```text
/**
 * enum ieee80211_smps_mode - spatial multiplexing power save mode
 *
 * @IEEE80211_SMPS_AUTOMATIC: automatic
 * @IEEE80211_SMPS_OFF: off
 * @IEEE80211_SMPS_STATIC: static
 * @IEEE80211_SMPS_DYNAMIC: dynamic
 * @IEEE80211_SMPS_NUM_MODES: internal, don't use
 */
```

## 2905. original/linux-5.10.260/include/net/mac80211.h:1536

Líneas 1536–1536; tipo `block`.

```text
/* keep last */
```

## 2906. original/linux-5.10.260/include/net/mac80211.h:1540

Líneas 1540–1573; tipo `block`.

```text
/**
 * struct ieee80211_conf - configuration of the device
 *
 * This struct indicates how the driver shall configure the hardware.
 *
 * @flags: configuration flags defined above
 *
 * @listen_interval: listen interval in units of beacon interval
 * @ps_dtim_period: The DTIM period of the AP we're connected to, for use
 *	in power saving. Power saving will not be enabled until a beacon
 *	has been received and the DTIM period is known.
 * @dynamic_ps_timeout: The dynamic powersave timeout (in ms), see the
 *	powersave documentation below. This variable is valid only when
 *	the CONF_PS flag is set.
 *
 * @power_level: requested transmit power (in dBm), backward compatibility
 *	value only that is set to the minimum of all interfaces
 *
 * @chandef: the channel definition to tune to
 * @radar_enabled: whether radar detection is enabled
 *
 * @long_frame_max_tx_count: Maximum number of transmissions for a "long" frame
 *	(a frame not RTS protected), called "dot11LongRetryLimit" in 802.11,
 *	but actually means the number of transmissions not the number of retries
 * @short_frame_max_tx_count: Maximum number of transmissions for a "short"
 *	frame, called "dot11ShortRetryLimit" in 802.11, but actually means the
 *	number of transmissions not the number of retries
 *
 * @smps_mode: spatial multiplexing powersave mode; note that
 *	%IEEE80211_SMPS_STATIC is used when the device is not
 *	configured for an HT channel.
 *	Note that this is only valid if channel contexts are not used,
 *	otherwise each channel context has the number of chains listed.
 */
```

## 2907. original/linux-5.10.260/include/net/mac80211.h:1588

Líneas 1588–1607; tipo `block`.

```text
/**
 * struct ieee80211_channel_switch - holds the channel switch data
 *
 * The information provided in this structure is required for channel switch
 * operation.
 *
 * @timestamp: value in microseconds of the 64-bit Time Synchronization
 *	Function (TSF) timer when the frame containing the channel switch
 *	announcement was received. This is simply the rx.mactime parameter
 *	the driver passed into mac80211.
 * @device_timestamp: arbitrary timestamp for the device, this is the
 *	rx.device_timestamp parameter the driver passed to mac80211.
 * @block_tx: Indicates whether transmission must be blocked before the
 *	scheduled channel switch, as indicated by the AP.
 * @chandef: the new channel to switch to
 * @count: the number of TBTT's until the channel switch event
 * @delay: maximum delay between the time the AP transmitted the last beacon in
  *	current channel and the expected time of the first beacon in the new
  *	channel, expressed in TU.
 */
```

## 2908. original/linux-5.10.260/include/net/mac80211.h:1617

Líneas 1617–1633; tipo `block`.

```text
/**
 * enum ieee80211_vif_flags - virtual interface flags
 *
 * @IEEE80211_VIF_BEACON_FILTER: the device performs beacon filtering
 *	on this virtual interface to avoid unnecessary CPU wakeups
 * @IEEE80211_VIF_SUPPORTS_CQM_RSSI: the device can do connection quality
 *	monitoring on this virtual interface -- i.e. it can monitor
 *	connection quality related parameters, such as the RSSI level and
 *	provide notifications if configured trigger levels are reached.
 * @IEEE80211_VIF_SUPPORTS_UAPSD: The device can do U-APSD for this
 *	interface. This flag should be set during interface addition,
 *	but may be set/cleared as late as authentication to an AP. It is
 *	only valid for managed/station mode interfaces.
 * @IEEE80211_VIF_GET_NOA_UPDATE: request to handle NOA attributes
 *	and send P2P_PS notification to the driver if NOA changed, even
 *	this is not pure P2P vif.
 */
```

## 2909. original/linux-5.10.260/include/net/mac80211.h:1642

Líneas 1642–1649; tipo `block`.

```text
/**
 * enum ieee80211_offload_flags - virtual interface offload flags
 *
 * @IEEE80211_OFFLOAD_ENCAP_ENABLED: tx encapsulation offload is enabled
 *	The driver supports sending frames passed as 802.3 frames by mac80211.
 *	It must also support sending 802.11 packets for the same interface.
 * @IEEE80211_OFFLOAD_ENCAP_4ADDR: support 4-address mode encapsulation offload
 */
```

## 2910. original/linux-5.10.260/include/net/mac80211.h:1656

Líneas 1656–1702; tipo `block`.

```text
/**
 * struct ieee80211_vif - per-interface data
 *
 * Data in this structure is continually present for driver
 * use during the life of a virtual interface.
 *
 * @type: type of this virtual interface
 * @bss_conf: BSS configuration for this interface, either our own
 *	or the BSS we're associated to
 * @addr: address of this interface
 * @p2p: indicates whether this AP or STA interface is a p2p
 *	interface, i.e. a GO or p2p-sta respectively
 * @csa_active: marks whether a channel switch is going on. Internally it is
 *	write-protected by sdata_lock and local->mtx so holding either is fine
 *	for read access.
 * @mu_mimo_owner: indicates interface owns MU-MIMO capability
 * @driver_flags: flags/capabilities the driver has for this interface,
 *	these need to be set (or cleared) when the interface is added
 *	or, if supported by the driver, the interface type is changed
 *	at runtime, mac80211 will never touch this field
 * @offloaad_flags: hardware offload capabilities/flags for this interface.
 *	These are initialized by mac80211 before calling .add_interface,
 *	.change_interface or .update_vif_offload and updated by the driver
 *	within these ops, based on supported features or runtime change
 *	restrictions.
 * @hw_queue: hardware queue for each AC
 * @cab_queue: content-after-beacon (DTIM beacon really) queue, AP mode only
 * @chanctx_conf: The channel context this interface is assigned to, or %NULL
 *	when it is not assigned. This pointer is RCU-protected due to the TX
 *	path needing to access it; even though the netdev carrier will always
 *	be off when it is %NULL there can still be races and packets could be
 *	processed after it switches back to %NULL.
 * @debugfs_dir: debugfs dentry, can be used by drivers to create own per
 *	interface debug files. Note that it will be NULL for the virtual
 *	monitor interface (if that is requested.)
 * @probe_req_reg: probe requests should be reported to mac80211 for this
 *	interface.
 * @rx_mcast_action_reg: multicast Action frames should be reported to mac80211
 *	for this interface.
 * @drv_priv: data area for driver use, will always be aligned to
 *	sizeof(void \*).
 * @txq: the multicast data TX queue (if driver uses the TXQ abstraction)
 * @txqs_stopped: per AC flag to indicate that intermediate TXQs are stopped,
 *	protected by fq->lock.
 * @offload_flags: 802.3 -> 802.11 enapsulation offload flags, see
 *	&enum ieee80211_offload_flags.
 */
```

## 2911. original/linux-5.10.260/include/net/mac80211.h:1730

Líneas 1730–1730; tipo `block`.

```text
/* must be last */
```

## 2912. original/linux-5.10.260/include/net/mac80211.h:1742

Líneas 1742–1752; tipo `block`.

```text
/**
 * wdev_to_ieee80211_vif - return a vif struct from a wdev
 * @wdev: the wdev to get the vif for
 *
 * This can be used by mac80211 drivers with direct cfg80211 APIs
 * (like the vendor commands) that get a wdev.
 *
 * Note that this function may return %NULL if the given wdev isn't
 * associated with a vif that the driver knows about (e.g. monitor
 * or AP_VLAN interfaces.)
 */
```

## 2913. original/linux-5.10.260/include/net/mac80211.h:1755

Líneas 1755–1765; tipo `block`.

```text
/**
 * ieee80211_vif_to_wdev - return a wdev struct from a vif
 * @vif: the vif to get the wdev for
 *
 * This can be used by mac80211 drivers with direct cfg80211 APIs
 * (like the vendor commands) that needs to get the wdev for a vif.
 *
 * Note that this function may return %NULL if the given wdev isn't
 * associated with a vif that the driver knows about (e.g. monitor
 * or AP_VLAN interfaces.)
 */
```

## 2914. original/linux-5.10.260/include/net/mac80211.h:1768

Líneas 1768–1812; tipo `block`.

```text
/**
 * enum ieee80211_key_flags - key flags
 *
 * These flags are used for communication about keys between the driver
 * and mac80211, with the @flags parameter of &struct ieee80211_key_conf.
 *
 * @IEEE80211_KEY_FLAG_GENERATE_IV: This flag should be set by the
 *	driver to indicate that it requires IV generation for this
 *	particular key. Setting this flag does not necessarily mean that SKBs
 *	will have sufficient tailroom for ICV or MIC.
 * @IEEE80211_KEY_FLAG_GENERATE_MMIC: This flag should be set by
 *	the driver for a TKIP key if it requires Michael MIC
 *	generation in software.
 * @IEEE80211_KEY_FLAG_PAIRWISE: Set by mac80211, this flag indicates
 *	that the key is pairwise rather then a shared key.
 * @IEEE80211_KEY_FLAG_SW_MGMT_TX: This flag should be set by the driver for a
 *	CCMP/GCMP key if it requires CCMP/GCMP encryption of management frames
 *	(MFP) to be done in software.
 * @IEEE80211_KEY_FLAG_PUT_IV_SPACE: This flag should be set by the driver
 *	if space should be prepared for the IV, but the IV
 *	itself should not be generated. Do not set together with
 *	@IEEE80211_KEY_FLAG_GENERATE_IV on the same key. Setting this flag does
 *	not necessarily mean that SKBs will have sufficient tailroom for ICV or
 *	MIC.
 * @IEEE80211_KEY_FLAG_RX_MGMT: This key will be used to decrypt received
 *	management frames. The flag can help drivers that have a hardware
 *	crypto implementation that doesn't deal with management frames
 *	properly by allowing them to not upload the keys to hardware and
 *	fall back to software crypto. Note that this flag deals only with
 *	RX, if your crypto engine can't deal with TX you can also set the
 *	%IEEE80211_KEY_FLAG_SW_MGMT_TX flag to encrypt such frames in SW.
 * @IEEE80211_KEY_FLAG_GENERATE_IV_MGMT: This flag should be set by the
 *	driver for a CCMP/GCMP key to indicate that is requires IV generation
 *	only for management frames (MFP).
 * @IEEE80211_KEY_FLAG_RESERVE_TAILROOM: This flag should be set by the
 *	driver for a key to indicate that sufficient tailroom must always
 *	be reserved for ICV or MIC, even when HW encryption is enabled.
 * @IEEE80211_KEY_FLAG_PUT_MIC_SPACE: This flag should be set by the driver for
 *	a TKIP key if it only requires MIC space. Do not set together with
 *	@IEEE80211_KEY_FLAG_GENERATE_MMIC on the same key.
 * @IEEE80211_KEY_FLAG_NO_AUTO_TX: Key needs explicit Tx activation.
 * @IEEE80211_KEY_FLAG_GENERATE_MMIE: This flag should be set by the driver
 *	for a AES_CMAC key to indicate that it requires sequence number
 *	generation only
 */
```

## 2915. original/linux-5.10.260/include/net/mac80211.h:1827

Líneas 1827–1849; tipo `block`.

```text
/**
 * struct ieee80211_key_conf - key information
 *
 * This key information is given by mac80211 to the driver by
 * the set_key() callback in &struct ieee80211_ops.
 *
 * @hw_key_idx: To be set by the driver, this is the key index the driver
 *	wants to be given when a frame is transmitted and needs to be
 *	encrypted in hardware.
 * @cipher: The key's cipher suite selector.
 * @tx_pn: PN used for TX keys, may be used by the driver as well if it
 *	needs to do software PN assignment by itself (e.g. due to TSO)
 * @flags: key flags, see &enum ieee80211_key_flags.
 * @keyidx: the key index (0-3)
 * @keylen: key material length
 * @key: key material. For ALG_TKIP the key is encoded as a 256-bit (32 byte)
 * 	data block:
 * 	- Temporal Encryption Key (128 bits)
 * 	- Temporal Authenticator Tx MIC Key (64 bits)
 * 	- Temporal Authenticator Rx MIC Key (64 bits)
 * @icv_len: The ICV length for this key type
 * @iv_len: The IV length for this key type
 */
```

## 2916. original/linux-5.10.260/include/net/mac80211.h:1867

Líneas 1867–1880; tipo `block`.

```text
/**
 * struct ieee80211_key_seq - key sequence counter
 *
 * @tkip: TKIP data, containing IV32 and IV16 in host byte order
 * @ccmp: PN data, most significant byte first (big endian,
 *	reverse order than in packet)
 * @aes_cmac: PN data, most significant byte first (big endian,
 *	reverse order than in packet)
 * @aes_gmac: PN data, most significant byte first (big endian,
 *	reverse order than in packet)
 * @gcmp: PN data, most significant byte first (big endian,
 *	reverse order than in packet)
 * @hw: data for HW-only (e.g. cipher scheme) keys
 */
```

## 2917. original/linux-5.10.260/include/net/mac80211.h:1906

Líneas 1906–1923; tipo `block`.

```text
/**
 * struct ieee80211_cipher_scheme - cipher scheme
 *
 * This structure contains a cipher scheme information defining
 * the secure packet crypto handling.
 *
 * @cipher: a cipher suite selector
 * @iftype: a cipher iftype bit mask indicating an allowed cipher usage
 * @hdr_len: a length of a security header used the cipher
 * @pn_len: a length of a packet number in the security header
 * @pn_off: an offset of pn from the beginning of the security header
 * @key_idx_off: an offset of key index byte in the security header
 * @key_idx_mask: a bit mask of key_idx bits
 * @key_idx_shift: a bit shift needed to get key_idx
 *     key_idx value calculation:
 *      (sec_header_base[key_idx_off] & key_idx_mask) >> key_idx_shift
 * @mic_len: a mic length in bytes
 */
```

## 2918. original/linux-5.10.260/include/net/mac80211.h:1936

Líneas 1936–1944; tipo `block`.

```text
/**
 * enum set_key_cmd - key command
 *
 * Used with the set_key() callback in &struct ieee80211_ops, this
 * indicates whether a key is being removed or added.
 *
 * @SET_KEY: a key is set
 * @DISABLE_KEY: a key must be disabled
 */
```

## 2919. original/linux-5.10.260/include/net/mac80211.h:1949

Líneas 1949–1958; tipo `block`.

```text
/**
 * enum ieee80211_sta_state - station state
 *
 * @IEEE80211_STA_NOTEXIST: station doesn't exist at all,
 *	this is a special state for add/remove transitions
 * @IEEE80211_STA_NONE: station exists without special state
 * @IEEE80211_STA_AUTH: station is authenticated
 * @IEEE80211_STA_ASSOC: station is associated
 * @IEEE80211_STA_AUTHORIZED: station is authorized (802.1X)
 */
```

## 2920. original/linux-5.10.260/include/net/mac80211.h:1960

Líneas 1960–1960; tipo `block`.

```text
/* NOTE: These need to be ordered correctly! */
```

## 2921. original/linux-5.10.260/include/net/mac80211.h:1968

Líneas 1968–1978; tipo `block`.

```text
/**
 * enum ieee80211_sta_rx_bandwidth - station RX bandwidth
 * @IEEE80211_STA_RX_BW_20: station can only receive 20 MHz
 * @IEEE80211_STA_RX_BW_40: station can receive up to 40 MHz
 * @IEEE80211_STA_RX_BW_80: station can receive up to 80 MHz
 * @IEEE80211_STA_RX_BW_160: station can receive up to 160 MHz
 *	(including 80+80 MHz)
 *
 * Implementation note: 20 must be zero to be initialized
 *	correctly, the values must be sorted.
 */
```

## 2922. original/linux-5.10.260/include/net/mac80211.h:1986

Líneas 1986–1992; tipo `block`.

```text
/**
 * struct ieee80211_sta_rates - station rate selection table
 *
 * @rcu_head: RCU head used for freeing the table on update
 * @rate: transmit rates/flags to be used by default.
 *	Overriding entries per-packet is possible by using cb tx control.
 */
```

## 2923. original/linux-5.10.260/include/net/mac80211.h:2004

Líneas 2004–2016; tipo `block`.

```text
/**
 * struct ieee80211_sta_txpwr - station txpower configuration
 *
 * Used to configure txpower for station.
 *
 * @power: indicates the tx power, in dBm, to be used when sending data frames
 *	to the STA.
 * @type: In particular if TPC %type is NL80211_TX_POWER_LIMITED then tx power
 *	will be less than or equal to specified from userspace, whereas if TPC
 *	%type is NL80211_TX_POWER_AUTOMATIC then it indicates default tx power.
 *	NL80211_TX_POWER_FIXED is not a valid configuration option for
 *	per peer TPC.
 */
```

## 2924. original/linux-5.10.260/include/net/mac80211.h:2022

Líneas 2022–2070; tipo `block`.

```text
/**
 * struct ieee80211_sta - station table entry
 *
 * A station table entry represents a station we are possibly
 * communicating with. Since stations are RCU-managed in
 * mac80211, any ieee80211_sta pointer you get access to must
 * either be protected by rcu_read_lock() explicitly or implicitly,
 * or you must take good care to not use such a pointer after a
 * call to your sta_remove callback that removed it.
 *
 * @addr: MAC address
 * @aid: AID we assigned to the station if we're an AP
 * @supp_rates: Bitmap of supported rates (per band)
 * @ht_cap: HT capabilities of this STA; restricted to our own capabilities
 * @vht_cap: VHT capabilities of this STA; restricted to our own capabilities
 * @he_cap: HE capabilities of this STA
 * @he_6ghz_capa: on 6 GHz, holds the HE 6 GHz band capabilities
 * @max_rx_aggregation_subframes: maximal amount of frames in a single AMPDU
 *	that this station is allowed to transmit to us.
 *	Can be modified by driver.
 * @wme: indicates whether the STA supports QoS/WME (if local devices does,
 *	otherwise always false)
 * @drv_priv: data area for driver use, will always be aligned to
 *	sizeof(void \*), size is determined in hw information.
 * @uapsd_queues: bitmap of queues configured for uapsd. Only valid
 *	if wme is supported. The bits order is like in
 *	IEEE80211_WMM_IE_STA_QOSINFO_AC_*.
 * @max_sp: max Service Period. Only valid if wme is supported.
 * @bandwidth: current bandwidth the station can receive with
 * @rx_nss: in HT/VHT, the maximum number of spatial streams the
 *	station can receive at the moment, changed by operating mode
 *	notifications and capabilities. The value is only valid after
 *	the station moves to associated state.
 * @smps_mode: current SMPS mode (off, static or dynamic)
 * @rates: rate control selection table
 * @tdls: indicates whether the STA is a TDLS peer
 * @tdls_initiator: indicates the STA is an initiator of the TDLS link. Only
 *	valid if the STA is a TDLS peer in the first place.
 * @mfp: indicates whether the STA uses management frame protection or not.
 * @max_amsdu_subframes: indicates the maximal number of MSDUs in a single
 *	A-MSDU. Taken from the Extended Capabilities element. 0 means
 *	unlimited.
 * @support_p2p_ps: indicates whether the STA supports P2P PS mechanism or not.
 * @max_rc_amsdu_len: Maximum A-MSDU size in bytes recommended by rate control.
 * @max_tid_amsdu_len: Maximum A-MSDU size in bytes for this TID
 * @txpwr: the station tx power configuration
 * @txq: per-TID data TX queues (if driver uses the TXQ abstraction); note that
 *	the last entry (%IEEE80211_NUM_TIDS) is used for non-data frames
 */
```

## 2925. original/linux-5.10.260/include/net/mac80211.h:2092

Líneas 2092–2106; tipo `block`.

```text
/**
	 * @max_amsdu_len:
	 * indicates the maximal length of an A-MSDU in bytes.
	 * This field is always valid for packets with a VHT preamble.
	 * For packets with a HT preamble, additional limits apply:
	 *
	 * * If the skb is transmitted as part of a BA agreement, the
	 *   A-MSDU maximal size is min(max_amsdu_len, 4065) bytes.
	 * * If the skb is not part of a BA agreement, the A-MSDU maximal
	 *   size is min(max_amsdu_len, 7935) bytes.
	 *
	 * Both additional HT limits must be enforced by the low level
	 * driver. This is defined by the spec (IEEE 802.11-2012 section
	 * 8.3.2.2 NOTE 2).
	 */
```

## 2926. original/linux-5.10.260/include/net/mac80211.h:2115

Líneas 2115–2115; tipo `block`.

```text
/* must be last */
```

## 2927. original/linux-5.10.260/include/net/mac80211.h:2119

Líneas 2119–2127; tipo `block`.

```text
/**
 * enum sta_notify_cmd - sta notify command
 *
 * Used with the sta_notify() callback in &struct ieee80211_ops, this
 * indicates if an associated station made a power state transition.
 *
 * @STA_NOTIFY_SLEEP: a station is now sleeping
 * @STA_NOTIFY_AWAKE: a sleeping station woke up
 */
```

## 2928. original/linux-5.10.260/include/net/mac80211.h:2132

Líneas 2132–2137; tipo `block`.

```text
/**
 * struct ieee80211_tx_control - TX control data
 *
 * @sta: station table entry, this sta pointer may be NULL and
 * 	it is not allowed to copy the pointer, due to RCU.
 */
```

## 2929. original/linux-5.10.260/include/net/mac80211.h:2142

Líneas 2142–2154; tipo `block`.

```text
/**
 * struct ieee80211_txq - Software intermediate tx queue
 *
 * @vif: &struct ieee80211_vif pointer from the add_interface callback.
 * @sta: station table entry, %NULL for per-vif queue
 * @tid: the TID for this queue (unused for per-vif queue),
 *	%IEEE80211_NUM_TIDS for non-data (if enabled)
 * @ac: the AC for this queue
 * @drv_priv: driver private area, sized by hw->txq_data_size
 *
 * The driver can obtain packets from this queue by calling
 * ieee80211_tx_dequeue().
 */
```

## 2930. original/linux-5.10.260/include/net/mac80211.h:2161

Líneas 2161–2161; tipo `block`.

```text
/* must be last */
```

## 2931. original/linux-5.10.260/include/net/mac80211.h:2165

Líneas 2165–2390; tipo `block`.

```text
/**
 * enum ieee80211_hw_flags - hardware flags
 *
 * These flags are used to indicate hardware capabilities to
 * the stack. Generally, flags here should have their meaning
 * done in a way that the simplest hardware doesn't need setting
 * any particular flags. There are some exceptions to this rule,
 * however, so you are advised to review these flags carefully.
 *
 * @IEEE80211_HW_HAS_RATE_CONTROL:
 *	The hardware or firmware includes rate control, and cannot be
 *	controlled by the stack. As such, no rate control algorithm
 *	should be instantiated, and the TX rate reported to userspace
 *	will be taken from the TX status instead of the rate control
 *	algorithm.
 *	Note that this requires that the driver implement a number of
 *	callbacks so it has the correct information, it needs to have
 *	the @set_rts_threshold callback and must look at the BSS config
 *	@use_cts_prot for G/N protection, @use_short_slot for slot
 *	timing in 2.4 GHz and @use_short_preamble for preambles for
 *	CCK frames.
 *
 * @IEEE80211_HW_RX_INCLUDES_FCS:
 *	Indicates that received frames passed to the stack include
 *	the FCS at the end.
 *
 * @IEEE80211_HW_HOST_BROADCAST_PS_BUFFERING:
 *	Some wireless LAN chipsets buffer broadcast/multicast frames
 *	for power saving stations in the hardware/firmware and others
 *	rely on the host system for such buffering. This option is used
 *	to configure the IEEE 802.11 upper layer to buffer broadcast and
 *	multicast frames when there are power saving stations so that
 *	the driver can fetch them with ieee80211_get_buffered_bc().
 *
 * @IEEE80211_HW_SIGNAL_UNSPEC:
 *	Hardware can provide signal values but we don't know its units. We
 *	expect values between 0 and @max_signal.
 *	If possible please provide dB or dBm instead.
 *
 * @IEEE80211_HW_SIGNAL_DBM:
 *	Hardware gives signal values in dBm, decibel difference from
 *	one milliwatt. This is the preferred method since it is standardized
 *	between different devices. @max_signal does not need to be set.
 *
 * @IEEE80211_HW_SPECTRUM_MGMT:
 * 	Hardware supports spectrum management defined in 802.11h
 * 	Measurement, Channel Switch, Quieting, TPC
 *
 * @IEEE80211_HW_AMPDU_AGGREGATION:
 *	Hardware supports 11n A-MPDU aggregation.
 *
 * @IEEE80211_HW_SUPPORTS_PS:
 *	Hardware has power save support (i.e. can go to sleep).
 *
 * @IEEE80211_HW_PS_NULLFUNC_STACK:
 *	Hardware requires nullfunc frame handling in stack, implies
 *	stack support for dynamic PS.
 *
 * @IEEE80211_HW_SUPPORTS_DYNAMIC_PS:
 *	Hardware has support for dynamic PS.
 *
 * @IEEE80211_HW_MFP_CAPABLE:
 *	Hardware supports management frame protection (MFP, IEEE 802.11w).
 *
 * @IEEE80211_HW_REPORTS_TX_ACK_STATUS:
 *	Hardware can provide ack status reports of Tx frames to
 *	the stack.
 *
 * @IEEE80211_HW_CONNECTION_MONITOR:
 *	The hardware performs its own connection monitoring, including
 *	periodic keep-alives to the AP and probing the AP on beacon loss.
 *
 * @IEEE80211_HW_NEED_DTIM_BEFORE_ASSOC:
 *	This device needs to get data from beacon before association (i.e.
 *	dtim_period).
 *
 * @IEEE80211_HW_SUPPORTS_PER_STA_GTK: The device's crypto engine supports
 *	per-station GTKs as used by IBSS RSN or during fast transition. If
 *	the device doesn't support per-station GTKs, but can be asked not
 *	to decrypt group addressed frames, then IBSS RSN support is still
 *	possible but software crypto will be used. Advertise the wiphy flag
 *	only in that case.
 *
 * @IEEE80211_HW_AP_LINK_PS: When operating in AP mode the device
 *	autonomously manages the PS status of connected stations. When
 *	this flag is set mac80211 will not trigger PS mode for connected
 *	stations based on the PM bit of incoming frames.
 *	Use ieee80211_start_ps()/ieee8021_end_ps() to manually configure
 *	the PS mode of connected stations.
 *
 * @IEEE80211_HW_TX_AMPDU_SETUP_IN_HW: The device handles TX A-MPDU session
 *	setup strictly in HW. mac80211 should not attempt to do this in
 *	software.
 *
 * @IEEE80211_HW_WANT_MONITOR_VIF: The driver would like to be informed of
 *	a virtual monitor interface when monitor interfaces are the only
 *	active interfaces.
 *
 * @IEEE80211_HW_NO_AUTO_VIF: The driver would like for no wlanX to
 *	be created.  It is expected user-space will create vifs as
 *	desired (and thus have them named as desired).
 *
 * @IEEE80211_HW_SW_CRYPTO_CONTROL: The driver wants to control which of the
 *	crypto algorithms can be done in software - so don't automatically
 *	try to fall back to it if hardware crypto fails, but do so only if
 *	the driver returns 1. This also forces the driver to advertise its
 *	supported cipher suites.
 *
 * @IEEE80211_HW_SUPPORT_FAST_XMIT: The driver/hardware supports fast-xmit,
 *	this currently requires only the ability to calculate the duration
 *	for frames.
 *
 * @IEEE80211_HW_QUEUE_CONTROL: The driver wants to control per-interface
 *	queue mapping in order to use different queues (not just one per AC)
 *	for different virtual interfaces. See the doc section on HW queue
 *	control for more details.
 *
 * @IEEE80211_HW_SUPPORTS_RC_TABLE: The driver supports using a rate
 *	selection table provided by the rate control algorithm.
 *
 * @IEEE80211_HW_P2P_DEV_ADDR_FOR_INTF: Use the P2P Device address for any
 *	P2P Interface. This will be honoured even if more than one interface
 *	is supported.
 *
 * @IEEE80211_HW_TIMING_BEACON_ONLY: Use sync timing from beacon frames
 *	only, to allow getting TBTT of a DTIM beacon.
 *
 * @IEEE80211_HW_SUPPORTS_HT_CCK_RATES: Hardware supports mixing HT/CCK rates
 *	and can cope with CCK rates in an aggregation session (e.g. by not
 *	using aggregation for such frames.)
 *
 * @IEEE80211_HW_CHANCTX_STA_CSA: Support 802.11h based channel-switch (CSA)
 *	for a single active channel while using channel contexts. When support
 *	is not enabled the default action is to disconnect when getting the
 *	CSA frame.
 *
 * @IEEE80211_HW_SUPPORTS_CLONED_SKBS: The driver will never modify the payload
 *	or tailroom of TX skbs without copying them first.
 *
 * @IEEE80211_HW_SINGLE_SCAN_ON_ALL_BANDS: The HW supports scanning on all bands
 *	in one command, mac80211 doesn't have to run separate scans per band.
 *
 * @IEEE80211_HW_TDLS_WIDER_BW: The device/driver supports wider bandwidth
 *	than then BSS bandwidth for a TDLS link on the base channel.
 *
 * @IEEE80211_HW_SUPPORTS_AMSDU_IN_AMPDU: The driver supports receiving A-MSDUs
 *	within A-MPDU.
 *
 * @IEEE80211_HW_BEACON_TX_STATUS: The device/driver provides TX status
 *	for sent beacons.
 *
 * @IEEE80211_HW_NEEDS_UNIQUE_STA_ADDR: Hardware (or driver) requires that each
 *	station has a unique address, i.e. each station entry can be identified
 *	by just its MAC address; this prevents, for example, the same station
 *	from connecting to two virtual AP interfaces at the same time.
 *
 * @IEEE80211_HW_SUPPORTS_REORDERING_BUFFER: Hardware (or driver) manages the
 *	reordering buffer internally, guaranteeing mac80211 receives frames in
 *	order and does not need to manage its own reorder buffer or BA session
 *	timeout.
 *
 * @IEEE80211_HW_USES_RSS: The device uses RSS and thus requires parallel RX,
 *	which implies using per-CPU station statistics.
 *
 * @IEEE80211_HW_TX_AMSDU: Hardware (or driver) supports software aggregated
 *	A-MSDU frames. Requires software tx queueing and fast-xmit support.
 *	When not using minstrel/minstrel_ht rate control, the driver must
 *	limit the maximum A-MSDU size based on the current tx rate by setting
 *	max_rc_amsdu_len in struct ieee80211_sta.
 *
 * @IEEE80211_HW_TX_FRAG_LIST: Hardware (or driver) supports sending frag_list
 *	skbs, needed for zero-copy software A-MSDU.
 *
 * @IEEE80211_HW_REPORTS_LOW_ACK: The driver (or firmware) reports low ack event
 *	by ieee80211_report_low_ack() based on its own algorithm. For such
 *	drivers, mac80211 packet loss mechanism will not be triggered and driver
 *	is completely depending on firmware event for station kickout.
 *
 * @IEEE80211_HW_SUPPORTS_TX_FRAG: Hardware does fragmentation by itself.
 *	The stack will not do fragmentation.
 *	The callback for @set_frag_threshold should be set as well.
 *
 * @IEEE80211_HW_SUPPORTS_TDLS_BUFFER_STA: Hardware supports buffer STA on
 *	TDLS links.
 *
 * @IEEE80211_HW_DEAUTH_NEED_MGD_TX_PREP: The driver requires the
 *	mgd_prepare_tx() callback to be called before transmission of a
 *	deauthentication frame in case the association was completed but no
 *	beacon was heard. This is required in multi-channel scenarios, where the
 *	virtual interface might not be given air time for the transmission of
 *	the frame, as it is not synced with the AP/P2P GO yet, and thus the
 *	deauthentication frame might not be transmitted.
 *
 * @IEEE80211_HW_DOESNT_SUPPORT_QOS_NDP: The driver (or firmware) doesn't
 *	support QoS NDP for AP probing - that's most likely a driver bug.
 *
 * @IEEE80211_HW_BUFF_MMPDU_TXQ: use the TXQ for bufferable MMPDUs, this of
 *	course requires the driver to use TXQs to start with.
 *
 * @IEEE80211_HW_SUPPORTS_VHT_EXT_NSS_BW: (Hardware) rate control supports VHT
 *	extended NSS BW (dot11VHTExtendedNSSBWCapable). This flag will be set if
 *	the selected rate control algorithm sets %RATE_CTRL_CAPA_VHT_EXT_NSS_BW
 *	but if the rate control is built-in then it must be set by the driver.
 *	See also the documentation for that flag.
 *
 * @IEEE80211_HW_STA_MMPDU_TXQ: use the extra non-TID per-station TXQ for all
 *	MMPDUs on station interfaces. This of course requires the driver to use
 *	TXQs to start with.
 *
 * @IEEE80211_HW_TX_STATUS_NO_AMPDU_LEN: Driver does not report accurate A-MPDU
 *	length in tx status information
 *
 * @IEEE80211_HW_SUPPORTS_MULTI_BSSID: Hardware supports multi BSSID
 *
 * @IEEE80211_HW_SUPPORTS_ONLY_HE_MULTI_BSSID: Hardware supports multi BSSID
 *	only for HE APs. Applies if @IEEE80211_HW_SUPPORTS_MULTI_BSSID is set.
 *
 * @IEEE80211_HW_AMPDU_KEYBORDER_SUPPORT: The card and driver is only
 *	aggregating MPDUs with the same keyid, allowing mac80211 to keep Tx
 *	A-MPDU sessions active while rekeying with Extended Key ID.
 *
 * @IEEE80211_HW_SUPPORTS_TX_ENCAP_OFFLOAD: Hardware supports tx encapsulation
 *	offload
 *
 * @NUM_IEEE80211_HW_FLAGS: number of hardware flags, used for sizing arrays
 */
```

## 2932. original/linux-5.10.260/include/net/mac80211.h:2443

Líneas 2443–2443; tipo `block`.

```text
/* keep last, obviously */
```

## 2933. original/linux-5.10.260/include/net/mac80211.h:2447

Líneas 2447–2571; tipo `block`.

```text
/**
 * struct ieee80211_hw - hardware information and state
 *
 * This structure contains the configuration and hardware
 * information for an 802.11 PHY.
 *
 * @wiphy: This points to the &struct wiphy allocated for this
 *	802.11 PHY. You must fill in the @perm_addr and @dev
 *	members of this structure using SET_IEEE80211_DEV()
 *	and SET_IEEE80211_PERM_ADDR(). Additionally, all supported
 *	bands (with channels, bitrates) are registered here.
 *
 * @conf: &struct ieee80211_conf, device configuration, don't use.
 *
 * @priv: pointer to private area that was allocated for driver use
 *	along with this structure.
 *
 * @flags: hardware flags, see &enum ieee80211_hw_flags.
 *
 * @extra_tx_headroom: headroom to reserve in each transmit skb
 *	for use by the driver (e.g. for transmit headers.)
 *
 * @extra_beacon_tailroom: tailroom to reserve in each beacon tx skb.
 *	Can be used by drivers to add extra IEs.
 *
 * @max_signal: Maximum value for signal (rssi) in RX information, used
 *	only when @IEEE80211_HW_SIGNAL_UNSPEC or @IEEE80211_HW_SIGNAL_DB
 *
 * @max_listen_interval: max listen interval in units of beacon interval
 *	that HW supports
 *
 * @queues: number of available hardware transmit queues for
 *	data packets. WMM/QoS requires at least four, these
 *	queues need to have configurable access parameters.
 *
 * @rate_control_algorithm: rate control algorithm for this hardware.
 *	If unset (NULL), the default algorithm will be used. Must be
 *	set before calling ieee80211_register_hw().
 *
 * @vif_data_size: size (in bytes) of the drv_priv data area
 *	within &struct ieee80211_vif.
 * @sta_data_size: size (in bytes) of the drv_priv data area
 *	within &struct ieee80211_sta.
 * @chanctx_data_size: size (in bytes) of the drv_priv data area
 *	within &struct ieee80211_chanctx_conf.
 * @txq_data_size: size (in bytes) of the drv_priv data area
 *	within @struct ieee80211_txq.
 *
 * @max_rates: maximum number of alternate rate retry stages the hw
 *	can handle.
 * @max_report_rates: maximum number of alternate rate retry stages
 *	the hw can report back.
 * @max_rate_tries: maximum number of tries for each stage
 *
 * @max_rx_aggregation_subframes: maximum buffer size (number of
 *	sub-frames) to be used for A-MPDU block ack receiver
 *	aggregation.
 *	This is only relevant if the device has restrictions on the
 *	number of subframes, if it relies on mac80211 to do reordering
 *	it shouldn't be set.
 *
 * @max_tx_aggregation_subframes: maximum number of subframes in an
 *	aggregate an HT/HE device will transmit. In HT AddBA we'll
 *	advertise a constant value of 64 as some older APs crash if
 *	the window size is smaller (an example is LinkSys WRT120N
 *	with FW v1.0.07 build 002 Jun 18 2012).
 *	For AddBA to HE capable peers this value will be used.
 *
 * @max_tx_fragments: maximum number of tx buffers per (A)-MSDU, sum
 *	of 1 + skb_shinfo(skb)->nr_frags for each skb in the frag_list.
 *
 * @offchannel_tx_hw_queue: HW queue ID to use for offchannel TX
 *	(if %IEEE80211_HW_QUEUE_CONTROL is set)
 *
 * @radiotap_mcs_details: lists which MCS information can the HW
 *	reports, by default it is set to _MCS, _GI and _BW but doesn't
 *	include _FMT. Use %IEEE80211_RADIOTAP_MCS_HAVE_\* values, only
 *	adding _BW is supported today.
 *
 * @radiotap_vht_details: lists which VHT MCS information the HW reports,
 *	the default is _GI | _BANDWIDTH.
 *	Use the %IEEE80211_RADIOTAP_VHT_KNOWN_\* values.
 *
 * @radiotap_he: HE radiotap validity flags
 *
 * @radiotap_timestamp: Information for the radiotap timestamp field; if the
 *	@units_pos member is set to a non-negative value then the timestamp
 *	field will be added and populated from the &struct ieee80211_rx_status
 *	device_timestamp.
 * @radiotap_timestamp.units_pos: Must be set to a combination of a
 *	IEEE80211_RADIOTAP_TIMESTAMP_UNIT_* and a
 *	IEEE80211_RADIOTAP_TIMESTAMP_SPOS_* value.
 * @radiotap_timestamp.accuracy: If non-negative, fills the accuracy in the
 *	radiotap field and the accuracy known flag will be set.
 *
 * @netdev_features: netdev features to be set in each netdev created
 *	from this HW. Note that not all features are usable with mac80211,
 *	other features will be rejected during HW registration.
 *
 * @uapsd_queues: This bitmap is included in (re)association frame to indicate
 *	for each access category if it is uAPSD trigger-enabled and delivery-
 *	enabled. Use IEEE80211_WMM_IE_STA_QOSINFO_AC_* to set this bitmap.
 *	Each bit corresponds to different AC. Value '1' in specific bit means
 *	that corresponding AC is both trigger- and delivery-enabled. '0' means
 *	neither enabled.
 *
 * @uapsd_max_sp_len: maximum number of total buffered frames the WMM AP may
 *	deliver to a WMM STA during any Service Period triggered by the WMM STA.
 *	Use IEEE80211_WMM_IE_STA_QOSINFO_SP_* for correct values.
 *
 * @n_cipher_schemes: a size of an array of cipher schemes definitions.
 * @cipher_schemes: a pointer to an array of cipher scheme definitions
 *	supported by HW.
 * @max_nan_de_entries: maximum number of NAN DE functions supported by the
 *	device.
 *
 * @tx_sk_pacing_shift: Pacing shift to set on TCP sockets when frames from
 *	them are encountered. The default should typically not be changed,
 *	unless the driver has good reasons for needing more buffers.
 *
 * @weight_multiplier: Driver specific airtime weight multiplier used while
 *	refilling deficit of each TXQ.
 *
 * @max_mtu: the max mtu could be set.
 */
```

## 2934. original/linux-5.10.260/include/net/mac80211.h:2625

Líneas 2625–2630; tipo `block`.

```text
/**
 * struct ieee80211_scan_request - hw scan request
 *
 * @ies: pointers different parts of IEs (in req.ie)
 * @req: cfg80211 request.
 */
```

## 2935. original/linux-5.10.260/include/net/mac80211.h:2634

Líneas 2634–2634; tipo `block`.

```text
/* Keep last */
```

## 2936. original/linux-5.10.260/include/net/mac80211.h:2638

Líneas 2638–2650; tipo `block`.

```text
/**
 * struct ieee80211_tdls_ch_sw_params - TDLS channel switch parameters
 *
 * @sta: peer this TDLS channel-switch request/response came from
 * @chandef: channel referenced in a TDLS channel-switch request
 * @action_code: see &enum ieee80211_tdls_actioncode
 * @status: channel-switch response status
 * @timestamp: time at which the frame was received
 * @switch_time: switch-timing parameter received in the frame
 * @switch_timeout: switch-timing parameter received in the frame
 * @tmpl_skb: TDLS switch-channel response template
 * @ch_sw_tm_ie: offset of the channel-switch timing IE inside @tmpl_skb
 */
```

## 2937. original/linux-5.10.260/include/net/mac80211.h:2663

Líneas 2663–2675; tipo `block`.

```text
/**
 * wiphy_to_ieee80211_hw - return a mac80211 driver hw struct from a wiphy
 *
 * @wiphy: the &struct wiphy which we want to query
 *
 * mac80211 drivers can use this to get to their respective
 * &struct ieee80211_hw. Drivers wishing to get to their own private
 * structure can then access it via hw->priv. Note that mac802111 drivers should
 * not use wiphy_priv() to try to get their private driver structure as this
 * is already used internally by mac80211.
 *
 * Return: The mac80211 driver hw struct of @wiphy.
 */
```

## 2938. original/linux-5.10.260/include/net/mac80211.h:2678

Líneas 2678–2683; tipo `block`.

```text
/**
 * SET_IEEE80211_DEV - set device for 802.11 hardware
 *
 * @hw: the &struct ieee80211_hw to set the device for
 * @dev: the &struct device of this 802.11 device
 */
```

## 2939. original/linux-5.10.260/include/net/mac80211.h:2689

Líneas 2689–2694; tipo `block`.

```text
/**
 * SET_IEEE80211_PERM_ADDR - set the permanent MAC address for 802.11 hardware
 *
 * @hw: the &struct ieee80211_hw to set the MAC address for
 * @addr: the address to set
 */
```

## 2940. original/linux-5.10.260/include/net/mac80211.h:2727

Líneas 2727–2734; tipo `block`.

```text
/**
 * ieee80211_free_txskb - free TX skb
 * @hw: the hardware
 * @skb: the skb
 *
 * Free a transmit skb. Use this function when some failure
 * to transmit happened and thus status cannot be reported.
 */
```

## 2941. original/linux-5.10.260/include/net/mac80211.h:2737

Líneas 2737–2803; tipo `block`.

```text
/**
 * DOC: Hardware crypto acceleration
 *
 * mac80211 is capable of taking advantage of many hardware
 * acceleration designs for encryption and decryption operations.
 *
 * The set_key() callback in the &struct ieee80211_ops for a given
 * device is called to enable hardware acceleration of encryption and
 * decryption. The callback takes a @sta parameter that will be NULL
 * for default keys or keys used for transmission only, or point to
 * the station information for the peer for individual keys.
 * Multiple transmission keys with the same key index may be used when
 * VLANs are configured for an access point.
 *
 * When transmitting, the TX control data will use the @hw_key_idx
 * selected by the driver by modifying the &struct ieee80211_key_conf
 * pointed to by the @key parameter to the set_key() function.
 *
 * The set_key() call for the %SET_KEY command should return 0 if
 * the key is now in use, -%EOPNOTSUPP or -%ENOSPC if it couldn't be
 * added; if you return 0 then hw_key_idx must be assigned to the
 * hardware key index, you are free to use the full u8 range.
 *
 * Note that in the case that the @IEEE80211_HW_SW_CRYPTO_CONTROL flag is
 * set, mac80211 will not automatically fall back to software crypto if
 * enabling hardware crypto failed. The set_key() call may also return the
 * value 1 to permit this specific key/algorithm to be done in software.
 *
 * When the cmd is %DISABLE_KEY then it must succeed.
 *
 * Note that it is permissible to not decrypt a frame even if a key
 * for it has been uploaded to hardware, the stack will not make any
 * decision based on whether a key has been uploaded or not but rather
 * based on the receive flags.
 *
 * The &struct ieee80211_key_conf structure pointed to by the @key
 * parameter is guaranteed to be valid until another call to set_key()
 * removes it, but it can only be used as a cookie to differentiate
 * keys.
 *
 * In TKIP some HW need to be provided a phase 1 key, for RX decryption
 * acceleration (i.e. iwlwifi). Those drivers should provide update_tkip_key
 * handler.
 * The update_tkip_key() call updates the driver with the new phase 1 key.
 * This happens every time the iv16 wraps around (every 65536 packets). The
 * set_key() call will happen only once for each key (unless the AP did
 * rekeying), it will not include a valid phase 1 key. The valid phase 1 key is
 * provided by update_tkip_key only. The trigger that makes mac80211 call this
 * handler is software decryption with wrap around of iv16.
 *
 * The set_default_unicast_key() call updates the default WEP key index
 * configured to the hardware for WEP encryption type. This is required
 * for devices that support offload of data packets (e.g. ARP responses).
 *
 * Mac80211 drivers should set the @NL80211_EXT_FEATURE_CAN_REPLACE_PTK0 flag
 * when they are able to replace in-use PTK keys according to the following
 * requirements:
 * 1) They do not hand over frames decrypted with the old key to
      mac80211 once the call to set_key() with command %DISABLE_KEY has been
      completed when also setting @IEEE80211_KEY_FLAG_GENERATE_IV for any key,
   2) either drop or continue to use the old key for any outgoing frames queued
      at the time of the key deletion (including re-transmits),
   3) never send out a frame queued prior to the set_key() %SET_KEY command
      encrypted with the new key and
   4) never send out a frame unencrypted when it should be encrypted.
   Mac80211 will not queue any new frames for a deleted key to the driver.
 */
```

## 2942. original/linux-5.10.260/include/net/mac80211.h:2805

Líneas 2805–2864; tipo `block`.

```text
/**
 * DOC: Powersave support
 *
 * mac80211 has support for various powersave implementations.
 *
 * First, it can support hardware that handles all powersaving by itself,
 * such hardware should simply set the %IEEE80211_HW_SUPPORTS_PS hardware
 * flag. In that case, it will be told about the desired powersave mode
 * with the %IEEE80211_CONF_PS flag depending on the association status.
 * The hardware must take care of sending nullfunc frames when necessary,
 * i.e. when entering and leaving powersave mode. The hardware is required
 * to look at the AID in beacons and signal to the AP that it woke up when
 * it finds traffic directed to it.
 *
 * %IEEE80211_CONF_PS flag enabled means that the powersave mode defined in
 * IEEE 802.11-2007 section 11.2 is enabled. This is not to be confused
 * with hardware wakeup and sleep states. Driver is responsible for waking
 * up the hardware before issuing commands to the hardware and putting it
 * back to sleep at appropriate times.
 *
 * When PS is enabled, hardware needs to wakeup for beacons and receive the
 * buffered multicast/broadcast frames after the beacon. Also it must be
 * possible to send frames and receive the acknowledment frame.
 *
 * Other hardware designs cannot send nullfunc frames by themselves and also
 * need software support for parsing the TIM bitmap. This is also supported
 * by mac80211 by combining the %IEEE80211_HW_SUPPORTS_PS and
 * %IEEE80211_HW_PS_NULLFUNC_STACK flags. The hardware is of course still
 * required to pass up beacons. The hardware is still required to handle
 * waking up for multicast traffic; if it cannot the driver must handle that
 * as best as it can, mac80211 is too slow to do that.
 *
 * Dynamic powersave is an extension to normal powersave in which the
 * hardware stays awake for a user-specified period of time after sending a
 * frame so that reply frames need not be buffered and therefore delayed to
 * the next wakeup. It's compromise of getting good enough latency when
 * there's data traffic and still saving significantly power in idle
 * periods.
 *
 * Dynamic powersave is simply supported by mac80211 enabling and disabling
 * PS based on traffic. Driver needs to only set %IEEE80211_HW_SUPPORTS_PS
 * flag and mac80211 will handle everything automatically. Additionally,
 * hardware having support for the dynamic PS feature may set the
 * %IEEE80211_HW_SUPPORTS_DYNAMIC_PS flag to indicate that it can support
 * dynamic PS mode itself. The driver needs to look at the
 * @dynamic_ps_timeout hardware configuration value and use it that value
 * whenever %IEEE80211_CONF_PS is set. In this case mac80211 will disable
 * dynamic PS feature in stack and will just keep %IEEE80211_CONF_PS
 * enabled whenever user has enabled powersave.
 *
 * Driver informs U-APSD client support by enabling
 * %IEEE80211_VIF_SUPPORTS_UAPSD flag. The mode is configured through the
 * uapsd parameter in conf_tx() operation. Hardware needs to send the QoS
 * Nullfunc frames and stay awake until the service period has ended. To
 * utilize U-APSD, dynamic powersave is disabled for voip AC and all frames
 * from that AC are transmitted with powersave enabled.
 *
 * Note: U-APSD client mode is not yet supported with
 * %IEEE80211_HW_PS_NULLFUNC_STACK.
 */
```

## 2943. original/linux-5.10.260/include/net/mac80211.h:2866

Líneas 2866–2925; tipo `block`.

```text
/**
 * DOC: Beacon filter support
 *
 * Some hardware have beacon filter support to reduce host cpu wakeups
 * which will reduce system power consumption. It usually works so that
 * the firmware creates a checksum of the beacon but omits all constantly
 * changing elements (TSF, TIM etc). Whenever the checksum changes the
 * beacon is forwarded to the host, otherwise it will be just dropped. That
 * way the host will only receive beacons where some relevant information
 * (for example ERP protection or WMM settings) have changed.
 *
 * Beacon filter support is advertised with the %IEEE80211_VIF_BEACON_FILTER
 * interface capability. The driver needs to enable beacon filter support
 * whenever power save is enabled, that is %IEEE80211_CONF_PS is set. When
 * power save is enabled, the stack will not check for beacon loss and the
 * driver needs to notify about loss of beacons with ieee80211_beacon_loss().
 *
 * The time (or number of beacons missed) until the firmware notifies the
 * driver of a beacon loss event (which in turn causes the driver to call
 * ieee80211_beacon_loss()) should be configurable and will be controlled
 * by mac80211 and the roaming algorithm in the future.
 *
 * Since there may be constantly changing information elements that nothing
 * in the software stack cares about, we will, in the future, have mac80211
 * tell the driver which information elements are interesting in the sense
 * that we want to see changes in them. This will include
 *
 *  - a list of information element IDs
 *  - a list of OUIs for the vendor information element
 *
 * Ideally, the hardware would filter out any beacons without changes in the
 * requested elements, but if it cannot support that it may, at the expense
 * of some efficiency, filter out only a subset. For example, if the device
 * doesn't support checking for OUIs it should pass up all changes in all
 * vendor information elements.
 *
 * Note that change, for the sake of simplification, also includes information
 * elements appearing or disappearing from the beacon.
 *
 * Some hardware supports an "ignore list" instead, just make sure nothing
 * that was requested is on the ignore list, and include commonly changing
 * information element IDs in the ignore list, for example 11 (BSS load) and
 * the various vendor-assigned IEs with unknown contents (128, 129, 133-136,
 * 149, 150, 155, 156, 173, 176, 178, 179, 219); for forward compatibility
 * it could also include some currently unused IDs.
 *
 *
 * In addition to these capabilities, hardware should support notifying the
 * host of changes in the beacon RSSI. This is relevant to implement roaming
 * when no traffic is flowing (when traffic is flowing we see the RSSI of
 * the received data packets). This can consist in notifying the host when
 * the RSSI changes significantly or when it drops below or rises above
 * configurable thresholds. In the future these thresholds will also be
 * configured by mac80211 (which gets them from userspace) to implement
 * them as the roaming algorithm requires.
 *
 * If the hardware cannot implement this, the driver should ask it to
 * periodically pass beacon frames to the host so that software can do the
 * signal strength threshold checking.
 */
```

## 2944. original/linux-5.10.260/include/net/mac80211.h:2927

Líneas 2927–2950; tipo `block`.

```text
/**
 * DOC: Spatial multiplexing power save
 *
 * SMPS (Spatial multiplexing power save) is a mechanism to conserve
 * power in an 802.11n implementation. For details on the mechanism
 * and rationale, please refer to 802.11 (as amended by 802.11n-2009)
 * "11.2.3 SM power save".
 *
 * The mac80211 implementation is capable of sending action frames
 * to update the AP about the station's SMPS mode, and will instruct
 * the driver to enter the specific mode. It will also announce the
 * requested SMPS mode during the association handshake. Hardware
 * support for this feature is required, and can be indicated by
 * hardware flags.
 *
 * The default mode will be "automatic", which nl80211/cfg80211
 * defines to be dynamic SMPS in (regular) powersave, and SMPS
 * turned off otherwise.
 *
 * To support this feature, the driver must set the appropriate
 * hardware support flags, and handle the SMPS flag to the config()
 * operation. It will then with this mechanism be instructed to
 * enter the requested SMPS mode while associated to an HT AP.
 */
```

## 2945. original/linux-5.10.260/include/net/mac80211.h:2952

Líneas 2952–2990; tipo `block`.

```text
/**
 * DOC: Frame filtering
 *
 * mac80211 requires to see many management frames for proper
 * operation, and users may want to see many more frames when
 * in monitor mode. However, for best CPU usage and power consumption,
 * having as few frames as possible percolate through the stack is
 * desirable. Hence, the hardware should filter as much as possible.
 *
 * To achieve this, mac80211 uses filter flags (see below) to tell
 * the driver's configure_filter() function which frames should be
 * passed to mac80211 and which should be filtered out.
 *
 * Before configure_filter() is invoked, the prepare_multicast()
 * callback is invoked with the parameters @mc_count and @mc_list
 * for the combined multicast address list of all virtual interfaces.
 * It's use is optional, and it returns a u64 that is passed to
 * configure_filter(). Additionally, configure_filter() has the
 * arguments @changed_flags telling which flags were changed and
 * @total_flags with the new flag states.
 *
 * If your device has no multicast address filters your driver will
 * need to check both the %FIF_ALLMULTI flag and the @mc_count
 * parameter to see whether multicast frames should be accepted
 * or dropped.
 *
 * All unsupported flags in @total_flags must be cleared.
 * Hardware does not support a flag if it is incapable of _passing_
 * the frame to the stack. Otherwise the driver must ignore
 * the flag, but not clear it.
 * You must _only_ clear the flag (announce no support for the
 * flag to mac80211) if you are not able to pass the packet type
 * to the stack (so the hardware always filters it).
 * So for example, you should clear @FIF_CONTROL, if your hardware
 * always filters control frames. If your hardware always passes
 * control frames to the kernel and is incapable of filtering them,
 * you do _not_ clear the @FIF_CONTROL flag.
 * This rule applies to all other FIF flags as well.
 */
```

## 2946. original/linux-5.10.260/include/net/mac80211.h:2992

Líneas 2992–3087; tipo `block`.

```text
/**
 * DOC: AP support for powersaving clients
 *
 * In order to implement AP and P2P GO modes, mac80211 has support for
 * client powersaving, both "legacy" PS (PS-Poll/null data) and uAPSD.
 * There currently is no support for sAPSD.
 *
 * There is one assumption that mac80211 makes, namely that a client
 * will not poll with PS-Poll and trigger with uAPSD at the same time.
 * Both are supported, and both can be used by the same client, but
 * they can't be used concurrently by the same client. This simplifies
 * the driver code.
 *
 * The first thing to keep in mind is that there is a flag for complete
 * driver implementation: %IEEE80211_HW_AP_LINK_PS. If this flag is set,
 * mac80211 expects the driver to handle most of the state machine for
 * powersaving clients and will ignore the PM bit in incoming frames.
 * Drivers then use ieee80211_sta_ps_transition() to inform mac80211 of
 * stations' powersave transitions. In this mode, mac80211 also doesn't
 * handle PS-Poll/uAPSD.
 *
 * In the mode without %IEEE80211_HW_AP_LINK_PS, mac80211 will check the
 * PM bit in incoming frames for client powersave transitions. When a
 * station goes to sleep, we will stop transmitting to it. There is,
 * however, a race condition: a station might go to sleep while there is
 * data buffered on hardware queues. If the device has support for this
 * it will reject frames, and the driver should give the frames back to
 * mac80211 with the %IEEE80211_TX_STAT_TX_FILTERED flag set which will
 * cause mac80211 to retry the frame when the station wakes up. The
 * driver is also notified of powersave transitions by calling its
 * @sta_notify callback.
 *
 * When the station is asleep, it has three choices: it can wake up,
 * it can PS-Poll, or it can possibly start a uAPSD service period.
 * Waking up is implemented by simply transmitting all buffered (and
 * filtered) frames to the station. This is the easiest case. When
 * the station sends a PS-Poll or a uAPSD trigger frame, mac80211
 * will inform the driver of this with the @allow_buffered_frames
 * callback; this callback is optional. mac80211 will then transmit
 * the frames as usual and set the %IEEE80211_TX_CTL_NO_PS_BUFFER
 * on each frame. The last frame in the service period (or the only
 * response to a PS-Poll) also has %IEEE80211_TX_STATUS_EOSP set to
 * indicate that it ends the service period; as this frame must have
 * TX status report it also sets %IEEE80211_TX_CTL_REQ_TX_STATUS.
 * When TX status is reported for this frame, the service period is
 * marked has having ended and a new one can be started by the peer.
 *
 * Additionally, non-bufferable MMPDUs can also be transmitted by
 * mac80211 with the %IEEE80211_TX_CTL_NO_PS_BUFFER set in them.
 *
 * Another race condition can happen on some devices like iwlwifi
 * when there are frames queued for the station and it wakes up
 * or polls; the frames that are already queued could end up being
 * transmitted first instead, causing reordering and/or wrong
 * processing of the EOSP. The cause is that allowing frames to be
 * transmitted to a certain station is out-of-band communication to
 * the device. To allow this problem to be solved, the driver can
 * call ieee80211_sta_block_awake() if frames are buffered when it
 * is notified that the station went to sleep. When all these frames
 * have been filtered (see above), it must call the function again
 * to indicate that the station is no longer blocked.
 *
 * If the driver buffers frames in the driver for aggregation in any
 * way, it must use the ieee80211_sta_set_buffered() call when it is
 * notified of the station going to sleep to inform mac80211 of any
 * TIDs that have frames buffered. Note that when a station wakes up
 * this information is reset (hence the requirement to call it when
 * informed of the station going to sleep). Then, when a service
 * period starts for any reason, @release_buffered_frames is called
 * with the number of frames to be released and which TIDs they are
 * to come from. In this case, the driver is responsible for setting
 * the EOSP (for uAPSD) and MORE_DATA bits in the released frames,
 * to help the @more_data parameter is passed to tell the driver if
 * there is more data on other TIDs -- the TIDs to release frames
 * from are ignored since mac80211 doesn't know how many frames the
 * buffers for those TIDs contain.
 *
 * If the driver also implement GO mode, where absence periods may
 * shorten service periods (or abort PS-Poll responses), it must
 * filter those response frames except in the case of frames that
 * are buffered in the driver -- those must remain buffered to avoid
 * reordering. Because it is possible that no frames are released
 * in this case, the driver must call ieee80211_sta_eosp()
 * to indicate to mac80211 that the service period ended anyway.
 *
 * Finally, if frames from multiple TIDs are released from mac80211
 * but the driver might reorder them, it must clear & set the flags
 * appropriately (only the last frame may have %IEEE80211_TX_STATUS_EOSP)
 * and also take care of the EOSP and MORE_DATA bits in the frame.
 * The driver may also use ieee80211_sta_eosp() in this case.
 *
 * Note that if the driver ever buffers frames other than QoS-data
 * frames, it must take care to never send a non-QoS-data frame as
 * the last frame in a service period, adding a QoS-nulldata frame
 * after a non-QoS-data frame if needed.
 */
```

## 2947. original/linux-5.10.260/include/net/mac80211.h:3089

Líneas 3089–3142; tipo `block`.

```text
/**
 * DOC: HW queue control
 *
 * Before HW queue control was introduced, mac80211 only had a single static
 * assignment of per-interface AC software queues to hardware queues. This
 * was problematic for a few reasons:
 * 1) off-channel transmissions might get stuck behind other frames
 * 2) multiple virtual interfaces couldn't be handled correctly
 * 3) after-DTIM frames could get stuck behind other frames
 *
 * To solve this, hardware typically uses multiple different queues for all
 * the different usages, and this needs to be propagated into mac80211 so it
 * won't have the same problem with the software queues.
 *
 * Therefore, mac80211 now offers the %IEEE80211_HW_QUEUE_CONTROL capability
 * flag that tells it that the driver implements its own queue control. To do
 * so, the driver will set up the various queues in each &struct ieee80211_vif
 * and the offchannel queue in &struct ieee80211_hw. In response, mac80211 will
 * use those queue IDs in the hw_queue field of &struct ieee80211_tx_info and
 * if necessary will queue the frame on the right software queue that mirrors
 * the hardware queue.
 * Additionally, the driver has to then use these HW queue IDs for the queue
 * management functions (ieee80211_stop_queue() et al.)
 *
 * The driver is free to set up the queue mappings as needed, multiple virtual
 * interfaces may map to the same hardware queues if needed. The setup has to
 * happen during add_interface or change_interface callbacks. For example, a
 * driver supporting station+station and station+AP modes might decide to have
 * 10 hardware queues to handle different scenarios:
 *
 * 4 AC HW queues for 1st vif: 0, 1, 2, 3
 * 4 AC HW queues for 2nd vif: 4, 5, 6, 7
 * after-DTIM queue for AP:   8
 * off-channel queue:         9
 *
 * It would then set up the hardware like this:
 *   hw.offchannel_tx_hw_queue = 9
 *
 * and the first virtual interface that is added as follows:
 *   vif.hw_queue[IEEE80211_AC_VO] = 0
 *   vif.hw_queue[IEEE80211_AC_VI] = 1
 *   vif.hw_queue[IEEE80211_AC_BE] = 2
 *   vif.hw_queue[IEEE80211_AC_BK] = 3
 *   vif.cab_queue = 8 // if AP mode, otherwise %IEEE80211_INVAL_HW_QUEUE
 * and the second virtual interface with 4-7.
 *
 * If queue 6 gets full, for example, mac80211 would only stop the second
 * virtual interface's BE queue since virtual interface queues are per AC.
 *
 * Note that the vif.cab_queue value should be set to %IEEE80211_INVAL_HW_QUEUE
 * whenever the queue is not used (i.e. the interface is not in AP mode) if the
 * queue could potentially be shared since mac80211 will look at cab_queue when
 * a queue is stopped/woken even if the interface is not in AP mode.
 */
```

## 2948. original/linux-5.10.260/include/net/mac80211.h:3144

Líneas 3144–3178; tipo `block`.

```text
/**
 * enum ieee80211_filter_flags - hardware filter flags
 *
 * These flags determine what the filter in hardware should be
 * programmed to let through and what should not be passed to the
 * stack. It is always safe to pass more frames than requested,
 * but this has negative impact on power consumption.
 *
 * @FIF_ALLMULTI: pass all multicast frames, this is used if requested
 *	by the user or if the hardware is not capable of filtering by
 *	multicast address.
 *
 * @FIF_FCSFAIL: pass frames with failed FCS (but you need to set the
 *	%RX_FLAG_FAILED_FCS_CRC for them)
 *
 * @FIF_PLCPFAIL: pass frames with failed PLCP CRC (but you need to set
 *	the %RX_FLAG_FAILED_PLCP_CRC for them
 *
 * @FIF_BCN_PRBRESP_PROMISC: This flag is set during scanning to indicate
 *	to the hardware that it should not filter beacons or probe responses
 *	by BSSID. Filtering them can greatly reduce the amount of processing
 *	mac80211 needs to do and the amount of CPU wakeups, so you should
 *	honour this flag if possible.
 *
 * @FIF_CONTROL: pass control frames (except for PS Poll) addressed to this
 *	station
 *
 * @FIF_OTHER_BSS: pass frames destined to other BSSes
 *
 * @FIF_PSPOLL: pass PS Poll frames
 *
 * @FIF_PROBE_REQ: pass probe request frames
 *
 * @FIF_MCAST_ACTION: pass multicast Action frames
 */
```

## 2949. original/linux-5.10.260/include/net/mac80211.h:3191

Líneas 3191–3222; tipo `block`.

```text
/**
 * enum ieee80211_ampdu_mlme_action - A-MPDU actions
 *
 * These flags are used with the ampdu_action() callback in
 * &struct ieee80211_ops to indicate which action is needed.
 *
 * Note that drivers MUST be able to deal with a TX aggregation
 * session being stopped even before they OK'ed starting it by
 * calling ieee80211_start_tx_ba_cb_irqsafe, because the peer
 * might receive the addBA frame and send a delBA right away!
 *
 * @IEEE80211_AMPDU_RX_START: start RX aggregation
 * @IEEE80211_AMPDU_RX_STOP: stop RX aggregation
 * @IEEE80211_AMPDU_TX_START: start TX aggregation, the driver must either
 *	call ieee80211_start_tx_ba_cb_irqsafe() or
 *	call ieee80211_start_tx_ba_cb_irqsafe() with status
 *	%IEEE80211_AMPDU_TX_START_DELAY_ADDBA to delay addba after
 *	ieee80211_start_tx_ba_cb_irqsafe is called, or just return the special
 *	status %IEEE80211_AMPDU_TX_START_IMMEDIATE.
 * @IEEE80211_AMPDU_TX_OPERATIONAL: TX aggregation has become operational
 * @IEEE80211_AMPDU_TX_STOP_CONT: stop TX aggregation but continue transmitting
 *	queued packets, now unaggregated. After all packets are transmitted the
 *	driver has to call ieee80211_stop_tx_ba_cb_irqsafe().
 * @IEEE80211_AMPDU_TX_STOP_FLUSH: stop TX aggregation and flush all packets,
 *	called when the station is removed. There's no need or reason to call
 *	ieee80211_stop_tx_ba_cb_irqsafe() in this case as mac80211 assumes the
 *	session is gone and removes the station.
 * @IEEE80211_AMPDU_TX_STOP_FLUSH_CONT: called when TX aggregation is stopped
 *	but the driver hasn't called ieee80211_stop_tx_ba_cb_irqsafe() yet and
 *	now the connection is dropped and the station will be removed. Drivers
 *	should clean up and drop remaining packets when this is called.
 */
```

## 2950. original/linux-5.10.260/include/net/mac80211.h:3236

Líneas 3236–3252; tipo `block`.

```text
/**
 * struct ieee80211_ampdu_params - AMPDU action parameters
 *
 * @action: the ampdu action, value from %ieee80211_ampdu_mlme_action.
 * @sta: peer of this AMPDU session
 * @tid: tid of the BA session
 * @ssn: start sequence number of the session. TX/RX_STOP can pass 0. When
 *	action is set to %IEEE80211_AMPDU_RX_START the driver passes back the
 *	actual ssn value used to start the session and writes the value here.
 * @buf_size: reorder buffer size  (number of subframes). Valid only when the
 *	action is set to %IEEE80211_AMPDU_RX_START or
 *	%IEEE80211_AMPDU_TX_OPERATIONAL
 * @amsdu: indicates the peer's ability to receive A-MSDU within A-MPDU.
 *	valid when the action is set to %IEEE80211_AMPDU_TX_OPERATIONAL
 * @timeout: BA session timeout. Valid only when the action is set to
 *	%IEEE80211_AMPDU_RX_START
 */
```

## 2951. original/linux-5.10.260/include/net/mac80211.h:3263

Líneas 3263–3268; tipo `block`.

```text
/**
 * enum ieee80211_frame_release_type - frame release reason
 * @IEEE80211_FRAME_RELEASE_PSPOLL: frame released for PS-Poll
 * @IEEE80211_FRAME_RELEASE_UAPSD: frame(s) released due to
 *	frame received on trigger-enabled AC
 */
```

## 2952. original/linux-5.10.260/include/net/mac80211.h:3274

Líneas 3274–3287; tipo `block`.

```text
/**
 * enum ieee80211_rate_control_changed - flags to indicate what changed
 *
 * @IEEE80211_RC_BW_CHANGED: The bandwidth that can be used to transmit
 *	to this station changed. The actual bandwidth is in the station
 *	information -- for HT20/40 the IEEE80211_HT_CAP_SUP_WIDTH_20_40
 *	flag changes, for HT and VHT the bandwidth field changes.
 * @IEEE80211_RC_SMPS_CHANGED: The SMPS state of the station changed.
 * @IEEE80211_RC_SUPP_RATES_CHANGED: The supported rate set of this peer
 *	changed (in IBSS mode) due to discovering more information about
 *	the peer.
 * @IEEE80211_RC_NSS_CHANGED: N_SS (number of spatial streams) was changed
 *	by the peer
 */
```

## 2953. original/linux-5.10.260/include/net/mac80211.h:3295

Líneas 3295–3307; tipo `block`.

```text
/**
 * enum ieee80211_roc_type - remain on channel type
 *
 * With the support for multi channel contexts and multi channel operations,
 * remain on channel operations might be limited/deferred/aborted by other
 * flows/operations which have higher priority (and vice versa).
 * Specifying the ROC type can be used by devices to prioritize the ROC
 * operations compared to other operations/flows.
 *
 * @IEEE80211_ROC_TYPE_NORMAL: There are no special requirements for this ROC.
 * @IEEE80211_ROC_TYPE_MGMT_TX: The remain on channel request is required
 *	for sending management frames offchannel.
 */
```

## 2954. original/linux-5.10.260/include/net/mac80211.h:3313

Líneas 3313–3323; tipo `block`.

```text
/**
 * enum ieee80211_reconfig_type - reconfig type
 *
 * This enum is used by the reconfig_complete() callback to indicate what
 * reconfiguration type was completed.
 *
 * @IEEE80211_RECONFIG_TYPE_RESTART: hw restart type
 *	(also due to resume() callback returning 1)
 * @IEEE80211_RECONFIG_TYPE_SUSPEND: suspend type (regardless
 *	of wowlan configuration)
 */
```

## 2955. original/linux-5.10.260/include/net/mac80211.h:3329

Líneas 3329–3880; tipo `block`.

```text
/**
 * struct ieee80211_ops - callbacks from mac80211 to the driver
 *
 * This structure contains various callbacks that the driver may
 * handle or, in some cases, must handle, for example to configure
 * the hardware to a new channel or to transmit a frame.
 *
 * @tx: Handler that 802.11 module calls for each transmitted frame.
 *	skb contains the buffer starting from the IEEE 802.11 header.
 *	The low-level driver should send the frame out based on
 *	configuration in the TX control data. This handler should,
 *	preferably, never fail and stop queues appropriately.
 *	Must be atomic.
 *
 * @start: Called before the first netdevice attached to the hardware
 *	is enabled. This should turn on the hardware and must turn on
 *	frame reception (for possibly enabled monitor interfaces.)
 *	Returns negative error codes, these may be seen in userspace,
 *	or zero.
 *	When the device is started it should not have a MAC address
 *	to avoid acknowledging frames before a non-monitor device
 *	is added.
 *	Must be implemented and can sleep.
 *
 * @stop: Called after last netdevice attached to the hardware
 *	is disabled. This should turn off the hardware (at least
 *	it must turn off frame reception.)
 *	May be called right after add_interface if that rejects
 *	an interface. If you added any work onto the mac80211 workqueue
 *	you should ensure to cancel it on this callback.
 *	Must be implemented and can sleep.
 *
 * @suspend: Suspend the device; mac80211 itself will quiesce before and
 *	stop transmitting and doing any other configuration, and then
 *	ask the device to suspend. This is only invoked when WoWLAN is
 *	configured, otherwise the device is deconfigured completely and
 *	reconfigured at resume time.
 *	The driver may also impose special conditions under which it
 *	wants to use the "normal" suspend (deconfigure), say if it only
 *	supports WoWLAN when the device is associated. In this case, it
 *	must return 1 from this function.
 *
 * @resume: If WoWLAN was configured, this indicates that mac80211 is
 *	now resuming its operation, after this the device must be fully
 *	functional again. If this returns an error, the only way out is
 *	to also unregister the device. If it returns 1, then mac80211
 *	will also go through the regular complete restart on resume.
 *
 * @set_wakeup: Enable or disable wakeup when WoWLAN configuration is
 *	modified. The reason is that device_set_wakeup_enable() is
 *	supposed to be called when the configuration changes, not only
 *	in suspend().
 *
 * @add_interface: Called when a netdevice attached to the hardware is
 *	enabled. Because it is not called for monitor mode devices, @start
 *	and @stop must be implemented.
 *	The driver should perform any initialization it needs before
 *	the device can be enabled. The initial configuration for the
 *	interface is given in the conf parameter.
 *	The callback may refuse to add an interface by returning a
 *	negative error code (which will be seen in userspace.)
 *	Must be implemented and can sleep.
 *
 * @change_interface: Called when a netdevice changes type. This callback
 *	is optional, but only if it is supported can interface types be
 *	switched while the interface is UP. The callback may sleep.
 *	Note that while an interface is being switched, it will not be
 *	found by the interface iteration callbacks.
 *
 * @remove_interface: Notifies a driver that an interface is going down.
 *	The @stop callback is called after this if it is the last interface
 *	and no monitor interfaces are present.
 *	When all interfaces are removed, the MAC address in the hardware
 *	must be cleared so the device no longer acknowledges packets,
 *	the mac_addr member of the conf structure is, however, set to the
 *	MAC address of the device going away.
 *	Hence, this callback must be implemented. It can sleep.
 *
 * @config: Handler for configuration requests. IEEE 802.11 code calls this
 *	function to change hardware configuration, e.g., channel.
 *	This function should never fail but returns a negative error code
 *	if it does. The callback can sleep.
 *
 * @bss_info_changed: Handler for configuration requests related to BSS
 *	parameters that may vary during BSS's lifespan, and may affect low
 *	level driver (e.g. assoc/disassoc status, erp parameters).
 *	This function should not be used if no BSS has been set, unless
 *	for association indication. The @changed parameter indicates which
 *	of the bss parameters has changed when a call is made. The callback
 *	can sleep.
 *
 * @prepare_multicast: Prepare for multicast filter configuration.
 *	This callback is optional, and its return value is passed
 *	to configure_filter(). This callback must be atomic.
 *
 * @configure_filter: Configure the device's RX filter.
 *	See the section "Frame filtering" for more information.
 *	This callback must be implemented and can sleep.
 *
 * @config_iface_filter: Configure the interface's RX filter.
 *	This callback is optional and is used to configure which frames
 *	should be passed to mac80211. The filter_flags is the combination
 *	of FIF_* flags. The changed_flags is a bit mask that indicates
 *	which flags are changed.
 *	This callback can sleep.
 *
 * @set_tim: Set TIM bit. mac80211 calls this function when a TIM bit
 * 	must be set or cleared for a given STA. Must be atomic.
 *
 * @set_key: See the section "Hardware crypto acceleration"
 *	This callback is only called between add_interface and
 *	remove_interface calls, i.e. while the given virtual interface
 *	is enabled.
 *	Returns a negative error code if the key can't be added.
 *	The callback can sleep.
 *
 * @update_tkip_key: See the section "Hardware crypto acceleration"
 * 	This callback will be called in the context of Rx. Called for drivers
 * 	which set IEEE80211_KEY_FLAG_TKIP_REQ_RX_P1_KEY.
 *	The callback must be atomic.
 *
 * @set_rekey_data: If the device supports GTK rekeying, for example while the
 *	host is suspended, it can assign this callback to retrieve the data
 *	necessary to do GTK rekeying, this is the KEK, KCK and replay counter.
 *	After rekeying was done it should (for example during resume) notify
 *	userspace of the new replay counter using ieee80211_gtk_rekey_notify().
 *
 * @set_default_unicast_key: Set the default (unicast) key index, useful for
 *	WEP when the device sends data packets autonomously, e.g. for ARP
 *	offloading. The index can be 0-3, or -1 for unsetting it.
 *
 * @hw_scan: Ask the hardware to service the scan request, no need to start
 *	the scan state machine in stack. The scan must honour the channel
 *	configuration done by the regulatory agent in the wiphy's
 *	registered bands. The hardware (or the driver) needs to make sure
 *	that power save is disabled.
 *	The @req ie/ie_len members are rewritten by mac80211 to contain the
 *	entire IEs after the SSID, so that drivers need not look at these
 *	at all but just send them after the SSID -- mac80211 includes the
 *	(extended) supported rates and HT information (where applicable).
 *	When the scan finishes, ieee80211_scan_completed() must be called;
 *	note that it also must be called when the scan cannot finish due to
 *	any error unless this callback returned a negative error code.
 *	This callback is also allowed to return the special return value 1,
 *	this indicates that hardware scan isn't desirable right now and a
 *	software scan should be done instead. A driver wishing to use this
 *	capability must ensure its (hardware) scan capabilities aren't
 *	advertised as more capable than mac80211's software scan is.
 *	The callback can sleep.
 *
 * @cancel_hw_scan: Ask the low-level tp cancel the active hw scan.
 *	The driver should ask the hardware to cancel the scan (if possible),
 *	but the scan will be completed only after the driver will call
 *	ieee80211_scan_completed().
 *	This callback is needed for wowlan, to prevent enqueueing a new
 *	scan_work after the low-level driver was already suspended.
 *	The callback can sleep.
 *
 * @sched_scan_start: Ask the hardware to start scanning repeatedly at
 *	specific intervals.  The driver must call the
 *	ieee80211_sched_scan_results() function whenever it finds results.
 *	This process will continue until sched_scan_stop is called.
 *
 * @sched_scan_stop: Tell the hardware to stop an ongoing scheduled scan.
 *	In this case, ieee80211_sched_scan_stopped() must not be called.
 *
 * @sw_scan_start: Notifier function that is called just before a software scan
 *	is started. Can be NULL, if the driver doesn't need this notification.
 *	The mac_addr parameter allows supporting NL80211_SCAN_FLAG_RANDOM_ADDR,
 *	the driver may set the NL80211_FEATURE_SCAN_RANDOM_MAC_ADDR flag if it
 *	can use this parameter. The callback can sleep.
 *
 * @sw_scan_complete: Notifier function that is called just after a
 *	software scan finished. Can be NULL, if the driver doesn't need
 *	this notification.
 *	The callback can sleep.
 *
 * @get_stats: Return low-level statistics.
 * 	Returns zero if statistics are available.
 *	The callback can sleep.
 *
 * @get_key_seq: If your device implements encryption in hardware and does
 *	IV/PN assignment then this callback should be provided to read the
 *	IV/PN for the given key from hardware.
 *	The callback must be atomic.
 *
 * @set_frag_threshold: Configuration of fragmentation threshold. Assign this
 *	if the device does fragmentation by itself. Note that to prevent the
 *	stack from doing fragmentation IEEE80211_HW_SUPPORTS_TX_FRAG
 *	should be set as well.
 *	The callback can sleep.
 *
 * @set_rts_threshold: Configuration of RTS threshold (if device needs it)
 *	The callback can sleep.
 *
 * @sta_add: Notifies low level driver about addition of an associated station,
 *	AP, IBSS/WDS/mesh peer etc. This callback can sleep.
 *
 * @sta_remove: Notifies low level driver about removal of an associated
 *	station, AP, IBSS/WDS/mesh peer etc. Note that after the callback
 *	returns it isn't safe to use the pointer, not even RCU protected;
 *	no RCU grace period is guaranteed between returning here and freeing
 *	the station. See @sta_pre_rcu_remove if needed.
 *	This callback can sleep.
 *
 * @sta_add_debugfs: Drivers can use this callback to add debugfs files
 *	when a station is added to mac80211's station list. This callback
 *	should be within a CONFIG_MAC80211_DEBUGFS conditional. This
 *	callback can sleep.
 *
 * @sta_notify: Notifies low level driver about power state transition of an
 *	associated station, AP,  IBSS/WDS/mesh peer etc. For a VIF operating
 *	in AP mode, this callback will not be called when the flag
 *	%IEEE80211_HW_AP_LINK_PS is set. Must be atomic.
 *
 * @sta_set_txpwr: Configure the station tx power. This callback set the tx
 *	power for the station.
 *	This callback can sleep.
 *
 * @sta_state: Notifies low level driver about state transition of a
 *	station (which can be the AP, a client, IBSS/WDS/mesh peer etc.)
 *	This callback is mutually exclusive with @sta_add/@sta_remove.
 *	It must not fail for down transitions but may fail for transitions
 *	up the list of states. Also note that after the callback returns it
 *	isn't safe to use the pointer, not even RCU protected - no RCU grace
 *	period is guaranteed between returning here and freeing the station.
 *	See @sta_pre_rcu_remove if needed.
 *	The callback can sleep.
 *
 * @sta_pre_rcu_remove: Notify driver about station removal before RCU
 *	synchronisation. This is useful if a driver needs to have station
 *	pointers protected using RCU, it can then use this call to clear
 *	the pointers instead of waiting for an RCU grace period to elapse
 *	in @sta_state.
 *	The callback can sleep.
 *
 * @sta_rc_update: Notifies the driver of changes to the bitrates that can be
 *	used to transmit to the station. The changes are advertised with bits
 *	from &enum ieee80211_rate_control_changed and the values are reflected
 *	in the station data. This callback should only be used when the driver
 *	uses hardware rate control (%IEEE80211_HW_HAS_RATE_CONTROL) since
 *	otherwise the rate control algorithm is notified directly.
 *	Must be atomic.
 * @sta_rate_tbl_update: Notifies the driver that the rate table changed. This
 *	is only used if the configured rate control algorithm actually uses
 *	the new rate table API, and is therefore optional. Must be atomic.
 *
 * @sta_statistics: Get statistics for this station. For example with beacon
 *	filtering, the statistics kept by mac80211 might not be accurate, so
 *	let the driver pre-fill the statistics. The driver can fill most of
 *	the values (indicating which by setting the filled bitmap), but not
 *	all of them make sense - see the source for which ones are possible.
 *	Statistics that the driver doesn't fill will be filled by mac80211.
 *	The callback can sleep.
 *
 * @conf_tx: Configure TX queue parameters (EDCF (aifs, cw_min, cw_max),
 *	bursting) for a hardware TX queue.
 *	Returns a negative error code on failure.
 *	The callback can sleep.
 *
 * @get_tsf: Get the current TSF timer value from firmware/hardware. Currently,
 *	this is only used for IBSS mode BSSID merging and debugging. Is not a
 *	required function.
 *	The callback can sleep.
 *
 * @set_tsf: Set the TSF timer to the specified value in the firmware/hardware.
 *	Currently, this is only used for IBSS mode debugging. Is not a
 *	required function.
 *	The callback can sleep.
 *
 * @offset_tsf: Offset the TSF timer by the specified value in the
 *	firmware/hardware.  Preferred to set_tsf as it avoids delay between
 *	calling set_tsf() and hardware getting programmed, which will show up
 *	as TSF delay. Is not a required function.
 *	The callback can sleep.
 *
 * @reset_tsf: Reset the TSF timer and allow firmware/hardware to synchronize
 *	with other STAs in the IBSS. This is only used in IBSS mode. This
 *	function is optional if the firmware/hardware takes full care of
 *	TSF synchronization.
 *	The callback can sleep.
 *
 * @tx_last_beacon: Determine whether the last IBSS beacon was sent by us.
 *	This is needed only for IBSS mode and the result of this function is
 *	used to determine whether to reply to Probe Requests.
 *	Returns non-zero if this device sent the last beacon.
 *	The callback can sleep.
 *
 * @get_survey: Return per-channel survey information
 *
 * @rfkill_poll: Poll rfkill hardware state. If you need this, you also
 *	need to set wiphy->rfkill_poll to %true before registration,
 *	and need to call wiphy_rfkill_set_hw_state() in the callback.
 *	The callback can sleep.
 *
 * @set_coverage_class: Set slot time for given coverage class as specified
 *	in IEEE 802.11-2007 section 17.3.8.6 and modify ACK timeout
 *	accordingly; coverage class equals to -1 to enable ACK timeout
 *	estimation algorithm (dynack). To disable dynack set valid value for
 *	coverage class. This callback is not required and may sleep.
 *
 * @testmode_cmd: Implement a cfg80211 test mode command. The passed @vif may
 *	be %NULL. The callback can sleep.
 * @testmode_dump: Implement a cfg80211 test mode dump. The callback can sleep.
 *
 * @flush: Flush all pending frames from the hardware queue, making sure
 *	that the hardware queues are empty. The @queues parameter is a bitmap
 *	of queues to flush, which is useful if different virtual interfaces
 *	use different hardware queues; it may also indicate all queues.
 *	If the parameter @drop is set to %true, pending frames may be dropped.
 *	Note that vif can be NULL.
 *	The callback can sleep.
 *
 * @channel_switch: Drivers that need (or want) to offload the channel
 *	switch operation for CSAs received from the AP may implement this
 *	callback. They must then call ieee80211_chswitch_done() to indicate
 *	completion of the channel switch.
 *
 * @set_antenna: Set antenna configuration (tx_ant, rx_ant) on the device.
 *	Parameters are bitmaps of allowed antennas to use for TX/RX. Drivers may
 *	reject TX/RX mask combinations they cannot support by returning -EINVAL
 *	(also see nl80211.h @NL80211_ATTR_WIPHY_ANTENNA_TX).
 *
 * @get_antenna: Get current antenna configuration from device (tx_ant, rx_ant).
 *
 * @remain_on_channel: Starts an off-channel period on the given channel, must
 *	call back to ieee80211_ready_on_channel() when on that channel. Note
 *	that normal channel traffic is not stopped as this is intended for hw
 *	offload. Frames to transmit on the off-channel channel are transmitted
 *	normally except for the %IEEE80211_TX_CTL_TX_OFFCHAN flag. When the
 *	duration (which will always be non-zero) expires, the driver must call
 *	ieee80211_remain_on_channel_expired().
 *	Note that this callback may be called while the device is in IDLE and
 *	must be accepted in this case.
 *	This callback may sleep.
 * @cancel_remain_on_channel: Requests that an ongoing off-channel period is
 *	aborted before it expires. This callback may sleep.
 *
 * @set_ringparam: Set tx and rx ring sizes.
 *
 * @get_ringparam: Get tx and rx ring current and maximum sizes.
 *
 * @tx_frames_pending: Check if there is any pending frame in the hardware
 *	queues before entering power save.
 *
 * @set_bitrate_mask: Set a mask of rates to be used for rate control selection
 *	when transmitting a frame. Currently only legacy rates are handled.
 *	The callback can sleep.
 * @event_callback: Notify driver about any event in mac80211. See
 *	&enum ieee80211_event_type for the different types.
 *	The callback must be atomic.
 *
 * @release_buffered_frames: Release buffered frames according to the given
 *	parameters. In the case where the driver buffers some frames for
 *	sleeping stations mac80211 will use this callback to tell the driver
 *	to release some frames, either for PS-poll or uAPSD.
 *	Note that if the @more_data parameter is %false the driver must check
 *	if there are more frames on the given TIDs, and if there are more than
 *	the frames being released then it must still set the more-data bit in
 *	the frame. If the @more_data parameter is %true, then of course the
 *	more-data bit must always be set.
 *	The @tids parameter tells the driver which TIDs to release frames
 *	from, for PS-poll it will always have only a single bit set.
 *	In the case this is used for a PS-poll initiated release, the
 *	@num_frames parameter will always be 1 so code can be shared. In
 *	this case the driver must also set %IEEE80211_TX_STATUS_EOSP flag
 *	on the TX status (and must report TX status) so that the PS-poll
 *	period is properly ended. This is used to avoid sending multiple
 *	responses for a retried PS-poll frame.
 *	In the case this is used for uAPSD, the @num_frames parameter may be
 *	bigger than one, but the driver may send fewer frames (it must send
 *	at least one, however). In this case it is also responsible for
 *	setting the EOSP flag in the QoS header of the frames. Also, when the
 *	service period ends, the driver must set %IEEE80211_TX_STATUS_EOSP
 *	on the last frame in the SP. Alternatively, it may call the function
 *	ieee80211_sta_eosp() to inform mac80211 of the end of the SP.
 *	This callback must be atomic.
 * @allow_buffered_frames: Prepare device to allow the given number of frames
 *	to go out to the given station. The frames will be sent by mac80211
 *	via the usual TX path after this call. The TX information for frames
 *	released will also have the %IEEE80211_TX_CTL_NO_PS_BUFFER flag set
 *	and the last one will also have %IEEE80211_TX_STATUS_EOSP set. In case
 *	frames from multiple TIDs are released and the driver might reorder
 *	them between the TIDs, it must set the %IEEE80211_TX_STATUS_EOSP flag
 *	on the last frame and clear it on all others and also handle the EOSP
 *	bit in the QoS header correctly. Alternatively, it can also call the
 *	ieee80211_sta_eosp() function.
 *	The @tids parameter is a bitmap and tells the driver which TIDs the
 *	frames will be on; it will at most have two bits set.
 *	This callback must be atomic.
 *
 * @get_et_sset_count:  Ethtool API to get string-set count.
 *
 * @get_et_stats:  Ethtool API to get a set of u64 stats.
 *
 * @get_et_strings:  Ethtool API to get a set of strings to describe stats
 *	and perhaps other supported types of ethtool data-sets.
 *
 * @mgd_prepare_tx: Prepare for transmitting a management frame for association
 *	before associated. In multi-channel scenarios, a virtual interface is
 *	bound to a channel before it is associated, but as it isn't associated
 *	yet it need not necessarily be given airtime, in particular since any
 *	transmission to a P2P GO needs to be synchronized against the GO's
 *	powersave state. mac80211 will call this function before transmitting a
 *	management frame prior to having successfully associated to allow the
 *	driver to give it channel time for the transmission, to get a response
 *	and to be able to synchronize with the GO.
 *	For drivers that set %IEEE80211_HW_DEAUTH_NEED_MGD_TX_PREP, mac80211
 *	would also call this function before transmitting a deauthentication
 *	frame in case that no beacon was heard from the AP/P2P GO.
 *	The callback will be called before each transmission and upon return
 *	mac80211 will transmit the frame right away.
 *      If duration is greater than zero, mac80211 hints to the driver the
 *      duration for which the operation is requested.
 *	The callback is optional and can (should!) sleep.
 *
 * @mgd_protect_tdls_discover: Protect a TDLS discovery session. After sending
 *	a TDLS discovery-request, we expect a reply to arrive on the AP's
 *	channel. We must stay on the channel (no PSM, scan, etc.), since a TDLS
 *	setup-response is a direct packet not buffered by the AP.
 *	mac80211 will call this function just before the transmission of a TDLS
 *	discovery-request. The recommended period of protection is at least
 *	2 * (DTIM period).
 *	The callback is optional and can sleep.
 *
 * @add_chanctx: Notifies device driver about new channel context creation.
 *	This callback may sleep.
 * @remove_chanctx: Notifies device driver about channel context destruction.
 *	This callback may sleep.
 * @change_chanctx: Notifies device driver about channel context changes that
 *	may happen when combining different virtual interfaces on the same
 *	channel context with different settings
 *	This callback may sleep.
 * @assign_vif_chanctx: Notifies device driver about channel context being bound
 *	to vif. Possible use is for hw queue remapping.
 *	This callback may sleep.
 * @unassign_vif_chanctx: Notifies device driver about channel context being
 *	unbound from vif.
 *	This callback may sleep.
 * @switch_vif_chanctx: switch a number of vifs from one chanctx to
 *	another, as specified in the list of
 *	@ieee80211_vif_chanctx_switch passed to the driver, according
 *	to the mode defined in &ieee80211_chanctx_switch_mode.
 *	This callback may sleep.
 *
 * @start_ap: Start operation on the AP interface, this is called after all the
 *	information in bss_conf is set and beacon can be retrieved. A channel
 *	context is bound before this is called. Note that if the driver uses
 *	software scan or ROC, this (and @stop_ap) isn't called when the AP is
 *	just "paused" for scanning/ROC, which is indicated by the beacon being
 *	disabled/enabled via @bss_info_changed.
 * @stop_ap: Stop operation on the AP interface.
 *
 * @reconfig_complete: Called after a call to ieee80211_restart_hw() and
 *	during resume, when the reconfiguration has completed.
 *	This can help the driver implement the reconfiguration step (and
 *	indicate mac80211 is ready to receive frames).
 *	This callback may sleep.
 *
 * @ipv6_addr_change: IPv6 address assignment on the given interface changed.
 *	Currently, this is only called for managed or P2P client interfaces.
 *	This callback is optional; it must not sleep.
 *
 * @channel_switch_beacon: Starts a channel switch to a new channel.
 *	Beacons are modified to include CSA or ECSA IEs before calling this
 *	function. The corresponding count fields in these IEs must be
 *	decremented, and when they reach 1 the driver must call
 *	ieee80211_csa_finish(). Drivers which use ieee80211_beacon_get()
 *	get the csa counter decremented by mac80211, but must check if it is
 *	1 using ieee80211_beacon_counter_is_complete() after the beacon has been
 *	transmitted and then call ieee80211_csa_finish().
 *	If the CSA count starts as zero or 1, this function will not be called,
 *	since there won't be any time to beacon before the switch anyway.
 * @pre_channel_switch: This is an optional callback that is called
 *	before a channel switch procedure is started (ie. when a STA
 *	gets a CSA or a userspace initiated channel-switch), allowing
 *	the driver to prepare for the channel switch.
 * @post_channel_switch: This is an optional callback that is called
 *	after a channel switch procedure is completed, allowing the
 *	driver to go back to a normal configuration.
 * @abort_channel_switch: This is an optional callback that is called
 *	when channel switch procedure was completed, allowing the
 *	driver to go back to a normal configuration.
 * @channel_switch_rx_beacon: This is an optional callback that is called
 *	when channel switch procedure is in progress and additional beacon with
 *	CSA IE was received, allowing driver to track changes in count.
 * @join_ibss: Join an IBSS (on an IBSS interface); this is called after all
 *	information in bss_conf is set up and the beacon can be retrieved. A
 *	channel context is bound before this is called.
 * @leave_ibss: Leave the IBSS again.
 *
 * @get_expected_throughput: extract the expected throughput towards the
 *	specified station. The returned value is expressed in Kbps. It returns 0
 *	if the RC algorithm does not have proper data to provide.
 *
 * @get_txpower: get current maximum tx power (in dBm) based on configuration
 *	and hardware limits.
 *
 * @tdls_channel_switch: Start channel-switching with a TDLS peer. The driver
 *	is responsible for continually initiating channel-switching operations
 *	and returning to the base channel for communication with the AP. The
 *	driver receives a channel-switch request template and the location of
 *	the switch-timing IE within the template as part of the invocation.
 *	The template is valid only within the call, and the driver can
 *	optionally copy the skb for further re-use.
 * @tdls_cancel_channel_switch: Stop channel-switching with a TDLS peer. Both
 *	peers must be on the base channel when the call completes.
 * @tdls_recv_channel_switch: a TDLS channel-switch related frame (request or
 *	response) has been received from a remote peer. The driver gets
 *	parameters parsed from the incoming frame and may use them to continue
 *	an ongoing channel-switch operation. In addition, a channel-switch
 *	response template is provided, together with the location of the
 *	switch-timing IE within the template. The skb can only be used within
 *	the function call.
 *
 * @wake_tx_queue: Called when new packets have been added to the queue.
 * @sync_rx_queues: Process all pending frames in RSS queues. This is a
 *	synchronization which is needed in case driver has in its RSS queues
 *	pending frames that were received prior to the control path action
 *	currently taken (e.g. disassociation) but are not processed yet.
 *
 * @start_nan: join an existing NAN cluster, or create a new one.
 * @stop_nan: leave the NAN cluster.
 * @nan_change_conf: change NAN configuration. The data in cfg80211_nan_conf
 *	contains full new configuration and changes specify which parameters
 *	are changed with respect to the last NAN config.
 *	The driver gets both full configuration and the changed parameters since
 *	some devices may need the full configuration while others need only the
 *	changed parameters.
 * @add_nan_func: Add a NAN function. Returns 0 on success. The data in
 *	cfg80211_nan_func must not be referenced outside the scope of
 *	this call.
 * @del_nan_func: Remove a NAN function. The driver must call
 *	ieee80211_nan_func_terminated() with
 *	NL80211_NAN_FUNC_TERM_REASON_USER_REQUEST reason code upon removal.
 * @can_aggregate_in_amsdu: Called in order to determine if HW supports
 *	aggregating two specific frames in the same A-MSDU. The relation
 *	between the skbs should be symmetric and transitive. Note that while
 *	skb is always a real frame, head may or may not be an A-MSDU.
 * @get_ftm_responder_stats: Retrieve FTM responder statistics, if available.
 *	Statistics should be cumulative, currently no way to reset is provided.
 *
 * @start_pmsr: start peer measurement (e.g. FTM) (this call can sleep)
 * @abort_pmsr: abort peer measurement (this call can sleep)
 * @set_tid_config: Apply TID specific configurations. This callback may sleep.
 * @reset_tid_config: Reset TID specific configuration for the peer.
 *	This callback may sleep.
 * @update_vif_offload: Update virtual interface offload flags
 *	This callback may sleep.
 * @sta_set_4addr: Called to notify the driver when a station starts/stops using
 *	4-address mode
 */
```

## 2956. original/linux-5.10.260/include/net/mac80211.h:3999

Líneas 3999–4029; tipo `block`.

```text
/**
	 * @ampdu_action:
	 * Perform a certain A-MPDU action.
	 * The RA/TID combination determines the destination and TID we want
	 * the ampdu action to be performed for. The action is defined through
	 * ieee80211_ampdu_mlme_action.
	 * When the action is set to %IEEE80211_AMPDU_TX_OPERATIONAL the driver
	 * may neither send aggregates containing more subframes than @buf_size
	 * nor send aggregates in a way that lost frames would exceed the
	 * buffer size. If just limiting the aggregate size, this would be
	 * possible with a buf_size of 8:
	 *
	 * - ``TX: 1.....7``
	 * - ``RX:  2....7`` (lost frame #1)
	 * - ``TX:        8..1...``
	 *
	 * which is invalid since #1 was now re-transmitted well past the
	 * buffer size of 8. Correct ways to retransmit #1 would be:
	 *
	 * - ``TX:        1   or``
	 * - ``TX:        18  or``
	 * - ``TX:        81``
	 *
	 * Even ``189`` would be wrong since 1 could be lost again.
	 *
	 * Returns a negative error code on failure. The driver may return
	 * %IEEE80211_AMPDU_TX_START_IMMEDIATE for %IEEE80211_AMPDU_TX_START
	 * if the session can start immediately.
	 *
	 * The callback can sleep.
	 */
```

## 2957. original/linux-5.10.260/include/net/mac80211.h:4197

Líneas 4197–4212; tipo `block`.

```text
/**
 * ieee80211_alloc_hw_nm - Allocate a new hardware device
 *
 * This must be called once for each hardware device. The returned pointer
 * must be used to refer to this device when calling other functions.
 * mac80211 allocates a private data area for the driver pointed to by
 * @priv in &struct ieee80211_hw, the size of this area is given as
 * @priv_data_len.
 *
 * @priv_data_len: length of private data
 * @ops: callbacks for this device
 * @requested_name: Requested name for this device.
 *	NULL is valid value, and means use the default naming (phy%d)
 *
 * Return: A pointer to the new hardware device, or %NULL on error.
 */
```

## 2958. original/linux-5.10.260/include/net/mac80211.h:4217

Líneas 4217–4230; tipo `block`.

```text
/**
 * ieee80211_alloc_hw - Allocate a new hardware device
 *
 * This must be called once for each hardware device. The returned pointer
 * must be used to refer to this device when calling other functions.
 * mac80211 allocates a private data area for the driver pointed to by
 * @priv in &struct ieee80211_hw, the size of this area is given as
 * @priv_data_len.
 *
 * @priv_data_len: length of private data
 * @ops: callbacks for this device
 *
 * Return: A pointer to the new hardware device, or %NULL on error.
 */
```

## 2959. original/linux-5.10.260/include/net/mac80211.h:4238

Líneas 4238–4248; tipo `block`.

```text
/**
 * ieee80211_register_hw - Register hardware device
 *
 * You must call this function before any other functions in
 * mac80211. Note that before a hardware can be registered, you
 * need to fill the contained wiphy's information.
 *
 * @hw: the device to register as returned by ieee80211_alloc_hw()
 *
 * Return: 0 on success. An error code otherwise.
 */
```

## 2960. original/linux-5.10.260/include/net/mac80211.h:4251

Líneas 4251–4256; tipo `block`.

```text
/**
 * struct ieee80211_tpt_blink - throughput blink description
 * @throughput: throughput in Kbit/sec
 * @blink_time: blink time in milliseconds
 *	(full cycle, ie. one off + one on period)
 */
```

## 2961. original/linux-5.10.260/include/net/mac80211.h:4262

Líneas 4262–4268; tipo `block`.

```text
/**
 * enum ieee80211_tpt_led_trigger_flags - throughput trigger flags
 * @IEEE80211_TPT_LEDTRIG_FL_RADIO: enable blinking with radio
 * @IEEE80211_TPT_LEDTRIG_FL_WORK: enable blinking when working
 * @IEEE80211_TPT_LEDTRIG_FL_CONNECTED: enable blinking when at least one
 *	interface is connected in some way, including being an AP
 */
```

## 2962. original/linux-5.10.260/include/net/mac80211.h:4286

Líneas 4286–4297; tipo `block`.

```text
/**
 * ieee80211_get_tx_led_name - get name of TX LED
 *
 * mac80211 creates a transmit LED trigger for each wireless hardware
 * that can be used to drive LEDs if your driver registers a LED device.
 * This function returns the name (or %NULL if not configured for LEDs)
 * of the trigger so you can automatically link the LED device.
 *
 * @hw: the hardware to get the LED trigger name for
 *
 * Return: The name of the LED trigger. %NULL if not configured for LEDs.
 */
```

## 2963. original/linux-5.10.260/include/net/mac80211.h:4307

Líneas 4307–4318; tipo `block`.

```text
/**
 * ieee80211_get_rx_led_name - get name of RX LED
 *
 * mac80211 creates a receive LED trigger for each wireless hardware
 * that can be used to drive LEDs if your driver registers a LED device.
 * This function returns the name (or %NULL if not configured for LEDs)
 * of the trigger so you can automatically link the LED device.
 *
 * @hw: the hardware to get the LED trigger name for
 *
 * Return: The name of the LED trigger. %NULL if not configured for LEDs.
 */
```

## 2964. original/linux-5.10.260/include/net/mac80211.h:4328

Líneas 4328–4339; tipo `block`.

```text
/**
 * ieee80211_get_assoc_led_name - get name of association LED
 *
 * mac80211 creates a association LED trigger for each wireless hardware
 * that can be used to drive LEDs if your driver registers a LED device.
 * This function returns the name (or %NULL if not configured for LEDs)
 * of the trigger so you can automatically link the LED device.
 *
 * @hw: the hardware to get the LED trigger name for
 *
 * Return: The name of the LED trigger. %NULL if not configured for LEDs.
 */
```

## 2965. original/linux-5.10.260/include/net/mac80211.h:4349

Líneas 4349–4360; tipo `block`.

```text
/**
 * ieee80211_get_radio_led_name - get name of radio LED
 *
 * mac80211 creates a radio change LED trigger for each wireless hardware
 * that can be used to drive LEDs if your driver registers a LED device.
 * This function returns the name (or %NULL if not configured for LEDs)
 * of the trigger so you can automatically link the LED device.
 *
 * @hw: the hardware to get the LED trigger name for
 *
 * Return: The name of the LED trigger. %NULL if not configured for LEDs.
 */
```

## 2966. original/linux-5.10.260/include/net/mac80211.h:4370

Líneas 4370–4381; tipo `block`.

```text
/**
 * ieee80211_create_tpt_led_trigger - create throughput LED trigger
 * @hw: the hardware to create the trigger for
 * @flags: trigger flags, see &enum ieee80211_tpt_led_trigger_flags
 * @blink_table: the blink table -- needs to be ordered by throughput
 * @blink_table_len: size of the blink table
 *
 * Return: %NULL (in case of error, or if no LED triggers are
 * configured) or the name of the new trigger.
 *
 * Note: This function must be called before ieee80211_register_hw().
 */
```

## 2967. original/linux-5.10.260/include/net/mac80211.h:4395

Líneas 4395–4402; tipo `block`.

```text
/**
 * ieee80211_unregister_hw - Unregister a hardware device
 *
 * This function instructs mac80211 to free allocated resources
 * and unregister netdevices from the networking subsystem.
 *
 * @hw: the hardware to unregister
 */
```

## 2968. original/linux-5.10.260/include/net/mac80211.h:4405

Líneas 4405–4413; tipo `block`.

```text
/**
 * ieee80211_free_hw - free hardware descriptor
 *
 * This function frees everything that was allocated, including the
 * private data for the driver. You must call ieee80211_unregister_hw()
 * before calling this function.
 *
 * @hw: the hardware to free
 */
```

## 2969. original/linux-5.10.260/include/net/mac80211.h:4416

Líneas 4416–4427; tipo `block`.

```text
/**
 * ieee80211_restart_hw - restart hardware completely
 *
 * Call this function when the hardware was restarted for some reason
 * (hardware error, ...) and the driver is unable to restore its state
 * by itself. mac80211 assumes that at this point the driver/hardware
 * is completely uninitialised and stopped, it starts the process by
 * calling the ->start() operation. The driver will need to reset all
 * internal state that it has prior to calling this function.
 *
 * @hw: the hardware to restart
 */
```

## 2970. original/linux-5.10.260/include/net/mac80211.h:4430

Líneas 4430–4451; tipo `block`.

```text
/**
 * ieee80211_rx_list - receive frame and store processed skbs in a list
 *
 * Use this function to hand received frames to mac80211. The receive
 * buffer in @skb must start with an IEEE 802.11 header. In case of a
 * paged @skb is used, the driver is recommended to put the ieee80211
 * header of the frame on the linear part of the @skb to avoid memory
 * allocation and/or memcpy by the stack.
 *
 * This function may not be called in IRQ context. Calls to this function
 * for a single hardware must be synchronized against each other. Calls to
 * this function, ieee80211_rx_ni() and ieee80211_rx_irqsafe() may not be
 * mixed for a single hardware. Must not run concurrently with
 * ieee80211_tx_status() or ieee80211_tx_status_ni().
 *
 * This function must be called with BHs disabled and RCU read lock
 *
 * @hw: the hardware this frame came in on
 * @sta: the station the frame was received from, or %NULL
 * @skb: the buffer to receive, owned by mac80211 after this call
 * @list: the destination list
 */
```

## 2971. original/linux-5.10.260/include/net/mac80211.h:4455

Líneas 4455–4476; tipo `block`.

```text
/**
 * ieee80211_rx_napi - receive frame from NAPI context
 *
 * Use this function to hand received frames to mac80211. The receive
 * buffer in @skb must start with an IEEE 802.11 header. In case of a
 * paged @skb is used, the driver is recommended to put the ieee80211
 * header of the frame on the linear part of the @skb to avoid memory
 * allocation and/or memcpy by the stack.
 *
 * This function may not be called in IRQ context. Calls to this function
 * for a single hardware must be synchronized against each other. Calls to
 * this function, ieee80211_rx_ni() and ieee80211_rx_irqsafe() may not be
 * mixed for a single hardware. Must not run concurrently with
 * ieee80211_tx_status() or ieee80211_tx_status_ni().
 *
 * This function must be called with BHs disabled.
 *
 * @hw: the hardware this frame came in on
 * @sta: the station the frame was received from, or %NULL
 * @skb: the buffer to receive, owned by mac80211 after this call
 * @napi: the NAPI context
 */
```

## 2972. original/linux-5.10.260/include/net/mac80211.h:4480

Líneas 4480–4499; tipo `block`.

```text
/**
 * ieee80211_rx - receive frame
 *
 * Use this function to hand received frames to mac80211. The receive
 * buffer in @skb must start with an IEEE 802.11 header. In case of a
 * paged @skb is used, the driver is recommended to put the ieee80211
 * header of the frame on the linear part of the @skb to avoid memory
 * allocation and/or memcpy by the stack.
 *
 * This function may not be called in IRQ context. Calls to this function
 * for a single hardware must be synchronized against each other. Calls to
 * this function, ieee80211_rx_ni() and ieee80211_rx_irqsafe() may not be
 * mixed for a single hardware. Must not run concurrently with
 * ieee80211_tx_status() or ieee80211_tx_status_ni().
 *
 * In process context use instead ieee80211_rx_ni().
 *
 * @hw: the hardware this frame came in on
 * @skb: the buffer to receive, owned by mac80211 after this call
 */
```

## 2973. original/linux-5.10.260/include/net/mac80211.h:4505

Líneas 4505–4517; tipo `block`.

```text
/**
 * ieee80211_rx_irqsafe - receive frame
 *
 * Like ieee80211_rx() but can be called in IRQ context
 * (internally defers to a tasklet.)
 *
 * Calls to this function, ieee80211_rx() or ieee80211_rx_ni() may not
 * be mixed for a single hardware.Must not run concurrently with
 * ieee80211_tx_status() or ieee80211_tx_status_ni().
 *
 * @hw: the hardware this frame came in on
 * @skb: the buffer to receive, owned by mac80211 after this call
 */
```

## 2974. original/linux-5.10.260/include/net/mac80211.h:4520

Líneas 4520–4532; tipo `block`.

```text
/**
 * ieee80211_rx_ni - receive frame (in process context)
 *
 * Like ieee80211_rx() but can be called in process context
 * (internally disables bottom halves).
 *
 * Calls to this function, ieee80211_rx() and ieee80211_rx_irqsafe() may
 * not be mixed for a single hardware. Must not run concurrently with
 * ieee80211_tx_status() or ieee80211_tx_status_ni().
 *
 * @hw: the hardware this frame came in on
 * @skb: the buffer to receive, owned by mac80211 after this call
 */
```

## 2975. original/linux-5.10.260/include/net/mac80211.h:4541

Líneas 4541–4557; tipo `block`.

```text
/**
 * ieee80211_sta_ps_transition - PS transition for connected sta
 *
 * When operating in AP mode with the %IEEE80211_HW_AP_LINK_PS
 * flag set, use this function to inform mac80211 about a connected station
 * entering/leaving PS mode.
 *
 * This function may not be called in IRQ context or with softirqs enabled.
 *
 * Calls to this function for a single hardware must be synchronized against
 * each other.
 *
 * @sta: currently connected sta
 * @start: start or stop PS
 *
 * Return: 0 on success. -EINVAL when the requested PS mode is already set.
 */
```

## 2976. original/linux-5.10.260/include/net/mac80211.h:4560

Líneas 4560–4572; tipo `block`.

```text
/**
 * ieee80211_sta_ps_transition_ni - PS transition for connected sta
 *                                  (in process context)
 *
 * Like ieee80211_sta_ps_transition() but can be called in process context
 * (internally disables bottom halves). Concurrent call restriction still
 * applies.
 *
 * @sta: currently connected sta
 * @start: start or stop PS
 *
 * Return: Like ieee80211_sta_ps_transition().
 */
```

## 2977. original/linux-5.10.260/include/net/mac80211.h:4585

Líneas 4585–4595; tipo `block`.

```text
/**
 * ieee80211_sta_pspoll - PS-Poll frame received
 * @sta: currently connected station
 *
 * When operating in AP mode with the %IEEE80211_HW_AP_LINK_PS flag set,
 * use this function to inform mac80211 that a PS-Poll frame from a
 * connected station was received.
 * This must be used in conjunction with ieee80211_sta_ps_transition()
 * and possibly ieee80211_sta_uapsd_trigger(); calls to all three must
 * be serialized.
 */
```

## 2978. original/linux-5.10.260/include/net/mac80211.h:4598

Líneas 4598–4613; tipo `block`.

```text
/**
 * ieee80211_sta_uapsd_trigger - (potential) U-APSD trigger frame received
 * @sta: currently connected station
 * @tid: TID of the received (potential) trigger frame
 *
 * When operating in AP mode with the %IEEE80211_HW_AP_LINK_PS flag set,
 * use this function to inform mac80211 that a (potential) trigger frame
 * from a connected station was received.
 * This must be used in conjunction with ieee80211_sta_ps_transition()
 * and possibly ieee80211_sta_pspoll(); calls to all three must be
 * serialized.
 * %IEEE80211_NUM_TIDS can be passed as the tid if the tid is unknown.
 * In this case, mac80211 will not check that this tid maps to an AC
 * that is trigger enabled and assume that the caller did the proper
 * checks.
 */
```

## 2979. original/linux-5.10.260/include/net/mac80211.h:4616

Líneas 4616–4619; tipo `block`.

```text
/*
 * The TX headroom reserved by mac80211 for its own tx_status functions.
 * This is enough for the radiotap header.
 */
```

## 2980. original/linux-5.10.260/include/net/mac80211.h:4622

Líneas 4622–4649; tipo `block`.

```text
/**
 * ieee80211_sta_set_buffered - inform mac80211 about driver-buffered frames
 * @sta: &struct ieee80211_sta pointer for the sleeping station
 * @tid: the TID that has buffered frames
 * @buffered: indicates whether or not frames are buffered for this TID
 *
 * If a driver buffers frames for a powersave station instead of passing
 * them back to mac80211 for retransmission, the station may still need
 * to be told that there are buffered frames via the TIM bit.
 *
 * This function informs mac80211 whether or not there are frames that are
 * buffered in the driver for a given TID; mac80211 can then use this data
 * to set the TIM bit (NOTE: This may call back into the driver's set_tim
 * call! Beware of the locking!)
 *
 * If all frames are released to the station (due to PS-poll or uAPSD)
 * then the driver needs to inform mac80211 that there no longer are
 * frames buffered. However, when the station wakes up mac80211 assumes
 * that all buffered frames will be transmitted and clears this data,
 * drivers need to make sure they inform mac80211 about all buffered
 * frames on the sleep transition (sta_notify() with %STA_NOTIFY_SLEEP).
 *
 * Note that technically mac80211 only needs to know this per AC, not per
 * TID, but since driver buffering will inevitably happen per TID (since
 * it is related to aggregation) it is easier to make mac80211 map the
 * TID to the AC as required instead of keeping track in all drivers that
 * use this API.
 */
```

## 2981. original/linux-5.10.260/include/net/mac80211.h:4653

Líneas 4653–4665; tipo `block`.

```text
/**
 * ieee80211_get_tx_rates - get the selected transmit rates for a packet
 *
 * Call this function in a driver with per-packet rate selection support
 * to combine the rate info in the packet tx info with the most recent
 * rate selection table for the station entry.
 *
 * @vif: &struct ieee80211_vif pointer from the add_interface callback.
 * @sta: the receiver station to which this packet is sent.
 * @skb: the frame to be transmitted.
 * @dest: buffer for extracted rate/retry information
 * @max_rates: maximum number of rates to fetch
 */
```

## 2982. original/linux-5.10.260/include/net/mac80211.h:4672

Líneas 4672–4684; tipo `block`.

```text
/**
 * ieee80211_sta_set_expected_throughput - set the expected tpt for a station
 *
 * Call this function to notify mac80211 about a change in expected throughput
 * to a station. A driver for a device that does rate control in firmware can
 * call this function when the expected throughput estimate towards a station
 * changes. The information is used to tune the CoDel AQM applied to traffic
 * going towards that station (which can otherwise be too aggressive and cause
 * slow stations to starve).
 *
 * @pubsta: the station to set throughput for.
 * @thr: the current expected throughput in kbps.
 */
```

## 2983. original/linux-5.10.260/include/net/mac80211.h:4688

Líneas 4688–4698; tipo `block`.

```text
/**
 * ieee80211_tx_rate_update - transmit rate update callback
 *
 * Drivers should call this functions with a non-NULL pub sta
 * This function can be used in drivers that does not have provision
 * in updating the tx rate in data path.
 *
 * @hw: the hardware the frame was transmitted by
 * @pubsta: the station to update the tx rate for.
 * @info: tx status information
 */
```

## 2984. original/linux-5.10.260/include/net/mac80211.h:4703

Líneas 4703–4718; tipo `block`.

```text
/**
 * ieee80211_tx_status - transmit status callback
 *
 * Call this function for all transmitted frames after they have been
 * transmitted. It is permissible to not call this function for
 * multicast frames but this can affect statistics.
 *
 * This function may not be called in IRQ context. Calls to this function
 * for a single hardware must be synchronized against each other. Calls
 * to this function, ieee80211_tx_status_ni() and ieee80211_tx_status_irqsafe()
 * may not be mixed for a single hardware. Must not run concurrently with
 * ieee80211_rx() or ieee80211_rx_ni().
 *
 * @hw: the hardware the frame was transmitted by
 * @skb: the frame that was transmitted, owned by mac80211 after this call
 */
```

## 2985. original/linux-5.10.260/include/net/mac80211.h:4722

Líneas 4722–4735; tipo `block`.

```text
/**
 * ieee80211_tx_status_ext - extended transmit status callback
 *
 * This function can be used as a replacement for ieee80211_tx_status
 * in drivers that may want to provide extra information that does not
 * fit into &struct ieee80211_tx_info.
 *
 * Calls to this function for a single hardware must be synchronized
 * against each other. Calls to this function, ieee80211_tx_status_ni()
 * and ieee80211_tx_status_irqsafe() may not be mixed for a single hardware.
 *
 * @hw: the hardware the frame was transmitted by
 * @status: tx status information
 */
```

## 2986. original/linux-5.10.260/include/net/mac80211.h:4739

Líneas 4739–4754; tipo `block`.

```text
/**
 * ieee80211_tx_status_noskb - transmit status callback without skb
 *
 * This function can be used as a replacement for ieee80211_tx_status
 * in drivers that cannot reliably map tx status information back to
 * specific skbs.
 *
 * Calls to this function for a single hardware must be synchronized
 * against each other. Calls to this function, ieee80211_tx_status_ni()
 * and ieee80211_tx_status_irqsafe() may not be mixed for a single hardware.
 *
 * @hw: the hardware the frame was transmitted by
 * @sta: the receiver station to which this packet is sent
 *	(NULL for multicast packets)
 * @info: tx status information
 */
```

## 2987. original/linux-5.10.260/include/net/mac80211.h:4767

Líneas 4767–4778; tipo `block`.

```text
/**
 * ieee80211_tx_status_ni - transmit status callback (in process context)
 *
 * Like ieee80211_tx_status() but can be called in process context.
 *
 * Calls to this function, ieee80211_tx_status() and
 * ieee80211_tx_status_irqsafe() may not be mixed
 * for a single hardware.
 *
 * @hw: the hardware the frame was transmitted by
 * @skb: the frame that was transmitted, owned by mac80211 after this call
 */
```

## 2988. original/linux-5.10.260/include/net/mac80211.h:4787

Líneas 4787–4798; tipo `block`.

```text
/**
 * ieee80211_tx_status_irqsafe - IRQ-safe transmit status callback
 *
 * Like ieee80211_tx_status() but can be called in IRQ context
 * (internally defers to a tasklet.)
 *
 * Calls to this function, ieee80211_tx_status() and
 * ieee80211_tx_status_ni() may not be mixed for a single hardware.
 *
 * @hw: the hardware the frame was transmitted by
 * @skb: the frame that was transmitted, owned by mac80211 after this call
 */
```

## 2989. original/linux-5.10.260/include/net/mac80211.h:4802

Líneas 4802–4817; tipo `block`.

```text
/**
 * ieee80211_tx_status_8023 - transmit status callback for 802.3 frame format
 *
 * Call this function for all transmitted data frames after their transmit
 * completion. This callback should only be called for data frames which
 * are using driver's (or hardware's) offload capability of encap/decap
 * 802.11 frames.
 *
 * This function may not be called in IRQ context. Calls to this function
 * for a single hardware must be synchronized against each other and all
 * calls in the same tx status family.
 *
 * @hw: the hardware the frame was transmitted by
 * @vif: the interface for which the frame was transmitted
 * @skb: the frame that was transmitted, owned by mac80211 after this call
 */
```

## 2990. original/linux-5.10.260/include/net/mac80211.h:4822

Líneas 4822–4830; tipo `block`.

```text
/**
 * ieee80211_report_low_ack - report non-responding station
 *
 * When operating in AP-mode, call this function to report a non-responding
 * connected STA.
 *
 * @sta: the non-responding connected sta
 * @num_packets: number of packets sent to @sta without a response
 */
```

## 2991. original/linux-5.10.260/include/net/mac80211.h:4835

Líneas 4835–4842; tipo `block`.

```text
/**
 * struct ieee80211_mutable_offsets - mutable beacon offsets
 * @tim_offset: position of TIM element
 * @tim_length: size of TIM element
 * @cntdwn_counter_offs: array of IEEE80211_MAX_CNTDWN_COUNTERS_NUM offsets
 *	to countdown counters.  This array can contain zero values which
 *	should be ignored.
 */
```

## 2992. original/linux-5.10.260/include/net/mac80211.h:4850

Líneas 4850–4868; tipo `block`.

```text
/**
 * ieee80211_beacon_get_template - beacon template generation function
 * @hw: pointer obtained from ieee80211_alloc_hw().
 * @vif: &struct ieee80211_vif pointer from the add_interface callback.
 * @offs: &struct ieee80211_mutable_offsets pointer to struct that will
 *	receive the offsets that may be updated by the driver.
 *
 * If the driver implements beaconing modes, it must use this function to
 * obtain the beacon template.
 *
 * This function should be used if the beacon frames are generated by the
 * device, and then the driver must use the returned beacon as the template
 * The driver or the device are responsible to update the DTIM and, when
 * applicable, the CSA count.
 *
 * The driver is responsible for freeing the returned skb.
 *
 * Return: The beacon template. %NULL on error.
 */
```

## 2993. original/linux-5.10.260/include/net/mac80211.h:4874

Líneas 4874–4895; tipo `block`.

```text
/**
 * ieee80211_beacon_get_tim - beacon generation function
 * @hw: pointer obtained from ieee80211_alloc_hw().
 * @vif: &struct ieee80211_vif pointer from the add_interface callback.
 * @tim_offset: pointer to variable that will receive the TIM IE offset.
 *	Set to 0 if invalid (in non-AP modes).
 * @tim_length: pointer to variable that will receive the TIM IE length,
 *	(including the ID and length bytes!).
 *	Set to 0 if invalid (in non-AP modes).
 *
 * If the driver implements beaconing modes, it must use this function to
 * obtain the beacon frame.
 *
 * If the beacon frames are generated by the host system (i.e., not in
 * hardware/firmware), the driver uses this function to get each beacon
 * frame from mac80211 -- it is responsible for calling this function exactly
 * once before the beacon is needed (e.g. based on hardware interrupt).
 *
 * The driver is responsible for freeing the returned skb.
 *
 * Return: The beacon template. %NULL on error.
 */
```

## 2994. original/linux-5.10.260/include/net/mac80211.h:4900

Líneas 4900–4908; tipo `block`.

```text
/**
 * ieee80211_beacon_get - beacon generation function
 * @hw: pointer obtained from ieee80211_alloc_hw().
 * @vif: &struct ieee80211_vif pointer from the add_interface callback.
 *
 * See ieee80211_beacon_get_tim().
 *
 * Return: See ieee80211_beacon_get_tim().
 */
```

## 2995. original/linux-5.10.260/include/net/mac80211.h:4915

Líneas 4915–4926; tipo `block`.

```text
/**
 * ieee80211_beacon_update_cntdwn - request mac80211 to decrement the beacon countdown
 * @vif: &struct ieee80211_vif pointer from the add_interface callback.
 *
 * The beacon counter should be updated after each beacon transmission.
 * This function is called implicitly when
 * ieee80211_beacon_get/ieee80211_beacon_get_tim are called, however if the
 * beacon frames are generated by the device, the driver should call this
 * function after each beacon transmission to sync mac80211's beacon countdown.
 *
 * Return: new countdown value
 */
```

## 2996. original/linux-5.10.260/include/net/mac80211.h:4929

Líneas 4929–4939; tipo `block`.

```text
/**
 * ieee80211_beacon_set_cntdwn - request mac80211 to set beacon countdown
 * @vif: &struct ieee80211_vif pointer from the add_interface callback.
 * @counter: the new value for the counter
 *
 * The beacon countdown can be changed by the device, this API should be
 * used by the device driver to update csa counter in mac80211.
 *
 * It should never be used together with ieee80211_beacon_update_cntdwn(),
 * as it will cause a race condition around the counter value.
 */
```

## 2997. original/linux-5.10.260/include/net/mac80211.h:4942

Líneas 4942–4949; tipo `block`.

```text
/**
 * ieee80211_csa_finish - notify mac80211 about channel switch
 * @vif: &struct ieee80211_vif pointer from the add_interface callback.
 *
 * After a channel switch announcement was scheduled and the counter in this
 * announcement hits 1, this function must be called by the driver to
 * notify mac80211 that the channel can be changed.
 */
```

## 2998. original/linux-5.10.260/include/net/mac80211.h:4952

Líneas 4952–4957; tipo `block`.

```text
/**
 * ieee80211_beacon_cntdwn_is_complete - find out if countdown reached 1
 * @vif: &struct ieee80211_vif pointer from the add_interface callback.
 *
 * This function returns whether the countdown reached zero.
 */
```

## 2999. original/linux-5.10.260/include/net/mac80211.h:4960

Líneas 4960–4971; tipo `block`.

```text
/**
 * ieee80211_proberesp_get - retrieve a Probe Response template
 * @hw: pointer obtained from ieee80211_alloc_hw().
 * @vif: &struct ieee80211_vif pointer from the add_interface callback.
 *
 * Creates a Probe Response template which can, for example, be uploaded to
 * hardware. The destination address should be set by the caller.
 *
 * Can only be called in AP mode.
 *
 * Return: The Probe Response template. %NULL on error.
 */
```

## 3000. original/linux-5.10.260/include/net/mac80211.h:4975

Líneas 4975–4988; tipo `block`.

```text
/**
 * ieee80211_pspoll_get - retrieve a PS Poll template
 * @hw: pointer obtained from ieee80211_alloc_hw().
 * @vif: &struct ieee80211_vif pointer from the add_interface callback.
 *
 * Creates a PS Poll a template which can, for example, uploaded to
 * hardware. The template must be updated after association so that correct
 * AID, BSSID and MAC address is used.
 *
 * Note: Caller (or hardware) is responsible for setting the
 * &IEEE80211_FCTL_PM bit.
 *
 * Return: The PS Poll template. %NULL on error.
 */
```

## 3001. original/linux-5.10.260/include/net/mac80211.h:4992

Líneas 4992–5010; tipo `block`.

```text
/**
 * ieee80211_nullfunc_get - retrieve a nullfunc template
 * @hw: pointer obtained from ieee80211_alloc_hw().
 * @vif: &struct ieee80211_vif pointer from the add_interface callback.
 * @qos_ok: QoS NDP is acceptable to the caller, this should be set
 *	if at all possible
 *
 * Creates a Nullfunc template which can, for example, uploaded to
 * hardware. The template must be updated after association so that correct
 * BSSID and address is used.
 *
 * If @qos_ndp is set and the association is to an AP with QoS/WMM, the
 * returned packet will be QoS NDP.
 *
 * Note: Caller (or hardware) is responsible for setting the
 * &IEEE80211_FCTL_PM bit as well as Duration and Sequence Control fields.
 *
 * Return: The nullfunc template. %NULL on error.
 */
```

## 3002. original/linux-5.10.260/include/net/mac80211.h:5015

Líneas 5015–5027; tipo `block`.

```text
/**
 * ieee80211_probereq_get - retrieve a Probe Request template
 * @hw: pointer obtained from ieee80211_alloc_hw().
 * @src_addr: source MAC address
 * @ssid: SSID buffer
 * @ssid_len: length of SSID
 * @tailroom: tailroom to reserve at end of SKB for IEs
 *
 * Creates a Probe Request template which can, for example, be uploaded to
 * hardware.
 *
 * Return: The Probe Request template. %NULL on error.
 */
```

## 3003. original/linux-5.10.260/include/net/mac80211.h:5033

Líneas 5033–5046; tipo `block`.

```text
/**
 * ieee80211_rts_get - RTS frame generation function
 * @hw: pointer obtained from ieee80211_alloc_hw().
 * @vif: &struct ieee80211_vif pointer from the add_interface callback.
 * @frame: pointer to the frame that is going to be protected by the RTS.
 * @frame_len: the frame length (in octets).
 * @frame_txctl: &struct ieee80211_tx_info of the frame.
 * @rts: The buffer where to store the RTS frame.
 *
 * If the RTS frames are generated by the host system (i.e., not in
 * hardware/firmware), the low-level driver uses this function to receive
 * the next RTS frame from the 802.11 code. The low-level is responsible
 * for calling this function before and RTS frame is needed.
 */
```

## 3004. original/linux-5.10.260/include/net/mac80211.h:5052

Líneas 5052–5064; tipo `block`.

```text
/**
 * ieee80211_rts_duration - Get the duration field for an RTS frame
 * @hw: pointer obtained from ieee80211_alloc_hw().
 * @vif: &struct ieee80211_vif pointer from the add_interface callback.
 * @frame_len: the length of the frame that is going to be protected by the RTS.
 * @frame_txctl: &struct ieee80211_tx_info of the frame.
 *
 * If the RTS is generated in firmware, but the host system must provide
 * the duration field, the low-level driver uses this function to receive
 * the duration field value in little-endian byteorder.
 *
 * Return: The duration.
 */
```

## 3005. original/linux-5.10.260/include/net/mac80211.h:5069

Líneas 5069–5082; tipo `block`.

```text
/**
 * ieee80211_ctstoself_get - CTS-to-self frame generation function
 * @hw: pointer obtained from ieee80211_alloc_hw().
 * @vif: &struct ieee80211_vif pointer from the add_interface callback.
 * @frame: pointer to the frame that is going to be protected by the CTS-to-self.
 * @frame_len: the frame length (in octets).
 * @frame_txctl: &struct ieee80211_tx_info of the frame.
 * @cts: The buffer where to store the CTS-to-self frame.
 *
 * If the CTS-to-self frames are generated by the host system (i.e., not in
 * hardware/firmware), the low-level driver uses this function to receive
 * the next CTS-to-self frame from the 802.11 code. The low-level is responsible
 * for calling this function before and CTS-to-self frame is needed.
 */
```

## 3006. original/linux-5.10.260/include/net/mac80211.h:5089

Líneas 5089–5101; tipo `block`.

```text
/**
 * ieee80211_ctstoself_duration - Get the duration field for a CTS-to-self frame
 * @hw: pointer obtained from ieee80211_alloc_hw().
 * @vif: &struct ieee80211_vif pointer from the add_interface callback.
 * @frame_len: the length of the frame that is going to be protected by the CTS-to-self.
 * @frame_txctl: &struct ieee80211_tx_info of the frame.
 *
 * If the CTS-to-self is generated in firmware, but the host system must provide
 * the duration field, the low-level driver uses this function to receive
 * the duration field value in little-endian byteorder.
 *
 * Return: The duration.
 */
```

## 3007. original/linux-5.10.260/include/net/mac80211.h:5107

Líneas 5107–5119; tipo `block`.

```text
/**
 * ieee80211_generic_frame_duration - Calculate the duration field for a frame
 * @hw: pointer obtained from ieee80211_alloc_hw().
 * @vif: &struct ieee80211_vif pointer from the add_interface callback.
 * @band: the band to calculate the frame duration on
 * @frame_len: the length of the frame.
 * @rate: the rate at which the frame is going to be transmitted.
 *
 * Calculate the duration field of some generic frame, given its
 * length and transmission rate (in 100kbps).
 *
 * Return: The duration.
 */
```

## 3008. original/linux-5.10.260/include/net/mac80211.h:5126

Líneas 5126–5146; tipo `block`.

```text
/**
 * ieee80211_get_buffered_bc - accessing buffered broadcast and multicast frames
 * @hw: pointer as obtained from ieee80211_alloc_hw().
 * @vif: &struct ieee80211_vif pointer from the add_interface callback.
 *
 * Function for accessing buffered broadcast and multicast frames. If
 * hardware/firmware does not implement buffering of broadcast/multicast
 * frames when power saving is used, 802.11 code buffers them in the host
 * memory. The low-level driver uses this function to fetch next buffered
 * frame. In most cases, this is used when generating beacon frame.
 *
 * Return: A pointer to the next buffered skb or NULL if no more buffered
 * frames are available.
 *
 * Note: buffered frames are returned only after DTIM beacon frame was
 * generated with ieee80211_beacon_get() and the low-level driver must thus
 * call ieee80211_beacon_get() first. ieee80211_get_buffered_bc() returns
 * NULL if the previous generated beacon was not DTIM, so the low-level driver
 * does not need to check for DTIM beacons separately and should be able to
 * use common code for all beacons.
 */
```

## 3009. original/linux-5.10.260/include/net/mac80211.h:5150

Líneas 5150–5158; tipo `block`.

```text
/**
 * ieee80211_get_tkip_p1k_iv - get a TKIP phase 1 key for IV32
 *
 * This function returns the TKIP phase 1 key for the given IV32.
 *
 * @keyconf: the parameter passed with the set key
 * @iv32: IV32 to get the P1K for
 * @p1k: a buffer to which the key will be written, as 5 u16 values
 */
```

## 3010. original/linux-5.10.260/include/net/mac80211.h:5162

Líneas 5162–5172; tipo `block`.

```text
/**
 * ieee80211_get_tkip_p1k - get a TKIP phase 1 key
 *
 * This function returns the TKIP phase 1 key for the IV32 taken
 * from the given packet.
 *
 * @keyconf: the parameter passed with the set key
 * @skb: the packet to take the IV32 value from that will be encrypted
 *	with this P1K
 * @p1k: a buffer to which the key will be written, as 5 u16 values
 */
```

## 3011. original/linux-5.10.260/include/net/mac80211.h:5183

Líneas 5183–5193; tipo `block`.

```text
/**
 * ieee80211_get_tkip_rx_p1k - get a TKIP phase 1 key for RX
 *
 * This function returns the TKIP phase 1 key for the given IV32
 * and transmitter address.
 *
 * @keyconf: the parameter passed with the set key
 * @ta: TA that will be used with the key
 * @iv32: IV32 to get the P1K for
 * @p1k: a buffer to which the key will be written, as 5 u16 values
 */
```

## 3012. original/linux-5.10.260/include/net/mac80211.h:5197

Líneas 5197–5207; tipo `block`.

```text
/**
 * ieee80211_get_tkip_p2k - get a TKIP phase 2 key
 *
 * This function computes the TKIP RC4 key for the IV values
 * in the packet.
 *
 * @keyconf: the parameter passed with the set key
 * @skb: the packet to take the IV32/IV16 values from that will be
 *	encrypted with this key
 * @p2k: a buffer to which the key will be written, 16 bytes
 */
```

## 3013. original/linux-5.10.260/include/net/mac80211.h:5211

Líneas 5211–5223; tipo `block`.

```text
/**
 * ieee80211_tkip_add_iv - write TKIP IV and Ext. IV to pos
 *
 * @pos: start of crypto header
 * @keyconf: the parameter passed with the set key
 * @pn: PN to add
 *
 * Returns: pointer to the octet following IVs (i.e. beginning of
 * the packet payload)
 *
 * This function writes the tkip IV value to pos (which should
 * point to the crypto header)
 */
```

## 3014. original/linux-5.10.260/include/net/mac80211.h:5226

Líneas 5226–5241; tipo `block`.

```text
/**
 * ieee80211_get_key_rx_seq - get key RX sequence counter
 *
 * @keyconf: the parameter passed with the set key
 * @tid: The TID, or -1 for the management frame value (CCMP/GCMP only);
 *	the value on TID 0 is also used for non-QoS frames. For
 *	CMAC, only TID 0 is valid.
 * @seq: buffer to receive the sequence data
 *
 * This function allows a driver to retrieve the current RX IV/PNs
 * for the given key. It must not be called if IV checking is done
 * by the device and not by mac80211.
 *
 * Note that this function may only be called when no RX processing
 * can be done concurrently.
 */
```

## 3015. original/linux-5.10.260/include/net/mac80211.h:5245

Líneas 5245–5261; tipo `block`.

```text
/**
 * ieee80211_set_key_rx_seq - set key RX sequence counter
 *
 * @keyconf: the parameter passed with the set key
 * @tid: The TID, or -1 for the management frame value (CCMP/GCMP only);
 *	the value on TID 0 is also used for non-QoS frames. For
 *	CMAC, only TID 0 is valid.
 * @seq: new sequence data
 *
 * This function allows a driver to set the current RX IV/PNs for the
 * given key. This is useful when resuming from WoWLAN sleep and GTK
 * rekey may have been done while suspended. It should not be called
 * if IV checking is done by the device and not by mac80211.
 *
 * Note that this function may only be called when no RX processing
 * can be done concurrently.
 */
```

## 3016. original/linux-5.10.260/include/net/mac80211.h:5265

Líneas 5265–5275; tipo `block`.

```text
/**
 * ieee80211_remove_key - remove the given key
 * @keyconf: the parameter passed with the set key
 *
 * Remove the given key. If the key was uploaded to the hardware at the
 * time this function is called, it is not deleted in the hardware but
 * instead assumed to have been removed already.
 *
 * Note that due to locking considerations this function can (currently)
 * only be called during key iteration (ieee80211_iter_keys().)
 */
```

## 3017. original/linux-5.10.260/include/net/mac80211.h:5278

Líneas 5278–5306; tipo `block`.

```text
/**
 * ieee80211_gtk_rekey_add - add a GTK key from rekeying during WoWLAN
 * @vif: the virtual interface to add the key on
 * @keyconf: new key data
 *
 * When GTK rekeying was done while the system was suspended, (a) new
 * key(s) will be available. These will be needed by mac80211 for proper
 * RX processing, so this function allows setting them.
 *
 * The function returns the newly allocated key structure, which will
 * have similar contents to the passed key configuration but point to
 * mac80211-owned memory. In case of errors, the function returns an
 * ERR_PTR(), use IS_ERR() etc.
 *
 * Note that this function assumes the key isn't added to hardware
 * acceleration, so no TX will be done with the key. Since it's a GTK
 * on managed (station) networks, this is true anyway. If the driver
 * calls this function from the resume callback and subsequently uses
 * the return code 1 to reconfigure the device, this key will be part
 * of the reconfiguration.
 *
 * Note that the driver should also call ieee80211_set_key_rx_seq()
 * for the new key for each TID to set up sequence counters properly.
 *
 * IMPORTANT: If this replaces a key that is present in the hardware,
 * then it will attempt to remove it during this call. In many cases
 * this isn't what you want, so call ieee80211_remove_key() first for
 * the key that's being replaced.
 */
```

## 3018. original/linux-5.10.260/include/net/mac80211.h:5311

Líneas 5311–5317; tipo `block`.

```text
/**
 * ieee80211_gtk_rekey_notify - notify userspace supplicant of rekeying
 * @vif: virtual interface the rekeying was done on
 * @bssid: The BSSID of the AP, for checking association
 * @replay_ctr: the new replay counter after GTK rekeying
 * @gfp: allocation flags
 */
```

## 3019. original/linux-5.10.260/include/net/mac80211.h:5321

Líneas 5321–5327; tipo `block`.

```text
/**
 * ieee80211_wake_queue - wake specific queue
 * @hw: pointer as obtained from ieee80211_alloc_hw().
 * @queue: queue number (counted from zero).
 *
 * Drivers should use this function instead of netif_wake_queue.
 */
```

## 3020. original/linux-5.10.260/include/net/mac80211.h:5330

Líneas 5330–5336; tipo `block`.

```text
/**
 * ieee80211_stop_queue - stop specific queue
 * @hw: pointer as obtained from ieee80211_alloc_hw().
 * @queue: queue number (counted from zero).
 *
 * Drivers should use this function instead of netif_stop_queue.
 */
```

## 3021. original/linux-5.10.260/include/net/mac80211.h:5339

Líneas 5339–5347; tipo `block`.

```text
/**
 * ieee80211_queue_stopped - test status of the queue
 * @hw: pointer as obtained from ieee80211_alloc_hw().
 * @queue: queue number (counted from zero).
 *
 * Drivers should use this function instead of netif_stop_queue.
 *
 * Return: %true if the queue is stopped. %false otherwise.
 */
```

## 3022. original/linux-5.10.260/include/net/mac80211.h:5351

Líneas 5351–5356; tipo `block`.

```text
/**
 * ieee80211_stop_queues - stop all queues
 * @hw: pointer as obtained from ieee80211_alloc_hw().
 *
 * Drivers should use this function instead of netif_stop_queue.
 */
```

## 3023. original/linux-5.10.260/include/net/mac80211.h:5359

Líneas 5359–5364; tipo `block`.

```text
/**
 * ieee80211_wake_queues - wake all queues
 * @hw: pointer as obtained from ieee80211_alloc_hw().
 *
 * Drivers should use this function instead of netif_wake_queue.
 */
```

## 3024. original/linux-5.10.260/include/net/mac80211.h:5367

Líneas 5367–5377; tipo `block`.

```text
/**
 * ieee80211_scan_completed - completed hardware scan
 *
 * When hardware scan offload is used (i.e. the hw_scan() callback is
 * assigned) this function needs to be called by the driver to notify
 * mac80211 that the scan finished. This function can be called from
 * any context, including hardirq context.
 *
 * @hw: the hardware that finished the scan
 * @info: information about the completed scan
 */
```

## 3025. original/linux-5.10.260/include/net/mac80211.h:5381

Líneas 5381–5388; tipo `block`.

```text
/**
 * ieee80211_sched_scan_results - got results from scheduled scan
 *
 * When a scheduled scan is running, this function needs to be called by the
 * driver whenever there are new scan results available.
 *
 * @hw: the hardware that is performing scheduled scans
 */
```

## 3026. original/linux-5.10.260/include/net/mac80211.h:5391

Líneas 5391–5400; tipo `block`.

```text
/**
 * ieee80211_sched_scan_stopped - inform that the scheduled scan has stopped
 *
 * When a scheduled scan is running, this function can be called by
 * the driver if it needs to stop the scan to perform another task.
 * Usual scenarios are drivers that cannot continue the scheduled scan
 * while associating, for instance.
 *
 * @hw: the hardware that is performing scheduled scans
 */
```

## 3027. original/linux-5.10.260/include/net/mac80211.h:5403

Líneas 5403–5416; tipo `block`.

```text
/**
 * enum ieee80211_interface_iteration_flags - interface iteration flags
 * @IEEE80211_IFACE_ITER_NORMAL: Iterate over all interfaces that have
 *	been added to the driver; However, note that during hardware
 *	reconfiguration (after restart_hw) it will iterate over a new
 *	interface and over all the existing interfaces even if they
 *	haven't been re-added to the driver yet.
 * @IEEE80211_IFACE_ITER_RESUME_ALL: During resume, iterate over all
 *	interfaces, even if they haven't been re-added to the driver yet.
 * @IEEE80211_IFACE_ITER_ACTIVE: Iterate only active interfaces (netdev is up).
 * @IEEE80211_IFACE_SKIP_SDATA_NOT_IN_DRIVER: Skip any interfaces where SDATA
 *	is not in the driver.  This may fix crashes during firmware recovery
 *	for instance.
 */
```

## 3028. original/linux-5.10.260/include/net/mac80211.h:5424

Líneas 5424–5436; tipo `block`.

```text
/**
 * ieee80211_iterate_interfaces - iterate interfaces
 *
 * This function iterates over the interfaces associated with a given
 * hardware and calls the callback for them. This includes active as well as
 * inactive interfaces. This function allows the iterator function to sleep.
 * Will iterate over a new interface during add_interface().
 *
 * @hw: the hardware struct of which the interfaces should be iterated over
 * @iter_flags: iteration flags, see &enum ieee80211_interface_iteration_flags
 * @iterator: the iterator function to call
 * @data: first argument of the iterator function
 */
```

## 3029. original/linux-5.10.260/include/net/mac80211.h:5442

Líneas 5442–5456; tipo `block`.

```text
/**
 * ieee80211_iterate_active_interfaces - iterate active interfaces
 *
 * This function iterates over the interfaces associated with a given
 * hardware that are currently active and calls the callback for them.
 * This function allows the iterator function to sleep, when the iterator
 * function is atomic @ieee80211_iterate_active_interfaces_atomic can
 * be used.
 * Does not iterate over a new interface during add_interface().
 *
 * @hw: the hardware struct of which the interfaces should be iterated over
 * @iter_flags: iteration flags, see &enum ieee80211_interface_iteration_flags
 * @iterator: the iterator function to call
 * @data: first argument of the iterator function
 */
```

## 3030. original/linux-5.10.260/include/net/mac80211.h:5468

Líneas 5468–5481; tipo `block`.

```text
/**
 * ieee80211_iterate_active_interfaces_atomic - iterate active interfaces
 *
 * This function iterates over the interfaces associated with a given
 * hardware that are currently active and calls the callback for them.
 * This function requires the iterator callback function to be atomic,
 * if that is not desired, use @ieee80211_iterate_active_interfaces instead.
 * Does not iterate over a new interface during add_interface().
 *
 * @hw: the hardware struct of which the interfaces should be iterated over
 * @iter_flags: iteration flags, see &enum ieee80211_interface_iteration_flags
 * @iterator: the iterator function to call, cannot sleep
 * @data: first argument of the iterator function
 */
```

## 3031. original/linux-5.10.260/include/net/mac80211.h:5489

Líneas 5489–5500; tipo `block`.

```text
/**
 * ieee80211_iterate_active_interfaces_rtnl - iterate active interfaces
 *
 * This function iterates over the interfaces associated with a given
 * hardware that are currently active and calls the callback for them.
 * This version can only be used while holding the RTNL.
 *
 * @hw: the hardware struct of which the interfaces should be iterated over
 * @iter_flags: iteration flags, see &enum ieee80211_interface_iteration_flags
 * @iterator: the iterator function to call, cannot sleep
 * @data: first argument of the iterator function
 */
```

## 3032. original/linux-5.10.260/include/net/mac80211.h:5508

Líneas 5508–5519; tipo `block`.

```text
/**
 * ieee80211_iterate_stations_atomic - iterate stations
 *
 * This function iterates over all stations associated with a given
 * hardware that are currently uploaded to the driver and calls the callback
 * function for them.
 * This function requires the iterator callback function to be atomic,
 *
 * @hw: the hardware struct of which the interfaces should be iterated over
 * @iterator: the iterator function to call, cannot sleep
 * @data: first argument of the iterator function
 */
```

## 3033. original/linux-5.10.260/include/net/mac80211.h:5524

Líneas 5524–5532; tipo `block`.

```text
/**
 * ieee80211_queue_work - add work onto the mac80211 workqueue
 *
 * Drivers and mac80211 use this to add work onto the mac80211 workqueue.
 * This helper ensures drivers are not queueing work when they should not be.
 *
 * @hw: the hardware struct for the interface we are adding work for
 * @work: the work we want to add onto the mac80211 workqueue
 */
```

## 3034. original/linux-5.10.260/include/net/mac80211.h:5535

Líneas 5535–5544; tipo `block`.

```text
/**
 * ieee80211_queue_delayed_work - add work onto the mac80211 workqueue
 *
 * Drivers and mac80211 use this to queue delayed work onto the mac80211
 * workqueue.
 *
 * @hw: the hardware struct for the interface we are adding work for
 * @dwork: delayable work to queue onto the mac80211 workqueue
 * @delay: number of jiffies to wait before queueing
 */
```

## 3035. original/linux-5.10.260/include/net/mac80211.h:5549

Líneas 5549–5560; tipo `block`.

```text
/**
 * ieee80211_start_tx_ba_session - Start a tx Block Ack session.
 * @sta: the station for which to start a BA session
 * @tid: the TID to BA on.
 * @timeout: session timeout value (in TUs)
 *
 * Return: success if addBA request was sent, failure otherwise
 *
 * Although mac80211/low level driver/user space application can estimate
 * the need to start aggregation on a certain RA/TID, the session level
 * will be managed by the mac80211.
 */
```

## 3036. original/linux-5.10.260/include/net/mac80211.h:5564

Líneas 5564–5573; tipo `block`.

```text
/**
 * ieee80211_start_tx_ba_cb_irqsafe - low level driver ready to aggregate.
 * @vif: &struct ieee80211_vif pointer from the add_interface callback
 * @ra: receiver address of the BA session recipient.
 * @tid: the TID to BA on.
 *
 * This function must be called by low level driver once it has
 * finished with preparations for the BA session. It can be called
 * from any context.
 */
```

## 3037. original/linux-5.10.260/include/net/mac80211.h:5577

Líneas 5577–5587; tipo `block`.

```text
/**
 * ieee80211_stop_tx_ba_session - Stop a Block Ack session.
 * @sta: the station whose BA session to stop
 * @tid: the TID to stop BA.
 *
 * Return: negative error if the TID is invalid, or no aggregation active
 *
 * Although mac80211/low level driver/user space application can estimate
 * the need to stop aggregation on a certain RA/TID, the session level
 * will be managed by the mac80211.
 */
```

## 3038. original/linux-5.10.260/include/net/mac80211.h:5590

Líneas 5590–5599; tipo `block`.

```text
/**
 * ieee80211_stop_tx_ba_cb_irqsafe - low level driver ready to stop aggregate.
 * @vif: &struct ieee80211_vif pointer from the add_interface callback
 * @ra: receiver address of the BA session recipient.
 * @tid: the desired TID to BA on.
 *
 * This function must be called by low level driver once it has
 * finished with preparations for the BA session tear down. It
 * can be called from any context.
 */
```

## 3039. original/linux-5.10.260/include/net/mac80211.h:5603

Líneas 5603–5613; tipo `block`.

```text
/**
 * ieee80211_find_sta - find a station
 *
 * @vif: virtual interface to look for station on
 * @addr: station's address
 *
 * Return: The station, if found. %NULL otherwise.
 *
 * Note: This function must be called under RCU lock and the
 * resulting pointer is only valid under RCU lock as well.
 */
```

## 3040. original/linux-5.10.260/include/net/mac80211.h:5617

Líneas 5617–5638; tipo `block`.

```text
/**
 * ieee80211_find_sta_by_ifaddr - find a station on hardware
 *
 * @hw: pointer as obtained from ieee80211_alloc_hw()
 * @addr: remote station's address
 * @localaddr: local address (vif->sdata->vif.addr). Use NULL for 'any'.
 *
 * Return: The station, if found. %NULL otherwise.
 *
 * Note: This function must be called under RCU lock and the
 * resulting pointer is only valid under RCU lock as well.
 *
 * NOTE: You may pass NULL for localaddr, but then you will just get
 *      the first STA that matches the remote address 'addr'.
 *      We can have multiple STA associated with multiple
 *      logical stations (e.g. consider a station connecting to another
 *      BSSID on the same AP hardware without disconnecting first).
 *      In this case, the result of this method with localaddr NULL
 *      is not reliable.
 *
 * DO NOT USE THIS FUNCTION with localaddr NULL if at all possible.
 */
```

## 3041. original/linux-5.10.260/include/net/mac80211.h:5643

Líneas 5643–5671; tipo `block`.

```text
/**
 * ieee80211_sta_block_awake - block station from waking up
 * @hw: the hardware
 * @pubsta: the station
 * @block: whether to block or unblock
 *
 * Some devices require that all frames that are on the queues
 * for a specific station that went to sleep are flushed before
 * a poll response or frames after the station woke up can be
 * delivered to that it. Note that such frames must be rejected
 * by the driver as filtered, with the appropriate status flag.
 *
 * This function allows implementing this mode in a race-free
 * manner.
 *
 * To do this, a driver must keep track of the number of frames
 * still enqueued for a specific station. If this number is not
 * zero when the station goes to sleep, the driver must call
 * this function to force mac80211 to consider the station to
 * be asleep regardless of the station's actual state. Once the
 * number of outstanding frames reaches zero, the driver must
 * call this function again to unblock the station. That will
 * cause mac80211 to be able to send ps-poll responses, and if
 * the station queried in the meantime then frames will also
 * be sent out as a result of this. Additionally, the driver
 * will be notified that the station woke up some time after
 * it is unblocked, regardless of whether the station actually
 * woke up while blocked or not.
 */
```

## 3042. original/linux-5.10.260/include/net/mac80211.h:5675

Líneas 5675–5693; tipo `block`.

```text
/**
 * ieee80211_sta_eosp - notify mac80211 about end of SP
 * @pubsta: the station
 *
 * When a device transmits frames in a way that it can't tell
 * mac80211 in the TX status about the EOSP, it must clear the
 * %IEEE80211_TX_STATUS_EOSP bit and call this function instead.
 * This applies for PS-Poll as well as uAPSD.
 *
 * Note that just like with _tx_status() and _rx() drivers must
 * not mix calls to irqsafe/non-irqsafe versions, this function
 * must not be mixed with those either. Use the all irqsafe, or
 * all non-irqsafe, don't mix!
 *
 * NB: the _irqsafe version of this function doesn't exist, no
 *     driver needs it right now. Don't call this function if
 *     you'd need the _irqsafe version, look at the git history
 *     and restore the _irqsafe version!
 */
```

## 3043. original/linux-5.10.260/include/net/mac80211.h:5696

Líneas 5696–5715; tipo `block`.

```text
/**
 * ieee80211_send_eosp_nullfunc - ask mac80211 to send NDP with EOSP
 * @pubsta: the station
 * @tid: the tid of the NDP
 *
 * Sometimes the device understands that it needs to close
 * the Service Period unexpectedly. This can happen when
 * sending frames that are filling holes in the BA window.
 * In this case, the device can ask mac80211 to send a
 * Nullfunc frame with EOSP set. When that happens, the
 * driver must have called ieee80211_sta_set_buffered() to
 * let mac80211 know that there are no buffered frames any
 * more, otherwise mac80211 will get the more_data bit wrong.
 * The low level driver must have made sure that the frame
 * will be sent despite the station being in power-save.
 * Mac80211 won't call allow_buffered_frames().
 * Note that calling this function, doesn't exempt the driver
 * from closing the EOSP properly, it will still have to call
 * ieee80211_sta_eosp when the NDP is sent.
 */
```

## 3044. original/linux-5.10.260/include/net/mac80211.h:5718

Líneas 5718–5742; tipo `block`.

```text
/**
 * ieee80211_sta_register_airtime - register airtime usage for a sta/tid
 *
 * Register airtime usage for a given sta on a given tid. The driver must call
 * this function to notify mac80211 that a station used a certain amount of
 * airtime. This information will be used by the TXQ scheduler to schedule
 * stations in a way that ensures airtime fairness.
 *
 * The reported airtime should as a minimum include all time that is spent
 * transmitting to the remote station, including overhead and padding, but not
 * including time spent waiting for a TXOP. If the time is not reported by the
 * hardware it can in some cases be calculated from the rate and known frame
 * composition. When possible, the time should include any failed transmission
 * attempts.
 *
 * The driver can either call this function synchronously for every packet or
 * aggregate, or asynchronously as airtime usage information becomes available.
 * TX and RX airtime can be reported together, or separately by setting one of
 * them to 0.
 *
 * @pubsta: the station
 * @tid: the TID to register airtime for
 * @tx_airtime: airtime used during TX (in usec)
 * @rx_airtime: airtime used during RX (in usec)
 */
```

## 3045. original/linux-5.10.260/include/net/mac80211.h:5746

Líneas 5746–5754; tipo `block`.

```text
/**
 * ieee80211_txq_airtime_check - check if a txq can send frame to device
 *
 * @hw: pointer obtained from ieee80211_alloc_hw()
 * @txq: pointer obtained from station or virtual interface
 *
 * Return true if the AQL's airtime limit has not been reached and the txq can
 * continue to send more packets to the device. Otherwise return false.
 */
```

## 3046. original/linux-5.10.260/include/net/mac80211.h:5758

Líneas 5758–5775; tipo `block`.

```text
/**
 * ieee80211_iter_keys - iterate keys programmed into the device
 * @hw: pointer obtained from ieee80211_alloc_hw()
 * @vif: virtual interface to iterate, may be %NULL for all
 * @iter: iterator function that will be called for each key
 * @iter_data: custom data to pass to the iterator function
 *
 * This function can be used to iterate all the keys known to
 * mac80211, even those that weren't previously programmed into
 * the device. This is intended for use in WoWLAN if the device
 * needs reprogramming of the keys during suspend. Note that due
 * to locking reasons, it is also only safe to call this at few
 * spots since it must hold the RTNL and be able to sleep.
 *
 * The order in which the keys are iterated matches the order
 * in which they were originally installed and handed to the
 * set_key callback.
 */
```

## 3047. original/linux-5.10.260/include/net/mac80211.h:5785

Líneas 5785–5799; tipo `block`.

```text
/**
 * ieee80211_iter_keys_rcu - iterate keys programmed into the device
 * @hw: pointer obtained from ieee80211_alloc_hw()
 * @vif: virtual interface to iterate, may be %NULL for all
 * @iter: iterator function that will be called for each key
 * @iter_data: custom data to pass to the iterator function
 *
 * This function can be used to iterate all the keys known to
 * mac80211, even those that weren't previously programmed into
 * the device. Note that due to locking reasons, keys of station
 * in removal process will be skipped.
 *
 * This function requires being called in an RCU critical section,
 * and thus iter must be atomic.
 */
```

## 3048. original/linux-5.10.260/include/net/mac80211.h:5809

Líneas 5809–5827; tipo `block`.

```text
/**
 * ieee80211_iter_chan_contexts_atomic - iterate channel contexts
 * @hw: pointer obtained from ieee80211_alloc_hw().
 * @iter: iterator function
 * @iter_data: data passed to iterator function
 *
 * Iterate all active channel contexts. This function is atomic and
 * doesn't acquire any locks internally that might be held in other
 * places while calling into the driver.
 *
 * The iterator will not find a context that's being added (during
 * the driver callback to add it) but will find it while it's being
 * removed.
 *
 * Note that during hardware restart, all contexts that existed
 * before the restart are considered already present so will be
 * found while iterating, whether they've been re-added already
 * or not.
 */
```

## 3049. original/linux-5.10.260/include/net/mac80211.h:5835

Líneas 5835–5848; tipo `block`.

```text
/**
 * ieee80211_ap_probereq_get - retrieve a Probe Request template
 * @hw: pointer obtained from ieee80211_alloc_hw().
 * @vif: &struct ieee80211_vif pointer from the add_interface callback.
 *
 * Creates a Probe Request template which can, for example, be uploaded to
 * hardware. The template is filled with bssid, ssid and supported rate
 * information. This function must only be called from within the
 * .bss_info_changed callback function and only in managed mode. The function
 * is only useful when the interface is associated, otherwise it will return
 * %NULL.
 *
 * Return: The Probe Request template. %NULL on error.
 */
```

## 3050. original/linux-5.10.260/include/net/mac80211.h:5852

Líneas 5852–5860; tipo `block`.

```text
/**
 * ieee80211_beacon_loss - inform hardware does not receive beacons
 *
 * @vif: &struct ieee80211_vif pointer from the add_interface callback.
 *
 * When beacon filtering is enabled with %IEEE80211_VIF_BEACON_FILTER and
 * %IEEE80211_CONF_PS is set, the driver needs to inform whenever the
 * hardware is not receiving beacons with this function.
 */
```

## 3051. original/linux-5.10.260/include/net/mac80211.h:5863

Líneas 5863–5876; tipo `block`.

```text
/**
 * ieee80211_connection_loss - inform hardware has lost connection to the AP
 *
 * @vif: &struct ieee80211_vif pointer from the add_interface callback.
 *
 * When beacon filtering is enabled with %IEEE80211_VIF_BEACON_FILTER, and
 * %IEEE80211_CONF_PS and %IEEE80211_HW_CONNECTION_MONITOR are set, the driver
 * needs to inform if the connection to the AP has been lost.
 * The function may also be called if the connection needs to be terminated
 * for some other reason, even if %IEEE80211_HW_CONNECTION_MONITOR isn't set.
 *
 * This function will cause immediate change to disassociated state,
 * without connection recovery attempts.
 */
```

## 3052. original/linux-5.10.260/include/net/mac80211.h:5879

Líneas 5879–5899; tipo `block`.

```text
/**
 * ieee80211_resume_disconnect - disconnect from AP after resume
 *
 * @vif: &struct ieee80211_vif pointer from the add_interface callback.
 *
 * Instructs mac80211 to disconnect from the AP after resume.
 * Drivers can use this after WoWLAN if they know that the
 * connection cannot be kept up, for example because keys were
 * used while the device was asleep but the replay counters or
 * similar cannot be retrieved from the device during resume.
 *
 * Note that due to implementation issues, if the driver uses
 * the reconfiguration functionality during resume the interface
 * will still be added as associated first during resume and then
 * disconnect normally later.
 *
 * This function can only be called from the resume callback and
 * the driver must not be holding any of its own locks while it
 * calls this function, or at least not any locks it needs in the
 * key configuration paths (if it supports HW crypto).
 */
```

## 3053. original/linux-5.10.260/include/net/mac80211.h:5902

Líneas 5902–5909; tipo `block`.

```text
/**
 * ieee80211_hw_restart_disconnect - disconnect from AP after
 * hardware restart
 * @vif: &struct ieee80211_vif pointer from the add_interface callback.
 *
 * Instructs mac80211 to disconnect from the AP after
 * hardware restart.
 */
```

## 3054. original/linux-5.10.260/include/net/mac80211.h:5912

Líneas 5912–5924; tipo `block`.

```text
/**
 * ieee80211_cqm_rssi_notify - inform a configured connection quality monitoring
 *	rssi threshold triggered
 *
 * @vif: &struct ieee80211_vif pointer from the add_interface callback.
 * @rssi_event: the RSSI trigger event type
 * @rssi_level: new RSSI level value or 0 if not available
 * @gfp: context flags
 *
 * When the %IEEE80211_VIF_SUPPORTS_CQM_RSSI is set, and a connection quality
 * monitoring is configured with an rssi threshold, the driver will inform
 * whenever the rssi level reaches the threshold.
 */
```

## 3055. original/linux-5.10.260/include/net/mac80211.h:5930

Líneas 5930–5935; tipo `block`.

```text
/**
 * ieee80211_cqm_beacon_loss_notify - inform CQM of beacon loss
 *
 * @vif: &struct ieee80211_vif pointer from the add_interface callback.
 * @gfp: context flags
 */
```

## 3056. original/linux-5.10.260/include/net/mac80211.h:5938

Líneas 5938–5942; tipo `block`.

```text
/**
 * ieee80211_radar_detected - inform that a radar was detected
 *
 * @hw: pointer as obtained from ieee80211_alloc_hw()
 */
```

## 3057. original/linux-5.10.260/include/net/mac80211.h:5945

Líneas 5945–5952; tipo `block`.

```text
/**
 * ieee80211_chswitch_done - Complete channel switch process
 * @vif: &struct ieee80211_vif pointer from the add_interface callback.
 * @success: make the channel switch successful or not
 *
 * Complete the channel switch post-process: set the new operational channel
 * and wake up the suspended queues.
 */
```

## 3058. original/linux-5.10.260/include/net/mac80211.h:5955

Líneas 5955–5963; tipo `block`.

```text
/**
 * ieee80211_request_smps - request SM PS transition
 * @vif: &struct ieee80211_vif pointer from the add_interface callback.
 * @smps_mode: new SM PS mode
 *
 * This allows the driver to request an SM PS transition in managed
 * mode. This is useful when the driver has more information than
 * the stack about possible interference, for example by bluetooth.
 */
```

## 3059. original/linux-5.10.260/include/net/mac80211.h:5967

Líneas 5967–5970; tipo `block`.

```text
/**
 * ieee80211_ready_on_channel - notification of remain-on-channel start
 * @hw: pointer as obtained from ieee80211_alloc_hw()
 */
```

## 3060. original/linux-5.10.260/include/net/mac80211.h:5973

Líneas 5973–5976; tipo `block`.

```text
/**
 * ieee80211_remain_on_channel_expired - remain_on_channel duration expired
 * @hw: pointer as obtained from ieee80211_alloc_hw()
 */
```

## 3061. original/linux-5.10.260/include/net/mac80211.h:5979

Líneas 5979–5992; tipo `block`.

```text
/**
 * ieee80211_stop_rx_ba_session - callback to stop existing BA sessions
 *
 * in order not to harm the system performance and user experience, the device
 * may request not to allow any rx ba session and tear down existing rx ba
 * sessions based on system constraints such as periodic BT activity that needs
 * to limit wlan activity (eg.sco or a2dp)."
 * in such cases, the intention is to limit the duration of the rx ppdu and
 * therefore prevent the peer device to use a-mpdu aggregation.
 *
 * @vif: &struct ieee80211_vif pointer from the add_interface callback.
 * @ba_rx_bitmap: Bit map of open rx ba per tid
 * @addr: & to bssid mac address
 */
```

## 3062. original/linux-5.10.260/include/net/mac80211.h:5996

Líneas 5996–6009; tipo `block`.

```text
/**
 * ieee80211_mark_rx_ba_filtered_frames - move RX BA window and mark filtered
 * @pubsta: station struct
 * @tid: the session's TID
 * @ssn: starting sequence number of the bitmap, all frames before this are
 *	assumed to be out of the window after the call
 * @filtered: bitmap of filtered frames, BIT(0) is the @ssn entry etc.
 * @received_mpdus: number of received mpdus in firmware
 *
 * This function moves the BA window and releases all frames before @ssn, and
 * marks frames marked in the bitmap as having been filtered. Afterwards, it
 * checks if any frames in the window starting from @ssn can now be released
 * (in case they were only waiting for frames that were filtered.)
 */
```

## 3063. original/linux-5.10.260/include/net/mac80211.h:6014

Líneas 6014–6024; tipo `block`.

```text
/**
 * ieee80211_send_bar - send a BlockAckReq frame
 *
 * can be used to flush pending frames from the peer's aggregation reorder
 * buffer.
 *
 * @vif: &struct ieee80211_vif pointer from the add_interface callback.
 * @ra: the peer's destination address
 * @tid: the TID of the aggregation session
 * @ssn: the new starting sequence number for the receiver
 */
```

## 3064. original/linux-5.10.260/include/net/mac80211.h:6027

Líneas 6027–6032; tipo `block`.

```text
/**
 * ieee80211_manage_rx_ba_offl - helper to queue an RX BA work
 * @vif: &struct ieee80211_vif pointer from the add_interface callback
 * @addr: station mac address
 * @tid: the rx tid
 */
```

## 3065. original/linux-5.10.260/include/net/mac80211.h:6036

Líneas 6036–6049; tipo `block`.

```text
/**
 * ieee80211_start_rx_ba_session_offl - start a Rx BA session
 *
 * Some device drivers may offload part of the Rx aggregation flow including
 * AddBa/DelBa negotiation but may otherwise be incapable of full Rx
 * reordering.
 *
 * Create structures responsible for reordering so device drivers may call here
 * when they complete AddBa negotiation.
 *
 * @vif: &struct ieee80211_vif pointer from the add_interface callback
 * @addr: station mac address
 * @tid: the rx tid
 */
```

## 3066. original/linux-5.10.260/include/net/mac80211.h:6058

Líneas 6058–6071; tipo `block`.

```text
/**
 * ieee80211_stop_rx_ba_session_offl - stop a Rx BA session
 *
 * Some device drivers may offload part of the Rx aggregation flow including
 * AddBa/DelBa negotiation but may otherwise be incapable of full Rx
 * reordering.
 *
 * Destroy structures responsible for reordering so device drivers may call here
 * when they complete DelBa negotiation.
 *
 * @vif: &struct ieee80211_vif pointer from the add_interface callback
 * @addr: station mac address
 * @tid: the rx tid
 */
```

## 3067. original/linux-5.10.260/include/net/mac80211.h:6080

Líneas 6080–6091; tipo `block`.

```text
/**
 * ieee80211_rx_ba_timer_expired - stop a Rx BA session due to timeout
 *
 * Some device drivers do not offload AddBa/DelBa negotiation, but handle rx
 * buffer reording internally, and therefore also handle the session timer.
 *
 * Trigger the timeout flow, which sends a DelBa.
 *
 * @vif: &struct ieee80211_vif pointer from the add_interface callback
 * @addr: station mac address
 * @tid: the rx tid
 */
```

## 3068. original/linux-5.10.260/include/net/mac80211.h:6095

Líneas 6095–6095; tipo `block`.

```text
/* Rate control API */
```

## 3069. original/linux-5.10.260/include/net/mac80211.h:6097

Líneas 6097–6115; tipo `block`.

```text
/**
 * struct ieee80211_tx_rate_control - rate control information for/from RC algo
 *
 * @hw: The hardware the algorithm is invoked for.
 * @sband: The band this frame is being transmitted on.
 * @bss_conf: the current BSS configuration
 * @skb: the skb that will be transmitted, the control information in it needs
 *	to be filled in
 * @reported_rate: The rate control algorithm can fill this in to indicate
 *	which rate should be reported to userspace as the current rate and
 *	used for rate calculations in the mesh network.
 * @rts: whether RTS will be used for this frame because it is longer than the
 *	RTS threshold
 * @short_preamble: whether mac80211 will request short-preamble transmission
 *	if the selected rate supports it
 * @rate_idx_mask: user-requested (legacy) rate mask
 * @rate_idx_mcs_mask: user-requested MCS rate mask (NULL if not in use)
 * @bss: whether this frame is sent out in AP or IBSS mode
 */
```

## 3070. original/linux-5.10.260/include/net/mac80211.h:6128

Líneas 6128–6130; tipo `block`.

```text
/**
 * enum rate_control_capabilities - rate control capabilities
 */
```

## 3071. original/linux-5.10.260/include/net/mac80211.h:6132

Líneas 6132–6138; tipo `block`.

```text
/**
	 * @RATE_CTRL_CAPA_VHT_EXT_NSS_BW:
	 * Support for extended NSS BW support (dot11VHTExtendedNSSCapable)
	 * Note that this is only looked at if the minimum number of chains
	 * that the AP uses is < the number of TX chains the hardware has,
	 * otherwise the NSS difference doesn't bother us.
	 */
```

## 3072. original/linux-5.10.260/include/net/mac80211.h:6193

Líneas 6193–6193; tipo `block`.

```text
/* warn when we cannot find a rate. */
```

## 3073. original/linux-5.10.260/include/net/mac80211.h:6196

Líneas 6196–6196; tipo `block`.

```text
/* and return 0 (the lowest index) */
```

## 3074. original/linux-5.10.260/include/net/mac80211.h:6212

Líneas 6212–6223; tipo `block`.

```text
/**
 * rate_control_set_rates - pass the sta rate selection to mac80211/driver
 *
 * When not doing a rate control probe to test rates, rate control should pass
 * its rate selection to mac80211. If the driver supports receiving a station
 * rate table, it will use it to ensure that frames are always sent based on
 * the most recent rate control module decision.
 *
 * @hw: pointer as obtained from ieee80211_alloc_hw()
 * @pubsta: &struct ieee80211_sta pointer to the target destination.
 * @rates: new tx rate set to be used for this station.
 */
```

## 3075. original/linux-5.10.260/include/net/mac80211.h:6287

Líneas 6287–6298; tipo `block`.

```text
/**
 * ieee80211_update_mu_groups - set the VHT MU-MIMO groud data
 *
 * @vif: the specified virtual interface
 * @membership: 64 bits array - a bit is set if station is member of the group
 * @position: 2 bits per group id indicating the position in the group
 *
 * Note: This function assumes that the given vif is valid and the position and
 * membership data is of the correct size and are in the same byte order as the
 * matching GroupId management frame.
 * Calls to this function need to be serialized with RX path.
 */
```

## 3076. original/linux-5.10.260/include/net/mac80211.h:6308

Líneas 6308–6317; tipo `block`.

```text
/**
 * ieee80211_ave_rssi - report the average RSSI for the specified interface
 *
 * @vif: the specified virtual interface
 *
 * Note: This function assumes that the given vif is valid.
 *
 * Return: The average RSSI value for the requested interface, or 0 if not
 * applicable.
 */
```

## 3077. original/linux-5.10.260/include/net/mac80211.h:6320

Líneas 6320–6327; tipo `block`.

```text
/**
 * ieee80211_report_wowlan_wakeup - report WoWLAN wakeup
 * @vif: virtual interface
 * @wakeup: wakeup reason(s)
 * @gfp: allocation flags
 *
 * See cfg80211_report_wowlan_wakeup().
 */
```

## 3078. original/linux-5.10.260/include/net/mac80211.h:6332

Líneas 6332–6345; tipo `block`.

```text
/**
 * ieee80211_tx_prepare_skb - prepare an 802.11 skb for transmission
 * @hw: pointer as obtained from ieee80211_alloc_hw()
 * @vif: virtual interface
 * @skb: frame to be sent from within the driver
 * @band: the band to transmit on
 * @sta: optional pointer to get the station to send the frame to
 *
 * Return: %true if the skb was prepared, %false otherwise.
 * On failure, the skb is freed by this function; callers must not
 * free it again.
 *
 * Note: must be called under RCU lock
 */
```

## 3079. original/linux-5.10.260/include/net/mac80211.h:6350

Líneas 6350–6360; tipo `block`.

```text
/**
 * ieee80211_parse_tx_radiotap - Sanity-check and parse the radiotap header
 *				 of injected frames.
 *
 * To accurately parse and take into account rate and retransmission fields,
 * you must initialize the chandef field in the ieee80211_tx_info structure
 * of the skb before calling this function.
 *
 * @skb: packet injected by userspace
 * @dev: the &struct device of this 802.11 device
 */
```

## 3080. original/linux-5.10.260/include/net/mac80211.h:6364

Líneas 6364–6376; tipo `block`.

```text
/**
 * struct ieee80211_noa_data - holds temporary data for tracking P2P NoA state
 *
 * @next_tsf: TSF timestamp of the next absent state change
 * @has_next_tsf: next absent state change event pending
 *
 * @absent: descriptor bitmask, set if GO is currently absent
 *
 * private:
 *
 * @count: count fields from the NoA descriptors
 * @desc: adjusted data from the NoA
 */
```

## 3081. original/linux-5.10.260/include/net/mac80211.h:6391

Líneas 6391–6399; tipo `block`.

```text
/**
 * ieee80211_parse_p2p_noa - initialize NoA tracking data from P2P IE
 *
 * @attr: P2P NoA IE
 * @data: NoA tracking data
 * @tsf: current TSF timestamp
 *
 * Return: number of successfully parsed descriptors
 */
```

## 3082. original/linux-5.10.260/include/net/mac80211.h:6403

Líneas 6403–6408; tipo `block`.

```text
/**
 * ieee80211_update_p2p_noa - get next pending P2P GO absent state change
 *
 * @data: NoA tracking data
 * @tsf: current TSF timestamp
 */
```

## 3083. original/linux-5.10.260/include/net/mac80211.h:6411

Líneas 6411–6420; tipo `block`.

```text
/**
 * ieee80211_tdls_oper_request - request userspace to perform a TDLS operation
 * @vif: virtual interface
 * @peer: the peer's destination address
 * @oper: the requested TDLS operation
 * @reason_code: reason code for the operation, valid for TDLS teardown
 * @gfp: allocation flags
 *
 * See cfg80211_tdls_oper_request().
 */
```

## 3084. original/linux-5.10.260/include/net/mac80211.h:6425

Líneas 6425–6443; tipo `block`.

```text
/**
 * ieee80211_reserve_tid - request to reserve a specific TID
 *
 * There is sometimes a need (such as in TDLS) for blocking the driver from
 * using a specific TID so that the FW can use it for certain operations such
 * as sending PTI requests. To make sure that the driver doesn't use that TID,
 * this function must be called as it flushes out packets on this TID and marks
 * it as blocked, so that any transmit for the station on this TID will be
 * redirected to the alternative TID in the same AC.
 *
 * Note that this function blocks and may call back into the driver, so it
 * should be called without driver locks held. Also note this function should
 * only be called from the driver's @sta_state callback.
 *
 * @sta: the station to reserve the TID for
 * @tid: the TID to reserve
 *
 * Returns: 0 on success, else on failure
 */
```

## 3085. original/linux-5.10.260/include/net/mac80211.h:6446

Líneas 6446–6459; tipo `block`.

```text
/**
 * ieee80211_unreserve_tid - request to unreserve a specific TID
 *
 * Once there is no longer any need for reserving a certain TID, this function
 * should be called, and no longer will packets have their TID modified for
 * preventing use of this TID in the driver.
 *
 * Note that this function blocks and acquires a lock, so it should be called
 * without driver locks held. Also note this function should only be called
 * from the driver's @sta_state callback.
 *
 * @sta: the station
 * @tid: the TID to unreserve
 */
```

## 3086. original/linux-5.10.260/include/net/mac80211.h:6462

Líneas 6462–6481; tipo `block`.

```text
/**
 * ieee80211_tx_dequeue - dequeue a packet from a software tx queue
 *
 * @hw: pointer as obtained from ieee80211_alloc_hw()
 * @txq: pointer obtained from station or virtual interface, or from
 *	ieee80211_next_txq()
 *
 * Returns the skb if successful, %NULL if no frame was available.
 *
 * Note that this must be called in an rcu_read_lock() critical section,
 * which can only be released after the SKB was handled. Some pointers in
 * skb->cb, e.g. the key pointer, are protected by RCU and thus the
 * critical section must persist not just for the duration of this call
 * but for the duration of the frame handling.
 * However, also note that while in the wake_tx_queue() method,
 * rcu_read_lock() is already held.
 *
 * softirqs must also be disabled when this function is called.
 * In process context, use ieee80211_tx_dequeue_ni() instead.
 */
```

## 3087. original/linux-5.10.260/include/net/mac80211.h:6485

Líneas 6485–6495; tipo `block`.

```text
/**
 * ieee80211_tx_dequeue_ni - dequeue a packet from a software tx queue
 * (in process context)
 *
 * Like ieee80211_tx_dequeue() but can be called in process context
 * (internally disables bottom halves).
 *
 * @hw: pointer as obtained from ieee80211_alloc_hw()
 * @txq: pointer obtained from station or virtual interface, or from
 *	ieee80211_next_txq()
 */
```

## 3088. original/linux-5.10.260/include/net/mac80211.h:6508

Líneas 6508–6517; tipo `block`.

```text
/**
 * ieee80211_next_txq - get next tx queue to pull packets from
 *
 * @hw: pointer as obtained from ieee80211_alloc_hw()
 * @ac: AC number to return packets from.
 *
 * Returns the next txq if successful, %NULL if no queue is eligible. If a txq
 * is returned, it should be returned with ieee80211_return_txq() after the
 * driver has finished scheduling it.
 */
```

## 3089. original/linux-5.10.260/include/net/mac80211.h:6520

Líneas 6520–6528; tipo `block`.

```text
/**
 * ieee80211_txq_schedule_start - start new scheduling round for TXQs
 *
 * @hw: pointer as obtained from ieee80211_alloc_hw()
 * @ac: AC number to acquire locks for
 *
 * Should be called before ieee80211_next_txq() or ieee80211_return_txq().
 * The driver must not call multiple TXQ scheduling rounds concurrently.
 */
```

## 3090. original/linux-5.10.260/include/net/mac80211.h:6531

Líneas 6531–6531; tipo `block`.

```text
/* (deprecated) */
```

## 3091. original/linux-5.10.260/include/net/mac80211.h:6539

Líneas 6539–6550; tipo `block`.

```text
/**
 * ieee80211_schedule_txq - schedule a TXQ for transmission
 *
 * @hw: pointer as obtained from ieee80211_alloc_hw()
 * @txq: pointer obtained from station or virtual interface
 *
 * Schedules a TXQ for transmission if it is not already scheduled,
 * even if mac80211 does not have any packets buffered.
 *
 * The driver may call this function if it has buffered packets for
 * this TXQ internally.
 */
```

## 3092. original/linux-5.10.260/include/net/mac80211.h:6557

Líneas 6557–6566; tipo `block`.

```text
/**
 * ieee80211_return_txq - return a TXQ previously acquired by ieee80211_next_txq()
 *
 * @hw: pointer as obtained from ieee80211_alloc_hw()
 * @txq: pointer obtained from station or virtual interface
 * @force: schedule txq even if mac80211 does not have any buffered packets.
 *
 * The driver may set force=true if it has buffered packets for this TXQ
 * internally.
 */
```

## 3093. original/linux-5.10.260/include/net/mac80211.h:6574

Líneas 6574–6597; tipo `block`.

```text
/**
 * ieee80211_txq_may_transmit - check whether TXQ is allowed to transmit
 *
 * This function is used to check whether given txq is allowed to transmit by
 * the airtime scheduler, and can be used by drivers to access the airtime
 * fairness accounting without going using the scheduling order enfored by
 * next_txq().
 *
 * Returns %true if the airtime scheduler thinks the TXQ should be allowed to
 * transmit, and %false if it should be throttled. This function can also have
 * the side effect of rotating the TXQ in the scheduler rotation, which will
 * eventually bring the deficit to positive and allow the station to transmit
 * again.
 *
 * The API ieee80211_txq_may_transmit() also ensures that TXQ list will be
 * aligned against driver's own round-robin scheduler list. i.e it rotates
 * the TXQ list till it makes the requested node becomes the first entry
 * in TXQ list. Thus both the TXQ list and driver's list are in sync. If this
 * function returns %true, the driver is expected to schedule packets
 * for transmission, and then return the TXQ through ieee80211_return_txq().
 *
 * @hw: pointer as obtained from ieee80211_alloc_hw()
 * @txq: pointer obtained from station or virtual interface
 */
```

## 3094. original/linux-5.10.260/include/net/mac80211.h:6601

Líneas 6601–6611; tipo `block`.

```text
/**
 * ieee80211_txq_get_depth - get pending frame/byte count of given txq
 *
 * The values are not guaranteed to be coherent with regard to each other, i.e.
 * txq state can change half-way of this function and the caller may end up
 * with "new" frame_cnt and "old" byte_cnt or vice-versa.
 *
 * @txq: pointer obtained from station or virtual interface
 * @frame_cnt: pointer to store frame count
 * @byte_cnt: pointer to store byte count
 */
```

## 3095. original/linux-5.10.260/include/net/mac80211.h:6616

Líneas 6616–6626; tipo `block`.

```text
/**
 * ieee80211_nan_func_terminated - notify about NAN function termination.
 *
 * This function is used to notify mac80211 about NAN function termination.
 * Note that this function can't be called from hard irq.
 *
 * @vif: &struct ieee80211_vif pointer from the add_interface callback.
 * @inst_id: the local instance id
 * @reason: termination reason (one of the NL80211_NAN_FUNC_TERM_REASON_*)
 * @gfp: allocation flags
 */
```

## 3096. original/linux-5.10.260/include/net/mac80211.h:6632

Líneas 6632–6642; tipo `block`.

```text
/**
 * ieee80211_nan_func_match - notify about NAN function match event.
 *
 * This function is used to notify mac80211 about NAN function match. The
 * cookie inside the match struct will be assigned by mac80211.
 * Note that this function can't be called from hard irq.
 *
 * @vif: &struct ieee80211_vif pointer from the add_interface callback.
 * @match: match event information
 * @gfp: allocation flags
 */
```

## 3097. original/linux-5.10.260/include/net/mac80211.h:6647

Líneas 6647–6657; tipo `block`.

```text
/**
 * ieee80211_calc_rx_airtime - calculate estimated transmission airtime for RX.
 *
 * This function calculates the estimated airtime usage of a frame based on the
 * rate information in the RX status struct and the frame length.
 *
 * @hw: pointer as obtained from ieee80211_alloc_hw()
 * @status: &struct ieee80211_rx_status containing the transmission rate
 *          information.
 * @len: frame length in bytes
 */
```

## 3098. original/linux-5.10.260/include/net/mac80211.h:6662

Líneas 6662–6671; tipo `block`.

```text
/**
 * ieee80211_calc_tx_airtime - calculate estimated transmission airtime for TX.
 *
 * This function calculates the estimated airtime usage of a frame based on the
 * rate information in the TX info struct and the frame length.
 *
 * @hw: pointer as obtained from ieee80211_alloc_hw()
 * @info: &struct ieee80211_tx_info of the frame.
 * @len: frame length in bytes
 */
```

## 3099. original/linux-5.10.260/include/net/mac80211.h:6675

Líneas 6675–6684; tipo `block`.

```text
/**
 * ieee80211_set_hw_80211_encap - enable hardware encapsulation offloading.
 *
 * This function is used to notify mac80211 that a vif can be passed raw 802.3
 * frames. The driver needs to then handle the 802.11 encapsulation inside the
 * hardware or firmware.
 *
 * @vif: &struct ieee80211_vif pointer from the add_interface callback.
 * @enable: indicate if the feature should be turned on or off
 */
```

## 3100. original/linux-5.10.260/include/net/mac80211.h:6687

Líneas 6687–6695; tipo `block`.

```text
/**
 * ieee80211_get_fils_discovery_tmpl - Get FILS discovery template.
 * @hw: pointer obtained from ieee80211_alloc_hw().
 * @vif: &struct ieee80211_vif pointer from the add_interface callback.
 *
 * The driver is responsible for freeing the returned skb.
 *
 * Return: FILS discovery template. %NULL on error.
 */
```

## 3101. original/linux-5.10.260/include/net/mac80211.h:6699

Líneas 6699–6708; tipo `block`.

```text
/**
 * ieee80211_get_unsol_bcast_probe_resp_tmpl - Get unsolicited broadcast
 *	probe response template.
 * @hw: pointer obtained from ieee80211_alloc_hw().
 * @vif: &struct ieee80211_vif pointer from the add_interface callback.
 *
 * The driver is responsible for freeing the returned skb.
 *
 * Return: Unsolicited broadcast probe response template. %NULL on error.
 */
```

## 3102. original/linux-5.10.260/include/net/mac80211.h:6712

Líneas 6712–6712; tipo `block`.

```text
/* MAC80211_H */
```

## 3103. original/port-overlay/drivers/net/wireless/realtek/rtlwifi/pci.c:1

Líneas 1–1; tipo `line`.

```text
// SPDX-License-Identifier: GPL-2.0
```

## 3104. original/port-overlay/drivers/net/wireless/realtek/rtlwifi/pci.c:2

Líneas 2–2; tipo `block`.

```text
/* Copyright(c) 2009-2012  Realtek Corporation.*/
```

## 3105. original/port-overlay/drivers/net/wireless/realtek/rtlwifi/pci.c:161

Líneas 161–166; tipo `block`.

```text
/* The OEM SyncSWTXBDHostIdxToHW88XX path performs a final read of
	 * TXBD element 0 after filling the descriptor and before the MMIO host
	 * index write.  Its comment explicitly uses that read to prevent the IO
	 * publication from overtaking descriptor writes.  Preserve the same
	 * ordering on Topaz instead of relying on a write barrier alone.
	 */
```

## 3106. original/port-overlay/drivers/net/wireless/realtek/rtlwifi/pci.c:348

Líneas 348–348; tipo `block`.

```text
/* Update PCI dependent default settings*/
```

## 3107. original/port-overlay/drivers/net/wireless/realtek/rtlwifi/pci.c:361

Líneas 361–361; tipo `block`.

```text
/*Update PCI ASPM setting */
```

## 3108. original/port-overlay/drivers/net/wireless/realtek/rtlwifi/pci.c:365

Líneas 365–365; tipo `block`.

```text
/*No ASPM */
```

## 3109. original/port-overlay/drivers/net/wireless/realtek/rtlwifi/pci.c:369

Líneas 369–369; tipo `block`.

```text
/*ASPM dynamically enabled/disable. */
```

## 3110. original/port-overlay/drivers/net/wireless/realtek/rtlwifi/pci.c:374

Líneas 374–374; tipo `block`.

```text
/*ASPM with Clock Req dynamically enabled/disable. */
```

## 3111. original/port-overlay/drivers/net/wireless/realtek/rtlwifi/pci.c:380

Líneas 380–382; tipo `block`.

```text
/* Always enable ASPM and Clock Req
		 * from initialization to halt.
		 */
```

## 3112. original/port-overlay/drivers/net/wireless/realtek/rtlwifi/pci.c:389

Líneas 389–391; tipo `block`.

```text
/* Always enable ASPM without Clock Req
		 * from initialization to halt.
		 */
```

## 3113. original/port-overlay/drivers/net/wireless/realtek/rtlwifi/pci.c:400

Líneas 400–400; tipo `block`.

```text
/*Update Radio OFF setting */
```

## 3114. original/port-overlay/drivers/net/wireless/realtek/rtlwifi/pci.c:418

Líneas 418–418; tipo `block`.

```text
/*Set HW definition to determine if it supports ASPM. */
```

## 3115. original/port-overlay/drivers/net/wireless/realtek/rtlwifi/pci.c:421

Líneas 421–421; tipo `block`.

```text
/*Not support ASPM. */
```

## 3116. original/port-overlay/drivers/net/wireless/realtek/rtlwifi/pci.c:425

Líneas 425–425; tipo `block`.

```text
/*Support ASPM. */
```

## 3117. original/port-overlay/drivers/net/wireless/realtek/rtlwifi/pci.c:430

Líneas 430–430; tipo `block`.

```text
/*ASPM value set by chipset. */
```

## 3118. original/port-overlay/drivers/net/wireless/realtek/rtlwifi/pci.c:440

Líneas 440–442; tipo `block`.

```text
/* toshiba aspm issue, toshiba will set aspm selfly
	 * so we should not set aspm in driver
	 */
```

## 3119. original/port-overlay/drivers/net/wireless/realtek/rtlwifi/pci.c:448

Líneas 448–452; tipo `block`.

```text
/* RTL8723BE found on some ASUSTek laptops, such as F441U and
	 * X555UQ with subsystem ID 11ad:1723 are known to output large
	 * amounts of PCIe AER errors during and after boot up, causing
	 * heavy lags, poor network throughput, and occasional lock-ups.
	 */
```

## 3120. original/port-overlay/drivers/net/wireless/realtek/rtlwifi/pci.c:478

Líneas 478–478; tipo `block`.

```text
/* @value is PCI_EXP_LNKCTL_CLKREQ_EN or 0 to enable/disable clk request. */
```

## 3121. original/port-overlay/drivers/net/wireless/realtek/rtlwifi/pci.c:494

Líneas 494–494; tipo `block`.

```text
/*Disable RTL8192SE ASPM & Disable Pci Bridge ASPM*/
```

## 3122. original/port-overlay/drivers/net/wireless/realtek/rtlwifi/pci.c:502

Líneas 502–502; tipo `block`.

```text
/*Retrieve original configuration settings. */
```

## 3123. original/port-overlay/drivers/net/wireless/realtek/rtlwifi/pci.c:522

Líneas 522–522; tipo `block`.

```text
/*for promising device will in L0 state after an I/O. */
```

## 3124. original/port-overlay/drivers/net/wireless/realtek/rtlwifi/pci.c:525

Líneas 525–525; tipo `block`.

```text
/*Set corresponding value. */
```

## 3125. original/port-overlay/drivers/net/wireless/realtek/rtlwifi/pci.c:532

Líneas 532–536; tipo `block`.

```text
/*Enable RTL8192SE ASPM & Enable Pci Bridge ASPM for
 *power saving We should follow the sequence to enable
 *RTL8192SE first then enable Pci Bridge ASPM
 *or the system will show bluescreen.
 */
```

## 3126. original/port-overlay/drivers/net/wireless/realtek/rtlwifi/pci.c:556

Líneas 556–556; tipo `block`.

```text
/*Get ASPM level (with/without Clock Req) */
```

## 3127. original/port-overlay/drivers/net/wireless/realtek/rtlwifi/pci.c:560

Líneas 560–560; tipo `block`.

```text
/*_rtl_pci_platform_switch_device_pci_aspm(dev,*/
```

## 3128. original/port-overlay/drivers/net/wireless/realtek/rtlwifi/pci.c:561

Líneas 561–561; tipo `block`.

```text
/*(priv->ndis_adapter.linkctrl_reg | ASPMLevel)); */
```

## 3129. original/port-overlay/drivers/net/wireless/realtek/rtlwifi/pci.c:606

Líneas 606–606; tipo `block`.

```text
/*Link Control Register */
```

## 3130. original/port-overlay/drivers/net/wireless/realtek/rtlwifi/pci.c:628

Líneas 628–628; tipo `block`.

```text
/*Always enable ASPM & Clock Req. */
```

## 3131. original/port-overlay/drivers/net/wireless/realtek/rtlwifi/pci.c:660

Líneas 660–660; tipo `block`.

```text
/* here open is 4, wep/tkip is 8, aes is 12*/
```

## 3132. original/port-overlay/drivers/net/wireless/realtek/rtlwifi/pci.c:664

Líneas 664–664; tipo `block`.

```text
/* The most skb num is 6 */
```

## 3133. original/port-overlay/drivers/net/wireless/realtek/rtlwifi/pci.c:691

Líneas 691–691; tipo `block`.

```text
/* just for early mode now */
```

## 3134. original/port-overlay/drivers/net/wireless/realtek/rtlwifi/pci.c:705

Líneas 705–705; tipo `block`.

```text
/* we just use em for BE/BK/VI/VO */
```

## 3135. original/port-overlay/drivers/net/wireless/realtek/rtlwifi/pci.c:727

Líneas 727–729; tipo `block`.

```text
/* Some macaddr can't do early mode. like
			 * multicast/broadcast/no_qos data
			 */
```

## 3136. original/port-overlay/drivers/net/wireless/realtek/rtlwifi/pci.c:775

Líneas 775–775; tipo `block`.

```text
/* remove early mode header */
```

## 3137. original/port-overlay/drivers/net/wireless/realtek/rtlwifi/pci.c:790

Líneas 790–793; tipo `block`.

```text
/* for sw LPS, just after NULL skb send out, we can
		 * sure AP knows we are sleeping, we should not let
		 * rf sleep
		 */
```

## 3138. original/port-overlay/drivers/net/wireless/realtek/rtlwifi/pci.c:818

Líneas 818–818; tipo `block`.

```text
/* update tid tx pkt num */
```

## 3139. original/port-overlay/drivers/net/wireless/realtek/rtlwifi/pci.c:892

Líneas 892–892; tipo `block`.

```text
/*info->status.rates[0].count = 1; */
```

## 3140. original/port-overlay/drivers/net/wireless/realtek/rtlwifi/pci.c:1007

Líneas 1007–1010; tipo `block`.

```text
/* UART at 115200 baud is part of the timing budget on Topaz.  Keep
		 * enough samples to diagnose a stuck queue without printing from every
		 * TX-DOK interrupt and creating the backlog we are measuring.
		 */
```

## 3141. original/port-overlay/drivers/net/wireless/realtek/rtlwifi/pci.c:1039

Líneas 1039–1039; tipo `block`.

```text
/* just set skb->cb to mapping addr for pci_unmap_single use */
```

## 3142. original/port-overlay/drivers/net/wireless/realtek/rtlwifi/pci.c:1051

Líneas 1051–1051; tipo `block`.

```text
/* skb->cb may be 64 bit address */
```

## 3143. original/port-overlay/drivers/net/wireless/realtek/rtlwifi/pci.c:1069

Líneas 1069–1081; tipo `block`.

```text
/* inorder to receive 8K AMSDU we have set skb to
 * 9100bytes in init rx ring, but if this packet is
 * not a AMSDU, this large packet will be sent to
 * TCP/IP directly, this cause big packet ping fail
 * like: "ping -s 65507", so here we will realloc skb
 * based on the true size of packet, Mac80211
 * Probably will do it better, but does not yet.
 *
 * Some platform will fail when alloc skb sometimes.
 * in this condition, we will send the old skb to
 * mac80211 directly, this will not cause any other
 * issues, but only this packet will be lost by TCP/IP
 */
```

## 3144. original/port-overlay/drivers/net/wireless/realtek/rtlwifi/pci.c:1104

Líneas 1104–1104; tipo `block`.

```text
/*hsisr interrupt handler*/
```

## 3145. original/port-overlay/drivers/net/wireless/realtek/rtlwifi/pci.c:1134

Líneas 1134–1134; tipo `block`.

```text
/*RX NORMAL PKT */
```

## 3146. original/port-overlay/drivers/net/wireless/realtek/rtlwifi/pci.c:1142

Líneas 1142–1142; tipo `block`.

```text
/*rx buffer descriptor */
```

## 3147. original/port-overlay/drivers/net/wireless/realtek/rtlwifi/pci.c:1144

Líneas 1144–1144; tipo `block`.

```text
/*if use new trx flow, it means wifi info */
```

## 3148. original/port-overlay/drivers/net/wireless/realtek/rtlwifi/pci.c:1146

Líneas 1146–1146; tipo `block`.

```text
/*rx pkt */
```

## 3149. original/port-overlay/drivers/net/wireless/realtek/rtlwifi/pci.c:1161

Líneas 1161–1161; tipo `block`.

```text
/* rx descriptor */
```

## 3150. original/port-overlay/drivers/net/wireless/realtek/rtlwifi/pci.c:1168

Líneas 1168–1168; tipo `block`.

```text
/* wait data to be filled by hardware */
```

## 3151. original/port-overlay/drivers/net/wireless/realtek/rtlwifi/pci.c:1172

Líneas 1172–1175; tipo `block`.

```text
/* Reaching this point means: data is filled already
		 * AAAAAAttention !!!
		 * We can NOT access 'skb' before 'pci_unmap_single'
		 */
```

## 3152. original/port-overlay/drivers/net/wireless/realtek/rtlwifi/pci.c:1179

Líneas 1179–1179; tipo `block`.

```text
/* get a new skb - if fail, old one will be reused */
```

## 3153. original/port-overlay/drivers/net/wireless/realtek/rtlwifi/pci.c:1203

Líneas 1203–1208; tipo `block`.

```text
/* The 92EE RX shift is byte-granular. On ARC700 a shift of
			 * one or three leaves the 802.11 header at an odd address and
			 * direct u16 frame-control loads trap. Move the completed frame
			 * down by one byte while headroom is still available. The later
			 * skb copy then preserves the aligned frame for mac80211.
			 */
```

## 3154. original/port-overlay/drivers/net/wireless/realtek/rtlwifi/pci.c:1229

Líneas 1229–1229; tipo `block`.

```text
/* handle command packet here */
```

## 3155. original/port-overlay/drivers/net/wireless/realtek/rtlwifi/pci.c:1235

Líneas 1235–1239; tipo `block`.

```text
/* NOTICE This can not be use for mac80211,
		 * this is done in mac80211 code,
		 * if done here sec DHCP will fail
		 * skb_trim(skb, skb->len - 4);
		 */
```

## 3156. original/port-overlay/drivers/net/wireless/realtek/rtlwifi/pci.c:1254

Líneas 1254–1254; tipo `block`.

```text
/*TODO*/
```

## 3157. original/port-overlay/drivers/net/wireless/realtek/rtlwifi/pci.c:1256

Líneas 1256–1256; tipo `block`.

```text
/*TODO*/
```

## 3158. original/port-overlay/drivers/net/wireless/realtek/rtlwifi/pci.c:1271

Líneas 1271–1271; tipo `block`.

```text
/* static bcn for roaming */
```

## 3159. original/port-overlay/drivers/net/wireless/realtek/rtlwifi/pci.c:1274

Líneas 1274–1274; tipo `block`.

```text
/* for sw lps */
```

## 3160. original/port-overlay/drivers/net/wireless/realtek/rtlwifi/pci.c:1303

Líneas 1303–1303; tipo `block`.

```text
/* drop packets with errors or those too short */
```

## 3161. original/port-overlay/drivers/net/wireless/realtek/rtlwifi/pci.c:1383

Líneas 1383–1388; tipo `block`.

```text
/* The 92EE RXQ register may remain read=write+1 while empty
		 * (observed 0x00010000, 0x00020001, ...).  It is telemetry, not a
		 * reliable pending predicate.  Only a full software budget proves
		 * probable backlog.  A short or zero batch re-opens HIMR; any packet
		 * arriving before/after that write leaves a latched ISR wakeup.
		 */
```

## 3162. original/port-overlay/drivers/net/wireless/realtek/rtlwifi/pci.c:1416

Líneas 1416–1419; tipo `block`.

```text
/* Reuse the normal close predicate.  It reads hardware RP and
		 * reclaims only descriptors strictly behind it; no descriptor is
		 * force-completed and index == hardware RP remains owned by HW.
		 */
```

## 3163. original/port-overlay/drivers/net/wireless/realtek/rtlwifi/pci.c:1465

Líneas 1465–1468; tipo `block`.

```text
/* Topaz INTx is level-triggered.  A temporary HIMR-off
			 * window must still acknowledge the latched device status or
			 * the generic level flow immediately retriggers forever.
			 */
```

## 3164. original/port-overlay/drivers/net/wireless/realtek/rtlwifi/pci.c:1488

Líneas 1488–1488; tipo `block`.

```text
/*read ISR: 4/8bytes */
```

## 3165. original/port-overlay/drivers/net/wireless/realtek/rtlwifi/pci.c:1501

Líneas 1501–1503; tipo `block`.

```text
/* Shared IRQ or HW disappeared. 92EE reports RX overflow in intb; an
	 * intb-only vector is real work and must not be mistaken for IRQ_NONE.
	 */
```

## 3166. original/port-overlay/drivers/net/wireless/realtek/rtlwifi/pci.c:1508

Líneas 1508–1508; tipo `block`.

```text
/*<1> beacon related */
```

## 3167. original/port-overlay/drivers/net/wireless/realtek/rtlwifi/pci.c:1526

Líneas 1526–1526; tipo `block`.

```text
/*<2> Tx related */
```

## 3168. original/port-overlay/drivers/net/wireless/realtek/rtlwifi/pci.c:1552

Líneas 1552–1555; tipo `block`.

```text
/*<3> Rx related. The MitraStar has one 500 MHz ARC core and a level
	 * INTx route. Keep HIMR masked and move RX out of hard IRQ context so a
	 * sustained client cannot starve UART, EMAC polling and the scheduler.
	 */
```

## 3169. original/port-overlay/drivers/net/wireless/realtek/rtlwifi/pci.c:1587

Líneas 1587–1587; tipo `block`.

```text
/*<4> fw related*/
```

## 3170. original/port-overlay/drivers/net/wireless/realtek/rtlwifi/pci.c:1597

Líneas 1597–1597; tipo `block`.

```text
/*<5> hsisr related*/
```

## 3171. original/port-overlay/drivers/net/wireless/realtek/rtlwifi/pci.c:1598

Líneas 1598–1602; tipo `block`.

```text
/* Only 8188EE & 8723BE Supported.
	 * If Other ICs Come in, System will corrupt,
	 * because maps[RTL_IMR_HSISR_IND] & maps[MAC_HSISR]
	 * are not initialized
	 */
```

## 3172. original/port-overlay/drivers/net/wireless/realtek/rtlwifi/pci.c:1643

Líneas 1643–1643; tipo `block`.

```text
/*This is for new trx flow*/
```

## 3173. original/port-overlay/drivers/net/wireless/realtek/rtlwifi/pci.c:1663

Líneas 1663–1663; tipo `block`.

```text
/*NB: the beacon data buffer must be 32-bit aligned. */
```

## 3174. original/port-overlay/drivers/net/wireless/realtek/rtlwifi/pci.c:1689

Líneas 1689–1696; tipo `block`.

```text
/* HGW-500BNA-QCv2 / RTL8192EE new-flow beacon descriptors are fixed at
	 * BCNQ descriptor 0.  The normal TX path rings the queue after set_desc(),
	 * but the beacon tasklet historically only set OWN and waited for the
	 * hardware/interrupt cadence.  On Topaz this can leave hostapd ENABLED
	 * while no external client sees RF beacons.  Publish the descriptor and
	 * explicitly trigger the existing BCNQ PCIe poll bit on the managed IRQ28
	 * target.  This is beacon-only; data queue TXBD32 policy is unchanged.
	 */
```

## 3175. original/port-overlay/drivers/net/wireless/realtek/rtlwifi/pci.c:1726

Líneas 1726–1731; tipo `block`.

```text
/* The 8192EE OEM DMA contract reserves a fixed 128-byte aperture for
	 * each beacon TXBD slot.  In global 32-bit mode each TXBD is 32 bytes,
	 * so retain four entries of backing storage even though mac80211 uses
	 * only descriptor zero for the single-BSS beacon.  This keeps all queues
	 * in the global 8-byte-segment format without under-allocating BCNQ.
	 */
```

## 3176. original/port-overlay/drivers/net/wireless/realtek/rtlwifi/pci.c:1740

Líneas 1740–1743; tipo `block`.

```text
/*BE queue need more descriptor for performance
	 *consideration or, No more tx desc will happen,
	 *and may cause mac80211 mem leakage.
	 */
```

## 3177. original/port-overlay/drivers/net/wireless/realtek/rtlwifi/pci.c:1747

Líneas 1747–1747; tipo `block`.

```text
/*2048/1024; */
```

## 3178. original/port-overlay/drivers/net/wireless/realtek/rtlwifi/pci.c:1748

Líneas 1748–1748; tipo `block`.

```text
/*64; */
```

## 3179. original/port-overlay/drivers/net/wireless/realtek/rtlwifi/pci.c:1785

Líneas 1785–1785; tipo `block`.

```text
/*Tx/Rx related var */
```

## 3180. original/port-overlay/drivers/net/wireless/realtek/rtlwifi/pci.c:1788

Líneas 1788–1788; tipo `block`.

```text
/*IBSS*/
```

## 3181. original/port-overlay/drivers/net/wireless/realtek/rtlwifi/pci.c:1791

Líneas 1791–1791; tipo `block`.

```text
/*AMPDU*/
```

## 3182. original/port-overlay/drivers/net/wireless/realtek/rtlwifi/pci.c:1794

Líneas 1794–1794; tipo `block`.

```text
/*set sane AMPDU defaults */
```

## 3183. original/port-overlay/drivers/net/wireless/realtek/rtlwifi/pci.c:1798

Líneas 1798–1798; tipo `block`.

```text
/*Retry Limit*/
```

## 3184. original/port-overlay/drivers/net/wireless/realtek/rtlwifi/pci.c:1802

Líneas 1802–1802; tipo `block`.

```text
/*QOS*/
```

## 3185. original/port-overlay/drivers/net/wireless/realtek/rtlwifi/pci.c:1805

Líneas 1805–1805; tipo `block`.

```text
/*task */
```

## 3186. original/port-overlay/drivers/net/wireless/realtek/rtlwifi/pci.c:1826

Líneas 1826–1826; tipo `block`.

```text
/* alloc tx buffer desc for new trx flow*/
```

## 3187. original/port-overlay/drivers/net/wireless/realtek/rtlwifi/pci.c:1862

Líneas 1862–1862; tipo `block`.

```text
/* alloc dma for this ring */
```

## 3188. original/port-overlay/drivers/net/wireless/realtek/rtlwifi/pci.c:1881

Líneas 1881–1881; tipo `block`.

```text
/* init every desc in this ring */
```

## 3189. original/port-overlay/drivers/net/wireless/realtek/rtlwifi/pci.c:1905

Líneas 1905–1905; tipo `block`.

```text
/* alloc dma for this ring */
```

## 3190. original/port-overlay/drivers/net/wireless/realtek/rtlwifi/pci.c:1917

Líneas 1917–1917; tipo `block`.

```text
/* init every desc in this ring */
```

## 3191. original/port-overlay/drivers/net/wireless/realtek/rtlwifi/pci.c:1928

Líneas 1928–1928; tipo `block`.

```text
/* alloc dma for this ring */
```

## 3192. original/port-overlay/drivers/net/wireless/realtek/rtlwifi/pci.c:1940

Líneas 1940–1940; tipo `block`.

```text
/* init every desc in this ring */
```

## 3193. original/port-overlay/drivers/net/wireless/realtek/rtlwifi/pci.c:1963

Líneas 1963–1963; tipo `block`.

```text
/* free every desc in this ring */
```

## 3194. original/port-overlay/drivers/net/wireless/realtek/rtlwifi/pci.c:1980

Líneas 1980–1980; tipo `block`.

```text
/* free dma of this ring */
```

## 3195. original/port-overlay/drivers/net/wireless/realtek/rtlwifi/pci.c:1999

Líneas 1999–1999; tipo `block`.

```text
/* free every desc in this ring */
```

## 3196. original/port-overlay/drivers/net/wireless/realtek/rtlwifi/pci.c:2010

Líneas 2010–2010; tipo `block`.

```text
/* free dma of this ring */
```

## 3197. original/port-overlay/drivers/net/wireless/realtek/rtlwifi/pci.c:2034

Líneas 2034–2036; tipo `block`.

```text
/* rxring_idx 0:RX_MPDU_QUEUE
	 * rxring_idx 1:RX_CMD_QUEUE
	 */
```

## 3198. original/port-overlay/drivers/net/wireless/realtek/rtlwifi/pci.c:2067

Líneas 2067–2067; tipo `block`.

```text
/*free rx rings */
```

## 3199. original/port-overlay/drivers/net/wireless/realtek/rtlwifi/pci.c:2071

Líneas 2071–2071; tipo `block`.

```text
/*free tx rings */
```

## 3200. original/port-overlay/drivers/net/wireless/realtek/rtlwifi/pci.c:2086

Líneas 2086–2086; tipo `block`.

```text
/* rxring_idx 0:RX_MPDU_QUEUE */
```

## 3201. original/port-overlay/drivers/net/wireless/realtek/rtlwifi/pci.c:2087

Líneas 2087–2087; tipo `block`.

```text
/* rxring_idx 1:RX_CMD_QUEUE */
```

## 3202. original/port-overlay/drivers/net/wireless/realtek/rtlwifi/pci.c:2089

Líneas 2089–2092; tipo `block`.

```text
/* force the rx_ring[RX_MPDU_QUEUE/
		 * RX_CMD_QUEUE].idx to the first one
		 *new trx flow, do nothing
		 */
```

## 3203. original/port-overlay/drivers/net/wireless/realtek/rtlwifi/pci.c:2105

Líneas 2105–2105; tipo `block`.

```text
/*clear one entry*/
```

## 3204. original/port-overlay/drivers/net/wireless/realtek/rtlwifi/pci.c:2132

Líneas 2132–2134; tipo `block`.

```text
/*after reset, release previous pending packet,
	 *and force the  tx idx to the first one
	 */
```

## 3205. original/port-overlay/drivers/net/wireless/realtek/rtlwifi/pci.c:2199

Líneas 2199–2199; tipo `block`.

```text
/* maybe every tid should be checked */
```

## 3206. original/port-overlay/drivers/net/wireless/realtek/rtlwifi/pci.c:2514

Líneas 2514–2514; tipo `block`.

```text
/* we just wait 1s for all queues */
```

## 3207. original/port-overlay/drivers/net/wireless/realtek/rtlwifi/pci.c:2618

Líneas 2618–2618; tipo `block`.

```text
/*should be after adapter start and interrupt enable. */
```

## 3208. original/port-overlay/drivers/net/wireless/realtek/rtlwifi/pci.c:2620

Líneas 2620–2623; tipo `block`.

```text
/* request_irq() installs the handler during probe, but RX DMA is not
	 * ready until hw_init(), rtl_init_rx_config() and set_hal_start().
	 * Open the physical IRQ line only after all three milestones.
	 */
```

## 3209. original/port-overlay/drivers/net/wireless/realtek/rtlwifi/pci.c:2643

Líneas 2643–2645; tipo `block`.

```text
/* Close the physical line exactly once before masking device interrupts
	 * or disabling hardware.  A later successful start balances this hold.
	 */
```

## 3210. original/port-overlay/drivers/net/wireless/realtek/rtlwifi/pci.c:2654

Líneas 2654–2656; tipo `block`.

```text
/*should be before disable interrupt&adapter
	 *and will do it immediately.
	 */
```

## 3211. original/port-overlay/drivers/net/wireless/realtek/rtlwifi/pci.c:2679

Líneas 2679–2679; tipo `block`.

```text
/* some things are not needed if firmware not available */
```

## 3212. original/port-overlay/drivers/net/wireless/realtek/rtlwifi/pci.c:2710

Líneas 2710–2715; tipo `block`.

```text
/* PCI ID 0x10ec:0x8192 occurs for both RTL8192E, which uses
	 * r8192e_pci, and RTL8192SE, which uses this driver. If the
	 * revision ID is RTL_PCI_REVISION_ID_8192PCIE (0x01), then
	 * the correct driver is r8192e_pci, thus this routine should
	 * return false.
	 */
```

## 3213. original/port-overlay/drivers/net/wireless/realtek/rtlwifi/pci.c:2822

Líneas 2822–2822; tipo `block`.

```text
/* use new trx flow */
```

## 3214. original/port-overlay/drivers/net/wireless/realtek/rtlwifi/pci.c:2831

Líneas 2831–2831; tipo `block`.

```text
/*find bus info */
```

## 3215. original/port-overlay/drivers/net/wireless/realtek/rtlwifi/pci.c:2836

Líneas 2836–2836; tipo `block`.

```text
/*find bridge info */
```

## 3216. original/port-overlay/drivers/net/wireless/realtek/rtlwifi/pci.c:2838

Líneas 2838–2840; tipo `block`.

```text
/* some ARM have no bridge_pdev and will crash here
	 * so we should check if bridge_pdev is NULL
	 */
```

## 3217. original/port-overlay/drivers/net/wireless/realtek/rtlwifi/pci.c:2842

Líneas 2842–2842; tipo `block`.

```text
/*find bridge info if available */
```

## 3218. original/port-overlay/drivers/net/wireless/realtek/rtlwifi/pci.c:2940

Líneas 2940–2942; tipo `block`.

```text
/* IRQF_NO_AUTOEN owns the initial disable depth.  Do not call
		 * disable_irq() here: start-ready performs the first enable_irq().
		 */
```

## 3219. original/port-overlay/drivers/net/wireless/realtek/rtlwifi/pci.c:2982

Líneas 2982–2982; tipo `block`.

```text
/* 0x719 Bit5 is DMA64 bit fetch. */
```

## 3220. original/port-overlay/drivers/net/wireless/realtek/rtlwifi/pci.c:3051

Líneas 3051–3051; tipo `block`.

```text
/*proximity init here*/
```

## 3221. original/port-overlay/drivers/net/wireless/realtek/rtlwifi/pci.c:3057

Líneas 3057–3057; tipo `block`.

```text
/* init cfg & intf_ops */
```

## 3222. original/port-overlay/drivers/net/wireless/realtek/rtlwifi/pci.c:3063

Líneas 3063–3063; tipo `block`.

```text
/* MEM map */
```

## 3223. original/port-overlay/drivers/net/wireless/realtek/rtlwifi/pci.c:3074

Líneas 3074–3074; tipo `block`.

```text
/*shared mem start */
```

## 3224. original/port-overlay/drivers/net/wireless/realtek/rtlwifi/pci.c:3089

Líneas 3089–3089; tipo `block`.

```text
/* Disable Clk Request */
```

## 3225. original/port-overlay/drivers/net/wireless/realtek/rtlwifi/pci.c:3091

Líneas 3091–3091; tipo `block`.

```text
/* leave D3 mode */
```

## 3226. original/port-overlay/drivers/net/wireless/realtek/rtlwifi/pci.c:3096

Líneas 3096–3096; tipo `block`.

```text
/* find adapter */
```

## 3227. original/port-overlay/drivers/net/wireless/realtek/rtlwifi/pci.c:3102

Líneas 3102–3102; tipo `block`.

```text
/* Init IO handler */
```

## 3228. original/port-overlay/drivers/net/wireless/realtek/rtlwifi/pci.c:3105

Líneas 3105–3105; tipo `block`.

```text
/*like read eeprom and so on */
```

## 3229. original/port-overlay/drivers/net/wireless/realtek/rtlwifi/pci.c:3119

Líneas 3119–3119; tipo `block`.

```text
/*aspm */
```

## 3230. original/port-overlay/drivers/net/wireless/realtek/rtlwifi/pci.c:3122

Líneas 3122–3122; tipo `block`.

```text
/* Init mac80211 sw */
```

## 3231. original/port-overlay/drivers/net/wireless/realtek/rtlwifi/pci.c:3131

Líneas 3131–3131; tipo `block`.

```text
/* Init PCI sw */
```

## 3232. original/port-overlay/drivers/net/wireless/realtek/rtlwifi/pci.c:3150

Líneas 3150–3150; tipo `block`.

```text
/* add for debug */
```

## 3233. original/port-overlay/drivers/net/wireless/realtek/rtlwifi/pci.c:3153

Líneas 3153–3153; tipo `block`.

```text
/*init rfkill */
```

## 3234. original/port-overlay/drivers/net/wireless/realtek/rtlwifi/pci.c:3154

Líneas 3154–3154; tipo `block`.

```text
/* Init PCI sw */
```

## 3235. original/port-overlay/drivers/net/wireless/realtek/rtlwifi/pci.c:3209

Líneas 3209–3209; tipo `block`.

```text
/* just in case driver is removed before firmware callback */
```

## 3236. original/port-overlay/drivers/net/wireless/realtek/rtlwifi/pci.c:3213

Líneas 3213–3213; tipo `block`.

```text
/* remove form debug */
```

## 3237. original/port-overlay/drivers/net/wireless/realtek/rtlwifi/pci.c:3216

Líneas 3216–3216; tipo `block`.

```text
/*ieee80211_unregister_hw will call ops_stop */
```

## 3238. original/port-overlay/drivers/net/wireless/realtek/rtlwifi/pci.c:3226

Líneas 3226–3226; tipo `block`.

```text
/*deinit rfkill */
```

## 3239. original/port-overlay/drivers/net/wireless/realtek/rtlwifi/pci.c:3234

Líneas 3234–3234; tipo `block`.

```text
/* free_irq() must not inherit our disable depth on a shared line. */
```

## 3240. original/port-overlay/drivers/net/wireless/realtek/rtlwifi/pci.c:3259

Líneas 3259–3273; tipo `block`.

```text
/***************************************
 * kernel pci power state define:
 * PCI_D0         ((pci_power_t __force) 0)
 * PCI_D1         ((pci_power_t __force) 1)
 * PCI_D2         ((pci_power_t __force) 2)
 * PCI_D3hot      ((pci_power_t __force) 3)
 * PCI_D3cold     ((pci_power_t __force) 4)
 * PCI_UNKNOWN    ((pci_power_t __force) 5)

 * This function is called when system
 * goes into suspend state mac80211 will
 * call rtl_mac_stop() from the mac80211
 * suspend function first, So there is
 * no need to call hw_disable here.
 ****************************************/
```

## 3241. original/port-overlay/drivers/net/wireless/realtek/rtlwifi/pci.c:3296

Líneas 3296–3298; tipo `block`.

```text
/* Keep the physical line held across bus resume.  mac80211 op_start
	 * releases it only after hardware and RX configuration are complete.
	 */
```

## 3242. original/port-overlay/drivers/net/wireless/realtek/rtlwifi/pci.c:3306

Líneas 3306–3306; tipo `block`.

```text
/* CONFIG_PM_SLEEP */
```

## 3243. original/port-overlay/drivers/net/wireless/realtek/rtlwifi/rtl8192ee/fw.c:1

Líneas 1–1; tipo `line`.

```text
// SPDX-License-Identifier: GPL-2.0
```

## 3244. original/port-overlay/drivers/net/wireless/realtek/rtlwifi/rtl8192ee/fw.c:2

Líneas 2–2; tipo `block`.

```text
/* Copyright(c) 2009-2014  Realtek Corporation.*/
```

## 3245. original/port-overlay/drivers/net/wireless/realtek/rtlwifi/rtl8192ee/fw.c:64

Líneas 64–69; tipo `block`.

```text
/* The normal 92EE path only clears MCUFWDL_EN. After a warm RAM boot
	 * the page/checksum bytes can retain state (observed 0x00070600).
	 * Hold the download engine, clear its complete four-byte state, reset
	 * the 8051 through the vendor 92EE sequence, then clear FWDL once more
	 * before the single retry.
	 */
```

## 3246. original/port-overlay/drivers/net/wireless/realtek/rtlwifi/rtl8192ee/fw.c:218

Líneas 218–221; tipo `block`.

```text
/* Exactly one board-scoped retry, and only for the checksum timeout.
	 * A later WINTINI timeout or any non-MitraStar target keeps the upstream
	 * behavior and returns the original error without cleanup/retry.
	 */
```

## 3247. original/port-overlay/drivers/net/wireless/realtek/rtlwifi/rtl8192ee/fw.c:273

Líneas 273–275; tipo `block`.

```text
/* 1. Prevent race condition in setting H2C cmd.
	 * (copy from MgntActSet_RF_State().)
	 */
```

## 3248. original/port-overlay/drivers/net/wireless/realtek/rtlwifi/rtl8192ee/fw.c:306

Líneas 306–306; tipo `block`.

```text
/* 2. Find the last BOX number which has been writen. */
```

## 3249. original/port-overlay/drivers/net/wireless/realtek/rtlwifi/rtl8192ee/fw.c:331

Líneas 331–331; tipo `block`.

```text
/* 3. Check if the box content is empty. */
```

## 3250. original/port-overlay/drivers/net/wireless/realtek/rtlwifi/rtl8192ee/fw.c:364

Líneas 364–366; tipo `block`.

```text
/* If Fw has not read the last
		 * H2C cmd, break and give up this H2C.
		 */
```

## 3251. original/port-overlay/drivers/net/wireless/realtek/rtlwifi/rtl8192ee/fw.c:373

Líneas 373–373; tipo `block`.

```text
/* 4. Fill the H2C cmd into box */
```

## 3252. original/port-overlay/drivers/net/wireless/realtek/rtlwifi/rtl8192ee/fw.c:385

Líneas 385–385; tipo `block`.

```text
/*boxcontent[0] &= ~(BIT(7));*/
```

## 3253. original/port-overlay/drivers/net/wireless/realtek/rtlwifi/rtl8192ee/fw.c:398

Líneas 398–398; tipo `block`.

```text
/*boxcontent[0] |= (BIT(7));*/
```

## 3254. original/port-overlay/drivers/net/wireless/realtek/rtlwifi/rtl8192ee/fw.c:484

Líneas 484–484; tipo `block`.

```text
/* DTIM = (awake_intvl - 1) */
```

## 3255. original/port-overlay/drivers/net/wireless/realtek/rtlwifi/rtl8192ee/fw.c:509

Líneas 509–511; tipo `block`.

```text
/* hw->conf.ps_dtim_period or mac->vif->bss_conf.dtim_period
		 * is only used in swlps.
		 */
```

## 3256. original/port-overlay/drivers/net/wireless/realtek/rtlwifi/rtl8192ee/fw.c:533

Líneas 533–535; tipo `block`.

```text
/* Keep awake interval to 1 to prevent from
				 * decreasing coex performance
				 */
```

## 3257. original/port-overlay/drivers/net/wireless/realtek/rtlwifi/rtl8192ee/fw.c:570

Líneas 570–575; tipo `block`.

```text
/* parm[0]: bit0=0-->Disconnect, bit0=1-->Connect
	 *          bit1=0-->update Media Status to MACID
	 *          bit1=1-->update Media Status from MACID to MACID_End
	 * parm[1]: MACID, if this is INFRA_STA, MacID = 0
	 * parm[2]: MACID_End
	 */
```

## 3258. original/port-overlay/drivers/net/wireless/realtek/rtlwifi/rtl8192ee/fw.c:583

Líneas 583–583; tipo `block`.

```text
/* ->1 */
```

## 3259. original/port-overlay/drivers/net/wireless/realtek/rtlwifi/rtl8192ee/fw.c:586

Líneas 586–586; tipo `block`.

```text
/* ->5 */
```

## 3260. original/port-overlay/drivers/net/wireless/realtek/rtlwifi/rtl8192ee/fw.c:593

Líneas 593–593; tipo `block`.

```text
/* page 0 beacon */
```

## 3261. original/port-overlay/drivers/net/wireless/realtek/rtlwifi/rtl8192ee/fw.c:611

Líneas 611–611; tipo `block`.

```text
/* page 1 beacon */
```

## 3262. original/port-overlay/drivers/net/wireless/realtek/rtlwifi/rtl8192ee/fw.c:629

Líneas 629–629; tipo `block`.

```text
/* page 2  ps-poll */
```

## 3263. original/port-overlay/drivers/net/wireless/realtek/rtlwifi/rtl8192ee/fw.c:647

Líneas 647–647; tipo `block`.

```text
/* page 3  null */
```

## 3264. original/port-overlay/drivers/net/wireless/realtek/rtlwifi/rtl8192ee/fw.c:665

Líneas 665–665; tipo `block`.

```text
/* page 4  probe_resp */
```

## 3265. original/port-overlay/drivers/net/wireless/realtek/rtlwifi/rtl8192ee/fw.c:683

Líneas 683–683; tipo `block`.

```text
/* page 5  probe_resp */
```

## 3266. original/port-overlay/drivers/net/wireless/realtek/rtlwifi/rtl8192ee/fw.c:697

Líneas 697–697; tipo `block`.

```text
/* page 6 qos null data */
```

## 3267. original/port-overlay/drivers/net/wireless/realtek/rtlwifi/rtl8192ee/fw.c:715

Líneas 715–715; tipo `block`.

```text
/* page 7 BT-qos null data */
```

## 3268. original/port-overlay/drivers/net/wireless/realtek/rtlwifi/rtl8192ee/fw.c:754

Líneas 754–757; tipo `block`.

```text
/*---------------------------------------------------------
	 *			(1) beacon
	 *---------------------------------------------------------
	 */
```

## 3269. original/port-overlay/drivers/net/wireless/realtek/rtlwifi/rtl8192ee/fw.c:762

Líneas 762–765; tipo `block`.

```text
/*-------------------------------------------------------
	 *			(2) ps-poll
	 *--------------------------------------------------------
	 */
```

## 3270. original/port-overlay/drivers/net/wireless/realtek/rtlwifi/rtl8192ee/fw.c:773

Líneas 773–776; tipo `block`.

```text
/*--------------------------------------------------------
	 *			(3) null data
	 *---------------------------------------------------------
	 */
```

## 3271. original/port-overlay/drivers/net/wireless/realtek/rtlwifi/rtl8192ee/fw.c:784

Líneas 784–787; tipo `block`.

```text
/*---------------------------------------------------------
	 *			(4) probe response
	 *----------------------------------------------------------
	 */
```

## 3272. original/port-overlay/drivers/net/wireless/realtek/rtlwifi/rtl8192ee/fw.c:795

Líneas 795–798; tipo `block`.

```text
/*---------------------------------------------------------
	 *			(5) QoS null data
	 *----------------------------------------------------------
	 */
```

## 3273. original/port-overlay/drivers/net/wireless/realtek/rtlwifi/rtl8192ee/fw.c:806

Líneas 806–809; tipo `block`.

```text
/*---------------------------------------------------------
	 *			(6) BT QoS null data
	 *----------------------------------------------------------
	 */
```

## 3274. original/port-overlay/drivers/net/wireless/realtek/rtlwifi/rtl8192ee/fw.c:848

Líneas 848–848; tipo `block`.

```text
/*Shoud check FW support p2p or not.*/
```

## 3275. original/port-overlay/drivers/net/wireless/realtek/rtlwifi/rtl8192ee/fw.c:874

Líneas 874–874; tipo `block`.

```text
/* update CTWindow value. */
```

## 3276. original/port-overlay/drivers/net/wireless/realtek/rtlwifi/rtl8192ee/fw.c:880

Líneas 880–880; tipo `block`.

```text
/* hw only support 2 set of NoA */
```

## 3277. original/port-overlay/drivers/net/wireless/realtek/rtlwifi/rtl8192ee/fw.c:882

Líneas 882–882; tipo `block`.

```text
/* To control the register setting for which NOA*/
```

## 3278. original/port-overlay/drivers/net/wireless/realtek/rtlwifi/rtl8192ee/fw.c:888

Líneas 888–888; tipo `block`.

```text
/* config P2P NoA Descriptor Register */
```

## 3279. original/port-overlay/drivers/net/wireless/realtek/rtlwifi/rtl8192ee/fw.c:894

Líneas 894–894; tipo `block`.

```text
/*Get Current TSF value */
```

## 3280. original/port-overlay/drivers/net/wireless/realtek/rtlwifi/rtl8192ee/fw.c:910

Líneas 910–910; tipo `block`.

```text
/* rst p2p circuit */
```

## 3281. original/port-overlay/drivers/net/wireless/realtek/rtlwifi/rtl8192ee/trx.c:1

Líneas 1–1; tipo `line`.

```text
// SPDX-License-Identifier: GPL-2.0
```

## 3282. original/port-overlay/drivers/net/wireless/realtek/rtlwifi/rtl8192ee/trx.c:2

Líneas 2–2; tipo `block`.

```text
/* Copyright(c) 2009-2014  Realtek Corporation.*/
```

## 3283. original/port-overlay/drivers/net/wireless/realtek/rtlwifi/rtl8192ee/trx.c:114

Líneas 114–117; tipo `block`.

```text
/* Live AP traffic has used MACID 2.  Query the RX descriptor MACID first
	 * and keep MACID 2 as a second-slot fallback when they differ.  The OEM
	 * command supports two stations and 0xff means unused.
	 */
```

## 3284. original/port-overlay/drivers/net/wireless/realtek/rtlwifi/rtl8192ee/trx.c:290

Líneas 290–293; tipo `block`.

```text
/* Probe traffic can be noisy enough to consume a shared trace budget
	 * before a client starts AUTH/ASSOC. Keep an independent bounded counter
	 * for every subtype so the first join attempt is always observable.
	 */
```

## 3285. original/port-overlay/drivers/net/wireless/realtek/rtlwifi/rtl8192ee/trx.c:374

Líneas 374–374; tipo `block`.

```text
/* Record it for next packet processing */
```

## 3286. original/port-overlay/drivers/net/wireless/realtek/rtlwifi/rtl8192ee/trx.c:384

Líneas 384–384; tipo `block`.

```text
/* CCK Driver info Structure is not the same as OFDM packet. */
```

## 3287. original/port-overlay/drivers/net/wireless/realtek/rtlwifi/rtl8192ee/trx.c:387

Líneas 387–390; tipo `block`.

```text
/* (1)Hardware does not provide RSSI for CCK
		 * (2)PWDB, Average PWDB cacluated by
		 * hardware (for rate adaptive)
		 */
```

## 3288. original/port-overlay/drivers/net/wireless/realtek/rtlwifi/rtl8192ee/trx.c:397

Líneas 397–397; tipo `block`.

```text
/*VGA_idx = 27~2*/
```

## 3289. original/port-overlay/drivers/net/wireless/realtek/rtlwifi/rtl8192ee/trx.c:403

Líneas 403–403; tipo `block`.

```text
/*VGA_idx = 2~0*/
```

## 3290. original/port-overlay/drivers/net/wireless/realtek/rtlwifi/rtl8192ee/trx.c:406

Líneas 406–406; tipo `block`.

```text
/*VGA_idx = 7~5*/
```

## 3291. original/port-overlay/drivers/net/wireless/realtek/rtlwifi/rtl8192ee/trx.c:409

Líneas 409–409; tipo `block`.

```text
/*VGA_idx = 7~4*/
```

## 3292. original/port-overlay/drivers/net/wireless/realtek/rtlwifi/rtl8192ee/trx.c:412

Líneas 412–412; tipo `block`.

```text
/*VGA_idx = 7~0*/
```

## 3293. original/port-overlay/drivers/net/wireless/realtek/rtlwifi/rtl8192ee/trx.c:415

Líneas 415–415; tipo `block`.

```text
/*VGA_idx = 5~0*/
```

## 3294. original/port-overlay/drivers/net/wireless/realtek/rtlwifi/rtl8192ee/trx.c:448

Líneas 448–448; tipo `block`.

```text
/* (3) Get Signal Quality (EVM) */
```

## 3295. original/port-overlay/drivers/net/wireless/realtek/rtlwifi/rtl8192ee/trx.c:469

Líneas 469–469; tipo `block`.

```text
/* (1)Get RSSI for HT rate */
```

## 3296. original/port-overlay/drivers/net/wireless/realtek/rtlwifi/rtl8192ee/trx.c:471

Líneas 471–471; tipo `block`.

```text
/* we will judge RF RX path now. */
```

## 3297. original/port-overlay/drivers/net/wireless/realtek/rtlwifi/rtl8192ee/trx.c:479

Líneas 479–479; tipo `block`.

```text
/* Translate DBM to percentage. */
```

## 3298. original/port-overlay/drivers/net/wireless/realtek/rtlwifi/rtl8192ee/trx.c:486

Líneas 486–488; tipo `block`.

```text
/* (2)PWDB, Average PWDB cacluated by
		 * hardware (for rate adaptive)
		 */
```

## 3299. original/port-overlay/drivers/net/wireless/realtek/rtlwifi/rtl8192ee/trx.c:498

Líneas 498–498; tipo `block`.

```text
/* (3)EVM of HT rate */
```

## 3300. original/port-overlay/drivers/net/wireless/realtek/rtlwifi/rtl8192ee/trx.c:510

Líneas 510–512; tipo `block`.

```text
/* Fill value in RFD, Get the first
				 * spatial stream only
				 */
```

## 3301. original/port-overlay/drivers/net/wireless/realtek/rtlwifi/rtl8192ee/trx.c:533

Líneas 533–535; tipo `block`.

```text
/* UI BSS List signal strength(in percentage),
	 * make it good looking, from 0~100.
	 */
```

## 3302. original/port-overlay/drivers/net/wireless/realtek/rtlwifi/rtl8192ee/trx.c:709

Líneas 709–712; tipo `block`.

```text
/* C2H packets are firmware records, not 802.11 frames.  The generic RX
	 * path consumes them after query_rx_desc(); return before interpreting
	 * their short payload as frame_control or PHY data on the ARC target.
	 */
```

## 3303. original/port-overlay/drivers/net/wireless/realtek/rtlwifi/rtl8192ee/trx.c:760

Líneas 760–767; tipo `block`.

```text
/* hw will set status->decrypted true, if it finds the
	 * frame is open data frame or mgmt frame.
	 * So hw will not decryption robust managment frame
	 * for IEEE80211w but still set status->decrypted
	 * true, so here we should set it back to undecrypted
	 * for IEEE80211w frame, and mac80211 sw will help
	 * to decrypt it
	 */
```

## 3304. original/port-overlay/drivers/net/wireless/realtek/rtlwifi/rtl8192ee/trx.c:775

Líneas 775–779; tipo `block`.

```text
/* rate_idx: index of data rate into band's
	 * supported rates or MCS index if HT rates
	 * are use (RX_FLAG_HT)
	 * Notice: this is diff with windows define
	 */
```

## 3305. original/port-overlay/drivers/net/wireless/realtek/rtlwifi/rtl8192ee/trx.c:823

Líneas 823–823; tipo `block`.

```text
/*in Windows, this == Rx_92EE_Interrupt*/
```

## 3306. original/port-overlay/drivers/net/wireless/realtek/rtlwifi/rtl8192ee/trx.c:955

Líneas 955–955; tipo `block`.

```text
/*tx desc size*/
```

## 3307. original/port-overlay/drivers/net/wireless/realtek/rtlwifi/rtl8192ee/trx.c:997

Líneas 997–1000; tipo `block`.

```text
/* OEM hdrLen includes LLC.  mac80211 Ethernet data normally
			 * carries an RFC1042/802.1H SNAP header immediately after the
			 * 802.11 header; keep those eight bytes in TXBD element 1.
			 */
```

## 3308. original/port-overlay/drivers/net/wireless/realtek/rtlwifi/rtl8192ee/trx.c:1019

Líneas 1019–1019; tipo `block`.

```text
/* tx desc addr */
```

## 3309. original/port-overlay/drivers/net/wireless/realtek/rtlwifi/rtl8192ee/trx.c:1028

Líneas 1028–1034; tipo `block`.

```text
/* OEM DMA32 layout: four 8-byte segments in one 0x20-byte TXBD.
		 * Segment 0 points at the 0x28-byte TX descriptor. The vendor AP
		 * path uses segment 1 for the 802.11 header and segment 2 for the
		 * remaining body; preserve that split for management frames when
		 * explicitly enabled. Other traffic keeps the proven single-buffer
		 * layout while this A/B remains diagnostic.
		 */
```

## 3310. original/port-overlay/drivers/net/wireless/realtek/rtlwifi/rtl8192ee/trx.c:1072

Líneas 1072–1072; tipo `block`.

```text
/* Reset */
```

## 3311. original/port-overlay/drivers/net/wireless/realtek/rtlwifi/rtl8192ee/trx.c:1084

Líneas 1084–1084; tipo `block`.

```text
/* Clear all status */
```

## 3312. original/port-overlay/drivers/net/wireless/realtek/rtlwifi/rtl8192ee/trx.c:1089

Líneas 1089–1089; tipo `block`.

```text
/* This if needs braces */
```

## 3313. original/port-overlay/drivers/net/wireless/realtek/rtlwifi/rtl8192ee/trx.c:1122

Líneas 1122–1122; tipo `block`.

```text
/* don't using extendsion mode. */
```

## 3314. original/port-overlay/drivers/net/wireless/realtek/rtlwifi/rtl8192ee/trx.c:1169

Líneas 1169–1169; tipo `block`.

```text
/* reserve 8 byte for AMPDU early mode */
```

## 3315. original/port-overlay/drivers/net/wireless/realtek/rtlwifi/rtl8192ee/trx.c:1341

Líneas 1341–1341; tipo `block`.

```text
/*set_tx_desc_pwr_status(pdesc, pwr_status);*/
```

## 3316. original/port-overlay/drivers/net/wireless/realtek/rtlwifi/rtl8192ee/trx.c:1342

Líneas 1342–1342; tipo `block`.

```text
/* Set TxRate and RTSRate in TxDesc  */
```

## 3317. original/port-overlay/drivers/net/wireless/realtek/rtlwifi/rtl8192ee/trx.c:1343

Líneas 1343–1343; tipo `block`.

```text
/* This prevent Tx initial rate of new-coming packets */
```

## 3318. original/port-overlay/drivers/net/wireless/realtek/rtlwifi/rtl8192ee/trx.c:1344

Líneas 1344–1344; tipo `block`.

```text
/* from being overwritten by retried  packet rate.*/
```

## 3319. original/port-overlay/drivers/net/wireless/realtek/rtlwifi/rtl8192ee/trx.c:1346

Líneas 1346–1346; tipo `block`.

```text
/*set_tx_desc_rts_rate(pdesc, 0x08); */
```

## 3320. original/port-overlay/drivers/net/wireless/realtek/rtlwifi/rtl8192ee/trx.c:1347

Líneas 1347–1347; tipo `block`.

```text
/* set_tx_desc_tx_rate(pdesc, 0x0b); */
```

## 3321. original/port-overlay/drivers/net/wireless/realtek/rtlwifi/rtl8192ee/trx.c:1357

Líneas 1357–1357; tipo `block`.

```text
/* tx report */
```

## 3322. original/port-overlay/drivers/net/wireless/realtek/rtlwifi/rtl8192ee/trx.c:1528

Líneas 1528–1528; tipo `block`.

```text
/* make sure tx desc is available by caller */
```

## 3323. original/port-overlay/drivers/net/wireless/realtek/rtlwifi/rtl8192ee/trx.c:1650

Líneas 1650–1650; tipo `block`.

```text
/* don't need to update ring->cur_tx_wp */
```

## 3324. original/port-overlay/drivers/net/wireless/realtek/rtlwifi/rtl8192ee/trx.c:1658

Líneas 1658–1661; tipo `block`.

```text
/* OEM SyncSWTXBDHostIdxToHW88XX/tx_recycle semantics: HW RP is
	 * the next descriptor still owned by hardware. index == HW RP is not
	 * reclaimable, including the full-minus-one state WP == RP - 1.
	 */
```

## 3325. original/port-overlay/drivers/net/wireless/realtek/rtlwifi/rtl8192ee/trx.c:1726

Líneas 1726–1728; tipo `block`.

```text
/* The 92EE new-flow queues ring their index register from set_desc(),
	 * except BCNQ: its fixed descriptor 0 is downloaded by PCIe poll bit 4.
	 */
```

## 3326. original/port-overlay/drivers/net/wireless/realtek/rtlwifi/rtl8192ee/trx.h:1

Líneas 1–1; tipo `block`.

```text
/* SPDX-License-Identifier: GPL-2.0 */
```

## 3327. original/port-overlay/drivers/net/wireless/realtek/rtlwifi/rtl8192ee/trx.h:2

Líneas 2–2; tipo `block`.

```text
/* Copyright(c) 2009-2014  Realtek Corporation.*/
```

## 3328. original/port-overlay/drivers/net/wireless/realtek/rtlwifi/rtl8192ee/trx.h:142

Líneas 142–142; tipo `block`.

```text
/* Dword 4 */
```

## 3329. original/port-overlay/drivers/net/wireless/realtek/rtlwifi/rtl8192ee/trx.h:168

Líneas 168–168; tipo `block`.

```text
/* Dword 5 */
```

## 3330. original/port-overlay/drivers/net/wireless/realtek/rtlwifi/rtl8192ee/trx.h:189

Líneas 189–189; tipo `block`.

```text
/* Dword 7 */
```

## 3331. original/port-overlay/drivers/net/wireless/realtek/rtlwifi/rtl8192ee/trx.h:195

Líneas 195–195; tipo `block`.

```text
/* Dword 9 */
```

## 3332. original/port-overlay/drivers/net/wireless/realtek/rtlwifi/rtl8192ee/trx.h:201

Líneas 201–201; tipo `block`.

```text
/* Dword 10 */
```

## 3333. original/port-overlay/drivers/net/wireless/realtek/rtlwifi/rtl8192ee/trx.h:207

Líneas 207–207; tipo `block`.

```text
/* Dword 11*/
```

## 3334. original/port-overlay/drivers/net/wireless/realtek/rtlwifi/rtl8192ee/trx.h:248

Líneas 248–248; tipo `block`.

```text
/* TX/RX buffer descriptor */
```

## 3335. original/port-overlay/drivers/net/wireless/realtek/rtlwifi/rtl8192ee/trx.h:250

Líneas 250–250; tipo `block`.

```text
/* for Txfilldescroptor92ee, fill the desc content. */
```

## 3336. original/port-overlay/drivers/net/wireless/realtek/rtlwifi/rtl8192ee/trx.h:292

Líneas 292–292; tipo `block`.

```text
/* Dword 0 */
```

## 3337. original/port-overlay/drivers/net/wireless/realtek/rtlwifi/rtl8192ee/trx.h:308

Líneas 308–308; tipo `block`.

```text
/* Dword 1 */
```

## 3338. original/port-overlay/drivers/net/wireless/realtek/rtlwifi/rtl8192ee/trx.h:314

Líneas 314–314; tipo `block`.

```text
/* Dword 2 */
```

## 3339. original/port-overlay/drivers/net/wireless/realtek/rtlwifi/rtl8192ee/trx.h:324

Líneas 324–324; tipo `block`.

```text
/* RX buffer  */
```

## 3340. original/port-overlay/drivers/net/wireless/realtek/rtlwifi/rtl8192ee/trx.h:326

Líneas 326–326; tipo `block`.

```text
/* DWORD 0 */
```

## 3341. original/port-overlay/drivers/net/wireless/realtek/rtlwifi/rtl8192ee/trx.h:362

Líneas 362–362; tipo `block`.

```text
/* DWORD 1 */
```

## 3342. original/port-overlay/drivers/net/wireless/realtek/rtlwifi/rtl8192ee/trx.h:368

Líneas 368–368; tipo `block`.

```text
/* DWORD 2 */
```

## 3343. original/port-overlay/drivers/net/wireless/realtek/rtlwifi/rtl8192ee/trx.h:488

Líneas 488–488; tipo `block`.

```text
/* TX report 2 format in Rx desc*/
```

## 3344. original/port-overlay/drivers/net/wireless/realtek/rtlwifi/rtl8192ee/trx.h:543

Líneas 543–543; tipo `block`.

```text
/*ex_intf_flg:1;*/
```

## 3345. original/port-overlay/drivers/net/wireless/realtek/rtlwifi/rtl8192ee/trx.h:550

Líneas 550–550; tipo `block`.

```text
/* _BIG_ENDIAN_	*/
```

## 3346. original/port-overlay/drivers/net/wireless/realtek/rtlwifi/rtl8192ee/trx.h:557

Líneas 557–557; tipo `block`.

```text
/*ex_intf_flg:1;*/
```

## 3347. original/port-overlay/drivers/net/wireless/realtek/rtlwifi/wifi.h:1

Líneas 1–1; tipo `block`.

```text
/* SPDX-License-Identifier: GPL-2.0 */
```

## 3348. original/port-overlay/drivers/net/wireless/realtek/rtlwifi/wifi.h:2

Líneas 2–2; tipo `block`.

```text
/* Copyright(c) 2009-2012  Realtek Corporation.*/
```

## 3349. original/port-overlay/drivers/net/wireless/realtek/rtlwifi/wifi.h:64

Líneas 64–64; tipo `block`.

```text
/* QoS related. */
```

## 3350. original/port-overlay/drivers/net/wireless/realtek/rtlwifi/wifi.h:65

Líneas 65–65; tipo `block`.

```text
/*aci: 0x00	Best Effort*/
```

## 3351. original/port-overlay/drivers/net/wireless/realtek/rtlwifi/wifi.h:66

Líneas 66–66; tipo `block`.

```text
/*aci: 0x01	Background*/
```

## 3352. original/port-overlay/drivers/net/wireless/realtek/rtlwifi/wifi.h:67

Líneas 67–67; tipo `block`.

```text
/*aci: 0x10	Video*/
```

## 3353. original/port-overlay/drivers/net/wireless/realtek/rtlwifi/wifi.h:68

Líneas 68–68; tipo `block`.

```text
/*aci: 0x11	Voice*/
```

## 3354. original/port-overlay/drivers/net/wireless/realtek/rtlwifi/wifi.h:69

Líneas 69–69; tipo `block`.

```text
/*Max: define total number.*/
```

## 3355. original/port-overlay/drivers/net/wireless/realtek/rtlwifi/wifi.h:85

Líneas 85–85; tipo `block`.

```text
/*slot time for 11g. */
```

## 3356. original/port-overlay/drivers/net/wireless/realtek/rtlwifi/wifi.h:89

Líneas 89–89; tipo `block`.

```text
/*related to tcp/ip. */
```

## 3357. original/port-overlay/drivers/net/wireless/realtek/rtlwifi/wifi.h:93

Líneas 93–93; tipo `block`.

```text
/*related with 802.11 frame*/
```

## 3358. original/port-overlay/drivers/net/wireless/realtek/rtlwifi/wifi.h:97

Líneas 97–97; tipo `block`.

```text
/* 14 is the max channel no */
```

## 3359. original/port-overlay/drivers/net/wireless/realtek/rtlwifi/wifi.h:99

Líneas 99–102; tipo `block`.

```text
/* Please refer to
					    *"phy_GetChnlGroup8812A" and
					    * "Hal_ReadTxPowerInfo8812A"
					    */
```

## 3360. original/port-overlay/drivers/net/wireless/realtek/rtlwifi/wifi.h:104

Líneas 104–104; tipo `block`.

```text
/*  ch1~3, 4~9, 10~14 = three groups */
```

## 3361. original/port-overlay/drivers/net/wireless/realtek/rtlwifi/wifi.h:116

Líneas 116–116; tipo `block`.

```text
/* for early mode */
```

## 3362. original/port-overlay/drivers/net/wireless/realtek/rtlwifi/wifi.h:173

Líneas 173–173; tipo `block`.

```text
/* = MAX_RATE_SECTION */
```

## 3363. original/port-overlay/drivers/net/wireless/realtek/rtlwifi/wifi.h:183

Líneas 183–183; tipo `block`.

```text
/* >= TX_PWR_BY_RATE_NUM_SECTION */
```

## 3364. original/port-overlay/drivers/net/wireless/realtek/rtlwifi/wifi.h:184

Líneas 184–184; tipo `block`.

```text
/* MAX_RATE_SECTION */
```

## 3365. original/port-overlay/drivers/net/wireless/realtek/rtlwifi/wifi.h:185

Líneas 185–185; tipo `block`.

```text
/* MAX_RATE_SECTION -1 */
```

## 3366. original/port-overlay/drivers/net/wireless/realtek/rtlwifi/wifi.h:187

Líneas 187–187; tipo `block`.

```text
/* 0:2 seg, 1: 4 seg, 2: 8 seg */
```

## 3367. original/port-overlay/drivers/net/wireless/realtek/rtlwifi/wifi.h:191

Líneas 191–193; tipo `block`.

```text
/* For now, it's just for 8192ee
 * but not OK yet, keep it 0
 */
```

## 3368. original/port-overlay/drivers/net/wireless/realtek/rtlwifi/wifi.h:214

Líneas 214–214; tipo `block`.

```text
/* MIN LEN keeps 13 here */
```

## 3369. original/port-overlay/drivers/net/wireless/realtek/rtlwifi/wifi.h:255

Líneas 255–255; tipo `block`.

```text
/*If only one tx, only BW20 and OFDM are used.*/
```

## 3370. original/port-overlay/drivers/net/wireless/realtek/rtlwifi/wifi.h:266

Líneas 266–266; tipo `block`.

```text
/*If only one tx, only BW20, OFDM, BW80 and BW160 are used.*/
```

## 3371. original/port-overlay/drivers/net/wireless/realtek/rtlwifi/wifi.h:340

Líneas 340–340; tipo `block`.

```text
/* keep it last */
```

## 3372. original/port-overlay/drivers/net/wireless/realtek/rtlwifi/wifi.h:376

Líneas 376–376; tipo `block`.

```text
/*RF state.*/
```

## 3373. original/port-overlay/drivers/net/wireless/realtek/rtlwifi/wifi.h:400

Líneas 400–400; tipo `block`.

```text
/* rflssi_readback */
```

## 3374. original/port-overlay/drivers/net/wireless/realtek/rtlwifi/wifi.h:401

Líneas 401–401; tipo `block`.

```text
/* rflssi_readbackpi */
```

## 3375. original/port-overlay/drivers/net/wireless/realtek/rtlwifi/wifi.h:600

Líneas 600–602; tipo `block`.

```text
/* Ref: 802.11i spec D10.0 7.3.2.25.1
 * Cipher Suites Encryption Algorithms
 */
```

## 3376. original/port-overlay/drivers/net/wireless/realtek/rtlwifi/wifi.h:610

Líneas 610–610; tipo `block`.

```text
/*IEEE802.11w */
```

## 3377. original/port-overlay/drivers/net/wireless/realtek/rtlwifi/wifi.h:675

Líneas 675–675; tipo `block`.

```text
/*reg map */
```

## 3378. original/port-overlay/drivers/net/wireless/realtek/rtlwifi/wifi.h:688

Líneas 688–688; tipo `block`.

```text
/*efuse map */
```

## 3379. original/port-overlay/drivers/net/wireless/realtek/rtlwifi/wifi.h:703

Líneas 703–703; tipo `block`.

```text
/*CAM map */
```

## 3380. original/port-overlay/drivers/net/wireless/realtek/rtlwifi/wifi.h:715

Líneas 715–715; tipo `block`.

```text
/*IMR map */
```

## 3381. original/port-overlay/drivers/net/wireless/realtek/rtlwifi/wifi.h:716

Líneas 716–716; tipo `block`.

```text
/*Beacon DMA Interrupt 6 */
```

## 3382. original/port-overlay/drivers/net/wireless/realtek/rtlwifi/wifi.h:717

Líneas 717–717; tipo `block`.

```text
/*Beacon DMA Interrupt 5 */
```

## 3383. original/port-overlay/drivers/net/wireless/realtek/rtlwifi/wifi.h:718

Líneas 718–718; tipo `block`.

```text
/*Beacon DMA Interrupt 4 */
```

## 3384. original/port-overlay/drivers/net/wireless/realtek/rtlwifi/wifi.h:719

Líneas 719–719; tipo `block`.

```text
/*Beacon DMA Interrupt 3 */
```

## 3385. original/port-overlay/drivers/net/wireless/realtek/rtlwifi/wifi.h:720

Líneas 720–720; tipo `block`.

```text
/*Beacon DMA Interrupt 2 */
```

## 3386. original/port-overlay/drivers/net/wireless/realtek/rtlwifi/wifi.h:721

Líneas 721–721; tipo `block`.

```text
/*Beacon DMA Interrupt 1 */
```

## 3387. original/port-overlay/drivers/net/wireless/realtek/rtlwifi/wifi.h:722

Líneas 722–722; tipo `block`.

```text
/*Beacon Queue DMA OK Interrup 8 */
```

## 3388. original/port-overlay/drivers/net/wireless/realtek/rtlwifi/wifi.h:723

Líneas 723–723; tipo `block`.

```text
/*Beacon Queue DMA OK Interrup 7 */
```

## 3389. original/port-overlay/drivers/net/wireless/realtek/rtlwifi/wifi.h:724

Líneas 724–724; tipo `block`.

```text
/*Beacon Queue DMA OK Interrup 6 */
```

## 3390. original/port-overlay/drivers/net/wireless/realtek/rtlwifi/wifi.h:725

Líneas 725–725; tipo `block`.

```text
/*Beacon Queue DMA OK Interrup 5 */
```

## 3391. original/port-overlay/drivers/net/wireless/realtek/rtlwifi/wifi.h:726

Líneas 726–726; tipo `block`.

```text
/*Beacon Queue DMA OK Interrup 4 */
```

## 3392. original/port-overlay/drivers/net/wireless/realtek/rtlwifi/wifi.h:727

Líneas 727–727; tipo `block`.

```text
/*Beacon Queue DMA OK Interrup 3 */
```

## 3393. original/port-overlay/drivers/net/wireless/realtek/rtlwifi/wifi.h:728

Líneas 728–728; tipo `block`.

```text
/*Beacon Queue DMA OK Interrup 2 */
```

## 3394. original/port-overlay/drivers/net/wireless/realtek/rtlwifi/wifi.h:729

Líneas 729–729; tipo `block`.

```text
/*Beacon Queue DMA OK Interrup 1 */
```

## 3395. original/port-overlay/drivers/net/wireless/realtek/rtlwifi/wifi.h:730

Líneas 730–730; tipo `block`.

```text
/*Timeout interrupt 2 */
```

## 3396. original/port-overlay/drivers/net/wireless/realtek/rtlwifi/wifi.h:731

Líneas 731–731; tipo `block`.

```text
/*Timeout interrupt 1 */
```

## 3397. original/port-overlay/drivers/net/wireless/realtek/rtlwifi/wifi.h:732

Líneas 732–732; tipo `block`.

```text
/*Transmit FIFO Overflow */
```

## 3398. original/port-overlay/drivers/net/wireless/realtek/rtlwifi/wifi.h:733

Líneas 733–733; tipo `block`.

```text
/*Power save time out interrupt */
```

## 3399. original/port-overlay/drivers/net/wireless/realtek/rtlwifi/wifi.h:734

Líneas 734–734; tipo `block`.

```text
/*Beacon DMA Interrupt 0 */
```

## 3400. original/port-overlay/drivers/net/wireless/realtek/rtlwifi/wifi.h:735

Líneas 735–735; tipo `block`.

```text
/*Receive FIFO Overflow */
```

## 3401. original/port-overlay/drivers/net/wireless/realtek/rtlwifi/wifi.h:736

Líneas 736–736; tipo `block`.

```text
/*Receive Descriptor Unavailable */
```

## 3402. original/port-overlay/drivers/net/wireless/realtek/rtlwifi/wifi.h:737

Líneas 737–737; tipo `block`.

```text
/*For 92C,ATIM Window End Interrupt */
```

## 3403. original/port-overlay/drivers/net/wireless/realtek/rtlwifi/wifi.h:738

Líneas 738–738; tipo `block`.

```text
/*H2C Queue DMA OK Interrupt */
```

## 3404. original/port-overlay/drivers/net/wireless/realtek/rtlwifi/wifi.h:739

Líneas 739–739; tipo `block`.

```text
/*Beacon Queue DMA OK Interrup */
```

## 3405. original/port-overlay/drivers/net/wireless/realtek/rtlwifi/wifi.h:740

Líneas 740–740; tipo `block`.

```text
/*High Queue DMA OK Interrupt */
```

## 3406. original/port-overlay/drivers/net/wireless/realtek/rtlwifi/wifi.h:741

Líneas 741–741; tipo `block`.

```text
/*Command Queue DMA OK Interrupt*/
```

## 3407. original/port-overlay/drivers/net/wireless/realtek/rtlwifi/wifi.h:742

Líneas 742–742; tipo `block`.

```text
/*Transmit Beacon OK interrup */
```

## 3408. original/port-overlay/drivers/net/wireless/realtek/rtlwifi/wifi.h:743

Líneas 743–743; tipo `block`.

```text
/*Management Queue DMA OK Interrupt */
```

## 3409. original/port-overlay/drivers/net/wireless/realtek/rtlwifi/wifi.h:744

Líneas 744–744; tipo `block`.

```text
/*For 92C,Transmit Beacon Error Interrupt */
```

## 3410. original/port-overlay/drivers/net/wireless/realtek/rtlwifi/wifi.h:745

Líneas 745–745; tipo `block`.

```text
/*AC_BK DMA OK Interrupt */
```

## 3411. original/port-overlay/drivers/net/wireless/realtek/rtlwifi/wifi.h:746

Líneas 746–746; tipo `block`.

```text
/*AC_BE DMA OK Interrupt */
```

## 3412. original/port-overlay/drivers/net/wireless/realtek/rtlwifi/wifi.h:747

Líneas 747–747; tipo `block`.

```text
/*AC_VI DMA OK Interrupt */
```

## 3413. original/port-overlay/drivers/net/wireless/realtek/rtlwifi/wifi.h:748

Líneas 748–748; tipo `block`.

```text
/*AC_VO DMA Interrupt */
```

## 3414. original/port-overlay/drivers/net/wireless/realtek/rtlwifi/wifi.h:749

Líneas 749–749; tipo `block`.

```text
/*Receive DMA OK Interrupt */
```

## 3415. original/port-overlay/drivers/net/wireless/realtek/rtlwifi/wifi.h:750

Líneas 750–750; tipo `block`.

```text
/*HSISR Interrupt*/
```

## 3416. original/port-overlay/drivers/net/wireless/realtek/rtlwifi/wifi.h:751

Líneas 751–753; tipo `block`.

```text
/*(RTL_IMR_BCNINT | RTL_IMR_TBDOK |
				 * RTL_IMR_TBDER)
				 */
```

## 3417. original/port-overlay/drivers/net/wireless/realtek/rtlwifi/wifi.h:754

Líneas 754–754; tipo `block`.

```text
/*fw interrupt*/
```

## 3418. original/port-overlay/drivers/net/wireless/realtek/rtlwifi/wifi.h:756

Líneas 756–756; tipo `block`.

```text
/*CCK Rates, TxHT = 0 */
```

## 3419. original/port-overlay/drivers/net/wireless/realtek/rtlwifi/wifi.h:762

Líneas 762–762; tipo `block`.

```text
/*OFDM Rates, TxHT = 0 */
```

## 3420. original/port-overlay/drivers/net/wireless/realtek/rtlwifi/wifi.h:782

Líneas 782–782; tipo `block`.

```text
/*keep it last */
```

## 3421. original/port-overlay/drivers/net/wireless/realtek/rtlwifi/wifi.h:786

Líneas 786–786; tipo `block`.

```text
/*Firmware PS mode for control LPS.*/
```

## 3422. original/port-overlay/drivers/net/wireless/realtek/rtlwifi/wifi.h:802

Líneas 802–802; tipo `block`.

```text
/*Active/Continuous access. */
```

## 3423. original/port-overlay/drivers/net/wireless/realtek/rtlwifi/wifi.h:803

Líneas 803–803; tipo `block`.

```text
/*Max power save mode. */
```

## 3424. original/port-overlay/drivers/net/wireless/realtek/rtlwifi/wifi.h:804

Líneas 804–804; tipo `block`.

```text
/*Fast power save mode. */
```

## 3425. original/port-overlay/drivers/net/wireless/realtek/rtlwifi/wifi.h:805

Líneas 805–805; tipo `block`.

```text
/*Auto power save mode. */
```

## 3426. original/port-overlay/drivers/net/wireless/realtek/rtlwifi/wifi.h:808

Líneas 808–808; tipo `block`.

```text
/*LED related.*/
```

## 3427. original/port-overlay/drivers/net/wireless/realtek/rtlwifi/wifi.h:829

Líneas 829–829; tipo `block`.

```text
/*QoS related.*/
```

## 3428. original/port-overlay/drivers/net/wireless/realtek/rtlwifi/wifi.h:830

Líneas 830–830; tipo `block`.

```text
/*acm implementation method.*/
```

## 3429. original/port-overlay/drivers/net/wireless/realtek/rtlwifi/wifi.h:850

Líneas 850–852; tipo `block`.

```text
/* aci/aifsn Field.
 * Ref: WMM spec 2.2.2: WME Parameter Element, p.12.
 */
```

## 3430. original/port-overlay/drivers/net/wireless/realtek/rtlwifi/wifi.h:861

Líneas 861–861; tipo `block`.

```text
/* Field */
```

## 3431. original/port-overlay/drivers/net/wireless/realtek/rtlwifi/wifi.h:864

Líneas 864–864; tipo `block`.

```text
/*mlme related.*/
```

## 3432. original/port-overlay/drivers/net/wireless/realtek/rtlwifi/wifi.h:948

Líneas 948–948; tipo `block`.

```text
/* After 8188E, we use V2 reason define. 88C/8723A use V1 reason. */
```

## 3433. original/port-overlay/drivers/net/wireless/realtek/rtlwifi/wifi.h:981

Líneas 981–981; tipo `block`.

```text
/* use ratr_table_mode_new */
```

## 3434. original/port-overlay/drivers/net/wireless/realtek/rtlwifi/wifi.h:982

Líneas 982–982; tipo `block`.

```text
/* support VHT */
```

## 3435. original/port-overlay/drivers/net/wireless/realtek/rtlwifi/wifi.h:983

Líneas 983–983; tipo `block`.

```text
/* extend FW C2H (e.g. TX REPORT) */
```

## 3436. original/port-overlay/drivers/net/wireless/realtek/rtlwifi/wifi.h:1067

Líneas 1067–1069; tipo `block`.

```text
/*SSID, supported rates, FH params, DS params,
	 * CF params, IBSS params, TIM (if beacon), RSN
	 */
```

## 3437. original/port-overlay/drivers/net/wireless/realtek/rtlwifi/wifi.h:1073

Líneas 1073–1073; tipo `block`.

```text
/*LED related.*/
```

## 3438. original/port-overlay/drivers/net/wireless/realtek/rtlwifi/wifi.h:1074

Líneas 1074–1074; tipo `block`.

```text
/*ledpin Identify how to implement this SW led.*/
```

## 3439. original/port-overlay/drivers/net/wireless/realtek/rtlwifi/wifi.h:1096

Líneas 1096–1096; tipo `block`.

```text
/*array to store values */
```

## 3440. original/port-overlay/drivers/net/wireless/realtek/rtlwifi/wifi.h:1097

Líneas 1097–1097; tipo `block`.

```text
/*index to current array to store */
```

## 3441. original/port-overlay/drivers/net/wireless/realtek/rtlwifi/wifi.h:1098

Líneas 1098–1098; tipo `block`.

```text
/*num of valid elements */
```

## 3442. original/port-overlay/drivers/net/wireless/realtek/rtlwifi/wifi.h:1099

Líneas 1099–1099; tipo `block`.

```text
/*sum of valid elements */
```

## 3443. original/port-overlay/drivers/net/wireless/realtek/rtlwifi/wifi.h:1142

Líneas 1142–1144; tipo `block`.

```text
/*Correct smoothed ss in Dbm, only used
	 * in driver to report real power now.
	 */
```

## 3444. original/port-overlay/drivers/net/wireless/realtek/rtlwifi/wifi.h:1152

Líneas 1152–1154; tipo `block`.

```text
/* Transformed, in dbm. Beautified signal
	 * strength for UI, not correct.
	 */
```

## 3445. original/port-overlay/drivers/net/wireless/realtek/rtlwifi/wifi.h:1226

Líneas 1226–1226; tipo `block`.

```text
/*0 is off, 1 is on */
```

## 3446. original/port-overlay/drivers/net/wireless/realtek/rtlwifi/wifi.h:1229

Líneas 1229–1229; tipo `block`.

```text
/*for P2P PS**/
```

## 3447. original/port-overlay/drivers/net/wireless/realtek/rtlwifi/wifi.h:1244

Líneas 1244–1244; tipo `block`.

```text
/* for P2P GO */
```

## 3448. original/port-overlay/drivers/net/wireless/realtek/rtlwifi/wifi.h:1251

Líneas 1251–1251; tipo `block`.

```text
/* CTWindow and NoA */
```

## 3449. original/port-overlay/drivers/net/wireless/realtek/rtlwifi/wifi.h:1255

Líneas 1255–1255; tipo `block`.

```text
/* indicate p2p ps mode */
```

## 3450. original/port-overlay/drivers/net/wireless/realtek/rtlwifi/wifi.h:1256

Líneas 1256–1256; tipo `block`.

```text
/*  indicate p2p ps state */
```

## 3451. original/port-overlay/drivers/net/wireless/realtek/rtlwifi/wifi.h:1257

Líneas 1257–1257; tipo `block`.

```text
/*  Identifies instance of Notice of Absence timing. */
```

## 3452. original/port-overlay/drivers/net/wireless/realtek/rtlwifi/wifi.h:1258

Líneas 1258–1258; tipo `block`.

```text
/*  Client traffic window. A period of time in TU after TBTT. */
```

## 3453. original/port-overlay/drivers/net/wireless/realtek/rtlwifi/wifi.h:1260

Líneas 1260–1260; tipo `block`.

```text
/*  opportunistic power save. */
```

## 3454. original/port-overlay/drivers/net/wireless/realtek/rtlwifi/wifi.h:1261

Líneas 1261–1261; tipo `block`.

```text
/*  number of NoA descriptor in P2P IE. */
```

## 3455. original/port-overlay/drivers/net/wireless/realtek/rtlwifi/wifi.h:1262

Líneas 1262–1262; tipo `block`.

```text
/*  Count for owner, Type of client. */
```

## 3456. original/port-overlay/drivers/net/wireless/realtek/rtlwifi/wifi.h:1264

Líneas 1264–1266; tipo `block`.

```text
/*  Max duration for owner, preferred or min acceptable duration
	 * for client.
	 */
```

## 3457. original/port-overlay/drivers/net/wireless/realtek/rtlwifi/wifi.h:1268

Líneas 1268–1270; tipo `block`.

```text
/*  Length of interval for owner, preferred or max acceptable intervali
	 * of client.
	 */
```

## 3458. original/port-overlay/drivers/net/wireless/realtek/rtlwifi/wifi.h:1272

Líneas 1272–1272; tipo `block`.

```text
/*  schedule in terms of the lower 4 bytes of the TSF timer. */
```

## 3459. original/port-overlay/drivers/net/wireless/realtek/rtlwifi/wifi.h:1278

Líneas 1278–1278; tipo `block`.

```text
/* 1: Owner, 0: Client */
```

## 3460. original/port-overlay/drivers/net/wireless/realtek/rtlwifi/wifi.h:1315

Líneas 1315–1315; tipo `block`.

```text
/*Radio A/B/C/D */
```

## 3461. original/port-overlay/drivers/net/wireless/realtek/rtlwifi/wifi.h:1331

Líneas 1331–1331; tipo `block`.

```text
/* record for power tracking */
```

## 3462. original/port-overlay/drivers/net/wireless/realtek/rtlwifi/wifi.h:1351

Líneas 1351–1351; tipo `block`.

```text
/* Dual mac */
```

## 3463. original/port-overlay/drivers/net/wireless/realtek/rtlwifi/wifi.h:1360

Líneas 1360–1360; tipo `block`.

```text
/* this is for 88E & 8723A */
```

## 3464. original/port-overlay/drivers/net/wireless/realtek/rtlwifi/wifi.h:1362

Líneas 1362–1362; tipo `block`.

```text
/* MAX_PG_GROUP groups of pwr diff by rates */
```

## 3465. original/port-overlay/drivers/net/wireless/realtek/rtlwifi/wifi.h:1376

Líneas 1376–1376; tipo `block`.

```text
/* the current Tx power level */
```

## 3466. original/port-overlay/drivers/net/wireless/realtek/rtlwifi/wifi.h:1395

Líneas 1395–1395; tipo `block`.

```text
/* pathA / pathB  */
```

## 3467. original/port-overlay/drivers/net/wireless/realtek/rtlwifi/wifi.h:1397

Líneas 1397–1397; tipo `block`.

```text
/*92ee*/
```

## 3468. original/port-overlay/drivers/net/wireless/realtek/rtlwifi/wifi.h:1398

Líneas 1398–1398; tipo `block`.

```text
/* bfsync */
```

## 3469. original/port-overlay/drivers/net/wireless/realtek/rtlwifi/wifi.h:1406

Líneas 1406–1406; tipo `block`.

```text
/*Enable GPIO[9] as WL RF HW PDn source*/
```

## 3470. original/port-overlay/drivers/net/wireless/realtek/rtlwifi/wifi.h:1444

Líneas 1444–1444; tipo `block`.

```text
/* just used for ap adhoc or mesh*/
```

## 3471. original/port-overlay/drivers/net/wireless/realtek/rtlwifi/wifi.h:1458

Líneas 1458–1458; tipo `block`.

```text
/*PCI MEM map */
```

## 3472. original/port-overlay/drivers/net/wireless/realtek/rtlwifi/wifi.h:1459

Líneas 1459–1459; tipo `block`.

```text
/*shared mem end        */
```

## 3473. original/port-overlay/drivers/net/wireless/realtek/rtlwifi/wifi.h:1460

Líneas 1460–1460; tipo `block`.

```text
/*shared mem start */
```

## 3474. original/port-overlay/drivers/net/wireless/realtek/rtlwifi/wifi.h:1462

Líneas 1462–1462; tipo `block`.

```text
/*PCI IO map */
```

## 3475. original/port-overlay/drivers/net/wireless/realtek/rtlwifi/wifi.h:1463

Líneas 1463–1463; tipo `block`.

```text
/*device I/O address */
```

## 3476. original/port-overlay/drivers/net/wireless/realtek/rtlwifi/wifi.h:1490

Líneas 1490–1490; tipo `block`.

```text
/*Probe Beacon management */
```

## 3477. original/port-overlay/drivers/net/wireless/realtek/rtlwifi/wifi.h:1498

Líneas 1498–1498; tipo `block`.

```text
/*using p2p role*/
```

## 3478. original/port-overlay/drivers/net/wireless/realtek/rtlwifi/wifi.h:1501

Líneas 1501–1501; tipo `block`.

```text
/*filters */
```

## 3479. original/port-overlay/drivers/net/wireless/realtek/rtlwifi/wifi.h:1511

Líneas 1511–1511; tipo `block`.

```text
/* early mode */
```

## 3480. original/port-overlay/drivers/net/wireless/realtek/rtlwifi/wifi.h:1512

Líneas 1512–1512; tipo `block`.

```text
/* skb wait queue */
```

## 3481. original/port-overlay/drivers/net/wireless/realtek/rtlwifi/wifi.h:1518

Líneas 1518–1518; tipo `block`.

```text
/*vht support*/
```

## 3482. original/port-overlay/drivers/net/wireless/realtek/rtlwifi/wifi.h:1526

Líneas 1526–1526; tipo `block`.

```text
/*RDG*/
```

## 3483. original/port-overlay/drivers/net/wireless/realtek/rtlwifi/wifi.h:1529

Líneas 1529–1529; tipo `block`.

```text
/*AP*/
```

## 3484. original/port-overlay/drivers/net/wireless/realtek/rtlwifi/wifi.h:1532

Líneas 1532–1532; tipo `block`.

```text
/* 16 bytes mcs for HT rates. */
```

## 3485. original/port-overlay/drivers/net/wireless/realtek/rtlwifi/wifi.h:1533

Líneas 1533–1533; tipo `block`.

```text
/* b/g rates */
```

## 3486. original/port-overlay/drivers/net/wireless/realtek/rtlwifi/wifi.h:1538

Líneas 1538–1538; tipo `block`.

```text
/* wireless mode */
```

## 3487. original/port-overlay/drivers/net/wireless/realtek/rtlwifi/wifi.h:1551

Líneas 1551–1551; tipo `block`.

```text
/*IBSS*/
```

## 3488. original/port-overlay/drivers/net/wireless/realtek/rtlwifi/wifi.h:1554

Líneas 1554–1554; tipo `block`.

```text
/*AMPDU*/
```

## 3489. original/port-overlay/drivers/net/wireless/realtek/rtlwifi/wifi.h:1555

Líneas 1555–1555; tipo `block`.

```text
/*For Min spacing configurations */
```

## 3490. original/port-overlay/drivers/net/wireless/realtek/rtlwifi/wifi.h:1560

Líneas 1560–1560; tipo `block`.

```text
/*QOS & EDCA */
```

## 3491. original/port-overlay/drivers/net/wireless/realtek/rtlwifi/wifi.h:1564

Líneas 1564–1564; tipo `block`.

```text
/* counters */
```

## 3492. original/port-overlay/drivers/net/wireless/realtek/rtlwifi/wifi.h:1629

Líneas 1629–1629; tipo `block`.

```text
/*92c or 92d or 92s and so on */
```

## 3493. original/port-overlay/drivers/net/wireless/realtek/rtlwifi/wifi.h:1632

Líneas 1632–1632; tipo `block`.

```text
/*version of chip */
```

## 3494. original/port-overlay/drivers/net/wireless/realtek/rtlwifi/wifi.h:1633

Líneas 1633–1633; tipo `block`.

```text
/*stop 0, start 1 */
```

## 3495. original/port-overlay/drivers/net/wireless/realtek/rtlwifi/wifi.h:1653

Líneas 1653–1653; tipo `block`.

```text
/*firmware */
```

## 3496. original/port-overlay/drivers/net/wireless/realtek/rtlwifi/wifi.h:1661

Líneas 1661–1661; tipo `block`.

```text
/*Reserve page start offset except beacon in TxQ. */
```

## 3497. original/port-overlay/drivers/net/wireless/realtek/rtlwifi/wifi.h:1666

Líneas 1666–1666; tipo `block`.

```text
/* FW Cmd IO related */
```

## 3498. original/port-overlay/drivers/net/wireless/realtek/rtlwifi/wifi.h:1676

Líneas 1676–1676; tipo `block`.

```text
/**/
```

## 3499. original/port-overlay/drivers/net/wireless/realtek/rtlwifi/wifi.h:1679

Líneas 1679–1679; tipo `block`.

```text
/*AMPDU init min space*/
```

## 3500. original/port-overlay/drivers/net/wireless/realtek/rtlwifi/wifi.h:1680

Líneas 1680–1680; tipo `block`.

```text
/*For Min spacing configurations */
```

## 3501. original/port-overlay/drivers/net/wireless/realtek/rtlwifi/wifi.h:1682

Líneas 1682–1682; tipo `block`.

```text
/* Dual mac */
```

## 3502. original/port-overlay/drivers/net/wireless/realtek/rtlwifi/wifi.h:1684

Líneas 1684–1684; tipo `block`.

```text
/* 0:2.4G, 1:5G */
```

## 3503. original/port-overlay/drivers/net/wireless/realtek/rtlwifi/wifi.h:1687

Líneas 1687–1687; tipo `block`.

```text
/* dual MAC 0--Mac0 1--Mac1 */
```

## 3504. original/port-overlay/drivers/net/wireless/realtek/rtlwifi/wifi.h:1689

Líneas 1689–1689; tipo `block`.

```text
/* just for DualMac S3S4 */
```

## 3505. original/port-overlay/drivers/net/wireless/realtek/rtlwifi/wifi.h:1693

Líneas 1693–1693; tipo `block`.

```text
/* Dual mac*/
```

## 3506. original/port-overlay/drivers/net/wireless/realtek/rtlwifi/wifi.h:1697

Líneas 1697–1699; tipo `block`.

```text
/* True if IMR or IQK  have done
	 * for 2.4G in scan progress
	 */
```

## 3507. original/port-overlay/drivers/net/wireless/realtek/rtlwifi/wifi.h:1706

Líneas 1706–1706; tipo `block`.

```text
/*for 92ee*/
```

## 3508. original/port-overlay/drivers/net/wireless/realtek/rtlwifi/wifi.h:1709

Líneas 1709–1709; tipo `block`.

```text
/*for wowlan*/
```

## 3509. original/port-overlay/drivers/net/wireless/realtek/rtlwifi/wifi.h:1718

Líneas 1718–1718; tipo `block`.

```text
/*Enable GPIO[9] as WL RF HW PDn source*/
```

## 3510. original/port-overlay/drivers/net/wireless/realtek/rtlwifi/wifi.h:1725

Líneas 1725–1725; tipo `block`.

```text
/*default 0 */
```

## 3511. original/port-overlay/drivers/net/wireless/realtek/rtlwifi/wifi.h:1730

Líneas 1730–1730; tipo `block`.

```text
/*Encryption Algorithm for Unicast Packet */
```

## 3512. original/port-overlay/drivers/net/wireless/realtek/rtlwifi/wifi.h:1732

Líneas 1732–1732; tipo `block`.

```text
/*Encryption Algorithm for Brocast/Multicast */
```

## 3513. original/port-overlay/drivers/net/wireless/realtek/rtlwifi/wifi.h:1734

Líneas 1734–1734; tipo `block`.

```text
/*Cam Entry Bitmap */
```

## 3514. original/port-overlay/drivers/net/wireless/realtek/rtlwifi/wifi.h:1737

Líneas 1737–1739; tipo `block`.

```text
/*local Key buffer, indx 0 is for
	 * pairwise key 1-4 is for agoup key.
	 */
```

## 3515. original/port-overlay/drivers/net/wireless/realtek/rtlwifi/wifi.h:1743

Líneas 1743–1745; tipo `block`.

```text
/*The pointer of Pairwise Key,
	 * it always points to KeyBuf[4]
	 */
```

## 3516. original/port-overlay/drivers/net/wireless/realtek/rtlwifi/wifi.h:1783

Líneas 1783–1783; tipo `block`.

```text
/*PHY status for Dynamic Management */
```

## 3517. original/port-overlay/drivers/net/wireless/realtek/rtlwifi/wifi.h:1786

Líneas 1786–1786; tipo `block`.

```text
/*out dm */
```

## 3518. original/port-overlay/drivers/net/wireless/realtek/rtlwifi/wifi.h:1792

Líneas 1792–1792; tipo `block`.

```text
/*out dm */
```

## 3519. original/port-overlay/drivers/net/wireless/realtek/rtlwifi/wifi.h:1814

Líneas 1814–1814; tipo `block`.

```text
/*Tx high power level */
```

## 3520. original/port-overlay/drivers/net/wireless/realtek/rtlwifi/wifi.h:1815

Líneas 1815–1815; tipo `block`.

```text
/*Indicate each dynamic mechanism's status. */
```

## 3521. original/port-overlay/drivers/net/wireless/realtek/rtlwifi/wifi.h:1838

Líneas 1838–1838; tipo `block`.

```text
/* Dynamic ATC switch */
```

## 3522. original/port-overlay/drivers/net/wireless/realtek/rtlwifi/wifi.h:1850

Líneas 1850–1850; tipo `block`.

```text
/*88e tx power tracking*/
```

## 3523. original/port-overlay/drivers/net/wireless/realtek/rtlwifi/wifi.h:1863

Líneas 1863–1863; tipo `block`.

```text
/* DMSP */
```

## 3524. original/port-overlay/drivers/net/wireless/realtek/rtlwifi/wifi.h:1866

Líneas 1866–1866; tipo `block`.

```text
/* DulMac */
```

## 3525. original/port-overlay/drivers/net/wireless/realtek/rtlwifi/wifi.h:1918

Líneas 1918–1918; tipo `block`.

```text
/* for 5GL/5GM/5GH band. */
```

## 3526. original/port-overlay/drivers/net/wireless/realtek/rtlwifi/wifi.h:1925

Líneas 1925–1925; tipo `block`.

```text
/* pathA / pathB */
```

## 3527. original/port-overlay/drivers/net/wireless/realtek/rtlwifi/wifi.h:1929

Líneas 1929–1929; tipo `block`.

```text
/*For power group */
```

## 3528. original/port-overlay/drivers/net/wireless/realtek/rtlwifi/wifi.h:1935

Líneas 1935–1935; tipo `block`.

```text
/*For HT 40MHZ pwr */
```

## 3529. original/port-overlay/drivers/net/wireless/realtek/rtlwifi/wifi.h:1937

Líneas 1937–1937; tipo `block`.

```text
/*For HT 40MHZ pwr */
```

## 3530. original/port-overlay/drivers/net/wireless/realtek/rtlwifi/wifi.h:1940

Líneas 1940–1953; tipo `block`.

```text
/*--------------------------------------------------------*
	 * 8192CE\8192SE\8192DE\8723AE use the following 4 arrays,
	 * other ICs (8188EE\8723BE\8192EE\8812AE...)
	 * define new arrays in Windows code.
	 * BUT, in linux code, we use the same array for all ICs.
	 *
	 * The Correspondance relation between two arrays is:
	 * txpwr_cckdiff[][] == CCK_24G_Diff[][]
	 * txpwr_ht20diff[][] == BW20_24G_Diff[][]
	 * txpwr_ht40diff[][] == BW40_24G_Diff[][]
	 * txpwr_legacyhtdiff[][] == OFDM_24G_Diff[][]
	 *
	 * Sizes of these arrays are decided by the larger ones.
	 */
```

## 3531. original/port-overlay/drivers/net/wireless/realtek/rtlwifi/wifi.h:1966

Líneas 1966–1966; tipo `block`.

```text
/* Band edge enable flag */
```

## 3532. original/port-overlay/drivers/net/wireless/realtek/rtlwifi/wifi.h:1972

Líneas 1972–1972; tipo `block`.

```text
/*ThermalMeter, index 0 for RFIC0, 1 for RFIC1 */
```

## 3533. original/port-overlay/drivers/net/wireless/realtek/rtlwifi/wifi.h:1974

Líneas 1974–1974; tipo `block`.

```text
/* CrystalCap. */
```

## 3534. original/port-overlay/drivers/net/wireless/realtek/rtlwifi/wifi.h:1978

Líneas 1978–1978; tipo `block`.

```text
/*Legacy to HT rate power diff */
```

## 3535. original/port-overlay/drivers/net/wireless/realtek/rtlwifi/wifi.h:1984

Líneas 1984–1984; tipo `block`.

```text
/*channel plan */
```

## 3536. original/port-overlay/drivers/net/wireless/realtek/rtlwifi/wifi.h:2008

Líneas 2008–2011; tipo `block`.

```text
/* just for PCIE ASPM
	 * If it supports ASPM, Offset[560h] = 0x40,
	 * otherwise Offset[560h] = 0x00.
	 */
```

## 3537. original/port-overlay/drivers/net/wireless/realtek/rtlwifi/wifi.h:2015

Líneas 2015–2015; tipo `block`.

```text
/*for LPS */
```

## 3538. original/port-overlay/drivers/net/wireless/realtek/rtlwifi/wifi.h:2016

Líneas 2016–2016; tipo `block`.

```text
/*Power save mode configured. */
```

## 3539. original/port-overlay/drivers/net/wireless/realtek/rtlwifi/wifi.h:2021

Líneas 2021–2021; tipo `block`.

```text
/*For Fw control LPS mode */
```

## 3540. original/port-overlay/drivers/net/wireless/realtek/rtlwifi/wifi.h:2023

Líneas 2023–2023; tipo `block`.

```text
/*Record Fw PS mode status. */
```

## 3541. original/port-overlay/drivers/net/wireless/realtek/rtlwifi/wifi.h:2027

Líneas 2027–2027; tipo `block`.

```text
/*for 32k*/
```

## 3542. original/port-overlay/drivers/net/wireless/realtek/rtlwifi/wifi.h:2029

Líneas 2029–2029; tipo `block`.

```text
/*for IPS */
```

## 3543. original/port-overlay/drivers/net/wireless/realtek/rtlwifi/wifi.h:2034

Líneas 2034–2034; tipo `block`.

```text
/*RF OFF Level */
```

## 3544. original/port-overlay/drivers/net/wireless/realtek/rtlwifi/wifi.h:2038

Líneas 2038–2038; tipo `block`.

```text
/*just for PCIE ASPM */
```

## 3545. original/port-overlay/drivers/net/wireless/realtek/rtlwifi/wifi.h:2043

Líneas 2043–2043; tipo `block`.

```text
/*cur power state */
```

## 3546. original/port-overlay/drivers/net/wireless/realtek/rtlwifi/wifi.h:2045

Líneas 2045–2045; tipo `block`.

```text
/* for SW LPS*/
```

## 3547. original/port-overlay/drivers/net/wireless/realtek/rtlwifi/wifi.h:2061

Líneas 2061–2061; tipo `block`.

```text
/*For P2P PS */
```

## 3548. original/port-overlay/drivers/net/wireless/realtek/rtlwifi/wifi.h:2066

Líneas 2066–2066; tipo `block`.

```text
/* wake up on line */
```

## 3549. original/port-overlay/drivers/net/wireless/realtek/rtlwifi/wifi.h:2070

Líneas 2070–2070; tipo `block`.

```text
/* Used for WOL, indicates the reason for waking event.*/
```

## 3550. original/port-overlay/drivers/net/wireless/realtek/rtlwifi/wifi.h:2080

Líneas 2080–2080; tipo `block`.

```text
/* hw desc rate */
```

## 3551. original/port-overlay/drivers/net/wireless/realtek/rtlwifi/wifi.h:2090

Líneas 2090–2090; tipo `block`.

```text
/*in 0-100 index. */
```

## 3552. original/port-overlay/drivers/net/wireless/realtek/rtlwifi/wifi.h:2091

Líneas 2091–2093; tipo `block`.

```text
/* Real power in dBm for this packet,
	 * no beautification and aggregation.
	 */
```

## 3553. original/port-overlay/drivers/net/wireless/realtek/rtlwifi/wifi.h:2095

Líneas 2095–2095; tipo `block`.

```text
/*in dBm Translate from PWdB */
```

## 3554. original/port-overlay/drivers/net/wireless/realtek/rtlwifi/wifi.h:2096

Líneas 2096–2096; tipo `block`.

```text
/*in 0-100 index. */
```

## 3555. original/port-overlay/drivers/net/wireless/realtek/rtlwifi/wifi.h:2115

Líneas 2115–2115; tipo `block`.

```text
/*in 0~100 index */
```

## 3556. original/port-overlay/drivers/net/wireless/realtek/rtlwifi/wifi.h:2118

Líneas 2118–2118; tipo `block`.

```text
/* per-path's Cfo_short */
```

## 3557. original/port-overlay/drivers/net/wireless/realtek/rtlwifi/wifi.h:2122

Líneas 2122–2122; tipo `block`.

```text
/* per-path's pwdb */
```

## 3558. original/port-overlay/drivers/net/wireless/realtek/rtlwifi/wifi.h:2123

Líneas 2123–2123; tipo `block`.

```text
/* per-path's SNR */
```

## 3559. original/port-overlay/drivers/net/wireless/realtek/rtlwifi/wifi.h:2130

Líneas 2130–2130; tipo `block`.

```text
/*for rssi */
```

## 3560. original/port-overlay/drivers/net/wireless/realtek/rtlwifi/wifi.h:2131

Líneas 2131–2131; tipo `block`.

```text
/*for rx path selection */
```

## 3561. original/port-overlay/drivers/net/wireless/realtek/rtlwifi/wifi.h:2145

Líneas 2145–2145; tipo `block`.

```text
/* count for roaming */
```

## 3562. original/port-overlay/drivers/net/wireless/realtek/rtlwifi/wifi.h:2195

Líneas 2195–2195; tipo `block`.

```text
/* early mode */
```

## 3563. original/port-overlay/drivers/net/wireless/realtek/rtlwifi/wifi.h:2197

Líneas 2197–2197; tipo `block`.

```text
/* The max value by HW */
```

## 3564. original/port-overlay/drivers/net/wireless/realtek/rtlwifi/wifi.h:2208

Líneas 2208–2208; tipo `block`.

```text
/* struct to store contents of interrupt vectors */
```

## 3565. original/port-overlay/drivers/net/wireless/realtek/rtlwifi/wifi.h:2334

Líneas 2334–2334; tipo `block`.

```text
/*com */
```

## 3566. original/port-overlay/drivers/net/wireless/realtek/rtlwifi/wifi.h:2349

Líneas 2349–2349; tipo `block`.

```text
/*pci */
```

## 3567. original/port-overlay/drivers/net/wireless/realtek/rtlwifi/wifi.h:2353

Líneas 2353–2353; tipo `block`.

```text
/*usb */
```

## 3568. original/port-overlay/drivers/net/wireless/realtek/rtlwifi/wifi.h:2357

Líneas 2357–2357; tipo `block`.

```text
/* default: 0,0 */
```

## 3569. original/port-overlay/drivers/net/wireless/realtek/rtlwifi/wifi.h:2359

Líneas 2359–2359; tipo `block`.

```text
/* default: 0 = using hardware encryption */
```

## 3570. original/port-overlay/drivers/net/wireless/realtek/rtlwifi/wifi.h:2362

Líneas 2362–2362; tipo `block`.

```text
/* default: 0 = DBG_EMERG (0)*/
```

## 3571. original/port-overlay/drivers/net/wireless/realtek/rtlwifi/wifi.h:2365

Líneas 2365–2365; tipo `block`.

```text
/* default: 1 = using no linked power save */
```

## 3572. original/port-overlay/drivers/net/wireless/realtek/rtlwifi/wifi.h:2368

Líneas 2368–2368; tipo `block`.

```text
/* default: 1 = using linked sw power save */
```

## 3573. original/port-overlay/drivers/net/wireless/realtek/rtlwifi/wifi.h:2371

Líneas 2371–2371; tipo `block`.

```text
/* default: 1 = using linked fw power save */
```

## 3574. original/port-overlay/drivers/net/wireless/realtek/rtlwifi/wifi.h:2374

Líneas 2374–2376; tipo `block`.

```text
/* default: 0 = not using MSI interrupts mode
	 * submodules should set their own default value
	 */
```

## 3575. original/port-overlay/drivers/net/wireless/realtek/rtlwifi/wifi.h:2379

Líneas 2379–2379; tipo `block`.

```text
/* default: 0 = dma 32 */
```

## 3576. original/port-overlay/drivers/net/wireless/realtek/rtlwifi/wifi.h:2382

Líneas 2382–2382; tipo `block`.

```text
/* default: 1 = enable aspm */
```

## 3577. original/port-overlay/drivers/net/wireless/realtek/rtlwifi/wifi.h:2385

Líneas 2385–2385; tipo `block`.

```text
/* default 0: 1 means disable */
```

## 3578. original/port-overlay/drivers/net/wireless/realtek/rtlwifi/wifi.h:2388

Líneas 2388–2388; tipo `block`.

```text
/* default 0: 1 means do not disable interrupts */
```

## 3579. original/port-overlay/drivers/net/wireless/realtek/rtlwifi/wifi.h:2391

Líneas 2391–2391; tipo `block`.

```text
/* select antenna */
```

## 3580. original/port-overlay/drivers/net/wireless/realtek/rtlwifi/wifi.h:2396

Líneas 2396–2396; tipo `block`.

```text
/* data - rx */
```

## 3581. original/port-overlay/drivers/net/wireless/realtek/rtlwifi/wifi.h:2401

Líneas 2401–2401; tipo `block`.

```text
/* op - rx */
```

## 3582. original/port-overlay/drivers/net/wireless/realtek/rtlwifi/wifi.h:2406

Líneas 2406–2406; tipo `block`.

```text
/* tx */
```

## 3583. original/port-overlay/drivers/net/wireless/realtek/rtlwifi/wifi.h:2413

Líneas 2413–2413; tipo `block`.

```text
/* endpoint mapping */
```

## 3584. original/port-overlay/drivers/net/wireless/realtek/rtlwifi/wifi.h:2428

Líneas 2428–2430; tipo `block`.

```text
/*this map used for some registers or vars
	 * defined int HAL but used in MAIN
	 */
```

## 3585. original/port-overlay/drivers/net/wireless/realtek/rtlwifi/wifi.h:2436

Líneas 2436–2436; tipo `block`.

```text
/* mutex */
```

## 3586. original/port-overlay/drivers/net/wireless/realtek/rtlwifi/wifi.h:2438

Líneas 2438–2438; tipo `block`.

```text
/* mutex for enter/leave IPS */
```

## 3587. original/port-overlay/drivers/net/wireless/realtek/rtlwifi/wifi.h:2439

Líneas 2439–2439; tipo `block`.

```text
/* mutex for enter/leave LPS */
```

## 3588. original/port-overlay/drivers/net/wireless/realtek/rtlwifi/wifi.h:2441

Líneas 2441–2441; tipo `block`.

```text
/*spin lock */
```

## 3589. original/port-overlay/drivers/net/wireless/realtek/rtlwifi/wifi.h:2450

Líneas 2450–2450; tipo `block`.

```text
/* lock for the scan list */
```

## 3590. original/port-overlay/drivers/net/wireless/realtek/rtlwifi/wifi.h:2452

Líneas 2452–2452; tipo `block`.

```text
/*FW clock change */
```

## 3591. original/port-overlay/drivers/net/wireless/realtek/rtlwifi/wifi.h:2455

Líneas 2455–2455; tipo `block`.

```text
/*Dual mac*/
```

## 3592. original/port-overlay/drivers/net/wireless/realtek/rtlwifi/wifi.h:2464

Líneas 2464–2464; tipo `block`.

```text
/*timer */
```

## 3593. original/port-overlay/drivers/net/wireless/realtek/rtlwifi/wifi.h:2468

Líneas 2468–2468; tipo `block`.

```text
/*task */
```

## 3594. original/port-overlay/drivers/net/wireless/realtek/rtlwifi/wifi.h:2473

Líneas 2473–2473; tipo `block`.

```text
/*work queue */
```

## 3595. original/port-overlay/drivers/net/wireless/realtek/rtlwifi/wifi.h:2479

Líneas 2479–2479; tipo `block`.

```text
/* For SW LPS */
```

## 3596. original/port-overlay/drivers/net/wireless/realtek/rtlwifi/wifi.h:2489

Líneas 2489–2489; tipo `block`.

```text
/* add for debug */
```

## 3597. original/port-overlay/drivers/net/wireless/realtek/rtlwifi/wifi.h:2582

Líneas 2582–2582; tipo `block`.

```text
/* 30 seconds */
```

## 3598. original/port-overlay/drivers/net/wireless/realtek/rtlwifi/wifi.h:2598

Líneas 2598–2598; tipo `block`.

```text
/* btc context */
```

## 3599. original/port-overlay/drivers/net/wireless/realtek/rtlwifi/wifi.h:2601

Líneas 2601–2601; tipo `block`.

```text
/* EEPROM BT info. */
```

## 3600. original/port-overlay/drivers/net/wireless/realtek/rtlwifi/wifi.h:2612

Líneas 2612–2612; tipo `block`.

```text
/* 0:on, 1:off */
```

## 3601. original/port-overlay/drivers/net/wireless/realtek/rtlwifi/wifi.h:2613

Líneas 2613–2613; tipo `block`.

```text
/* 0:good, 1:bad */
```

## 3602. original/port-overlay/drivers/net/wireless/realtek/rtlwifi/wifi.h:2614

Líneas 2614–2614; tipo `block`.

```text
/* 0:SW, 1:SW/HW dynamic */
```

## 3603. original/port-overlay/drivers/net/wireless/realtek/rtlwifi/wifi.h:2721

Líneas 2721–2721; tipo `block`.

```text
/* sort by age */
```

## 3604. original/port-overlay/drivers/net/wireless/realtek/rtlwifi/wifi.h:2753

Líneas 2753–2753; tipo `block`.

```text
/* sta entry list for ap adhoc or mesh */
```

## 3605. original/port-overlay/drivers/net/wireless/realtek/rtlwifi/wifi.h:2756

Líneas 2756–2756; tipo `block`.

```text
/* c2hcmd list for kthread level access */
```

## 3606. original/port-overlay/drivers/net/wireless/realtek/rtlwifi/wifi.h:2762

Líneas 2762–2764; tipo `block`.

```text
/* hal_cfg : for diff cards
	 * intf_ops : for diff interrface usb/pcie
	 */
```

## 3607. original/port-overlay/drivers/net/wireless/realtek/rtlwifi/wifi.h:2768

Líneas 2768–2771; tipo `block`.

```text
/* this var will be set by set_bit,
	 * and was used to indicate status of
	 * interface or hardware
	 */
```

## 3608. original/port-overlay/drivers/net/wireless/realtek/rtlwifi/wifi.h:2774

Líneas 2774–2774; tipo `block`.

```text
/* tables for dm */
```

## 3609. original/port-overlay/drivers/net/wireless/realtek/rtlwifi/wifi.h:2782

Líneas 2782–2782; tipo `block`.

```text
/* true if regs saved */
```

## 3610. original/port-overlay/drivers/net/wireless/realtek/rtlwifi/wifi.h:2787

Líneas 2787–2787; tipo `block`.

```text
/* true when entering PS */
```

## 3611. original/port-overlay/drivers/net/wireless/realtek/rtlwifi/wifi.h:2790

Líneas 2790–2793; tipo `block`.

```text
/* intel Proximity, should be alloc mem
	 * in intel Proximity module and can only
	 * be used in intel Proximity mode
	 */
```

## 3612. original/port-overlay/drivers/net/wireless/realtek/rtlwifi/wifi.h:2796

Líneas 2796–2796; tipo `block`.

```text
/*for bt coexist use*/
```

## 3613. original/port-overlay/drivers/net/wireless/realtek/rtlwifi/wifi.h:2799

Líneas 2799–2801; tipo `block`.

```text
/* separate 92ee from other ICs,
	 * 92ee use new trx flow.
	 */
```

## 3614. original/port-overlay/drivers/net/wireless/realtek/rtlwifi/wifi.h:2807

Líneas 2807–2811; tipo `block`.

```text
/* This must be the last item so
	 * that it points to the data allocated
	 * beyond  this structure like:
	 * rtl_pci_priv or rtl_usb_priv
	 */
```

## 3615. original/port-overlay/drivers/net/wireless/realtek/rtlwifi/wifi.h:2821

Líneas 2821–2821; tipo `block`.

```text
/* Bluetooth Co-existence Related */
```

## 3616. original/port-overlay/drivers/net/wireless/realtek/rtlwifi/wifi.h:2870

Líneas 2870–2876; tipo `block`.

```text
/****************************************
 *	mem access macro define start
 *	Call endian free function when
 *	1. Read/write packet content.
 *	2. Before write integer to IO.
 *	3. After read integer from IO.
 ****************************************/
```

## 3617. original/port-overlay/drivers/net/wireless/realtek/rtlwifi/wifi.h:2881

Líneas 2881–2881; tipo `block`.

```text
/* mem access macro define end */
```

## 3618. original/port-overlay/drivers/net/wireless/realtek/rtlwifi/wifi.h:2894

Líneas 2894–2894; tipo `block`.

```text
/*PCI ASPM */
```

## 3619. original/port-overlay/drivers/net/wireless/realtek/rtlwifi/wifi.h:2895

Líneas 2895–2895; tipo `block`.

```text
/*PCI clock request */
```

## 3620. original/port-overlay/drivers/net/wireless/realtek/rtlwifi/wifi.h:2896

Líneas 2896–2896; tipo `block`.

```text
/*PCI D3 mode */
```

## 3621. original/port-overlay/drivers/net/wireless/realtek/rtlwifi/wifi.h:2897

Líneas 2897–2897; tipo `block`.

```text
/*NIC halt, re-initialize hw parameters*/
```

## 3622. original/port-overlay/drivers/net/wireless/realtek/rtlwifi/wifi.h:2899

Líneas 2899–2899; tipo `block`.

```text
/*FW free, re-download the FW */
```

## 3623. original/port-overlay/drivers/net/wireless/realtek/rtlwifi/wifi.h:2900

Líneas 2900–2900; tipo `block`.

```text
/*FW in 32k */
```

## 3624. original/port-overlay/drivers/net/wireless/realtek/rtlwifi/wifi.h:2901

Líneas 2901–2901; tipo `block`.

```text
/*Always enable ASPM and Clock Req in initialization.*/
```

## 3625. original/port-overlay/drivers/net/wireless/realtek/rtlwifi/wifi.h:2903

Líneas 2903–2903; tipo `block`.

```text
/* no matter RFOFF or SLEEP we set PS_ASPM_LEVL*/
```

## 3626. original/port-overlay/drivers/net/wireless/realtek/rtlwifi/wifi.h:2905

Líneas 2905–2905; tipo `block`.

```text
/*When LPS is on, disable 2R if no packet is received or transmittd.*/
```

## 3627. original/port-overlay/drivers/net/wireless/realtek/rtlwifi/wifi.h:2907

Líneas 2907–2907; tipo `block`.

```text
/*LPS with ASPM */
```

## 3628. original/port-support/include/linux/openmitrastar_qtn_skb.h:1

Líneas 1–1; tipo `block`.

```text
/* SPDX-License-Identifier: GPL-2.0-only */
```

## 3629. original/port-support/include/linux/openmitrastar_qtn_skb.h:60

Líneas 60–60; tipo `block`.

```text
/* __QTN_SKB_CB_H */
```

## 3630. original/port-support/include/linux/openmitrastar_qtn_skb.h:61

Líneas 61–61; tipo `block`.

```text
/* _LINUX_OPENMITRASTAR_QTN_SKB_H */
```

## Índice de archivos

| Archivo | Comentarios |
|---|---:|
| `original/kernel-api/linux-5.10.260/include/linux/device.h` | 57 |
| `original/kernel-api/linux-5.10.260/include/linux/device/driver.h` | 15 |
| `original/kernel-api/linux-5.10.260/include/linux/module.h` | 90 |
| `original/kernel-api/linux-5.10.260/include/linux/moduleparam.h` | 58 |
| `original/kernel-api/linux-5.10.260/include/linux/pci.h` | 326 |
| `original/kernel-api/linux-5.10.260/include/linux/pm.h` | 33 |
| `original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/Kconfig` | 1 |
| `original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/Makefile` | 1 |
| `original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/base.c` | 130 |
| `original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/base.h` | 12 |
| `original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/btcoexist/Makefile` | 1 |
| `original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/btcoexist/halbt_precomp.h` | 5 |
| `original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/btcoexist/halbtc8192e2ant.c` | 87 |
| `original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/btcoexist/halbtc8192e2ant.h` | 9 |
| `original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/btcoexist/halbtc8723b1ant.c` | 189 |
| `original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/btcoexist/halbtc8723b1ant.h` | 10 |
| `original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/btcoexist/halbtc8723b2ant.c` | 139 |
| `original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/btcoexist/halbtc8723b2ant.h` | 9 |
| `original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/btcoexist/halbtc8821a1ant.c` | 110 |
| `original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/btcoexist/halbtc8821a1ant.h` | 9 |
| `original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/btcoexist/halbtc8821a2ant.c` | 121 |
| `original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/btcoexist/halbtc8821a2ant.h` | 9 |
| `original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/btcoexist/halbtc8822bwifionly.c` | 7 |
| `original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/btcoexist/halbtc8822bwifionly.h` | 2 |
| `original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/btcoexist/halbtcoutsrc.c` | 54 |
| `original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/btcoexist/halbtcoutsrc.h` | 38 |
| `original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/btcoexist/rtl_btc.c` | 9 |
| `original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/btcoexist/rtl_btc.h` | 2 |
| `original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/cam.c` | 7 |
| `original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/cam.h` | 2 |
| `original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/core.c` | 88 |
| `original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/core.h` | 2 |
| `original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/debug.c` | 8 |
| `original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/debug.h` | 35 |
| `original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/efuse.c` | 6 |
| `original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/efuse.h` | 2 |
| `original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/pci.c` | 128 |
| `original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/pci.h` | 62 |
| `original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/ps.c` | 51 |
| `original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/ps.h` | 2 |
| `original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/pwrseqcmd.h` | 4 |
| `original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/rc.c` | 6 |
| `original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/rc.h` | 3 |
| `original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/regd.c` | 20 |
| `original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/regd.h` | 4 |
| `original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/rtl8192ee/Makefile` | 1 |
| `original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/rtl8192ee/def.h` | 2 |
| `original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/rtl8192ee/dm.c` | 30 |
| `original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/rtl8192ee/dm.h` | 19 |
| `original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/rtl8192ee/fw.c` | 36 |
| `original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/rtl8192ee/fw.h` | 10 |
| `original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/rtl8192ee/hw.c` | 100 |
| `original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/rtl8192ee/hw.h` | 2 |
| `original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/rtl8192ee/led.c` | 2 |
| `original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/rtl8192ee/led.h` | 2 |
| `original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/rtl8192ee/phy.c` | 100 |
| `original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/rtl8192ee/phy.h` | 3 |
| `original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/rtl8192ee/pwrseq.c` | 14 |
| `original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/rtl8192ee/pwrseq.h` | 95 |
| `original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/rtl8192ee/reg.h` | 18 |
| `original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/rtl8192ee/rf.c` | 2 |
| `original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/rtl8192ee/rf.h` | 2 |
| `original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/rtl8192ee/sw.c` | 17 |
| `original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/rtl8192ee/table.c` | 2 |
| `original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/rtl8192ee/table.h` | 2 |
| `original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/rtl8192ee/trx.c` | 38 |
| `original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/rtl8192ee/trx.h` | 21 |
| `original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/stats.c` | 3 |
| `original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/stats.h` | 3 |
| `original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/usb.c` | 57 |
| `original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/usb.h` | 17 |
| `original/linux-5.10.260/drivers/net/wireless/realtek/rtlwifi/wifi.h` | 281 |
| `original/linux-5.10.260/include/net/mac80211.h` | 260 |
| `original/port-overlay/drivers/net/wireless/realtek/rtlwifi/pci.c` | 140 |
| `original/port-overlay/drivers/net/wireless/realtek/rtlwifi/rtl8192ee/fw.c` | 38 |
| `original/port-overlay/drivers/net/wireless/realtek/rtlwifi/rtl8192ee/trx.c` | 45 |
| `original/port-overlay/drivers/net/wireless/realtek/rtlwifi/rtl8192ee/trx.h` | 21 |
| `original/port-overlay/drivers/net/wireless/realtek/rtlwifi/wifi.h` | 281 |
| `original/port-support/include/linux/openmitrastar_qtn_skb.h` | 3 |
