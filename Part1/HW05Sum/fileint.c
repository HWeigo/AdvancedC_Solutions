// ***
// *** You MUST modify this file.
// ***

#include <stdio.h>
#include <stdbool.h>

#ifdef TEST_ADDFILE

// #define DEBUG 
bool addFile(char * filename, int * sum)
{
	
  // You cannot assume * sum is zero. Thus, * sum needs to be set 0
	
	*sum = 0;
#ifdef DEBUG
	fprintf(stdout, "sum = %d\n", *sum);
#endif 
  // open a file whose name is filename for reading
  // if fopen fails, return false. Do NOT fclose
	FILE *fptr;
	fptr = fopen(filename, "r");
	if(fptr == NULL)
	{
		fprintf(stderr, "fopen failed.\n");
		return false;
	}
#ifdef DEBUG
	fprintf(stdout, "fopen succeed.\n");
#endif

	int var;
	do 
	{
		fscanf(fptr, "%d", &var);
		if(!feof(fptr))
		{
#ifdef DEBUG 
			fprintf(stdout, "var = %d\n", var);
#endif
			*sum += var;
		}
	}while(!feof(fptr));
#ifdef DEBUG 
	fprintf(stdout, "sum = %d\n", *sum);
#endif
	fclose(fptr);
  // if fopen succeeds, read integers using fscan (do not use fgetc)
  //
  // * sum stores the result of adding all numbers from the file
  // When no more numbers can be read, fclose, return true
  //
  return true;
}
#endif


#ifdef TEST_WRITESUM
// #define DEBUG 
bool writeSum(char * filename, int sum)
{
  // open a file whose name is filename for writing
  // if fopen succeeds, write sum as an integer using fprintf
  // fprintf should use one newline '\n'
  // fclose, return true
  //
	FILE *fptr;
	fptr = fopen(filename, "w");
	if(fptr == NULL)
	{
		fprintf(stderr, "fopen failed.\n");
		return false;
	}
#ifdef DEBUG
	fprintf(stdout, "fopen succeed.\n");
#endif

	fprintf(fptr, "%d\n", sum);
	
	fclose(fptr);
  return true;
}
#endif
