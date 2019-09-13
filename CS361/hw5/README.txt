CS 361: HW #5
University of Illinois at Chicago
Fall 2014

Author: Bresia Prudente
ACCC ID: bprude2
UIN: 679176497

---------------------------------
FILES / PROGRAMS
---------------------------------
Included are the following files and programs:

raceTest.c
header.h
makefile
README.txt

---------------------------------
NOTES
---------------------------------
The read operation doesn't calculate the bits.

Often the write errors will exceed that of the write errors.

---------------------------------
INSTRUCTIONS
---------------------------------
$ make

$ ./raceTest nBuffers nWorkers sleepMin sleepMax [randSeed] [-lock | -nolock]

	-> nBuffers is the number of buffers that MUST be prime and less than 32
	-> nWorkers is the number of workers that MUST be less than nBuffers
	-> sleepMin is the minimum sleep value that MUST be greater than or equal to 0
	-> sleepMax is the maximum sleep value that MUST be greater than sleepMin
	-> randSeed is the value to be added to a random generator
	-> -lock or -nolock determines whether semaphores will be used

---------------------------------
TROUBLESHOOT
---------------------------------
If the makefile does not work, enter the following into the command line

$ gcc -o raceTest raceTest.c