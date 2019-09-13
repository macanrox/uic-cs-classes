/* 
 * Bresia Prudente (bprude2)
 * CS 361 - Fall 2014
 */

#include "header.h"

 void *worker(void *ptr);

//This generates a randomized value based on min and max values
float randGen(float min, float max, int seed){
    
    static int isSeed = 0;
    
    //Check if it should be seeded, otherwise give a null
    if (isSeed == 0) {
        if (isSeed == -1)
            srand(time(NULL));
        else
            srand(isSeed);
        isSeed++;
    }//end if

    float range = (max - min);
    float divide = RAND_MAX / range;
    return (min + (rand() / divide));
    
}//end double randGen

int main (int argc, char *argv[]){
    
    //Print user info
    printf("\nAuthor : Bresia Prudente\n"
           "ACCC ID: bprude2\n\n");
    
    /**********************/
    /* PARSE COMMAND LINE */
    /**********************/
    if (argc < 7 && argc < 5) {
        printf("Usage: ./raceTest nBuffers nWorkers sleepMin sleepMax [randSeed] [-lock | -nolock]\n\n");
        exit(-1);
    }//end if
    
    //Declare and initialize variables
    int nBuffers = atoi(argv[1]);
    int nWorkers = atoi(argv[2]);
    float sleepMin = atof(argv[3]);
    float sleepMax = atof(argv[4]);
    int randSeed;
    double randomized;
    bool semLock = FALSE;
    int semid;
    int bufArr[nBuffers];  //local array initialized to zero
    double nWorkerArr[nWorkers];    //for sorting array of rand numbers

    //initializing local array
    int tmp1;
    for (tmp1 = 0; tmp1 < nBuffers; tmp1++){
        bufArr[tmp1] = 0;
    }//end for

    printf("Running simulation for %d workers accessing %d buffers, ", nWorkers, nBuffers);
    
    //Check if user enables lock or nolock
    if (argc == 7) {
        if (strcmp(argv[6], "-lock") == 0) {
            semLock = TRUE;
            printf("with locking.\n");   //sanity test
        }//end if
        else if (strcmp(argv[6], "-nolock") == 0){
            semLock = FALSE;
            printf("without locking.\n");    //sanity test
        }//end else if
    }//end if
    //if user doesn't enter a value, default to unlock
    if (argc < 7){
        semLock = FALSE;
        printf("without locking (default).\n");   //sanity test
    }//end if
    
    //Min and Max must be positive real numbers
    //min cannot be greater than max
    if (sleepMin > sleepMax) {
        printf("sleepMin cannot be greater than sleepMax!\n\n");
        exit(-1);
    }//end if
    else if((sleepMin < 0) || (sleepMax < 0)){
        printf("sleepMin and/or sleepMax values must be POSITIVE\n\n");
        exit(-1);
    }//end else if

    printf("Sleeping from %f to %f seconds.\n", sleepMin, sleepMax);
    
    //To check randSeed
    if (argc >= 5)
        randSeed = atoi(argv[5]);
    else
        randSeed = -1;  //if user enters nothing
    
    //nBuffers must be a positive prime integer less than 32
    if (nBuffers < 0) {
        printf("nBuffers must be POSITIVE\n\n");
        exit(-1);
    }//end if
    else if (nBuffers > 32){
        printf("nBuffers must be less than 32\n\n");
        exit(-1);
    }//end else if
    else if (nBuffers % 2 == 0){
        printf("%d is NOT a prime number\n\n", nBuffers);
        exit(-1);
    }//end else if

    //nWorkers must be a positive integer less than nBuffers
    if (nWorkers > nBuffers){
        printf("nWorkers must be less than nBuffers!\n\n");
        exit(-1);
    }//end if
    else if (nWorkers < 0){
        printf("nWorkers must be POSITIVE\n\n");
        exit(-1);
    }//end else if
    
    /**********************/
    /*   SET UP WORKERS   */
    /**********************/

    if (semLock){
        semid = semget(IPC_PRIVATE, nBuffers, IPC_CREAT|0600);
        if (semid < 0){
            perror("semget");
            exit(-1);
        }//end if
        union semun argVal;
        argVal.val = 1;
        int c;
        for (c = 0; c < nBuffers; c++){
            if(semctl(semid, c, SETVAL, argVal) < 0){
                perror("semctl");
                exit(-1);
            }//end if(semctl...)
        }//end for (c = 0...)
    }//end if (semLock...)
    else
        semid = -1;

    //Give each worker a random value
    printf("\n");
    int x;
    for (x = 0; x < nWorkers; x++) {
        randomized = randGen(sleepMin, sleepMax, randSeed);
        nWorkerArr[x] = randomized;
        printf("sleepTime [ %d ] = %f\n", x, randomized);    //sanity test
    }//end for
    printf("\n");
    
    struct threadStruct strand[nWorkers];   //array of M structs

    //fill up these values
    int a;
    for ( a = 0; a < nWorkers; a++){
        strand[a].nBuffers = nBuffers;
        strand[a].workerID = a + 1;
        strand[a].sleepTime = nWorkerArr[a];
        strand[a].semID = semid;
        //strand[a].semID = -1;
        strand[a].mutexID = -1;
        strand[a].buffers = bufArr;
        strand[a].nReadErrors = 0;
    }//end for

    /**********************/
    /*      THREADS       */
    /**********************/

    pthread_t isThread[nWorkers];   //create nWorker threads
    struct threadStruct *structPtr; //struct pointer
    long b;
    int rErrorCounter = 0, wErrorCounter = 0;
    
    for (b = 0; b < nWorkers; b++){
        structPtr = &strand[b]; //assign a pointer to each struct

        //create M threads
        if(pthread_create(&isThread[b], NULL, worker, (void *)structPtr) != 0){
            perror("pthread_create");
            exit(-1);
        }//end if

    }//end for

    for (b = 0; b < nWorkers; b++){
        //join threads
        if(pthread_join(isThread[b], NULL) != 0){
            perror("pthread_join");
            exit(-1);
        }//end if

        //have main increment read error counter
        if (strand[b].nReadErrors != 0){
            rErrorCounter += strand[b].nReadErrors;
        }//end if
    }//end for

    /**********************/
    /*  MAIN PRINTS MSGS  */
    /**********************/

    //examine the contents of each buffer element
    int noErrors = (int)(pow(2, nWorkers) - 1);  //no errors contains (2^nWorkers)-1
    int d;
    printf("\nAll buffers should hold %d\n\n", noErrors);   //sanity test
    for (d = 0; d < nBuffers; d++){
        printf("Buffer %d holds %d\n", d, strand->buffers[d]);  //sanity test
        if (*(strand->buffers) != noErrors){
            wErrorCounter++;
        }//end if
    }//end for
    printf("\n");

    //save the bad bits counter into an array index
    int *badBitsArr; //initialize array with write error counter as its index
    badBitsArr = (int *)malloc(sizeof(int)*wErrorCounter);
    int badBitsIndex = 0;
    int e;
    for (e = 0; e < nBuffers; e++){
        if (*(strand->buffers) != noErrors){
            badBitsArr[badBitsIndex] = e; //save into the array
            badBitsIndex++;   //increment accordingly
            //break out of it once it reaches value of write error counter
            if (badBitsIndex == wErrorCounter){
                break;
            }//end if (badBitsIndex...
        }//end if (*(strand...
        else if(wErrorCounter == 0)
            break;
    }//end for

    //now actually make error reports
    int isBadBits, shiftBadBits;
    int wErrCount = 0;
    int *badBitsArr2; 
    badBitsArr2 = (int *)malloc(sizeof(int)*32);    //calling a 32 bit int array to store some values

    //initialize unused index to -1
    int y;
    for (y = 0; y < 32; y++){
        badBitsArr2[y] = -1;
    }//end for

    //Make error reports for each buffer
    int f, g;
    for (f = 0; f < wErrorCounter; f++){
        g = badBitsArr[f];
        isBadBits = strand->buffers[g];   //put contents of found bad bits into array

        printf("Error in buffer %d. ", g); 
    
        //examine the bad bits
        shiftBadBits = (isBadBits ^ noErrors);
        int z, h = 0;;
        for (z = 0; z < 32; z++){
            if(shiftBadBits & (1 << z)){    //tests which bits are lost to overwriting
                badBitsArr2[h] = z;
                h++;
            }//end if ((shiftBadBits...
        }//end for (z = 0...

        //print out the bad bits
        int i = 0;
        printf("( Bad bits = ");
        while(i < h){
            if (i < (h-1))  //beautify it up
                printf("%d, ", badBitsArr2[i]);
            else
                printf("%d", badBitsArr2[i]);
            wErrCount++;
            i++;
        }
        printf(" )\n");

    }//end for
    printf("\n");

    //main prints the total number of errors
    printf("%d read errors and %d write errors encountered.\n\n", rErrorCounter, wErrCount);

    //detach semaphores
    if(semLock){
        if (semctl(semid, 0, IPC_RMID)){
            perror("semctl");
            exit(-1);
        }//end if (semctl...)
    }//end if(semLock)

    printf("Program exiting...\n\n");
    sleep(1);
    return 0;
    
}//end main

