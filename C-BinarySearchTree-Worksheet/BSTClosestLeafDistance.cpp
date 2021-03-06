/*
Given a Binary Search Tree and a Node(temp).Find the Closest Distance from the Node to 
any leaf of the Tree.
(Least number of Edges needed to be travelled to go to the Node )

Ex : Consider the below tree .
      2
     / \
,   1   3
         \
         14
For 3 ,Output is 1 . As its closest leaf is 14 and 3 is at a distance of 1 to 14 .

Ex 2: Consider the below tree .
    2
   / \
  1   3
       \
        14
        / \
       9   20
      /      \
     6       25
For 3 ,Output is now 2 . As closest leaf to 3 is 1 and 3 is at a distance of 2 to 1 .
(through root 2 )

For 14 ,O/P : 2
For 2 , O/P : 1

Return -1 ,for Invalid Inputs
*/

#include <stdlib.h>
#include <stdio.h>

struct node{
  struct node * left;
  int data;
  struct node *right;
};

int  getMin(int i, int j)
{
	int min= (i < j) ? i : j;
	return min;
}
int closestDown(struct node *root)
{
	if (root == NULL)
	{
		return INT_MAX;
	}
	if (root->left == NULL && root->right == NULL)
	{
		return 0;
	}
	return 1 + getMin(closestDown(root->left), closestDown(root->right));
}
int closestNode(struct node *root, struct node *temp, struct node *visitedNodes[], int index)
{
	if (root == NULL)
	{
		return INT_MAX;
	}
	if (root == temp)
	{

		//  Find the cloest leaf under the subtree rooted with given key
		int res = closestDown(root);

		// Traverse all ancestors and update result if any parent node
		// gives smaller distance
		for (int i = index - 1; i >= 0; i--)
			res = getMin(res, index - i + closestDown(visitedNodes[i]));
		return res;
	}
		// If key node found, store current node and recur for left and
		// right childrens
		visitedNodes[index] = root;
		return getMin(closestNode(root->left, temp, visitedNodes, index + 1),
			closestNode(root->right, temp, visitedNodes, index + 1));
	
}
int get_closest_leaf_distance(struct node *root, struct node *temp)
{
	if (root == NULL || temp == NULL)
	{
		return -1;
	}
	struct node *visitedNodes[100];
	return closestNode(root, temp, visitedNodes, 0);
}