#include <iostream>
#include <string>
#define MAX 80
using namespace std;


struct Term {
    int expn;//���� ����
    float coef;//���� ���
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
    int nTerms;//����� 0�� �ƴ� ���� ����
    Term term[MAX];//����� 0�� �ƴ� ���� �迭

public:
    SparsePoly() {}
    void read() {
        cout << "����� 0�� �ƴ� ���� ����: ";
        cin >> nTerms;
        for (int i = 0; i < nTerms; i++) {
            struct Term temp;
            cout << i + 1 << "��° ���� ����� ���� �Է�";
            cin >> temp.coef >> temp.expn;
            term[i] = temp;
        }
    }

    void add(SparsePoly a, SparsePoly b) {
        int count = 0, bcount = 0;
        int start = 0;
        struct Term add;//���ϱ�� ����ü
        *this = a;
        nTerms += b.nTerms; //������ ����(�ϴ���)
        cout << nTerms << endl;
        cout << a.nTerms << endl;
        Term* temp = new Term[a.nTerms];//������ a�� �ִ� ��ҵ��� ������ �迭
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
    cout << "ù��° ��Ҵ��׽� ���: ";
    sp1.display();
    sp2.read();
    cout << "�ι�° ��Ҵ��׽� ���: ";
    sp2.display();
    sp3.add(sp1, sp2);
    cout << "�� ��Ҵ��׽��� ��: ";
    sp3.display();
    return 0;

}

