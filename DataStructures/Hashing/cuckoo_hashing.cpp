// Implements Hashing Data Structure using cuckoo hashing.
// It uses concept of Multiple-Choice and Relocation.
// Worst case Time Complexity: O(1)

#include <iostream>
#include <climits>
using namespace std;

// Upper bound on number of elements in our set.
#define MAXN 11
// Choices for position.
#define ver 2

int hashtable[ver][MAXN];

int pos[ver];

void initTable()
{
	for (int j = 0; j < MAXN; j++)
		for (int i = 0; i < ver; i++)
			hashtable[i][j] = INT_MIN;
}

int hashF(int function, int key)
{
	switch(function)
	{
		case 1: return key % MAXN;
		case 2: return (key / MAXN) % MAXN;
		default: return -1;
	}
}

void place(int key, int tableID, int cnt, int n)
{
	// if function has been recursively called max number of time
	// then, stop and declare cycle. Rehash. */
	if (cnt == n)
	{
		cout << "Unpositioned: " << key << endl;
		cout << "Cycle present.REHASH\n";
		return;
	}

	// Calculate and store possible pos for key, is key already present, return.
	for (int i = 0; i < ver; i++)
	{
		pos[i] = hashF(i + 1, key);
		if (hashtable[i][pos[i]] == key)
			return;
	}

	// Check if another key is present at the pos for the new key.
	// If yes, place the new key in its position and place the older
	// key in an alternate position
	if (hashtable[tableID][pos[tableID]] != INT_MIN)
	{
		int dis = hashtable[tableID][pos[tableID]];
		hashtable[tableID][pos[tableID]] = key;
		place(dis, (tableID + 1) % ver, cnt + 1, n);
	}
	else // place the new key in its position
		hashtable[tableID][pos[tableID]] = key;
}

void printTable()
{
	cout << "\nCuckoo HashTable:\n";
	for (int i = 0; i < ver; i++)
	{
		for (int j = 0; j < MAXN; j++)
		{
			if (hashtable[i][j] == INT_MIN)
				cout << "- ";
			else
				cout << hashtable[i][j] << " ";
		}
		cout << endl;
	}
}

void cuckoo(int keys[], int n)
{
	initTable();
	int i, cnt;
	for (i = 0, cnt = 0; i < n; i++, cnt = 0)
		place(keys[i], 0, cnt, n);
	printTable();
}

int main()
{
	int keys_1[] = {20, 50, 53, 75, 100, 67, 105, 3, 36, 39};
	int n = sizeof(keys_1) / sizeof(int);

	cuckoo(keys_1, n);

	int keys_2[] = {20, 50, 53, 75, 100, 67, 105, 3, 36, 39, 6};
	int m = sizeof(keys_2) / sizeof(int);

	cuckoo(keys_2, m);

	return 0;
}
