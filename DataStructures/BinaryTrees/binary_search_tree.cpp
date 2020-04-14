// Implements Binary Search Tree Data Structure.

#include <iostream>

using namespace std;

struct Node
{
	int key;
	Node(int key) : key(key) { left = NULL; right = NULL; }
	Node *left, *right;
};

Node* search(Node* root, int key)
{
	if (root == NULL || root->key == key)
		return root;
	if (root->key < key)
		return search(root->right, key);
	return search(root->left, key);
}

void insert(Node*& node, int key)
{
	if (node == NULL)
	{
		node = new Node(key);
		return;
	}

	if (key < node->key)
		insert(node->left, key);
	else
		insert(node->right, key);
}

void printInOrder(Node* root)
{
	if (root == NULL)
		return;
	printInOrder(root->left);
	cout << root->key << " ";
	printInOrder(root->right);
}

Node* minValueNode(Node* node)
{
	Node* current = node;
	while (current->left != NULL && current)
		current = minValueNode(current->left);
	return current;
}

Node* deleteNode(Node* root, int key)
{
	if (root == NULL)
		return root;
	if (key < root->key)
		root->left = deleteNode(root->left, key);
	else if (key > root->key)
		root->right = deleteNode(root->right, key);
	else
	{
		// If it has only one child
		if (root->left == NULL)
		{
			Node* temp = root->right;
			delete root;
			return temp;
		}
		else if (root->right == NULL)
		{
			Node* temp = root->left;
			delete root;
			return temp;
		}
		Node* temp = minValueNode(root->right);
		root->key = temp->key;
		root->right = deleteNode(root->right, temp->key);
	}
	return root;
}

int main()
{
	Node* root = NULL;
	insert(root, 50);
	insert(root, 30); 
    insert(root, 20); 
    insert(root, 40); 
    insert(root, 70); 
    insert(root, 60); 
    insert(root, 80); 

    printInOrder(root);
    cout << "\n";
    root = deleteNode(root, 20);
    printInOrder(root);

    return 0;
}

