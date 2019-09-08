// ***
// *** You MUST modify this file, only the ssort function
// ***

#include <stdio.h>
#include <stdbool.h>

#ifdef TEST_COUNTCHAR

// #define DEBUG 
bool countChar(char * filename, int * counts, int size)
{
  // open a file whose name is filename for reading
  // if fopen fails, return false. Do NOT fclose
  // if fopen succeeds, read every character from the file
  //
	FILE * fptr;
	fptr = fopen(filename, "r");
	if (fptr == NULL)
	{
#ifdef DEBUG
		fprintf(stdout, "fopen fail.\n");
#endif
		return false;
	}
#ifdef DEBUG 
	fprintf(stdout, "fopen succsess.\n");
#endif 

  // if a character (call it onechar) is between
  // 0 and size - 1 (inclusive), increase
  // counts[onechar] by one
  // You should *NOT* assume that size is 256
  // reemember to call fclose
  // you may assume that counts already initialized to zero
  // size is the size of counts
  // you may assume that counts has enough memory space
  //
  // hint: use fgetc
  // Please read the document of fgetc carefully, in particular
  // when reaching the end of the file
	int onechar = 0;
	do
	{
		onechar = fgetc(fptr);
		if(onechar >= 0 && onechar <= (size - 1))
		{
			counts[onechar]++;
		}
	}while(onechar != EOF);
	
	fclose(fptr);
	return true;
}
#endif

#ifdef TEST_PRINTCOUNTS
void printCounts(int * counts, int size)
{
  // print the values in counts in the following format
  // each line has three items:
  // ind, onechar, counts[ind]
  // ind is between 0 and size - 1 (inclusive)
  // onechar is printed if ind is between 'a' and 'z' or
  // 'A' and 'Z'. Otherwise, print space
  // if counts[ind] is zero, do not print

	for(int i = 0; i <= (size - 1); i++)
	{
		if(counts[i] != 0)
		{
			// for charecter a-Z
			if ((i >= 65 && i <= 90) || (i>= 97 && i<= 122))
			{
				fprintf(stdout,"%d, %c, %d\n", i, i, counts[i]);
			}
			else
			{
				fprintf(stdout,"%d, %c, %d\n", i, 32, counts[i]);
			}
		}
	}

}
#endif
