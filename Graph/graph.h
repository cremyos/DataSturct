#ifndef GRAPH_H
#define GRAPH_H

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

using namespace std;

#define MAXVEX 10

int visited[9];
int visited_AdjList[9];

int graph[9][9] = {
0, 1, 0, 0, 0, 1, 0, 0, 0,
1, 0, 1, 0, 0, 0, 1, 0, 1,
0, 1, 0, 1, 0, 0, 0, 0, 1,
0, 0, 1, 0, 1, 0, 1, 1, 1,
0, 0, 0, 1, 0, 1, 0, 1, 0,
1, 0, 0, 0, 1, 0, 1, 0, 0,
0, 1, 0, 1, 0, 1, 0, 1, 0,
0, 0, 0, 1, 1, 0, 1, 0, 0,
0, 1, 1, 1, 0, 0, 0, 0, 0
};

typedef char VertexType;
typedef int EdgeType;

typedef struct EdgeNode
{
	int adjvex;
	EdgeType weight;
	struct EdgeNode *next;
}EdgeNode;

typedef struct VertexNode
{
	VertexType data;
	EdgeNode *firstedge;
}VertexNode, AdjList[MAXVEX];

typedef struct
{
	AdjList adjList;
	int numVertexes, numEdges;
}GraphAdjList;


class C_Graph
{
private:
	EdgeNode *Edge;
	VertexNode *vertex;
	GraphAdjList *G;

public:
	C_Graph();
	~C_Graph();

	void CreateALGraph(GraphAdjList *G);
	void DFS_Martix(int graph[][9], int i);
	void DFSTravel_Martix(int graph[][9]);
	void DFS_AdjList(GraphAdjList *G, int i);
	void DFSTravel_AdjList(GraphAdjList *G);
};

#endif
