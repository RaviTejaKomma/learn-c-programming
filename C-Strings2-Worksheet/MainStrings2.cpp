/*

Use Strings2 File for testing any other function in other Cpp files of the Strings Project.

DO NOT write main function in any other File or else your Build Fails.s

Objectives of C-Strings-2 Lesson:

->Using malloc to create new strings
->New ways of Handling Strings

Solve CommonRoute , Concat4Strings keeping complexity in Mind , BruteForce solutions take
long time to pass ,and will eventually fail when we run on our side with Timeouts .

Make Sure The Each Individual Test cases for Large inputs dosent take more than 
2Seconds. (ie Real20_CommonRoute TestCase in CommonRouteSpec)
*/

#include "FunctionHeadersStrings2.h"

int main(){

	char sentences[][100] = { "a" };
	char words[][100] = { "a" };
	int counts[100] = {  1, 0 };
	int result=count_word_in_str_way_1(sentences[0], words[0]);
	int i = 0;
	//Test Consonants_Vowels

	//Test getFrequencyofWord

	//Test getSubstring

	//Test getLastWord

	return 0;
}


/*
int hack_len = 0, code_len = 0,index1=0,index2=0,pathcost=0;
int tempindex1 = 0, tempindex2 = 0;
for (; hacklist[hack_len] != '\0' || codelist[code_len] != '\0';)
{
if (hacklist[hack_len] != '\0')hack_len++;
if (codelist[code_len] != '\0')code_len++;
}
int arr[100][100] = {0};
int maxValue=0 , current = 0;
for (int i = hack_len-1; i>=0;i--)
{
for (int j = code_len-1; j >= 0; j--)
{
if (hacklist[i] == codelist[j])
{
arr[i][j] = 1 + arr[i + 1][j + 1];
current = arr[i][j];
if (arr[i][j] > maxValue)
{
maxValue = arr[i][j];
index1 = i;
index2 = j;
}
else if (arr[i][j] == maxValue) // for multiple substrings
{
tempindex1 = i;
tempindex2 = j;
char *substr1,*substr2;
substr1 = (char*)malloc((maxValue+1)*sizeof(char));
substr2 = (char*)malloc((maxValue+1)*sizeof(char));
int s = 0,p=0,q=0,pathcost1=0,pathcost2=0;
// substr1 creation and pathcost1 calculation
p = index1, q = index2;
while (arr[p][q] != 0)
{
substr1[s++] = hacklist[p];
pathcost1 = pathcost1 + (hacklist[p] - 'A' + 1);
p++;
q++;
}
substr1[s] = '\0';
//substr2 creation and pathcost2 calculation
p = tempindex1, q = tempindex2,s=0;
while (arr[p][q] != 0)
{
substr2[s++] = hacklist[p];
pathcost2 = pathcost2 + (hacklist[p] - 'A' + 1);
p++;
q++;
}
substr2[s] = '\0';
if (pathcost1 < pathcost2)
{
maxValue = arr[index1][index2];
index1 = index1;
index2 = index2;
}
else if (pathcost1 > pathcost2)
{
maxValue = arr[tempindex1][tempindex2];
index1 = tempindex1;
index2 = tempindex2;
}
else
{
if (strcmp(substr1, substr2) > 0)
{
// if substring2 appears before substring1 lexicographically
maxValue = arr[tempindex1][tempindex2];
index1 = tempindex1;
index2 = tempindex2;
}
else if (strcmp(substr1, substr2) < 0)
{
// if substring1 appears before substring2 lexicographically
maxValue = arr[index1][index2];
index1 = index1;
index2 = index2;
}
}
free(substr1);
free(substr2);
}
}
else
{
arr[i][j] = 0;
}
}
}
if (maxValue == 0)
{
*cost = 0;
return NULL;
}
char *result;
result = (char*)malloc(maxValue*sizeof(char));
int i = 0;
while (arr[index1][index2] != 0)
{
result[i++] = hacklist[index1];
pathcost = pathcost + (hacklist[index1]-'A'+1);
index1++;
index2++;
}
result[i] = '\0';
*cost = pathcost;
return result;
*/
