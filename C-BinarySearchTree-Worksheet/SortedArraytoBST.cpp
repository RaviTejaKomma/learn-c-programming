/*
Given a Sorted Array of integers .Create a new Balanced Binary Search Tree from the Array
and return the head of the new BST .

Ex : Input : [1,6,10]
Output : A new BST which structure is as follows 
  6
 / \
1  10

A BST is said to be balanced ,when it satisifes the following property 

Every node's Difference of Left subtree height and right-subtree height is not more than 1 .

Below Tree is Not a Balanced BST ,as 1's left subtree has height of 0 ,but 
right subtree height is 2 
(Diff >1)

  1
   \
    3
   / \
  10  5

Note : Return head of newly created BST
Note : Return Null for invalid Inputs
Note : Donot create a new BST .
*/
#include <stdlib.h>
struct node
{
	struct node * left;
	int data;
	struct node *right;
};

// helper functions //
struct node *createNode(int num)
{
	struct node *newnode = (struct node*)malloc(sizeof(struct node));
	newnode->data = num;
	newnode->left = NULL, newnode->right = NULL;
	return newnode;
}

// given sorted array is the inorder traversal of BST // 
// Now we are constructing Height balanced BST from the given sorted array(i.e inorder traversal) //

struct node *wrapperFunc_convert_array_to_bst(int *arr, int start, int end)
{
	if (start > end)
	{
		return NULL;
	}
	int mid = (start + end) / 2;
	struct node *root=createNode(arr[mid]);
	root->left = wrapperFunc_convert_array_to_bst(arr, start, mid - 1);
	root->right = wrapperFunc_convert_array_to_bst(arr,mid+1,end);
	return root;
}
// helper functions //

struct node * convert_array_to_bst(int *arr, int len)
{
	if (arr == NULL || len <= 0)
	{
		return NULL;
	}
	struct node *result = wrapperFunc_convert_array_to_bst(arr, 0, len - 1);
	return result;
}

