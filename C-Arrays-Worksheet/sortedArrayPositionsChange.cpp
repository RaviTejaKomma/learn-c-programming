/*
OVERVIEW: In a given ascending sorted array, two numbers are changed their position, please fix those two numbers.
E.g.: In [10, 40, 30, 20, 50] 20 and 40 are swapped, so final output will be [10, 20, 30, 40, 50]

INPUTS: Ascending sorted array with two positions swapped, length of the array.

OUTPUT: Update sorted array by fixing swapped numbers.

ERROR CASES: Return NULL for invalid Inputs.

Problem Code :SAP
*/

#include <stdio.h>

void * sortedArrayPositionsChange(int *Arr, int len)
{
	if (Arr == NULL || len < 1)
	{
		return NULL;
	}
	int i,j=0,temp,swap_index1=0,swap_index2=0;
	for (i = len - 1; i > 0; i--)
	{
		if (Arr[i] < Arr[i-1])
		{
			swap_index1 = i;

			j = i - 1;
			while (j >= 0 && Arr[i] < Arr[j])
			{
				j--;
			}
			swap_index2 = j + 1;
			break;
		}
	}
	/*
	for (i = 1; i<len-1; i++)
	{
		if (Arr[i]>Arr[i - 1] && Arr[i] > Arr[i + 1] && (i + 1) != len - 1)
		{
			swap_index1 = i;
		}
		if (Arr[i]<Arr[i - 1] && Arr[i] < Arr[i + 1] && (i - 1) != 0)
		{
			swap_index2 = i;
		}
	}
	*/

	temp = Arr[swap_index1];
	Arr[swap_index1] = Arr[swap_index2];
	Arr[swap_index2] = temp;
	return Arr;
   
}