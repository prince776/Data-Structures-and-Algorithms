#include <bits/stdc++.h>
using namespace std;

void SieveOfEatosthenes(int n)
{

	bool prime[n+1];
	memset(prime, true, sizeof(prime));

	for (int p = 2; p * p <= n; p++)
	{
		if (prime[p])
		{
			for (int i = p * p; i <= n; i += p)
				prime[i] = false;
		}
	}

	// Print all prime numbers
	for (int p = 2; p <= n; p++)
	{
		if (prime[p])
			cout << p << " ";
	}
	cout << "\n";
}

int main()
{
	int n = 30;
	SieveOfEatosthenes(n);
	return 0;
}
