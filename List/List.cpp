/**
 * Name : List.cpp
 * Date : 2016-04-16
 * Author: Lniper
 * Aim : Make a List using C plus plus.
 */

#include <iostream>
#include "List.h"

using namespace std;

/*
 * Initalize the list
 */
List::List()
{
	list = (SqList *)malloc(sizeof(SqList));
	memset(list->data, 0, sizeof(list->data));
	list->iLength = 0;
}

/*
 * Check the list null or not
 * True instead of the empty
 * False instead of  not empty
 */
int List::ListEmpty(SqList *list)
{
	if(list->iLength == 0)
		return 1;
	else
		return 0;
}

/*
 * Clear the list and return true
 */
int List::ClearList(SqList *list)
{
	memset(list->data, 0, sizeof(list->data));
	list->iLength = 0;
}

/*
 * Get the No.i
 */
ElemType* List::GetElem(SqList* list, int i, ElemType *e)
{
	/*
	 * Judge empty
	 */
	if (ListEmpty(list))
	{
		printf("List is Empty");
		return 0;
	}

	*e = list->data[i];

	return e;
}

/*
 * Find the element in list
 */
int	List::LocateElem(SqList *list, ElemType e)
{
	int j = 0;

	if (ListEmpty(list))
	{
		printf("List is Empty");
		return 0;
	}

	for(; j < list->iLength; j++)
	{
		if(list->data[j] == e)
		{
			printf("Get the element in seq is %d\n", j);
			goto there;
		}
	}

	if((j == list->iLength) && (list->data[j] != e))
	{
		printf("Can not find the element");
		return -1;
	}

	there: return j;
}

/*
 * Insert a element in list
 */
int List::ListInsert(SqList *list, int i, ElemType *e)
{
	int j = 0;

	if(list->iLength == MAXSIZE+1)
	{
		printf("List is full can not insert");
		return -1;
	}

	list->iLength += 1;
	for(j = i; j < list->iLength; j++)
	{
		list->data[j+1] = list->data[j];
	}
	list->data[i] = *e;

	return 1;
}

/*
 * Delete a element in list
 */
int	List::ListDelete(SqList *list, int i, ElemType *e)
{
	int j = 0;

	if (ListEmpty(list))
	{
		printf("List is Empty");
		return -1;
	}

	*e = list->data[i];

	for(j = i; j < list->iLength; j++)
	{
		list->data[j] = list->data[j+1];
	}

	return *e;
}

/*
 * Length of list
 */
int	List::ListLength(SqList *list)
{
	return list->iLength;
}

int main()
{
    return 0;
}
