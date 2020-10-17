#include <iostream>
using namespace std;
int ArrayMax(int score[], int n) {
	int tmp = score[0];
	for (int i = 1; i < n; i++) {
		if (score[i]>tmp){
			tmp = score[i];
	    }
	}
	return tmp;
}
// char* a = "data structure";
int main() {
	int score[] = { 1,2,3,4,5 };
	cout<< ArrayMax(score, 5);
	//ArrayMax({ 1,2,3,4,5 }, 5);
	return 0;
}