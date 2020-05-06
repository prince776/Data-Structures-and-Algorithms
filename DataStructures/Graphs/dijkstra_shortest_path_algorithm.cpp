#include <bits/stdc++.h>
using namespace std;

#define INF 1e9 + 5

struct Graph
{
	int V;
	vector<pair<int, int>> *adjList;
	Graph(int V) : V(V)
	{
		adjList = new vector<pair<int, int>>[V];
	}
	~Graph()
	{
		delete[] adjList;
	}
	void addEdge(int src, int dest, int weight);
};


void Graph::addEdge(int src, int dest, int weight)
{
	adjList[src].push_back(make_pair(dest, weight));
}

struct comparer
{
	bool operator()(pair<int, int> a, pair<int, int> b)
	{
		return a.second < b.second;
	}	
};

void DijkstraSP(Graph *graph, int src)
{
	int V = graph->V;
	
	int distTo[V];
	bool processed[V];


	for (int i = 0; i < V; i++)
	{	
		distTo[i] = INF;
		processed[i] = false;
	}
	distTo[src] = 0;
	priority_queue<pair<int, int>, vector<pair<int, int>>, comparer> pq;
	pq.push(make_pair(src, 0));
	while (!pq.empty())
	{
		int a = pq.top().first;
		pq.pop();
		if (processed[a]) continue;
		processed[a] = true;
		for (auto &it : graph->adjList[a])
		{
			int b = it.first;
			int w = it.second;
			if (distTo[b] > distTo[a] + w)
			{
				distTo[b] = distTo[a] + w;
				pq.push(make_pair(b, distTo[b]));
			}
		}
	}

	cout << "Vertex distancesfrom source: \n";
	for (int i = 0; i < V; i++)
		cout << i << " " << distTo[i] << "\n";
}

int main()
{
	int V = 9;
	Graph *graph = new Graph(V);

	graph->addEdge(0, 1, 4);
	graph->addEdge(0, 7, 8);
	graph->addEdge(1, 2, 8);
	graph->addEdge(1, 7, 11);
	graph->addEdge(2, 3, 7);
	graph->addEdge(2, 8, 2);
	graph->addEdge(2, 5, 4);
	graph->addEdge(3, 4, 9);
	graph->addEdge(3, 5, 14);
	graph->addEdge(4, 5, 10);
	graph->addEdge(5, 6, 2);
	graph->addEdge(6, 7, 1);
	graph->addEdge(6, 8, 6);
	graph->addEdge(7, 8, 7);

	DijkstraSP(graph, 0);

	return 0;
}
