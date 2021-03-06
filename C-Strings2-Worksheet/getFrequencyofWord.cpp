/*

Problem : Return the Count of how many times the word occurred in given string in two ways
Way1: Not using Recursion
Way2:Using Recursion [Optional]

Input : "Hello HelloAgain HelloAGAINAGAIN commonItsHelloagain","Hello"
Output : 4

Note: Dont modify original str or word,Just return count ,Spaces can also be part of words like "ab cd" in "ab cd ab cd" returns 2
*/

#include <stdlib.h>
int z_algorithm(char *pattern_string, int pattern_len, int string_len);
int z_algorithm(char *pattern_string, int pattern_len, int string_len)
{
	int *z, left, right, whole_len = string_len + pattern_len+1,result=0;
	z = (int*)calloc(whole_len,sizeof(int));
	z[0] = left = right = 0;
	for (int k = 1; k <whole_len; k++)
	{
		if (k > right)
		{
			left = right = k;
			while (right < whole_len && pattern_string[right] == pattern_string[right - left])
			{
				right++;
			}
			z[k] = right - left;
			right--;
		}
		else
		{
			int k1 = k - left;
			if (z[k1] < right - k + 1)
			{
				z[k] = z[k1];
			}
			else
			{
				left = k;
				while (right < whole_len && pattern_string[right] == pattern_string[right - left])
				{
					right++;
				}
				z[k] = right - left;
				right--;
			}
		}
	}
	for (left = 0; left <=whole_len; left++)
	{
		if (z[left] == pattern_len)result++;
	}
	return result;
}
int count_word_in_str_way_1(char *str, char *word)
{
	int strlen , wordlen,i,j,result=0;
	strlen = wordlen = 0;
	for (; str[strlen] != '\0' || word[wordlen] != '\0';)
	{
		if (str[strlen] != '\0')strlen++;
		if (word[wordlen] != '\0')wordlen++;
	}
	char *merged_string;
	merged_string = (char*)calloc((strlen + wordlen + 1),sizeof(char));
	for (i = 0; word[i] != '\0'; i++)
	{
		merged_string[i] = word[i];
	}
	merged_string[i++] = '$';
	for (j=0; str[j] != '\0'; j++)
	{
		merged_string[i++] = str[j];
	}
	merged_string[i] = '\0';
	result=z_algorithm(merged_string, wordlen, strlen);
	return result;
}

int count_word_int_str_way_2_recursion(char *str, char *word){
	return 0;
}

