CS 361 - Homework 3
Bresia Prudente (bprude2)

-------------
Notes
-------------

This program is incomplete.
It will not print page tables.

-------------
Files
-------------

vmpager.c
makefile
readme.txt

-------------
Instructions
-------------

$ make

$ ./vmpager <filename> <memory access> <frame table size>

<filename> is the full filename (including its extension)

<emory access> is the number of memory of access to process. If unsure, 
enter 0 as the value.

<frame table size> is the number of frames available to the virtual 
memory manager. Default is 256, but can have a larger value.

-------------
Troubleshoot
-------------

If make does not create an executable:

$ gcc -o vmpager vmpager.c
 