#include "graph.h"

C_Graph::C_Graph()
{
	Edge = new EdgeNode;
	vertex = new VertexNode;
	graphadj = new GraphAdjList;
}

C_Graph::~C_Graph()
{
	delete Edge;
	delete vertex;
	delete graphadj;
}

void C_Graph::CreateALGraph(GraphAdjList *G)
{
	
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

int main()
{
	C_Graph g;

	g.DFSTravel_Martix(graph);
	cout<<endl;
	return 0;
}
