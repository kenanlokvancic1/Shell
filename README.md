# Shell: CLAM

**Members**: Dorijan Komšić, Kenan Lokvančić

# Q1: What does mmap() do?

In computing, mmap(2) is a POSIX-compliant Unix system call that maps files or devices into memory.mmap() is a method of memory-mapped file I/O. It implements demand paging because file contents are not read from disk directly and initially do not use physical RAM at all. The actual reads from disk are performed in a "lazy" manner, after a specific location is accessed. After the memory is no longer needed, it is important to munmap(2) the pointers to it. Protection information can be managed using mprotect(2), and special treatment can be enforced using madvise(2).

mmap() creates a new mapping in the virtual address space of the calling process. The starting address for the new mapping is specified in addr. The length argument specifies the length of the mapping (which must be greater than 0). If addr is NULL, then the kernel chooses the (page-aligned) address at which to create the mapping; this is the most portable method of creating a new mapping.  

If addr is not NULL, then the kernel takes it as a hint about where to place the mapping; on Linux, the kernel will pick a nearby page boundary (but always above or equal to the value specified by /proc/sys/vm/mmap_min_addr) and attempt to create the mapping there. If another mapping already exists there, the kernel picks a new address that may or may not depend on the hint. The address of the new mapping is returned as the result of the call. 

The mmap() function causes a reference to be associated with the file represented by fildes. This reference is not removed by subsequent close operations. The file remains referenced as long as a mapping exists over the file.
If a mapping already exists for the portion of the processes address space that is to be mapped and the value MAP_FIXED was specified for flags, then the previous mappings for the affected pages are implicitly unmapped. If one or more files affected by the implicit unmap no longer have active mappings, these files will be unreferenced as a result of mmap().

# Q2: What happens during a context switch? Do we want the OS to perform many or few context switches?
 
In the old days of batch computing, a number of non-preemptive schedulers were developed; such systems would run each job to completion before considering whether to run a new job. Virtually all modern schedulers are preemptive, and quite willing to stop one process from running in order to run another. This implies that the scheduler can perform a context switch, stopping one running process temporarily and resuming (or starting) another, where the role of a context switch steps in. 

The precise meaning of the phrase “context switch” varies. In a multitasking context, it refers to the process of storing the system state for one task, so that task can be paused and another task resumed. A context switch can also occur as the result of an interrupt, such as when a task needs to access disk storage, freeing up CPU time for other tasks. Some operating systems also require a context switch to move between user mode and kernel mode tasks.

Many computers support virtual memory. It makes it possible to run programs larger than physical memory by placing them on the disk and using main memory as a kind of cache for the most heavily executed parts. The virtual memory requires remapping memory addresses on the fly to convert the address the program generated to the physical address in RAM where the word is located. This mapping is done by a part of the CPU called the MMU (Memory Management Unit). 

The presence of caching and the MMU can have a major impact on performance. In a multiprogramming system, when switching from one program to another (context switch) it may be necessary to flush all modified blocks from the cache and change the mapping registers in the MMU. Both of these are expensive operations and programmers try hard to avoid them.

# Sources: 
1. https://www.unix.com/programming/21041-getting-username-c-program-unix.html
2. https://www.geeksforgeeks.org/c-program-print-contents-file/
3. https://www.tutorialspoint.com/basics-of-file-handling-in-c-programming#:~:text=File%20Handling%20is%20the%20storing,with%20it%20in%20the%20program
4. https://www.tutorialspoint.com/c-program-to-delete-a-file
5. https://github.com/0xAether/ccowsay
6. https://stackoverflow.com/questions/61970526/colored-output-in-c
7. https://gist.github.com/RabaDabaDoba/145049536f815903c79944599c6f952a
8. https://stackoverflow.com/questions/2347770/how-do-you-clear-the-console-screen-in-c
9. https://linuxhint.com/use-write-system-call-c/
10. https://www.geeksforgeeks.org/fork-bomb/
11. https://www.ibm.com/docs/en/i/7.3?topic=ssw_ibm_i_73/apis/mmap.htm
12. https://man7.org/linux/man-pages/man2/mmap.2.html
13. https://en.wikipedia.org/wiki/Mmap
14. https://en.wikipedia.org/wiki/Context_switch#cite_note-Tanenbaum2014-1
15. Andrew S. Tanenbaum,  Modern Operating Systems Third Edition,  Vrije Universiteit  Amsterdam, The Netherlands (2009)