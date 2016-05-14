#ifndef STACK_H
#define STACK_H

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXSIZE 100

using namespace std;

typedef int ElemType;

typedef struct ST_Stack
{
	ElemType stack_data[MAXSIZE];
	int count;
}stack;

class Stack
{
private:
	stack *st;			//stack struct 

public:
	Stack();
	~Stack();
	
	void push(ElemType e);
	void pop(ElemType e);
	ElemType top();	
};

#endif
