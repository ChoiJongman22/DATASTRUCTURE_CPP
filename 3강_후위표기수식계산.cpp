#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <stack>
#define MAX 30

using namespace std;

class OperandStack {
private:
	double data[MAX];
	int top;
public:
	OperandStack() {
		top = -1;
	}
	bool isEmpty() {
		return top == -1;
	}
	bool isFull() {
		return top == MAX - 1;
	}
	void push(double e) {
		if (isFull()) {
			cout << "������ȭ����" << "\n";
		}
		data[++top] = e;
	}
	double pop() {
		if (isEmpty()) {
			cout << "�����̺���ִ�!" << "\n";
		}
		return data[top--];
	}
};


double calcPostfixExpr(FILE* fp = stdin) {
	char c;
	OperandStack st;


	while ((c = getc(fp)) != '\n') {
		if (c == '+' || c == '-' || c == '*' || c == '/') {
			double val2 = st.pop();
			double val1 = st.pop();
			switch (c) {
			case '+':st.push(val1 + val2); break;
			case '-':st.push(val1 - val2); break;
			case '*':st.push(val1 * val2); break;
			case '/':st.push(val1 / val2); break;
			}
		}

		else if (c >= '0' && c <= '9') {
			ungetc(c, fp);
			double val;
			fscanf(fp, "%lf", &val);
			st.push(val);
		}
	}
	return (st.pop());
}

void main() {
	cout << "�����Է� (Postfix)= ";
	double res = calcPostfixExpr();
	cout << "����� => " << res << "\n";
}