#include <iostream>
#include <queue>
#include <deque>

using namespace std;

int main() {
	string name;
	string gender;

	queue<string> male;
	queue<string> female;

	cout << "�����ּ����α׷��Դϴ�." << endl;
	cout << "���α׷� ���Ḧ ���Ͻø� �̸��� '�׸�'�� �Է����ּ���." << endl;

	while (1) {
		cout << "���̸�: ";
		cin >> name;
		if (name == "�׸�") {
			break;
		}
		cout << "������ �Է��ϼ���(f or m)";
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

			cout << "Ŀ���� ź���߽��ϴ�." << boyfriend << "�� " << girlfriend << endl<<endl;
		}
		else {
			cout << "���� ����ڰ� �����ϴ�. ��ٷ��ּ���." << endl << endl;
		}
	}
	return 0;
}