#include <iostream>
#include <string>
#define MAX 100
using namespace std;

class Node {
private:
	Node* link;
	int data;
public:
	Node(int val = 0) :data(val), link(NULL) { } //data=val;, link=NULL;
	Node* getLink() { return link; }
	void setLink(Node* next) { link = next; }
	void display() { cout << data; }
};

class LinkedQueue {
private:
	Node* front;
	Node* rear;
public:
	LinkedQueue() :front(NULL), rear(NULL) {}
	~LinkedQueue() { while (isEmpty())delete dequeue(); }
	bool isEmpty() {
		return front == NULL;
	}

	void enqueue(Node* p) {
		if (isEmpty())front = rear = p;
		else {
			rear->setLink(p);
			rear = p;
		}
	}

	Node* dequeue() {
		if (isEmpty())return NULL;
		Node* p = front;
		front = front->getLink();
		if (front == NULL)rear = NULL;
		return p;
	}

	void display() {
		cout << "Å¥ ³»¿ë: ";
		for (Node* p = front; p != NULL; p = p->getLink())
			p->display();
		cout << "\n";
	}
};

void main() {
	LinkedQueue que;
	for (int i = 1; i < 10; i++) {
		que.enqueue(new Node(i));
	}
	que.display();
	delete que.dequeue();
	delete que.dequeue();
	delete que.dequeue();
	que.display();
}