/**********************/
/* WORKER FUNCTION */    
/**********************/
void *worker( void *param){

    struct threadStruct *update = (struct threadStruct*)param;  //call struct void
    int nBuffers = update->nBuffers;
    int workerID = update->workerID;
    double sleepTime = update->sleepTime;
    int semID = update->semID;
    int mutexID = update->mutexID;
    int *buffers = update->buffers;
    int nReadErrors;

    struct sembuf sops; //for semop()
    workerID = update->workerID;
    semID = update->semID;
    bool semLock = FALSE;
    if (semID != -1)
        semLock = TRUE;

    /*****************************/
    /* READ AND WRITE OPERATIONS */
    /*****************************/
    //First two are READS and the third is a WRITE
    int beforeSleep = 0, afterSleep = 0, isWorkerID = workerID;
    int read = 0, write = 0;    //write will be used as a counter until it reaches nBuffers
    int readErrCount = 0, writeErrCount = 0;
    int addShift = (1 << (workerID - 1));

    while(write < nBuffers){

        //lock using -1
        if(semLock){
            sops.sem_num = isWorkerID;   //semaphore number
            sops.sem_op = -1;   //semaphore operation
            sops.sem_flg = 0;   //operation flags
            semop(semID, &sops, 1);
        }//end if

        beforeSleep = buffers[isWorkerID];  //read initial buffer
        usleep(sleepTime); //no more tears, only dreams now
        afterSleep = buffers[isWorkerID];   //read the buffer value again

        //read error operation
        if (beforeSleep != afterSleep){
            printf("Worker %d observed that ", workerID);
            printf("buffer %d changed from %d to %d\n", buffers[workerID], isWorkerID, workerID);
            readErrCount++;  //increment error counter

        }//end if

        //unlock using +1
        if(semLock){
            sops.sem_num = isWorkerID;   //semaphore number
            sops.sem_op = 1;   //semaphore operation
            sops.sem_flg = 0;   //operation flags
            semop(semID, &sops, 1);
        }//end if

        isWorkerID += workerID;
        //if worker is greater than nBuffer, wrap back to zero
        if (isWorkerID > (nBuffers - 1))
           isWorkerID = isWorkerID % nBuffers;

        //lock using -1
        if(semLock){
            sops.sem_num = isWorkerID;   //semaphore number
            sops.sem_op = -1;   //semaphore operation
            sops.sem_flg = 0;   //operation flags
            semop(semID, &sops, 1);
        }//end if

        beforeSleep = buffers[isWorkerID];   //read initial value of buffer
        usleep(sleepTime);
        afterSleep = beforeSleep + addShift;   //add to initial value
        buffers[isWorkerID] = afterSleep;  //put back into the struct

        write++;    //increment counter for nBuffers

        //unlock using +1
        if(semLock){
            sops.sem_num = isWorkerID;   //semaphore number
            sops.sem_op = 1;   //semaphore operation
            sops.sem_flg = 0;   //operation flags
            semop(semID, &sops, 1);
        }//end if

        isWorkerID += workerID;    //increment worker ID
        if (isWorkerID > (nBuffers - 1))
           isWorkerID = isWorkerID % nBuffers;

    }//end while

    update->nReadErrors = readErrCount; //update struct with # of read errors

    return NULL;

}//end void *worker

