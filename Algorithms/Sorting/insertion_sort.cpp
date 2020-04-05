// Implements Bubble Sort Algorithm.
// Time complexity: O(n^{2})

#include <iostream>

using namespace std;

void insertionSort(int arr[], int n)
{
	int key, j;
	for (int i = 0; i < n; i++)
	{
		key = arr[i];
		for (j = i - 1; j >= 0 && arr[j] > key; j--)
			arr[j + 1] = arr[j];
		arr[j + 1] = key;
	}
}

int main()  
{  
    int arr[] = {64, 25, 12, 22, 11};  
    int n = sizeof(arr)/sizeof(arr[0]);  
    insertionSort(arr, n);  
	cout << "Sorted array: \n";  
    for (int i = 0; i < n; i++)
    {
    	cout << arr[i] << " ";
    }
    return 0;  
}
