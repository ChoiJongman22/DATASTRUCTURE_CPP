#include <iostream>
using namespace std;

int findMaxPixel(int a[][5], int h, int w) {
	int maxVal = 0;
	for (int i = 0; i < h; i++) {
		for (int j = 0; j < w; j++) {
			if (maxVal < a[i][j])
				maxVal = a[i][j];
		}
	}
	return maxVal;
}

int main() {
	int img[4][5] = {
		{3,24,82,12,22},
		{34,7,12,19,21},
		{99,7,65,73,58},
		{20,7,8,48,29}
	};
	int maxPixel = findMaxPixel(img, 4, 5);
	cout << maxPixel;
}