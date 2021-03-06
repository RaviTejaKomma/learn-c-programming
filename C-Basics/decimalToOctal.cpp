/*
OVERVIEW: 
1)Write a function which takes a decimal number as input and returns the octal number for decimalToOctal().
E.g.: decimalToOctal(10) returns 12.

2)Write a function which takes a fractional decimal number as input and returns the octal number for decimalToOctalFraction()
until precision two
E.g.: decimalToOctal(6.06) returns 6.03

INPUTS: Single decimal number num;

OUTPUT: Octal value of the Decimal Number num.

Discalimer:Return 0 for invalid cases.[Negetive Numbers]
*/
#include<stdlib.h>
int decimalToOctal(int num)
{
	int remainder=0,result[100],final_result=0,i=0;
	if (num > 0)
	{
		//result = (int*)malloc(sizeof(int));
		while (num > 0)
		{
			remainder = num % 8;
			result[i++] = remainder;
			num = num / 8;
		}
		i--;
		while (i >= 0)
		{
			remainder = result[i--] % 10;
			final_result = (final_result * 10) + remainder;
		}
		return final_result;
	}
	return 0;
}

float decimalToOctalFraction(float num)
{ 
	if (num < 0)
	{
		return -1;
	}
	int intpart=(int)num,i=0;
	float decimalpart ,decimalresult=0,finalresult,temp;
	decimalpart = num - intpart;
	intpart = decimalToOctal(intpart);
	while (i < 2)
	{
		temp = decimalpart * 8 ;
		decimalresult = decimalresult*10 +(int)temp;
		if (temp != 0)
		{ 
			decimalpart =  temp -int(temp);
		}
		else
		{
			decimalpart = temp;
		}

		i++;
	}
	decimalresult = decimalresult / 100;
	finalresult = intpart + decimalresult;
	return finalresult;
}
