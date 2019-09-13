
CS 361: HW#4
University of Illinois at Chicago
Fall 2014

Author: Bresia Prudente
ACCC ID: bprude2
UIN: 679176497

---------------------------------
PROGRAMS
---------------------------------
Included are the following files:

mandelbrot-bprude2.c
mandelCalc-bprude2.c
mandelDisplay-bprude2.c
README.txt
makefile

---------------------------------
NOTES
---------------------------------
The entire program is incomplete. Due to a misunderstanding with the assignment, most of the children operations are done within mandelbrot.

mandelbrot-bprude2.c 
	-> most of the starting operations are done correctly. There is an issue with 	   sending values through the pipes to the children.

mandelCalc-bprude2.c
	-> takes in parameters, but doesn't perform calculations

mandelDisplay-bprude2.c
	-> is empty; doesn't perform calculations

---------------------------------
INSTRUCTIONS
---------------------------------
$ make

$ ./mandelbrot

$ ./mandelDisplay shmID msgqID
	- shmID is the shared memory ID
	- msgqID is the message queue ID

$ ./mandelDraw shmID msgqID msgID2

For more information on current queues:
$ ipcs -q -t
$ ipcs -a

To delete an ID from the queue:
$ ipcrm -q <ID>

---------------------------------
TROUBLESHOOT
---------------------------------
If the three executables can't be created, enter the following commands:
$ gcc -g -o mandelbrot mandelbrot-bprude2.c
$ gcc -g -o mandelDisplay mandelCalc-bprude2.c
$ gcc -g -o mandelDraw mandelDisplay-bprude2.c
