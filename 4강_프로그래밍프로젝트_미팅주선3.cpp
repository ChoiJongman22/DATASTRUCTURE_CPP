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
	int random;//성별 무작위

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
		cout << "시뮬레이션 할 최대 인원(예:100) = ";
		cin >> maxStudent;
		cout << "단위시간에 나오는 학생 수(예:0.5) = ";
		cin >> probArrival;
	}
	void run() {
		queue<int> male, female;
		while (count < maxStudent) {
			cout << count + 1 << "번째 시도" << endl;
			if (IsNewStudent()) {
				student++;
				random = rand() % 2; //0이냐 1이냐만 따져야하니까
				if (!random) {
					male.push(count);
					m++;
					cout << "남학생이 참석했습니다." << endl;
				}
				else {
					female.push(count);
					f++;
					cout << "여학생이 참석했습니다." << endl;
				}
			}
			else {
				cout << "아쉽게도 " << count << " 학생은 바빠서 참석하지 못했습니다." << endl;
			}

			if (!male.empty() && !female.empty()) {
				int boy, girl;
				boy = male.front();
				male.pop();
				girl = female.front();
				female.pop();
				cout << "미팅 성공! " << boy << "와" << girl << "가 커플이 되었습니다." << endl << endl;
				couple++;
			}
			else {
				cout << "아직 대상자가 없습니다. 기다려주세요." << endl << endl;
			}
			count++;
		}
	}
	void printStat()
	{
		cout << "=================================================================" << endl;
		cout << "미팅에 지원한 총 학생 수= " << maxStudent << endl;
		cout << "미팅에 참여한 학생 수= " << student << endl;
		cout << "성비(남학생:여학생) = " << m << " : " << f << endl;
		cout << "성사된 커플 수= " << couple << endl;
		cout << "안타까운 솔로들= " << maxStudent - 2 * (couple) << endl;
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