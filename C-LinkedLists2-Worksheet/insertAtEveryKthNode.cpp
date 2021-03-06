/*
OVERVIEW: Given a single linked list insert a new node at every Kth node with value K.
E.g.: 1->2->3->4->5, k = 2, 1->2->2->3->4->2->5

INPUTS: A linked list and Value of K.

OUTPUT: Insert a new node at every Kth node with value K.

ERROR CASES: Return NULL for error cases.

NOTES:
*/

#include <stdio.h>
#include <malloc.h>

struct node {
	int num;
	struct node *next;
};

//Use this function , Dont create any new function with name createNode or createList
struct node * createNodeDummy(int num)
{
	struct node *newNode = new node; // or //(struct node *)malloc(sizeof(struct node));
	newNode->num = num;
	newNode->next = NULL;
	return newNode;
}

struct node * insertAtEveryKthNode(struct node *head, int K) 
{
	if (head == NULL || K<1)
	{
		return NULL;
	}
	/*
	int track = 0;
	struct node *current=head,*previous=head;
	while (current != NULL || track==K)
	{
		if (track != K)
		{
			previous = current;
			current = current->next;
			track++;
		}
		else
		{
			struct node *newnode=createNodeDummy(K);
			newnode->next = current;
			previous->next = newnode;
			track = 0;
		}
	}

	return head;*/
	/// or ///
	
	struct node *previous = head;

	struct node *newnode;

	int temp;

	if (head == NULL || K <= 0)

		return NULL;

	previous = head;

	temp = K;

	while (previous)

	{

		temp--;

		if (temp == 0)

		{

			newnode = createNodeDummy(K);

			(newnode)->next = previous->next;

			previous->next = (newnode);

			temp = K;

			previous = newnode->next;

		}
		else
		{
			previous = previous->next;
		}
	}

	return head;
}
