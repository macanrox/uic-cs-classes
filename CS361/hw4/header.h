/*
 CS 361: HW #4
 University of Illinois at Chicago
 Fall 2014
 
 Author: Bresia Prudente
 ACCC ID: bprude2
 UIN: 679176497
 */

#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <sys/shm.h>
#include <sys/wait.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <signal.h>
#include <errno.h>

#define TRUE 1

#define MSGSIZE 80
#define MSGTYPE1 1
#define MSGTYPE2 2
#define MSGTYPE3 3
#define MAX 512
#define SHMSZE 80   //shared memory size

//struct for user defined buffer
typedef struct {
	long msgtype;	//message type
	int code;
	char mtext[MSGSIZE];	//message text of size 80
} msgbuf;

void signalHandler(int sig);