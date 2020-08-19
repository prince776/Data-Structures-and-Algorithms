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
    subset() = default;
	subset(int parent, int rank) :
		parent(parent),
		rank(rank)
	{

	}
};

int find(struct subset subsets[], int i) 
{ 
    // find root and make root as parent of i (path compression) 
    if (subsets[i].parent != i) 
        subsets[i].parent = find(subsets, subsets[i].parent); 
  
    return subsets[i].parent; 
} 
  
// A function that does union of two sets of x and y 
// (uses union by rank) 
void Union(struct subset subsets[], int x, int y) 
{ 
    int xroot = find(subsets, x); 
    int yroot = find(subsets, y); 
  
    // Attach smaller rank tree under root of high rank tree 
    // (Union by Rank) 
    if (subsets[xroot].rank < subsets[yroot].rank) 
        subsets[xroot].parent = yroot; 
    else if (subsets[xroot].rank > subsets[yroot].rank) 
        subsets[yroot].parent = xroot; 
  
    // If ranks are same, then make one as root and increment 
    // its rank by one 
    else
    { 
        subsets[yroot].parent = xroot; 
        subsets[xroot].rank++; 
    } 
} 