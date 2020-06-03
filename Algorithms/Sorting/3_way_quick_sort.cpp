#include <bits/stdc++.h>

using namespace std;

void swap(int &a, int &b)
{
	int t = a;
	a = b;
	b = t;
}

void partition(int a[], int low, int high, int &i, int &j)
{
	// To handle two elemts
	if (high - low <= 1)
	{
		if (a[high] < a[low])
			swap(a[high], a[low]);
		i = low;
		j = high;
		return;
	}

	int mid = low;
	int pivot = a[high];

	while (mid <= high)
	{
		if (a[mid] < pivot)
			swap(a[low++], a[mid++]);
		else if (a[mid] == pivot)
			mid++;
		else if (a[mid] > pivot)
			swap(a[mid], a[high--]);
	}

	i = low - 1;
	j = mid;
}

void quickSort(int a[], int low, int high)
{
	if (low >= high)
		return;
	int i, j;

	partition(a, low, high, i, j);
	quickSort(a, low, i);
	quickSort(a, j, high);
}

int main()  
{  
    int arr[] = {64, 25, 25, 11, 11, 12, 22, 11};  
    int n = sizeof(arr)/sizeof(arr[0]);  
    quickSort(arr, 0, n - 1);  
	cout << "Sorted array: \n";  
    for (int i = 0; i < n; i++)
    {
    	cout << arr[i] << " ";
    }
    return 0;  
}
