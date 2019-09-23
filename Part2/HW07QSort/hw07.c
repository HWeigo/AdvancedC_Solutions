// ***
// *** You MUST modify this file.
// ***

#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#ifdef TEST_COUNTINT
int countInt(char * filename)
{
  // count the number of integers in the file
  // Please notice that if a file contains
  // 124 378 -56
  // There are three integers: 124, 378, -56
  // DO NOT count individual character '1', '2', '4' ...
  //
  // If fopen fails, return -1
	FILE *fptr;
	fptr = fopen(filename, "r");
	if(fptr == NULL)
	{
		fprintf(stderr, "fopen failed.\n");
		return -1;
	}
	int cnt = 0;
	int var;
	while(fscanf(fptr, "%d", &var) == 1)
	{
		cnt++;
	}
#ifdef DEBUG_HW
	fprintf(stdout, "cnt = %d\n", cnt);
#endif
  // remember to fclose if fopen succeeds
	fclose(fptr);
	return cnt;
}
#endif

#ifdef TEST_READINT
bool readInt(char* filename, int * intArr, int size)
{
  // if fopen fails, return false
  // read integers from the file.
  // 
  //
  // if the number of integers is different from size (too
  // few or too many) return false
  // 
  // if everything is fine, fclose and return true
	FILE *fptr;
	fptr = fopen(filename, "r");
	if(fptr == NULL)
	{
		fprintf(stderr, "fopen failed.\n");
		return false;
	}
	int cnt=0;
	do
	{
		fscanf(fptr, "%d", intArr);
		if(!feof(fptr))
		{
#ifdef DEBUG_HW 
			fprintf(stdout, "var = %d\n", *intArr);
#endif 
			intArr++;
			cnt++;
		}
	}while(!feof(fptr));
	
	if(cnt != size) return false;

	fclose(fptr);
	return true;
}
#endif

#ifdef TEST_COMPAREINT
int compareInt(const void *p1, const void *p2)
{
  // needed by qsort
  //
  // return an integer less than, equal to, or greater than zero if
  // the first argument is considered to be respectively less than,
  // equal to, or greater than the second.
	const int *iptr1 = (const int *) p1;
	const int *iptr2 = (const int *) p2;
	int val1 = *iptr1;
	int val2 = *iptr2;
	if(val1 < val2) return -1;
	if(val1 == val2) return 0;
	if(val1 > val2) return 1;
	return 0;
}
#endif

#ifdef TEST_WRITEINT
bool writeInt(char* filename, int * intArr, int size)
{
  // if fopen fails, return false
  // write integers to the file.
  // one integer per line
  // 
  // fclose and return true
	FILE *fptr;
	fptr = fopen(filename, "w");
	if(fptr == NULL)
	{	
		fprintf(stderr, "fopen failed.\n");
		return false;
	}
	for(int i=0; i<size; ++i)
	{
		fprintf(fptr, "%d\n", intArr[i]);
	}

	return true;
}
#endif
