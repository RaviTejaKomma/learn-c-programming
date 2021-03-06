/*
OVERVIEW: 	Given date of births of two persons as inputs, return 1 if person one is elder,
2 if person two is elder, 0 if both are of same age.
Example: isOlder("24-07-2000", "25-07-2000") should return 1 as person one
is elder than person two.

INPUTS: 	DOBs of two persons as parameters in the format "DD-MM-YYYY".

OUTPUT: 	1 if person one is elder, 2 if person two is elder, 0 if both are of same age.

ERROR CASES: Return -1 if any DOB is invalid.

NOTES: 		Don't use any built-in C functions for comparisions. You are free to write any helper functions.
*/

int isOlder(char *dob1, char *dob2) 
{
	int i=0;
	while (dob1[i] != '\0' || dob2[i] != '\0')
	{
		if (dob1[i] >= 48 && dob1[i] <= 57 && dob2[i] >= 48 && dob2[i] <= 57)
		{
			i++;
			continue;
		}
		else if (i == 2 && dob1[2] == '-' && dob2[2] == '-')
		{
			i++;
			continue;
		}
		else if (i==5 && dob1[5] == '-' && dob2[5] == '-')
		{
			i++;
			continue;
		}
		else
		{
			return -1;
		}

	}
	if (i!=10)
	{
		return -1;
	}
	int dob1_date = dob1[0]-'0', dob2_date = dob2[0]-'0', dob1_month = dob1[3]-'0', dob2_month = dob2[3]-'0',//
		dob1_year = dob1[6]-'0', dob2_year = dob2[6]-'0';
	dob1_date = dob1_date * 10 + dob1[1]-'0';
	dob2_date = dob2_date * 10 + dob2[1]-'0';
	dob1_month = dob1_month * 10 + dob1[4]-'0';
	dob2_month = dob2_month * 10 + dob2[4]-'0';
	dob1_year = dob1_year * 1000 + (dob1[7]-'0')*100 + (dob1[8]-'0')*10 + dob1[9]-'0';
	dob2_year = dob2_year * 1000 + (dob2[7] - '0')*100 + (dob2[8] - '0')*10 + dob2[9] - '0';
	if (dob1_month <= 12 && dob2_month <= 12)
	{
		if ((dob1_year % 400 == 0) || (dob1_year % 4 == 0 && dob1_year % 100 != 0))
		{
			if (dob1_date > 29)
			{
				return -1;
			}
		}
		else
		{
			if (dob1_date > 28)
			{
				return -1;
			}
		}
		if ((dob2_year % 400 == 0) || (dob2_year % 4 == 0 && dob2_year % 100 != 0))
		{
			if (dob2_date > 29)
			{
				return -1;
			}
		}
		else
		{
			if (dob2_date > 28)
			{
				return -1;
			}
		}
		if (dob1_month == 4 || dob1_month == 6 || dob1_month == 9 || dob1_month == 11)
		{
			if (dob1_date > 30)
			{
				return -1;
			}
		}
		else
		{
			if (dob1_date > 31)
			{
				return -1;
			}
		}
		if (dob2_month == 4 || dob2_month == 6 || dob2_month == 9 || dob2_month == 11)
		{
			if (dob2_date > 30)
			{
				return -1;
			}
		}
		else
		{
			if (dob2_date > 31)
			{
				return -1;
			}
		}
	}
	else
	{
		return -1;
	}
	// checking which person is elder
	if (dob1_year > dob2_year)
	{
		return 2;
	}
	else if (dob1_year < dob2_year)
	{
		return 1;

	}
	else if (dob1_year == dob2_year)
	{
		if (dob1_month>dob2_month)
		{
			return 2;
		}
		else if (dob1_month < dob2_month)
		{
			return 1;
		}
		else if (dob1_month == dob2_month)
		{
			if (dob1_date > dob2_date)
			{
				return 2;
			}
			else if (dob1_date < dob2_date)
			{
				return 1;
			}
			else if (dob1_date == dob2_date)
			{
				return 0;
			}
		}
	}
}
