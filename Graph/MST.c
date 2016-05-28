#include <stdio.h>
#include <stdlib.h>

///INFINITY define the no way between two node 
#define INFINITY 65535
#define MAXVEX 9
#define MAXEDGE 15
#define MAXVEX 9
 
/*
 * graph
 */
int graph[9][9] = {
0, 10, INFINITY, INFINITY, INFINITY, 11, INFINITY, INFINITY, INFINITY,
10, 0, 18, INFINITY, INFINITY, INFINITY, 16, INFINITY, 12,
INFINITY, INFINITY, 0, 22, INFINITY, INFINITY, INFINITY, INFINITY, 8,
INFINITY, INFINITY, 22, 0, 20, INFINITY, 24, 16, 21,
INFINITY, INFINITY, INFINITY, 20, 0, 26, INFINITY, 7, INFINITY,
11, INFINITY, INFINITY, INFINITY, 26, 0, 17, INFINITY, INFINITY,
INFINITY, 16, INFINITY, 24, INFINITY, 17, 0, 19, INFINITY,
INFINITY, INFINITY, INFINITY, 16, 7, INFINITY, 19, 0, INFINITY,
INFINITY, 12, 8, 21, INFINITY, INFINITY, INFINITY, INFINITY, 0
};

/**
 * Edge of the graph
 */
typedef struct ST_Edge
{
	int begin;
	int end;
	int weight;
}Edge;

/**
 * Define the find function which can find end node
 */
int Find(int parent[], int f);

/**
 * MST of Prim 
 */
void MiniSpanTree_Prim(int graph[][9])
{
	int min, i, j, k;
	int adjvex[MAXVEX];
	int lowcost[MAXVEX];
	lowcost[0] = 0;
	
	adjvex[0] = 0;
	for(i = 1; i < 9; i++) {
		lowcost[i] = graph[0][i];
		adjvex[i] = 0;	
	}
	
	for(i = 1; i < 9; i++) {
		min = INFINITY;
	
		j = 1;
		k = 0;
		while(j < 9) {
			if(lowcost[j] != 0 && lowcost[j] < min) {
				min = lowcost[j];
				k = j;			
			}		
			j++;
		}
		printf("(%d, %d)\n", adjvex[k], k);
		lowcost[k] = 0;
		for(j = 1; j < 9; j++) {
			if(lowcost[j] != 0 && graph[k][j] < lowcost[j]) {
				lowcost[j] = graph[k][j];
				adjvex[j] = k;			
			}		
		}
	}	
}

/**
 * Create the edge of graph
 * Save the edge into the struct
 */
void Create_Edge(Edge *edges)
{
	int i, j, k = 0;
	for(i = 0; i < 9; i++)
		for(j = i; j < 9; j++) {
			if(graph[i][j] != INFINITY && graph[i][j] != 0) {
				edges[k].begin = i;
				edges[k].end = j;
				edges[k].weight = graph[i][j];
				k++;			
			}		
		}
	for(i = 0; i < MAXEDGE; i++)
		printf("begin = %d || end = %d || weight = %d\n", edges[i].begin, edges[i].end, edges[i].weight);
}

/**
 * MST function of Kruskal
 */
void MiniSpanTree_Kruskal(int graph[][9])
{
	int i, n, m;
	Edge edges[MAXEDGE] = {0};
	int parent[MAXVEX] = {0};
	
	Create_Edge(edges);

	for(i = 0; i < MAXVEX; i++)
		parent[i] = 0;
		
	for(i = 0; i < MAXEDGE; i++) {
		n = Find(parent, edges[i].begin);
		m = Find(parent, edges[i].end);
		if(n != m) {
			parent[n] = m;
			printf("(%d, %d) %d\n", edges[i].begin, edges[i].end, edges[i].weight);		
		}
	}
}

/**
 * find the end node
 */
int Find(int parent[], int f)
{
	while(parent[f] > 0)
		f = parent[f];
	return f;
}

int main()
{
	printf("Prim: \n");
	MiniSpanTree_Prim(graph);
	printf("\n");
	printf("Kruskal: \n");
	MiniSpanTree_Kruskal(graph);
	printf("\n");
	return 0;
}

