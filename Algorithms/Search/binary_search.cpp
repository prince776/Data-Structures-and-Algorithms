// Solution to	"who will win" problem on geeks for geeks using binary search.
// Question available at: https://practice.geeksforgeeks.org/problems/who-will-win/0

#include <iostream>
using namespace std;

bool isPresent(int a[], int n, int k)
{
    int lo = 0,hi = n -1,mid =  (lo + hi)/ 2;
    while(lo <= hi)
    {
        if(k == a[mid])
            return true;
        else if(k < a[mid])
            hi = mid - 1;
        else
            lo = mid + 1;
        mid = (lo + hi) / 2;
    }
    
    return false;
}

int main() {
	
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	int t;
	cin >> t;
	while(t--)
	{
	    int n, k, ans;
	    cin >> n >> k;
	    int a[n];
	    for(int i = 0; i < n; i++)
	    {
	        cin >> a[i];
	    }
	    
	    ans = isPresent(a, n, k)? 1 : -1;
	    cout << ans << "\n";
	}
	
	return 0;
}