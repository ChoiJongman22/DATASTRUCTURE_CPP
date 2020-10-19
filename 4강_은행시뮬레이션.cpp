#include <iostream>
#include <time.h>
#define MAX 100

using namespace std;

struct Customer {
	int id;  //����ȣ
	int tArrival;//�����ð�
	int tService;//���񽺸� �޴� �ð�
	

	Customer(int i = 0, int tArr = 0, int tServ = 0) :
		id(i), tArrival(tArr), tService(tServ){}
};

class CircularQueue {
protected://����� ����
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
			cout << "ť�� ��ȭ�����Դϴ�." << "\n";
		}
		else {
			rear = (rear + 1) % MAX;
			data[rear] = val;
		}
	}

	Customer dequeue() {
		if (isEmpty()) {
			cout << "ť�� ��������Դϴ�." << "\n";
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
		cout << " �� " << a.id << " �湮 (���� �ð�: " << a.tService << "��)\n";
		que.enqueue(a);
	}

public:
	BankSimulator():nCustomers(0),totalWaitTime(0),nServedCustomers(0){}
	void readSimulatorParameters() {
		cout << "�ùķ��̼� �� �ִ� �ð� (��:10) = ";
		cin >> nSimulator;
		cout << "�����ð��� �����ϴ� �� ��(��: 0.7) = ";
		cin >> probArrival;
		cout << "�� ���� ���� �ִ� ���� �ð�(��:5) = ";
		cin >> tMaxService;
		cout << "=========================" << endl;
	}

	void run() {
		int clock = 0;
		int serviceTime = -1;
		while (clock < nSimulator) {
			clock++;
			cout << "����ð� : " << clock<<"\n";

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
				printf(" �� %d ���� ���� (���ð�: %d��)\n",a.id,clock-a.tArrival);
				serviceTime = a.tService - 1; //�����Ͽ� �ٽ� ����
			}

		}
	}

	void printStat() {
		cout << "=======================\n";
		cout << "���� ���� ���� =  " << nServedCustomers << "\n";
		cout << "��ü ��� �ð� = " << totalWaitTime << "\n";
		cout << "���񽺰� ��մ��ð� = " << (double)totalWaitTime / nServedCustomers << "\n";
		cout << "���� ��� �� �� = " << nCustomers - nServedCustomers << "\n";

	}
};

void main() {
	srand((unsigned int)time(NULL));
	BankSimulator sim;
	sim.readSimulatorParameters();
	sim.run();
	sim.printStat();

}