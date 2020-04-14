// Implements AVL Tree Data Structure.

#include <bits/stdc++.h>
using namespace std;

struct Node
{
	int key;
	Node *left, *right;
	int height;
	Node (int key) : 
			key(key), 
			left(0), 
			right(0), 
			height(1) 
	{ 
		// Nothing to do here.
	}
};

int max(int a, int b)
{
	return (a > b)? a : b;
}

int height(Node* node)
{
	if (!node)
		return 0;
	return node->height;
}

Node* rightRotate(Node* node)
{
	Node *x = node->left;
	Node *t = x->right;

	// Perform rotation.
	x->right = node;
	node->left = t;

	// Update heights.
	node->height = max(height(node->left), height(node->right)) + 1;
	x->height = max(height(x->left), height(x->right)) + 1;

	return x;
}

Node* leftRotate(Node* node)
{
	Node* y = node->right;
	Node* t = y->left;

	// Perform rotation.
	y->left = node;
	node->right = t;

	// Update heights.
	node->height = max(height(node->left), height(node->right)) + 1;
	y->height = max(height(y->left), height(y->right)) + 1;
	return y;
}

int getBalance(Node* node)
{
	if (!node)
			return 0;
	return height(node->left) - height(node->right);
}

Node* insert(Node* node, int key)
{
	// Normal BST operations.
	if (!node)
			return new Node(key);

	if (key < node->key)
		node->left = insert(node->left, key);
	else if (key > node->key)
		node->right = insert(node->right, key);
	else
		return node;

	// Update height of this ancestor node.
	node->height = 1 + max(height(node->left), height(node->right));
	// Get balance factor to check balancing, then rotate accordingly.
	int balance = getBalance(node);

	// If balance != [-1,1], then 4 cases of unbalancing.

	// Case 1: Left left.
	if (balance > 1 && key < node->left->key)
		return rightRotate(node);
	
	// Case 2: Right right.
	if (balance < -1 && key > node->right->key)
		return leftRotate(node);

	// Case 3: Left right.
	if (balance > 1 && key > node->left->key)
	{
		node->left = leftRotate(node->left);
		return rightRotate(node);
	}

	// Case 4: Right left.
	if (balance < - 1 && key < node->right->key)
	{
		node->right = rightRotate(node->right);
		return leftRotate(node);
	}
	return node;
}

Node* minNode(Node* node)
{
	if (!node->left)
		return node;
	return minNode(node->left);
}

Node* deleteNode(Node* root, int key)
{
	// STEP 1: Perform standard BST delete (Hibbard deletion).
	if (!root)
		return root;
	if (key < root->key)
		root->left = deleteNode(root->left, key);
	else if (key > root->key)
		root->right = deleteNode(root->right, key);
	else
	{
		// node with at max one child.
		if (!root->left || !root->right)
		{
			Node* temp = root->left? root->left : root->right;
			if (!temp) // 0 children
			{
				temp = root;
				root = NULL;
			}
			else // 1 child
				*root = *temp;
			delete temp;
		}
		else // two children case
		{
			Node* temp = minNode(root->right);
			root->key = temp->key;
			root->right = deleteNode(root->right, temp->key);
		}
	}
	// If tree had only 1 node.
	if (!root)
		return root;

	// STEP 2: Balance back the tree.
	root->height = 1 + max(height(root->left), height(root->right));
	int balance = getBalance(root);

	// To balance the tree, we'll have 4 cases:
	// Case 1: Left left.
	if (balance > 1 && getBalance(root->left) >= 0)
		return rightRotate(root);

	// Case 2: Left right.
	if (balance > 1 && getBalance(root->left) < 0)
	{
		root->left = leftRotate(root->left);
		return rightRotate(root);
	}

	// Case 3: Right right.
	if  (balance < -1 && getBalance(root->right) <= 0)
		return leftRotate(root);

	// Case 4: Right left.
	if (balance < -1 && getBalance(root->right) > 0)
	{
		root->right = rightRotate(root->right);
		return leftRotate(root);
	}
	return root;
}

void printPreOrder(Node* root)
{
	if (!root)
		return;
	cout << root->key << " ";
	printPreOrder(root->left);
	printPreOrder(root->right);
}

int main()
{
	Node* root = NULL;

    root = insert(root, 9);  
    root = insert(root, 5);  
    root = insert(root, 10);  
    root = insert(root, 0);  
    root = insert(root, 6);  
    root = insert(root, 11);  
    root = insert(root, -1);  
    root = insert(root, 1);  
    root = insert(root, 2);

    printPreOrder(root);
    cout << endl;

    root = deleteNode(root, 10);

    printPreOrder(root);
    cout << endl;

    return 0;
}
