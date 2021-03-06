/*
Given a value n

1. return nth Fibonacci number for the function nthFibonacci(int)
	EX: 0 for n=1 and 1 for n=2


2. return nth prime number for the function nthPrime(int)
	EX: 2 for n=1 and 3 for n=2

INPUTS: single integer n

OUTPUTS: nth Fibonacci number for nthFibonacci() 
		 nth prime number for nthPrime()

ERROR CASES: return -1 for the error cases
*/
#include<stdlib.h>
int nthFibonacci(int n)
{
	if (n <= 0)
	{
		return -1;
	}

	int a = 0, b = 1 ,c=0;
	if (n == 1)
		return 0;
	if (n == 2)
		return 1;
	for (int i = 1; i <=(n-2); i++)
	{
		c = a + b;
		a = b;
		b = c;
	}
	return c;
}

int nthPrime(int num)
{
	if (num <= 0)
	{
		return -1;
	}
	int result[100], i = 0, number = 2, r, flag, j;
	result[i++] = number;
	result[i] = '\0';
	number = 3;
	while(i<num)
	{
		flag = 1;
		for (j = 0; result[j] != '\0'; j++)
		{
			r = result[j];
			if (number%r == 0)
			{
				flag = 0;
				break;
			}
		}
		if (flag)
		{
			result[j] = number;
			result[j + 1] = '\0';
			i++;
		}
		number += 2;
	}
	return result[num-1];
}