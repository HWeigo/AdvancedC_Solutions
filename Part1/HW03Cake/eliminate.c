// ***
// *** You MUST modify this file
// ***

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h> 
#include <string.h> 

#ifdef TEST_ELIMINATE
// 100% of the score
void eliminate(int n, int k)
{
// #define DEBUG

	// allocate an arry of n elements
	int * arr = malloc(sizeof(* arr) * n);
	// check whether memory allocation succeeds.
	// if allocation fails, stop
	if (arr == NULL)
    {
      fprintf(stderr, "malloc fail\n");
      return;
    }

#ifdef DEBUG

	fprintf(stdout, "arr has %d number. \n", n);
	fprintf(stdout, "k is  %d. \n", k);

#endif
 
	// initialize all elements
	for(int i=0; i< n; ++i)
	{
		arr[i] = i + 1;
		fprintf(stdout, "%d \n", arr[i]);
	}
  
  // counting to k,
  // mark the eliminated element
  // print the index of the marked element
  // repeat until only one element is unmarked




  // print the last one




  // release the memory of the array
  free (arr);
}
#endif
