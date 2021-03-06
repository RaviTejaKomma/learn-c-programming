/*
OVERVIEW: You are given 2 bank statements that are ordered by date - 
Write a function that produces a single merged statement ordered by dates.
E.g.: Input: A[3] = { { 10, "09-10-2003", "First" }, { 20, "19-10-2004", "Second" }, { 30, "03-03-2005", "Third" } };
B[2] = { { 10, "09-10-2003", "First" }, { 220, "18-01-2010", "Sixth" } };
Output: { { 10, "09-10-2003", "First" }, { 10, "09-10-2003", "First" }, { 20, "19-10-2004", "Second" },  30, "03-03-2005", "Third" }, { 220, "18-01-2010", "Sixth" } }

INPUTS: Two bank statements (array of transactions).

OUTPUT: Combined statement ordered by transaction date.

ERROR CASES: Return NULL for invalid inputs.

NOTES:
*/

#include <iostream>

struct transaction {
	int amount;
	char date[11];
	char description[20];
};
int datecmp(char *date1, char *date2)
{
	int date1_day = date1[0] - '0', date1_month = date1[3] - '0', date1_year = date1[6] - '0';
	date1_day = date1_day * 10 + date1[1] - '0';
	date1_month = date1_month * 10 + date1[4] - '0';
	date1_year = date1_year * 1000 + (date1[7] - '0') * 100 + (date1[8] - '0') * 10 + date1[9] - '0';
	int date2_day = date2[0] - '0', date2_month = date2[3] - '0', date2_year = date2[6] - '0';
	date2_day = date2_day * 10 + date2[1] - '0';
	date2_month = date2_month * 10 + date2[4] - '0';
	date2_year = date2_year * 1000 + (date2[7] - '0') * 100 + (date2[8] - '0') * 10 + date2[9] - '0';
	if (date1_year < date2_year)
	{
		return 2;
	}
	else if (date1_year > date2_year)
	{
		return 1;
	}
	else if (date1_year == date2_year)
	{
		if (date1_month < date2_month)
		{
			return 2;
		}
		else if (date1_month > date2_month)
		{
			return 1;
		}
		else if (date1_month == date2_month)
		{
			if (date1_day < date2_day)
			{
				return 2;
			}
			else if (date1_day > date2_day)
			{
				return 1;
			}
			else if (date1_day == date2_day)
			{
				return 0;
			}
		}
	}
	
}

struct transaction * mergeSortedArrays(struct transaction *A, int ALen, struct transaction *B, int BLen) {
	if (A == NULL || B == NULL || ALen<0 || BLen<0)
	{
		return NULL;
	}
	struct transaction sorted[100];
	int i, j, k;
	j = k = 0;
	for (i = 0; i < ALen + BLen;i++) 
	{
		if (j < ALen && k < BLen) 
		{
			if (datecmp(A[j].date,B[k].date)==2) // A[j].date is small 
			{
				sorted[i] = A[j];
				j++;
			}
			else
			{
				sorted[i] = B[k];
				k++;
			}
		}
		else if (j == ALen) 
		{
			sorted[i] = B[k];
			k++;			
		}
		else 
		{
			sorted[i] = A[j];
			j++;		
		}
	}
	return sorted;
}