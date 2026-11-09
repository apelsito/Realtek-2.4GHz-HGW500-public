cmd_drivers/net/wireless/realtek/rtlwifi/rtl8192ee/pwrseq.o := @TOOLCHAIN_ROOT@/bin/arc-snps-linux-uclibc-gcc -Wp,-MMD,drivers/net/wireless/realtek/rtlwifi/rtl8192ee/.pwrseq.o.d -nostdinc -isystem @TOOLCHAIN_ROOT@/bin/../lib/gcc/arc-snps-linux-uclibc/15.2.0/include -I@KERNEL_SOURCE@/arch/arc/include -I./arch/arc/include/generated -I@KERNEL_SOURCE@/include -I./include -I@KERNEL_SOURCE@/arch/arc/include/uapi -I./arch/arc/include/generated/uapi -I@KERNEL_SOURCE@/include/uapi -I./include/generated/uapi -include @KERNEL_SOURCE@/include/linux/kconfig.h -include @KERNEL_SOURCE@/include/linux/compiler_types.h -D__KERNEL__ -fmacro-prefix-map=@KERNEL_SOURCE@/= -Wall -Wundef -Werror=strict-prototypes -Wno-trigraphs -fno-strict-aliasing -fno-common -fshort-wchar -fno-PIE -Werror=implicit-function-declaration -Werror=implicit-int -Werror=return-type -Wno-format-security -std=gnu89 -fno-common -pipe -fno-builtin -mmedium-calls -D__linux__ -mcpu=arc700 -fsection-anchors -mno-sdata -fcall-used-gp -fno-delete-null-pointer-checks -Wno-frame-address -Wno-format-truncation -Wno-format-overflow -Wno-address-of-packed-member -Os -fno-allow-store-data-races -Wframe-larger-than=1024 -fno-stack-protector -Wimplicit-fallthrough -Wno-unused-but-set-variable -Wno-unused-const-variable -Wno-dangling-pointer -fomit-frame-pointer -ftrivial-auto-var-init=zero -Wdeclaration-after-statement -Wvla -Wno-pointer-sign -Wno-stringop-truncation -Wno-zero-length-bounds -Wno-array-bounds -Wno-stringop-overflow -Wno-restrict -Wno-maybe-uninitialized -fno-strict-overflow -fno-stack-check -fconserve-stack -Werror=date-time -Werror=incompatible-pointer-types -Werror=designated-init -fno-builtin-wcslen -Wno-packed-not-aligned -ffile-prefix-map=@HISTORICAL_OUTPUT@=/f358-output -I @KERNEL_SOURCE@/drivers/net/wireless/realtek/rtlwifi/rtl8192ee -I ./drivers/net/wireless/realtek/rtlwifi/rtl8192ee  -DMODULE -mlong-calls -mno-millicode  -DKBUILD_BASENAME='"pwrseq"' -DKBUILD_MODNAME='"rtl8192ee"' -c -o drivers/net/wireless/realtek/rtlwifi/rtl8192ee/pwrseq.o @KERNEL_SOURCE@/drivers/net/wireless/realtek/rtlwifi/rtl8192ee/pwrseq.c

source_drivers/net/wireless/realtek/rtlwifi/rtl8192ee/pwrseq.o := @KERNEL_SOURCE@/drivers/net/wireless/realtek/rtlwifi/rtl8192ee/pwrseq.c

