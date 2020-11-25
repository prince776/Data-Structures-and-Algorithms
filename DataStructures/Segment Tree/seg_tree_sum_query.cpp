#include <bits/stdc++.h>
using namespace std;

constexpr int MAX_SIZE = 10;

int st[4 * MAX_SIZE];

int combine(int x, int y)
{
	return x + y; // sum for sum queries
}

void buildST(int a[], int v, int l, int r)
{
	if (l == r)
		st[v] = a[l];
	else
	{
		int mid = (l + r) / 2;
		buildST(a, 2 * v, l, mid);
		buildST(a, 2 * v + 1, mid + 1, r);
		st[v] = combine(st[v * 2], st[v * 2 + 1]);
	} 
}

int sumQuery(int v, int nL, int nR, int l, int r)
{
	if (l > r)
		return 0;
	if (nL == l && nR == r)
		return st[v];
	int mid = (nL + nR) / 2;
	return combine(
		sumQuery(v * 2, nL, mid, l, min(r, mid)),
		sumQuery(v * 2 + 1, mid + 1, nR, max(l, mid + 1), r)
	);			
}

void updateST(int v, int nL, int nR, int pos, int newVal)
{
	if (nL == nR)
	{
		st[v] = newVal;
		return;
	}
	int mid = (nL + nR) / 2;
	if (pos <= mid)
		updateST(2 * v, nL, mid, pos, newVal);
	else
		updateST(2 * v + 1, mid + 1, nR, pos, newVal);
	st[v] = combine(st[2 * v], st[2 * v + 1]);
}

int32_t main()
{
	int a[] = {1, 2, 3, 4, 5, 6};
	int n = sizeof(a) / sizeof(int);

	buildST(a, 1, 0, n - 1);

	// Test to check if seg tree works correctly.
	random_device dev;
	mt19937 rng(dev());

    uniform_int_distribution<mt19937::result_type> dist(0,1000); // distribution in range [1, 6]

    int numTests = 1000; // Test thousand times.
    int remTest = numTests;
    int valueUpdateCount = 0;
    while (remTest--)
    {
    	int type = dist(rng) % 2;
    	if (!type)
    	{
    		// Do a random update
    		int idx = dist(rng) % n;
    		int newVal = dist(rng);

    		updateST(1, 0, n - 1, idx, newVal);
    		a[idx] = newVal;
    		valueUpdateCount++;
    	}else
    	{
    		// Do a random range query
    		int l = dist(rng) % n, r = dist(rng) % n;
    		if (l > r) swap(l, r);

    		int stAns = sumQuery(1, 0, n - 1, l, r);
    		int actualAns = 0;
    		for (int i = l; i <= r; i++)
    			actualAns += a[i];

    		if (actualAns != stAns)
    		{
    			cout << "Test failed\n";
    			return 0;
    		}
    	}
    }
    cout << "Test Passed\n";
    cout << "valueUpdateCount: " << valueUpdateCount << "\n";
    cout << "query count: " << numTests - valueUpdateCount << "\n";
    return 0;
}