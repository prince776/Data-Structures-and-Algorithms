#include <bits/stdc++.h>
using namespace std;

int min(int a, int b)
{
	return ((a < b)? a : b);
}

int binomalCoeff(int n, int k)
{
	int dp[n + 1][k + 1];

	for (int i = 0; i <= n; i++)
	{
		for (int j = 0; j <= k; j++)
		{
			if (!j || j == i)
				dp[i][j] = 1;
			else
				dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j];
		}
	}
	return dp[n][k];
}

int binomalCoeff_spaceOptimized(int n, int k)
{
	int dp[k + 1] = {0};
	dp[0] = 1;

	for (int i = 1; i <= n; i++)
	{
		// Calculate next row of pascal triangle using previous row
		for (int j = min(i, k); j > 0; j--)
		{
			dp[j] = dp[j] + dp[j - 1];
		}
	}
	return dp[k];
}

int main()
{
	cout << "5C2 = " << binomalCoeff(5, 2) << "\n";
	cout << "5C2 = " << binomalCoeff_spaceOptimized(5, 2) << "\n";

}