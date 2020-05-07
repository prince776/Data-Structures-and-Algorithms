#include <bits/stdc++.h>
using namespace std;

class Graph
{
	int V;
	vector<int> *adj;

	void topologicalSortUtil(int v, bool visited[], stack<int> &s);

public:

	Graph(int V) : V(V)
	{
		adj = new vector<int>[V];
	}
	~Graph()
	{
		delete[] adj;
	}

	void addEdge(int v, int w);

	void topologicalSort();
};

void Graph::addEdge(int v, int w)
{
	adj[v].push_back(w);
}

void Graph::topologicalSortUtil(int v, bool visited[], stack<int> &s)
{
	visited[v] = true;
	for (auto &it : adj[v])
	{
		if (!visited[it])
			topologicalSortUtil(it, visited, s);
	}
	s.push(v);
}

void Graph::topologicalSort()
{
	stack<int> s;
	bool visited[V] = {0};
	
	for (int i = 0; i < V; i++)
		if (!visited[i])
			topologicalSortUtil(i, visited, s);
	
	while (!s.empty())
	{
		cout << s.top() << " ";
		s.pop();
	}
}

int main()
{
	Graph g(6);
	g.addEdge(5, 2);
	g.addEdge(5, 0);
	g.addEdge(4, 0);
	g.addEdge(4, 1);
	g.addEdge(2, 3);
	g.addEdge(3, 1);

	cout << "Topological sorted order: \n";
	g.topologicalSort();

	return 0;
}