// Implements Left Leaning Red Black BST.

#include <bits/stdc++.h>
using namespace std;

struct Node
{
	int data;
	Node* left, *right;
	bool color;
	Node(int data, bool color = true) : 
			data(data),
			left(0), 
			right(0),
			color(color)
	{
		// Nothing to do here.
	}
};

Node* rotateLeft(Node* node)
{
	Node* child = node->right;
	Node* childL = child->left;

	child->left = node;
	node->right = childL;

	return child;
}

Node* rotateRight(Node* node)
{
	Node* child = node->left;
	Node* childR = child->right;

	child->right = node;
	node->left = childR;

	return child;
}


bool isRed(Node* node)
{
	if (!node)
		return false;
	else
		return node->color == true;
}

void swapColors(Node* node1, Node* node2)
{
	bool temp = node1->color;
	node1->color = node2->color;
	node2->color = temp;
}

void flipColors(Node *node)
{
	node->color = !node->color;
	node->left->color = !node->left->color;
	node->right->color = !node->right->color;
}

Node* insert(Node* node, int data)
{
	// Basic insertion in a BST.
	if (!node)
		return new Node(data, true);
	if (data < node->data)
		node->left =  insert(node->left, data);
	else if (data > node->data)
		node->right = insert(node->right, data);
	else
		return node;

	// Tree balancing.

	// case 1: right is red, left is black or NULL
	if (isRed(node->right) && !isRed(node->left))
	{
		node = rotateLeft(node);
		swapColors(node, node->left);
	}
	// case 2: left and grand left is red.
	if (isRed(node->left) && isRed(node->left->left))
	{
		node = rotateRight(node);
		swapColors(node, node->right);
	}
	// case 3: both left and right children are red.
	if (isRed(node->left) && isRed(node->right))
	{
		flipColors(node);
	}
	return node;
}

void printInOrder(Node* root)
{
	if (!root)
		return;
	printInOrder(root->left);
	cout << root->data << " ";
	printInOrder(root->right);
}

int main()
{
	Node *root = NULL;
	root = insert(root, 10);

	root = insert(root, 20);

	root = insert(root, 30);

	root = insert(root, 40);

	root = insert(root, 50);

	root = insert(root, 25);

	printInOrder(root);

	return 0;
}