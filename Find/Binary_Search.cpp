/*
 ************************************************
 * Name : Binary_Search.c
 * Date : 2016-07-03
 * Author : Lniper
 * Aim : Binary Search.
 ************************************************
 */
#include "Search.h"

/**
 * Binary Search 
 */
int CSearch::Binary_Search(int n, int key)
{
	int low, high, mid;

	low = 1;
	high = n;
	while(low <= high) {
		mid = (low+high)/2;
		if (key < array[mid])
			high = mid - 1;
		else if (key > array[mid])
			low = mid + 1;
		else 
			return mid;
	}
	
	return 0;
}

int main(void)
{
	CSearch find1;
	
	cout<<"Binary Search: ";
	if(find1.Binary_Search(MAXSIZE, 10))
		printf("position = %d\n", find1.Binary_Search(MAXSIZE, 10));
	else 
		printf("Can't find the element");
		
	return 0;
}