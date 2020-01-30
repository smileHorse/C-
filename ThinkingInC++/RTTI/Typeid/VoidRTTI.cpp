#include <iostream>
#include <typeinfo>
using namespace std;

class Stimpy {
public:
	virtual void happy() {}
	virtual void joy() {}
	virtual ~Stimpy() {}
};

//int main() {
//	void* v = new Stimpy;
//	// Error
//	// Stimpy* s = dynamic_cast<Stimpy*>(v);
//	// Error
//	// cout << typeid(*v).name() << endl;
//}