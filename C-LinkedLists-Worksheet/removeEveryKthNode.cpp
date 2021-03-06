/*
OVERVIEW: Given a single linked list, remove every Kth node in the linked list.
E.g.: 1->2->3->4->5 and K 2, output is 1->3->5.

INPUTS: A linked list and Value of K.

OUTPUT: Remove every Kth node in the linked list.

ERROR CASES: Return NULL for error cases.

NOTES:
*/

#include <stdio.h>

struct node {
	int num;
	struct node *next;
};

struct node * removeEveryKthNode(struct node *head, int K) 
{
	if (head == NULL || K <= 0 || K==1) // if K==1 all the nodes will be deleted hence we return NULL
	{
		return NULL;
	}
	int count = 1;
	struct node *previous,*current;
	previous = head;
	current = head;
	while (current != NULL)
	{
		if (count%K == 0)
		{
			previous->next = current->next;
			current = current->next;
		}
		else
		{
			previous = current;
			current = current->next;
		}
		count += 1;
	}
	return head;
}