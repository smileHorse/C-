// thread.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"

#include <iostream>
#include <thread>

using namespace std;

void counter(int id, int numIterations)
{
	for (int i = 0; i < numIterations; ++i)
	{
		cout << "Counter " << id << " has value ";
		cout << i << endl;
	}
}

int main()
{
	thread t1(counter, 1, 6);
	thread t2(coutner, 2, 4);
	t1.join();
	t2.join();

	return 0;
}

