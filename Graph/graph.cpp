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

int main()
{
	C_Graph g;
	GraphAdjList *G;
	G = new GraphAdjList;

	g.DFSTravel_Martix(graph);
	cout<<endl;
	g.CreateALGraph(G);
	g.DFSTravel_AdjList(G);
	cout<<endl;
	delete G;
	return 0;
}

