/*
OVERVIEW:  Given a single linked list of 0s 1s and 2s ,Sort the SLL such that zeroes 
will be followed by ones and then twos.


INPUTS:  SLL head pointer

OUTPUT: Sorted SLL ,Head should Finally point to an sll of sorted 0,1,2


ERROR CASES:

NOTES: Only 0,1,2, will be in sll nodes
*/

#include <stdio.h>
#include <malloc.h>

struct node {
	int data;
	struct node *next;
};

void sll_012_sort(struct node *head)
{
	int temp, len = 0, i;
	struct node *temp1, *temp2;
	temp1 = head;
	/*
	while (temp1 != NULL)
	{
		len += 1;
		temp1 = temp1->next;
	}
	
	for (i = 0; i<len; i++)
	{

	temp1 = head;
	while (temp1->next != NULL)
	{
	temp2 = temp1->next;
	if (temp1->data > temp2->data)
	{
	temp = temp1->data;
	temp1->data = temp2->data;
	temp2->data = temp;
	}
	temp1 = temp1->next;
	}
	}*/
	// or //
	
	temp1 = head;
	while (temp1 != NULL)
	{
		temp2 = temp1->next;
		while (temp2 != NULL)
		{
			if (temp1->data > temp2->data)
			{
				temp = temp1->data;
				temp1->data = temp2->data;
				temp2->data = temp;
			}
			temp2 = temp2->next;
		}
		temp1 = temp1->next;
	}
	
	//or//
	/*
	int count_of_0 = 0, count_of_1 = 0, count_of_2 = 0;
	while (temp1 != NULL)
	{
		if (temp1->data == 0)
		{
			count_of_0 += 1;
		}
		else if (temp1->data == 1)
		{
			count_of_1 += 1;
		}
		else if (temp1->data == 2)
		{
			count_of_2 += 1;
		}
		temp1 = temp1->next;
	}
	temp1 = head;
	for (i = 0; i < (count_of_0 + count_of_1 + count_of_2); i++)
	{
		if (i < count_of_0)
		{
			temp1->data = 0;
		}
		else if (i < count_of_1)
		{
			temp1->data = 1;
		}
		else if (i < count_of_2)
		{
			temp1->data = 2;
		}
		temp1 = temp1->next;
	}*/


}