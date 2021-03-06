/*
OVERVIEW: Given two strings, find the words that are common to both the strings.
E.g.: Input: "one two three", "two three five".  result: "two", "three".

INPUTS: Two strings.

result: common words in two given strings, return 2D array of strings.

ERROR CASES: Return NULL for invalid inputs.

NOTES: If there are no common words return NULL.
*/

#include <stdio.h>
//#include <string.h>

#include <malloc.h>


#define SIZE 31
bool strcmp1(char *str1, char *str2);
bool isspace(char *str);

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

bool isspace(char *str)
{
	while (*str)
	{
		if (*str != ' ')
		{
			return false;
		}
		str++;
	}
	return true;
}



char ** commonWords(char *str1, char *str2)
{
	if (str1 == NULL || str2 == NULL)
	{
		return NULL;
	}
	

	if (isspace(str1) || isspace(str2))
	{
		return NULL;
	}
	
	int i = 0, j = 0, k = 0, words_count_1, words_count_2,t=0;

	char split_words_1[100][SIZE], split_words_2[100][SIZE];

	char **result = (char**)malloc(20*sizeof(char *));

	for (int j = 0; str1[j] != '\0'; j++){
		if (str1[j] != ' ')
			split_words_1[i][k++] = str1[j];
		else
		{
			// Null terminate split_words_1 once you find space.
			split_words_1[i][k++] = '\0';
			i++;
			k = 0;
		}
	}
	// Null terminate split_words_1 after loop completion.
	split_words_1[i][k++] = '\0';

	// Increment the value of i based on space count to get total number of words
	words_count_1 = i > 0 ? i + 1 : i;
	i = 0; k = 0;

	for (int j = 0; str2[j] != '\0'; j++){
		if (str2[j] != ' ')
			split_words_2[i][k++] = str2[j];
		else
		{
			// Null terminate split_words_2 once you find space.
			split_words_2[i][k++] = '\0';
			i++;
			k = 0;
		}
	}
	// Null terminate split_words_2 after loop ends.
	split_words_2[i][k++] = '\0';

	// Increment the value of i based on space count to get total number of words
	words_count_2 = i > 0 ? i + 1 : i;
	// Your code goes here
	for (i = 0; i <= words_count_1; i++)
	{

		for (int j = 0; j <= words_count_2; j++)
		{
			//cout << split_words_1[i] << "   " << split_words_2[j];
			if (strcmp1(split_words_1[i], split_words_2[j]))
			{
				//cout << split_words_1[i];

				result[t] = (char*)malloc(100 * sizeof(char));

				result[t++] = split_words_1[i];
			}
		}
	}
		// Null terminate the result string.
		result[t] = '\0';
		if (t == 0)
			return NULL;
		else
			return result;
}

