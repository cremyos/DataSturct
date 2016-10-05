/**
 * Name Bubble.cpp
 * Author : Lniper
 * Date : 2016-10-05
 * Aim : Bubble Sort
 */
#include "Sort.h"

/**
 * Bubble Sort
 */
Status CSort::Bubble(int *array)
{
	int i, j;

	for(i = 0; i < MAXSIZE; i++) {
		for(j = 0; j < MAXSIZE; j++) {
			if(array[j] > array[j+1]) {
				Swap(array+j, array+j+1);
			}
		}
	}
	   
}

/**
 * New Bubble
 */
Status CSort::BubbleV2(int *array)
{
	int i = 0, j = 0;
	Status flag = FALSE;

	for(; i < MAXSIZE && flag; i++) {
		flag = FALSE;

		for(; j < MAXSIZE; j ++) {
			if(array[j] > array[j+1]) {
				Swap(array+j, array+j+1);
				flag = TRUE;
			}				
		}
	}
}

int main()
{
	CSort s1;

	s1.Bubble(s1.array);
	s1.Print(s1.array);

	CSort s2;

	s2.Bubble(s2.array);
	s2.Print(s2.array);
	
	return 0;
}
