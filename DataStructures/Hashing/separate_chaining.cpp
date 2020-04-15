// Implements Hashing Data Strucute using Separate Chaining.
// Total elements: n
// Hash table size: m
// alpha: n / m
// Time complexity for search, insert, and delete: O(1 + alpha).
// Worst case: logn / loglogn
#include <bits/stdc++.h>
using namespace std;

struct Hash
{
	int bucket;
	list<int> *table;
public:
	Hash(int v);
	void insertItem(int x);
	void deleteItem(int x);

	int hashFunction(int x)
	{
		return (x % bucket);
	}
	void displayHash();
};

Hash::Hash(int v)
{
	bucket = v;
	table = new list<int>[bucket];
}

void Hash::insertItem(int x)
{
	int index = hashFunction(x);
	table[index].push_back(x);
}

void Hash::deleteItem(int x)
{
	int index = hashFunction(x);
	list<int>::iterator i;
	for (i = table[index].begin(); i != table[index].end(); i++)
		if (*i == x)
			break;
	if (i != table[index].end())
		table[index].erase(i);
}

void Hash::displayHash()
{
	for (int i = 0; i < bucket; i++)
	{
		cout << i;
		for (auto x : table[i])
			cout << "-->" << x;
		cout << endl;
	}
}

int main()
{
	int a[] = {15, 11, 27, 3244, 8, 12};
	int n = sizeof(a) / sizeof(int);

	Hash h(7);
	for (int i = 0; i < n; i++)
		h.insertItem(a[i]);
	h.deleteItem(12);
	h.displayHash();
	return 0;

}