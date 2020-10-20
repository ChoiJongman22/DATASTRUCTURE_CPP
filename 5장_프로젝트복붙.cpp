[Location2D.h]

/*

�̷� Ž���� ���� 2���� ��ǥ Ŭ����

*/

struct Location2D

{

    int row; //���� ��ġ�� �� ��ȣ

    int col; //���� ��ġ�� �� ��ȣ

    Location2D(int r = 0, int c = 0)

    {

        row = r;

        col = c;

    }

    //��ġ p�� �ڽ��� �̿����� �˻��ϴ� �Լ�

    bool isNeighbor(Location2D& p)

    {

        return ((row == p.row && (col == p.col - 1 || col == p.col + 1)) || (col == p.col && (row == p.row - 1 || row == p.row + 1)));

    }

    //��ġ p�� �ڽŰ� ���� ��ġ������ �˻��ϴ� �Լ�(������ �����ε� ���)

    bool operator==(Location2D& p)

    {

        return row == p.row && col == p.col;

    }

};

[Maze.h]

/*

2���� �迭�� ���� �Ҵ�� ������ �̿��Ͽ� 3.5������ �Ұ��� �̷� Ž�� ������ ������ ���� �����϶�

(1) �̷� Ž���� ���� Ŭ���� Maze�� �����϶�

(2) ������ ���� ��ü ���α׷��� �����϶�

*/

#include <iostream>

#include <fstream>

#include "Location2D.h"

#include <stack>

using namespace std;



class Maze

{

private:

    int width; //�̷��� �ʺ�

    int height; //�̷��� ����

    int** map; //�̷� ��

    stack<Location2D> locStack; //����

    Location2D exitLoc; //�̷��� �ⱸ

public:

    Maze()

    {

        init(0, 0);

    }

    ~Maze()

    {

        reset();

    }

    void init(int w, int h) //map ������ �迭�� �������� �Ҵ�

    {

        map = new int* [h];

        for (int i = 0; i < h; i++)

            map[i] = new int[w];

    }

    void reset() //�̷� �� maze�� �������� ����

    {

        for (int i = 0; i < height; i++)

            delete[]map[i];

        delete[]map;

    }

    void load(char* fname) //���Ͽ��� �̷� ������ �о��

    {

        ifstream fin(fname, ios::in);



        fin >> width >> height;

        init(width, height);

        int temp;



        for (int i = 0; i < height; i++)

        {

            for (int j = 0; j < width; j++)

            {

                fin >> temp;

                map[i][j] = temp;

                if (map[i][j] == 5)

                {

                    Location2D entry(j, i);

                    locStack.push(entry);

                }

                else if (map[i][j] == 9)

                {

                    exitLoc.col = i;

                    exitLoc.row = j;

                }

            }

            cout << endl;

        }

        fin.close();

    }

    bool isValidLoc(int r, int c)

    {

        if (r < 0 || c < 0 || r >= 20 || c >= 10) //������ ����� �� �� ����

            return false;

        else //����ִ� ��γ� ���������� ���� true

            return (map[c][r] == 1 || map[c][r] == 9);

    }

    void print() //���� Maze�� ȭ�鿡 ���

    {

        cout << "��ü �̷��� ũ�� = " << height << " * " << width << endl;

        for (int i = 0; i < height; i++)

        {

            for (int j = 0; j < width; j++)

            {

                if (map[i][j] == 1)

                {

                    cout << "  ";

                }

                else if (map[i][j] == 0)

                {

                    cout << "��";

                }

                else if (map[i][j] == 7)

                {

                    cout << "��"; //������ ���

                }

                else if (map[i][j] == 5)

                {

                    cout << "��";

                }

                else if (map[i][j] == 9)

                {

                    cout << "��";

                }

            }

            cout << endl;

        }

        cout << endl;

    }

    void searchExit() //���� �̷θ� Ž���ϴ� �Լ�

