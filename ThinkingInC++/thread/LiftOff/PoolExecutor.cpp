#include <iostream>
#include "zthread/PoolExecutor.h"
#include "LiftOff.h"
using namespace ZThread;
using namespace std;

//int main() {
//	try {
//		PoolExecutor executor(5);
//		for (int i = 0; i < 5; ++i)
//		{
//			executor.execute(new LiftOff(10, i));
//		}
//	} catch(Synchronization_Exception& e) {
//		cerr << e.what() << endl;
//	}
//}