/*
There is a general and he has N Snipers in his control . He has a battefield of NxN Blocks .
He now has to place all N snipers in the battle field such that he can have control of all Blocks,
ie each block should atleast have One sniper having control on it .

A Sniper has control of all blocks in line in all 4 directions . and also all blocks in all 4 diagonals
from his position .

Example :

. C C C
C C S C
. C C C
C . C .

In the above field if Sniper S is placed at (1,2) He has control of all blocks denoted by C .
But their is a problem for the General. All his snipers dont like each other So if any sees any
other sniper in his field of view (Control Blocks) ,he will instantly kill the other sniper .So
Your task is to help the general to place all his N Snipers on NxN field such that ,No sniper can
kill other sniper,but still have control of all the Blocks .

Input : A NxN board , which is all 0's , and N (number of snipers )
Output : Return 1 if its General can place all N snipers or else return 0 .
		 Also modify the battlefield ,such that Blocks which have sniper placed are denoted by 1
		 and all other blocks as 0.

		 Note : If there are multiple correct arrangements ,Arrange in any 1 of the possible ways.
Example Input :
int battle_field[4][4]={0};
solve_nsnipers(&battle_field[0][0],4);

Example Output :
Returns 1 , and modifies battle_field as follows .
0 1 0 0
0 0 0 1
1 0 0 0
0 0 1 0


Read :How to access elements in 2D array when its first element address is passed 
: http://www.geeksforgeeks.org/pass-2d-array-parameter-c/

P.S: The Above Problem is just a modified version of a popular BackTracking problem .
*/

#include "stdafx.h"
bool isSafe(int *board, int row, int col,int N)
{
	int i, j;

	/* Check this row on left side */
	for (i = 0; i < col; i++)
		if (*((board + (row)*N) + i))
			return false;

	/* Check upper diagonal on left side */
	for (i = row, j = col; i >= 0 && j >= 0; i--, j--)
		if (*((board + (i)*N) + j))
			return false;

	/* Check lower diagonal on left side */
	for (i = row, j = col; j >= 0 && i<N; i++, j--)
		if (*((board + (i)*N) + j))
			return false;

	return true;
}

/* A recursive utility function to solve N
Queen problem */
bool solveNQUtil(int *board, int col,int N)
{
	/* base case: If all queens are placed
	then return true */
	if (col >= N)
		return true;

	/* Consider this column and try placing
	this queen in all rows one by one */
	for (int i = 0; i < N; i++)
	{
		/* Check if queen can be placed on
		board[i][col] */
		if (isSafe(board, i, col,N))
		{
			/* Place this queen in board[i][col] */

			*((board + (i)*N) + col)=1;

			/* recur to place rest of the queens */
			if (solveNQUtil(board, col + 1,N))
				return true;

			/* If placing queen in board[i][col]
			doesn't lead to a solution, then
			remove queen from board[i][col] */
			*((board + (i)*N) + col) = 0; // BACKTRACK
		}
	}

	/* If queen can not be place in any row in
	this colum col  then return false */
	return false;
}

int solve_nsnipers(int *battlefield, int n)
{
	if (battlefield == NULL || n <= 3)
	{
		return 0;
	}
	
	if (solveNQUtil(battlefield, 0,n) == false)
	{
		return 0;
	}

	return 1;
}
