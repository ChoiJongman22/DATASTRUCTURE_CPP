#include <iostream>
#include <fstream>
#include <stack>
using namespace std;

struct Location2D {
	int row;
	int col;
	Location2D(int r = 0, int c = 0) {
		row = r;
		col = c;
	}

	bool isNeighbor(Location2D& p) {
		return((row == p.row && (col == p.col - 1 || col == p.col + 1)) || (col == p.col && (row == p.row - 1 || row == p.row + 1)));
	}

	bool operator==(Location2D& p) {
		return row == p.row && col == p.col;
	}
};

class Maze {
private:
	int width;
	int height;
	int** map;
	stack<Location2D> locStack;
	Location2D exitLoc;
public:
	Maze() {
		init(0, 0);
	}
	~Maze() {
		reset();
	}

	void init(int w, int h) {
		map = new int* [h];
		for (int i = 0; i < h; i++) {
			map[i] = new int[w];
		}
	}
	void reset() {//메모리 해제
		for (int i = 0; i < height; i++) {
			delete[] map[i];
		}
		delete[] map;
	}
	void load(char* fname) {
		ifstream fin(fname, ios::in);

		fin >> width >> height;
		init(width, height);
		int temp;

		for (int i = 0; i < height; i++) {
			for (int j = 0; j < width; j++) {
				fin >> temp;
				map[i][j] = temp;
				if (map[i][j] == 5){
					Location2D entry(j, i);
					locStack.push(entry);
				}
				else if (map[i][j] == 9) {
					exitLoc.col = i;
					exitLoc.row = j;
				}
			}
			cout << endl;
		}
		fin.close();
	}
	bool isValidLoc(int r, int c) {
		if (r < 0 || c < 0 || r >= 20 || c >= 10) {
			return false;
		}
		else {
			return (map[c][r] == 1 || map[c][r] == 9);
		}
	}
	void print() {
		cout << "전체 미로의 크기: " << height << " " << width << endl;

		for (int i = 0; i < height; i++) {
			for (int j = 0; j < width; j++) {
				if (map[i][j] == 1) {
					cout << " ";
				}
				else if (map[i][j] == 0) {
					cout<< "■";
				}
				else if (map[i][j] == 7) {
					cout << "□";
				}
				else if (map[i][j] == 5) {
					cout << "○";
				}
				else if (map[i][j] == 9) {
					cout << "◎";
				}
			}
			cout << endl;
		}
		cout << endl;
	}

	void searchExit() {
		while (locStack.empty() == false) {
			Location2D here = locStack.top();
			locStack.pop();
			int r = here.row;
			int c = here.col;
			map[c][r] = 7;
			if (exitLoc.col == c && exitLoc.row == r) {
				return;
			}
			else {
				if (isValidLoc(r - 1, c))

				{

					locStack.push(Location2D(r - 1, c));

				}

				if (isValidLoc(r + 1, c))

				{

					locStack.push(Location2D(r + 1, c));

				}

				if (isValidLoc(r, c - 1))

				{

					locStack.push(Location2D(r, c - 1));

				}

				if (isValidLoc(r, c + 1))
				{
					locStack.push(Location2D(r, c + 1));
				}
			}
		}
	}
};

int main() {
	Maze maze; //미로 탐색 객체 생성

	maze.load("MAZE.txt");

	maze.print();

	maze.searchExit(); //미로를 탐색해 출구를 찾음

	maze.print();

	return 0;
}