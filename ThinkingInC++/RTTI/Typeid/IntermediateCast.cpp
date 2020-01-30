#include <cassert>
#include <iostream>
using namespace std;

class B1 { public: virtual ~B1() {} };
class B2 { public: virtual ~B2() {} };

class MI : public B1, public B2 {};
class MI2 : public MI {};

//int main() {
//	B2* b2 = new MI2;
//	MI2* mi2 = dynamic_cast<MI2*>(b2);
//	MI* mi = dynamic_cast<MI*>(b2);
//	B1* b1 = dynamic_cast<B1*>(b2);
//	assert(typeid(b2) != typeid(MI2*));
//	assert(typeid(b2) == typeid(B2*));
//	delete b2;
//}