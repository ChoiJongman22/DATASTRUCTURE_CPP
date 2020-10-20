#include <iostream>
using namespace std;


int** Create_Matrix(int row, int column) {

	if (row <= 0 || column <= 0) return NULL;
	int** mat = new int* [row];
	for (int i = 0; i < row; i++) {
		mat[i] = new int[column];
	}

	for (int i = 0; i < row; i++) {
		for (int j = 0; j < column; j++) {
			mat[i][j] = rand() % 10;
		}
	}
	return mat;
}
int** Display_Matrix(int** A, int row, int column) {

	for (int i = 0; i < row; i++) {
		for (int j = 0; j < column; j++) {

			cout << A[i][j] << " ";
		}
		cout << endl;
	}
	return A;
}

int** Multiplication(int** &A, int** &B, int** &C, int& row_A, int& col_A, int& col_B) {
	if (row_A != col_B) {
		cout << "행렬곱의 정의에 어긋납니다." << endl;
	}
	else {
		for (int i = 0; i < row_A; i++) {
			for (int j = 0; i < col_A; j++) {
				for (int u = 0; u < col_B; u++) {
					C[i][j] += A[i][u] * B[u][j];
				}
			}
		}
	}
	return C;
}
void main() {
	int row_A, column_A;
	int row_B, column_B;

	while (1) {

		cout << "행렬A의 row와 column을 입력하세요." << endl;
		cin >> row_A >> column_A;
		cout << endl;


		cout << "행렬B의 row와 column을 입력하세요." << endl;
		cin >> row_B >> column_B;
		cout << endl;
		if (column_A != row_B) {
			cout << "행렬곱의 정의에 어긋납니다." << endl << endl;
			continue;
		}
		else {
			int** C = new int* [row_A];
			for (int i = 0; i < row_A; i++) {
				C[i] = new int[column_B];
				for (int j = 0; j < column_B; j++) {
					C[i][j] = 0;
				}
			}
			
			int** A = Create_Matrix(row_A, column_A);
			cout << "행렬 A= " << endl;
			Display_Matrix(A, row_A, column_A);
			cout << endl;
			int** B = Create_Matrix(row_B, column_B);
			cout << "행렬 B= " << endl;
			Display_Matrix(B, row_B, column_B);
			cout << "A*B = " << endl;
			C = Multiplication(A, B, C, row_A, column_A, column_B);
			Display_Matrix(C, row_A, column_B);
			break;
		}
	}
}