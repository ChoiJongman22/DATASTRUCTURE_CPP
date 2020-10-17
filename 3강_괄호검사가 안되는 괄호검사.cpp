#include <iostream>
#include <fstream>
#include <ostream>
#include <string>
#define MAX 20 

using namespace std;

inline void error(char* message) {
	cout << message << endl;
	exit(1);
}


class Stack {
private:
	int top;
	int data[MAX];
public:
	Stack() { top = -1; }
	~Stack() {};

	bool isEmpty() { return top == -1; }
	bool isFull() { return top == MAX; }

	void push(int x) {
		if (isFull())
			error((char*)"������ȭ����");
		data[++top] = x;
	}

	int pop() {
		if (isEmpty())
			error((char*)"���ð��鿡��");
		//cout << "���ð��鿡��" << endl;
		return data[top--];
	}

	void show() {
		cout << "���� �׸��� ��: " << top + 1 << endl;
		for (int i = 0; i <= top; i++) {
			cout << data[i] << endl;
		}
	}
};


bool checkMatching(char* filename) {
	ifstream f_o;
	f_o.open(filename, ifstream::in);
	if (!f_o) {
		cout << "������ ���� �����ϴ�." << endl;
	}

	int nLine = 1;
	int nChar = 0;
	Stack s;
	char ch = f_o.get();


	while (!f_o.eof()) {

		if (f_o.get() == '\n')

			nLine++;
		nChar++;

		if (ch == '[' || ch == '(' || ch == '{')
		{
			s.push(ch);
		}

		else if (ch == ']' || ch == ')' || ch == '}') {
			int prev = s.pop();

			if ((ch == ']' && prev != '[')
				|| (ch == ')' && prev != '(')
				|| (ch == '}' && prev != '{'))
				break;
		}
	}
	f_o.close();

	if (!s.isEmpty())
		cout << "�����߰�: " << "���μ�= " << nLine << " ���ڼ�= " << nChar << endl;
	else
		cout << "����: " << "���μ�= " << nLine << " ���ڼ�= " << nChar << endl;

	return s.isEmpty();//bool�Լ���
}


int main() {
	checkMatching("�ҽ�.cpp");
	checkMatching("�ҽ�12.cpp");
}