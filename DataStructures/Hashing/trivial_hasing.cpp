// Implements Trivial implementation of Hashing Data Structure.

#include <bits/stdc++.h>
using namespace std;

#define MAX 1000

bool has[MAX + 1][2];

bool search(int x)
{
	if (x >= 0)
	{
		if (has[x][0] == 1)
			return true;
	}
	else
	{
		x = abs(x);
		if (has[x][1] == 1)
			return true;
	}
	return false;
}

void insert(int a[], int n) 
{ 
    for (int i = 0; i < n; i++) { 
        if (a[i] >= 0)  
            has[a[i]][0] = 1; 
       else
            has[abs(a[i])][1] = 1; 
    } 
} 
  

int main()
{
	int a[] = { -2, -5, 1, 5, 111};
	insert(a, 5);
	if (search(1))
		cout << "Present!\n";
	else
		cout << "Not Present!\n";
	return 0;
}
