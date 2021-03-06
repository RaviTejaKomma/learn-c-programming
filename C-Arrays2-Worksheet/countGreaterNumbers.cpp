/*
OVERVIEW: You are given a bank statement where transactions are ordered by date. Write a function that finds the number of transactions in that statement after a given date.
-- find the count of numbers greater than a given number in a sorted array.
E.g.: Input: A[3] = { { 10, "09-10-2003", "First" }, { 20, "19-10-2004", "Second" }, { 30, "03-03-2005", "Third" } };
date = "19-10-2004"
Output: 1 (as there is only one transaction { 30, "03-03-2005", "Third" })

INPUTS: One bank statement (array of transactions) and date.

OUTPUT: Return the number of transactions in that statement after a given date.

ERROR CASES: Return NULL for invalid inputs.

NOTES:
*/

struct transaction {
	int amount;
	char date[11];
	char description[20];
};

int countGreaterNumbers(struct transaction *Arr, int len, char *date) 
{
	int date_date = date[0] - '0', date_month = date[3] - '0', date_year = date[6] - '0';
	date_date = date_date * 10 + date[1] - '0';
	date_month = date_month * 10 + date[4] - '0';
	date_year = date_year * 1000 + (date[7] - '0') * 100 + (date[8] - '0') * 10 + date[9] - '0';
	int result = 0,temp_month,temp_year,temp_date;
	char *dot;
	for (int i = 0; i < len; i++)
	{
		dot=Arr[i].date;
		temp_date = ((dot[0] - '0') * 10) + (dot[1] - '0');
		temp_month = ((dot[3] - '0') * 10) + (dot[4] - '0');
		temp_year = (dot[6]-'0') * 1000 + (dot[7] - '0') * 100 + (dot[8] - '0') * 10 + dot[9] - '0';
		if (temp_year > date_year)
		{
			result += 1;
		}
		else if (temp_year == date_year)
		{
			if (temp_month>date_month)
			{
				result += 1;
			}
			else if (temp_month == date_month)
			{
				if (temp_date > date_date)
				{
					result += 1;
				}
			}
		}

	}
	return result;
}
