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
	cout << "�����ּ����α׷��Դϴ�." << endl;
	cout << "���α׷� ���Ḧ ���Ͻø� �̸��� 'stop'�� �Է����ּ���." << endl << endl;

	while (1) {
		cout << "���̸�: ";
		cin >> name;
		if (name == "stop") {
			break;
		}
		cout << "������ �Է��ϼ���(f or m) ";
		cin >> gender;
		cout << "�ּ��� ��� ���Ͻʴϱ�?";
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

			cout << "Ŀ���� ź���߽��ϴ�. " << boy << "�� " << girl << endl << endl;
		}
		else {
			cout << "���� ����ڰ� �����ϴ�. ��ٷ��ּ���." << endl << endl;
		}
	}
	return 0;
}