#include <iostream>
using namespace std;

void swap(int* px, int* py) {
	int tmp;
	tmp = *px;
	*px = *py;
	*py = tmp;
}

void main() {
	int a = 1, b = 2;
	swap(&a, &b);
	cout << a << b << endl;
}