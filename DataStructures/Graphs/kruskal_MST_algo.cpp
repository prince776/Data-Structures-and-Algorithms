#include <bits/stdc++.h>
using namespace std;

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
	Graph(int V, int E) :
		V(V), E(E)
	{
		edges = new Edge[E];
	}

	~Graph()
	{
		delete[] edges;
	}
};

// Structure for Union-Find.
struct subset
{
	int parent, rank;
};

int find(subset subsets[], int i)
{
	if (subsets[i].parent != i)
		subsets[i].parent = find(subsets, subsets[i].parent);
	return subsets[i].parent;
}

void Union(subset subsets[], int x, int y)
{
	int xroot = find(subsets, x);
	int yroot = find(subsets, y);
	if (subsets[xroot].rank < subsets[yroot].rank)
		subsets[xroot].parent = yroot;
	else if (subsets[xroot].rank > subsets[yroot].rank)
		subsets[yroot].parent = xroot;
	else
	{
		subsets[yroot].parent = xroot;
		subsets[xroot].rank++;
	}
}

int comp(Edge a, Edge b)
{
	return a.weight < b.weight;
}


void kruskalMST(Graph* graph)
{
	int V = graph->V;
	Edge result[V];
	int e = 0; // index var for result[]
	int i = 0; // index var for sorted edges

	sort(graph->edges, graph->edges + graph->E, comp);

	subset* subsets = new subset[V];

	// create V disjoint sets
	for (int v = 0; v < V; v++)
	{
		subsets[v].parent = v;
		subsets[v].rank = 0;
	}

	while (e < V - 1 && i < graph->E)
	{
		Edge edge = graph->edges[i++];

		int x = find(subsets, edge.src);
		int y = find(subsets, edge.dest);

		if (x != y)
		{
			result[e++] = edge;
			Union(subsets, x, y);
		}
	}

	cout << "Edges in MST are: \n";
	for (i = 0; i < e; i++)
	{
		cout << result[i].src << " -- " << result[i].dest << " == "
			 << result[i].weight << "\n";
	}
}

int main()
{
	int V = 4;
	int E = 5;
	Graph* graph = new Graph(V, E);

	// add edge 0-1  
    graph->edges[0].src = 0;  
    graph->edges[0].dest = 1;  
    graph->edges[0].weight = 10;  
  
    // add edge 0-2  
    graph->edges[1].src = 0;  
    graph->edges[1].dest = 2;  
    graph->edges[1].weight = 6;  
  
    // add edge 0-3  
    graph->edges[2].src = 0;  
    graph->edges[2].dest = 3;  
    graph->edges[2].weight = 5;  
  
    // add edge 1-3  
    graph->edges[3].src = 1;  
    graph->edges[3].dest = 3;  
    graph->edges[3].weight = 15;  
  
    // add edge 2-3  
    graph->edges[4].src = 2;  
    graph->edges[4].dest = 3;  
    graph->edges[4].weight = 4;

    kruskalMST(graph);
    delete graph;
    return 0;
}