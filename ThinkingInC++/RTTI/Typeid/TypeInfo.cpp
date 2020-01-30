#include <iostream>
#include <typeinfo>
using namespace std;

struct PolyBase { virtual ~PolyBase() {} };
struct PolyDer : public PolyBase { PolyDer() {} };
struct NonPolyBase {};
struct NonPolyDer : public NonPolyBase { NonPolyDer(int) {} };

//int main() {
//	// Test polymorphic Types
//	const PolyDer pd;
//	const PolyBase* ppb = &pd;
//	cout << typeid(ppb).name() << endl;
//	cout << typeid(*ppb).name() << endl;
//	cout << boolalpha << (typeid(*ppb) == typeid(pd)) << endl;
//	cout << (typeid(PolyDer) == typeid(const PolyDer)) << endl;
//
//	// Test non-polymorphic Types
//	const NonPolyDer npd(1);
//	const NonPolyBase* nppb = &npd;
//	cout << typeid(nppb).name() << endl;
//	cout << typeid(*nppb).name() << endl;
//	cout << (typeid(*nppb) == typeid(npd)) << endl;
//
//	// Test a built-in type
//	int i;
//	cout << typeid(i).name() << endl;
//
//	int* ptr = new int(1);
//	cout << typeid(*ptr).name() << endl;
//	delete ptr;
//	ptr = NULL;
//	cout << typeid(ptr).name() << endl;
//	cout << typeid(*ptr).name() << endl;
//};