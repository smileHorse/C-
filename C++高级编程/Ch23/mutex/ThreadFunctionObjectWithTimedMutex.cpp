#include "stdafx.h"

#include <thread>
#include <iostream>
#include <mutex>
#include <chrono>

using namespace std;

class Counter
{
public:
	Counter(int id, int numIterations)
		: id(id), numIterations(numIterations)
	{}

	void operator()() const
	{
		for (int i = 0; i < numIterations; ++i)
		{
			unique_lock<timed_mutex> lock(mTimedMutex, 200ms);	// C++ 14
			// unique_lock<timed_mutex> lock(mTimedMutex, chrono::milliseconds(200)); // C++ 11
			if (lock)
			{
				cout << "Counter " << id << " has value ";
				cout << i << endl;
			}
			else
			{
				// Lock not acquired in 200ms
			}
		}
	}

private:
	int id;
	int numIterations;
	static timed_mutex mTimedMutex;
};

timed_mutex Counter::mTimedMutex;

int main()
{
	// Using uniform initialization syntax
	thread t1{ Counter{ 1, 20 } };

	// Using named variable
	Counter c(2, 12);
	thread t2(c);

	// Using temporary
	thread t3(Counter(3, 10));

	// wait for threads to finish
	t1.join();
	t2.join();
	t3.join();

	return 0;
};