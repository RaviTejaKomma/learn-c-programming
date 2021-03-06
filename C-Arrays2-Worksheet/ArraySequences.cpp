/*
Given an array which has two arithmetic sequences and
one geometric sequence (in any order).
Copy indexes where each sequence starts and ends into an Array and return it.

Note : Each sequence will be of atleast LENGTH 3,and The sequences can be overlapping

Ex : 1, 3, 5, 7, 2, 4, 8, 16 18 20, output is [0, 3, 7, 9, 4, 7]
Ex : 1 ,2, 4, 8, 12, 16, 21, 26     output is [2, 5, 5, 7, 0, 3]
Ex : 10 15 20 30 50 70 100 200 400 800  output is [0, 2, 3, 5, 6, 9]

The final_arr[0], final_arr[1] values in final array
will be start and end indexes of First A.P in the Original Array

The final_arr[2], final_arr[3] values in final array
will be start and end indexes of Second A.P

The final_arr[4], final_arr[5] values in final array
will be start and end indexes of First  G.P (Only)

Input: Array and Length of Array
Output : New Array which has 6 integers , which denote the (start,end) indexes .

Note : All elements in the array will be part of atleast 1 sequence .
Two A.P cannot start at same index .

Difficulty : Medium
*/
// overlappings are possible but no two AP's can overlap.
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

int * find_sequences(int *arr, int len)
{
	if (arr == NULL || len < 1)
	{
		return NULL;
	}
	int *result = (int*)calloc(6,sizeof(int));
	int common_diff, common_ratio,i,j;
	common_diff = arr[1] - arr[0];
	common_ratio = arr[1] / arr[0];
	bool ap = false, gp = false;
	for (i = 1; i < len; i++)
	{
		if (arr[i + 1] - arr[i] == common_diff)
		{
			ap = true;
		}
		else if (arr[i + 1] / arr[i] == common_ratio && !ap)
		{
			gp = true;
		}
		else
		{
			break;
		}
	}
	if (ap)
	{
		result[0] = 0 ;
		result[1] = i;
		goto find_ap_and_gp;
	}
	else if (gp)
	{
		result[4] = 0, result[5] = i ;
		goto find_ap1_and_ap2;
	}
find_ap_and_gp:
	//finding second AP's common difference and first three elements
	for (i; i< len; i++)
	{
		if (arr[i + 1] - arr[i] == arr[i + 2] - arr[i + 1])
		{
			result[2] = i;
			common_diff = arr[i + 1] - arr[i];
			break;
		}
	}
	//finding second AP's last index
	for (i++; i < len; i++)
	{
		if (arr[i + 1] - arr[i] != common_diff)
		{
			result[3] = i;
			break;
		}
	}
	//finding GP common ratio and first three elements
	for (i=0 ; i< len ; i++)
	{
		if (arr[i] != 0 && arr[i + 1] != 0 && ((float)arr[i + 1] / arr[i] == (float)arr[i + 2] / arr[i + 1]))
		{
			result[4] = i;
			common_ratio = arr[i + 1] / arr[i];
			break;
		}
	}
	//finding GP last index
	for (i++; i < len-1; i++)
	{
		if (arr[i + 1] / arr[i] != common_ratio)
		{
			break;
		}
	}
	result[5] = i ;
	goto end;
		
find_ap1_and_ap2:
	//finding  first AP's common difference and first three elements
	for (i=0; i< len ; i++)
	{
		if (arr[i + 1] - arr[i] == arr[i + 2] - arr[i+1])
		{
			result[0] = i;
			common_diff = arr[i + 1] - arr[i];
			break;
		}
	}
	//finding  first AP's last index
	for (i++; i < len; i++)
	{
		if (arr[i + 1] - arr[i]!=common_diff )
		{
			result[1] = i;
			break;
		}
	}
	//finding second AP's first index
	if (arr[i + 2] - arr[i + 1] == arr[i + 1] - arr[i])
	{
		result[2] = i , result[3] = len - 1;
	}
	else
	{
		result[2] = i+1 , result[3] = len - 1;
	}
    goto end;
	
end:
	return result;
}