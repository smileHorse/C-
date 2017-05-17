// ato C/-p : 定义控制台应用程序的入口点。
//

#include "stdafx.h"

#include <atomic>
#include <chrono>
#include <iostream>
#include <thread>
#include <vector>

void func(int &counter)
{
	for (int i = 0; i < 100; ++i)
	{
		++counter;
		std::this_thread::sleep_for(std::chrono::milliseconds(1));
	}
}

void atomicFunc(std::atomic<int>& counter)
{
	for (int i = 0; i < 100; i++)
	{
		++counter;
		std::this_thread::sleep_for(std::chrono::milliseconds(1));
	}
}

void atomicFunc2(std::atomic<int>& counter)
{
	int result = 0;
	for (int i = 0; i < 100; ++i)
	{
		++result;
		std::this_thread::sleep_for(std::chrono::milliseconds(1));
	}
	counter += result;
}

void execFunc()
{
	int counter = 0;
	std::vector<std::thread> threads;
	for (int i = 0; i < 10; i++)
	{
		threads.push_back(std::thread{ func, std::ref(counter) });
	}

	for (auto& t : threads)
	{
		t.join();
	}

	std::cout << "Result = " << counter << std::endl;
}

void execAtomicFunc()
{
	std::atomic<int> counter(0);
	std::vector<std::thread> threads;
	for (int i = 0; i < 10; i++)
	{
		threads.push_back(std::thread{ atomicFunc2, std::ref(counter) });
	}

	for (auto& t : threads)
	{
		t.join();
	}

	std::cout << "Result = " << counter << std::endl;
}

int main()
{
	execAtomicFunc();
    return 0;
}
