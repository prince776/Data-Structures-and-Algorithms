// Implements Merge Sort Algorithm.
// Time complexity: O(nLogn)
// Auxillary space: O(n)

#include <iostream>

using namespace std;

void merge(int arr[], int l, int m, int r) 
{ 
    int i, j, k; 
    int n1 = m - l + 1; 
    int n2 =  r - m; 
  
    // Create temp arrays.
    int L[n1], R[n2]; 
  
    // Copy values to them.
    for (i = 0; i < n1; i++) 
        L[i] = arr[l + i]; 
    for (j = 0; j < n2; j++) 
        R[j] = arr[m + 1+ j]; 
  
    i = 0; // Initial index of first subarray 
    j = 0; // Initial index of second subarray 
    k = l; // Initial index of merged subarray 
    while (i < n1 && j < n2) 
    { 
        if (L[i] <= R[j]) 
            arr[k] = L[i++]; 
        else
            arr[k] = R[j++];
        k++;
    }
  
    // Copy the remaining elements of L[]
    while (i < n1) 
        arr[k++] = L[i++]; 

  
    // Copy the remaining elements of R[]
    while (j < n2) 
    	arr[k++] = R[j++];  
}

void mergeSort(int arr[], int l, int r)
{
	if (l < r)
	{
		// same as (r + l) / 2, used to avoid numerical overflow 
		int m = l + (r - l) / 2;

		mergeSort(arr, l, m);
		mergeSort(arr, m + 1, r);

		merge(arr, l, m, r);
	}
}

int main()  
{  
    int arr[] = {64, 25, 12, 22, 11};  
    int n = sizeof(arr)/sizeof(arr[0]);  
    mergeSort(arr, 0, n - 1);  
	cout << "Sorted array: \n";  
    for (int i = 0; i < n; i++)
    {
    	cout << arr[i] << " ";
    }
    return 0;  
}
