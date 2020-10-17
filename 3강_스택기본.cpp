#include <iostream>
#define MAX 100
using namespace std;

class Stack {
private:
	int top;
	int data[MAX];

public:
	Stack() { top = -1; }
	~Stack() {}
	bool isEmpty() { return top == -1; }
	bool isFull() { return top == MAX - 1; }
	void push(int a) {
		if (isFull()) {
			cout << "������ȭ" << "\n";
		}
		data[++top] = a;
	}
	int pop(){
		if (isEmpty()) {
			cout << "���ð��鿡��" << "\n";
		}
		return data[top--];
	}

	int peek() {
		if (isEmpty()) {
			cout << "���ð��鿡��" << "\n";
		}
		return data[top];
	}

	void display() {
		cout << "������ �׸� ��" << top + 1 << endl;
		for(int i=top;i>=0;i--){
			cout << data[i] << endl;
		}
	}
};

int main() {
	Stack s;
	s.push(5);
	s.push(1);
	s.push(2);
	s.push(3);
	s.push(6);
	s.push(8);
	s.pop();
	s.pop();
	s.display();
	return 0;

}