
#include <iostream>
#include "LiftOff.h"
#include "zthread/Thread.h"
using namespace ZThread;
using namespace std;

//int main() 
//{
//	try {
//		Thread t(new LiftOff(10));
//		cout << "Waiting for LiftOff" << endl;
//	}
//	catch(Synchronization_Exception& e) {
//		cerr << e.what() << endl;
//	}
//	return 0;
//}