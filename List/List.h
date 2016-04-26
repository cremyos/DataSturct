#ifndef LIST_H_INCLUDED
#define LIST_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXSIZE 50		//Max store size

typedef int ElemType;	//ElemType in stead of any type

typedef struct ST_SqList
{
	int			iLength;		//List length
	ElemType	data[MAXSIZE];	//Data array
}SqList;

class List
{
private:
	SqList*		list;				//SqList type

public:
	List();
	~List();
	int	ListEmpty(SqList* list);							//Judge the list null or not
	int	ClearList(SqList* list);							//Clear the list
	ElemType*	GetElem(SqList* list, int i, ElemType *e);	//Get the No.i elem in list and return to e
	int	LocateElem(SqList *list, ElemType e);				//Find the element equal e
	int ListInsert(SqList *list, int i, ElemType *e);		//Insert the element e in No.i.
	int	ListDelete(SqList *list, int i, ElemType *e);		//Delete the element e in No.i.
	int	ListLength(SqList *list);							//return the length of the list.
};




#endif // LIST_H_INCLUDED
