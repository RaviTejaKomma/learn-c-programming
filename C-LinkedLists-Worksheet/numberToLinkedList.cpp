/*
OVERVIEW:  Given a number convert that to single linked list (each digit as a node).
E.g.: Input: 234, Output: 2->3->4.

INPUTS:  A number.

OUTPUT: Create linked list from given number, each digit as a node.

ERROR CASES: 

NOTES: For negative numbers ignore negative sign.
*/

#include <stdio.h>
#include <malloc.h>

int reverse(int n);
struct node
{
	int num;
	struct node *next;
};



struct node * numberToLinkedList(int N)
{
	int remainder = 0;
	if (N < 0)
	{
		N = (-1)*N;
	}
	struct node *start=NULL, *newnode;
	if (N == 0)
	{
		start = (struct node*)malloc(sizeof(struct node));
		start->num = 0;
		start->next = NULL;
	}
	while (N > 0)
	{
		remainder = N % 10;
		if (start==NULL)
		{
			start = (struct node*)malloc(sizeof(struct node));
			start->num=remainder;
			start->next = NULL;
		}
		else
		{
			newnode = (struct node*)malloc(sizeof(struct node));
			newnode->num = remainder;
			newnode->next = start;
			start = newnode;
		}
		N = N / 10;
	}
	return start;
}