#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "maze.h"

Maze * readMaze(const char *filename, Maze *mzptr)
{
	FILE *fptr = fopen(filename, "r");
	if(fptr == NULL)
	{
		fprintf(stderr, "File is NULL.\n");
		return NULL;
	}

	int row = 0;
	int col = 0;
	int maxCol = 0;
	int c;
	while(!feof(fptr)) 
	{
		c = fgetc(fptr);
		if(c == EOF)
		{
			break;
		}
		col ++;
		if(c == '\n')
		{
			col --;
			if(maxCol < col)
			{
				maxCol = col;
			}
			row ++;
			col = 0;
		}
	}

	if(maxCol <= 2 || row <= 2)
	{
		fclose(fptr);
		fprintf(stderr, "Maze's size too small.\n");
		return NULL;
	}

	mzptr = malloc(sizeof(Maze));
	mzptr->rowNum = row;
	mzptr->colNum = maxCol;
	mzptr->cells = malloc(sizeof(int*) * row);
	for(int i = 0; i < row; i++)
	{
		(mzptr->cells)[i] = malloc(sizeof(int) * maxCol);
	}

	fseek(fptr, 0, SEEK_SET);
	int indcol = 0;
	int indrow = 0;
	while(!feof(fptr))
	{
		c = fgetc(fptr);
		if(c == EOF)
		{
			break;
		}
		switch(c)
		{
			case 'b':
				(mzptr->cells)[indrow][indcol] = -1;
				indcol++;
				break;
			case '\n':
				indcol = 0;
				indrow ++;
				break;
			case 's':
				(mzptr->cells)[indrow][indcol] = 0;
				mzptr->row_start = indrow;
				mzptr->col_start = indcol;
				indcol ++;
				break;
			case ' ':
				(mzptr->cells)[indrow][indcol] = row * maxCol + 1;
				indcol ++;
				break;
		}
	}

	for(indcol=0;indcol<maxCol;indcol++)
	{
		if((mzptr->cells)[0][indcol] != -1)
		{
			(mzptr->cells)[0][indcol] = -2;
			mzptr->row_exit = 0;
			mzptr->col_exit = indcol;
		}
	}
	fclose(fptr);
	return mzptr;
}

void printMaze(Maze *mzptr)
{
	if(mzptr == NULL)
	{
		fprintf(stderr, "Maze is NULL.\n");
		return;
	}
	int row = mzptr->rowNum;
	int col = mzptr->colNum;
	for(int i=0;i<row;i++)
	{
		for(int j=0;j<col;j++)
		{
			printf("%d\t", (mzptr->cells)[i][j]);
		}
		printf("\n");
	}
//	printf("%d\n",(mzptr->cells)[0][4]);
	return;
}

void destroyMaze(Maze *mzptr)
{
	for(int j=0; j<(mzptr->rowNum); j++)
	{
		free((mzptr->cells)[j]);
	}
	free(mzptr->cells);
	free(mzptr);
	return;
}

bool canMove(Maze *mzptr, int row, int col, int dir)
{
	int curr = (mzptr->cells)[row][col];
	switch(dir)
	{
		case NORTH:
			row--;
			break;
		case SOUTH:
			row++;
			break;
		case EAST:
			col++;
			break;
		case WEST:
			col--;
			break;
	}
	
	int dest = (mzptr->cells)[row][col];
	
	if((dest == -1 || dest < (curr + 1)) && (dest != -2))
	{
		return false;
	}
	return true;
}

void getout(Maze *mzptr, int row, int col, int dir, int step)
{
	if((mzptr->cells)[row][col] == -2)
	{
		(mzptr->cells)[row][col] = step;
		return;
	}
	(mzptr->cells)[row][col] = step;
	if(canMove(mzptr, row, col, NORTH) && dir != SOUTH)
	{
		(mzptr->cells)[row][col] = step;
		getout(mzptr, row-1, col, NORTH, step + 1);
	}
	if(canMove(mzptr, row, col, SOUTH) && dir != NORTH)
	{
		(mzptr->cells)[row][col] = step;
		getout(mzptr, row+1, col, SOUTH, step + 1);
	}
	if(canMove(mzptr, row, col, EAST) && dir != WEST)
	{
		(mzptr->cells)[row][col] = step;
		getout(mzptr, row, col+1, EAST, step + 1);
	}
	if(canMove(mzptr, row, col, WEST) && dir != EAST)
	{
		(mzptr->cells)[row][col] = step;
		getout(mzptr, row, col-1, WEST, step + 1);
	}
}

void playMaze(Maze *mzptr, int row, int col, int dir, int step)
{
	getout(mzptr, mzptr->row_start, mzptr->col_start, ORIGIN, 0);
	int i = mzptr->row_exit;
	int j = mzptr->col_exit;
	if((mzptr->cells)[i][j] == -2)
	{
		(mzptr->cells)[i][j] = mzptr->rowNum * mzptr->colNum + 1;
	}
}


