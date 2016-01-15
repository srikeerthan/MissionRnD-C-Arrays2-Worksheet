/*
OVERVIEW: You are given 2 bank statements that are ordered by date - Write a function that produces a single merged statement ordered by dates.
E.g.: Input: A[3] = { { 10, "09-10-2003", "First" }, { 20, "19-10-2004", "Second" }, { 30, "03-03-2005", "Third" } };
B[2] = { { 10, "09-10-2003", "First" }, { 220, "18-01-2010", "Sixth" } };
Output: { { 10, "09-10-2003", "First" }, { 10, "09-10-2003", "First" }, { 20, "19-10-2004", "Second" },  30, "03-03-2005", "Third" }, { 220, "18-01-2010", "Sixth" } }

INPUTS: Two bank statements (array of transactions).

OUTPUT: Combined statement ordered by transaction date.

ERROR CASES: Return NULL for invalid inputs.

NOTES:
*/

#include <iostream>

struct transaction {
	int amount;
	char date[11];
	char description[20];
};

int comparision(char *Adate, char *Bdate)
{
	if (Adate[6]>Bdate[6])
	{
		return 1;
	}
	else if (Adate[6] == Bdate[6])
	{
		if (Adate[7] > Adate[7])
		{
			return 1;
		}
		else if (Adate[7] == Bdate[7])
		{
			if (Adate[8] > Adate[8])
			{
				return 1;
			}
			else if (Adate[8] == Bdate[8])
			{
				if (Adate[9] > Bdate[9])
				{
					return 1;
				}
				else if (Adate[9] == Bdate[9])
				{
					if (Adate[3] > Bdate[3])
					{
						return 1;
					}
					else if (Adate[3] == Bdate[3])
					{
						if (Adate[4] > Bdate[4])
						{
							return 1;
						}
						else if (Adate[4] == Bdate[4])
						{
							if (Adate[0]> Bdate[0])
							{
								return 1;
							}
							else if (Adate[0] == Bdate[0])
							{
								if (Adate[1] > Bdate[1])
								{
									return 1;
								}
								else if (Adate[1] == Bdate[1])
								{
									return 0;
								}
								else
								{
									return 2;
								}
							}
							else
							{
								return 2;
							}
						}
						else
						{
							return 2;
						}
					}
					else
					{
						return 2;
					}
				}
				else
				{
					return 2;
				}
			}
			else
			{
				return 2;
			}
		}
		else
		{
			return 2;
		}
	}
	else
	{
		return 2;
	}
}

struct transaction * mergeSortedArrays(struct transaction *A, int ALen, struct transaction *B, int BLen) {
	if (A==NULL || B==NULL)
		return NULL;
	else
	{
		int Astatements = 0, Bstatements = 0, result = -1, Cstatements = 0;
		struct transaction C[30];
		while (Astatements < ALen && Bstatements < BLen)
		{
			result = comparision(A[Astatements].date, B[Bstatements].date);
			if (result == 0)
			{
				C[Cstatements] = A[Astatements];
				Cstatements++;
				Astatements++;
				C[Cstatements] = B[Bstatements];
				Bstatements++;
				Cstatements++;
				
			}
			else if (result == 1)
			{
				C[Cstatements] = B[Bstatements];
				Bstatements++;
				Cstatements++;
			}
			else
			{
				C[Cstatements] = A[Astatements];
				Astatements++;
				Cstatements++;
			}
		}
		if (Astatements == ALen && Bstatements < BLen)
		{
			while (Bstatements < BLen)
			{
				C[Cstatements] = B[Bstatements];
				Bstatements++;
				Cstatements++;
			}
		}
		else if (Astatements < ALen && Bstatements == BLen)
		{
			while (Astatements < ALen)
			{
				C[Cstatements] = A[Astatements];
				Astatements++;
				Cstatements++;
			}
		}
		return C;
	}
}