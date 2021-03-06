/*
Write a program to generate elements of a matrix in spiral order.
Store the generated elements in single dimensional array and return that array.

Directions for Spiral are : Go Right ,Go Down ,Go Left, Go Up
Ex:

Matrix:
1	2	3
4	5	6
7	8	9

Spiral order:
1	2	3	6	9	8	7	4	5

Given matrix is a two dimensional array(input_array) with dimensions rows, columns.
If rows, columns are invalid then return NULL.
If input_array is NULL then return NULL.

Example Input :

int board[2][3]={{4,6,7},{1,3,8}};

spiral(2,2,(int **)board); // Rows followed by columns followed by board

Example Output : Return an array consisting of {4,6,7,8,3,1};

Note : Check the function Parameters ,Its a double pointer .

*/


#include "stdafx.h"
#include<stdlib.h>
void spiralUtil(int x, int y,int rows,int cols,int **input_array, int *index, int *result)
{

	    // right //
	    while (y < cols  && input_array[x][y] != -1)
		{
			result[(*index)++] = input_array[x][y];
			input_array[x][y] = -1;
			y++;
		}
		y--;
		x++;
		// down //
		while (x < rows  && input_array[x][y] != -1)
		{
			result[(*index)++] = input_array[x][y];
			input_array[x][y] = -1;
			x++;
		}
		x--;
		y--;
		// left // 
		while (y >= 0 && input_array[x][y] != -1)
		{
			result[(*index)++] = input_array[x][y];
			input_array[x][y] = -1;
			y--;
		}
		y++;
		x--;
		// up //
		while (x >= 0 && input_array[x][y] != -1)
		{
			result[(*index)++] = input_array[x][y];
			input_array[x][y] = -1;
			x--;
		}
		x++;
		y++;

		// if we cannot move in any direction //
		if (x>0 && x<rows && y>0 && y<cols && input_array[x + 1][y] == -1 && input_array[x - 1][y] == -1
			&& input_array[x][y + 1] == -1 && input_array[x][y - 1] == -1)
		{
			result[(*index)++] = input_array[x][y];
			return;
		}
		else if (x>0 && x < rows && y>0 && y < cols)
		{
			spiralUtil(x, y, rows, cols, input_array, index, result);
		}
		
	return;
}
int *spiral(int rows, int columns, int **input_array)
{
	if (input_array == NULL || rows <= 0 || columns <= 0)
	{
		return NULL;
	}

	int direction = 1;
	int *result = (int*)malloc((rows*columns)*sizeof(int));
	int index = 0;

	spiralUtil(0,0,rows,columns,input_array, &index,result);
	return result;
}
