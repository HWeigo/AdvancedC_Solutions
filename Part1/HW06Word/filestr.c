// ***
// *** You MUST modify this file.
// ***

#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#ifdef TEST_COUNTWORD
// #define DEBUG 
int countWord(char * filename, char * word, char * line, int size)
{
  // filename: name of the input file
  // word: the word to search
  // line: temporary space to store what is read from the file
  // size: size of line
  // open a file whose name is filename for reading
  // if fopen fails, return -1. 
  // if fopen succeeds, set sum to zero
	
	FILE *fptr;
	fptr = fopen(filename, "r");
	if (fptr == NULL)
	{
		fprintf(stderr, "fopen failed.\n");
		return false;
	}
#ifdef DEBUG
	fprintf(stdout, "fonpen succeed.\n");
#endif

	int lenOfWord = strlen(word);
	int sum = 0;
#ifdef DEBUG 
	fprintf(stdout,"%d\n", lenOfWord);
#endif 
//	while(!feof(fptr))
	while(fgets(line, size, fptr) != NULL)
	{
//		fgets(line, size, fptr);
#ifdef DEBUG 
		fprintf(stdout,"%s\n",line);
#endif 
	    char *cptr = strstr(line, word);
		while(cptr)
		{
			sum++;
			cptr += lenOfWord;
			cptr = strstr(cptr, word);
		}
	}
	return sum;
  // use fgets to read the file
  // if word appears in a line, add one to sum
  //
  // It is possible that the same word appears multiple times in a line
  // If this word is split in two or more lines, do not count the word.
  //
  // It is also possible that a long line is split by fgets. If this happens,
  // do not count the word.
  //
  // return sum
  //
  // If a line is "aaaaa" and the word is "aa", how is the count defined?
  // In this assignment, the first two letters are consumed when the
  // the first match occurs. Thus, the next match starts at the third
  // character. For this case, the correct answer is 2, not 4.
  
  return 0;
}
#endif
