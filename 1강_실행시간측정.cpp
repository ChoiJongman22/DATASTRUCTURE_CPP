#include <iostream>
#include <ctime>
using namespace std;
int ArrayMax(int score[], int n) {
	int tmp = score[0];
	for (int i = 1; i < n; i++) {
		if (score[i] > tmp) {
			tmp = score[i];
		}
	}
	return tmp;
}

int score[] = { 1,2,3,4,5,7,7,7,77,7,7,7,7,7,7,1,51,251,51,52,52,51,5,125,25,25,15,15,1,51,52,52,2,52,52,5 };
int main() {
	clock_t start, finish;
	double duration;
	start = clock();
	ArrayMax(score,100 );

	finish = clock();
	duration = (double)(finish - start) / CLOCKS_PER_SEC;//1초마다 몇 번의 클럭틱이 나오는지 
	cout << duration << endl;

}