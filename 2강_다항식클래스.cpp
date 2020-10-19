#include <iostream>
#include <string>
#define MAX 80
using namespace std;

class Polynomial{
private:
	int degree;
	float coef[MAX];
	
public:
	Polynomial() { degree = 0; }//�ִ� ������ 0���� �ʱ�ȭ

	void read() {
		cout << "�ְ������� �Է�����" << "\n";
		cin >> degree;
		cout << "�� ���� ����� �Է��ϼ���." << degree + 1<<"��";
		for (int i = 0; i <= degree; i++) {
			cin >> *(coef + i);//�̰� ���??
		}
	}
	void display(string str = " Poly = ") {
		cout << str;
		for (int i = 0; i < degree; i++) {
			cout << coef[i] << "x^" << degree - i << "+";
		}
		cout << coef[degree];//�����
	}

	void add(Polynomial a, Polynomial b) {
		if (a.degree > b.degree) {
			*this = a;
			for (int i = 0; i <= b.degree; i++) {
				coef[i + (degree - b.degree)] += b.coef[i];// coef[i+(degree-b.degree)]= coef[i+(degree-b.degree)]+b.coef[i]
			}
		}
		else {
			*this = b;
			for (int i = 0; i <= a.degree; i++) {
				coef[i + (degree - a.degree)] += a.coef[i];
			}
		}
	}
	bool isZero() { return degree == 0; }
	void negate() {
		for (int i = 0; i <= degree; i++) {
			coef[i] = -coef[i];
		}
	}
};

void main() {
	Polynomial a, b, c;
	a.read();
	b.read();
	b.negate();
	c.add(a, b);
	a.display("A= ");
	b.display("B= ");
	c.display("A+B= ");
}