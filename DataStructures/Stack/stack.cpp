// Implements Stack Data Structure.

#include <bits/stdc++.h>

using namespace std;

class StackNode 
{
public:
	int data;
	StackNode* next;
	StackNode(int data) : data(data), next(NULL) { }
};

bool isEmpty(StackNode* node)
{
	return !node? true : false;
}

void push(StackNode*& root, int data)
{
	StackNode* temp = new StackNode(data);
	temp->next = root;
	root = temp;
	cout << data << " pushed to stack.\n";
}

int pop(StackNode*& root)
{
	if (isEmpty(root))
			return INT_MIN;
	StackNode* temp = root;
	root = root->next;
	int popped = temp->data;
	delete temp;
	return popped;
}

int peek(StackNode* root)
{
	if (isEmpty(root))
		return INT_MIN;
	return root->data;
}

int main()
{
	StackNode* root = NULL;
	push(root, 10);
	push(root, 100);
	push(root, 1000);

	cout << pop(root) << " popped from stack.\n";
	cout << peek(root) << " is at the top.\n";

}

