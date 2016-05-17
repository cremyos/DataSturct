/************************************************
 * Name : linkqueue.cpp
 * Author : Lniper
 * Date : 2016-05-14
 * Aim : Link queue basic operation.
 ************************************************
 */
#include "linkqueue.h"

/**
 * Initialization the  struct 
 */
LinkQueue::LinkQueue()
{
	lq = new LinkQue;
	lq->front = new QNode;
	lq->front->data = 0;
	lq->front->next = NULL;
	lq->rear = new QNode;
	lq->rear->data = 0;
	lq->rear->next = NULL;
}

/**
 * Release the resource
 */
LinkQueue::~LinkQueue()
{
	delete lq->front;
	delete lq->rear;
	delete lq;
}

/**
 * Insert the element into the queue
 */
int LinkQueue::EnQueue(ElemType e)
{
	QueuePtr s = (QueuePtr)malloc(sizeof(QNode));
	if(!s)
		return -1;
	
	s->data = e;
	s->next = NULL;
	lq->rear->next = s;
		
	lq->rear = s;
	free(s);
	return 0;	
}

/**
 * Delete the element fromt the queue
 */
int LinkQueue::DeQueue(ElemType *e)
{
	QueuePtr p;
	
	if(lq->front == lq->rear)
		return -1;
	
	p = lq->front->next;
	*e = p->data;
	lq->front->next = p->next;

	if(lq->rear == p)	
		lq->rear = lq->front;
	
	free(p);
}

/**
 * Visit the queue
 */	
void LinkQueue::visitQueue()
{
	QueuePtr p;
	
	p = (QueuePtr)malloc(sizeof(QNode));
	p = lq->front->next;
	while(p) {
		cout<< p->data<<endl;
		p = p->next;
	}

	free(p);
}

int main()
{
	LinkQueue link;
	ElemType *e;
	int i = 0;

	for(; i < 10; i++) {
		link.EnQueue(i);	
	}

	link.visitQueue();
	
	link.DeQueue(e);

	link.visitQueue();
	
	return 0;
}
