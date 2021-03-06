#include "FunctionHeadersArrays1.h"
#include <stdio.h>
int main(){

	//Test RemoveArraysDuplicates
	/*
	int arr[3] = { 1, 2, 7 };
	int len = removeArrayDuplicates(arr, 3);
	printf("%d", len);
	*/

	//Test Students Count
	/*
	int arr2[3]={1,4,10};
	int *newarray=sortedArrayInsertNumber(arr, 3, 3);
	printf("%d %d %d %d", newarray[0], newarray[1], newarray[2],newarray[3]);
	*/
	int* Arr2;
	Arr2 = nPrime(10);
	getchar();
	return 0;
}
//struct student temp;
/*
for (int i = 0; i < len; i++)
{
for (int j = i + 1; j < len; j++)
{
if (students[i].score < students[j].score)
{
temp = students[i];
students[i] = students[j];
students[j] = temp;
}
}

}*/