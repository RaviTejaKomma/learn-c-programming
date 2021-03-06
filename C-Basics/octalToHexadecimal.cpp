/*
OVERVIEW:
1)Write a function which takes a octal number as input and returns the hexadecimal number for 
  octalToHexadecimal().
E.g.: octalToHexadecimal(10) returns 8.

2)Write a function which takes a fractional octal number as input and returns the hexadecimal number for 
octalToHexadecimalFraction() until precision two
E.g.: octalToHexadecimal(6.01) returns 6.04

INPUTS: Single octal number num;

OUTPUT: hexadecimal value of the octal number num.

Discalimer:Return 0 for invalid cases.[Negetive Numbers]
*/
#include<math.h>
/*
int pow(int base, int power);
int pow(int base, int power)
{
	int result = 1;
	while (power != 0)
	{
		result = result*base;
		power--;
	}
	return result;
}*/

int octalToHexadecimal(long int num)
{
	if (num < 0)
		return 0; 
	long int remainder,result=0,decimalnumber,finalresult[100],hexanumber=0;
	int i = 0;
	double power = 8;
	while (num != 0)
	{
		remainder = num % 10;
		result = result + (remainder*pow( power, i));
		i++;
		num = num / 10;
	}
	decimalnumber = result;
	i = 0;
	while (decimalnumber > 0)
	{
		remainder = decimalnumber % 16;
		finalresult[i++] = remainder;
		decimalnumber = decimalnumber / 16;
	}
	i--;
	while (i >= 0)
	{
		remainder = finalresult[i--] % 10;
		hexanumber = (hexanumber * 10) + remainder;
	}


	return hexanumber;
}

float octalToHexadecimalFraction(float num)
{
	if (num < 0)
		return 0;
	int intpart = (int)num, i = 0;
	float decimalpart, decimalresult = 0, finalresult, temp;
	decimalpart = num - intpart;
	intpart = octalToHexadecimal(intpart);

	while (i < 2)
	{
		temp = decimalpart * 16;
		decimalresult = decimalresult * 10 + (int)temp;
		if (temp != 0)
		{
			decimalpart = temp - int(temp);
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
	return 0.00;
}