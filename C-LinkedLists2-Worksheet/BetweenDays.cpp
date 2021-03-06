/*
Q4: Two dates are given in a 8 node single linked list form,where each node
has one digit only, dates 01-31, months 01-12, year 0000-9999.

Find the number of days in between those two dates .[Exclusive]

Ex : Date1:  0->1->0->1->2->0->0->4 .
     Date2 : 0->5->0->1->2->0->0->4 should return 3 .
As there are 3 days between Jan1st 2004 and Jan 5th 2004.

Ex 2 : Date1 : 3->1->1->2->2->0->1->2.
       Date2 : 0->2->0->1->2->0->1->3 should return 1 .
(There is only one day between 31st Dec 2012 and 2nd  Jan 2013 .)

Note : Consecutive Days and Same Days should return 0;
->Return -1 for NULL Inputs .
->Between Days have to be calculated by not including start and end date .
->The SLL will have 8 Nodes in all cases . Year 999 will be represented as 0999.

Difficulty : Hard 
*/
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
int countLeapYears(int year, int month);
struct node{
	int data;
	struct node *next;
};
 // program with including both start and end dates
int between_days(struct node *date1head, struct node *date2head)
{
	// error cases //
	if (date1head == NULL || date2head == NULL)
	{
		return -1;
	}
	// extracting date1
	int day1 = ((date1head->data) * 10) + (date1head->next->data);
	date1head = date1head->next->next;
	int month1 = ((date1head->data) * 10) + (date1head->next->data);
	date1head = date1head->next->next;
	int year1 = ((date1head->data) * 10) + (date1head->next->data);
	date1head = date1head->next->next;
	year1 = (year1 * 10) + (date1head->data);
	date1head = date1head->next;
	year1 = (year1 * 10) + (date1head->data);
	// extracting date2
	int day2 = ((date2head->data) * 10) + (date2head->next->data);
	date2head = date2head->next->next;
	int month2 = ((date2head->data) * 10) + (date2head->next->data);
	date2head = date2head->next->next;
	int year2 = ((date2head->data) * 10) + (date2head->next->data);
	date2head = date2head->next->next;
	year2 = (year2 * 10) + (date2head->data);
	date2head = date2head->next;
	year2 = (year2 * 10) + (date2head->data);

	///////////////////////////////////////////////////////////////
	const int monthDays[12] = { 31, 28, 31, 30, 31, 30,
		31, 31, 30, 31, 30, 31 };

	long int n1 = year1*365 + day1;

	// Add days for months in given date
	for (int i = 0; i<(month1 - 1); i++)
		n1 += monthDays[i];

	// Since every leap year is of 366 days,
	// Add a day for every leap year
	n1 += countLeapYears(year1,month1);

	// SIMILARLY, COUNT TOTAL NUMBER OF DAYS BEFORE 'dt2'

	long int n2 = year2 * 365 + day2;

	for (int i = 0; i<(month2 - 1); i++)
		n2 += monthDays[i];

	n2 += countLeapYears(year2,month2);

	// return difference between two counts
	if (n1 == n2)
	{
		return (n2 - n1); // same days 
	}
	else if (n2>n1)
	{
		return (n2 - n1 - 1);
	}
	else
	{
		return (n1 - n2 - 1);
	}
}

// This function counts number of leap years before the
// given date
int countLeapYears(int year,int month)
{
	// Check if the current year needs to be considered
	// for the count of leap years or not
	if (month <= 2)
		year--;

	// An year is a leap year if it is a multiple of 4,
	// multiple of 400 and not a multiple of 100.
	return year / 4 - year / 100 + year / 400;
}