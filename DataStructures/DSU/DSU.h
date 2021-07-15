#include <bits/stdc++.h>
using namespace std;

class DSU
{
private:
    vector<int> parent, size;
public:
    DSU(int n)
    {
        parent = vector<int>(n);
        size = vector<int>(n, 1);
        iota(begin(parent), end(parent), 0);
    }
    
    int getParent(int x)
    {
        if (parent[x] == x) return x;
        return parent[x] = getParent(parent[x]);
    }

    void join(int x, int y)
    {
        x = getParent(x);
        y = getParent(y);
        if (size[x] > size[y])
            swap(x, y);
        if (x == y) return;
        parent[x] = y;
        size[y] += size[x];
    }

    int getSize(int x)
    {
        return size[x] = size[getParent(x)];
    }
};
