#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "memory.h"

int main(int argc, char ** agrv)
{
	// argv[1]: size of memory
	
	if(agrc < 3)
	{
		fprintf(stderr, "Not enough argument.");
		return EXIT_FAILURE;
	}
	size = argv[1];
	Memory *mem = NULL;
	createMemory(&mem, size);
	allocateMemory(mem, argv[2]);
}