    {

        while (locStack.empty() == false) //������ ������� �ʴ� ����

        {

            Location2D here = locStack.top(); //���ÿ� ��� ��ü ����

            locStack.pop();



            int r = here.row;

            int c = here.col;



            map[c][r] = 7; //�������� ���� ���

            if (exitLoc.col == c && exitLoc.row == r)

            {

                return;

            }

            else

            {

                map[c][r] = 7; //������ ������ ǥ��

                //�� �� �ִ� �� �� ������

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

[MazeMain.cpp]

#include "Maze.h"



int main(void)

{

    Maze maze; //�̷� Ž�� ��ü ����

    maze.load("C:\\Maze.txt");

    maze.print();

    maze.searchExit(); //�̷θ� Ž���� �ⱸ�� ã��

    maze.print();

    return 0;

}













[Maze.h ������� �߰� ����]

/*

2���� �迭�� ���� �Ҵ�� ������ �̿��Ͽ� 3.5������ �Ұ��� �̷� Ž�� ������ ������ ���� �����϶�

(1) �̷� Ž���� ���� Ŭ���� Maze�� �����϶�

(2) ������ ���� ��ü ���α׷��� �����϶�

*/

#include <iostream>

#include <fstream>

#include "Location2D.h"

#include <stack>

using namespace std;



class Maze

{

private:

    int width; //�̷��� �ʺ�

    int height; //�̷��� ����

    int** map; //�̷� ��

    stack<Location2D> locStack; //����

    stack<Location2D> optimum; //�������

    Location2D exitLoc; //�̷��� �ⱸ

public:

    Maze()

    {

        init(0, 0);

    }

    ~Maze()

    {

        reset();

    }

    void init(int w, int h) //map ������ �迭�� �������� �Ҵ�

    {

        map = new int* [h];

        for (int i = 0; i < h; i++)

            map[i] = new int[w];

    }

    void reset() //�̷� �� maze�� �������� ����

    {

        for (int i = 0; i < height; i++)

            delete[]map[i];

        delete[]map;

    }

    void load(char* fname) //���Ͽ��� �̷� ������ �о��

    {

        ifstream fin(fname, ios::in);



        fin >> width >> height;

        init(width, height);

        int temp;



        for (int i = 0; i < height; i++)

        {

            for (int j = 0; j < width; j++)

            {

                fin >> temp;

                map[i][j] = temp;

                if (map[i][j] == 5)

                {

                    Location2D entry(j, i);

                    locStack.push(entry);

                    optimum.push(entry); //������� ���ÿ��� �Է�

                }

                else if (map[i][j] == 9)

                {

                    exitLoc.col = i;

                    exitLoc.row = j;

                }

            }

            cout << endl;

        }

        fin.close();

    }

    bool isValidLoc(int r, int c)

    {

        if (r < 0 || c < 0 || r >= 20 || c >= 10) //������ ����� �� �� ����

            return false;

        else //����ִ� ��γ� ���������� ���� true

            return (map[c][r] == 1 || map[c][r] == 9);

    }

    bool isShortestPath(int r, int c) //������θ� ����� �� ���̴� �Լ�

    {

        if (r < 0 || c < 0 || r >= 20 || c >= 10) //������ ����� �� �� ����

            return false;

        else

            return (map[c][r] == 7 || map[c][r] == 9); //�̹� ã�� ����̰ų� �ⱸ�϶��� true

    }

    void print() //���� Maze�� ȭ�鿡 ���

    {

        cout << "��ü �̷��� ũ�� = " << height << " * " << width << endl;

        for (int i = 0; i < height; i++)

        {

            for (int j = 0; j < width; j++)

            {

                if (map[i][j] == 1)

                {

                    cout << "  ";

                }

                else if (map[i][j] == 0)

                {

                    cout << "��";

                }

                else if (map[i][j] == 3)

                {

                    cout << "��";

                }

                else if (map[i][j] == 7)

                {

                    cout << "��"; //������ ���

                }

                else if (map[i][j] == 5)

                {

                    cout << "��";

                }

                else if (map[i][j] == 9)

                {

                    cout << "��";

                }

            }

            cout << endl;

        }

        cout << endl;

    }

    void searchExit() //���� �̷θ� Ž���ϴ� �Լ�

    {

        while (locStack.empty() == false) //������ ������� �ʴ� ����

        {

            Location2D here = locStack.top(); //���ÿ� ��� ��ü ����

            locStack.pop();



            int r = here.row;

            int c = here.col;



            map[c][r] = 7; //�������� ���� ���

            if (exitLoc.col == c && exitLoc.row == r)

            {

                return;

            }

            else

            {

                map[c][r] = 7; //������ ������ ǥ��

                                          //�� �� �ִ� �� �� ������

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

    void ShortestPath() //�������

    {

        while (!optimum.empty()) //������ searchExit()�� ����

        {

            Location2D here = optimum.top();

            optimum.pop();



            int r = here.row;

            int c = here.col;



            map[c][r] = 3;

            if (exitLoc.col == c && exitLoc.row == r)

            {

                return;

            }

            else

            {

                map[c][r] = 3; //������ ������ ǥ��

                if (isShortestPath(r - 1, c))

                {

                    optimum.push(Location2D(r - 1, c));

                }

                if (isShortestPath(r + 1, c))

                {

                    optimum.push(Location2D(r + 1, c));

                }

                if (isShortestPath(r, c - 1))

                {

                    if (!isShortestPath(r + 1, c)) //���������� ���� ��ΰ� ���� ��� ����

                        optimum.push(Location2D(r, c - 1));

                }

                if (isShortestPath(r, c + 1))

                {

                    if (!isShortestPath(r + 1, c) && !isShortestPath(r, c - 1)) //���������� ���� ��γ� �������� ���� ��� �� �� �ϳ��� ������ ����

                        optimum.push(Location2D(r, c + 1));

                }

            }

        }

    }


};



[MazeMain.cpp]

#include "Maze.h"



int main(void)

{

    Maze maze; //�̷� Ž�� ��ü ����

    maze.load("C:\\Maze.txt");

    maze.print();

    maze.searchExit(); //�̷θ� Ž���� �ⱸ�� ã��

    maze.ShortestPath();

    maze.print();

    return 0;


}



