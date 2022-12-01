#include <bits/stdc++.h>
using namespace std;
 
class Node
{
public:
    int data;
    Node *next;

    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
};

// function for inserting element at head
void InsertAtTail(Node *&tail, int NewData)
{
    // create new Node which become Inserted on Tail Node
    Node *NewNode = new Node(NewData);

    // Link next of  tail Node to NULL

    tail->next = NewNode;
    tail = NewNode;
}

// creating a function to reverse a linked list
Node *reverseList(Node *&head)
{
    if (head == NULL || head->next == NULL) return head; 
    
    Node *previous = NULL; 
    Node *curr = head;
    Node *forward = NULL;

    while (curr != NULL)
    {
        forward = curr->next;
        curr->next = previous;
        //take 1 step frwd..
        previous = curr;
        curr = forward;
    }
    return previous;
}

// creating function for traverse the Linked List
void printLL(Node *&head)
{
    Node *copyNode = head;
    while (copyNode != NULL)
    {
        cout << copyNode->data << " ";
        copyNode = copyNode->next;
    }
}

int main()
{
    Node *Node1 = new Node(100);
    Node *head = Node1;
    Node *tail = Node1;
    InsertAtTail(tail, 23);
    InsertAtTail(tail, 32);
    InsertAtTail(tail, 50);
    InsertAtTail(tail, 15);
    InsertAtTail(tail, 43);

    Node *ans = reverseList(head);
    // printing Linked list
    printLL(ans);
}
