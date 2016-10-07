#ifndef SORT_H_
#define SORT_H_

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

using namespace std;

#define MAXSIZE 10
#define TRUE 1
#define FALSE -1

typedef int Status;


class CSort
{
 public:
	int *array;
	int *array_temp;

	/**
	 * Common function
	 */
	CSort();
	~CSort();
	Status Swap(int *a, int *b);								///< swap a,b
	void Print(int *array);										///< print the array

	/**
	 * Bubble function
	 */
	Status Bubble(int *array);									///< Bubble Sort
	Status BubbleV2(int *array);								///< New Bubble Sort

	/**
	 * Select Sort
	 */
	Status SSelectSort(int *array);								///< simple select sort

	/**
	 * Insert Sort
	 */
	Status InsertSort(int *array);								///< Insert sort

	/**
	 * Heap Sort
	 */
	Status HeapSortMAX_Down(int *array, int len, int CNode);			///< Adjust Heap sort MAXDown
	Status CreateHeapMAX(int *array, int len);							///< Create the heap sort in max down
	Status HeapMAX(int *array, int len);								///< MAXDown heap sort
	
	Status HeapSortMIN_Down(int *array, int len, int CNode);			///< Adjust Heap sort MinDown
	Status CreateHeapMIN(int *array, int len);							///< Create the heap sort in mindown
	Status HeapMIN(int *array, int len);								///< MinDown heap Sort
	

	
	
};

/**
 * Construct
 */
CSort::CSort()
{
	array = new int[MAXSIZE];
	int i = 0;
	
	for(; i < MAXSIZE; i++) {
		array[i] = MAXSIZE - i;
	}

	array_temp = new int[MAXSIZE];
	array_temp[0] = 3;
	array_temp[1] = 9;
	array_temp[2] = 5;
	array_temp[3] = 4;
	array_temp[4] = 10;
	array_temp[5] = 0;
	array_temp[6] = 12;
	array_temp[7] = 6;
	array_temp[8] = 7;
	array_temp[9] = 8;
}

/**
 * Swap a and b
 */
Status CSort::Swap(int *a, int *b)
{
	int t = 0;
	
	t = *a;
	*a = *b;
	*b = t;
}

/**
 * Print the array
 */
void CSort::Print(int *array)
{
	int i = 0;
	cout<<"array is ";
	for(; i < MAXSIZE; i++) {
		cout<<array[i]<<" ";
	}
	cout<<endl;
}

CSort::~CSort()
{
	delete array;
	delete array_temp;
}

#endif
