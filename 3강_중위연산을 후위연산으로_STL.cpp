#define _CRT_SECURE_NO_WARNINGS
#include <stack>
#include <iostream>

using namespace std;


inline int precedence(char op) {
	switch (op) {
	    case '(' : case ')' :  return 0;
	    case '+' : case '-' :  return 1;
	    case '*' : case '/' :  return 2;
	}
	return -1;
}


void infix2Postfix(FILE *fp = stdin) {
	char c, op;
	double val;
	stack<char> st;

	while ((c = getc(fp)) != '\n') {//엔터 문자 입력전까지
		//피연산자이면 그대로 출력
		if ((c >= '0' && c <= '9')) {
			ungetc(c, fp);
			fscanf(fp, "%lf", &val);
			cout << val << " ";
		}
		else if (c == '(') st.push(c);
		else if (c == ')') {
			while (!st.empty()) {
				op = st.top();
				st.pop();
				if (op == '(')break;
				else { cout << op<< " "; }
			}
		}

		else if (c == '+' || c == '-' || c == '*' || c == '/') {
			while (!st.empty()) {
				op = st.top();			
				if (precedence(c) <= precedence(op)) {
					cout << op <<" ";
					st.pop();
				}
				else break;
			}
			st.push(c);
		}
	}

	while (!st.empty()) {
		char a = st.top();
		cout << a << " ";
		st.pop();
	}
	cout << "\n";
}

void main() {
	cout << "수식입력 (Infix) = ";
	infix2Postfix();
}