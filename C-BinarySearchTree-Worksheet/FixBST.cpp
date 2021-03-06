/*

Given a Binary Search Tree ,with two misplaced Node .Find those nodes and fix them .

Do not create a new tree ,Modify the original tree
Ex : In the below tree 3 and 30 is misplaced .

  5
 / \
2   3
 \
  30
When fixed 30 will be right node of 5 , and 3 will be right node of 2 .

Ex :In the below tree 1 and 20 are misplaced

         9
        / \
       4   1
      /     \
    20      30
Nodes 1 and 20 need to be fixed here .

*/
#include <stdio.h>
#include <stdlib.h>


struct node
{
	struct node * left;
	int data;
	struct node *right;
};




void inorderHelperFunc(struct node *root, struct node **arr, int *index)
{
	if (root == NULL)
	{
		return;
	}
	inorderHelperFunc(root->left, arr, index);
	arr[(*index)++] = root;
	inorderHelperFunc(root->right, arr, index);
}

void fix_bst(struct node *root)
{
	if (root == NULL)
	{
		return;
	}
	//struct node *inOrder=(struct node*)malloc(30*sizeof(struct node));
	struct node **inOrder=(struct node**)malloc(30*sizeof(struct node*));

	int index = 0;
	inorderHelperFunc(root, inOrder , &index);

	int i, j = 0,swap_index1 = 0, swap_index2 = 0;

	for (i = index-1; i > 0; i--)
	{
		if ((*inOrder[i]).data < (*inOrder[i - 1]).data)
		{
			swap_index1 = i;

			j = i - 1;
			while (j >= 0 && (*inOrder[i]).data < (*inOrder[j]).data)
			{
				j--;
			}
			swap_index2 = j + 1;
			break;
		}
	}

	int temp = (*inOrder[swap_index1]).data; 
	(*inOrder[swap_index1]).data=(*inOrder[swap_index2]).data;
	(*inOrder[swap_index2]).data = temp;

	return;
}



