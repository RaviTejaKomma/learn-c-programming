/*
OVERVIEW: Given a single linked list, reverse the linked list.
E.g.: 1->2->3->4->5, output is 5->4->3->2->1.

INPUTS: A linked list.

OUTPUT: Reverse the linked list.

ERROR CASES: Return NULL for error cases.

NOTES:
*/

#include <stdio.h>

struct node {
	int num;
	struct node *next;
};

struct node * reverseLinkedList(struct node *head) 
{
	if (head == NULL)
	{
		return NULL;
	}
	/*
	struct node *currNode,*nextNode,*prevNode;
	nextNode = prevNode = NULL;
	currNode = head;
	while (currNode != NULL)
	{
		nextNode = currNode->next;
		currNode->next = prevNode;
		prevNode = currNode;
		currNode = nextNode;
	}
	head = prevNode;
	*/
	// or //
	if (head->next == NULL)
	{
		return head;
	}
	struct node *tail = NULL, *temp = NULL;
	tail = head->next;
	temp = reverseLinkedList(tail);
	head->next->next = head;
	head->next = NULL; // last element
	return temp;
}
