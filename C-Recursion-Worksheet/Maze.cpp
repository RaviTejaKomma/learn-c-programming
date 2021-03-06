/*
Find if there is a connecting path between two given points in the maze.
The maze is a matrix of order MxN, check if there exists a path between (x1,y1) and (x2,y2).
Two points are said to connected if there is a series of 1's non-diagonally.
Example:
Maze of order 4x4:

1	0	1	0
1	1	0	0
0	1	0	1
0	1	1	1

(x1,y1):(0,0)
(x2,y2):(2,3)

In this case, there exists a connected path:
1
1	1
	1		1
	1	1	1

Since there is a connected path, your function has to return 1.
If a path doesn't exist between two co-ordinates then return 0.
If the co-ordinates are invalid or size of the matrix is invalid then return 0.

Function Prototype :path_exists(int *maze, int rows, int columns, int x1, int y1, int x2, int y2) ;
Maze: Pointer to first element of an array .
rows : No of rows
columns : Columns
x1,x2,y1,y2: Co-ordinates

Hint : You can use path_exists as a wrapper function for your original recursive function 
which might take
more parameters .
*/

#include<stdlib.h>




void solveMazeUtil(int *maze, int x, int y,int result1,int result2,int rows,int cols,int **temp,int *isValid)
{
	temp[x][y] = 1;
	if (x == result1 && y == result2)
	{
		*isValid = 1;
		return;
	}
	
	// Check if maze[x][y] is valid
	
	if ((x - 1) >= 0 && !temp[x - 1][y] && *((maze + (x - 1)*cols) + y) != 0 && *isValid!=1)
	{ 
		solveMazeUtil(maze,x - 1, y,result1,result2,rows,cols,temp,isValid);
	}

	if ((x + 1) <rows  && !temp[x + 1][y] && *((maze + (x + 1)*cols) + y) != 0 && *isValid != 1)
	{
		solveMazeUtil(maze, x+1, y, result1, result2, rows, cols, temp, isValid);
	}

	if ((y - 1) >= 0 && !temp[x][y - 1] && *((maze + (x)*cols) + y - 1) != 0 && *isValid != 1)
	{
		solveMazeUtil(maze, x, y-1, result1, result2, rows, cols, temp, isValid);
	}

	if ((y + 1) <cols  && !temp[x][y + 1] && *((maze + (x)*cols) + y + 1) != 0 && *isValid != 1)
	{
		solveMazeUtil(maze, x , y+1, result1, result2, rows, cols, temp, isValid);
	}
	temp[x][y] = 0;
}

int path_exists(int *maze, int rows, int columns, int x1, int y1, int x2, int y2)
{

	if (maze == NULL || rows <= 0 || columns <= 0 || *((maze + x1*columns) + y1)!=1
		|| *((maze + x2*columns) + y2)!=1)
	{
		return 0;
	}
	
	int **temp=(int**)malloc(rows*sizeof(int*));
	for (int i = 0; i < rows; i++)
	{
		temp[i] = (int*)calloc(columns,sizeof(int));
	}
	
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < columns; j++)
		{
			temp[i][j]=0;
		}
	}
	temp[x1][y1] = 1;
	int isValid = 0;
	solveMazeUtil(maze, x1, y1, x2, y2, rows, columns,temp,&isValid);
	return isValid;
}

/*
if (x >= 0 && x < rows && y >= 0 && y < cols)
{
*((temp + x*cols) + y) = 1;

// mark x,y as part of solution path

// Move forward in x direction //
if (solveMazeUtil(maze, x, y + 1, result1, result2, rows, cols,temp,isValid))
return 1;

if (solveMazeUtil(maze, x + 1, y, result1, result2, rows, cols,temp) == 1)// && *((temp + (x+1)*cols) + y) != 1)
return 1;

// If moving in x direction doesn't give solution then Move down in y direction  //
if (solveMazeUtil(maze, x - 1, y, result1, result2, rows, cols,temp) == 1)// && *((temp + (x-1)*cols) + y) != 1)
return 1;


if (solveMazeUtil(maze, x, y - 1, result1, result2, rows, cols,temp) == 1)// && *((temp + x*cols) + y-1) != 1)
return 1;

*((temp + x*cols) + y) = 0;
return 0;
}

*/