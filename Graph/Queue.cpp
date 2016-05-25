/************************************************
 * Name : Queue.cpp
 * Author : Lniper
 * Date : 2016-05-14
 * Aim : Queue basic operation.
 ************************************************
 */
#include "Queue.h"

/**
 * Initilaztion the queue struct
 */
Queue::Queue()
{
	q = new queue;
	memset(q->queue_data, -1, sizeof(q->queue_data));
	q->front = 0;	
	q->rear = 0;
}

/**
 * release the queue resource
 */
Queue::~Queue()
{
	delete q;
}

/**
 * Insert the element into the queue
 */
int Queue::EnQueue(ElemType e)
{
	if((q->rear+1) % MAXSIZE == q->front)
		return -1;
	q->queue_data[q->rear] = e;
	q->rear = (q->rear+1)%MAXSIZE;

	return 0;
}

/**
 * Delete the element from the queue
 */
int Queue::DelQueue(ElemType e)
{
	if(q->front == q->rear)
		return -1;
	e = q->queue_data[q->front];
	q->front  = (q->front + 1)%MAXSIZE;
//	cout<<"Delete the element is "<<e<<endl;
	return 0;
}

/**
 * Get the top element of the queue
 */
void Queue::GetQueueTop()
{
	cout<<q->queue_data[q->front]<<endl;
}

BOOL Queue::IsEmpty()
{
	if(q->rear == q->front)
		return 1;
	else 
		return 0;
}

/*int main()
{
	Queue Que;	
	int i = 1;
	ElemType e;

	for(; i <= 10; i++) {
		Que.EnQueue(i);
	}

	Que.GetQueueTop();

	Que.DelQueue(e);
	
	Que.GetQueueTop();
	return 0;
}*/
