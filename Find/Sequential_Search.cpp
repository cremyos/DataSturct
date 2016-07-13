/*
 ************************************************
 * Name : Sequential_Search.c
 * Date : 2016-07-02
 * Author : Lniper
 * Aim : Sequence Search.
 ************************************************
 */
#include "Search.h"

/**
 * Sequence Search
 */
int CSearch::Sequential_Search(int n, int key)
{
	int i;
	int position = 0;
	
	for(i = 1; i < MAXSIZE; i++)
	{
		if(array[i] == key) {
			position = i;
			return position;
		}
	}
	printf("Can not find the element\n");
	return 0;
}

/**
 * Find the element in Sequence using signal.
 */
int CSearch::Sequential_Search_Signal(int n, int key)
{
	int i = n; 
	int position = 0;
		
	array[0] = key;
	i = n;
	while(array[i] != key){
		i--;
	}
	position = i;
	return position;
}

int main()
{
	CSearch find1;
	
	cout<<"Sequence Search : ";
	printf("position = %d\n", find1.Sequential_Search(MAXSIZE, 10));
	
	cout<<"Sequence Search with signal: ";
	if(find1.Sequential_Search_Signal(MAXSIZE, 10))
		printf("position = %d\n", find1.Sequential_Search_Signal(MAXSIZE, 10));
	else 
		printf("Can't find the element");
		
	return 0;
}
