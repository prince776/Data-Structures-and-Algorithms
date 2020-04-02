// Solution to "N meetings in one room" problem based on greedy algorithmic approach.
// Question available at: https://practice.geeksforgeeks.org/problems/n-meetings-in-one-room/0

#include <iostream>
#include <algorithm>

using namespace std;

struct Activity
{
    int start;
    int finish;
    int index;
};

bool activityCompare(Activity a1, Activity a2)
{
    return a1.finish < a2.finish;
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    int n;
    cin >> t;
    while( t-- )
    {
        cin >> n;
        Activity a[n];
        for (int i = 0; i < n; i++)
        {
            cin >> a[i].start;
            a[i].index = i;
        }
        for (int i = 0; i < n; i++)
            cin >> a[i].finish;
        
        sort(a, a + n, activityCompare);
        
        int lastI = 0;
        cout << a[lastI].index + 1;
        for (int i = 1; i < n; i++)
        {
            if(a[i].start >= a[lastI].finish)
            {
                cout << " " << a[i].index + 1;
                lastI = i;
            }
        }
        cout << "\n";
    }
    
	return 0;
}