/*
Given an SLL which has a modified version of node called oddevennode .
Each oddevennode will have a next pointer and a random pointer ,The next will point to the next oddevennode
in the SLL and random will point to NULL initially.

You need to modify the SLL random pointers in such a way that ,All odd numbers in the list
are connected by random pointers in the same order in which they are in SLL and the same for even numbers.

Ex : SLL is : 1-2-3-4-5-6 
Here 1->next will point to 2 ,2->next to 3 and so on till 6->next is NULL .All 1-6 nodes have random set to
NULL initially .Now you need to modify random pointers in such a way that First Odd number in List random will
point to second odd number in the list and so on .

so 1->random should point to 3 .3->random should point to 5 .5->random to NULL (As 5 is the last Oddnumber)
and 2->random should point to 4 ,4->random should point to 6 .6->random to NULL .(As 6 is last even number)

Return an Array consisting of two numbers [Oddcount,Evencount] or NULL for invalid Inputs

Ex 2 : 50->4->3->7->10->99->17
O.P : SLL randoms should be modified as .
50->4->10 . [Even numbers if transversed through Randoms from 50]
3->7->99->17. [Odd numbers if transversed through Randoms from 3]
The function SHOULD RETURN [4,3]  . Oddnumbers and Even numbers count array .

Note : The Order of Randoms Pointers should be in the same order they are in the original SLL .so if 33 has 
arrived before 5 in the SLL .33->random should be 5 but not in reverse .And it should also be continous ,Like 
if  there is only 1 odd node 71 any where between 33 and 5 ,33->random should point to 71 and 71->random should
point to 5.
The type if node is oddevennode ,and not Node .
*/
#include <stdlib.h>
#include <stdio.h>

struct oddevennode{
	int data;
	struct oddevennode * next;
	struct oddevennode * random;

};

int * oddeven_sll(struct oddevennode *head)
{
	if (head == NULL)
	{
		return NULL;
	}
	struct oddevennode *temp, *even = NULL, *odd = NULL;
	int *result;
	result = (int*)calloc(2,sizeof(int));
	temp = head;
	//result[0] = 0;    if
	//result[1] = 0;
	while (temp != NULL)
	{
		if ((temp->data) % 2 == 0)
		{
			if (even == NULL)
			{
				even = temp;
				result[1] += 1;
			}
			else
			{
				even->random = temp;
				even = temp;
				result[1] += 1;
			}
		}
		else
		{
			if (odd == NULL)
			{
				odd = temp;
				result[0] += 1;
			}
			else
			{
				odd->random = temp;
				odd = temp;
				result[0] += 1;
			}
		}
		temp = temp->next;
	}

	return result;
}