#include <bits/stdc++.h>
using namespace std;

void printFactors(int n) 
{ 
    for (int i=1; i * i<=n; i++) 
    { 
        if (n%i == 0) 
        { 
            if (n/i == i) 
                cout << i << " "; 
  
            else 
                cout << i << " " << n/i << " "; 
        } 
    }
    cout << "\n";
} 

void printPrimeFactors(int n)
{
	set<int> f;
	for (int i = 2; i*i <= n; i++)
	{
		while (n % i == 0)
		{
			f.insert(i);
			n /= i;
		}
	}
	for (auto &i : f)
	{
		cout << i << " ";
	}
	cout << "\n";
}

int main()
{
	printFactors(100);
	printPrimeFactors(100);
	return 0;
}