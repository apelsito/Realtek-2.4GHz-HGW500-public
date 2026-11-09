cmd_drivers/net/wireless/realtek/rtlwifi/rtl_pci.mod.o := @TOOLCHAIN_ROOT@/bin/arc-snps-linux-uclibc-gcc -Wp,-MMD,drivers/net/wireless/realtek/rtlwifi/.rtl_pci.mod.o.d -nostdinc -isystem @TOOLCHAIN_ROOT@/bin/../lib/gcc/arc-snps-linux-uclibc/15.2.0/include -I@KERNEL_SOURCE@/arch/arc/include -I./arch/arc/include/generated -I@KERNEL_SOURCE@/include -I./include -I@KERNEL_SOURCE@/arch/arc/include/uapi -I./arch/arc/include/generated/uapi -I@KERNEL_SOURCE@/include/uapi -I./include/generated/uapi -include @KERNEL_SOURCE@/include/linux/kconfig.h -include @KERNEL_SOURCE@/include/linux/compiler_types.h -D__KERNEL__ -fmacro-prefix-map=@KERNEL_SOURCE@/= -Wall -Wundef -Werror=strict-prototypes -Wno-trigraphs -fno-strict-aliasing -fno-common -fshort-wchar -fno-PIE -Werror=implicit-function-declaration -Werror=implicit-int -Werror=return-type -Wno-format-security -std=gnu89 -fno-common -pipe -fno-builtin -mmedium-calls -D__linux__ -mcpu=arc700 -fsection-anchors -mno-sdata -fcall-used-gp -fno-delete-null-pointer-checks -Wno-frame-address -Wno-format-truncation -Wno-format-overflow -Wno-address-of-packed-member -Os -fno-allow-store-data-races -Wframe-larger-than=1024 -fno-stack-protector -Wimplicit-fallthrough -Wno-unused-but-set-variable -Wno-unused-const-variable -Wno-dangling-pointer -fomit-frame-pointer -ftrivial-auto-var-init=zero -Wdeclaration-after-statement -Wvla -Wno-pointer-sign -Wno-stringop-truncation -Wno-zero-length-bounds -Wno-array-bounds -Wno-stringop-overflow -Wno-restrict -Wno-maybe-uninitialized -fno-strict-overflow -fno-stack-check -fconserve-stack -Werror=date-time -Werror=incompatible-pointer-types -Werror=designated-init -fno-builtin-wcslen -Wno-packed-not-aligned -ffile-prefix-map=@HISTORICAL_OUTPUT@=/f358-output -I @KERNEL_SOURCE@/ -I ./  -DMODULE -mlong-calls -mno-millicode  -DKBUILD_BASENAME='"rtl_pci.mod"' -DKBUILD_MODNAME='"rtl_pci"' -c -o drivers/net/wireless/realtek/rtlwifi/rtl_pci.mod.o drivers/net/wireless/realtek/rtlwifi/rtl_pci.mod.c

source_drivers/net/wireless/realtek/rtlwifi/rtl_pci.mod.o := drivers/net/wireless/realtek/rtlwifi/rtl_pci.mod.c

