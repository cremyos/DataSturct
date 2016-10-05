/**
 * Name : InsertSort.cpp
 * Author : Lniper
 * Date : 2016-10-06
 * Aim : insert sort.
 */

#include "Sort.h"

Status CSort::InsertSort(int *array)
{
	int i= 0, j = 0, temp = 0;

	for(i = 1; i < MAXSIZE; i++) {
		if(array[i] < array[i - 1]) {
			/**
			 * set a signal
			 */
			temp = array[i];
			/**
			 * everyone move behind
			 */
			for(j = i - 1; array[j] >= temp; j--)
				array[j+1] = array[j];
			array[j+1] = temp;
			
				
		}
	}
	return TRUE;
}

int main()
{
	CSort s1;

	cout<<"InsertSort: ";
	s1.InsertSort(s1.array);
	s1.Print(s1.array);
	
	return 0;
}

