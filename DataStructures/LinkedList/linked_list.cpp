// Implements Linked List Data Structure.

#include <iostream>

using namespace std;

class Node
{
public:
	Node(int data) : data(data) { }
	int data;
	Node* next;
};

void push(Node** headRef, int data)
{
	Node* newNode = new Node(data);
	newNode->next = (*headRef);
	(*headRef) = newNode;
}

void insertAfter(Node* prevNode, int data)
{
	if(prevNode == NULL)
	{
		cout << "Previous node can't be null!\n";
		return;
	}
	Node* newNode = new Node(data);
	newNode->next = prevNode->next;
	prevNode->next = newNode;
}

void append(struct Node** headRef, int data)
{
	Node* last = *headRef;

	Node* newNode = new Node(data);
	newNode->next = NULL;
	
	if (*headRef == NULL)
	{
		*headRef = newNode;
		return;
	}

	while(last->next != NULL)
		last = last->next;
	last->next = newNode;
}

void deleteNode(Node** headRef, int key)
{
	Node* temp = *headRef;
	Node* prev;

	// If head node has the key
	if (temp != NULL && temp->data == key)
	{
		*headRef = temp->next;
		delete temp;
		return;
	}

	while(temp != NULL && temp->data != key)
	{
		prev = temp;
		temp = temp->next;
	}

	if(temp == NULL)
	{
		cout << "Node with given key not found";
		return;
	}

	prev->next = temp->next;
	delete temp;
}

void printList(Node* head)
{
	while(head != NULL)
	{
		std::cout << head->data << " ";
		head = head->next;
	}
	std::cout << "\n";
}

int main()
{
	Node* head = NULL;

	append(&head, 6);
	push(&head, 5);
	append(&head, 8);
	append(&head, 9);
	insertAfter(head->next, 7);
	deleteNode(&head, 7);

	printList(head);

	return 0;
}