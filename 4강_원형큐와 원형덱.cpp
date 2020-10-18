#include <iostream>
#define MAX 100
using namespace std;

class CircularQueue {
protected://상속을 위한
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
			cout << "큐가 포화상태입니다." << "\n";
		}
		else {
			rear = (rear + 1) % MAX;
			data[rear] = val;
		}
	}

	int dequeue() {
		if (isEmpty()) {
			cout << "큐가 공백상태입니다." << "\n";
		}
		else {
			front = (front + 1) % MAX;
			return data[front];
		}
	}

	void display() {
		cout << "큐내용: ";
		int maxi = (front < rear) ? rear : rear + MAX;
		for (int i = front + 1; i <= maxi; i++) {
			cout << data[i % MAX];

		}
		cout << "\n";
	}
};



//원형큐 메인함수.
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
			cout << "덱이 포화상태입니다." << "\n";
		}
		else {
			data[front] = val;
			front = (front - 1 + MAX) % MAX;
		}
	}

	int deleteRear() {
		if (isEmpty()) {
			cout << "덱이 공백상태입니다." << "\n";
		}
		else {
			int ret = data[rear];
			rear = (rear - 1 + MAX) % MAX;
			return ret;
		}
	}

	void display() {
		cout << "덱의 내용: ";
		int maxi = (front < rear) ? rear : rear + MAX;
		for (int i = front + 1; i <= maxi; i++) {
			cout << data[i % MAX];
		}
		cout << "\n";
	
	}
};

//원형덱의 메인함수

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