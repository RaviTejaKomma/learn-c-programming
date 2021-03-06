/*
OVERVIEW: Given a string, 
Count the number of consonants and vowels and copy them to 'consonants' and 'vowels' respectively
Notes : Neglect Space and Other Symbols .Consider Capital Letters too

E.g.: Input: "aB c" , Output: consonants should contain 2 and vowels 1

INPUTS: A string and two int pointers

OUTPUT: Modify the consonants and vowels pointers accordingly with their counts 
(*consonants=?? ;*vowels=??)

INPUT2: Dont Forget they are pointers ;consonants and vowels are addresses of two variables .

Output: consonants should be ??,vowels should be ??

??:Count them :)

NOTES: Don't create new string , Dont return anything ,you have been given two pointers 
,copy values into those .
*/

#include <stddef.h>


void count_vowels_and_consonants(char *str, int *consonants, int *vowels)
{
	if (str == NULL || *str==NULL)
	{
		*consonants=0;
		*vowels = 0;
		return;
	}
	char index = '\0';
	int i = 0,temp;
	*vowels = 0;
	*consonants = 0;
	while (str[i]!='\0')
	{
		temp = (int)str[i];
		if (!(((int)str[i]>=65 && (int)str[i]<=90) || ((int)str[i] >=97 && (int)str[i]<=122)))
		{
			i++;
			continue;
		}
		index = str[i];
		switch (index)
		{
		case 'a': *vowels += 1;
			       break;
		case 'e': *vowels += 1;
			break;
		case 'i': *vowels += 1;
			break;
		case 'o': *vowels += 1;
			break;
		case 'u': *vowels += 1;
			break;
		case 'A': *vowels += 1;
			break;
		case 'E': *vowels += 1;
			break;
		case 'I': *vowels += 1;
			break;
		case 'O': *vowels += 1;
			break;
		case 'U': *vowels += 1;
			break;
		default: *consonants += 1;
		}
		i++;
	}
}
