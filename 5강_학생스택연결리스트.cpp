#include <iostream>
using namespace std;

class Student {
private:
	int id;
	string name;
	string dept;

public:
	Student(int i=0, string n="", string d="") :
		id(i),name(n),dept(d){}

	void display() {
		cout << "학번: " << id << "학생이름: " << name << "학과이름: " << dept << endl;
	}
};


class Node: public Student {
private:
	Node* link;
	
public:
	Node(int id = 0, string name = "", string dept = "") : Student(id, name, dept) { link = NULL; }
	~Node() {};
	Node* getlink() { return link; }
	void setLink(Node* p) { link = p; }
	
};



class LinkedStack {
private:
	Node* top;
public:
	LinkedStack() { top = NULL; }
	~LinkedStack() { while (isEmpty())delete pop(); }

	bool isEmpty() {
		return top == NULL;
	}
	void push(Node* p) {
		if (isEmpty())top = p;
		else {
			p->setLink(top);
			top = p;
		}
	}

	Node* pop() {
		if (isEmpty())return NULL;
		Node* p = top;
		top = top->getlink();
		return p;
	}
	void display() {
		cout << "[LinkedStack]" << endl;

		for (Node* p = top; p != NULL; p = p->getlink()) {
			p->display();
		}
		cout << "\n";
	}

};

int main() {
	LinkedStack st;
	st.push(new Node(2015, "최종헌", "글로벌미디어학부"));
	st.push(new Node(2015, "김영준", "글로벌미디어학부"));
	st.push(new Node(2016, "박준형", "글로벌미디어학부"));
	st.push(new Node(2017, "정승훈", "글로벌미디어학부"));
	st.display();
	Node* node = st.pop();
	cout << "팝항목\n";
	node->display();
	cout << endl;
	delete node;
	st.display();





}