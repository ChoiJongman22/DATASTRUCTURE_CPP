#include <iostream>
#include <string>
#define MAX 100
using namespace std;

class Student {
private:
	int id;
	string name;
	string dept;

public:
	Student(int i = 0, string n = "", string d = "") { set(i, n, d); }
	void set(int i, string n, string d) {
		id = i;
		name = n;
		dept = d;
	}

	void display() {
		cout << "�й�: " << id << "�̸�: " << name << " �а�: " << dept << "\n";
	}
};

class Node :public Student {
private:
	Node* link;
public:
	Node(int id = 0, string name = "", string dept = "")
		:Student(id, name, dept) {
		link = NULL;
	}
	~Node() {}
	Node* getLink() { return link; }
	void setLink(Node* p) { link = p; }
};

class StudentQueue :public Node {
private:
	Node* front;
	Node* rear;
public:
	StudentQueue() :front(NULL), rear(NULL) {}
	~StudentQueue() { while (isEmpty())delete dequeue(); }
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
		cout << "�л����� : " << "\n";
		for (Node* p = front; p != NULL; p = p->getLink())
			p->display();
		cout << "\n";
	}
};

void main() {
	StudentQueue que;
	que.enqueue(new Node(2015, "������", "�۷ι��̵���к�"));
	que.enqueue(new Node(2015, "�迵��", "�۷ι��̵���к�"));
	que.enqueue(new Node(2016, "������", "�۷ι��̵���к�"));
	que.enqueue(new Node(2017, "������", "�۷ι��̵���к�"));
	que.display();
	delete que.dequeue();
	que.display();
}