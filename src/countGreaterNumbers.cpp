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

int countGreaterNumbers(struct transaction *Arr, int len, char *date) {
	int count=0,statements=0,equal=0;
	while (statements < len)
	{
		if (Arr[statements].date[6]>date[6])
		{
			count = 1;
			statements++;
			break;
		}
		else if (Arr[statements].date[6] == date[6])
		{
			if (Arr[statements].date[7] > date[7])
			{
				count++;
				statements++;
				break;
			}
			else if (Arr[statements].date[7] == date[7])
			{
				if(Arr[statements].date[8] > date[8])
				{
					count++;
					statements++;
					break;
				}
				else if (Arr[statements].date[8] == date[8])
				{
					if (Arr[statements].date[9] > date[9])
					{
						count++;
						statements++;
						break;
					}
					else if (Arr[statements].date[9] == date[9])
					{
						if (Arr[statements].date[3] > date[3])
						{
							count++;
							statements++;
							break;
						}
						else if (Arr[statements].date[3] == date[3])
						{
							if (Arr[statements].date[4] > date[4])
							{
								count++;
								statements++;
								break;
							}
							else if (Arr[statements].date[4] == date[4])
							{
								if (Arr[statements].date[0] > date[0])
								{
									count++;
									statements++;
									break;
								}
								else if (Arr[statements].date[0] == date[0])
								{
									if (Arr[statements].date[1] > date[1])
									{
										count++;
										statements++;
										break;
									}
									else if (Arr[statements].date[1] == date[1])
									{
										equal = 1;
										statements++;
										continue;
									}
									else
									{
										statements++;
										continue;
									}
								}
								else
								{
									statements++;
									continue;
								}
							}
							else
							{
								statements++;
								continue;
							}
						}
						else
						{
							statements++;
							continue;
						}
					}
					else
					{
						statements++;
						continue;
					}
				}
				else
				{
					statements++;
					continue;
				}
			}
			else
			{
				statements++;
				continue;
			}
		}
		else
		{
			statements++;
			continue;
		}
	}
	if (count == 1)
	{
		while (statements < len)
		{
			count++;
			statements++;
		}
	}
	return count;
}
