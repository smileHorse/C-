#include <iostream>
#include "zthread/ThreadedExecutor.h"
#include "LiftOff.h"
using namespace ZThread;
using namespace std;

//int main() {
//	try {
//		ThreadedExecutor executor;
//		for (int i = 0; i < 5; ++i)
//		{
//			executor.execute(new LiftOff(10, i));
//		}
//	} catch(Synchronization_Exception& e) {
//		cerr << e.what() << endl;
//	}
//}