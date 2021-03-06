/*
OVERVIEW: You are given 2 bank statements that are ordered by date. 
Write a function that returns dates common to both statements
(ie both statements have transactions in these dates).
E.g.: Input: A[3] = { { 10, "09-10-2003", "First" }, { 20, "19-10-2004", "Second" }, { 30, "03-03-2005", "Third" } };
B[3] = { { 10, "09-10-2003", "First" }, { 220, "18-01-2010", "Sixth" }, { 320, "27-08-2015", "Seventh" } };
Output: { { 10, "09-10-2003", "First" } }

INPUTS: Two bank statements (array of transactions).

OUTPUT: Transactions having same dates.


ERROR CASES: Return NULL for invalid inputs.

NOTES:
*/

#include <iostream>
bool strcmp1(char *str1, char *str2);
struct transaction {
	int amount;
	char date[11];
	char description[20];
};
bool strcmp1(char *str1, char *str2)
{
	while (*str1 && *str2)
	{
		if (*str1 != *str2)
		{
			return false;
		}
		str1++;
		str2++;
	}

	return  !*str1 && !*str2;
}


struct transaction * sortedArraysCommonElements(struct transaction *A, int ALen, struct transaction *B, int BLen) {
	if (A == NULL || B == NULL)
	{
		return NULL;
	}
	struct transaction result[10];
	int k=0;
	for (int i = 0; i < ALen; i++)
	{
		for (int j = 0; j < BLen; j++)
		{
			if (strcmp1(A[i].date,B[j].date))
			{
				if (strcmp1(A[i].description, B[j].description))
				{
					if (A[i].amount==B[j].amount)
					{
						result[k] = A[i];
						k++;
					}
				}
			}
		}
	}
	if (k == 0)return NULL;
	return result;
}