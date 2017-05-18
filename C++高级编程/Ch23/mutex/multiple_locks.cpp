// mutex.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"

#include <mutex>

using namespace std;

mutex mut1;
mutex mut2;

void process()
{
	unique_mutex<mutex> lock1(mut1, defer_lock_t());
	unique_mutex<mutex> lock2(mut2, defer_lock_t());
	lock(lock1, lock2);
}

int main()
{
	process();

	return 0;
}

