// Implements Binary Tree Data Structure.

#include <iostream>
#include <queue>

using namespace std;

struct Node
{
	Node(int data) : data(data) { left = 0; right = 0; }
	int data;
	Node* left;
	Node* right;
};

// In-order traversal. Comes under DFS
void inOrder(Node* node)
{
	if (!node)
		return;
	inOrder(node->left);
	cout << node->data << " ";
	inOrder(node->right);
}

void insert(Node* root, int data)
{
	queue<Node*> q;
	q.push(root);

	// Do level order traversal until empty place is found
	// This is BFS
	while (!q.empty())
	{
		Node* temp = q.front();
		q.pop();

		if(!temp->left)
		{
			temp->left= new Node(data);
			break;
		} else 
			q.push(temp->left);

		if (!temp->right)
		{
			temp->right = new Node(data);
			break;
		} else
			q.push(temp->right);
	}
}

void deleteDeepest(Node* root, Node* node)
{
	Node* temp = root;
	queue<Node*> q;
	q.push(temp);

	while(!q.empty())
	{
		temp = q.front();
		q.pop();
		if (temp == node)
		{
			temp = NULL;
			delete node;
			return;
		}
		if (temp->right)
		{
			if (temp->right == node)
			{
				temp->right = NULL;
				delete node;
				return;
			} else
				q.push(temp->right);
		}
		if (temp->left)
		{
			if (temp->left == node)
			{
				temp->left = NULL;
				delete node;
				return;
			} else
				q.push(temp->left);
		}
	}
}

void deletion(Node*& root, int data)
{
	if (!root)
		return;
	if (root->left == NULL && root->right == NULL)
	{
		if(root->data == data)
		{
			root = NULL;
			return;
		}	
		else
			return;
	}

	// Find the node to be deleted.
	Node* reqNode = NULL, *temp, *prev;

	queue<Node*> q;
	q.push(root);

	// DO BFS to find the required node(deepest).
	while (!q.empty())
	{
		prev = temp;
		temp = q.front();
		q.pop();

		if(temp->data == data)
			reqNode = temp;
		if (temp->left)
			q.push(temp->left);
		if (temp->right)
			q.push(temp->right);
	}

	if(reqNode)
	{
		reqNode->data = temp->data;
		deleteDeepest(root, temp);
	}
}

// Level order traversal, aka Breadth First Search, using queue
void printLevelOrder(Node* root)
{
	if (root == NULL) return;
	queue<Node*> q;
	q.push(root);
	while (!q.empty())
	{
		Node* node = q.front();
		q.pop();

		cout << node->data << " ";

		if (node->left != NULL)
			q.push(node->left);
		if (node->right != NULL)
			q.push(node->right);
	}
}

// Level order traversal, aka Breadth First Search, using recursion
int height(Node* root)
{
	if (root == NULL)
		return 0;
	int lHeight = height(root->left);
	int rHeight = height(root->right);
	if (lHeight > rHeight)
		return lHeight + 1;
	else
		return rHeight + 1;
}

void printGivenLevel(Node* root, int level)
{
	if (root == NULL)
		return;
	if (level == 1)
		cout << root->data << " ";
	else
	{
		printGivenLevel(root->left, level - 1);
		printGivenLevel(root->right, level - 1);
	}
}

void printLevelOrder_recursive(Node* root)
{
	int h = height(root);
	for (int i = 0; i <= h; i++)
		printGivenLevel(root, i);
}


// Depth First Searches:
// DFS 1: Inorder: Left, Root, Right
// DFS 2: Preorder: Root, Left, Right
// DFS 3: postorder: Left, Right, Root

void printInOrder(Node* node)
{
	if (node == NULL)
		return;
	printInOrder(node->left);
	cout << node->data << " ";
	printInOrder(node->right);
}

void printPreOrder(Node* node)
{
	if (node == NULL)
		return;
	cout << node->data << " ";
	printPreOrder(node->left);
	printPreOrder(node->right);
}

void printPostOrder(Node* node)
{
	if (node == NULL)
		return;
	printPostOrder(node->left);
	printPostOrder(node->right);
	cout << node->data << " ";
}

int main()
{
	Node* root = new Node(10);

	root->left = new Node(11);
	root->left->left = new Node(7);
	root->left->right = new Node(12);
	root->right = new Node(9);
	root->right->left = new Node(15);
	root->right->right = new Node(8);

	// cout << "Inorder traversal:\n";
	// inOrder(root);

	// deletion(root, 11);

	// cout << "\nInorder traversal:\n";
	// inOrder(root);

	cout << "\nPrinting using BFS (using queue):\n";
	printLevelOrder(root);
	cout << "\nPrinting using BFS (using recursion):\n";
	printLevelOrder_recursive(root);
	cout << "\nPrinting using DFS (Inorder):\n";
	printInOrder(root);
	cout << "\nPrinting using DFS (Preorder):\n";
	printPreOrder(root);
	cout << "\nPrinting using DFS (Postorder):\n";
	printPostOrder(root);


	return 0;
}