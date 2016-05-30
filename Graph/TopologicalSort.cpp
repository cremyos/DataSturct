/************************************************
 * Name : TopologicalSort.c
 * Date : 2016-05-30
 * Author : Lniper
 * Aim : TopologicalSort
 ************************************************
 */
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

using namespace std;
//#include "Queue.cpp"
//#include "Queue.h"

#define ERROR -1
#define OK 0
#define MAXVEX 14
#define MAXEDGE 20

typedef int Status;

int graph[14][14] = {
0, 0, 0, 0,  1, 1, 0, 0,  0, 0, 0, 1,  0, 0,
0, 0, 1, 0,  1, 0, 0, 0,  1, 0, 0, 0,  0, 0,
0, 0, 0, 0,  0, 1, 1, 0,  0, 1, 0, 0,  0, 0,
0, 0, 1, 0,  0, 0, 0, 0,  0, 0, 0, 0,  0, 1,

0, 0, 0, 0,  0, 0, 0, 1,  0, 0, 0, 0,  0, 0,
0, 0, 0, 0,  0, 0, 0, 1,  0, 0, 0, 0,  0, 0,
0, 0, 0, 0,  0, 0, 0, 0,  1, 0, 0, 0,  1, 0,
0, 0, 0, 0,  0, 1, 0, 0,  0, 0, 0, 0,  0, 0,

0, 0, 0, 0,  0, 0, 0, 0,  0, 0, 0, 0,  0, 0,
0, 0, 0, 0,  0, 0, 0, 0,  0, 0, 1, 1,  0, 0,
0, 0, 0, 0,  0, 0, 0, 0,  0, 0, 0, 0,  0, 1,
0, 0, 0, 0,  0, 0, 0, 0,  0, 0, 0, 0,  0, 0,

0, 0, 0, 0,  0, 0, 0, 0,  0, 1, 0, 0,  0, 0,
0, 0, 0, 0,  0, 0, 0, 0,  0, 0, 0, 0,  0, 0,
};


typedef struct EdgeNode
{
	int adjvex;
	int weight;
	struct EdgeNode *next;
}EdgeNode;

typedef struct VertexNode
{
	int in;
	int data;
	EdgeNode *firstedge;
}VertexNode, AdjList[MAXVEX];

typedef struct
{
	AdjList adjList;
	int numVertexes, numEdges;
}graphAdjList, *GraphAdjList;

Status TopologicalSort(GraphAdjList GL)
{
	EdgeNode *e;
	int i, k, gettop;
	int top = 0;
	int count = 0;
	int *stack;
	stack = (int *)malloc(GL->numVertexes * sizeof(int));
	
	for(i = 0; i < GL->numVertexes; i++)
		if (GL->adjList[i].in == 0)
			stack[++top] = i;
	
	while(top != 0) {
		gettop = stack[top--];
		printf("%d -> ", GL->adjList[gettop].data);
		count ++;
		for(e = GL->adjList[gettop].firstedge; e; e = e->next) {
			k = e->adjvex;
			if(!(--GL->adjList[k].in))
				stack[++top] = k;
		}
	}
	if(count < GL->numVertexes)
		return ERROR;
	else 
		return OK;
}

void CreateALGraph(GraphAdjList G)
{
	int i, j, k;
	EdgeNode *e;
	for(i = 0; i < MAXVEX; i++) {
		G->adjList[i].data = 'A'+i;
		G->adjList[i].firstedge = NULL;
	}

	for(i = 0; i < MAXVEX; i++) {
		for(j = 0; j < MAXVEX; j++) {
			if(graph[i][j] == 1) {
                e = new EdgeNode;
				e->adjvex = j;
				e->next = G->adjList[i].firstedge;
				G->adjList[i].firstedge = e;

                e = new EdgeNode;
				e->adjvex = i;
				e->next = G->adjList[j].firstedge;
				G->adjList[j].firstedge = e;

			}
		}
	}
	delete e;
}

int main()
{
	GraphAdjList GL;

	CreateALGraph(GL);
	
	TopologicalSort(GL);
}
