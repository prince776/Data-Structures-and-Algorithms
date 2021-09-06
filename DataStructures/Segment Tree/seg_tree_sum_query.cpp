#include <bits/stdc++.h>
using namespace std;

#include "segtree.h"

int32_t main()
{
	vector<int> a = {1, 2, 3, 4, 5, 6};
	int n = a.size();

	// SegTree<int, int> st(a, [](int x, int y) { return x + y; });
	SegTree<int, int> st(a, [](int x, int y) { return x + y; });

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

			st.pointUpdate(idx, newVal);
    		a[idx] = newVal;
    		valueUpdateCount++;
    	}else
    	{
    		// Do a random range query
    		int l = dist(rng) % n, r = dist(rng) % n;
    		if (l > r) swap(l, r);

    		int stAns = st.query(l ,r);
    		int actualAns = 0;
    		for (int i = l; i <= r; i++)
    			actualAns += a[i];

    		if (actualAns != stAns)
    		{
    			cout << "Test failed\n";
				cout << stAns << ": " << actualAns << "\n";
    			return 0;
    		}
    	}
    }
    cout << "Test Passed\n";
    cout << "valueUpdateCount: " << valueUpdateCount << "\n";
    cout << "query count: " << numTests - valueUpdateCount << "\n";
    return 0;
}