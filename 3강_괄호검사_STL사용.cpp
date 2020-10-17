#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <stack>
using namespace std;

bool check(char* filename) {//string filename으로 하지말자
	FILE* fp = fopen(filename, "r");//읽기 모드
	if (fp == NULL) {
		cout << "파일이 존재하지 않습니다." << endl;
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
	cout << "파일검사결과: " << filename << "\n";

	if (s.empty()==true) {
		cout << "문제발견! 라인수: " << nLine << " 문자수: " << nChar << "\n";
	}
	else {
		cout << "OK! 라인수: " << nLine << " 문자수: " << nChar << "\n";
	}
	return s.empty();
}


int main() {
	check("괄호검사_STL사용.cpp");
}