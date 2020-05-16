#include <bits/stdc++.h>
using namespace std;

int countDerangements(int n)
{
	if (n < 0)
		return 0;
	if (n < 3)
		return (n % 2) ? 1: 0;
	
	int dp[n + 1];

	dp[0] = 1;
	dp[1] = 0;
	dp[2] = 1;

	for (int i = 3; i <= n; i++)
		dp[i] = (i - 1) * (dp[i - 1] + dp[i - 2]);

	return dp[n];
}

int main()
{
	cout << "countDerangements(4) = " << countDerangements(4) << "\n";
	return 0;
}