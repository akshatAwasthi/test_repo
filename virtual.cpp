
phonegap cordova create hello com.eaxmple.hello HelloWorld

#include <iostream>

using namespace std;

class base {
public:
	
	base() {
		cout<<"base constructor called..\n";
	}
	
	virtual ~base() {
		cout<<"base destructor called..\n";
	}
};

class derived : public base {
public:
	
	derived() {
		cout<<"derived class constructor called..\n";
	}
	
	~derived() {
		cout<<"derived class destructor called..\n";
	}
};

int main() {

	base *p = new derived();

	delete p;
	
	return 0;
}
