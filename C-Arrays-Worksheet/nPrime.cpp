
/*
OVERVIEW: Given a number N return all the prime numbers upto the integer N.
Ex: input: 10 output: [2,3,5,7] 

INPUTS: An Integer N

OUTPUT: Return an Array of Prime numbers until the number N(N inclusive)

ERROR CASES: Return NULL for invalid inputs

Sample Input : 10
Sample Output : An Array consisting elements {2,3,5,7}
NOTES:

Try to think of a optimized way , and avoid unnecessary comparisons.
*/

#include <stdio.h>
#include <stdlib.h>
int* nPrime(int N)
{
	if (N < 2)
	{
		return NULL;
	}
	int *primes,i,j;
	primes = (int*)malloc(N*sizeof(int));
	for (i = 0; i <=N;i++)
	{
		primes[i] = 1;
	}
	primes[0] = 0;
	primes[1] = 0;
	for (i = 2; i <= N; i++)
	{
		for (j = i; i*j <=N; j++)
		{
			primes[i*j] = 0;
		}
	}
	j = 0;
	for (i = 0; i <= N; i++)
	{
		if (primes[i] == 1)
		{
			primes[j] = i;
			j++;
		}
	}

	return primes;
}