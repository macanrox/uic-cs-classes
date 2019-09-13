/*
 * Bresia Prudente (bprude2)
 * CS 361 - Fall 2014
 */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include <string.h>
#include <stdbool.h>
#include <errno.h>
#include <stdint.h>	//for intmax_t
#include <math.h>   //for pow
#include <pthread.h>	//for threads

#include <sys/msg.h>
#include <sys/shm.h>
#include <sys/sem.h>
#include <sys/ipc.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/resource.h>

#define TRUE 1
#define FALSE 0
#define MSGSIZE 80

//explicitly call union semun
union semun {
	int val;
	struct semid_ds *buf;
	unsigned short int *array;
} argVal;

//contains parameters from void * worker( void * );
struct threadStruct{
    
    int nBuffers;
    int workerID;
    double sleepTime;
    int semID;
    int mutexID;
    int *buffers;
    int nReadErrors;
};