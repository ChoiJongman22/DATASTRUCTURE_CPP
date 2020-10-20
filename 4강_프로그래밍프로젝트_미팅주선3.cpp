#include <iostream>
#include <ctime>
#include <queue>
using namespace std;

class CircularSimulator{
private:
	int maxStudent;
	double participate;
	int couple;
	int count;
	int student;
	double probArrival;
	int m, f;
	int random;//���� ������

	double Random() {
		return rand() / (double)RAND_MAX;
	}
	bool IsNewStudent() {
		return (Random() > probArrival);
	}

public:
	CircularSimulator() {
		count = couple = m = f = student = 0;
	}

	void readSimulatorParameters() {
		cout << "�ùķ��̼� �� �ִ� �ο�(��:100) = ";
		cin >> maxStudent;
		cout << "�����ð��� ������ �л� ��(��:0.5) = ";
		cin >> probArrival;
	}
	void run() {
		queue<int> male, female;
		while (count < maxStudent) {
			cout << count + 1 << "��° �õ�" << endl;
			if (IsNewStudent()) {
				student++;
				random = rand() % 2; //0�̳� 1�̳ĸ� �������ϴϱ�
				if (!random) {
					male.push(count);
					m++;
					cout << "���л��� �����߽��ϴ�." << endl;
				}
				else {
					female.push(count);
					f++;
					cout << "���л��� �����߽��ϴ�." << endl;
				}
			}
			else {
				cout << "�ƽ��Ե� " << count << " �л��� �ٺ��� �������� ���߽��ϴ�." << endl;
			}

			if (!male.empty() && !female.empty()) {
				int boy, girl;
				boy = male.front();
				male.pop();
				girl = female.front();
				female.pop();
				cout << "���� ����! " << boy << "��" << girl << "�� Ŀ���� �Ǿ����ϴ�." << endl << endl;
				couple++;
			}
			else {
				cout << "���� ����ڰ� �����ϴ�. ��ٷ��ּ���." << endl << endl;
			}
			count++;
		}
	}
	void printStat()
	{
		cout << "=================================================================" << endl;
		cout << "���ÿ� ������ �� �л� ��= " << maxStudent << endl;
		cout << "���ÿ� ������ �л� ��= " << student << endl;
		cout << "����(���л�:���л�) = " << m << " : " << f << endl;
		cout << "����� Ŀ�� ��= " << couple << endl;
		cout << "��Ÿ��� �ַε�= " << maxStudent - 2 * (couple) << endl;
	}
};

int main() {
	srand((unsigned)time(NULL));
	CircularSimulator sim;
	sim.readSimulatorParameters();
	sim.run();
	sim.printStat();
	return 0;
}