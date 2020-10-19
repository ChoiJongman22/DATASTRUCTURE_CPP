#include <iostream>
#include <queue>
#include <deque>

using namespace std;

int main() {
	deque<string> male;
	deque<string> female;
	string answer;
	string gender;
	string name;
	cout << "미팅주선프로그램입니다." << endl;
	cout << "프로그램 종료를 원하시면 이름에 'stop'을 입력해주세요." << endl << endl;

	while (1) {
		cout << "고객이름: ";
		cin >> name;
		if (name == "stop") {
			break;
		}
		cout << "성별을 입력하세요(f or m) ";
		cin >> gender;
		cout << "주선을 즉시 원하십니까?";
		cin >> answer;
		if (gender == "m" && answer == "y") {
			male.push_front(name);
		}
		else if (answer == "n") {
			male.push_back(name);
		}
		else if (gender == "f" && answer == "y") {
			female.push_front(name);
		}
		else if (answer == "n") {
			female.push_back(name);
		}


		if (!male.empty() && !female.empty()) {
			string boy, girl;
			boy = male.front();
			male.pop_front();
			girl = female.front();
			female.pop_front();

			cout << "커플이 탄생했습니다. " << boy << "와 " << girl << endl << endl;
		}
		else {
			cout << "아직 대상자가 없습니다. 기다려주세요." << endl << endl;
		}
	}
	return 0;
}