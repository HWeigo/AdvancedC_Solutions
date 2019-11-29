// ***
// *** You must modify this file
// ***

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "memory.h"

#ifdef TEST_CREATEMEMORY
bool createMemory(Memory ** mem, int size)
{
  // create a memory object
  // size the number of blocks
  // please be aware that size is not necessarily
  // a multiple of 8
  //
  // * mem stores the memory of the allocated memory object
  // If creating the memory object fails, return false
  // If creating the memory object succeeds, return true
 // if too small 
	if (size <= 1)
	{
		return false;
	}
	*mem = malloc(sizeof(Memory));
	(*mem)->block = malloc(sizeof(int)*size);
	int *inptr = (*mem)->block;
	for(int i=0;i<size;i++)
	{
		inptr[i] = -1;
	}
	(*mem)->size = size;
	return true;
}
#endif

#ifdef TEST_DESTROYMEMORY
void destroyMemory(Memory * mem)
{
	free(mem->block);
	free(mem);
	return;
  // release the memory allocated by createMemory
  // must not have memory leak
}
#endif

#ifdef TEST_SAVEOCCUPANCY
unsigned char setbit(unsigned char num, int bit)
{
	num |= (1<<bit);
	return num;
}

unsigned char clearbit(unsigned char num, int bit)
{
	num &= ~(1<<bit);
	return num;
}

bool saveOccupancy(Memory * mem, const char * filename)
{
  // save the occupancy of the blocks
  // if a block is not occupied, use bit 0
  // if a block is occupied, use bit 1
  // save the bits to the file with filename
  //
  // If the number of blocks is not a multiple of 8,
  // use 0 for the unused bit (or bits)
  //
  // If n is the number of blocks, the output to the file
  // should have n / 8 bytes (when n is a multiple of 8).
  // and n / 8 + 1 bytes (when n is not a multiple of 8).
  //
  // If opening the file or saving fails, return false
  // Othersie, return true
	int numBlocks = mem->size;
	int integer = numBlocks / 8;
	int remainder = numBlocks % 8;
	int byte = 0
	unsigned char output = 0;
	unsigned char mask = 0;
	if(numBlocks == 0)
	{
		return false;
	}

	if(remainder)
	{
		output = 0xFF;
		byte = integer + 1;
		for(int i=0;i<byte;i++)
		{
			output = output << 8 + 0xFF;
		}
		for(int i=0;i<(8-remainder);i++)
		{
			output = clearbit(i);
		}
	}
	else
	{
		output = 0xFF;
		byte = integer;
		for(int i=0;i<byte;i++)
		{
			output = output << 8 + 0xFF;
		}
	}

	for(int i=0;i<numBlocks;i++)
	{
		if(mem->block[i] == -1)
		{
			output = clearbit(output,8*byte-1-i);
		}
	}
	
	// write file 
	FILE *fptr = NULL;
	fptr = fopen(filename, "w");
	fwrite(output, 1, sizeof(output), fptr);
	fclose(fptr);

	return true;
}
#endif

#ifdef TEST_ALLOCATEMEMORY
// This function allocates memory of the specified size
//
// The function uses *first fit* to find consecutive blocks as large
// as the needed size
//
// The function returns the index of the first block of the allocated
// memory
//
// If it is not possible finding large enough consecutive blocks,
// return -1.
//
// Please notice that return 0 means one (or several) blocks are
// allocated and the first block starts from 0. This is different from
// the malloc function in C. When malloc returns NULL (equivalent to
// 0), malloc fails
int checkAvailable(int *inptr, int sizeAllo)
{
	for(int i=0;i<sizeAllo;i++)
	{
		if(inptr[i] != -1)
		{
			return false;
		}
	}
	return true;
}

int allocateMemory(Memory * mem, int size)
{
	if (size <= 0)
    {
      return -1;
    }
	int *inptr = NULL;
	int ind = 0;
	while(ind < (mem->size - size)) // double check!
	{
		inptr =&((mem->block)[ind]);
		if(checkAvailable(inptr, size))
		{
			mem->block[ind] = size;
			for(int i=1;i<size;i++)
			{
				mem->block[ind+i] = 0;
			}
			return ind;
		}
		ind++;
	}
	return -1;
}
#endif 

#ifdef TEST_FREEMEMORY
// release the memory block (or blocks) with
// the starting address
//
// Please notice that this function does not take an argument that
// specifies how many blocks need to be released. Your program
// has to keep track of that.
//
// If starting is invalid, this function is no effect
void freeMemory(Memory * mem, int starting)
{
	if (mem == NULL)
    {
      return;
    }
	if (starting < 0) 
    {
      fprintf(stderr, "WRONG, starting address negative\n");
      return;
    }
	if(starting >= mem->size)
	{
		fprintf(stderr, "WRONG, starting address too large.\n");
		return;
	}
	int check = mem->block[starting];
	if(check == -1 || check == 0)
	{
		return;
	}
	int numDelete = mem->block[starting];
	for(int i=0;i<numDelete;i++)
	{
		mem->block[starting+i] = -1;
	}
	return;
}
#endif  
