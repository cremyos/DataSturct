/************************************************
 * Name : stack.cpp
 * Author : Lniper
 * Date : 2016-05-14
 * Aim : stack basic operation.
 ************************************************
 */
#include "stack.h"

/**
 * Initlization the struct of stack
 */
Stack::Stack()
{
	st = new stack;
	memset(st->stack_data, -1, sizeof(st->stack_data));
	st->count = 0;
}

/**
 * free the resource of the element
 */
Stack::~Stack()
{
	delete st;
}

/**
 * Push the element into the stack
 */
void Stack::push(ElemType e)
{
	st->count++;
	st->stack_data[st->count] = e;
}

/**
 * Pop the element from the stack
 */
void Stack::pop(ElemType e)
{
	e = st->stack_data[st->count];
	st->count--;

}

/**
 * Get the top element of the stack
 */
ElemType Stack::top()
{
	cout<<st->stack_data[st->count]<<endl;
}

int main(void)
{
	Stack S;
	int i = 0;
	ElemType e;

	for(; i < 10; i++) {
		S.push(i);
	}

	S.top();		
	S.pop(e);
	
	return 0;
}
