/*
Given two SORTED Circular Linked Lists ,
Write a function to merge those two linked lists .
The First Linked List head should point to the final merged linked list .
The Final merged linked list should also be in SORTED order and a Circular Linked List.
You need to return the Length of Final SLL.

*********
The First linked list head should now point to the Final sorted(Ascending) Linked list First Node
*********
Ex : A: 0->3->5->10->20 (and 20 now pointing back to 0,instead of Null )
B: 1->2->6->11->21->50->70 (70 Pointing back to 1).

The Final Linked List is A:0->1->2->3->5->6->10->11->20->21->50->70 .

Note : Dont use Malloc or create any new nodes ,Only pointers need to be interchanged,
You can use temp pointers although.
Note : The Final Linked List should be  also be a circular Linked List where Last node is
pointing towards the first node.
Note : Return -1 for Invalid Inputs like NULL;

Input : head1 and head2 are Addresses of Two Circular Linked Lists heads .
Output :Length of New SLL .Modify the head1 value, such that it now points to 
Merged Sorted Circular SLL .

Difficulty : Medium
*/
#include <stdlib.h>
#include <stdio.h>

struct node{
	int data;
	struct node *next;
};
// (*head1)->next is right but not *head1->next because of presedence problem
struct node* SortedMerge(struct node *a, struct node *b);
int merge_circularlists(struct node **head1, struct node **head2)
{
	if (head1 == NULL || head2 == NULL || *head1 == NULL || *head2 == NULL)
	{
		return -1;
	}
	struct node *break1,*break2;
	break1 = *head1;
	while ((break1->next) != *head1)
	{
		break1 = break1->next;
	}
	break1->next = NULL;
	break2 = *head2;
	while ((break2->next) != *head2)
	{
		break2 = break2->next;
	}
	break2->next = NULL;
	*head1=SortedMerge(*head1, *head2);
	int len = 0;
	struct node *temp;
	temp = *head1;
	while (temp->next != NULL)
	{
		temp = temp->next;
		len++;
	}
	len++;
	temp->next = *head1;
	return len;
}

struct node* SortedMerge(struct node *a, struct node *b)
{
	struct node *result = NULL;

	if (a == NULL && b == NULL)
	{
		return NULL;
	}
	// Base cases //
	if (a == NULL)
		return(b);
	else if (b == NULL)
		return(a);

	// Pick either a or b, and recur //
	if (a->data <= b->data)
	{
		result = a;
		result->next = SortedMerge(a->next,b);
	}
	else
	{
		result = b;
		result->next = SortedMerge(a, b->next);
	}
	return(result);
}


