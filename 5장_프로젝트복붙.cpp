[Location2D.h]

/*

미로 탐색을 위한 2차원 좌표 클래스

*/

struct Location2D

{

    int row; //현재 위치의 행 번호

    int col; //현재 위치의 열 벊호

    Location2D(int r = 0, int c = 0)

    {

        row = r;

        col = c;

    }

    //위치 p가 자신의 이웃인지 검사하는 함수

    bool isNeighbor(Location2D& p)

    {

        return ((row == p.row && (col == p.col - 1 || col == p.col + 1)) || (col == p.col && (row == p.row - 1 || row == p.row + 1)));

    }

    //위치 p가 자신과 같은 위치인지를 검사하는 함수(연산자 오버로딩 사용)

    bool operator==(Location2D& p)

    {

        return row == p.row && col == p.col;

    }

};

[Maze.h]

/*

2차원 배열의 동적 할당과 해제를 이용하여 3.5절에서 소개한 미로 탐색 문제를 다음과 같이 보완하라

(1) 미로 탐색을 위한 클래스 Maze를 구현하라

(2) 다음과 같은 전체 프로그램을 구현하라

*/

#include <iostream>

#include <fstream>

#include "Location2D.h"

#include <stack>

using namespace std;



class Maze

{

private:

    int width; //미로의 너비

    int height; //미로의 높이

    int** map; //미로 맵

    stack<Location2D> locStack; //스택

    Location2D exitLoc; //미로의 출구

public:

    Maze()

    {

        init(0, 0);

    }

    ~Maze()

    {

        reset();

    }

    void init(int w, int h) //map 이차원 배열을 동적으로 할당

    {

        map = new int* [h];

        for (int i = 0; i < h; i++)

            map[i] = new int[w];

    }

    void reset() //미로 맵 maze를 동적으로 해제

    {

        for (int i = 0; i < height; i++)

            delete[]map[i];

        delete[]map;

    }

    void load(char* fname) //파일에서 미로 파일을 읽어옴

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

        if (r < 0 || c < 0 || r >= 20 || c >= 10) //범위를 벗어나면 갈 수 없다

            return false;

        else //비어있는 통로나 도착지점일 때만 true

            return (map[c][r] == 1 || map[c][r] == 9);

    }

    void print() //현재 Maze를 화면에 출력

    {

        cout << "전체 미로의 크기 = " << height << " * " << width << endl;

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

                    cout << "■";

                }

                else if (map[i][j] == 7)

                {

                    cout << "□"; //지나온 경로

                }

                else if (map[i][j] == 5)

                {

                    cout << "○";

                }

                else if (map[i][j] == 9)

                {

                    cout << "◎";

                }

            }

            cout << endl;

        }

        cout << endl;

    }

    void searchExit() //실제 미로를 탐색하는 함수

    {

        while (locStack.empty() == false) //스택이 비어있지 않는 동안

        {

            Location2D here = locStack.top(); //스택에 상단 객체 복사

            locStack.pop();



            int r = here.row;

            int c = here.col;



            map[c][r] = 7; //시작점은 최적 경로

            if (exitLoc.col == c && exitLoc.row == r)

            {

                return;

            }

            else

            {

                map[c][r] = 7; //지나온 곳으로 표기

                //갈 수 있는 곳 다 가본다

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

    Maze maze; //미로 탐색 객체 생성

    maze.load("C:\\Maze.txt");

    maze.print();

    maze.searchExit(); //미로를 탐색해 출구를 찾음

    maze.print();

    return 0;

}













[Maze.h 최적경로 추가 버전]

/*

2차원 배열의 동적 할당과 해제를 이용하여 3.5절에서 소개한 미로 탐색 문제를 다음과 같이 보완하라

(1) 미로 탐색을 위한 클래스 Maze를 구현하라

(2) 다음과 같은 전체 프로그램을 구현하라

*/

#include <iostream>

#include <fstream>

#include "Location2D.h"

#include <stack>

using namespace std;



class Maze

{

private:

    int width; //미로의 너비

    int height; //미로의 높이

    int** map; //미로 맵

    stack<Location2D> locStack; //스택

    stack<Location2D> optimum; //최적경로

    Location2D exitLoc; //미로의 출구

public:

    Maze()

    {

        init(0, 0);

    }

    ~Maze()

    {

        reset();

    }

    void init(int w, int h) //map 이차원 배열을 동적으로 할당

    {

        map = new int* [h];

        for (int i = 0; i < h; i++)

            map[i] = new int[w];

    }

    void reset() //미로 맵 maze를 동적으로 해제

    {

        for (int i = 0; i < height; i++)

            delete[]map[i];

        delete[]map;

    }

    void load(char* fname) //파일에서 미로 파일을 읽어옴

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

                    optimum.push(entry); //최적경로 스택에도 입력

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

        if (r < 0 || c < 0 || r >= 20 || c >= 10) //범위를 벗어나면 갈 수 없다

            return false;

        else //비어있는 통로나 도착지점일 때만 true

            return (map[c][r] == 1 || map[c][r] == 9);

    }

    bool isShortestPath(int r, int c) //최적경로를 사용할 때 쓰이는 함수

    {

        if (r < 0 || c < 0 || r >= 20 || c >= 10) //범위를 벗어나면 갈 수 없다

            return false;

        else

            return (map[c][r] == 7 || map[c][r] == 9); //이미 찾은 경로이거나 출구일때만 true

    }

    void print() //현재 Maze를 화면에 출력

    {

        cout << "전체 미로의 크기 = " << height << " * " << width << endl;

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

                    cout << "■";

                }

                else if (map[i][j] == 3)

                {

                    cout << "☆";

                }

                else if (map[i][j] == 7)

                {

                    cout << "□"; //지나온 경로

                }

                else if (map[i][j] == 5)

                {

                    cout << "○";

                }

                else if (map[i][j] == 9)

                {

                    cout << "◎";

                }

            }

            cout << endl;

        }

        cout << endl;

    }

    void searchExit() //실제 미로를 탐색하는 함수

    {

        while (locStack.empty() == false) //스택이 비어있지 않는 동안

        {

            Location2D here = locStack.top(); //스택에 상단 객체 복사

            locStack.pop();



            int r = here.row;

            int c = here.col;



            map[c][r] = 7; //시작점은 최적 경로

            if (exitLoc.col == c && exitLoc.row == r)

            {

                return;

            }

            else

            {

                map[c][r] = 7; //지나온 곳으로 표기

                                          //갈 수 있는 곳 다 가본다

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

    void ShortestPath() //최적경로

    {

        while (!optimum.empty()) //구조는 searchExit()과 동일

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

                map[c][r] = 3; //지나온 곳으로 표기

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

                    if (!isShortestPath(r + 1, c)) //오른쪽으로 가는 경로가 없을 경우 제외

                        optimum.push(Location2D(r, c - 1));

                }

                if (isShortestPath(r, c + 1))

                {

                    if (!isShortestPath(r + 1, c) && !isShortestPath(r, c - 1)) //오른쪽으로 가는 경로나 위쪽으로 가는 경로 둘 중 하나라도 있을시 제외

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

    Maze maze; //미로 탐색 객체 생성

    maze.load("C:\\Maze.txt");

    maze.print();

    maze.searchExit(); //미로를 탐색해 출구를 찾음

    maze.ShortestPath();

    maze.print();

    return 0;


}