deps_drivers/net/wireless/realtek/rtlwifi/rtl_pci.mod.o := \
    $(wildcard include/config/retpoline.h) \
  @KERNEL_SOURCE@/include/linux/kconfig.h \
    $(wildcard include/config/cc/version/text.h) \
    $(wildcard include/config/cpu/big/endian.h) \
    $(wildcard include/config/booger.h) \
    $(wildcard include/config/foo.h) \
  @KERNEL_SOURCE@/include/linux/compiler_types.h \
    $(wildcard include/config/have/arch/compiler/h.h) \
    $(wildcard include/config/enable/must/check.h) \
    $(wildcard include/config/cc/has/asm/inline.h) \
  @KERNEL_SOURCE@/include/linux/compiler_attributes.h \
  @KERNEL_SOURCE@/include/linux/compiler-gcc.h \
    $(wildcard include/config/arm64.h) \
    $(wildcard include/config/arch/use/builtin/bswap.h) \
    $(wildcard include/config/kcov.h) \
  @KERNEL_SOURCE@/include/linux/module.h \
    $(wildcard include/config/modules.h) \
    $(wildcard include/config/sysfs.h) \
    $(wildcard include/config/modules/tree/lookup.h) \
    $(wildcard include/config/livepatch.h) \
    $(wildcard include/config/unused/symbols.h) \
    $(wildcard include/config/module/sig.h) \
    $(wildcard include/config/generic/bug.h) \
    $(wildcard include/config/kallsyms.h) \
    $(wildcard include/config/smp.h) \
    $(wildcard include/config/tracepoints.h) \
    $(wildcard include/config/tree/srcu.h) \
    $(wildcard include/config/bpf/events.h) \
    $(wildcard include/config/jump/label.h) \
    $(wildcard include/config/tracing.h) \
    $(wildcard include/config/event/tracing.h) \
    $(wildcard include/config/ftrace/mcount/record.h) \
    $(wildcard include/config/kprobes.h) \
    $(wildcard include/config/have/static/call/inline.h) \
    $(wildcard include/config/module/unload.h) \
    $(wildcard include/config/mitigation/its.h) \
    $(wildcard include/config/constructors.h) \
    $(wildcard include/config/function/error/injection.h) \
  @KERNEL_SOURCE@/include/linux/list.h \
    $(wildcard include/config/debug/list.h) \
  @KERNEL_SOURCE@/include/linux/types.h \
    $(wildcard include/config/have/uid16.h) \
    $(wildcard include/config/uid16.h) \
    $(wildcard include/config/arch/dma/addr/t/64bit.h) \
    $(wildcard include/config/phys/addr/t/64bit.h) \
    $(wildcard include/config/64bit.h) \
  @KERNEL_SOURCE@/include/uapi/linux/types.h \
  arch/arc/include/generated/uapi/asm/types.h \
  @KERNEL_SOURCE@/include/uapi/asm-generic/types.h \
  @KERNEL_SOURCE@/include/asm-generic/int-ll64.h \
  @KERNEL_SOURCE@/include/uapi/asm-generic/int-ll64.h \
  arch/arc/include/generated/uapi/asm/bitsperlong.h \
  @KERNEL_SOURCE@/include/asm-generic/bitsperlong.h \
  @KERNEL_SOURCE@/include/uapi/asm-generic/bitsperlong.h \
  @KERNEL_SOURCE@/include/uapi/linux/posix_types.h \
  @KERNEL_SOURCE@/include/linux/stddef.h \
  @KERNEL_SOURCE@/include/uapi/linux/stddef.h \
  @KERNEL_SOURCE@/include/linux/compiler_types.h \
  arch/arc/include/generated/uapi/asm/posix_types.h \
  @KERNEL_SOURCE@/include/uapi/asm-generic/posix_types.h \
  @KERNEL_SOURCE@/include/linux/poison.h \
    $(wildcard include/config/illegal/pointer/value.h) \
    $(wildcard include/config/page/poisoning/zero.h) \
  @KERNEL_SOURCE@/include/linux/const.h \
  @KERNEL_SOURCE@/include/vdso/const.h \
  @KERNEL_SOURCE@/include/uapi/linux/const.h \
  @KERNEL_SOURCE@/include/linux/kernel.h \
    $(wildcard include/config/preempt/voluntary.h) \
    $(wildcard include/config/debug/atomic/sleep.h) \
    $(wildcard include/config/preempt/rt.h) \
    $(wildcard include/config/mmu.h) \
    $(wildcard include/config/prove/locking.h) \
    $(wildcard include/config/panic/timeout.h) \
  @KERNEL_SOURCE@/include/linux/limits.h \
  @KERNEL_SOURCE@/include/uapi/linux/limits.h \
  @KERNEL_SOURCE@/include/vdso/limits.h \
  @KERNEL_SOURCE@/include/linux/linkage.h \
    $(wildcard include/config/arch/use/sym/annotations.h) \
  @KERNEL_SOURCE@/include/linux/stringify.h \
  @KERNEL_SOURCE@/include/linux/export.h \
    $(wildcard include/config/modversions.h) \
    $(wildcard include/config/module/rel/crcs.h) \
    $(wildcard include/config/have/arch/prel32/relocations.h) \
    $(wildcard include/config/trim/unused/ksyms.h) \
  @KERNEL_SOURCE@/arch/arc/include/asm/linkage.h \
    $(wildcard include/config/arc/has/ll64.h) \
    $(wildcard include/config/arc/has/dccm.h) \
    $(wildcard include/config/arc/has/iccm.h) \
  @KERNEL_SOURCE@/arch/arc/include/asm/dwarf.h \
  @KERNEL_SOURCE@/include/linux/compiler.h \
    $(wildcard include/config/trace/branch/profiling.h) \
    $(wildcard include/config/profile/all/branches.h) \
    $(wildcard include/config/stack/validation.h) \
  arch/arc/include/generated/asm/rwonce.h \
  @KERNEL_SOURCE@/include/asm-generic/rwonce.h \
  @KERNEL_SOURCE@/include/linux/kasan-checks.h \
    $(wildcard include/config/kasan.h) \
  @KERNEL_SOURCE@/include/linux/kcsan-checks.h \
    $(wildcard include/config/kcsan.h) \
    $(wildcard include/config/kcsan/ignore/atomics.h) \
  @KERNEL_SOURCE@/include/linux/bitops.h \
  @KERNEL_SOURCE@/include/linux/bits.h \
  @KERNEL_SOURCE@/include/vdso/bits.h \
  @KERNEL_SOURCE@/include/linux/build_bug.h \
  @KERNEL_SOURCE@/arch/arc/include/asm/bitops.h \
    $(wildcard include/config/arc/has/llsc.h) \
    $(wildcard include/config/isa/arcompact.h) \
    $(wildcard include/config/isa/arcv2.h) \
  @KERNEL_SOURCE@/arch/arc/include/asm/barrier.h \
  @KERNEL_SOURCE@/include/asm-generic/barrier.h \
  @KERNEL_SOURCE@/arch/arc/include/asm/smp.h \
  @KERNEL_SOURCE@/include/linux/irqflags.h \
    $(wildcard include/config/trace/irqflags.h) \
    $(wildcard include/config/irqsoff/tracer.h) \
    $(wildcard include/config/preempt/tracer.h) \
    $(wildcard include/config/trace/irqflags/support.h) \
  @KERNEL_SOURCE@/include/linux/typecheck.h \
  @KERNEL_SOURCE@/include/linux/cleanup.h \
  @KERNEL_SOURCE@/arch/arc/include/asm/irqflags.h \
  @KERNEL_SOURCE@/arch/arc/include/asm/irqflags-compact.h \
    $(wildcard include/config/arc/compact/irq/levels.h) \
  @KERNEL_SOURCE@/arch/arc/include/asm/arcregs.h \
  @KERNEL_SOURCE@/include/soc/arc/aux.h \
    $(wildcard include/config/arc.h) \
  @KERNEL_SOURCE@/include/soc/arc/timers.h \
  arch/arc/include/generated/asm/percpu.h \
  @KERNEL_SOURCE@/include/asm-generic/percpu.h \
    $(wildcard include/config/debug/preempt.h) \
    $(wildcard include/config/have/setup/per/cpu/area.h) \
  @KERNEL_SOURCE@/include/linux/threads.h \
    $(wildcard include/config/nr/cpus.h) \
    $(wildcard include/config/base/small.h) \
  @KERNEL_SOURCE@/include/linux/percpu-defs.h \
    $(wildcard include/config/debug/force/weak/per/cpu.h) \
    $(wildcard include/config/amd/mem/encrypt.h) \
  @KERNEL_SOURCE@/include/asm-generic/bitops/hweight.h \
  @KERNEL_SOURCE@/include/asm-generic/bitops/arch_hweight.h \
  @KERNEL_SOURCE@/include/asm-generic/bitops/const_hweight.h \
  @KERNEL_SOURCE@/include/asm-generic/bitops/fls64.h \
  @KERNEL_SOURCE@/include/asm-generic/bitops/sched.h \
  @KERNEL_SOURCE@/include/asm-generic/bitops/lock.h \
  @KERNEL_SOURCE@/include/linux/atomic.h \
  @KERNEL_SOURCE@/arch/arc/include/asm/atomic.h \
    $(wildcard include/config/generic/atomic64.h) \
  @KERNEL_SOURCE@/arch/arc/include/asm/cmpxchg.h \
  @KERNEL_SOURCE@/include/asm-generic/atomic64.h \
  @KERNEL_SOURCE@/include/linux/atomic-fallback.h \
  @KERNEL_SOURCE@/include/asm-generic/atomic-long.h \
  @KERNEL_SOURCE@/include/asm-generic/bitops/find.h \
    $(wildcard include/config/generic/find/first/bit.h) \
  @KERNEL_SOURCE@/include/asm-generic/bitops/le.h \
  @KERNEL_SOURCE@/arch/arc/include/uapi/asm/byteorder.h \
  @KERNEL_SOURCE@/include/linux/byteorder/little_endian.h \
  @KERNEL_SOURCE@/include/uapi/linux/byteorder/little_endian.h \
  @KERNEL_SOURCE@/include/linux/swab.h \
  @KERNEL_SOURCE@/include/uapi/linux/swab.h \
  @KERNEL_SOURCE@/arch/arc/include/uapi/asm/swab.h \
    $(wildcard include/config/arc/has/swape.h) \
  @KERNEL_SOURCE@/include/linux/byteorder/generic.h \
  @KERNEL_SOURCE@/include/asm-generic/bitops/ext2-atomic-setbit.h \
  @KERNEL_SOURCE@/include/linux/kstrtox.h \
  @KERNEL_SOURCE@/include/linux/log2.h \
    $(wildcard include/config/arch/has/ilog2/u32.h) \
    $(wildcard include/config/arch/has/ilog2/u64.h) \
  @KERNEL_SOURCE@/include/linux/minmax.h \
  @KERNEL_SOURCE@/include/linux/printk.h \
    $(wildcard include/config/message/loglevel/default.h) \
    $(wildcard include/config/console/loglevel/default.h) \
    $(wildcard include/config/console/loglevel/quiet.h) \
    $(wildcard include/config/early/printk.h) \
    $(wildcard include/config/printk/nmi.h) \
    $(wildcard include/config/printk.h) \
    $(wildcard include/config/dynamic/debug.h) \
    $(wildcard include/config/dynamic/debug/core.h) \
  @KERNEL_SOURCE@/include/linux/init.h \
    $(wildcard include/config/strict/kernel/rwx.h) \
    $(wildcard include/config/strict/module/rwx.h) \
  @KERNEL_SOURCE@/include/linux/kern_levels.h \
  @KERNEL_SOURCE@/include/linux/cache.h \
    $(wildcard include/config/arch/has/cache/line/size.h) \
  @KERNEL_SOURCE@/include/uapi/linux/kernel.h \
  @KERNEL_SOURCE@/include/uapi/linux/sysinfo.h \
  @KERNEL_SOURCE@/arch/arc/include/asm/cache.h \
    $(wildcard include/config/arc/cache/line/shift.h) \
  @KERNEL_SOURCE@/include/linux/ratelimit_types.h \
  @KERNEL_SOURCE@/include/uapi/linux/param.h \
  arch/arc/include/generated/uapi/asm/param.h \
  @KERNEL_SOURCE@/include/asm-generic/param.h \
    $(wildcard include/config/hz.h) \
  @KERNEL_SOURCE@/include/uapi/asm-generic/param.h \
  @KERNEL_SOURCE@/include/linux/spinlock_types.h \
    $(wildcard include/config/debug/spinlock.h) \
    $(wildcard include/config/debug/lock/alloc.h) \
  @KERNEL_SOURCE@/include/linux/spinlock_types_up.h \
  @KERNEL_SOURCE@/include/linux/lockdep_types.h \
    $(wildcard include/config/prove/raw/lock/nesting.h) \
    $(wildcard include/config/preempt/lock.h) \
    $(wildcard include/config/lockdep.h) \
    $(wildcard include/config/lock/stat.h) \
  @KERNEL_SOURCE@/include/linux/rwlock_types.h \
  arch/arc/include/generated/asm/div64.h \
  @KERNEL_SOURCE@/include/asm-generic/div64.h \
  @KERNEL_SOURCE@/include/linux/stat.h \
  arch/arc/include/generated/uapi/asm/stat.h \
  @KERNEL_SOURCE@/include/uapi/asm-generic/stat.h \
  @KERNEL_SOURCE@/include/uapi/linux/stat.h \
  @KERNEL_SOURCE@/include/linux/time.h \
    $(wildcard include/config/arch/uses/gettimeoffset.h) \
    $(wildcard include/config/posix/timers.h) \
  @KERNEL_SOURCE@/include/linux/math64.h \
    $(wildcard include/config/arch/supports/int128.h) \
  @KERNEL_SOURCE@/include/vdso/math64.h \
  @KERNEL_SOURCE@/include/linux/time64.h \
  @KERNEL_SOURCE@/include/vdso/time64.h \
  @KERNEL_SOURCE@/include/uapi/linux/time.h \
  @KERNEL_SOURCE@/include/uapi/linux/time_types.h \
  @KERNEL_SOURCE@/include/linux/time32.h \
  @KERNEL_SOURCE@/include/linux/timex.h \
  @KERNEL_SOURCE@/include/uapi/linux/timex.h \
  @KERNEL_SOURCE@/arch/arc/include/asm/timex.h \
  @KERNEL_SOURCE@/include/asm-generic/timex.h \
  @KERNEL_SOURCE@/include/vdso/time32.h \
  @KERNEL_SOURCE@/include/vdso/time.h \
  @KERNEL_SOURCE@/include/linux/uidgid.h \
    $(wildcard include/config/multiuser.h) \
    $(wildcard include/config/user/ns.h) \
  @KERNEL_SOURCE@/include/linux/highuid.h \
  @KERNEL_SOURCE@/include/linux/kmod.h \
  @KERNEL_SOURCE@/include/linux/umh.h \
  @KERNEL_SOURCE@/include/linux/gfp.h \
    $(wildcard include/config/highmem.h) \
    $(wildcard include/config/zone/dma.h) \
    $(wildcard include/config/zone/dma32.h) \
    $(wildcard include/config/zone/device.h) \
    $(wildcard include/config/numa.h) \
    $(wildcard include/config/pm/sleep.h) \
    $(wildcard include/config/compaction.h) \
    $(wildcard include/config/contig/alloc.h) \
    $(wildcard include/config/cma.h) \
  @KERNEL_SOURCE@/include/linux/mmdebug.h \
    $(wildcard include/config/debug/vm.h) \
    $(wildcard include/config/debug/virtual.h) \
    $(wildcard include/config/debug/vm/pgflags.h) \
  @KERNEL_SOURCE@/include/linux/bug.h \
    $(wildcard include/config/bug/on/data/corruption.h) \
  @KERNEL_SOURCE@/arch/arc/include/asm/bug.h \
  @KERNEL_SOURCE@/arch/arc/include/asm/ptrace.h \
    $(wildcard include/config/arc/has/accl/regs.h) \
    $(wildcard include/config/arc/dsp/save/restore/regs.h) \
  @KERNEL_SOURCE@/arch/arc/include/uapi/asm/ptrace.h \
  @KERNEL_SOURCE@/include/asm-generic/bug.h \
    $(wildcard include/config/bug.h) \
    $(wildcard include/config/generic/bug/relative/pointers.h) \
    $(wildcard include/config/debug/bugverbose.h) \
  @KERNEL_SOURCE@/include/linux/instrumentation.h \
    $(wildcard include/config/debug/entry.h) \
  @KERNEL_SOURCE@/include/linux/mmzone.h \
    $(wildcard include/config/force/max/zoneorder.h) \
    $(wildcard include/config/memory/isolation.h) \
    $(wildcard include/config/zsmalloc.h) \
    $(wildcard include/config/shadow/call/stack.h) \
    $(wildcard include/config/memcg.h) \
    $(wildcard include/config/need/multiple/nodes.h) \
    $(wildcard include/config/sparsemem.h) \
    $(wildcard include/config/memory/hotplug.h) \
    $(wildcard include/config/discontigmem.h) \
    $(wildcard include/config/transparent/hugepage.h) \
    $(wildcard include/config/flat/node/mem/map.h) \
    $(wildcard include/config/page/extension.h) \
    $(wildcard include/config/deferred/struct/page/init.h) \
    $(wildcard include/config/have/memoryless/nodes.h) \
    $(wildcard include/config/flatmem.h) \
    $(wildcard include/config/sparsemem/vmemmap.h) \
    $(wildcard include/config/sparsemem/extreme.h) \
    $(wildcard include/config/memory/hotremove.h) \
    $(wildcard include/config/have/arch/pfn/valid.h) \
    $(wildcard include/config/holes/in/zone.h) \
  @KERNEL_SOURCE@/include/linux/spinlock.h \
    $(wildcard include/config/preemption.h) \
  @KERNEL_SOURCE@/include/linux/preempt.h \
    $(wildcard include/config/preempt/count.h) \
    $(wildcard include/config/trace/preempt/toggle.h) \
    $(wildcard include/config/preempt/notifiers.h) \
  arch/arc/include/generated/asm/preempt.h \
  @KERNEL_SOURCE@/include/asm-generic/preempt.h \
  @KERNEL_SOURCE@/include/linux/thread_info.h \
    $(wildcard include/config/thread/info/in/task.h) \
    $(wildcard include/config/have/arch/within/stack/frames.h) \
    $(wildcard include/config/hardened/usercopy.h) \
  @KERNEL_SOURCE@/include/linux/restart_block.h \
  @KERNEL_SOURCE@/include/linux/errno.h \
  @KERNEL_SOURCE@/include/uapi/linux/errno.h \
  arch/arc/include/generated/uapi/asm/errno.h \
  @KERNEL_SOURCE@/include/uapi/asm-generic/errno.h \
  @KERNEL_SOURCE@/include/uapi/asm-generic/errno-base.h \
  @KERNEL_SOURCE@/arch/arc/include/asm/thread_info.h \
    $(wildcard include/config/16kstacks.h) \
  @KERNEL_SOURCE@/arch/arc/include/asm/page.h \
    $(wildcard include/config/arc/has/pae40.h) \
    $(wildcard include/config/linux/ram/base.h) \
  @KERNEL_SOURCE@/arch/arc/include/uapi/asm/page.h \
    $(wildcard include/config/arc/page/size/16k.h) \
    $(wildcard include/config/arc/page/size/4k.h) \
    $(wildcard include/config/arc/page/size/8k.h) \
  @KERNEL_SOURCE@/include/asm-generic/memory_model.h \
  @KERNEL_SOURCE@/include/linux/pfn.h \
  @KERNEL_SOURCE@/include/asm-generic/getorder.h \
  @KERNEL_SOURCE@/arch/arc/include/asm/segment.h \
  @KERNEL_SOURCE@/include/linux/bottom_half.h \
  @KERNEL_SOURCE@/include/linux/lockdep.h \
    $(wildcard include/config/debug/locking/api/selftests.h) \
  @KERNEL_SOURCE@/include/linux/smp.h \
    $(wildcard include/config/up/late/init.h) \
  @KERNEL_SOURCE@/include/linux/cpumask.h \
    $(wildcard include/config/cpumask/offstack.h) \
    $(wildcard include/config/hotplug/cpu.h) \
    $(wildcard include/config/debug/per/cpu/maps.h) \
  @KERNEL_SOURCE@/include/linux/bitmap.h \
  @KERNEL_SOURCE@/include/linux/string.h \
    $(wildcard include/config/binary/printf.h) \
    $(wildcard include/config/fortify/source.h) \
  @KERNEL_SOURCE@/include/uapi/linux/string.h \
  @KERNEL_SOURCE@/arch/arc/include/asm/string.h \
  @KERNEL_SOURCE@/include/linux/smp_types.h \
  @KERNEL_SOURCE@/include/linux/llist.h \
    $(wildcard include/config/arch/have/nmi/safe/cmpxchg.h) \
  arch/arc/include/generated/asm/mmiowb.h \
  @KERNEL_SOURCE@/include/asm-generic/mmiowb.h \
    $(wildcard include/config/mmiowb.h) \
  @KERNEL_SOURCE@/include/linux/spinlock_up.h \
  @KERNEL_SOURCE@/arch/arc/include/asm/processor.h \
    $(wildcard include/config/arc/fpu/save/restore.h) \
    $(wildcard include/config/arc/kvaddr/size.h) \
  @KERNEL_SOURCE@/arch/arc/include/asm/dsp.h \
    $(wildcard include/config/arc/dsp/agu/userspace.h) \
  @KERNEL_SOURCE@/arch/arc/include/asm/fpu.h \
  @KERNEL_SOURCE@/include/linux/rwlock.h \
    $(wildcard include/config/preempt.h) \
  @KERNEL_SOURCE@/include/linux/spinlock_api_up.h \
  @KERNEL_SOURCE@/include/linux/wait.h \
  @KERNEL_SOURCE@/arch/arc/include/asm/current.h \
    $(wildcard include/config/arc/curr/in/reg.h) \
  @KERNEL_SOURCE@/include/asm-generic/current.h \
  @KERNEL_SOURCE@/include/uapi/linux/wait.h \
  @KERNEL_SOURCE@/include/linux/numa.h \
    $(wildcard include/config/nodes/shift.h) \
    $(wildcard include/config/numa/keep/meminfo.h) \
  @KERNEL_SOURCE@/include/linux/seqlock.h \
  @KERNEL_SOURCE@/include/linux/mutex.h \
    $(wildcard include/config/mutex/spin/on/owner.h) \
    $(wildcard include/config/debug/mutexes.h) \
  @KERNEL_SOURCE@/include/linux/osq_lock.h \
  @KERNEL_SOURCE@/include/linux/debug_locks.h \
  @KERNEL_SOURCE@/include/linux/ww_mutex.h \
    $(wildcard include/config/debug/ww/mutex/slowpath.h) \
  @KERNEL_SOURCE@/include/linux/nodemask.h \
  @KERNEL_SOURCE@/include/linux/pageblock-flags.h \
    $(wildcard include/config/hugetlb/page.h) \
    $(wildcard include/config/hugetlb/page/size/variable.h) \
  @KERNEL_SOURCE@/include/linux/page-flags-layout.h \
    $(wildcard include/config/numa/balancing.h) \
    $(wildcard include/config/kasan/sw/tags.h) \
  include/generated/bounds.h \
  @KERNEL_SOURCE@/include/linux/mm_types.h \
    $(wildcard include/config/have/aligned/struct/page.h) \
    $(wildcard include/config/arch/want/huge/pmd/share.h) \
    $(wildcard include/config/userfaultfd.h) \
    $(wildcard include/config/swap.h) \
    $(wildcard include/config/have/arch/compat/mmap/bases.h) \
    $(wildcard include/config/membarrier.h) \
    $(wildcard include/config/aio.h) \
    $(wildcard include/config/mmu/notifier.h) \
    $(wildcard include/config/arch/want/batched/unmap/tlb/flush.h) \
    $(wildcard include/config/iommu/support.h) \
  @KERNEL_SOURCE@/include/linux/mm_types_task.h \
    $(wildcard include/config/split/ptlock/cpus.h) \
    $(wildcard include/config/arch/enable/split/pmd/ptlock.h) \
  @KERNEL_SOURCE@/include/linux/auxvec.h \
  @KERNEL_SOURCE@/include/uapi/linux/auxvec.h \
  arch/arc/include/generated/uapi/asm/auxvec.h \
  @KERNEL_SOURCE@/include/uapi/asm-generic/auxvec.h \
  @KERNEL_SOURCE@/include/linux/rbtree.h \
  @KERNEL_SOURCE@/include/linux/rcupdate.h \
    $(wildcard include/config/preempt/rcu.h) \
    $(wildcard include/config/tiny/rcu.h) \
    $(wildcard include/config/tasks/rcu/generic.h) \
    $(wildcard include/config/rcu/stall/common.h) \
    $(wildcard include/config/no/hz/full.h) \
    $(wildcard include/config/rcu/nocb/cpu.h) \
    $(wildcard include/config/tasks/rcu.h) \
    $(wildcard include/config/tasks/trace/rcu.h) \
    $(wildcard include/config/tasks/rude/rcu.h) \
    $(wildcard include/config/tree/rcu.h) \
    $(wildcard include/config/debug/objects/rcu/head.h) \
    $(wildcard include/config/prove/rcu.h) \
    $(wildcard include/config/rcu/boost.h) \
    $(wildcard include/config/arch/weak/release/acquire.h) \
  @KERNEL_SOURCE@/include/linux/rcutiny.h \
    $(wildcard include/config/srcu.h) \
  @KERNEL_SOURCE@/include/linux/rwsem.h \
    $(wildcard include/config/rwsem/spin/on/owner.h) \
    $(wildcard include/config/debug/rwsems.h) \
  @KERNEL_SOURCE@/include/linux/err.h \
  @KERNEL_SOURCE@/include/linux/completion.h \
  @KERNEL_SOURCE@/include/linux/swait.h \
  @KERNEL_SOURCE@/include/linux/uprobes.h \
    $(wildcard include/config/uprobes.h) \
  @KERNEL_SOURCE@/include/linux/workqueue.h \
    $(wildcard include/config/debug/objects/work.h) \
    $(wildcard include/config/freezer.h) \
    $(wildcard include/config/wq/watchdog.h) \
  @KERNEL_SOURCE@/include/linux/timer.h \
    $(wildcard include/config/debug/objects/timers.h) \
    $(wildcard include/config/no/hz/common.h) \
  @KERNEL_SOURCE@/include/linux/ktime.h \
  @KERNEL_SOURCE@/include/linux/jiffies.h \
  @KERNEL_SOURCE@/include/vdso/jiffies.h \
  include/generated/timeconst.h \
  @KERNEL_SOURCE@/include/vdso/ktime.h \
  @KERNEL_SOURCE@/include/linux/timekeeping.h \
  @KERNEL_SOURCE@/include/linux/timekeeping32.h \
  @KERNEL_SOURCE@/include/linux/debugobjects.h \
    $(wildcard include/config/debug/objects.h) \
    $(wildcard include/config/debug/objects/free.h) \
  @KERNEL_SOURCE@/arch/arc/include/asm/mmu.h \
    $(wildcard include/config/arc/mmu/v1.h) \
    $(wildcard include/config/arc/mmu/ver.h) \
    $(wildcard include/config/arc/mmu/v2.h) \
    $(wildcard include/config/arc/mmu/v3.h) \
    $(wildcard include/config/arc/mmu/v4.h) \
    $(wildcard include/config/qtn/topaz/head/wdt/canary.h) \
    $(wildcard include/config/arc/dbg/tlb/paranoia.h) \
  @KERNEL_SOURCE@/include/linux/page-flags.h \
    $(wildcard include/config/arch/uses/pg/uncached.h) \
    $(wildcard include/config/memory/failure.h) \
    $(wildcard include/config/idle/page/tracking.h) \
    $(wildcard include/config/thp/swap.h) \
    $(wildcard include/config/ksm.h) \
  @KERNEL_SOURCE@/include/linux/memory_hotplug.h \
    $(wildcard include/config/arch/has/add/pages.h) \
    $(wildcard include/config/have/arch/nodedata/extension.h) \
    $(wildcard include/config/have/bootmem/info/node.h) \
  @KERNEL_SOURCE@/include/linux/notifier.h \
  @KERNEL_SOURCE@/include/linux/srcu.h \
    $(wildcard include/config/tiny/srcu.h) \
  @KERNEL_SOURCE@/include/linux/rcu_segcblist.h \
  @KERNEL_SOURCE@/include/linux/srcutiny.h \
  @KERNEL_SOURCE@/include/linux/topology.h \
    $(wildcard include/config/use/percpu/numa/node/id.h) \
    $(wildcard include/config/sched/smt.h) \
  @KERNEL_SOURCE@/include/linux/arch_topology.h \
    $(wildcard include/config/generic/arch/topology.h) \
  @KERNEL_SOURCE@/include/linux/percpu.h \
    $(wildcard include/config/need/per/cpu/embed/first/chunk.h) \
    $(wildcard include/config/need/per/cpu/page/first/chunk.h) \
  arch/arc/include/generated/asm/topology.h \
  @KERNEL_SOURCE@/include/asm-generic/topology.h \
  @KERNEL_SOURCE@/include/linux/sysctl.h \
    $(wildcard include/config/sysctl.h) \
  @KERNEL_SOURCE@/include/uapi/linux/sysctl.h \
  @KERNEL_SOURCE@/include/linux/elf.h \
    $(wildcard include/config/arch/use/gnu/property.h) \
    $(wildcard include/config/arch/have/elf/prot.h) \
  @KERNEL_SOURCE@/arch/arc/include/asm/elf.h \
  @KERNEL_SOURCE@/include/uapi/linux/elf-em.h \
  @KERNEL_SOURCE@/arch/arc/include/uapi/asm/elf.h \
  @KERNEL_SOURCE@/include/uapi/linux/elf.h \
  @KERNEL_SOURCE@/include/linux/kobject.h \
    $(wildcard include/config/uevent/helper.h) \
    $(wildcard include/config/debug/kobject/release.h) \
  @KERNEL_SOURCE@/include/linux/sysfs.h \
  @KERNEL_SOURCE@/include/linux/kernfs.h \
    $(wildcard include/config/kernfs.h) \
  @KERNEL_SOURCE@/include/linux/idr.h \
  @KERNEL_SOURCE@/include/linux/radix-tree.h \
  @KERNEL_SOURCE@/include/linux/xarray.h \
    $(wildcard include/config/xarray/multi.h) \
  @KERNEL_SOURCE@/include/linux/kconfig.h \
  @KERNEL_SOURCE@/include/linux/sched/mm.h \
    $(wildcard include/config/arch/has/membarrier/callbacks.h) \
  @KERNEL_SOURCE@/include/linux/sched.h \
    $(wildcard include/config/virt/cpu/accounting/native.h) \
    $(wildcard include/config/sched/info.h) \
    $(wildcard include/config/schedstats.h) \
    $(wildcard include/config/fair/group/sched.h) \
    $(wildcard include/config/rt/group/sched.h) \
    $(wildcard include/config/rt/mutexes.h) \
    $(wildcard include/config/uclamp/task.h) \
    $(wildcard include/config/uclamp/buckets/count.h) \
    $(wildcard include/config/cgroup/sched.h) \
    $(wildcard include/config/blk/dev/io/trace.h) \
    $(wildcard include/config/psi.h) \
    $(wildcard include/config/compat/brk.h) \
    $(wildcard include/config/cgroups.h) \
    $(wildcard include/config/blk/cgroup.h) \
    $(wildcard include/config/stackprotector.h) \
    $(wildcard include/config/arch/has/scaled/cputime.h) \
    $(wildcard include/config/virt/cpu/accounting/gen.h) \
    $(wildcard include/config/posix/cputimers.h) \
    $(wildcard include/config/posix/cpu/timers/task/work.h) \
    $(wildcard include/config/keys.h) \
    $(wildcard include/config/sysvipc.h) \
    $(wildcard include/config/detect/hung/task.h) \
    $(wildcard include/config/io/uring.h) \
    $(wildcard include/config/audit.h) \
    $(wildcard include/config/auditsyscall.h) \
    $(wildcard include/config/ubsan.h) \
    $(wildcard include/config/ubsan/trap.h) \
    $(wildcard include/config/block.h) \
    $(wildcard include/config/task/xacct.h) \
    $(wildcard include/config/cpusets.h) \
    $(wildcard include/config/x86/cpu/resctrl.h) \
    $(wildcard include/config/futex.h) \
    $(wildcard include/config/compat.h) \
    $(wildcard include/config/perf/events.h) \
    $(wildcard include/config/rseq.h) \
    $(wildcard include/config/task/delay/acct.h) \
    $(wildcard include/config/fault/injection.h) \
    $(wildcard include/config/latencytop.h) \
    $(wildcard include/config/kunit.h) \
    $(wildcard include/config/function/graph/tracer.h) \
    $(wildcard include/config/bcache.h) \
    $(wildcard include/config/vmap/stack.h) \
    $(wildcard include/config/security.h) \
    $(wildcard include/config/gcc/plugin/stackleak.h) \
    $(wildcard include/config/x86/mce.h) \
    $(wildcard include/config/arch/task/struct/on/stack.h) \
    $(wildcard include/config/debug/rseq.h) \
  @KERNEL_SOURCE@/include/uapi/linux/sched.h \
  @KERNEL_SOURCE@/include/linux/pid.h \
  @KERNEL_SOURCE@/include/linux/rculist.h \
    $(wildcard include/config/prove/rcu/list.h) \
  @KERNEL_SOURCE@/include/linux/refcount.h \
  @KERNEL_SOURCE@/include/linux/sem.h \
  @KERNEL_SOURCE@/include/uapi/linux/sem.h \
  @KERNEL_SOURCE@/include/linux/ipc.h \
  @KERNEL_SOURCE@/include/linux/rhashtable-types.h \
  @KERNEL_SOURCE@/include/uapi/linux/ipc.h \
  arch/arc/include/generated/uapi/asm/ipcbuf.h \
  @KERNEL_SOURCE@/include/uapi/asm-generic/ipcbuf.h \
  arch/arc/include/generated/uapi/asm/sembuf.h \
  @KERNEL_SOURCE@/include/uapi/asm-generic/sembuf.h \
  @KERNEL_SOURCE@/include/linux/shm.h \
  @KERNEL_SOURCE@/include/uapi/linux/shm.h \
  @KERNEL_SOURCE@/include/uapi/asm-generic/hugetlb_encode.h \
  arch/arc/include/generated/uapi/asm/shmbuf.h \
  @KERNEL_SOURCE@/include/uapi/asm-generic/shmbuf.h \
  @KERNEL_SOURCE@/arch/arc/include/asm/shmparam.h \
  @KERNEL_SOURCE@/include/linux/plist.h \
    $(wildcard include/config/debug/plist.h) \
  @KERNEL_SOURCE@/include/linux/hrtimer.h \
    $(wildcard include/config/high/res/timers.h) \
    $(wildcard include/config/time/low/res.h) \
    $(wildcard include/config/timerfd.h) \
  @KERNEL_SOURCE@/include/linux/hrtimer_defs.h \
  @KERNEL_SOURCE@/include/linux/timerqueue.h \
  @KERNEL_SOURCE@/include/linux/seccomp.h \
    $(wildcard include/config/seccomp.h) \
    $(wildcard include/config/have/arch/seccomp/filter.h) \
    $(wildcard include/config/seccomp/filter.h) \
    $(wildcard include/config/checkpoint/restore.h) \
  @KERNEL_SOURCE@/include/uapi/linux/seccomp.h \
  @KERNEL_SOURCE@/include/linux/resource.h \
  @KERNEL_SOURCE@/include/uapi/linux/resource.h \
  arch/arc/include/generated/uapi/asm/resource.h \
  @KERNEL_SOURCE@/include/asm-generic/resource.h \
  @KERNEL_SOURCE@/include/uapi/asm-generic/resource.h \
  @KERNEL_SOURCE@/include/linux/latencytop.h \
  @KERNEL_SOURCE@/include/linux/sched/prio.h \
  @KERNEL_SOURCE@/include/linux/sched/types.h \
  @KERNEL_SOURCE@/include/linux/signal_types.h \
    $(wildcard include/config/old/sigaction.h) \
  @KERNEL_SOURCE@/include/uapi/linux/signal.h \
  @KERNEL_SOURCE@/arch/arc/include/uapi/asm/signal.h \
  @KERNEL_SOURCE@/include/asm-generic/signal.h \
  @KERNEL_SOURCE@/include/uapi/asm-generic/signal.h \
  @KERNEL_SOURCE@/include/uapi/asm-generic/signal-defs.h \
  @KERNEL_SOURCE@/arch/arc/include/uapi/asm/sigcontext.h \
  arch/arc/include/generated/uapi/asm/siginfo.h \
  @KERNEL_SOURCE@/include/uapi/asm-generic/siginfo.h \
  @KERNEL_SOURCE@/include/linux/task_io_accounting.h \
    $(wildcard include/config/task/io/accounting.h) \
  @KERNEL_SOURCE@/include/linux/posix-timers.h \
  @KERNEL_SOURCE@/include/linux/alarmtimer.h \
    $(wildcard include/config/rtc/class.h) \
  @KERNEL_SOURCE@/include/linux/task_work.h \
  @KERNEL_SOURCE@/include/uapi/linux/rseq.h \
  @KERNEL_SOURCE@/include/linux/kcsan.h \
  @KERNEL_SOURCE@/include/linux/sync_core.h \
    $(wildcard include/config/arch/has/sync/core/before/usermode.h) \
  @KERNEL_SOURCE@/include/linux/local_lock.h \
  @KERNEL_SOURCE@/include/linux/local_lock_internal.h \
  @KERNEL_SOURCE@/include/linux/kobject_ns.h \
  @KERNEL_SOURCE@/include/linux/kref.h \
  @KERNEL_SOURCE@/include/linux/moduleparam.h \
    $(wildcard include/config/alpha.h) \
    $(wildcard include/config/ia64.h) \
    $(wildcard include/config/ppc64.h) \
  @KERNEL_SOURCE@/include/linux/jump_label.h \
    $(wildcard include/config/have/arch/jump/label/relative.h) \
  @KERNEL_SOURCE@/include/linux/rbtree_latch.h \
  @KERNEL_SOURCE@/include/linux/error-injection.h \
  @KERNEL_SOURCE@/include/asm-generic/error-injection.h \
  @KERNEL_SOURCE@/include/linux/tracepoint-defs.h \
  @KERNEL_SOURCE@/include/linux/static_key.h \
  @KERNEL_SOURCE@/include/linux/static_call_types.h \
    $(wildcard include/config/have/static/call.h) \
  @KERNEL_SOURCE@/arch/arc/include/asm/module.h \
    $(wildcard include/config/arc/dw2/unwind.h) \
  @KERNEL_SOURCE@/include/asm-generic/module.h \
    $(wildcard include/config/have/mod/arch/specific.h) \
    $(wildcard include/config/modules/use/elf/rel.h) \
    $(wildcard include/config/modules/use/elf/rela.h) \
  @KERNEL_SOURCE@/include/linux/build-salt.h \
    $(wildcard include/config/build/salt.h) \
  @KERNEL_SOURCE@/include/linux/elfnote.h \
  @KERNEL_SOURCE@/include/linux/vermagic.h \
  include/generated/utsrelease.h \
  @KERNEL_SOURCE@/arch/arc/include/asm/vermagic.h \

drivers/net/wireless/realtek/rtlwifi/rtl_pci.mod.o: $(deps_drivers/net/wireless/realtek/rtlwifi/rtl_pci.mod.o)

$(deps_drivers/net/wireless/realtek/rtlwifi/rtl_pci.mod.o):
