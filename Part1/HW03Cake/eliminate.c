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
		arr[i] = i;

#ifdef DEBUG 
		fprintf(stdout, "%d \n", arr[i]);
#endif 

	}
#ifdef DEBUG 
	fprintf(stdout,"\n \n");
#endif 

	// counting to k,
	// mark the eliminated element
	// print the index of the marked element
	// repeat until only one element is unmarked
	int idx = 0;
	int remains_num = n;

	while(remains_num != 1)
	{
		// counting to k
		int set_idx = 0,	// flag used to detect whether idx reach k
			cnt = 1;		// counter of how many valid step was taken
		while(set_idx != 1)
		{
			idx++;
			if(idx == n) idx = 0;
			if(arr[idx] != -1)
			{
				cnt++;
			}
			if(cnt == k) set_idx = 1;
		}
		// fprintf(stdout, "idx: %d \n", idx);
		fprintf(stdout, "%d\n", arr[idx]);
		arr[idx] = -1;
		
#ifdef DEBUG
		for(int i=0; i<n; ++i)
		{
			fprintf(stdout, "%d \t", arr[i]);
		}
		fprintf(stdout,"\n");
#endif

#ifdef DEBUG 
		fprintf(stdout, "Before eliminate, the idx is at: %d \n", idx);
#endif 
		do
		{
			idx++;
			if(idx == n) idx = 0;
		}while(arr[idx] == -1);
#ifdef DEBUG 
		fprintf(stdout, "After eliminate, the idx is at: %d \n", idx);
#endif 
		remains_num--;
	}
	
	// print the last one
	fprintf(stdout, "%d \n", arr[idx]);

	// release the memory of the array
	free (arr);
}
#endif
