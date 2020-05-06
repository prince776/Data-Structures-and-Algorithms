#include <bits/stdc++.h>
using namespace std;

#define INF 1e9 + 5

struct Edge
{
	int src, dest, weight;
	Edge()
	{

	}
	Edge(int src, int dest, int weight) :
		src(src), dest(dest), weight(weight)
	{
		// Nothing to do here.		
	}
};

struct Graph
{
	int V, E;
	Edge* edges;
	Graph(int V, int E) : V(V), E(E)
	{
		edges = new Edge[E];
	}
	~Graph()
	{
		delete[] edges;
	}
};

void printArr(int distTo[], int n)
{
	cout << "Vertex distancesfrom source: \n";
	for (int i = 0; i < n; i++)
		cout << i << " " << distTo[i] << "\n";
}

void BellmanFord(Graph* graph, int src)
{
	int V = graph->V;
	int E = graph->E;
	int distTo[V];

	// Initialize all distances to infinity and the src to be 0.
	for (int i = 0; i < V; i++)
		distTo[i] = INF;
	distTo[src] = 0;

	// Relax all edges V - 1 times.
	for (int i = 0; i < V - 1; i++)
	{
		for (int j = 0; j < E; j++)
		{
			int u = graph->edges[j].src;
			int v = graph->edges[j].dest;
			int weight = graph->edges[j].weight;
			distTo[v] = min(distTo[v], distTo[u] + weight);
		}
	}
	printArr(distTo, V);
}

int main()
{

	int V = 5;
	int E = 8;
	Graph* graph = new Graph(5, 8);

// add edge 0-1 (or A-B in above figure) 
    graph->edges[0].src = 0; 
    graph->edges[0].dest = 1; 
    graph->edges[0].weight = -1; 
  
    // add edge 0-2 (or A-C in above figure) 
    graph->edges[1].src = 0; 
    graph->edges[1].dest = 2; 
    graph->edges[1].weight = 4; 
  
    // add edge 1-2 (or B-C in above figure) 
    graph->edges[2].src = 1; 
    graph->edges[2].dest = 2; 
    graph->edges[2].weight = 3; 
  
    // add edge 1-3 (or B-D in above figure) 
    graph->edges[3].src = 1; 
    graph->edges[3].dest = 3; 
    graph->edges[3].weight = 2; 
  
    // add edge 1-4 (or A-E in above figure) 
    graph->edges[4].src = 1; 
    graph->edges[4].dest = 4; 
    graph->edges[4].weight = 2; 
  
    // add edge 3-2 (or D-C in above figure) 
    graph->edges[5].src = 3; 
    graph->edges[5].dest = 2; 
    graph->edges[5].weight = 5; 
  
    // add edge 3-1 (or D-B in above figure) 
    graph->edges[6].src = 3; 
    graph->edges[6].dest = 1; 
    graph->edges[6].weight = 1; 
  
    // add edge 4-3 (or E-D in above figure) 
    graph->edges[7].src = 4; 
    graph->edges[7].dest = 3; 
    graph->edges[7].weight = -3; 

    BellmanFord(graph, 0);

    return 0;
}
