// Implements Bubble Sort Algorithm.
// Time complexity: O(n^{2})

#include <iostream>

using namespace std;

void bubbleSort(int arr[], int n)
{
	bool swapped = false;
	for (int i = 0; i < n - 1; i++)
	{
		swapped = false;
		for(int j = 0; j < n - i - 1; j++)
		{
			if(arr[j] > arr[j + 1])
			{
				int temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
				swapped = true;
			}
		}
		if(!swapped)
			return;
	}
}

void bubbleSort_recursive(int arr[], int n)
{
	if (n == 1)
		return;
	bool swapped = false;
	for (int i = 0; i < n - 1; i++)
	{
		if(arr[i] > arr[i + 1])
		{
				int temp = arr[i];
				arr[i] = arr[i + 1];
				arr[i + 1] = temp;
				swapped = true;
		}
	}
	if (!swapped)
		return;
	bubbleSort_recursive(arr, n - 1);
}

int main()  
{  
    int arr[] = {64, 25, 12, 22, 11};  
    int n = sizeof(arr)/sizeof(arr[0]);  
    bubbleSort_recursive(arr, n);  
	cout << "Sorted array: \n";  
    for (int i = 0; i < n; i++)
    {
    	cout << arr[i] << " ";
    }
    return 0;  
}
