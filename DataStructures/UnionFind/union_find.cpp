#include <bits/stdc++.h>
using namespace std;

// This is inefficient implementation.
int find_ineff(int parent[], int i)
{
	if (parent[i] == -1)
		return i;
	return find(parent, parent[i]);
}

void Union_ineff(int parent[], int x, int y)
{
	int xset = find(parent, x);
	int yset = find(parent, y);
	if (xset != yset)
	{
		parent[xset] = yset;
	}
}

// Efficient version, union by rank with path compression.
struct subset
{
	int parent, rank;
	subset(int parent, int rank) :
		parent(parent),
		rank(rank)
	{

	}
};

int find(subset subsets[], int i)
{
	// Path compression
	if (subsets[i].parent != i)
		subsets[i].parent = find(subsets, subsets[i].parent);

	return subsets[i].parent;
}

int Union(subset subsets[], int x, int y)
{
	int xRoot = find(subsets, x);
	int yRoot = find(subsets, y);

	// Attach smaller rank tree under higher rank tree root
	if (subsets[xRoot].rank < subsets[yRoot].rank)
		subsets[xRoot].parent = yRoot;
	if (subsets[yRoot].rank < subsets[xRoot].rank)
		subsets[yRoot].parent = xRoot;

	// If same rank, make one as root and increment the rank.
	else
	{
		subsets[yRoot].parent = xRoot;
		subsets[xRoot].rank++;
	}
}