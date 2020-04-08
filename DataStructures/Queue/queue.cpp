// Implements Queue Data Structure.

#include <bits/stdc++.h>

using namespace std;

struct QueueNode
{
	int data;
	QueueNode* next;
	QueueNode(int data) : data(data), next(NULL) { }
};

struct Queue
{
	QueueNode* rear, *front;
	Queue() : rear(0), front (0) { }

	void enQueue(int data)
	{
		QueueNode* temp = new QueueNode(data);
		if (!rear)
		{
			front = temp;
			rear = temp;
			return;
		}
		rear->next = temp;
		rear = temp;
	}

	void deQueue()
	{
		if (!front)
			return;
		QueueNode* temp = front;
		front = front->next;
		if (!front)
			rear = NULL;
		delete temp;
	}
};

int main()
{
	Queue q;
	q.enQueue(10);
	q.enQueue(15);
	q.enQueue(20);
	q.enQueue(25);
	q.deQueue();
	q.deQueue();
	cout << "Front: " << q.front->data << "\n";
	cout << "Rear: " << q.rear->data << "\n";
	return 0;
}