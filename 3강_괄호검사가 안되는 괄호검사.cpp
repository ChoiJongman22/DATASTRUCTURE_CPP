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
			error((char*)"스택포화에러");
		data[++top] = x;
	}

	int pop() {
		if (isEmpty())
			error((char*)"스택공백에러");
		//cout << "스택공백에러" << endl;
		return data[top--];
	}

	void show() {
		cout << "스택 항목의 수: " << top + 1 << endl;
		for (int i = 0; i <= top; i++) {
			cout << data[i] << endl;
		}
	}
};


bool checkMatching(char* filename) {
	ifstream f_o;
	f_o.open(filename, ifstream::in);
	if (!f_o) {
		cout << "파일을 열수 없습니다." << endl;
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
		cout << "문제발견: " << "라인수= " << nLine << " 문자수= " << nChar << endl;
	else
		cout << "정상: " << "라인수= " << nLine << " 문자수= " << nChar << endl;

	return s.isEmpty();//bool함수라서
}


int main() {
	checkMatching("소스.cpp");
	checkMatching("소스12.cpp");
}