#include <iostream>
#include "EvenChecker.h"
#include "zthread/ThreadedExecutor.h"
using namespace ZThread;
using namespace std;

//class EvenGenerator : public Generator {
//	unsigned int currentEvenValue;
//public:
//	EvenGenerator() { currentEvenValue = 0; }
//	~EvenGenerator() { cout << "~EvenGenerator" << endl; }
//	int nextValue() {
//		++currentEvenValue;
//		++currentEvenValue;
//		return currentEvenValue;
//	}
//};
//
//int main() {
//	EvenChecker::test<EvenGenerator>();
//}