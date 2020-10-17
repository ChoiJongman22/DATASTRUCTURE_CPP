#include <iostream>
#include <string>
using namespace std;

class Car {
protected:
	int speed;
	string name;
public:
	int gear;
	Car() {}//기본생성자
	~Car() {}
	Car(int s, int g, string n) :
		speed(s), gear(g), name(n){}
	
	void changeGear(int g = 4) {
		gear = g;
	}
	void SpeedUp() {
		speed += 5;
	}
	void display() {
		cout << name << ", " << gear << ", " << speed;

	}
	void whereAmI() {
		cout << this;
	}
};

int main() {
	Car c;
	c.changeGear(4);
	c.SpeedUp();
	c.display();
	c.whereAmI();
}