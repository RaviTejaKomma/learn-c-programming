/*
OVERVIEW: Given a string, reverse all the words not the string.

E.g.: Input: "i like coding". Output: "coding like i"

INPUTS: A string.

OUTPUT: Modify the string according to the logic.

NOTES: Don't create new string.
*/
#include <Stdio.h>
#include <string.h>
void *reverse(char *input, int index1, int index2);
void *reverse(char *input, int index1, int index2)
{
	char temp;
	for (index1,index2; index2>index1; index1++, index2--)
	{
		temp = input[index1];
		input[index1] = input[index2];
		input[index2] = temp;

	}
	return NULL;
}
void str_words_in_rev(char *input, int len)
{
	int i = 0, j = 0;
	while (i<len)
	{
		if (input[i] == '\0')
		{
			break;
		}
		if (input[i] != ' ')
		{
			for (j = i + 1; j<=len; j++)
			{
				if (input[j] == ' ' || j==len)
				{
					reverse(input, i, j - 1);
					i = j;
					break;
				}
			}
		}
		else
		{
			i++;
		}
	}
	reverse(input, 0, len - 1);
}
