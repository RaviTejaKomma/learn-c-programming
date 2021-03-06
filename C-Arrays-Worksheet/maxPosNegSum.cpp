
/*
OVERVIEW: Given an array of integers find the maximum possible sum formed by a positive and the negative
integer in the array.
Ex: input: [1, 9, 8, 2, 3, -1,-10,-5] output: 8 (formed by 9 and -1) 

INPUTS: An Integer array and the length of the array

OUTPUT: Maximum possible sum formed by a positive and the negative integer in the array

ERROR CASES: Return 0 for the invalid inputs

NOTES:
*/

#include <stdio.h>

int maxPosNegSum(int* input,int length)
{
	if (length < 1)
	{
		return 0;
	}
	int no_of_positive = 0, no_of_negaitve = 0,pos_max,neg_max,result;
	for (int i = 0; i < length; i++)
	{
		if (input[i] >=0)
		{
			no_of_positive += 1;
		}
		else if (input[i] < 0)
		{
			no_of_negaitve += 1;
		}
	}
	if ((no_of_positive + no_of_negaitve) != length || no_of_positive == 0 || no_of_negaitve == 0)
	{
		return 0;
	}
	pos_max = input[0];
	neg_max = -32768;
	for (int i = 0; i < length; i++)
	{
		if (input[i]>pos_max)
		{
			pos_max = input[i];
		}
		if (input[i] < 0 && neg_max<input[i])
		{
			neg_max = input[i];
		}
	}
	result = pos_max + neg_max;
	return result;
}