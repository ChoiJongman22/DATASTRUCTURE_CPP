#include <iostream>
#include <queue>
#include <deque>

using namespace std;

int main() {
	string name;
	string gender;

	queue<string> male;
	queue<string> female;

	cout << "미팅주선프로그램입니다." << endl;
	cout << "프로그램 종료를 원하시면 이름에 '그만'을 입력해주세요." << endl;

	while (1) {
		cout << "고객이름: ";
		cin >> name;
		if (name == "그만") {
			break;
		}
		cout << "성별을 입력하세요(f or m)";
		cin >> gender;
		if (gender == "m") {
			male.push(name);
		}
		else if (gender == "f") {
			female.push(name);
		}

		if (!male.empty() && !female.empty()) {
			string boyfriend, girlfriend;
			boyfriend = male.front();
			male.pop();
			girlfriend = female.front();
			female.pop();

			cout << "커플이 탄생했습니다." << boyfriend << "와 " << girlfriend << endl<<endl;
		}
		else {
			cout << "아직 대상자가 없습니다. 기다려주세요." << endl << endl;
		}
	}
	return 0;
}