/*
 ************************************************
 * Name : Linklist.cpp
 * Author : Lniper
 * Date : 2016-04-27
 * Aim : Come true the linklist's class and 
 *		 function.
 ************************************************
 */

#include "Linklist.h"

CLink::CLink()
{
	this->link = (Linklist *)malloc(sizeof(Linklist));
}

/**
 * Create a list with node
 */
void CLink::CreateList(int n)
{
	Linklist *temp1, *temp2;
	int i = 0;
	temp1 = (Linklist *)malloc(sizeof(Linklist));
	temp1 = this->link;	

	/*
	 * insert the node from head to tail.
	 */
	for(; i < n; i++ )
	{
		temp2 = (Linklist *)malloc(sizeof(Linklist));
		temp2->data = i;
		temp1->next = temp2;
		temp1 = temp2;
	}
	temp1->next = NULL;
}

/**
 * visit the list
 */
void CLink::VisitList()
{
	Linklist *temp;
	
	temp = (Linklist *)malloc(sizeof(Linklist));
	temp = link->next;

	/*
	 * visit every node in list
	 */	
	while(temp)
	{
		cout<<temp->data<<" ";
		temp = temp->next;
	}
}

/**
 * insert the element into the list
 */
void CLink::InsertList(int i, ElemType e)
{
	Linklist *temp, *insertlink;
	int j = 0;	

	temp = link->next;

	/*
	 * make the node point to the node which I want to insert
	 */
	while(i--)
		temp = temp->next;

	/*
	 * Insert the node 
	 */
	insertlink = (Linklist *)malloc(sizeof(Linklist));
	insertlink->data = e;
	insertlink->next = temp->next;
	temp->next = insertlink;
}

/**
 * Delete the element in list
 */
void CLink::DeleteList(int i)
{
	Linklist *temp, *deletelink;

	temp = link->next;
	
	/*
	 * find the node in front of the node which I want to delete
	 */
	while(i--)
	{
		temp = temp->next;
	}
	
	/*
	 * Delete the element and release the point
	 */
	deletelink = temp->next;
	temp->next = deletelink->next;
	
	free(deletelink);
}

CLink::~CLink()
{
	free(link);
}

int main(void)
{
	CLink l1;
		
	l1.CreateList(10);			/// example
	l1.VisitList();
	cout<<endl;

	l1.InsertList(3, 20);		/// example
	l1.VisitList();
	cout<<endl;

	l1.DeleteList(3);			/// example
	l1.VisitList();

	return 0;
}
