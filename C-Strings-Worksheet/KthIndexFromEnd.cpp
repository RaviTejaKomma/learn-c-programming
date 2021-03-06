/*
OVERVIEW: Given a string, return the letter at Kth index from the end of the string.
E.g.: Input: "qwertyui", 3. Output: 't' (index starting from zero).

INPUTS: A string and value of K.

OUTPUT: Return the letter at Kth index from the end of the string (index starting from zero).

ERROR CASES: Return '\0' for invalid inputs.

NOTES:
*/
#include<stdio.h>
char KthIndexFromEnd(char *str, int K) 
{
	if (str==NULL || K < 0)
	{
		return '\0';
	}
	int len = 0,i=0,j=0;
	while (str[i] != '\0')
	{
		len++;
		i++;
	}
	if (len == 0 || K>len )
	{
		return '\0';
	}
	return str[len - K-1];
	
	
	
}