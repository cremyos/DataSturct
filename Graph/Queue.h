#ifndef QUEUE_H
#define QUEUE_H

#include <stdio.h>
#include <iostream>
#include <string.h>

#define MAXSIZE 100

using namespace std;

typedef int ElemType;
typedef int BOOL;

typedef struct ST_Queue {

	ElemType queue_data[MAXSIZE];
	int front;
	int rear;
}queue;

class Queue
{
private:
	queue *q;

public:
	Queue();
	~Queue();
	
	int EnQueue(ElemType e);
	int DelQueue(ElemType e);
	BOOL IsEmpty();
	void GetQueueTop();
};

#endif
