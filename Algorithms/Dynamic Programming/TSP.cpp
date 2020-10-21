// Travelling Salesperson Problem, solution using DP
#include <bits/stdc++.h>
using namespace std;

int n=4;
int dist[10][10] = {
        {0,20,42,25},
        {20,0,30,34},
        {42,30,0,10},
        {25,34,10,0}
};

// 2^n masks, n pos
int dp[16][4];

int tsp(int mask, int pos)
{
	if (mask == (1 << n) - 1)
		return dist[0][pos];

	if (dp[mask][pos] != -1)
		return dp[mask][pos];

	int ans = INT_MAX;

	for (int i = 0; i < n; i++)
	{
		if ((mask & (1 << i)) == 0)
			ans = min(ans, dist[pos][i] + tsp(mask | (1 << i), i));
	}

	return dp[mask][pos] = ans;
}

int32_t main()
{
	for (int i = 0; i < 16; i++)
		for (int j = 0; j < 4; j++)
			dp[i][j] = -1;
	cout << tsp(1, 0) << "\n";
	return 0;
}