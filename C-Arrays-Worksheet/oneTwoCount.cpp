/*
OVERVIEW: Given an Integer Array return the count of one's and two's in a new array of length two.
Ex: input: [1,2,2,1,2,1,2] 
	output: [3,4]
	where 3 is the count of 1's and 4 is the count of 2's

INPUTS: An Integer Array and length of the array 

OUTPUT: An Array with 1's count and 2's count

ERROR CASES: Return NULL for invalid inputs

Difficulty : Very Easy
*/
#include<stdlib.h>
#include <stdio.h>
int* oneTwoCount(int* input, int length)
{
	int *result;
	result = (int*)calloc(2,sizeof(int));
	result[0] = 0;
	result[1] = 0;
	if (length < 1)
	{
		return NULL;
	}
	for (int i = 0; i < length; i++)
	{
		if (input[i] == 1)
		{
			result[0]+=1;
		}
		else if (input[i] == 2)
		{
			result[1]+=1;
		}
		else
		{
			return NULL;
		}
	}
	return result;
}