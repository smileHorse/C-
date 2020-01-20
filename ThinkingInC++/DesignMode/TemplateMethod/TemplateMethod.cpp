#include <iostream>
using namespace std;

class ApplicationFramework {
protected:
	virtual void customize1() = 0;
	virtual void customize2() = 0;
public:
	void templateMethod() {
		for (int i = 0; i < 5; ++i){
			customize1();
			customize2();
		}
	}
};

// Create a new Application
class MyApp : public ApplicationFramework {
protected:
	virtual void customize1() { cout << "Hello "; }
	virtual void customize2() { cout << "World!" << endl; }
};

int main() {
	MyApp app;
	app.templateMethod();
}