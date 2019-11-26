#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include "maze.h"

int main(int argc, char *argv[])
{
	if(argc < 2)
	{
		fprintf(stderr, "Need to input a filename.\n");
		return -1;
	}
	Maze *mzptr = NULL;
	mzptr = readMaze(argv[1], mzptr);
	if(mzptr == NULL)
	{
		return -1;
	}
//	printMaze(mzptr);
//	printf("\n");	

	playMaze(mzptr, mzptr->row_start, mzptr->col_start, ORIGIN, 0);
	
	printMaze(mzptr);
	destroyMaze(mzptr);
	return 0;
}

