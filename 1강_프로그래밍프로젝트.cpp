#include <iostream>
using namespace std;

int A(int n) {
	int sum = 0;
	sum = n * (n + 1) / 2;
	return sum;
}

int B(int n) {
	int sum = 0;
	for (int i = 1; i <= n; i++) {
		sum += i;
	}
	return sum;
}

int C(int n) {
	int sum = 0;
	for(int i=0;i<=n;i++){
		sum += 1 * i;
	}
	return sum;
}

int main() {
	cout << A(5);
	cout << B(5);
	cout << C(5);
	return 0;

}