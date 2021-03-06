/*
OVERVIEW: Given a string, remove all spaces in it.
E.g.: Input: "abd scd". Output: "abdscd"

INPUTS: A string.

OUTPUT: Return string after removing spaces.

ERROR CASES: Return '\0' for invalid inputs.

NOTES: Don't create new string.
*/
#include<stdio.h>
char removeSpaces(char *str) 
{
	if (str == NULL)
	{
		return '\0';
	}
	int i, j=0;
	char temp;
	for (i = 0; str[i] != '\0'; i++)
	{
		if (str[i] == ' ' && str[j]!=' ')
		{
			j = i;
		}
		if (str[j]==' ' && str[i] != ' ')
		{
			temp = str[i];
			str[i] = str[j];
			str[j] = temp;
			i = j;
		}
	}
	if (j != 0)
	{
		str[j] = '\0';
	}
	return *str;
}