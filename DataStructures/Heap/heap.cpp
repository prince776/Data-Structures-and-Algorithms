// Implement Heap Data Structure.

#include <iostream>
#include <climits>

using namespace std;

void swap(int *x, int *y)
{
	int t = *x;
	*x = *y;
	*y = t;
}

class MinHeap
{
	int *hArr;
	int capacity;
	int heapSize;

public:

	MinHeap(int capacity);

	void MinHeapify(int );

	int parent(int i) { return (i - 1) / 2;}

	int left(int i) { return 2 * i + 1; }

	int right(int i) { return 2 * i + 2; }

	int extractMin();

	void decreaseKey(int i, int new_val);

	int getMin() { return hArr[0];}

	void deleteKey(int i);

	void insertKey(int k);
};

MinHeap::MinHeap(int cap)
{
	heapSize = 0;
	capacity = cap;
	hArr = new int[cap];
}

void MinHeap::insertKey(int k)
{
	if (heapSize == capacity)
	{
		cout << "Overflow: Can't insert key!\n";
		return;
	}

	int i = heapSize;
	hArr[heapSize++] = k; // insert the new key at end

	// swim
	while (i != 0 && hArr[parent(i)] > hArr[i])
	{
		swap(&hArr[i], &hArr[parent(i)]);
		i = parent(i);
	}
}

void MinHeap::decreaseKey(int i, int new_val)
{
	hArr[i] = new_val;
	// swim
	while (i != 0 && hArr[parent(i)] > hArr[i])
	{
		swap(&hArr[i], &hArr[parent(i)]);
		i = parent(i);
	}
}

int MinHeap::extractMin()
{
	if (heapSize <= 0)
		return INT_MAX;
	if (heapSize == 1)
	{
		heapSize--;
		return hArr[0];
	}

	int root = hArr[0];
	hArr[0] = hArr[heapSize - 1];
	heapSize--;
	// sink
	MinHeapify(0);

	return root;
}

void MinHeap::deleteKey(int i)
{
	decreaseKey(i, INT_MIN);
	extractMin();
}

// sink
void MinHeap::MinHeapify(int i)
{
	int l = left(i);
	int r = right(i);
	int smallest = i;
	if (l < heapSize && hArr[l] < hArr[i])
		smallest = l;
	if (r < heapSize && hArr[r] < hArr[i])
		smallest = r;
	if (smallest != i)
	{
		swap(&hArr[i], &hArr[smallest]);
		MinHeapify(smallest);
	}
}

int main()
{
	MinHeap h(11);
	h.insertKey(3); 
    h.insertKey(2); 
    h.deleteKey(1); 
    h.insertKey(15); 
    h.insertKey(5); 
    h.insertKey(4); 
    h.insertKey(45);
    cout << h.extractMin() << " "; 
    cout << h.getMin() << " "; 
    h.decreaseKey(2, 1); 
    cout << h.getMin(); 

    return 0;  
}
