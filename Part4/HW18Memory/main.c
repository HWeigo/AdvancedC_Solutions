#include <stdio.h>
#include <string.h>
#include <stdlib.h>
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
int main(int argc, char ** argv)
{
	// argv[1]: size of memory
	
	if(argc < 4)
	{
		fprintf(stderr, "Not enough argument.");
		return EXIT_FAILURE;
	}
	int totalSize = (int)strtol(argv[1], NULL, 10);
	int alloSize = (int)strtol(argv[2], NULL, 10);
	Memory *mem = NULL;
	createMemory(&mem, totalSize);
	allocateMemory(mem, alloSize);
	allocateMemory(mem, alloSize);
	freeMemory(mem, 0);
	allocateMemory(mem,3);
	saveOccupancy(mem, argv[3]);
	printOccupancy(mem);
	destroyMemory(mem);

	return EXIT_SUCCESS;
}
