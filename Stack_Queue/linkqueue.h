#ifndef LINKQUEUE_H
#define LINKQUEUE_H

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
using namespace std;

typedef	int ElemType;

typedef struct QNode
{
	ElemType		data;
	struct QNode	*next;
}QNode, *QueuePtr;

typedef struct 
{
	QueuePtr front, rear;
}LinkQue;

class LinkQueue
{
private:
	LinkQue *lq;

public:
	LinkQueue();
	~LinkQueue();

	int EnQueue(ElemType e);
	int DeQueue(ElemType *e);
	void visitQueue();
};

#endif
