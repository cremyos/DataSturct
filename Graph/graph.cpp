/************************************************
 * Name : graph.cpp
 * Date : 2016-05-30
 * Author : Lniper
 * Aim : Create the graph adjlist and Martix. 
 *       Travel the graph.
 ************************************************
 */

#include "graph.h"

C_Graph::C_Graph()
{
	Edge = new EdgeNode;
	vertex = new VertexNode;
}

C_Graph::~C_Graph()
{
	delete Edge;
	delete vertex;
}

void C_Graph::CreateALGraph(GraphAdjList *G)
{
	int i, j, k;
	EdgeNode *e;
	for(i = 0; i < 9; i++) {
		G->adjList[i].data = 'A'+i;
		G->adjList[i].firstedge = NULL;
	}

	for(i = 0; i < 9; i++) {
		for(j = 0; j < 9; j++) {
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


void C_Graph::DFS_Martix(int graph[][9], int i)
{
	int j = 0;
	visited[i] = 1;
	printf("%c ", 'A'+i);
	for(; j < 9; j++)
		if(graph[i][j] == 1 && !visited[j])
			DFS_Martix(graph, j);
}

void C_Graph::DFSTravel_Martix(int graph[][9])
{
	int i = 0;

	for(; i < 9; i++)
		visited[i] = 0;

	for(i = 0; i < 9; i++)
		if(!visited[i])
			DFS_Martix(graph, i);
}

void C_Graph::DFS_AdjList(GraphAdjList *G, int i)
{
	EdgeNode *p;
	p = new EdgeNode;
	visited_AdjList[i] = 1;
	printf("%c ", G->adjList[i].data);
	p = G->adjList[i].firstedge;
	while(p) {
		if(!visited_AdjList[p->adjvex])
			DFS_AdjList(G, p->adjvex);
		p = p->next;
	}

	delete p;
}

void C_Graph::DFSTravel_AdjList(GraphAdjList *G)
{
	int i;
	for(i = 0; i < 9; i++)
		visited_AdjList[i] = 0;
	for(i = 0; i < 9; i++)
		if(!visited_AdjList[i])
			DFS_AdjList(G, i);
}

void C_Graph::BFSTravel_Martix(int graph[][9])
{
	int i, j;
	ElemType e = 0;

	for(i = 0; i < 9; i++)
		visited_BFS[i] = 0;
	for(i = 0; i < 9; i++) {
		if(!visited_BFS[i]) {
			visited_BFS[i] = 1;
			printf("%c ", 'A' + i);
			EnQueue(i);
			while(!IsEmpty()) {
				DelQueue(e);
				for(j = 0; j < 9; j++) {
					if(graph[i][j] == 1 && !visited_BFS[j]) {
						visited_BFS[j] = 1;				
						printf("%c ", 'A'+j);
						EnQueue(j);
					}
				}
			}
		}	
	}
}

void C_Graph::BFSTravel_AdjList(GraphAdjList *G)
{
	int i;
	EdgeNode *p;
	
	for(i = 0; i < 9; i++)
		visited_BFSAdjList[i] = 0;
	for(i = 0; i < 9; i++) {
		if(!visited_BFSAdjList[i]) {
			visited_BFSAdjList[i] = 1;
			printf("%c ", G->adjList[i].data);
			EnQueue(i);
			while(!IsEmpty()) {
				DelQueue(i);
				p = G->adjList[i].firstedge;
				while(p) {
					if(!visited_BFSAdjList[p->adjvex]) {
						visited_BFSAdjList[p->adjvex] = 1;
						printf("%c ", G->adjList[p->adjvex].data);
						EnQueue(p->adjvex);
					}
					p = p->next;
				}
			}
		}
			
	}
}

int main()
{
	C_Graph g;
	GraphAdjList *G;
	G = new GraphAdjList;

	cout<<"DFSTravel_Martix: ";
	g.DFSTravel_Martix(graph);
	cout<<endl;
	g.CreateALGraph(G);
	cout<<"DFSTravel_AdjList: ";
	g.DFSTravel_AdjList(G);
	cout<<endl;
	cout<<"BFSTravel_Martix: ";
	g.BFSTravel_Martix(graph);
	cout<<endl;
	cout<<"BFSTravel_AdjList: ";
	g.BFSTravel_AdjList(G);
	cout<<endl;
	delete G;
	return 0;
}

