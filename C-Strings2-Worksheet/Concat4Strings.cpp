/*
Given 4 strings, write a fucntion to get smallest string that consists all four strings.
In Case of Multiple strings with equal smallest length,
Return the string which occurs alphabetically first .

Ex : (acat, tiger, silica, licaria) O/P: "silicariacatiger"
Ex : (def,abc,ghi,jkl)   O/P : “abcdefghijkl” (Alphabetically first )
Ex : (apple,pp,pineapple,nea) O/P: "pineapple";
Ex : (zzzabc,abcdef,yyyzzz,cabyyy) O/P: "cabyyyzzzabcdef" (Order Swapped )

Note : Each string given as input ,should be in the same format in the output string.
Ie if input string is abcd ,it cannot be modified as bdca in the final string .

The Order of Strings in the Final string ,maynot be in the same order
given in which they are given
Function Signatue : char * smallestword(char *s1,char *s2,char *s3,char *s4);

Note : You can use String.h functions .

Constraints :
Length of each String will be less than 100 .

Difficulty : Hard
*/


#include <stdlib.h>
#include <string.h>
#include <stdio.h>
char *merge2OverlappingStrings(char *str1, char *str2);

// to store the permutations //
struct container
{
	char *string1;
	char *string2;
	char *string3;
	char *string4;
};

// to merge 2 overlapping or non overlapping strings //
char *merge2OverlappingStrings(char *str1, char *str2)
{
	int len1 = strlen(str1), len2 = strlen(str2);
	int i = 0, j = 0, k = 0;
	// 2 dimensional grid //
	int arr[100][100] = { 0 };
	int maxValue = 0, current = 0, index1 = 0, index2 = 0;
	
    // in order to be the sufix of str1 and prefix of str2, it is sufficient to elaborate the diagonals 
	//which have 1 in the last column of the grid.
	for (i = len1 - 1; i >= 0; i--)
	{
		for (j = 0; j <len2; j++)
		{
			if ((str1[i] == str2[j]) && (arr[j + 1][i + 1] != 0 || i == len1 - 1))
			{
				arr[j][i] = 1 + arr[j + 1][i + 1];
				current = arr[j][1];
				if (arr[j][i] > maxValue && j == 0)
				{
					maxValue = arr[j][i];
					index1 = j;
					index2 = i;
				}
			}
		}
	}
	// merged string //
	char *result = (char*)malloc((len1+len2+1)*sizeof(char));
	for (i = 0; str1[i] != '\0'; i++)
	{
		result[k++] = str1[i];
	}
	for (j = maxValue; str2[j] != '\0'; j++)
	{
		result[k++] = str2[j];
	}
	result[k] = '\0';
	return result;
}

char * concat_4strings(char *s1, char *s2, char *s3, char *s4){
	if (s1 == NULL || s2 == NULL || s3 == NULL|| s4 == NULL)
	{
		return NULL;
	}
	char *finalResult = (char*)calloc(100, sizeof(char));

	finalResult=strcat(strcat(strcat(strcat(finalResult, s1), s2), s3),s4);

	int n = 4;
	struct container permutations[24] = { { s1, s2, s3, s4 }, { s1, s2, s4, s3 }, { s1, s3, s2, s4 },
	{ s1, s3, s4, s2 }, { s1, s4, s2, s3 }, { s1, s4, s3, s2 }, { s2, s1, s3, s4 }, { s2, s3, s1, s4 },
	{ s2, s4, s1, s3 }, { s2, s4, s3, s1 }, { s2, s3, s4, s1 }, { s2, s1, s4, s3 }, { s3, s4, s1, s2 },
	{ s3, s4, s2, s1 }, { s3, s2, s1, s4 }, { s3, s2, s4, s1 }, { s3, s1, s2, s4 }, { s3, s1, s4, s2 },
	{ s4, s1, s2, s3 }, { s4, s1, s3, s2 }, { s4, s2, s3, s1 }, { s4, s2, s1, s3 }, { s4, s3, s1, s2 }, { s4, s3, s2, s1 } };
	for (int i = 0; i < 24; i++)
	{
		char *result =
		merge2OverlappingStrings(merge2OverlappingStrings
		(merge2OverlappingStrings(permutations[i].string1,permutations[i].string2),
		permutations[i].string3),
		permutations[i].string4);

		if (strlen(finalResult) == strlen(result))
		{
			if (strcmp(finalResult, result) > 0)
			{
				finalResult = result;
			}		
		}
		else if (strlen(finalResult) > strlen(result))
		{
			finalResult = result;
		}
	}
	return finalResult;
}
