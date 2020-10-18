#include <iostream>
#define MAX 100
using namespace std;

class CircularQueue {
protected://����� ����
	int front;
	int rear;
	int data[MAX];

public:
	CircularQueue() {
		front = rear = 0;
	}
	bool isEmpty() { return front == rear; }
	bool isFull() { return (rear + 1) % MAX == front; }

	void enqueue(int val) {
		if (isFull()) {
			cout << "ť�� ��ȭ�����Դϴ�." << "\n";
		}
		else {
			rear = (rear + 1) % MAX;
			data[rear] = val;
		}
	}

	int dequeue() {
		if (isEmpty()) {
			cout << "ť�� ��������Դϴ�." << "\n";
		}
		else {
			front = (front + 1) % MAX;
			return data[front];
		}
	}

	void display() {
		cout << "ť����: ";
		int maxi = (front < rear) ? rear : rear + MAX;
		for (int i = front + 1; i <= maxi; i++) {
			cout << data[i % MAX];

		}
		cout << "\n";
	}
};



//����ť �����Լ�.
//void main() {
//	CircularQueue que;
//	for (int i = 1; i < 10; i++) {
//		que.enqueue(i);
//	}
//	que.display();
//	que.dequeue();
//	que.dequeue();
//	que.display();
//}


class CircularDeque :public  CircularQueue{
public:
	CircularDeque(){}
	void addRear(int val) { enqueue(val); }
	int deleteFront() { return dequeue(); }
	
	void addFront(int val) {
		if (isFull()) {
			cout << "���� ��ȭ�����Դϴ�." << "\n";
		}
		else {
			data[front] = val;
			front = (front - 1 + MAX) % MAX;
		}
	}

	int deleteRear() {
		if (isEmpty()) {
			cout << "���� ��������Դϴ�." << "\n";
		}
		else {
			int ret = data[rear];
			rear = (rear - 1 + MAX) % MAX;
			return ret;
		}
	}

	void display() {
		cout << "���� ����: ";
		int maxi = (front < rear) ? rear : rear + MAX;
		for (int i = front + 1; i <= maxi; i++) {
			cout << data[i % MAX];
		}
		cout << "\n";
	
	}
};

//�������� �����Լ�

void main() {
	CircularDeque deq;
	for (int i = 1; i < 10; i++) {
		if (i % 2==0) { deq.addFront(i); }
		else if(i%2==1) { deq.addRear(i); }
	}
	deq.display();
	deq.deleteFront();
	deq.deleteRear();
	deq.deleteFront();
	deq.display();
}