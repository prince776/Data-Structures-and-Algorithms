#include <bits/stdc++.h>
using namespace std;

#include "../DSU/DSU.h"

class Edge
{
public:
    int u, v, w;
    Edge() = default;
    Edge(int u, int v, int w) :
        u(u), v(v), w(w) {};

    bool operator<(Edge const& other) const
    {
        return w < other.w;
    }
    friend istream& operator>>(istream& is, Edge &edge);
};

istream& operator>>(istream& is, Edge &edge)
{
    return (is >> edge.u >> edge.v >> edge.w);
}

auto kruskalMST(vector<Edge> &edges, int V)
{
    int cost = 0;
    
    DSU dsu(V);
    sort(begin(edges), end(edges));

    vector<Edge> tree;
    for (const auto &[u, v, w] : edges)
    {
        if (dsu.getParent(u) != dsu.getParent(v))
        {
            cost += w;
            tree.emplace_back(u, v, w);
            dsu.join(u, v);
        }
    }

    return make_pair(tree, cost);
}

auto makeGraphFromEdges(vector<Edge>& edges, int V)
{
    vector<vector<pair<int, int>>> adj(V);
    for (auto &[u, v, w] : edges)
    {
        adj[u].emplace_back(v, w);
        adj[v].emplace_back(u, w);
    }
    return adj;
}
