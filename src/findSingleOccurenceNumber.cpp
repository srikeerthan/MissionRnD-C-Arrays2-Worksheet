/*
OVERVIEW: Given an array where every element occurs three times, except one element which occurs only
once. Find the element that occurs once.
E.g.: Input: arr = 12, 1, 12, 3, 12, 1, 1, 2, 3, 3
ouput: 2

INPUTS: Integer array and length of the array.

OUTPUT: Element that occurs only once.

ERROR CASES: Return -1 for invalid inputs.

NOTES:
*/

#include <iostream>

void Bubble_sort(int list[], int len)
{
	int iter, element, temp,count=0;
	for (iter = 0; iter < (len - 1); iter++)
	{
		count = 0;
		for (element = 0; element < (len - iter - 1); element++)
		{
			if (list[element] > list[element + 1])
			{
				count = 1;
				temp = list[element];
				list[element] = list[element + 1];
				list[element + 1] = temp;
			}
		}
		if (count == 0)
			break;
	}
}
int findSingleOccurenceNumber(int *A, int len) {
	if (A==NULL)
		return -1;
	else
	{
		int value,number=0,count=0;
		Bubble_sort(A, len);
		for (value = 0; value < len; value++)
		{
			if (count == 0)
			{
				number = A[value];
				count = 1;
				continue;
			}
			if (number != A[value] && count == 3)
			{
				count = 1;
				number = A[value];
			}
			else if (number != A[value] && count < 3)
			{
				return number;
			}
			else
				count++;
		}
		return A[value - 1];
	}
}