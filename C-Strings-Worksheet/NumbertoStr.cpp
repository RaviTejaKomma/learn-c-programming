/*
OVERVIEW: Given a float number ,Convert it into a string 

INPUTS: A Float,Final string ,How many digits after decimal has to be displayed .
Its zero for integers.


OUTPUT: No need to output anything ,Modify the str in function parameter such that it
now holds the string format of the float number specified

Example : number_to_str(345,str,0);
Should copy "345\0" in the str;
number_to_str(345.342,str,2);
Should copy "345.34" in the str;

NOTES: Don't create new string.

*/

#include <stdio.h>
int reverse(int num);
int  reverse(int num)
{
	int remainder = 0,reverse=0;
	while (num!= 0)
	{
		remainder = num % 10;
		reverse = reverse * 10 + remainder;
		num = num / 10;
	}
	return reverse;
}
void number_to_str(float number, char *str,int afterdecimal)
{
	int integer_part,i=0,sign=0;
	int r = 10.35;
	float decimal_part;
	if (number < 0)
	{
		number = (-1)*number;
		sign = 1;
	}
	if (afterdecimal != 0)
	{
		integer_part = (int)number;
		decimal_part = number - integer_part;
	}
	else
	{
		integer_part = number;
	}

	integer_part=reverse(integer_part); //reversed number
	if (sign)
	{
		str[i++] = '-';
	}
	while (integer_part != 0)
	{
		str[i++] =(integer_part % 10)+'0';
		integer_part = integer_part / 10;
	}
	// for decimalpart
	if (afterdecimal != 0)
	{
		str[i++] = '.';
		while (afterdecimal != 0)
		{
			str[i++] = (int)(decimal_part * 10)+'0';
			decimal_part = decimal_part*10 - (int)(decimal_part * 10);
			afterdecimal--;
		}
	}
}
