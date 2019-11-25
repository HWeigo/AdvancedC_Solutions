#ifndef MAZE_H
#define MAZE_H

typedef struct 
{
	int rowNum;
	int colNum;
	int row_start;
	int col_start;
	int row_exit;
	int col_exit;
	int **cells;
}Maze;

enum {ORIGIN, EAST, SOUTH, WEST, NORTH};
void destroyMaze(Maze *mzptr);
void printMaze(Maze *mzptr);
Maze * readMaze(const char *filename, Maze *mzptr);
void getout(Maze *mzptr, int row, int col, int dir, int step);
bool canMove(Maze *mzptr, int row, int col, int dir);
void playMaze(Maze *mzptr, int row, int col, int dir, int step);

#endif

