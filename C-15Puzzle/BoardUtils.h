#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>


//Board Struct which holds all the data of the Puzzle
typedef struct Board {
	//Stores the Actual table of all values ,which are being displayed
	int **table;

	//No of rows of Table
	int rows;

	//No of cols of Table
	int cols;

	//Row postion of the emptyTile ie the 0's row position in table,ie if table[2][4] is 0,emptyTileRow will be 2
	int emptyTileRow;

	//Col postion of the emptyTile ie the 0's col position in table,ie if table[2][4] is 0,emptyTileCol will be 4
	int emptyTileCol;
};

/*

Create a new Board By allocating memory from Heap , Let it be board;
Create a 2D Array from Heap(Dynamically) with specified number of rows and cols
and copy its reference to board->table;

Note : Return NULL for Invalid Inputs 
Note : Copy Rows into newlyCreatedBoard->rows , and vice versa for cols ,
Also copy 0 for emptyTileRow,emptyTileCol

*/
Board * createBoard(int rows, int cols)
{	
	if (rows!=cols || rows<1 || cols<1)
	{
		return NULL;
	}
	Board *newlyCreatedBoard=(Board*)malloc(sizeof(Board));

	newlyCreatedBoard->cols = cols;
	newlyCreatedBoard->rows = rows;

	newlyCreatedBoard->emptyTileRow = 0;
	newlyCreatedBoard->emptyTileCol = 0;

    newlyCreatedBoard->table = (int**)malloc(rows*sizeof(int*));
	for (int r = 0; r < rows; r++)
	{
		newlyCreatedBoard->table[r] = (int*)malloc(cols*sizeof(int));
	}

	return newlyCreatedBoard;
}

/*
	Copy the tobeCopied Array into source->table . 
	Learn how to Copy a 2D array when address of first row is given .
	Note this function is called in the following way 
	
	Input :
	Board *temp=createBoard(4,4);
	int table[4][4]={1,2,3,4,5,6,7,8,9,10,12,11,14,13,0,15}
	initializeBoard(temp,(int *)table,4,4);

	Output :
	source->board should have the 2d array , source->rows must be 4,source ->cols must be 4 , 
	source->emptyTileRow must be 3 , source->emptyTileCol should be 2 .
	[ As 0 is in tobeCopiedArray[3][2] ]

	Note :Also initialize emptyTileRow and emptyTileCol according to the zero position 
	you found in the tobeCopiedArray

	Do Nothing for Invalid Inputs
*/
void initializeBoard(Board * source, int *tobeCopiedArray, int rows, int cols)
{
	if (source != NULL && tobeCopiedArray != NULL && rows == cols && rows>1 && cols>1)
	{
		source->rows = rows, source->cols = cols;

		for (int i = 0; i < rows; i++)
		{
			for (int j = 0; j < cols; j++)
			{
				int value = *((tobeCopiedArray + i*cols) + j);
				if (value == 0)
				{
					source->emptyTileRow = i;
					source->emptyTileCol = j;
				}
				source->table[i][j] = value;
			}
		}
	}
}

/*
Check if the Current board is in Win / Loss Condition . Return 1 if it is Win conditon , 0 if not .
Win Condition : Every Element should be in sequential Order starting from smallest number at table[0][0]
and ending at table[rows-1][cols-2] & table[rows-1][cols-1] will be 0 .

Example Input : 
1,2,3,4
5,6,7,8
9,10,11,12
13,14,15,0 

Example Output : Return 1 

Example Input :
1,2,3,4
5,6,7,8
9,10,15,11
13,14,0,12

Example Output :Return 0
Note : Order will always start from 1 and keep on increasing by 1 , till last but 1 element is reached , Last element will be 0.
*/
int checkBoard(Board * board)
{
	int trackOfValues = 1; // minimum value for any n*n marix // 
	if ((board->emptyTileRow == (board->rows) - 1) && (board->emptyTileCol == (board->cols) - 1))
	{
		for (int i = 0; i < board->rows; i++)
		{
			for (int j = 0; j < board->cols; j++)
			{
				if (i != (board->rows)-1 || j != (board->cols)-1)
				{
					if (board->table[i][j] == trackOfValues)
					{
						trackOfValues+=1;
						continue;
					}
					else
					{
						return 0;
					}
				}
			}
		}
		return 1;
	}
	else
	{
		return 0;
	}
}


/*
Print the Board in a Good Way . 
Make sure Each Number is properly formatted and Seperated ,and Row lines too .
Print Empty Space when you encounter 0 . 
Also make sure your board looks good for 5x5 or 7x7 boards too .
Use your Thinking /UI Skills .
*/
void drawBoardOnScreen(Board *board){

	/*
	Example  : Print the current board like
	1  2  3  4
	5  6  7  8
	9 10 11 12
	13 14  0 15

	----------[W] UP --- [S] Down --- [A] LEFT --- [D] Right--------------
	*/
	
	for (int i = 0; i < board->rows; i++)
	{
		printf("\n\n\n\n\t\t\t\t");
		for (int j = 0; j < board->cols; j++)
		{
			
		}
	}
	//printf("\n\n\n\n\t\t\t\t%d           \n");
}

/*
Clear The Screen , So that we can redraw the Board (which has modified values )
*/
void clearScreen()
{
	system("cls"); // important //
}

/*
	Clear the Screen and ReDraw the Board ,Call above two functions 
*/
void clearAndRedrawScreen(Board * board)
{
	clearScreen();
	drawBoardOnScreen(board);
}



