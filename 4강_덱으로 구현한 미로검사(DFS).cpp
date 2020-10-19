#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <deque>
#define MAZE_MAX 6
using namespace std;

struct Location2D {
	int row;
	int col;
	Location2D(int r = 0, int c = 0) {
		row = r;
		col = c;
	}

	bool isNeighbor(Location2D& p) {
		return(((row == p.row && (col == p.col - 1 || col == p.col + 1))) ||
			(col == p.col && (row == p.row - 1 || row == p.row + 1)));
	}
	bool operator==(Location2D& p) {
		return row == p.row && col == p.col;
	}
};

char map[MAZE_MAX][MAZE_MAX] = {
	{'1','1','1','1','1','1'},
	{'e','0','1','0','0','1'},
	{'1','0','0','0','1','1'},
	{'1','0','1','0','1','1'},
	{'1','0','1','0','0','x'},
	{'1','1','1','1','1','1'}
};


bool isValidLoc(int r, int c) {
	if (r < 0 || c < 0 || r >= MAZE_MAX || c >= MAZE_MAX) {
		return false;
	}
	else {
		return map[r][c] == '0' || map[r][c] == 'x';
	}
}

void main() {
	deque<Location2D> locDeque;
	Location2D entry(1, 0);
	locDeque.push_front(entry);

	while (locDeque.empty() == false) {
		Location2D here = locDeque.front();
		locDeque.pop_front();
		int r = here.row;
		int c = here.col;
		cout << "(" << r << ", " << c << ") ";

		if (map[r][c] == 'x') {
			cout << "¹Ì·ÎÅ½»ö¼º°ø" << "\n";
			return;
		}
		else {
			map[r][c] = '.';
			if (isValidLoc(r - 1, c))locDeque.push_front(Location2D(r - 1, c));//»ó
			if (isValidLoc(r + 1, c))locDeque.push_front(Location2D(r + 1, c));//ÇÏ
			if (isValidLoc(r, c - 1))locDeque.push_front(Location2D(r, c - 1));//ÁÂ
			if (isValidLoc(r, c + 1))locDeque.push_front(Location2D(r, c + 1));//¿ì
		}
	}
	cout << "¹Ì·ÎÅ½»ö½ÇÆÐ" << "\n";
}