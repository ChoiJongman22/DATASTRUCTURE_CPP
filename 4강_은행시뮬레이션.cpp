#include <iostream>
#include <time.h>
#define MAX 100

using namespace std;

struct Customer {
	int id;  //고객번호
	int tArrival;//도착시간
	int tService;//서비스를 받는 시간
	

	Customer(int i = 0, int tArr = 0, int tServ = 0) :
		id(i), tArrival(tArr), tService(tServ){}
};

class CircularQueue {
protected://상속을 위한
	int front;
	int rear;
	Customer data[MAX];

public:
	CircularQueue() {
		front = rear = 0;
	}
	bool isEmpty() { return front == rear; }
	bool isFull() { return (rear + 1) % MAX == front; }

	void enqueue(Customer val) {
		if (isFull()) {
			cout << "큐가 포화상태입니다." << "\n";
		}
		else {
			rear = (rear + 1) % MAX;
			data[rear] = val;
		}
	}

	Customer dequeue() {
		if (isEmpty()) {
			cout << "큐가 공백상태입니다." << "\n";
		}
		else {
			front = (front + 1) % MAX;
			return data[front];
		}
	}
};

class BankSimulator {
private:
	int nSimulator;
	double probArrival; 
	int tMaxService;
	int totalWaitTime;
	int nCustomers;
	int nServedCustomers;
	CircularQueue que;

	double Random() { return rand() / (double)RAND_MAX; }
	bool IsNewCustomer() { return Random() < probArrival; }
	int RandServiceTime() { return (int)(tMaxService * Random()) + 1; }

	void InsertCustomer(int arrivalTime) {
		Customer a(++nCustomers, arrivalTime, RandServiceTime());
		cout << " 고객 " << a.id << " 방문 (서비스 시간: " << a.tService << "분)\n";
		que.enqueue(a);
	}

public:
	BankSimulator():nCustomers(0),totalWaitTime(0),nServedCustomers(0){}
	void readSimulatorParameters() {
		cout << "시뮬레이션 할 최대 시간 (예:10) = ";
		cin >> nSimulator;
		cout << "단위시간에 도착하는 고객 수(예: 0.7) = ";
		cin >> probArrival;
		cout << "한 고객에 대한 최대 서비스 시간(예:5) = ";
		cin >> tMaxService;
		cout << "=========================" << endl;
	}

	void run() {
		int clock = 0;
		int serviceTime = -1;
		while (clock < nSimulator) {
			clock++;
			cout << "현재시간 : " << clock<<"\n";

			if (IsNewCustomer()) {
				InsertCustomer(clock);
			}
			if (serviceTime > 0) {
				serviceTime--;
			}
			else {
				if (que.isEmpty()) continue;
				Customer a = que.dequeue();
				nServedCustomers++;
				totalWaitTime += clock - a.tArrival;
				printf(" 고객 %d 서비스 시작 (대기시간: %d분)\n",a.id,clock-a.tArrival);
				serviceTime = a.tService - 1; //월요일에 다시 설명
			}

		}
	}

	void printStat() {
		cout << "=======================\n";
		cout << "서비스 받은 고객수 =  " << nServedCustomers << "\n";
		cout << "전체 대기 시간 = " << totalWaitTime << "\n";
		cout << "서비스고객 평균대기시간 = " << (double)totalWaitTime / nServedCustomers << "\n";
		cout << "현재 대기 고객 수 = " << nCustomers - nServedCustomers << "\n";

	}
};

void main() {
	srand((unsigned int)time(NULL));
	BankSimulator sim;
	sim.readSimulatorParameters();
	sim.run();
	sim.printStat();

}