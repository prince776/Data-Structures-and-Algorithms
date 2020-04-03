// Interpolation search algorithm, for sorted uniform distributions.
// Time complexity, best: O(log log n) and worst: O(n)

#include <bits/stdc++.h>

using namespace std;

int interpolationSearch(int arr[], int n, int x)
{
	int lo = 0, hi = n - 1;

	while(lo <= hi && x > arr[lo] && x <= arr[hi])
	{
		if (lo == hi)
		{
			if (arr[lo] == x)
				return lo;
			return -1;
		}

		int pos = lo + ( (double)(hi - lo) / (arr[hi] - arr[lo]) ) * (x - arr[lo]);
		if(arr[pos] == x)
			return pos;
		if(arr[pos] < x)
			lo = pos + 1;
		else
			hi = pos - 1;
	}
	return -1;
}

int main()
{
	int arr[] = {1,2,3,4,5,6,7,8};
	int x = 5;
	int n = 8;
	cout << interpolationSearch(arr, n, x) << "\n";
	return 0;
}