# OpenMP Examples


## OpenMP

An API for writing multithreaded applications

* A set of compiler directives and library routines for parallel application programmers
* Greatly simplifies writing multi-threaded (MT) programs in Fortran, C and C++

#### OpenMP Head File
```c
#include <omp.h>
```

#### OpenMP Core Syntax

```c
#pragma omp <directive> [clause[[,] clause] ...]
```

#### Compile OpenMP Using GCC
```Bash
$ gcc -fopenmp hello.c -o hello
```

## Directive:

#### atomic

#### barrier

#### critical

#### flush

#### for

#### master

#### ordered

#### parallel

#### sections

#### single
#### threadprivate

## Clause:

#### copyin

#### copyprivate

#### default

#### firstprivate

#### if

#### lastprivate

#### nowait

#### num_threads

#### ordered

#### private

#### reduction

#### schedule

##### schedule(static, chunk_size)

##### schedule(dynamic, chunk_size)

##### schedule(guided, chunk_size)

##### schedule(runtime)

#### shared

## OpenMP Functions:

#### void omp_set_num_threads(int _Num_threads);
		set the number of threads used in a parallel region
	在后续并行区域设置线程数，此调用只影响调用线程所遇到的同一级或内部嵌套级别的后续并行区域.说明：此函数只能在串行代码部分调用.
	
#### int omp_get_num_threads(void);
		get the number of threads used in a parallel region
	返回当前线程数目.说明：如果在串行代码中调用此函数，返回值为1.

#### int omp_get_max_threads(void);
	如果在程序中此处遇到未使用 num_threads() 子句指定的活动并行区域,则返回程序的最大可用线程数量.说明：可以在串行或并行区域调用，通常这个最大数量由omp_set_num_threads()或OMP_NUM_THREADS环境变量决定.

#### int omp_get_thread_num(void);
		get the thread rank in a parallel region
	返回当前线程id.id从1开始顺序编号,主线程id是0.

#### int omp_get_num_procs(void);
	返回程序可用的处理器数.

#### void omp_set_dynamic(int _Dynamic_threads);
	启用或禁用可用线程数的动态调整.(缺省情况下启用动态调整.)此调用只影响调用线程所遇到的同一级或内部嵌套级别的后续并行区域.如果 _Dynamic_threads 的值为非零值,启用动态调整;否则,禁用动态调整.

#### int omp_get_dynamic(void);
	确定在程序中此处是否启用了动态线程调整.启用了动态线程调整时返回非零值;否则,返回零值.

#### int omp_in_parallel(void);
	确定线程是否在并行区域的动态范围内执行.如果在活动并行区域的动态范围内调用,则返回非零值;否则,返回零值.活动并行区域是指 IF 子句求值为 TRUE 的并行区域.

#### void omp_set_nested(int _Nested);
	启用或禁用嵌套并行操作.此调用只影响调用线程所遇到的同一级或内部嵌套级别的后续并行区域._Nested 的值为非零值时启用嵌套并行操作;否则,禁用嵌套并行操作.缺省情况下,禁用嵌套并行操作.

#### int omp_get_nested(void);
	确定在程序中此处是否启用了嵌套并行操作.启用嵌套并行操作时返回非零值;否则,返回零值.
	互斥锁操作 嵌套锁操作 功能

#### void omp_init_lock(omp_lock_t * _Lock);
#### void omp_init_nest_lock(omp_nest_lock_t * _Lock);
	初始化一个（嵌套）互斥锁.

#### void omp_destroy_lock(omp_lock_t * _Lock);
#### void omp_destroy_nest_lock(omp_nest_lock_t * _Lock);
	结束一个（嵌套）互斥锁的使用并释放内存.

#### void omp_set_lock(omp_lock_t * _Lock);
#### void omp_set_nest_lock(omp_nest_lock_t * _Lock);
	获得一个（嵌套）互斥锁.

#### void omp_unset_lock(omp_lock_t * _Lock);
#### void omp_unset_nest_lock(omp_nest_lock_t * _Lock);
	释放一个（嵌套）互斥锁.

#### int omp_test_lock(omp_lock_t * _Lock);
#### int omp_test_nest_lock(omp_nest_lock_t * _Lock);
	试图获得一个（嵌套）互斥锁,并在成功时放回真（true）,失败是返回假（false）.

#### double omp_get_wtime(void);
	获取wall clock time,返回一个double的数,表示从过去的某一时刻经历的时间,一般用于成对出现,进行时间比较. 此函数得到的时间是相对于线程的,也就是每一个线程都有自己的时间.

#### double omp_get_wtick(void);
	得到clock ticks的秒数.

