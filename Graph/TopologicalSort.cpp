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

#define ERROR -1
#define OK 0
#define MAXVEX 14
#define MAXEDGE 20

typedef int Status;

int visited_AdjList[14] = {0};

/**
 * Graph Martix
 */
int graph[14][14] = {
0, 0, 0, 0,  1, 1, 0, 0,  0, 0, 0, 1,  0, 0,
0, 0, 1, 0,  1, 0, 0, 0,  1, 0, 0, 0,  0, 0,
0, 0, 0, 0,  0, 1, 1, 0,  0, 1, 0, 0,  0, 0,
0, 0, 1, 0,  0, 0, 0, 0,  0, 0, 0, 0,  0, 1,

0, 0, 0, 0,  0, 0, 0, 1,  0, 0, 0, 0,  0, 0,
0, 0, 0, 0,  0, 0, 0, 0,  1, 0, 0, 0,  1, 0,
0, 0, 0, 0,  0, 1, 0, 0,  0, 0, 0, 0,  0, 0,
0, 0, 0, 0,  0, 0, 0, 0,  0, 0, 0, 0,  0, 0,

0, 0, 0, 0,  0, 0, 0, 1,  0, 0, 0, 0,  0, 0,
0, 0, 0, 0,  0, 0, 0, 0,  0, 0, 1, 1,  0, 0,
0, 0, 0, 0,  0, 0, 0, 0,  0, 0, 0, 0,  0, 1,
0, 0, 0, 0,  0, 0, 0, 0,  0, 0, 0, 0,  0, 0,

0, 0, 0, 0,  0, 0, 0, 0,  0, 1, 0, 0,  0, 0,
0, 0, 0, 0,  0, 0, 0, 0,  0, 0, 0, 0,  0, 0,
};


typedef struct EdgeNode
{
	int adjvex;				/// Adj vex
	struct EdgeNode *next;	/// next point  
}EdgeNode;

typedef struct VertexNode
{
	int in;					/// In-degree
	int data;				/// data
	EdgeNode *firstedge;	/// first edge node
}VertexNode, AdjList[MAXVEX];

typedef struct
{
	AdjList adjList;			/// adjlist
	int numVertexes, numEdges;	///number of vertex and edge
}graphAdjList, *GraphAdjList;

/**
 * TopologicalSort 
 */
Status TopologicalSort(GraphAdjList GL)
{
	EdgeNode *e;
	int i, k, gettop = 0;
	int top = 0;
	int count = 0;
	int *stack;
	stack = (int *)malloc(MAXVEX * sizeof(int));
	
	for(i = 0; i < MAXVEX; i++)
		if (GL->adjList[i].in == 0) 
			stack[++top] = i;
	
	while(top != 0) {
		gettop = stack[top--];
		printf("%d -> ", GL->adjList[gettop].data);
		count ++;
		for(e = GL->adjList[gettop].firstedge; e; e = e->next) {
			k = e->adjvex;
			if(!(--GL->adjList[k].in)) {
				stack[++top] = k;
			}
				
		}
	}
	if(count < MAXVEX)
		return ERROR;
	else 
		return OK;
}

/**
 * Create the Graph of AdjList
 */
void CreateALGraph(GraphAdjList G)
{
	int i, j, k;
	EdgeNode *e;

	for(i = 0; i < MAXVEX; i++) {
		G->adjList[i].data = i;		
		G->adjList[i].firstedge = NULL;
	}
	
	G->adjList[0].in = 0;
	G->adjList[1].in = 0;
	G->adjList[2].in = 2;
	G->adjList[3].in = 0;
	G->adjList[4].in = 2;
	G->adjList[5].in = 3;
	G->adjList[6].in = 1;
	G->adjList[7].in = 2;
	G->adjList[8].in = 2;
	G->adjList[9].in = 1;
	G->adjList[10].in = 1;
	G->adjList[11].in = 2;
	G->adjList[12].in = 1;
	G->adjList[13].in = 2;
	
	for(i = 0; i < MAXVEX; i++) {
		for(j = 0; j < MAXVEX; j++) {
			if(graph[i][j] == 1) {
                e = new EdgeNode;
				e->adjvex = j;
				e->next = G->adjList[i].firstedge;
				G->adjList[i].firstedge = e;
			}
		}
	}
	delete e;
}

int main()
{
	GraphAdjList GL;
	int i = 0;
	
	GL = (GraphAdjList )malloc(sizeof(graphAdjList));
	CreateALGraph(GL);
	cout<<"TopologicalSort Result: "<<endl;
	TopologicalSort(GL);
	cout<<endl;
	
	free(GL);
	return 0;
}
