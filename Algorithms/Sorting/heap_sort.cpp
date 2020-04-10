// Implements Heap Sort Algorithm.
// Time complexity: O(nLogn)

#include <iostream>

using namespace std;

// sinking, building a max heap
void heapify(int arr[], int n, int i)
{
	int largest = i;
	int l = 2 * i + 1;
	int r = 2 * i + 2;

	if (l < n && arr[l] > arr[largest])
		largest = l;
	if (r < n && arr[r] > arr[largest])
		largest = r;

	if (largest != i )
	{
		int t = arr[largest];
		arr[largest] = arr[i];
		arr[i] = t;
		heapify(arr, n, largest);
	}
}

void heapSort(int arr[], int n)
{
	// Build heap, bottom up, done in time O(n).
	for (int i = n / 2 - 1; i >= 0; i--)
		heapify(arr, n, i);

	// Extract elements, done in O(nLogn).
	for (int i = n - 1; i >= 0; i--)
	{
		int t = arr[0];
		arr[0] = arr[i];
		arr[i] = t;
		heapify(arr, i, 0);
	}
}

int main()  
{  
    int arr[] = {64, 25, 12, 22, 11};  
    int n = sizeof(arr)/sizeof(arr[0]);  
    heapSort(arr, n);  
	cout << "Sorted array: \n";  
    for (int i = 0; i < n; i++)
    {
    	cout << arr[i] << " ";
    }
    return 0;  
}