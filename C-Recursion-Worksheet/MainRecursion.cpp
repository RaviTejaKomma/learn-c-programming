#include "stdafx.h"
#include <stdlib.h>

#include "FunctionHeaders.h"

int main(){
	
	//Check NSnipers

	//Check CountPairs Sample Code 

	//Check Steps Sample Code

	//Check Spiral Sample Code

	//Check Maze Sample Code

	/*
	int maze[4][3] = {
		{ 0, 0, 1 },
		{ 1, 1, 1 },
		{ 1, 0, 1 },
		{ 1, 0, 1 }
	};

	int m = 4, n = 3;
	int x1 = 3, y1 = 0, x2 = 0, y2 = 2;

	int check=path_exists(&maze[0][0], m, n, x1, y1, x2, y2);
	printf("%d\n", check);
	*/

	int inputs[6] = { 3, 5, 7, 9, 10, 12 };
	int answers[6] = { 3, 8, 21, 55, 89, 233 };
	int result = get_steps(inputs[0]);
	result = get_steps(inputs[1]);
	result = get_steps(inputs[2]);
	result = get_steps(inputs[3]);
	result = get_steps(inputs[4]);
	result = get_steps(inputs[5]);

	return 0;
}