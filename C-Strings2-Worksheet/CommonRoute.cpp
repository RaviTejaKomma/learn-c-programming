/*
There are two friends Hack and Code . They have decided to go on a world tour which consists of only Islands.
There are a total of 26 Islands in the world ,where Each Island has a name from A ,B ,C ,D ... till Z .
[Each Island name is restricted to only 1 Letter]

Hack and Code seperately made their travel lists ,where they specify List of Islands they want to visit
in a particular order .
Ex : If Hack's List is "CADBZ" , He wants to go first to C island ,next A island and B and so on ,and finally
reach Z island .

Now Hack and Code had shared their lists , and they observed that their lists are not at all similar .
No one wants to compromise on their Travel List and Order,and each wants other person to accept their List .
After a through discussion,They finally decided that they will Find the Common route in the List which covers
Maxium Islands and make that their Tour .

Cost of Visting each Island will be equal to the position in the Alphabats Series that Island Name is( Letter ) .
Cost of Visiting A island is 1 ,H is 8 , Z is 26 and so on .
Can you help Hack and Code to find the Common Route ,so that their dispute is solved .

Inputs :
Two Strings of Capital Letters ,where each Letter denotes an Island .They can visit each Island any
number of times.
Output :
Return a Common Route String which covers maxiumum Islands

Example 1 :
Input : HackList="CADBZAYZY" CodeList="BZAYACAFRDBZ"
Output: Return "BZAY" and modify the Cost variable to  54 [2+26+1+25]
Explanation :
They both can start at B ,Go to Z ,and go to A,Finally reach Y .This Route covers 4 islands ,where
all other routes like CA ,DBZ , ZAY ,etc covers less than 4 islands .

Note : If there are Two Maximum routes which cover Equal number of Islands , Return the Route which Costs
less . IF the Costs are also equal ,Return the Route ,whose FirstIsland is Alphabetically Before
[Assume two routes with same cost ,will always have first island a different one].

Final Route Islands should be in Both Hack and Codes list and in same order ,If Final route is ACB
There must be a route in both Lists which is ACB . [AZZCB , ADCDB dont qualify ,Order should be continous]
Return NULL for Invalid Inputs or No Common Route[Cost will be 0].

Example 2 : Input : "CABTYUZZZ" , "ZZZTYUCAB" , Output : "CAB" and cost should be 6 (Least Cost )
Example 3 : Input : "HHHZAADTD" , "ZAAHHHDTDRR" , Output : "DTD" (DTD , HHH ,ZAA has same cost of 28 ,but the
First Island in DTD ie 'D' occurs alphabatically before 'H' and 'Z')

*/

#include <stdlib.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
 

char * find_common_route(char * hacklist, char *codelist, int *cost)
{
	if (hacklist == NULL || codelist == NULL)
	{
		return NULL;
	}
	if (*hacklist == NULL || *codelist == NULL)
	{
		*cost = 0;
		return NULL;
	}
	int hacklen = strlen(hacklist),codelen=strlen(codelist),pathcost=0;
	int current[20000] = { 0 }, previous[20000] = { 0 };
	int maxvalue = 0, tempMax=0, curr=0, index=0;
	if (hacklen <= 1000 || codelen <= 1000)
	{
		for (int i = hacklen - 1; i >= 0; i--)
		{
			for (int j = codelen - 1; j >= 0; j--)
			{
				if (hacklist[i] == codelist[j])
				{
					current[j] = previous[j + 1] + 1;
					curr = current[j];
					if (curr > maxvalue)
					{
						maxvalue = curr;
						index = i;
					}
					if (curr == maxvalue) // for multiple substrings
					{
						int tempindex = i;
						char *substr1, *substr2;
						substr1 = (char*)malloc((maxvalue + 1)*sizeof(char));
						substr2 = (char*)malloc((maxvalue + 1)*sizeof(char));

						int  pathcost1 = 0, pathcost2 = 0;

						// substr1 creation and pathcost1 calculation
						//substr2 creation and pathcost2 calculation

						int p1 = index, p2 = tempindex, s = 0;
						tempMax = maxvalue;

						while (tempMax != 0)
						{
							substr1[s] = hacklist[p1];
							pathcost1 = pathcost1 + (hacklist[p1] - 'A' + 1);
							substr2[s] = hacklist[p2];
							pathcost2 = pathcost2 + (hacklist[p2] - 'A' + 1);
							p1++, p2++, s++;
							tempMax--;
						}
						substr1[s] = '\0';
						substr2[s] = '\0';

						if (strcmp(substr1, substr2) != 0)
						{
							if (pathcost1 < pathcost2)
							{
								index = index;
							}
							else if (pathcost1 > pathcost2)
							{
								index = tempindex;
							}
							else
							{
								if (strcmp(substr1, substr2) > 0)
								{
									// if substring2 appears before substring1 lexicographically
									index = tempindex;
								}
								else if (strcmp(substr1, substr2) < 0)
								{
									// if substring1 appears before substring2 lexicographically
									index = index;
								}
							}
						}

						free(substr1);
						free(substr2);
					}
				}
			}
			for (int l = 0; l <= codelen; l++)
			{
				previous[l] = current[l];
				current[l] = 0;
			}
		}
	}
	else
	{
		for (int i = hacklen - 1; i >= 0; i--)
		{
			for (int j = codelen - 1; j >= 0; j--)
			{
				if (hacklist[i] == codelist[j])
				{
					current[j] = previous[j + 1] + 1;
					curr = current[j];
					if (curr > maxvalue)
					{
						maxvalue = curr;
						index = i;
					}
					
				}
			}
			for (int l = 0; l <= codelen; l++)
			{
				previous[l] = current[l];
				current[l] = 0;
			}
		}
	}
	
	if (maxvalue == 0)
	{
		*cost = 0;
		return NULL;
	}
	char *result;
	result = (char*)malloc(maxvalue*sizeof(char));
	int k = 0;
	while (maxvalue!=0)
	{
		result[k++] = hacklist[index];
		pathcost = pathcost + (hacklist[index] - 'A' + 1);
		index++;
		maxvalue--;
	}
	result[k] = '\0';
	*cost = pathcost;
	return result;
}




