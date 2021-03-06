/*

Given a Binary Search Tree ,Calculate its Inorder ,Postorder and PreOrder

Input : A BST
Output : Copy Inorder/Postorder/Preorder into the array specified .

Note : Memory for the Array is already allocated ,Dont allocate it again using malloc
->Take help of helper functions which are actually solving the problem .
->Dont Process Invalid Inputs

Bonus Task : 
->Go to the BSTTransversals Spec File ,We have left a custom test case for you ,Try to fill
it and understand how testing works .
*/

#include <stdio.h>

struct node
{
	struct node * left;
	int data;
	struct node *right;
};

// Helper Functions //
void inorderHelperFunc(struct node *root, int *arr, int *index);
void preorderHelperFunc(struct node *root, int *arr, int *index);
void postorderHelperFunc(struct node *root, int *arr, int *index);

void inorder(struct node *root, int *arr)
{ 
	if (root == NULL || arr == NULL)
	{
		return;
	}
	int index = 0;
	inorderHelperFunc(root, arr, &index);
}
void inorderHelperFunc(struct node *root, int *arr,int *index)
{
	if (root == NULL)
	{
		return;
	}
	inorderHelperFunc(root->left, arr,index);
	arr[(*index)++] = root->data;
	inorderHelperFunc(root->right, arr, index);
}

void preorder(struct node *root, int *arr)
{
	if (root == NULL || arr == NULL)
	{
		return;
	}
	int index = 0;
	preorderHelperFunc(root, arr, &index);
}
void preorderHelperFunc(struct node *root, int *arr, int *index)
{
	if (root == NULL)
	{
		return;
	}
	arr[(*index)++] = root->data;
	preorderHelperFunc(root->left, arr, index);
	preorderHelperFunc(root->right, arr, index);
}



void postorder(struct node *root, int *arr)
{
	if (root == NULL || arr == NULL)
	{
		return;
	}
	int index = 0;
	postorderHelperFunc(root, arr, &index);
}
void postorderHelperFunc(struct node *root, int *arr, int *index)
{
	if (root == NULL)
	{
		return;
	}

	postorderHelperFunc(root->left, arr, index);
	postorderHelperFunc(root->right, arr, index);
	arr[(*index)++] = root->data;
}


