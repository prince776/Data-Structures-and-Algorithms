// Jump search algorithm. For sorted sequences.
// Time complexity is O(n^{1/2})

#include <bits/stdc++.h> 

using namespace std;

int jumpSearch(int arr[], int x, int n)
{
	int stepSize = sqrt(n); // best step size.
	int step = stepSize, prev = 0;
	while (arr[min(step, n) - 1] < x)
	{
		prev = step;
		step += stepSize;
		if(prev >= n)
			return -1;
	}

	while(arr[prev] < x)
	{
		prev++;
		if(prev == min(step, n))
			return -1;
	}

	if(arr[prev] == x)
		return prev;

	return -1;
}

int main()
{
	int arr[] = {1,2,3,4,5,6,7,8};
	int x = 5;
	int n = 8;
	cout << jumpSearch(arr, x, n) << "\n";
	return 0;
}