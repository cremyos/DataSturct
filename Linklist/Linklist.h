#ifndef LINKLIST_H
#define	LINKLIST_H

/*
 ************************************************
 * Name : Linklist.h
 * Author : Lniper
 * Date : 2016-04-27
 * Aim : Linklist class and function.
 ************************************************
 */
#include <iostream>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

typedef int ElemType;

/**
 * Node struct
 */
typedef struct ST_Node
{
	ElemType		data;
	struct ST_Node *next;
}Node, Linklist;

/**
 * Class Linklist, include create, visit, insert and delete
 */
class CLink
{
private:
	Linklist *link;
public:
	CLink();			
	~CLink();
	void CreateList(int n);						//Create a linklist with head
	void VisitList();							//visit the linklist
	void InsertList(int i, ElemType e);			//Insert a element into the linklist
	void DeleteList(int i);						//Delete a node from the linklist
	
};

#endif 
