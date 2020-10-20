#include <iostream>
#include <string>
#define MAX 80
using namespace std;

class Polynomial {
private:
	int degree;
	float coef[MAX];

public:
	Polynomial() { degree = 0; }//�ִ� ������ 0���� �ʱ�ȭ

	void read() {
		cout << "�ְ������� �Է�����" << "\n";
		cin >> degree;
		cout << "�� ���� ����� �Է��ϼ���." << degree + 1 << "��";
		for (int i = 0; i <= degree; i++) {
			cin >> *(coef + i);//�̰� ���??
		}
	}
	void display(string str = " Poly = ") {
		cout << str;
		for (int i = 0; i < degree; i++) {
			cout << coef[i] << "x^" << degree - i << "+ ";
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

	void sub(Polynomial a, Polynomial b) {
		if (a.degree > b.degree) {
			*this = a;
			for (int i = 0; i <= b.degree; i++) {
				coef[i + (degree - b.degree)] -= b.coef[i];// coef[i+(degree-b.degree)]= coef[i+(degree-b.degree)]+b.coef[i]
			}
		}
		else {
			b.negate();
			*this = b;
			for (int i = 0; i <= a.degree; i++) {
				coef[i + (degree - a.degree)] += a.coef[i];
			}
		}
	}
	void mult(Polynomial a, Polynomial b) {
		*this = a;
		int temp = degree;
		degree += b.degree;
		int* temporary = new int[degree + 1];//�ӽù迭�����Ҵ�
		for (int i = 0; i <= degree; i++) {
			temporary[i] = 0;//�ʱ�ȭ
		}
		if (temp < b.degree) {
			for (int i = 0; i <= temp; i++) {
				coef[i + b.degree] = coef[i];
				coef[i] = 0;
			}
		}
		else if (temp == b.degree) {
			for (int i = 0; i <= temp; i++) {
				coef[i + temp] = coef[i];
				if (i != temp) {
					coef[i] = 0;
				}
			}
		}
		else {
			for (int i = 0; i <= temp; i++) {
				temporary[i] = coef[i];
			}
			for (int i = 0; i <= temp; i++) {
				coef[i + b.degree] = temporary[i];
				if (i < b.degree) {
					coef[i] = 0;
				}
			}
			for (int i = 0; i <= degree; i++) {
				temporary[i] = 0;
			}
		}
		for (int i = 0; i <= temp; i++) {
			for (int j = 0; j <= b.degree; j++) {
				temporary[i + j] += coef[b.degree + i] * b.coef[j];
			}
		}
		for (int i = 0; i <= temp; i++) {
			for (int j = 0; j <= b.degree; j++) {
				coef[i + j] = temporary[i + j];
			}
		}
		trim();
		delete[] temporary;
	}

	bool isZero() { return degree == 0; }
	void negate() {
		for (int i = 0; i <= degree; i++) {
			coef[i] = -coef[i];
		}
	}

	void trim() {
		int count = 0;
		while (!coef[count]) {
			count++;
		}
		if (count) {
			int temp = degree;
			degree -= count;
			for (int i = 0; i <= temp - count; i++) {
				coef[i] = coef[i + count];
			}
		}
	}
};

int main() {
	Polynomial a, b, c;
	a.read();
	b.read();
	c.add(a, b);
	a.display("A= ");
	b.display("B= ");
	c.display("����= ");
	c.sub(a, b);
	c.display("����= ");
	c.mult(a, b);
	c.display("����= ");
	return 0;
}