#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <stack>
using namespace std;

bool check(char* filename) {//string filename���� ��������
	FILE* fp = fopen(filename, "r");//�б� ���
	if (fp == NULL) {
		cout << "������ �������� �ʽ��ϴ�." << endl;
	}

	int nLine = 1;
	int nChar = 0;

	stack<char> s;
	char ch;

	while ((ch = getc(fp)) != EOF) {
		if (ch == '\n')nLine++;
		nChar++;
		if (ch == '[' || ch == '(' || ch == '{') {
			s.push(ch);
		}
		else if (ch == ']' || ch == ')' || ch == '}') {
			char prev = s.top();
			s.pop();
			if ((ch == ']' && prev != '[') ||
				(ch == '}' && prev != '{') ||
				(ch == ')' && prev != '(')) {
				break;
			}
		}
	}
	fclose(fp);
	cout << "���ϰ˻���: " << filename << "\n";

	if (s.empty()==true) {
		cout << "�����߰�! ���μ�: " << nLine << " ���ڼ�: " << nChar << "\n";
	}
	else {
		cout << "OK! ���μ�: " << nLine << " ���ڼ�: " << nChar << "\n";
	}
	return s.empty();
}


int main() {
	check("��ȣ�˻�_STL���.cpp");
}