#include <stdio.h>
#include <stdlib.h>
#include <stdin.h>
#include <string.h>
#include "ht.h"

int main(int argc, char *argv[])
{
	//Get the file
	char dict[21877];
	char filename[20];
	FILE *file;
	int i = 0;
	int c;
	char *buffer = (char *)malloc(size));

	//Prompt user input
	printf("Choose the file you'd like to open: ");
	fscanf("%s", &filename);
	file = fopen(filename, "rt");
	if(file == NULL)
	{
		printf("File not found.");
		exit(0);
	}

}//end main
