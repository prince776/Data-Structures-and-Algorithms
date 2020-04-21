// Implements Graph Data Structure using adjacency list.

#include <bits/stdc++.h>
using namespace std;

struct Graph
{
	int V;
	unordered_set<int>* adjList;
	bool *marked;
	int *edgeTo;
	int searchSrc;
	int *id;
	int count;

	Graph(int V);

	~Graph()
	{
		delete[] adjList;
		delete[] marked;
		delete[] edgeTo;
		delete[] id;
	}

	void addEdge(int src, int dest);

	void printGraph();

	void searchEdge(int src, int dest);

	void resetSearch();

	// searches

	void BFS(int s);

	void DFS(int s);

	void dfsUtil(int v);

	bool hasPathTo(int v) { return marked[v]; }

	stack<int> pathTo(int v);

	// identifies connected componenets
	void identifyCC();

	void dfsWithCount(int v);

	int numCC() { return count; }

	int getId(int v) { return id[v]; }

};

Graph::Graph(int V) :
		V(V), 
		adjList(new unordered_set<int>[V])
{
	marked = new bool[V];
	edgeTo = new int[V];
	id = new int[V];
	count = 0;
	resetSearch();
}

void Graph::resetSearch()
{
	for (int i = 0; i < V; i++)
	{
		marked[i] = false;
		edgeTo[i] = -1;
	}
}

void Graph::addEdge(int src, int dest)
{
	adjList[src].insert(dest);
	adjList[dest].insert(src);
}

void Graph::printGraph()
{
	for (int i = 0; i < V; i++)
	{
		unordered_set<int> adj = adjList[i];
		cout << "Adjacency List of vertex " << i;
		if (marked[i])
			cout << "*\n";
		else
			cout << "\n";
		for (auto& it : adj)
		{
			cout << it << " ";
		}
		cout << "\n";
	}
}

void Graph::searchEdge(int src, int dest)
{
	auto it = adjList[src].find(dest);
	if (it == adjList[src].end())
		cout << "Edge not found!";
	else
		cout << "Edge found!";
	cout << endl;
}

void Graph::BFS(int s)
{
	searchSrc = s;
	cout << "BFS Traversal: \n";
	resetSearch();
	queue<int> q;
	q.push(s);
	marked[s] = true;
	cout << s << " ";
	while (!q.empty())
	{
		int v = q.front();
		q.pop();
		for (auto& it : adjList[v])
		{
			if (!marked[it])
			{
				q.push(it);
				marked[it] = true;
				edgeTo[it] = v;
				cout << it << " ";
			}
		}
	}
	cout << endl;
}

void Graph::DFS(int s)
{
	searchSrc = s;
	resetSearch();
	cout << "DFS Traversal: \n";
	dfsUtil(s);
	cout << "\n";
}

void Graph::dfsUtil(int v)
{
	marked[v] = true;
	cout << v << " ";
	for (auto& it : adjList[v])
	{
		if (!marked[it]){
			dfsUtil(it);
			edgeTo[it] = v;
		}
	}
}

stack<int> Graph::pathTo(int v)
{
	stack<int> path;
	if (!hasPathTo(v))
		return path;
	for (int x = v; x != searchSrc; x = edgeTo[x])
		path.push(x);
	path.push(searchSrc);
	return path;
}

void Graph::identifyCC()
{
	count = 0;
	for (int i = 0; i < V; i++)
	{
		marked[i] = false;
		id[i] = -1;
	}
	for (int v = 0; v < V; v++)
	{
		if (!marked[v])
		{
			dfsWithCount(v);
			count++;
		}
	}
}

void Graph::dfsWithCount(int v)
{
	marked[v] = true;
	id[v] = count;
	for (auto& it: adjList[v])
	{
		if (!marked[it])
			dfsWithCount(it);
	}
}

int main()
{
	int V = 7;
	Graph g(V);
	g.addEdge(0, 1);
	g.addEdge(0, 4);
	g.addEdge(1, 2);
	g.addEdge(1, 3);
	g.addEdge(1, 4);
	g.addEdge(2, 3);
	g.addEdge(3, 4);
	g.addEdge(5, 6);
	cout << "Before BFS: \n";
	g.printGraph();

	g.DFS(0);

	stack<int> path = g.pathTo(2);
	cout << "0 to 2(with DFS): \n";
	while (!path.empty())
	{
		cout << path.top() << " ";
		path.pop();	
	}
	cout <<  endl;
	g.BFS(0);

	path = g.pathTo(2);
	cout << "0 to 2(with BFS): \n";
	while (!path.empty())
	{
		cout << path.top() << " ";
		path.pop();	
	}
	cout << endl;

	g.identifyCC();
	cout << "Total connected componenets: " << g.numCC() << endl;

	return 0;
}

