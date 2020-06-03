#include <bits/stdc++.h>
using namespace std;

// BIT[] is 1-based indexed, hence size = n + 1.

const int n = 5;

int BIT[n + 1];

void update(int x, int delta) // add delta at index x
{	
	for (; x <= n; x += x &-x)
		BIT[x] += delta; // update sum value at all indices which cover x
}

int query(int x)
{
	int sum = 0;
	for (; x > 0; x -= x&-x)
		sum += BIT[x];
	return sum;
}

int main()
{
	int a[] = {1, 2, 3, 4, 5};
	for (int i = 0; i < n; i++)
	{
		update(i + 1, a[i]);
	}
	cout << "sum i, 1 to 3: " << query(4) - query(1) << "\n";
	return 0;
}