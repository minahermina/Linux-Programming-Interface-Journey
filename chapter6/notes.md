### /proc/sys/kernel/pid_max 
    defines max pid in linux systems
## The parent of any process can be found by looking at the Ppid field provided in the Linux-specific /proc/PID/status file
    
- Although not specified in SUSv3, the C program environment on most UNIX
implementations (including Linux) provides three global symbols: etext, edata, and
end. These symbols can be used from within a program to obtain the addresses of
the next byte past, respectively, the end of the program text, the end of the initial-
ized data segment, and the end of the uninitialized data segment. To make use of
these symbols, we must explicitly declare them, as follows:
``` c
extern char etext, edata, end;
        /* For example, &etext gives the address of the end
           of the program text / start of initialized data */
``` 
## Locality of Reference

Locality of reference refers to the tendency of programs to access certain memory locations more frequently than others. This concept is essential for understanding memory optimization techniques in computer systems.

### Types of Locality

1. **Spatial Locality**  
   Spatial locality is the tendency of a program to reference memory addresses that are near those recently accessed. This behavior often occurs due to:
   - Sequential processing of instructions.
   - Sequential processing of data structures.

2. **Temporal Locality**  
   Temporal locality is the tendency of a program to access the same memory
### Resident Set
the pages of a program need
to be resident in physical memory page frames; these pages form the so-called