deps_drivers/net/wireless/realtek/rtlwifi/rtl8192ee/pwrseq.o := \
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
    $(wildcard include/config/retpoline.h) \
    $(wildcard include/config/arch/use/builtin/bswap.h) \
    $(wildcard include/config/kcov.h) \
  @KERNEL_SOURCE@/drivers/net/wireless/realtek/rtlwifi/rtl8192ee/pwrseq.h \
  @KERNEL_SOURCE@/drivers/net/wireless/realtek/rtlwifi/rtl8192ee/../pwrseqcmd.h \
  @KERNEL_SOURCE@/drivers/net/wireless/realtek/rtlwifi/rtl8192ee/../wifi.h \
    $(wildcard include/config/pm.h) \
  @KERNEL_SOURCE@/include/linux/sched.h \
    $(wildcard include/config/debug/atomic/sleep.h) \
    $(wildcard include/config/virt/cpu/accounting/native.h) \
    $(wildcard include/config/smp.h) \
    $(wildcard include/config/sched/info.h) \
    $(wildcard include/config/schedstats.h) \
    $(wildcard include/config/fair/group/sched.h) \
    $(wildcard include/config/rt/group/sched.h) \
    $(wildcard include/config/rt/mutexes.h) \
    $(wildcard include/config/uclamp/task.h) \
    $(wildcard include/config/uclamp/buckets/count.h) \
    $(wildcard include/config/thread/info/in/task.h) \
    $(wildcard include/config/cgroup/sched.h) \
    $(wildcard include/config/preempt/notifiers.h) \
    $(wildcard include/config/blk/dev/io/trace.h) \
    $(wildcard include/config/preempt/rcu.h) \
    $(wildcard include/config/tasks/rcu.h) \
    $(wildcard include/config/tasks/trace/rcu.h) \
    $(wildcard include/config/psi.h) \
    $(wildcard include/config/memcg.h) \
    $(wildcard include/config/compat/brk.h) \
    $(wildcard include/config/cgroups.h) \
    $(wildcard include/config/blk/cgroup.h) \
    $(wildcard include/config/stackprotector.h) \
    $(wildcard include/config/arch/has/scaled/cputime.h) \
    $(wildcard include/config/virt/cpu/accounting/gen.h) \
    $(wildcard include/config/no/hz/full.h) \
    $(wildcard include/config/posix/cputimers.h) \
    $(wildcard include/config/posix/cpu/timers/task/work.h) \
    $(wildcard include/config/keys.h) \
    $(wildcard include/config/sysvipc.h) \
    $(wildcard include/config/detect/hung/task.h) \
    $(wildcard include/config/io/uring.h) \
    $(wildcard include/config/audit.h) \
    $(wildcard include/config/auditsyscall.h) \
    $(wildcard include/config/debug/mutexes.h) \
    $(wildcard include/config/trace/irqflags.h) \
    $(wildcard include/config/lockdep.h) \
    $(wildcard include/config/ubsan.h) \
    $(wildcard include/config/ubsan/trap.h) \
    $(wildcard include/config/block.h) \
    $(wildcard include/config/compaction.h) \
    $(wildcard include/config/task/xacct.h) \
    $(wildcard include/config/cpusets.h) \
    $(wildcard include/config/x86/cpu/resctrl.h) \
    $(wildcard include/config/futex.h) \
    $(wildcard include/config/compat.h) \
    $(wildcard include/config/perf/events.h) \
    $(wildcard include/config/debug/preempt.h) \
    $(wildcard include/config/numa.h) \
    $(wildcard include/config/numa/balancing.h) \
    $(wildcard include/config/rseq.h) \
    $(wildcard include/config/task/delay/acct.h) \
    $(wildcard include/config/fault/injection.h) \
    $(wildcard include/config/latencytop.h) \
    $(wildcard include/config/kasan.h) \
    $(wildcard include/config/kcsan.h) \
    $(wildcard include/config/kunit.h) \
    $(wildcard include/config/function/graph/tracer.h) \
    $(wildcard include/config/tracing.h) \
    $(wildcard include/config/uprobes.h) \
    $(wildcard include/config/bcache.h) \
    $(wildcard include/config/mmu.h) \
    $(wildcard include/config/vmap/stack.h) \
    $(wildcard include/config/livepatch.h) \
    $(wildcard include/config/security.h) \
    $(wildcard include/config/gcc/plugin/stackleak.h) \
    $(wildcard include/config/x86/mce.h) \
    $(wildcard include/config/arch/task/struct/on/stack.h) \
    $(wildcard include/config/preemption.h) \
    $(wildcard include/config/debug/rseq.h) \
  @KERNEL_SOURCE@/include/uapi/linux/sched.h \
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
  @KERNEL_SOURCE@/arch/arc/include/asm/current.h \
    $(wildcard include/config/arc/curr/in/reg.h) \
  @KERNEL_SOURCE@/include/asm-generic/current.h \
  @KERNEL_SOURCE@/include/linux/thread_info.h \
    $(wildcard include/config/have/arch/within/stack/frames.h) \
    $(wildcard include/config/hardened/usercopy.h) \
  @KERNEL_SOURCE@/include/linux/bug.h \
    $(wildcard include/config/generic/bug.h) \
    $(wildcard include/config/bug/on/data/corruption.h) \
  @KERNEL_SOURCE@/arch/arc/include/asm/bug.h \
  @KERNEL_SOURCE@/arch/arc/include/asm/ptrace.h \
    $(wildcard include/config/isa/arcompact.h) \
    $(wildcard include/config/arc/has/accl/regs.h) \
    $(wildcard include/config/arc/dsp/save/restore/regs.h) \
  @KERNEL_SOURCE@/arch/arc/include/uapi/asm/ptrace.h \
  @KERNEL_SOURCE@/include/asm-generic/bug.h \
    $(wildcard include/config/bug.h) \
    $(wildcard include/config/generic/bug/relative/pointers.h) \
    $(wildcard include/config/debug/bugverbose.h) \
  @KERNEL_SOURCE@/include/linux/compiler.h \
    $(wildcard include/config/trace/branch/profiling.h) \
    $(wildcard include/config/profile/all/branches.h) \
    $(wildcard include/config/stack/validation.h) \
  arch/arc/include/generated/asm/rwonce.h \
  @KERNEL_SOURCE@/include/asm-generic/rwonce.h \
  @KERNEL_SOURCE@/include/linux/kasan-checks.h \
  @KERNEL_SOURCE@/include/linux/kcsan-checks.h \
    $(wildcard include/config/kcsan/ignore/atomics.h) \
  @KERNEL_SOURCE@/include/linux/instrumentation.h \
    $(wildcard include/config/debug/entry.h) \
  @KERNEL_SOURCE@/include/linux/kernel.h \
    $(wildcard include/config/preempt/voluntary.h) \
    $(wildcard include/config/preempt/rt.h) \
    $(wildcard include/config/prove/locking.h) \
    $(wildcard include/config/panic/timeout.h) \
    $(wildcard include/config/ftrace/mcount/record.h) \
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
    $(wildcard include/config/modules.h) \
    $(wildcard include/config/trim/unused/ksyms.h) \
    $(wildcard include/config/unused/symbols.h) \
  @KERNEL_SOURCE@/arch/arc/include/asm/linkage.h \
    $(wildcard include/config/arc/has/ll64.h) \
    $(wildcard include/config/arc/has/dccm.h) \
    $(wildcard include/config/arc/has/iccm.h) \
  @KERNEL_SOURCE@/arch/arc/include/asm/dwarf.h \
  @KERNEL_SOURCE@/include/linux/bitops.h \
  @KERNEL_SOURCE@/include/linux/bits.h \
  @KERNEL_SOURCE@/include/linux/const.h \
  @KERNEL_SOURCE@/include/vdso/const.h \
  @KERNEL_SOURCE@/include/uapi/linux/const.h \
  @KERNEL_SOURCE@/include/vdso/bits.h \
  @KERNEL_SOURCE@/include/linux/build_bug.h \
  @KERNEL_SOURCE@/arch/arc/include/asm/bitops.h \
    $(wildcard include/config/arc/has/llsc.h) \
    $(wildcard include/config/isa/arcv2.h) \
  @KERNEL_SOURCE@/arch/arc/include/asm/barrier.h \
  @KERNEL_SOURCE@/include/asm-generic/barrier.h \
  @KERNEL_SOURCE@/arch/arc/include/asm/smp.h \
  @KERNEL_SOURCE@/include/linux/irqflags.h \
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
    $(wildcard include/config/lock/stat.h) \
  @KERNEL_SOURCE@/include/linux/rwlock_types.h \
  arch/arc/include/generated/asm/div64.h \
  @KERNEL_SOURCE@/include/asm-generic/div64.h \
  @KERNEL_SOURCE@/include/linux/restart_block.h \
  @KERNEL_SOURCE@/include/linux/time64.h \
  @KERNEL_SOURCE@/include/linux/math64.h \
    $(wildcard include/config/arch/supports/int128.h) \
  @KERNEL_SOURCE@/include/vdso/math64.h \
  @KERNEL_SOURCE@/include/vdso/time64.h \
  @KERNEL_SOURCE@/include/uapi/linux/time.h \
  @KERNEL_SOURCE@/include/uapi/linux/time_types.h \
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
    $(wildcard include/config/flatmem.h) \
  @KERNEL_SOURCE@/arch/arc/include/uapi/asm/page.h \
    $(wildcard include/config/arc/page/size/16k.h) \
    $(wildcard include/config/arc/page/size/4k.h) \
    $(wildcard include/config/arc/page/size/8k.h) \
  @KERNEL_SOURCE@/include/asm-generic/memory_model.h \
    $(wildcard include/config/discontigmem.h) \
    $(wildcard include/config/sparsemem/vmemmap.h) \
    $(wildcard include/config/sparsemem.h) \
  @KERNEL_SOURCE@/include/linux/pfn.h \
  @KERNEL_SOURCE@/include/asm-generic/getorder.h \
  @KERNEL_SOURCE@/arch/arc/include/asm/segment.h \
  @KERNEL_SOURCE@/include/linux/pid.h \
  @KERNEL_SOURCE@/include/linux/rculist.h \
    $(wildcard include/config/prove/rcu/list.h) \
  @KERNEL_SOURCE@/include/linux/list.h \
    $(wildcard include/config/debug/list.h) \
  @KERNEL_SOURCE@/include/linux/poison.h \
    $(wildcard include/config/illegal/pointer/value.h) \
    $(wildcard include/config/page/poisoning/zero.h) \
  @KERNEL_SOURCE@/include/linux/rcupdate.h \
    $(wildcard include/config/tiny/rcu.h) \
    $(wildcard include/config/tasks/rcu/generic.h) \
    $(wildcard include/config/rcu/stall/common.h) \
    $(wildcard include/config/rcu/nocb/cpu.h) \
    $(wildcard include/config/tasks/rude/rcu.h) \
    $(wildcard include/config/tree/rcu.h) \
    $(wildcard include/config/debug/objects/rcu/head.h) \
    $(wildcard include/config/hotplug/cpu.h) \
    $(wildcard include/config/prove/rcu.h) \
    $(wildcard include/config/rcu/boost.h) \
    $(wildcard include/config/arch/weak/release/acquire.h) \
  @KERNEL_SOURCE@/include/linux/preempt.h \
    $(wildcard include/config/preempt/count.h) \
    $(wildcard include/config/trace/preempt/toggle.h) \
  arch/arc/include/generated/asm/preempt.h \
  @KERNEL_SOURCE@/include/asm-generic/preempt.h \
  @KERNEL_SOURCE@/include/linux/bottom_half.h \
  @KERNEL_SOURCE@/include/linux/lockdep.h \
    $(wildcard include/config/debug/locking/api/selftests.h) \
  @KERNEL_SOURCE@/include/linux/smp.h \
    $(wildcard include/config/up/late/init.h) \
  @KERNEL_SOURCE@/include/linux/cpumask.h \
    $(wildcard include/config/cpumask/offstack.h) \
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
  @KERNEL_SOURCE@/arch/arc/include/asm/processor.h \
    $(wildcard include/config/arc/fpu/save/restore.h) \
    $(wildcard include/config/arc/kvaddr/size.h) \
  @KERNEL_SOURCE@/arch/arc/include/asm/dsp.h \
    $(wildcard include/config/arc/dsp/agu/userspace.h) \
  @KERNEL_SOURCE@/arch/arc/include/asm/fpu.h \
  @KERNEL_SOURCE@/include/linux/rcutiny.h \
    $(wildcard include/config/srcu.h) \
  @KERNEL_SOURCE@/include/linux/wait.h \
  @KERNEL_SOURCE@/include/linux/spinlock.h \
  arch/arc/include/generated/asm/mmiowb.h \
  @KERNEL_SOURCE@/include/asm-generic/mmiowb.h \
    $(wildcard include/config/mmiowb.h) \
  @KERNEL_SOURCE@/include/linux/spinlock_up.h \
  @KERNEL_SOURCE@/include/linux/rwlock.h \
    $(wildcard include/config/preempt.h) \
  @KERNEL_SOURCE@/include/linux/spinlock_api_up.h \
  @KERNEL_SOURCE@/include/uapi/linux/wait.h \
  @KERNEL_SOURCE@/include/linux/refcount.h \
  @KERNEL_SOURCE@/include/linux/sem.h \
  @KERNEL_SOURCE@/include/uapi/linux/sem.h \
  @KERNEL_SOURCE@/include/linux/ipc.h \
  @KERNEL_SOURCE@/include/linux/uidgid.h \
    $(wildcard include/config/multiuser.h) \
    $(wildcard include/config/user/ns.h) \
  @KERNEL_SOURCE@/include/linux/highuid.h \
  @KERNEL_SOURCE@/include/linux/rhashtable-types.h \
  @KERNEL_SOURCE@/include/linux/mutex.h \
    $(wildcard include/config/mutex/spin/on/owner.h) \
  @KERNEL_SOURCE@/include/linux/osq_lock.h \
  @KERNEL_SOURCE@/include/linux/debug_locks.h \
  @KERNEL_SOURCE@/include/linux/workqueue.h \
    $(wildcard include/config/debug/objects/work.h) \
    $(wildcard include/config/freezer.h) \
    $(wildcard include/config/sysfs.h) \
    $(wildcard include/config/wq/watchdog.h) \
  @KERNEL_SOURCE@/include/linux/timer.h \
    $(wildcard include/config/debug/objects/timers.h) \
    $(wildcard include/config/no/hz/common.h) \
  @KERNEL_SOURCE@/include/linux/ktime.h \
  @KERNEL_SOURCE@/include/linux/time.h \
    $(wildcard include/config/arch/uses/gettimeoffset.h) \
    $(wildcard include/config/posix/timers.h) \
  @KERNEL_SOURCE@/include/linux/time32.h \
  @KERNEL_SOURCE@/include/linux/timex.h \
  @KERNEL_SOURCE@/include/uapi/linux/timex.h \
  @KERNEL_SOURCE@/arch/arc/include/asm/timex.h \
  @KERNEL_SOURCE@/include/asm-generic/timex.h \
  @KERNEL_SOURCE@/include/vdso/time32.h \
  @KERNEL_SOURCE@/include/vdso/time.h \
  @KERNEL_SOURCE@/include/linux/jiffies.h \
  @KERNEL_SOURCE@/include/vdso/jiffies.h \
  include/generated/timeconst.h \
  @KERNEL_SOURCE@/include/vdso/ktime.h \
  @KERNEL_SOURCE@/include/linux/timekeeping.h \
  @KERNEL_SOURCE@/include/linux/timekeeping32.h \
  @KERNEL_SOURCE@/include/linux/debugobjects.h \
    $(wildcard include/config/debug/objects.h) \
    $(wildcard include/config/debug/objects/free.h) \
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
  @KERNEL_SOURCE@/include/linux/rbtree.h \
  @KERNEL_SOURCE@/include/linux/percpu.h \
    $(wildcard include/config/need/per/cpu/embed/first/chunk.h) \
    $(wildcard include/config/need/per/cpu/page/first/chunk.h) \
  @KERNEL_SOURCE@/include/linux/mmdebug.h \
    $(wildcard include/config/debug/vm.h) \
    $(wildcard include/config/debug/virtual.h) \
    $(wildcard include/config/debug/vm/pgflags.h) \
  @KERNEL_SOURCE@/include/linux/seqlock.h \
  @KERNEL_SOURCE@/include/linux/ww_mutex.h \
    $(wildcard include/config/debug/ww/mutex/slowpath.h) \
  @KERNEL_SOURCE@/include/linux/timerqueue.h \
  @KERNEL_SOURCE@/include/linux/seccomp.h \
    $(wildcard include/config/seccomp.h) \
    $(wildcard include/config/have/arch/seccomp/filter.h) \
    $(wildcard include/config/seccomp/filter.h) \
    $(wildcard include/config/checkpoint/restore.h) \
  @KERNEL_SOURCE@/include/uapi/linux/seccomp.h \
  @KERNEL_SOURCE@/include/linux/nodemask.h \
    $(wildcard include/config/highmem.h) \
  @KERNEL_SOURCE@/include/linux/numa.h \
    $(wildcard include/config/nodes/shift.h) \
    $(wildcard include/config/numa/keep/meminfo.h) \
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
  @KERNEL_SOURCE@/include/linux/mm_types_task.h \
    $(wildcard include/config/arch/want/batched/unmap/tlb/flush.h) \
    $(wildcard include/config/split/ptlock/cpus.h) \
    $(wildcard include/config/arch/enable/split/pmd/ptlock.h) \
  @KERNEL_SOURCE@/include/linux/task_io_accounting.h \
    $(wildcard include/config/task/io/accounting.h) \
  @KERNEL_SOURCE@/include/linux/posix-timers.h \
  @KERNEL_SOURCE@/include/linux/alarmtimer.h \
    $(wildcard include/config/rtc/class.h) \
  @KERNEL_SOURCE@/include/linux/task_work.h \
  @KERNEL_SOURCE@/include/uapi/linux/rseq.h \
  @KERNEL_SOURCE@/include/linux/kcsan.h \
  @KERNEL_SOURCE@/include/linux/firmware.h \
    $(wildcard include/config/fw/loader.h) \
  @KERNEL_SOURCE@/include/linux/gfp.h \
    $(wildcard include/config/zone/dma.h) \
    $(wildcard include/config/zone/dma32.h) \
    $(wildcard include/config/zone/device.h) \
    $(wildcard include/config/pm/sleep.h) \
    $(wildcard include/config/contig/alloc.h) \
    $(wildcard include/config/cma.h) \
  @KERNEL_SOURCE@/include/linux/mmzone.h \
    $(wildcard include/config/force/max/zoneorder.h) \
    $(wildcard include/config/memory/isolation.h) \
    $(wildcard include/config/zsmalloc.h) \
    $(wildcard include/config/shadow/call/stack.h) \
    $(wildcard include/config/need/multiple/nodes.h) \
    $(wildcard include/config/memory/hotplug.h) \
    $(wildcard include/config/transparent/hugepage.h) \
    $(wildcard include/config/flat/node/mem/map.h) \
    $(wildcard include/config/page/extension.h) \
    $(wildcard include/config/deferred/struct/page/init.h) \
    $(wildcard include/config/have/memoryless/nodes.h) \
    $(wildcard include/config/sparsemem/extreme.h) \
    $(wildcard include/config/memory/hotremove.h) \
    $(wildcard include/config/have/arch/pfn/valid.h) \
    $(wildcard include/config/holes/in/zone.h) \
  @KERNEL_SOURCE@/include/linux/pageblock-flags.h \
    $(wildcard include/config/hugetlb/page.h) \
    $(wildcard include/config/hugetlb/page/size/variable.h) \
  @KERNEL_SOURCE@/include/linux/page-flags-layout.h \
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
    $(wildcard include/config/iommu/support.h) \
  @KERNEL_SOURCE@/include/linux/auxvec.h \
  @KERNEL_SOURCE@/include/uapi/linux/auxvec.h \
  arch/arc/include/generated/uapi/asm/auxvec.h \
  @KERNEL_SOURCE@/include/uapi/asm-generic/auxvec.h \
  @KERNEL_SOURCE@/include/linux/rwsem.h \
    $(wildcard include/config/rwsem/spin/on/owner.h) \
    $(wildcard include/config/debug/rwsems.h) \
  @KERNEL_SOURCE@/include/linux/err.h \
  @KERNEL_SOURCE@/include/linux/completion.h \
  @KERNEL_SOURCE@/include/linux/swait.h \
  @KERNEL_SOURCE@/include/linux/uprobes.h \
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
    $(wildcard include/config/tree/srcu.h) \
  @KERNEL_SOURCE@/include/linux/srcu.h \
    $(wildcard include/config/tiny/srcu.h) \
  @KERNEL_SOURCE@/include/linux/rcu_segcblist.h \
  @KERNEL_SOURCE@/include/linux/srcutiny.h \
  @KERNEL_SOURCE@/include/linux/topology.h \
    $(wildcard include/config/use/percpu/numa/node/id.h) \
    $(wildcard include/config/sched/smt.h) \
  @KERNEL_SOURCE@/include/linux/arch_topology.h \
    $(wildcard include/config/generic/arch/topology.h) \
  arch/arc/include/generated/asm/topology.h \
  @KERNEL_SOURCE@/include/asm-generic/topology.h \
  @KERNEL_SOURCE@/include/linux/etherdevice.h \
    $(wildcard include/config/have/efficient/unaligned/access.h) \
  @KERNEL_SOURCE@/include/linux/if_ether.h \
  @KERNEL_SOURCE@/include/linux/skbuff.h \
    $(wildcard include/config/openmitrastar/qdrv/compat.h) \
    $(wildcard include/config/nf/conntrack.h) \
    $(wildcard include/config/bridge/netfilter.h) \
    $(wildcard include/config/net/tc/skb/ext.h) \
    $(wildcard include/config/skb/extensions.h) \
    $(wildcard include/config/ipv6/ndisc/nodetype.h) \
    $(wildcard include/config/net/switchdev.h) \
    $(wildcard include/config/net/cls/act.h) \
    $(wildcard include/config/net/redirect.h) \
    $(wildcard include/config/tls/device.h) \
    $(wildcard include/config/net/sched.h) \
    $(wildcard include/config/net/rx/busy/poll.h) \
    $(wildcard include/config/xps.h) \
    $(wildcard include/config/network/secmark.h) \
    $(wildcard include/config/tracepoints.h) \
    $(wildcard include/config/debug/net.h) \
    $(wildcard include/config/network/phy/timestamping.h) \
    $(wildcard include/config/xfrm.h) \
    $(wildcard include/config/mptcp.h) \
    $(wildcard include/config/netfilter/xt/target/trace.h) \
    $(wildcard include/config/nf/tables.h) \
    $(wildcard include/config/ip/vs.h) \
  @KERNEL_SOURCE@/include/linux/bvec.h \
  @KERNEL_SOURCE@/include/linux/mm.h \
    $(wildcard include/config/sysctl.h) \
    $(wildcard include/config/have/arch/mmap/rnd/bits.h) \
    $(wildcard include/config/have/arch/mmap/rnd/compat/bits.h) \
    $(wildcard include/config/mem/soft/dirty.h) \
    $(wildcard include/config/arch/uses/high/vma/flags.h) \
    $(wildcard include/config/arch/has/pkeys.h) \
    $(wildcard include/config/ppc.h) \
    $(wildcard include/config/x86.h) \
    $(wildcard include/config/parisc.h) \
    $(wildcard include/config/ia64.h) \
    $(wildcard include/config/sparc64.h) \
    $(wildcard include/config/arm64/mte.h) \
    $(wildcard include/config/stack/growsup.h) \
    $(wildcard include/config/shmem.h) \
    $(wildcard include/config/dev/pagemap/ops.h) \
    $(wildcard include/config/device/private.h) \
    $(wildcard include/config/pci/p2pdma.h) \
    $(wildcard include/config/arch/has/pte/special.h) \
    $(wildcard include/config/arch/has/pte/devmap.h) \
    $(wildcard include/config/debug/vm/rb.h) \
    $(wildcard include/config/page/poisoning.h) \
    $(wildcard include/config/init/on/alloc/default/on.h) \
    $(wildcard include/config/init/on/free/default/on.h) \
    $(wildcard include/config/debug/pagealloc.h) \
    $(wildcard include/config/arch/has/set/direct/map.h) \
    $(wildcard include/config/hibernation.h) \
    $(wildcard include/config/hugetlbfs.h) \
    $(wildcard include/config/mapping/dirty/helpers.h) \
  @KERNEL_SOURCE@/include/linux/mmap_lock.h \
  @KERNEL_SOURCE@/include/linux/range.h \
  @KERNEL_SOURCE@/include/linux/percpu-refcount.h \
  @KERNEL_SOURCE@/include/linux/bit_spinlock.h \
  @KERNEL_SOURCE@/include/linux/shrinker.h \
  @KERNEL_SOURCE@/include/linux/page_ext.h \
  @KERNEL_SOURCE@/include/linux/stacktrace.h \
    $(wildcard include/config/stacktrace.h) \
    $(wildcard include/config/arch/stackwalk.h) \
    $(wildcard include/config/have/reliable/stacktrace.h) \
  @KERNEL_SOURCE@/include/linux/stackdepot.h \
  @KERNEL_SOURCE@/include/linux/page_ref.h \
    $(wildcard include/config/debug/page/ref.h) \
  @KERNEL_SOURCE@/include/linux/tracepoint-defs.h \
  @KERNEL_SOURCE@/include/linux/static_key.h \
  @KERNEL_SOURCE@/include/linux/jump_label.h \
    $(wildcard include/config/jump/label.h) \
    $(wildcard include/config/have/arch/jump/label/relative.h) \
  @KERNEL_SOURCE@/include/linux/memremap.h \
  @KERNEL_SOURCE@/include/linux/ioport.h \
    $(wildcard include/config/io/strict/devmem.h) \
  @KERNEL_SOURCE@/include/linux/overflow.h \
  @KERNEL_SOURCE@/include/linux/sizes.h \
  @KERNEL_SOURCE@/include/linux/pgtable.h \
    $(wildcard include/config/pgtable/levels.h) \
    $(wildcard include/config/highpte.h) \
    $(wildcard include/config/have/arch/transparent/hugepage/pud.h) \
    $(wildcard include/config/have/arch/soft/dirty.h) \
    $(wildcard include/config/arch/enable/thp/migration.h) \
    $(wildcard include/config/have/arch/huge/vmap.h) \
    $(wildcard include/config/x86/espfix64.h) \
  @KERNEL_SOURCE@/arch/arc/include/asm/pgtable.h \
    $(wildcard include/config/arc/cache/pages.h) \
    $(wildcard include/config/arc/hugepage/16m.h) \
    $(wildcard include/config/arc/hugepage/2m.h) \
  @KERNEL_SOURCE@/include/asm-generic/pgtable-nopmd.h \
  @KERNEL_SOURCE@/include/asm-generic/pgtable-nopud.h \
  @KERNEL_SOURCE@/include/asm-generic/pgtable-nop4d.h \
  @KERNEL_SOURCE@/include/asm-generic/pgtable_uffd.h \
    $(wildcard include/config/have/arch/userfaultfd/wp.h) \
  @KERNEL_SOURCE@/include/linux/huge_mm.h \
  @KERNEL_SOURCE@/include/linux/sched/coredump.h \
    $(wildcard include/config/core/dump/default/elf/headers.h) \
  @KERNEL_SOURCE@/include/linux/fs.h \
    $(wildcard include/config/read/only/thp/for/fs.h) \
    $(wildcard include/config/fs/posix/acl.h) \
    $(wildcard include/config/cgroup/writeback.h) \
    $(wildcard include/config/ima.h) \
    $(wildcard include/config/file/locking.h) \
    $(wildcard include/config/fsnotify.h) \
    $(wildcard include/config/fs/encryption.h) \
    $(wildcard include/config/fs/verity.h) \
    $(wildcard include/config/epoll.h) \
    $(wildcard include/config/unicode.h) \
    $(wildcard include/config/quota.h) \
    $(wildcard include/config/fs/dax.h) \
    $(wildcard include/config/mandatory/file/locking.h) \
    $(wildcard include/config/migration.h) \
  @KERNEL_SOURCE@/include/linux/wait_bit.h \
  @KERNEL_SOURCE@/include/linux/kdev_t.h \
  @KERNEL_SOURCE@/include/uapi/linux/kdev_t.h \
  @KERNEL_SOURCE@/include/linux/dcache.h \
  @KERNEL_SOURCE@/include/linux/rculist_bl.h \
  @KERNEL_SOURCE@/include/linux/list_bl.h \
  @KERNEL_SOURCE@/include/linux/lockref.h \
    $(wildcard include/config/arch/use/cmpxchg/lockref.h) \
  @KERNEL_SOURCE@/include/linux/stringhash.h \
    $(wildcard include/config/dcache/word/access.h) \
  @KERNEL_SOURCE@/include/linux/hash.h \
    $(wildcard include/config/have/arch/hash.h) \
  @KERNEL_SOURCE@/include/linux/path.h \
  @KERNEL_SOURCE@/include/linux/stat.h \
  arch/arc/include/generated/uapi/asm/stat.h \
  @KERNEL_SOURCE@/include/uapi/asm-generic/stat.h \
  @KERNEL_SOURCE@/include/uapi/linux/stat.h \
  @KERNEL_SOURCE@/include/linux/list_lru.h \
    $(wildcard include/config/memcg/kmem.h) \
  @KERNEL_SOURCE@/include/linux/radix-tree.h \
  @KERNEL_SOURCE@/include/linux/xarray.h \
    $(wildcard include/config/xarray/multi.h) \
  @KERNEL_SOURCE@/include/linux/kconfig.h \
  @KERNEL_SOURCE@/include/linux/sched/mm.h \
    $(wildcard include/config/arch/has/membarrier/callbacks.h) \
  @KERNEL_SOURCE@/include/linux/sync_core.h \
    $(wildcard include/config/arch/has/sync/core/before/usermode.h) \
  @KERNEL_SOURCE@/include/linux/local_lock.h \
  @KERNEL_SOURCE@/include/linux/local_lock_internal.h \
  @KERNEL_SOURCE@/include/linux/capability.h \
  @KERNEL_SOURCE@/include/uapi/linux/capability.h \
  @KERNEL_SOURCE@/include/linux/semaphore.h \
  @KERNEL_SOURCE@/include/linux/fcntl.h \
    $(wildcard include/config/arch/32bit/off/t.h) \
  @KERNEL_SOURCE@/include/uapi/linux/fcntl.h \
  arch/arc/include/generated/uapi/asm/fcntl.h \
  @KERNEL_SOURCE@/include/uapi/asm-generic/fcntl.h \
  @KERNEL_SOURCE@/include/uapi/linux/openat2.h \
  @KERNEL_SOURCE@/include/linux/migrate_mode.h \
  @KERNEL_SOURCE@/include/linux/percpu-rwsem.h \
  @KERNEL_SOURCE@/include/linux/rcuwait.h \
  @KERNEL_SOURCE@/include/linux/sched/signal.h \
    $(wildcard include/config/sched/autogroup.h) \
    $(wildcard include/config/bsd/process/acct.h) \
    $(wildcard include/config/taskstats.h) \
  @KERNEL_SOURCE@/include/linux/signal.h \
    $(wildcard include/config/proc/fs.h) \
  @KERNEL_SOURCE@/include/linux/sched/jobctl.h \
  @KERNEL_SOURCE@/include/linux/sched/task.h \
    $(wildcard include/config/have/exit/thread.h) \
    $(wildcard include/config/arch/wants/dynamic/task/struct.h) \
    $(wildcard include/config/have/arch/thread/struct/whitelist.h) \
  @KERNEL_SOURCE@/include/linux/uaccess.h \
    $(wildcard include/config/set/fs.h) \
  @KERNEL_SOURCE@/include/linux/fault-inject-usercopy.h \
    $(wildcard include/config/fault/injection/usercopy.h) \
  @KERNEL_SOURCE@/include/linux/instrumented.h \
  @KERNEL_SOURCE@/arch/arc/include/asm/uaccess.h \
    $(wildcard include/config/cc/optimize/for/size.h) \
  @KERNEL_SOURCE@/include/asm-generic/uaccess.h \
    $(wildcard include/config/uaccess/memcpy.h) \
  arch/arc/include/generated/asm/extable.h \
  @KERNEL_SOURCE@/include/asm-generic/extable.h \
  @KERNEL_SOURCE@/include/linux/cred.h \
    $(wildcard include/config/debug/credentials.h) \
  @KERNEL_SOURCE@/include/linux/key.h \
    $(wildcard include/config/key/notifications.h) \
    $(wildcard include/config/net.h) \
  @KERNEL_SOURCE@/include/linux/sysctl.h \
  @KERNEL_SOURCE@/include/uapi/linux/sysctl.h \
  @KERNEL_SOURCE@/include/linux/assoc_array.h \
    $(wildcard include/config/associative/array.h) \
  @KERNEL_SOURCE@/include/linux/sched/user.h \
    $(wildcard include/config/posix/mqueue.h) \
    $(wildcard include/config/bpf/syscall.h) \
    $(wildcard include/config/watch/queue.h) \
  @KERNEL_SOURCE@/include/linux/ratelimit.h \
  @KERNEL_SOURCE@/include/linux/rcu_sync.h \
  @KERNEL_SOURCE@/include/linux/delayed_call.h \
  @KERNEL_SOURCE@/include/linux/uuid.h \
  @KERNEL_SOURCE@/include/uapi/linux/uuid.h \
  @KERNEL_SOURCE@/include/linux/errseq.h \
  @KERNEL_SOURCE@/include/linux/ioprio.h \
  @KERNEL_SOURCE@/include/linux/sched/rt.h \
  @KERNEL_SOURCE@/include/linux/iocontext.h \
  @KERNEL_SOURCE@/include/linux/fs_types.h \
  @KERNEL_SOURCE@/include/uapi/linux/fs.h \
  @KERNEL_SOURCE@/include/uapi/linux/ioctl.h \
  arch/arc/include/generated/uapi/asm/ioctl.h \
  @KERNEL_SOURCE@/include/asm-generic/ioctl.h \
  @KERNEL_SOURCE@/include/uapi/asm-generic/ioctl.h \
  @KERNEL_SOURCE@/include/linux/quota.h \
    $(wildcard include/config/quota/netlink/interface.h) \
  @KERNEL_SOURCE@/include/linux/percpu_counter.h \
  @KERNEL_SOURCE@/include/uapi/linux/dqblk_xfs.h \
  @KERNEL_SOURCE@/include/linux/dqblk_v1.h \
  @KERNEL_SOURCE@/include/linux/dqblk_v2.h \
  @KERNEL_SOURCE@/include/linux/dqblk_qtree.h \
  @KERNEL_SOURCE@/include/linux/projid.h \
  @KERNEL_SOURCE@/include/uapi/linux/quota.h \
  @KERNEL_SOURCE@/include/linux/nfs_fs_i.h \
  @KERNEL_SOURCE@/include/linux/vmstat.h \
    $(wildcard include/config/vm/event/counters.h) \
    $(wildcard include/config/debug/tlbflush.h) \
    $(wildcard include/config/debug/vm/vmacache.h) \
  @KERNEL_SOURCE@/include/linux/vm_event_item.h \
    $(wildcard include/config/memory/balloon.h) \
    $(wildcard include/config/balloon/compaction.h) \
  @KERNEL_SOURCE@/include/linux/socket.h \
  arch/arc/include/generated/uapi/asm/socket.h \
  @KERNEL_SOURCE@/include/uapi/asm-generic/socket.h \
  arch/arc/include/generated/uapi/asm/sockios.h \
  @KERNEL_SOURCE@/include/uapi/asm-generic/sockios.h \
  @KERNEL_SOURCE@/include/uapi/linux/sockios.h \
  @KERNEL_SOURCE@/include/linux/uio.h \
    $(wildcard include/config/arch/has/uaccess/flushcache.h) \
    $(wildcard include/config/arch/has/copy/mc.h) \
  @KERNEL_SOURCE@/include/uapi/linux/uio.h \
  @KERNEL_SOURCE@/include/uapi/linux/socket.h \
  @KERNEL_SOURCE@/include/linux/openmitrastar_qtn_skb.h \
  @KERNEL_SOURCE@/include/linux/net.h \
  @KERNEL_SOURCE@/include/linux/random.h \
    $(wildcard include/config/arch/random.h) \
  @KERNEL_SOURCE@/include/linux/once.h \
  @KERNEL_SOURCE@/include/uapi/linux/random.h \
  @KERNEL_SOURCE@/include/linux/irqnr.h \
  @KERNEL_SOURCE@/include/uapi/linux/irqnr.h \
  @KERNEL_SOURCE@/include/linux/prandom.h \
  @KERNEL_SOURCE@/include/linux/siphash.h \
  @KERNEL_SOURCE@/include/linux/sockptr.h \
  @KERNEL_SOURCE@/include/linux/slab.h \
    $(wildcard include/config/debug/slab.h) \
    $(wildcard include/config/failslab.h) \
    $(wildcard include/config/have/hardened/usercopy/allocator.h) \
    $(wildcard include/config/slab.h) \
    $(wildcard include/config/slub.h) \
    $(wildcard include/config/slob.h) \
  @KERNEL_SOURCE@/include/linux/kasan.h \
    $(wildcard include/config/kasan/vmalloc.h) \
    $(wildcard include/config/kasan/generic.h) \
  @KERNEL_SOURCE@/include/uapi/linux/net.h \
  @KERNEL_SOURCE@/include/linux/textsearch.h \
  @KERNEL_SOURCE@/include/net/checksum.h \
  @KERNEL_SOURCE@/arch/arc/include/asm/checksum.h \
  @KERNEL_SOURCE@/include/asm-generic/checksum.h \
  @KERNEL_SOURCE@/include/linux/dma-mapping.h \
    $(wildcard include/config/dma/api/debug.h) \
    $(wildcard include/config/has/dma.h) \
    $(wildcard include/config/need/dma/map/state.h) \
  @KERNEL_SOURCE@/include/linux/device.h \
    $(wildcard include/config/debug/devres.h) \
    $(wildcard include/config/energy/model.h) \
    $(wildcard include/config/generic/msi/irq/domain.h) \
    $(wildcard include/config/pinctrl.h) \
    $(wildcard include/config/generic/msi/irq.h) \
    $(wildcard include/config/dma/ops.h) \
    $(wildcard include/config/dma/declare/coherent.h) \
    $(wildcard include/config/dma/cma.h) \
    $(wildcard include/config/arch/has/sync/dma/for/device.h) \
    $(wildcard include/config/arch/has/sync/dma/for/cpu.h) \
    $(wildcard include/config/arch/has/sync/dma/for/cpu/all.h) \
    $(wildcard include/config/dma/ops/bypass.h) \
    $(wildcard include/config/of.h) \
    $(wildcard include/config/devtmpfs.h) \
    $(wildcard include/config/sysfs/deprecated.h) \
  @KERNEL_SOURCE@/include/linux/dev_printk.h \
  @KERNEL_SOURCE@/include/linux/energy_model.h \
  @KERNEL_SOURCE@/include/linux/kobject.h \
    $(wildcard include/config/uevent/helper.h) \
    $(wildcard include/config/debug/kobject/release.h) \
  @KERNEL_SOURCE@/include/linux/sysfs.h \
  @KERNEL_SOURCE@/include/linux/kernfs.h \
    $(wildcard include/config/kernfs.h) \
  @KERNEL_SOURCE@/include/linux/idr.h \
  @KERNEL_SOURCE@/include/linux/kobject_ns.h \
  @KERNEL_SOURCE@/include/linux/kref.h \
  @KERNEL_SOURCE@/include/linux/sched/cpufreq.h \
    $(wildcard include/config/cpu/freq.h) \
  @KERNEL_SOURCE@/include/linux/sched/topology.h \
    $(wildcard include/config/sched/debug.h) \
    $(wildcard include/config/sched/mc.h) \
  @KERNEL_SOURCE@/include/linux/sched/idle.h \
  @KERNEL_SOURCE@/include/linux/klist.h \
  @KERNEL_SOURCE@/include/linux/pm.h \
    $(wildcard include/config/vt/console/sleep.h) \
    $(wildcard include/config/pm/clk.h) \
    $(wildcard include/config/pm/generic/domains.h) \
  @KERNEL_SOURCE@/include/linux/device/bus.h \
    $(wildcard include/config/acpi.h) \
  @KERNEL_SOURCE@/include/linux/device/class.h \
  @KERNEL_SOURCE@/include/linux/device/driver.h \
  arch/arc/include/generated/asm/device.h \
  @KERNEL_SOURCE@/include/asm-generic/device.h \
  @KERNEL_SOURCE@/include/linux/pm_wakeup.h \
  @KERNEL_SOURCE@/include/linux/dma-direction.h \
  @KERNEL_SOURCE@/include/linux/scatterlist.h \
    $(wildcard include/config/need/sg/dma/length.h) \
    $(wildcard include/config/debug/sg.h) \
    $(wildcard include/config/sgl/alloc.h) \
    $(wildcard include/config/arch/no/sg/chain.h) \
    $(wildcard include/config/sg/pool.h) \
  @KERNEL_SOURCE@/arch/arc/include/asm/io.h \
  @KERNEL_SOURCE@/arch/arc/include/asm/unaligned.h \
    $(wildcard include/config/arc/emul/unaligned.h) \
  @KERNEL_SOURCE@/include/asm-generic/unaligned.h \
  @KERNEL_SOURCE@/include/linux/unaligned/le_struct.h \
  @KERNEL_SOURCE@/include/linux/unaligned/packed_struct.h \
  @KERNEL_SOURCE@/include/linux/unaligned/be_byteshift.h \
  @KERNEL_SOURCE@/include/linux/unaligned/generic.h \
  @KERNEL_SOURCE@/include/asm-generic/io.h \
    $(wildcard include/config/generic/iomap.h) \
    $(wildcard include/config/generic/ioremap.h) \
    $(wildcard include/config/has/ioport/map.h) \
    $(wildcard include/config/virt/to/bus.h) \
  @KERNEL_SOURCE@/include/asm-generic/pci_iomap.h \
    $(wildcard include/config/pci.h) \
    $(wildcard include/config/no/generic/pci/ioport/map.h) \
    $(wildcard include/config/generic/pci/iomap.h) \
  @KERNEL_SOURCE@/include/linux/logic_pio.h \
    $(wildcard include/config/indirect/pio.h) \
  @KERNEL_SOURCE@/include/linux/fwnode.h \
  @KERNEL_SOURCE@/include/linux/vmalloc.h \
  @KERNEL_SOURCE@/arch/arc/include/asm/vmalloc.h \
  @KERNEL_SOURCE@/include/linux/mem_encrypt.h \
    $(wildcard include/config/arch/has/mem/encrypt.h) \
  @KERNEL_SOURCE@/include/linux/netdev_features.h \
  @KERNEL_SOURCE@/include/linux/sched/clock.h \
    $(wildcard include/config/have/unstable/sched/clock.h) \
    $(wildcard include/config/irq/time/accounting.h) \
  @KERNEL_SOURCE@/include/net/flow_dissector.h \
  @KERNEL_SOURCE@/include/linux/in6.h \
  @KERNEL_SOURCE@/include/uapi/linux/in6.h \
  @KERNEL_SOURCE@/include/uapi/linux/libc-compat.h \
  @KERNEL_SOURCE@/include/uapi/linux/if_ether.h \
  @KERNEL_SOURCE@/include/linux/splice.h \
  @KERNEL_SOURCE@/include/linux/pipe_fs_i.h \
  @KERNEL_SOURCE@/include/uapi/linux/if_packet.h \
  @KERNEL_SOURCE@/include/net/flow.h \
  @KERNEL_SOURCE@/include/linux/netdevice.h \
    $(wildcard include/config/dcb.h) \
    $(wildcard include/config/hyperv/net.h) \
    $(wildcard include/config/wlan.h) \
    $(wildcard include/config/ax25.h) \
    $(wildcard include/config/mac80211/mesh.h) \
    $(wildcard include/config/net/ipip.h) \
    $(wildcard include/config/net/ipgre.h) \
    $(wildcard include/config/ipv6/sit.h) \
    $(wildcard include/config/ipv6/tunnel.h) \
    $(wildcard include/config/rps.h) \
    $(wildcard include/config/netpoll.h) \
    $(wildcard include/config/xdp/sockets.h) \
    $(wildcard include/config/bql.h) \
    $(wildcard include/config/rfs/accel.h) \
    $(wildcard include/config/fcoe.h) \
    $(wildcard include/config/xfrm/offload.h) \
    $(wildcard include/config/net/poll/controller.h) \
    $(wildcard include/config/libfcoe.h) \
    $(wildcard include/config/wireless/ext.h) \
    $(wildcard include/config/net/l3/master/dev.h) \
    $(wildcard include/config/ipv6.h) \
    $(wildcard include/config/vlan/8021q.h) \
    $(wildcard include/config/net/dsa.h) \
    $(wildcard include/config/tipc.h) \
    $(wildcard include/config/irda.h) \
    $(wildcard include/config/atalk.h) \
    $(wildcard include/config/mpls/routing.h) \
    $(wildcard include/config/netfilter/ingress.h) \
    $(wildcard include/config/garp.h) \
    $(wildcard include/config/mrp.h) \
    $(wildcard include/config/cgroup/net/prio.h) \
    $(wildcard include/config/macsec.h) \
    $(wildcard include/config/net/flow/limit.h) \
    $(wildcard include/config/ethtool/netlink.h) \
  @KERNEL_SOURCE@/include/linux/delay.h \
  @KERNEL_SOURCE@/arch/arc/include/asm/delay.h \
  @KERNEL_SOURCE@/include/linux/prefetch.h \
  @KERNEL_SOURCE@/include/linux/dynamic_queue_limits.h \
  @KERNEL_SOURCE@/include/linux/ethtool.h \
  @KERNEL_SOURCE@/include/linux/compat.h \
    $(wildcard include/config/arch/has/syscall/wrapper.h) \
    $(wildcard include/config/x86/x32/abi.h) \
    $(wildcard include/config/compat/old/sigaction.h) \
    $(wildcard include/config/odd/rt/sigaction.h) \
  @KERNEL_SOURCE@/include/uapi/linux/if.h \
  @KERNEL_SOURCE@/include/uapi/linux/hdlc/ioctl.h \
  @KERNEL_SOURCE@/include/uapi/linux/aio_abi.h \
  @KERNEL_SOURCE@/include/uapi/linux/unistd.h \
  @KERNEL_SOURCE@/arch/arc/include/uapi/asm/unistd.h \
  @KERNEL_SOURCE@/include/uapi/asm-generic/unistd.h \
  arch/arc/include/generated/asm/compat.h \
  @KERNEL_SOURCE@/include/asm-generic/compat.h \
    $(wildcard include/config/compat/for/u64/alignment.h) \
  @KERNEL_SOURCE@/include/uapi/linux/ethtool.h \
  @KERNEL_SOURCE@/include/net/net_namespace.h \
    $(wildcard include/config/ieee802154/6lowpan.h) \
    $(wildcard include/config/ip/sctp.h) \
    $(wildcard include/config/ip/dccp.h) \
    $(wildcard include/config/netfilter.h) \
    $(wildcard include/config/nf/defrag/ipv6.h) \
    $(wildcard include/config/netfilter/netlink/acct.h) \
    $(wildcard include/config/nf/ct/netlink/timeout.h) \
    $(wildcard include/config/wext/core.h) \
    $(wildcard include/config/mpls.h) \
    $(wildcard include/config/can.h) \
    $(wildcard include/config/crypto/user.h) \
    $(wildcard include/config/net/ns.h) \
  @KERNEL_SOURCE@/include/net/netns/core.h \
  @KERNEL_SOURCE@/include/net/netns/mib.h \
    $(wildcard include/config/xfrm/statistics.h) \
    $(wildcard include/config/tls.h) \
  @KERNEL_SOURCE@/include/net/snmp.h \
  @KERNEL_SOURCE@/include/uapi/linux/snmp.h \
  @KERNEL_SOURCE@/include/linux/u64_stats_sync.h \
  @KERNEL_SOURCE@/include/net/netns/unix.h \
  @KERNEL_SOURCE@/include/net/netns/packet.h \
  @KERNEL_SOURCE@/include/net/netns/ipv4.h \
    $(wildcard include/config/ip/multiple/tables.h) \
    $(wildcard include/config/ip/route/classid.h) \
    $(wildcard include/config/ip/mroute.h) \
    $(wildcard include/config/ip/mroute/multiple/tables.h) \
    $(wildcard include/config/ip/route/multipath.h) \
  @KERNEL_SOURCE@/include/net/inet_frag.h \
  @KERNEL_SOURCE@/include/net/netns/ipv6.h \
    $(wildcard include/config/ipv6/multiple/tables.h) \
    $(wildcard include/config/ipv6/subtrees.h) \
    $(wildcard include/config/ipv6/mroute.h) \
    $(wildcard include/config/ipv6/mroute/multiple/tables.h) \
  @KERNEL_SOURCE@/include/net/dst_ops.h \
  @KERNEL_SOURCE@/include/uapi/linux/icmpv6.h \
  @KERNEL_SOURCE@/include/net/netns/nexthop.h \
  @KERNEL_SOURCE@/include/net/netns/ieee802154_6lowpan.h \
  @KERNEL_SOURCE@/include/net/netns/sctp.h \
  @KERNEL_SOURCE@/include/net/netns/dccp.h \
  @KERNEL_SOURCE@/include/net/netns/netfilter.h \
    $(wildcard include/config/netfilter/family/arp.h) \
    $(wildcard include/config/netfilter/family/bridge.h) \
    $(wildcard include/config/nf/defrag/ipv4.h) \
  @KERNEL_SOURCE@/include/linux/netfilter_defs.h \
  @KERNEL_SOURCE@/include/uapi/linux/netfilter.h \
  @KERNEL_SOURCE@/include/linux/in.h \
  @KERNEL_SOURCE@/include/uapi/linux/in.h \
  @KERNEL_SOURCE@/include/net/netns/x_tables.h \
    $(wildcard include/config/bridge/nf/ebtables.h) \
  @KERNEL_SOURCE@/include/net/netns/nftables.h \
  @KERNEL_SOURCE@/include/net/netns/xfrm.h \
  @KERNEL_SOURCE@/include/uapi/linux/xfrm.h \
  @KERNEL_SOURCE@/include/net/netns/mpls.h \
  @KERNEL_SOURCE@/include/net/netns/can.h \
  @KERNEL_SOURCE@/include/net/netns/xdp.h \
  @KERNEL_SOURCE@/include/net/netns/bpf.h \
  @KERNEL_SOURCE@/include/linux/bpf-netns.h \
  @KERNEL_SOURCE@/include/uapi/linux/bpf.h \
    $(wildcard include/config/efficient/unaligned/access.h) \
    $(wildcard include/config/cgroup/net/classid.h) \
    $(wildcard include/config/bpf/kprobe/override.h) \
    $(wildcard include/config/function/error/injection.h) \
    $(wildcard include/config/bpf/lirc/mode2.h) \
    $(wildcard include/config/sock/cgroup/data.h) \
  @KERNEL_SOURCE@/include/uapi/linux/bpf_common.h \
  @KERNEL_SOURCE@/include/linux/ns_common.h \
  @KERNEL_SOURCE@/include/linux/seq_file_net.h \
  @KERNEL_SOURCE@/include/linux/seq_file.h \
  @KERNEL_SOURCE@/include/linux/nsproxy.h \
  @KERNEL_SOURCE@/include/net/netprio_cgroup.h \
  @KERNEL_SOURCE@/include/linux/cgroup.h \
    $(wildcard include/config/cgroup/cpuacct.h) \
    $(wildcard include/config/cgroup/data.h) \
    $(wildcard include/config/cgroup/bpf.h) \
  @KERNEL_SOURCE@/include/uapi/linux/cgroupstats.h \
  @KERNEL_SOURCE@/include/uapi/linux/taskstats.h \
  @KERNEL_SOURCE@/include/linux/user_namespace.h \
    $(wildcard include/config/inotify/user.h) \
    $(wildcard include/config/fanotify.h) \
    $(wildcard include/config/persistent/keyrings.h) \
  @KERNEL_SOURCE@/include/linux/kernel_stat.h \
  @KERNEL_SOURCE@/include/linux/interrupt.h \
    $(wildcard include/config/irq/forced/threading.h) \
    $(wildcard include/config/generic/irq/probe.h) \
    $(wildcard include/config/irq/timings.h) \
  @KERNEL_SOURCE@/include/linux/irqreturn.h \
  @KERNEL_SOURCE@/include/linux/hardirq.h \
  @KERNEL_SOURCE@/include/linux/context_tracking_state.h \
    $(wildcard include/config/context/tracking.h) \
  @KERNEL_SOURCE@/include/linux/ftrace_irq.h \
    $(wildcard include/config/hwlat/tracer.h) \
  @KERNEL_SOURCE@/include/linux/vtime.h \
    $(wildcard include/config/virt/cpu/accounting.h) \
  arch/arc/include/generated/asm/hardirq.h \
  @KERNEL_SOURCE@/include/asm-generic/hardirq.h \
  @KERNEL_SOURCE@/include/linux/irq_cpustat.h \
  @KERNEL_SOURCE@/include/linux/irq.h \
    $(wildcard include/config/generic/irq/effective/aff/mask.h) \
    $(wildcard include/config/generic/irq/ipi.h) \
    $(wildcard include/config/irq/domain/hierarchy.h) \
    $(wildcard include/config/generic/irq/migration.h) \
    $(wildcard include/config/generic/pending/irq.h) \
    $(wildcard include/config/hardirqs/sw/resend.h) \
    $(wildcard include/config/generic/irq/legacy/alloc/hwirq.h) \
    $(wildcard include/config/generic/irq/legacy.h) \
    $(wildcard include/config/generic/irq/multi/handler.h) \
  @KERNEL_SOURCE@/include/linux/irqhandler.h \
  @KERNEL_SOURCE@/include/linux/io.h \
  @KERNEL_SOURCE@/arch/arc/include/asm/irq.h \
  @KERNEL_SOURCE@/include/asm-generic/irq.h \
  arch/arc/include/generated/asm/irq_regs.h \
  @KERNEL_SOURCE@/include/asm-generic/irq_regs.h \
  @KERNEL_SOURCE@/include/linux/irqdesc.h \
    $(wildcard include/config/generic/irq/debugfs.h) \
    $(wildcard include/config/sparse/irq.h) \
    $(wildcard include/config/handle/domain/irq.h) \
    $(wildcard include/config/irq/domain.h) \
  arch/arc/include/generated/asm/hw_irq.h \
  @KERNEL_SOURCE@/include/asm-generic/hw_irq.h \
  @KERNEL_SOURCE@/arch/arc/include/asm/sections.h \
  @KERNEL_SOURCE@/include/asm-generic/sections.h \
  @KERNEL_SOURCE@/include/linux/cgroup-defs.h \
  @KERNEL_SOURCE@/include/linux/bpf-cgroup.h \
  @KERNEL_SOURCE@/include/linux/bpf.h \
    $(wildcard include/config/bpf/jit.h) \
    $(wildcard include/config/bpf/jit/always/on.h) \
    $(wildcard include/config/inet.h) \
  @KERNEL_SOURCE@/include/linux/file.h \
  @KERNEL_SOURCE@/include/linux/rbtree_latch.h \
  @KERNEL_SOURCE@/include/linux/module.h \
    $(wildcard include/config/modules/tree/lookup.h) \
    $(wildcard include/config/module/sig.h) \
    $(wildcard include/config/kallsyms.h) \
    $(wildcard include/config/bpf/events.h) \
    $(wildcard include/config/event/tracing.h) \
    $(wildcard include/config/kprobes.h) \
    $(wildcard include/config/have/static/call/inline.h) \
    $(wildcard include/config/module/unload.h) \
    $(wildcard include/config/mitigation/its.h) \
    $(wildcard include/config/constructors.h) \
  @KERNEL_SOURCE@/include/linux/kmod.h \
  @KERNEL_SOURCE@/include/linux/umh.h \
  @KERNEL_SOURCE@/include/linux/elf.h \
    $(wildcard include/config/arch/use/gnu/property.h) \
    $(wildcard include/config/arch/have/elf/prot.h) \
  @KERNEL_SOURCE@/arch/arc/include/asm/elf.h \
  @KERNEL_SOURCE@/include/uapi/linux/elf-em.h \
  @KERNEL_SOURCE@/arch/arc/include/uapi/asm/elf.h \
  @KERNEL_SOURCE@/include/uapi/linux/elf.h \
  @KERNEL_SOURCE@/include/linux/moduleparam.h \
    $(wildcard include/config/alpha.h) \
    $(wildcard include/config/ppc64.h) \
  @KERNEL_SOURCE@/include/linux/error-injection.h \
  @KERNEL_SOURCE@/include/asm-generic/error-injection.h \
  @KERNEL_SOURCE@/include/linux/static_call_types.h \
    $(wildcard include/config/have/static/call.h) \
  @KERNEL_SOURCE@/arch/arc/include/asm/module.h \
    $(wildcard include/config/arc/dw2/unwind.h) \
  @KERNEL_SOURCE@/include/asm-generic/module.h \
    $(wildcard include/config/have/mod/arch/specific.h) \
    $(wildcard include/config/modules/use/elf/rel.h) \
    $(wildcard include/config/modules/use/elf/rela.h) \
  @KERNEL_SOURCE@/include/linux/kallsyms.h \
    $(wildcard include/config/kallsyms/all.h) \
  @KERNEL_SOURCE@/include/linux/psi_types.h \
  @KERNEL_SOURCE@/include/linux/kthread.h \
  @KERNEL_SOURCE@/include/net/xdp.h \
  @KERNEL_SOURCE@/include/uapi/linux/neighbour.h \
  @KERNEL_SOURCE@/include/linux/netlink.h \
  @KERNEL_SOURCE@/include/net/scm.h \
    $(wildcard include/config/security/network.h) \
  @KERNEL_SOURCE@/include/linux/security.h \
    $(wildcard include/config/security/infiniband.h) \
    $(wildcard include/config/security/network/xfrm.h) \
    $(wildcard include/config/security/path.h) \
    $(wildcard include/config/securityfs.h) \
  @KERNEL_SOURCE@/include/linux/kernel_read_file.h \
  @KERNEL_SOURCE@/include/uapi/linux/netlink.h \
  @KERNEL_SOURCE@/include/uapi/linux/netdevice.h \
  @KERNEL_SOURCE@/include/linux/if_link.h \
  @KERNEL_SOURCE@/include/uapi/linux/if_link.h \
  @KERNEL_SOURCE@/include/uapi/linux/if_bonding.h \
  @KERNEL_SOURCE@/include/uapi/linux/pkt_cls.h \
  @KERNEL_SOURCE@/include/uapi/linux/pkt_sched.h \
  @KERNEL_SOURCE@/include/linux/hashtable.h \
  @KERNEL_SOURCE@/include/linux/crc32.h \
  @KERNEL_SOURCE@/include/linux/bitrev.h \
    $(wildcard include/config/have/arch/bitreverse.h) \
  @KERNEL_SOURCE@/include/linux/usb.h \
    $(wildcard include/config/usb/mon.h) \
    $(wildcard include/config/usb/led/trig.h) \
  @KERNEL_SOURCE@/include/linux/mod_devicetable.h \
  @KERNEL_SOURCE@/include/linux/usb/ch9.h \
  @KERNEL_SOURCE@/include/uapi/linux/usb/ch9.h \
  @KERNEL_SOURCE@/include/linux/pm_runtime.h \
  @KERNEL_SOURCE@/include/net/mac80211.h \
    $(wildcard include/config/mac80211/debugfs.h) \
    $(wildcard include/config/nl80211/testmode.h) \
    $(wildcard include/config/mac80211/leds.h) \
  @KERNEL_SOURCE@/include/linux/ieee80211.h \
  @KERNEL_SOURCE@/include/net/cfg80211.h \
    $(wildcard include/config/cfg80211.h) \
    $(wildcard include/config/cfg80211/wext.h) \
  @KERNEL_SOURCE@/include/linux/debugfs.h \
    $(wildcard include/config/debug/fs.h) \
  @KERNEL_SOURCE@/include/uapi/linux/nl80211.h \
  @KERNEL_SOURCE@/include/net/regulatory.h \
  @KERNEL_SOURCE@/include/net/codel.h \
  @KERNEL_SOURCE@/include/net/pkt_sched.h \
  @KERNEL_SOURCE@/include/linux/if_vlan.h \
  @KERNEL_SOURCE@/include/linux/rtnetlink.h \
    $(wildcard include/config/net/ingress.h) \
    $(wildcard include/config/net/egress.h) \
  @KERNEL_SOURCE@/include/uapi/linux/rtnetlink.h \
  @KERNEL_SOURCE@/include/uapi/linux/if_addr.h \
  @KERNEL_SOURCE@/include/uapi/linux/if_vlan.h \
  @KERNEL_SOURCE@/include/net/sch_generic.h \
  @KERNEL_SOURCE@/include/uapi/linux/pkt_cls.h \
  @KERNEL_SOURCE@/include/net/gen_stats.h \
  @KERNEL_SOURCE@/include/uapi/linux/gen_stats.h \
  @KERNEL_SOURCE@/include/net/rtnetlink.h \
  @KERNEL_SOURCE@/include/net/netlink.h \
  @KERNEL_SOURCE@/include/net/flow_offload.h \
  @KERNEL_SOURCE@/include/uapi/linux/pkt_sched.h \
  @KERNEL_SOURCE@/include/net/inet_ecn.h \
  @KERNEL_SOURCE@/include/linux/ip.h \
  @KERNEL_SOURCE@/include/uapi/linux/ip.h \
  @KERNEL_SOURCE@/include/net/inet_sock.h \
  @KERNEL_SOURCE@/include/linux/jhash.h \
  @KERNEL_SOURCE@/include/net/sock.h \
    $(wildcard include/config/sock/validate/xmit.h) \
  @KERNEL_SOURCE@/include/linux/list_nulls.h \
  @KERNEL_SOURCE@/include/linux/page_counter.h \
  @KERNEL_SOURCE@/include/linux/memcontrol.h \
    $(wildcard include/config/memcg/swap.h) \
  @KERNEL_SOURCE@/include/linux/vmpressure.h \
  @KERNEL_SOURCE@/include/linux/eventfd.h \
    $(wildcard include/config/eventfd.h) \
  @KERNEL_SOURCE@/include/linux/writeback.h \
  @KERNEL_SOURCE@/include/linux/flex_proportions.h \
  @KERNEL_SOURCE@/include/linux/backing-dev-defs.h \
  @KERNEL_SOURCE@/include/linux/blk_types.h \
    $(wildcard include/config/blk/cgroup/iocost.h) \
    $(wildcard include/config/blk/inline/encryption.h) \
    $(wildcard include/config/blk/dev/integrity.h) \
  @KERNEL_SOURCE@/include/linux/blk-cgroup.h \
  @KERNEL_SOURCE@/include/linux/blkdev.h \
    $(wildcard include/config/blk/rq/alloc/time.h) \
    $(wildcard include/config/blk/wbt.h) \
    $(wildcard include/config/blk/dev/zoned.h) \
    $(wildcard include/config/blk/dev/bsg.h) \
    $(wildcard include/config/blk/dev/throttling.h) \
    $(wildcard include/config/blk/debug/fs.h) \
  @KERNEL_SOURCE@/include/uapi/linux/major.h \
  @KERNEL_SOURCE@/include/linux/genhd.h \
    $(wildcard include/config/fail/make/request.h) \
    $(wildcard include/config/cdrom.h) \
  arch/arc/include/generated/asm/local.h \
  @KERNEL_SOURCE@/include/asm-generic/local.h \
  @KERNEL_SOURCE@/include/linux/pagemap.h \
  @KERNEL_SOURCE@/include/linux/highmem.h \
    $(wildcard include/config/x86/32.h) \
    $(wildcard include/config/debug/highmem.h) \
  @KERNEL_SOURCE@/arch/arc/include/asm/cacheflush.h \
    $(wildcard include/config/arc/cache/vipt/aliasing.h) \
  @KERNEL_SOURCE@/arch/arc/include/asm/kmap_types.h \
  @KERNEL_SOURCE@/include/linux/hugetlb_inline.h \
  @KERNEL_SOURCE@/include/linux/mempool.h \
  @KERNEL_SOURCE@/include/linux/bio.h \
  @KERNEL_SOURCE@/include/linux/bsg.h \
  @KERNEL_SOURCE@/include/uapi/linux/bsg.h \
  @KERNEL_SOURCE@/include/uapi/linux/blkzoned.h \
  @KERNEL_SOURCE@/include/linux/elevator.h \
  @KERNEL_SOURCE@/include/linux/blk-mq.h \
    $(wildcard include/config/fail/io/timeout.h) \
  @KERNEL_SOURCE@/include/linux/sbitmap.h \
  @KERNEL_SOURCE@/include/linux/filter.h \
    $(wildcard include/config/have/ebpf/jit.h) \
  @KERNEL_SOURCE@/include/linux/set_memory.h \
    $(wildcard include/config/arch/has/set/memory.h) \
  @KERNEL_SOURCE@/include/crypto/sha.h \
  @KERNEL_SOURCE@/include/uapi/linux/filter.h \
  @KERNEL_SOURCE@/include/linux/rculist_nulls.h \
  @KERNEL_SOURCE@/include/linux/poll.h \
  @KERNEL_SOURCE@/include/uapi/linux/poll.h \
  arch/arc/include/generated/uapi/asm/poll.h \
  @KERNEL_SOURCE@/include/uapi/asm-generic/poll.h \
  @KERNEL_SOURCE@/include/uapi/linux/eventpoll.h \
  @KERNEL_SOURCE@/include/net/dst.h \
  @KERNEL_SOURCE@/include/net/neighbour.h \
  @KERNEL_SOURCE@/include/linux/indirect_call_wrapper.h \
  @KERNEL_SOURCE@/include/net/tcp_states.h \
  @KERNEL_SOURCE@/include/uapi/linux/net_tstamp.h \
  @KERNEL_SOURCE@/include/net/l3mdev.h \
  @KERNEL_SOURCE@/include/net/fib_rules.h \
  @KERNEL_SOURCE@/include/uapi/linux/fib_rules.h \
  @KERNEL_SOURCE@/include/net/fib_notifier.h \
  @KERNEL_SOURCE@/include/net/request_sock.h \
  @KERNEL_SOURCE@/include/net/netns/hash.h \
  @KERNEL_SOURCE@/include/net/dsfield.h \
  @KERNEL_SOURCE@/include/linux/ipv6.h \
    $(wildcard include/config/ipv6/router/pref.h) \
    $(wildcard include/config/ipv6/route/info.h) \
    $(wildcard include/config/ipv6/optimistic/dad.h) \
    $(wildcard include/config/ipv6/seg6/hmac.h) \
    $(wildcard include/config/ipv6/mip6.h) \
  @KERNEL_SOURCE@/include/uapi/linux/ipv6.h \
  @KERNEL_SOURCE@/include/linux/tcp.h \
    $(wildcard include/config/smc.h) \
    $(wildcard include/config/bpf.h) \
    $(wildcard include/config/tcp/md5sig.h) \
  @KERNEL_SOURCE@/include/linux/win_minmax.h \
  @KERNEL_SOURCE@/include/net/inet_connection_sock.h \
  @KERNEL_SOURCE@/include/net/inet_timewait_sock.h \
  @KERNEL_SOURCE@/include/net/timewait_sock.h \
  @KERNEL_SOURCE@/include/uapi/linux/tcp.h \
  @KERNEL_SOURCE@/include/linux/udp.h \
  @KERNEL_SOURCE@/include/uapi/linux/udp.h \
  @KERNEL_SOURCE@/include/net/ieee80211_radiotap.h \
  @KERNEL_SOURCE@/include/linux/bitfield.h \
  @KERNEL_SOURCE@/drivers/net/wireless/realtek/rtlwifi/rtl8192ee/../debug.h \
    $(wildcard include/config/rtlwifi/debug.h) \

drivers/net/wireless/realtek/rtlwifi/rtl8192ee/pwrseq.o: $(deps_drivers/net/wireless/realtek/rtlwifi/rtl8192ee/pwrseq.o)

$(deps_drivers/net/wireless/realtek/rtlwifi/rtl8192ee/pwrseq.o):
