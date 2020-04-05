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

int main()
{
	Node* root = new Node(10);

	root->left = new Node(11);
	root->left->left = new Node(7);
	root->left->right = new Node(12);
	root->right = new Node(9);
	root->right->left = new Node(15);
	root->right->right = new Node(8);

	cout << "Inorder traversal:\n";
	inOrder(root);

	deletion(root, 11);

	cout << "\nInorder traversal:\n";
	inOrder(root);

	return 0;
}