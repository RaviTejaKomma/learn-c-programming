/*
OVERVIEW:  You are given scores for students of a class in alphabetical order. Write a function that sorts these scores in descending order.
Input is array of structures of type student (each student has name and score).
E.g.: If input is [ { "stud1", 20 }, { "stud2", 30 }, { "stud3", 40 } ] (three students with marks 20, 30 , 40).
Output for this will be [ { "stud3", 40 }, { "stud2", 30 }, { "stud1", 20 } ]

INPUTS: Array of structures of type student, length of array.

OUTPUT: Sort the array in descending order of scores.

ERROR CASES: Return NULL for invalid Inputs.

Problem Code :SD
*/

#include <stdio.h>
int partition(struct student *students,int left, int right, int pivot);
void quickSort(struct student *students, int left, int right);
void * swap(struct student *students, int num1, int num2);
struct student {
	char name[10];
	int score;
};

void * scoresDescendingSort(struct student *students, int len)
{
	if (students == NULL || len < 1)
	{
		return NULL;
	}
	//in place sorting;;
	quickSort(students, 0, len - 1);
	return NULL;
}
void * swap(struct student *students, int num1, int num2)
{
	struct student temp;
	temp= students[num1];
	students[num1] = students[num2];
	students[num2] = temp;
	return NULL;
}
int partition(struct student *students,int start, int end, int pivot)
{
	int partitionIndex = start;
	for (int i = start; i < end; i++)
	{
		if (students[i].score >= students[pivot].score)
		{
			swap(students, i, partitionIndex);
			partitionIndex += 1;
		}
	}
	swap(students, partitionIndex, pivot);
	return partitionIndex;
}
void quickSort(struct student *students,int left, int right){
	if (right - left <= 0){
		return;
	}
	else {
		int pivot = right;
		int partitionPoint = partition(students,left, right, pivot);
		quickSort(students,left, partitionPoint - 1);
		quickSort(students,partitionPoint + 1, right);
	}
}
/*https://www.youtube.com/watch?v=COk73cpQbFQ*/
//quick sort algorithm my code school