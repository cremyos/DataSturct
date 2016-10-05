/**
 * Name : SelectSort.cpp
 * Author : Lniper
 * Date : 2016-10-05
 * Aim : Select sort
 */

#include "Sort.h"

/**
 * simple select sort
 */
Status CSort::SSelectSort(int *array)
{
 	int i= 0, j = 0, min = 0;

	for(i = 0; i < MAXSIZE; i++) {
		min = i;
		for(j = i+1; j < MAXSIZE; j++) {
			if(array[min] > array[j])
				min = j;
		}
		if(i != min)
			Swap(array+i, array+min);
	}
	return TRUE;
}

int main()
{
	CSort s1;

	cout<<"SSelectSort: ";
	s1.SSelectSort(s1.array);
	s1.Print(s1.array);
	
	return 0;
}
