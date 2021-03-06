/*

Problem : Return the Last word in a string

Input : I will do this without using String Library
Output : Library

Note:Dont modify original string Neglect Spaces at the right end and at left end if required .
->Create a new string and return it , Use dynamic memory allocation .
*/
#include <stdlib.h>



char * get_last_word(char * str)
{

	int word_start=0, word_end=0,temp=0;
	while (str[word_start] == ' ')
	{
		word_start++;
	}
	for (word_end = word_start; str[word_end] != '\0'; word_end++)
	{
		if (str[word_end+1] != ' ')
		{
			if (str[word_end + 1] == '\0')
			{
				break;
			}
			continue;

		}
		else
		{
			for (temp = word_end + 1; str[temp] == ' '; temp++)
			{

			}
			if (str[temp] == '\0')
			{
				break;
			}
			word_start = temp;
			word_end = temp-1;
		}
	}
	char *result;
	result = (char*)malloc((word_end - word_end+1)*sizeof(char));
	temp = 0;
	while (word_start <= word_end)
	{
		result[temp] = str[word_start++];
		temp++;
	}
	result[temp] = '\0';
	return result;
}
