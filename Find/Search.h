#ifndef SEARCH_H_
#define SEARCH_H_

#include <iostream>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

#define MAXSIZE 21

/**
 * CSearch Class
 */
class CSearch{
private:
	int *array;
public:
	CSearch();
	~CSearch();

	int	Sequential_Search(int n, int key);	///Sequence Search and return the position.
	int	Sequential_Search_Signal(int n, int key);	///Sequence Search with signal.
	int Binary_Search(int n, int key);				///Binary Search 
	int Fibonacci_Search(int n, int key);			//Fibonacci Search
};

/**
 * construct function
 */
CSearch::CSearch()
{
	int i = 0;
	
	array = new int[MAXSIZE];
	array[0] = MAXSIZE-1;
	for(i = 1; i < MAXSIZE; i++)
		array[i] = i;
}

/**
 * Destruct function
 */
CSearch::~CSearch()
{
	delete array;
}

#endif
