#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include "memory.h"

void printOccupancy(Memory *mem)
{
	int size = mem->size;
	for(int i=0;i<size;i++)
	{
		printf("%d ", mem->block[i]);
	}
	printf("\n");
}

const int Operations[] = {'+', '-'}; 

int isOperator(char * word) 
{ 
	int ind; 
	int numop = sizeof(Operations) / sizeof(int); 

	for (ind = 0; ind < numop; ind ++) 
	{ 

		char *loc = strchr(word, Operations[ind]); 
		if (loc != NULL && !isdigit(loc[1])) 
		{ 
			return ind; 
        } 
    } 
	return -1; 
}

bool memoryHelp(char *filename, Memory *mem)
{
	FILE *fptr = NULL;
	fptr = fopen(filename, "r");
	if(fptr == NULL)
	{
		return false;
	}

	char input[10];
	int size = 0;
	while(fgets(input, 10, fptr) != NULL)
	{
		switch(isOperator(input))
		{
			case 0:
				if(fgets(input, 10, fptr) == NULL)
				{
					return false;
				}
				size = strtol(input, NULL, 10);
				allocateMemory(mem, size);
				break;
			case 1:
				if(fgets(input, 10, fptr) == NULL)
				{
					return false;
				}
				size = strtol(input, NULL, 10);
				freeMemory(mem, size);
				break;
		}
	}
	fclose(fptr);
	return true;
}

int main(int argc, char ** argv)
{
	// argv[1]: size of memory
	
	if(argc < 4)
	{
		fprintf(stderr, "Not enough argument.");
		return EXIT_FAILURE;
	}
	int totalSize = (int)strtol(argv[1], NULL, 10);
	Memory *mem = NULL;
	if(!createMemory(&mem, totalSize))
	{
		return EXIT_FAILURE;
	}
	if(!memoryHelp(argv[2], mem))
	{
		return EXIT_FAILURE;
	}
	saveOccupancy(mem, argv[3]);
	printOccupancy(mem);
	destroyMemory(mem);

	return EXIT_SUCCESS;
}
