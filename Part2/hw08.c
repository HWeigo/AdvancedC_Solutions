// ***
// *** You must modify this file
// ***
#include <stdio.h>  
#include <stdlib.h> 
#include <string.h> 
#include <stdbool.h>
#include "hw08.h"


#ifdef TEST_COUNTVECTOR
int countVector(char * filename)
{
  // count the number of vectors in the file and return the number
  // The input is a binary file. You must use fread.
  // You must not use fscanf(, "%d", ) 
  //
  // If fopen fails, return -1
  //
  // For the mode of fopen, you may use "r" without b
  //

	FILE *fptr;
	fptr = fopen(filename, "r");
	if(fptr == NULL)
	{
		fprintf(stderr, "fopen failed.\n");
		return -1;
	}
	
	int tmp[3];
	int cnt = 0;
	while(fread(tmp, sizeof(int), 3, fptr))
	{
		cnt++;
//		fptr += sizeof(int) * 3;
	}

	fclose(fptr);
	return cnt;
}
#endif

#ifdef TEST_READVECTOR
bool readVector(char* filename, Vector * vecArr, int size)
{
  // if fopen fails, return false
  // read Vectors from the file.
  // 
	FILE *fptr;
	fptr = fopen(filename, "r");
	if(fptr == NULL)
	{
		fprintf(stderr, "fopen failed.\n");
		return false;
	}

	size_t tmp;
	for(int i = 0; i< size; i++)
	{
		tmp = fread(&vecArr[i], sizeof(int), 3, fptr);
		if(tmp != 3) return false;
//		fptr += sizeof(Vector);
	}
  // if the number of integers is different from size (too
  // few or too many) return false
  // 
  // if everything is fine, fclose and return true
	fclose(fptr);
	return true;
}
#endif

#ifdef TEST_COMPAREVECTOR
int compareVector(const void *p1, const void *p2)
{
  // compare the x attribute first
  // If the first vector's x is less than the second vector's x
  // return -1
  // If the first vector's x is greater than the second vector's x
  // return 1
  // If the two vectors' x is the same, compare the y attribute

	const Vector *iptr1 = (const Vector *)p1;
	const Vector *iptr2 = (const Vector *)p2;
	int	x1 = iptr1->x;
	int x2 = iptr2->x;
	if(x1 < x2) return -1;
	if(x1 > x2) return 1;
  // If the first vector's y is less than the second vector's y
  // return -1
  // If the first vector's y is greater than the second vector's y
  // return 1
  // If the two vectors' y is the same, compare the z attribute
	int y1 = iptr1->y;
	int y2 = iptr2->y;
	if(y1 < y2) return -1;
	if(y1 > y2) return 1;
  // If the first vector's z is less than the second vector's z
  // return -1
  // If the first vector's z is greater than the second vector's z
  // return 1
  // If the two vectors' x, y, z are the same (pairwise), return 0
	int z1 = iptr1->z;
	int z2 = iptr2->z;
	if(z1 < z2) return -1;
	if(z1 > z2) return 1;

	return 0;
}
#endif

#ifdef TEST_WRITEVECTOR
bool writeVector(char* filename, Vector * vecArr, int size)
{
  // if fopen fails, return false
  	FILE *fptr;
	fptr = fopen(filename, "w");
	if(fptr == NULL)
	{
		fprintf(stderr, "fopen failed.\n");
		return false;
	}
 
  // write the array to file using fwrite
  // need to check how many have been written
  // if not all are written, fclose and return false
	for(int i=0; i<size; i++)
	{
		size_t tmp = fwrite(&vecArr[i], sizeof(int), 3, fptr);
		if(tmp != 3) return false;
	}
  // fclose and return true
	fclose(fptr);
	return true;
}
#endif

// This function is provided to you. No need to change
void printVector(Vector * vecArr, int size)
{
  int ind = 0;
  for (ind = 0; ind < size; ind ++)
    {
      printf("%6d %6d %6d\n",
	     vecArr[ind].x, vecArr[ind].y, vecArr[ind].z);
    }
}
