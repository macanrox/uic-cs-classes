/*
 * CS 361 - Homework 3
 * Bresia Prudente (bprude2)
 */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <errno.h>
#include <string.h>
#include <stdint.h>	//for intmax_t and uint8_t
#include <sys/mman.h>	//for mmap()
#include <stdbool.h>

//We will have 256 running processes
//Each process has 256 pages in their table
//All page tables are two dimensional arrays
//PageTableEntry pageTables[ PAGETABLESIZE ][ NPROCESSES ]
#define PAGETABLESIZE 256
#define NPROCESSES 256

//Define struct for memory access
typedef struct { 
	uint8_t pid; 
	uint8_t page; 
} MemoryAccess;

//Define struct for page table entries
typedef struct { 
	int frame; // -1 if not currently loaded
	int pageHits;
	int pageMisses;
} PageTableEntry;

//Define struct for frame table entries
//Size is given as a command line argument
typedef struct { 
	uint8_t pid;	//process ID using frame (or 0 if vacant)
	uint8_t page;	//page number (or 0 if vacant)
	bool vacant;	//to confirm that frame is vacant
} FrameTableEntry;

//Declare global page hits and page misses
int globalPageHits;
int globalPageMisses;

//MAIN
int main( int argc, char *argv[] ){
	
	//Print out info
	printf("\nAuthor: Bresia Anne Prudente\n"
	       "ACCC ID: bprude2\n");
	
	//Command line parameters
	if ( argc != 4 ) {
		printf("\nUsage: vmpager inputDataFile [ #memoryAccess frameTableSize ]\n");
	}//end if
	
	//Print out command line prompt
	printf("\nFile Name: %s", argv[1] );
	printf("\n");
	
	//Declare and initialize variables
	int memoryAccessInput = atoi( argv[2] );	//for conversion
	int frameTableInput = atoi( argv[3] );	//for conversion
	int fd = 0;	//file descriptor
	FILE *data;	//filename taken from command line
	struct stat buf;	//struct buffer returned by API
	errno = 0;	//set errno to default value
    int userBuf;
    int maxMemoryAccess;
	MemoryAccess *map;	//memory address pointer
	PageTableEntry pageTables[PAGETABLESIZE][NPROCESSES];	//page table process
    PageTableEntry *pages;  //page table pointer
	FrameTableEntry *frames;	//frame table pointer
	int sizeOfMemAcc = sizeof(MemoryAccess);	//size of the memory struct
	int sizeOfPageTable = sizeof(PageTableEntry);	//size of the page struct
	int sizeOfFrameTable = sizeof(FrameTableEntry);	//size of the frame struct
	int elem;
	//pages[elem].frame = -1;
	//pages[elem].pageHits = 0;
	//pages[elem].pageMisses = 0;
	
	/*****************************************/
	/**** INPUT DATA FILE INTERPRETATION *****/
	/*****************************************/
	
	//Check if user specifies size of memory access
	//Otherwise read entire file if not specified
    
	if (memoryAccessInput == 0 || memoryAccessInput == '\0' ) {
		
		//Open and read the file
		data = fopen( argv[1], "r" );
		fd = fileno(data);
		
		//Declare fstat() and then check for error
		int sizeOfFile = fstat(fd, &buf);
		
		if ( sizeOfFile != 0 ) {
			printf("\nfstat error: [%s]\n", strerror(errno));
			close(fd);
			return -1;
		}//end if ( sizeOfFile...
		
		//Print out file size in bytes
		printf("File size 1: %jd bytes\n",(intmax_t)buf.st_size);
        printf("\n");
        
        userBuf = buf.st_size;
        
		//Map memory address
		map = mmap( 0, userBuf, PROT_READ, MAP_SHARED, fd, 0);
		
		//Print error message
		if (map == MAP_FAILED) {
			perror("mmap() error\n\n");
			exit(-1);
		}//end if (map...

        maxMemoryAccess = userBuf / sizeOfMemAcc;	//max number of memory accesses
		
	}//end if (memoryAccessInput...
    // If user inputs a specific value, do this...
    else {
        
        //Open and read the file
		data = fopen( argv[1], "r" );
		fd = fileno(data);
		
		//Declare fstat() and then check for error
		int sizeOfFile = fstat(fd, &buf);
		
		if ( sizeOfFile != 0 ) {
			printf("\nfstat error: [%s]\n", strerror(errno));
			close(fd);
			return -1;
		}//end if ( sizeOfFile...
		
		//Print out file size in bytes
		printf("File size 2: %jd bytes\n",(intmax_t)buf.st_size);
		printf("\n");
        
        userBuf = buf.st_size - memoryAccessInput;
        
		//Map memory address
		map = mmap( 0, userBuf, PROT_READ, MAP_SHARED, fd, 0);
		
		//Print error message
		if (map == MAP_FAILED) {
			perror("mmap() error\n\n");
			exit(-1);
		}//end if (map...
        
        maxMemoryAccess = userBuf / sizeOfMemAcc;	//max number of memory accesses
        
    }//end else
    
	printf("Memory Access: %d\n", maxMemoryAccess);
	printf("Frame Table Size: %d\n", frameTableInput);
	printf("\n");
	
	//Print out the global page hits and misses
	printf("INFINITE MEMORY\n");
	printf("Initial global page hits: %d\n", globalPageHits);
	printf("Initial global page misses: %d\n", globalPageMisses);
	printf("\n");
	
	//Run the simulation to increment page misses and hits
	int x, y;
	for (x = 0; x < maxMemoryAccess; x++) {
		
		if (map[x].pid > 0 && map[x].page > 0) {
			globalPageHits++;
			//++pages[y].pageHits;
		}//end if (map[i].pid...
		
		else {
            globalPageMisses++;
			//++pages[y].pageMisses;
		}//end else if (map[y].pid...
		
	}//end for (x = 0...
	
	//Sum of hits and misses = memory access is a good thing!
	printf("Global page hits: %d\n", globalPageHits);
	printf("Global page misses: %d\n", globalPageMisses);
	printf("\n");
    
    int closeMap = munmap(map, sizeof(map));
    printf("Closed file and data. Program now exiting...\n\n");
	
	//Close all things
	if (closeMap == -1) {
		perror("Error unmapping the file\n");
		fclose(data);
		close(fd);
		printf("Closed file and data, program exiting\n");
		exit(-1);
	}//end if
	
	return 0;
	
}//end main


