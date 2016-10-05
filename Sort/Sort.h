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
}

#endif
