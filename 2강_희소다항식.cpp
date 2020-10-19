#include <iostream>
#include <string>
#define MAX 80
using namespace std;


struct Term {
    int expn;//항의 지수
    float coef;//항의 계수
};

void sortPoly(Term term[], int nTerms) {
    for (int i = 0; i < nTerms; i++) {
        for (int j = i; j < nTerms; j++) {
            if (term[i].expn < term[j].expn) {
                Term temp = term[i];
                term[i] = term[j];
                term[j] = temp;
            }
        }
    }
}

class SparsePoly {
private:
    int nTerms;//계수가 0이 아닌 항의 개수
    Term term[MAX];//계수가 0이 아닌 항의 배열

public:
    SparsePoly() {}
    void read() {
        cout << "계수가 0이 아닌 항의 개수: ";
        cin >> nTerms;
        for (int i = 0; i < nTerms; i++) {
            struct Term temp;
            cout << i + 1 << "번째 항의 계수와 지수 입력";
            cin >> temp.coef >> temp.expn;
            term[i] = temp;
        }
    }

    void add(SparsePoly a, SparsePoly b) {
        int count = 0, bcount = 0;
        int start = 0;
        struct Term add;//더하기용 구조체
        *this = a;
        nTerms += b.nTerms; //두항을 더해(일단은)
        cout << nTerms << endl;
        cout << a.nTerms << endl;
        Term* temp = new Term[a.nTerms];//기존에 a에 있던 요소들을 저장할 배열
        for (int i = 0; i < a.nTerms; i++) {
            temp[i] = a.term[i];
        }
        while (count < nTerms && bcount < b.nTerms) {
            if (temp[count].expn == b.term[bcount].expn) {
                add.coef = temp[count].coef + b.term[bcount].coef;
                add.expn = temp[count].expn;
                term[start++] = add;
                count++;
                bcount++;
                nTerms--;
            }

            else if (temp[count].expn > b.term[bcount].expn) {
                term[start++] = temp[count];
                count++;
            }
            else {
                term[start++] = b.term[bcount];
                bcount++;
            }
        }
        for (; count < nTerms; count++) {
            term[start++] = temp[count];
        }
        for (; bcount < b.nTerms; bcount++) {
            term[start++] = b.term[bcount];
        }
        delete[] temp;
    }

    void display(string str = "Spoly= ") {
        sortPoly(term, nTerms);
        for (int i = 0; i < nTerms; i++) {
            cout << term[i].coef;
            if (term[i].expn) {
                cout << "x^(" << term[i].expn << ")";
            }
            if (i != nTerms - 1) {
                cout << " + ";
            }
        }
        cout << "\n";
    }
};


int main(void)
{
    SparsePoly sp1, sp2, sp3;
    sp1.read();
    cout << "첫번째 희소다항식 출력: ";
    sp1.display();
    sp2.read();
    cout << "두번째 희소다항식 출력: ";
    sp2.display();
    sp3.add(sp1, sp2);
    cout << "두 희소다항식의 합: ";
    sp3.display();
    return 0;

}

