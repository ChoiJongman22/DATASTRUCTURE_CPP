#include <iostream>
using namespace std;


int A(int n){
	int sum = 0;
	sum = n * n;
	return sum;

}
int B(int n) {
	int sum = 0;
	for (int i = 1; i <= n; i++) {
		sum += n;
	}
	return sum;
}

int C(int n) {
	int sum = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			sum += 1;
		}
	}
	return sum;
}
int main() {
	cout<< A(5);
	cout<<B(5);
	cout << C(5);
}