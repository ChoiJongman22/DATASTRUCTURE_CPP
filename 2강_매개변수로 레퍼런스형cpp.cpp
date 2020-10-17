#include <iostream>
#include <string>
using namespace std;



void swap(int& x, int& y) {
	int tmp;
	tmp = x;
	x = y;
	y = tmp;
}
int main() {
	int a = 1;
	int b = 2;
	swap(a, b);
	cout << a << b << endl;
}