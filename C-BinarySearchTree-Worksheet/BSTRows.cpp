/*
Given a Binary Search Tree ,Copy All Elements in BST into a Array in horizontal row by row fashion where
each row is copied from Right to Left.

First copy the Frist row ,Next the second row etc .
Ex : If Bst is 
    6                        <-- Copy this first 
   / \
  4  10                      <-- Copy this row next from 10 and next 4 ..
 / \   \
1   5   15                   <-- Order her is 15 ,5 ,1 
          \
          17

Output will be a array consisting of [6,10,4,15,5,1,17];

Input : BST head node ;
Output :Return An array which has All the elements in row by row order (R->L) .

Note : Return -1 for Invalid Cases .
*/

#include <stdlib.h>
#include <stdio.h>

struct node
{
	struct node * left;
	int data;
	struct node *right;
};

struct node** createQueue(int *, int *);
void enQueue(struct node **, int *, struct node *);
struct node *deQueue(struct node **, int *);

/* Given a binary tree, print its nodes in level order
using array for implementing queue */



/*UTILITY FUNCTIONS*/
struct node** createQueue(int *front, int *rear)
{
	struct node **queue =
		(struct node **)malloc(sizeof(struct node*)*15);

	*front = *rear = 0;
	return queue;
}

void enQueue(struct node **queue, int *rear, struct node *new_node)
{
	queue[*rear] = new_node;
	(*rear)++;
}

struct node *deQueue(struct node **queue, int *front,int *rear)
{
	(*front)++;
	if (*front-1 == *rear)
	{
		return NULL;
	}
	return queue[*front - 1];
}


int* BSTRighttoLeftRows(struct node* root)
{
	if (root == NULL)
	{
		return NULL;
	}
	int rear=0, front=0,i=0;
	struct node **queue = createQueue(&front, &rear);
	struct node *temp_node = root;
	int *result = (int*)malloc(15 * sizeof(int));
	while (temp_node)
	{
		
		result[i++] = temp_node->data;
		/*Enqueue left child */
		if (temp_node->right)
			enQueue(queue, &rear, temp_node->right);

		/*Enqueue right child */
		if (temp_node->left)
			enQueue(queue, &rear, temp_node->left);

		/*Dequeue node and make it temp_node*/
		temp_node = deQueue(queue, &front,&rear);
	}

	return result;
	
}
