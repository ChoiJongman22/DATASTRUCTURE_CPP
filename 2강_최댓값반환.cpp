#include <iostream>
using namespace std;

int findMAX(int a[], int len) {
	int maxV = a[0];
	for (int i = 1; i < len; i++) {
		if (maxV < a[i]) {
			maxV = a[i];
		}
	}
	return maxV;
}

int main() {
	int arr[10] = { 3,24,82,12,34,7,34,53,17,26 };
	int maxV = findMAX(arr, 10);
	cout << maxV;
	return 0;
}