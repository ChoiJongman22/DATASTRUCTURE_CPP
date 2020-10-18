#include <iostream>
using namespace std;

int** alloc2DInt(int rows, int cols) {
	if (rows <= 0 || cols <= 0) {
		return NULL;
	}
	int** mat = new int* [rows];//포인터 변수를 저장할 배열
	for (int i = 0; i < rows; i++) {
		mat[i] = new int[cols];
	}
	return mat;
}

void free2DInt(int** mat, int rows, int cols = 0) {
	if (mat != NULL) {
		for (int i = 0; i < rows; i++) {
			delete[] mat[i];
		}
		delete[] mat;
	}
}

void set2DRandom(int** mat, int rows, int cols) {
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {
			mat[i][j] = rand() % 100;
		}
	}
}

void print2DInt(int** mat, int rows, int cols) {
	cout << "행의 수 = " << rows << "열의 수= " << cols<<"\n";
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {
			cout << mat[i][j] <<" ";
		}
		cout << "\n";
	}
}

void main() {
	int** mat;
	int rows, cols;

	cout << "행과 열의 크기를 입력하세요.: ";
	cin >> rows >> cols;

	mat = alloc2DInt(rows, cols);
	set2DRandom(mat, rows, cols);
	print2DInt(mat, rows, cols);
	free2DInt(mat, rows, cols);
}