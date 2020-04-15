// Implements Hashing Data Struture with Open Addressing.
// Type of open addressing used: Double Hashing.
// Avoids clustering on cost of performance and being less cache friendly.
// we move like: (hash1(key) + i * hash2(key)) % TABLE_SIZE

// hash1(key) = key % TABLE_SIZE
// hash2(key) = PRIME - (key % PRIME), PRIME < TABLE_SIZE

// Total elements: n
// Hash table size: m
// alpha: n / m ( < 1)
// Avg. Time Complexity: 1 / (1 - alpha)
// Worst Case: logn

#include <bits/stdc++.h>
using namespace std;

#define TABLE_SIZE 13
#define PRIME 7

class DoubleHash
{
	int* hashTable;
	int curr_size;
public:
	bool isFull()
	{
		return (curr_size == TABLE_SIZE);
	}

	int hash1(int key)
	{
		return (key % TABLE_SIZE);
	}

	int hash2(int key)
	{
		return (PRIME - (key % PRIME));
	}

	DoubleHash()
	{
		hashTable = new int[TABLE_SIZE];
		curr_size = 0;
		for (int i = 0; i < TABLE_SIZE; i++)
			hashTable[i] = -1;
	}

	void insertHash(int key)
	{
		if (isFull())
			return;
		int index = hash1(key);

		// If collision occurs.
		if (hashTable[index] != -1)
		{
			int index2 = hash2(key);
			int i = 1;
			while (1)
			{
				int newIndex = (index + i * index2) % TABLE_SIZE;
				if (hashTable[newIndex] == -1)
				{
					hashTable[newIndex] = key;
					break;
				}
				i++;
			}
		}
		else
			hashTable[index] = key;
		curr_size++;
	}

	void search(int key)
	{
		int index1 = hash1(key);
		int index2 = hash2(key);
		int i = 0;
		while (hashTable[(index1 + i*index2) % TABLE_SIZE] != key)
		{
			if (hashTable[(index1 + i*index2) % TABLE_SIZE] == -1)
			{
				cout << "Key: " << key << " doesn't exist!\n";
				return;
			}
			i++;
		}
		cout << "Key: " << key << " exists!\n";
	}

	void displayHash()
	{
		for (int i = 0; i < TABLE_SIZE; i++)
		{
			if (hashTable[i] != -1)
				cout << i << " ---> " << hashTable[i] << endl;
			else
				cout << i << endl; 
		}
	}
};

int main()
{
	int a[] = {19, 22, 34, 224, 124};
	int n = 5;
	DoubleHash h;
	for (int i = 0; i < n; i++)
		h.insertHash(a[i]);
	h.search(34);
	h.search(111);
	h.displayHash();
	return 0;
}