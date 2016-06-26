#include <iostream>

using namespace std;

class B {
public:
	int b;
	B(int b_) {
		cout<<"B(int b) called..\n";
		b = b_;
	}
	B() {
		cout<<"B() called..\n";
	}
};

class C {
public:
	int c;
	C(int c_) {
		cout<<"C(int c) called..\n";
		c = c_;
	}
	C() {
		cout<<"C() called..\n";
	}
};

class A {
public:
	B b_obj;
	C c_obj;
	int y;
	A() : c_obj(2), b_obj(3), y(7){
		/*(b_obj_).b_ = 2;
		(c_obj_).c_ = 3;*/
	}
	void show() {
		cout<<b_obj.b<<c_obj.c<<y;
	}
};

int main() {
	A a_obj;
	a_obj.show();
	return 0;
}