// Implements algorithm for calculating pow(x, y) using Divide and Conquer technique.
// Time complexity: O(logn)

#include <bits/stdc++.h>
using namespace std;

float power(float x, int y)
{
	float temp;
	if (y == 0)
		return 1;
	temp = power(x, y / 2);
	if (y % 2 == 0)
		return temp * temp;
	else
	{
		if (y > 0)
			return x * temp * temp;
		else
			return (temp * temp) / x;
	}
}

int main()
{
	float x = 23.21;
	int y = -5;
	cout << power(x, y) << endl;
	cout << pow(x, y) << endl;
	return 0;
}