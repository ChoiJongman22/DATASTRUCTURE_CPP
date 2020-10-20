#include <iostream>
using namespace std;

class Node {
private:
	Node* link;
	int data;
public:
	Node(int d=0): data(d),link(NULL) {}
	~Node() {};
	Node* getlink() { return link;}
	void setLink(Node* p) { link = p; }
	void display() { cout << data; }
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

		for(Node* p=top;p!=NULL;p=p->getlink()){
			p->display();
		}
		cout << "\n";
	}

};

int main(){
	LinkedStack st;
	st.push(new Node(1));
	st.push(new Node(2));
	st.push(new Node(3));
	st.push(new Node(4));
	st.push(new Node(5));
	st.display();
	Node* node = st.pop();
	cout << "ÆËÇ×¸ñ\n";
	node->display();
	cout << endl;
	delete node;
	st.display();
}