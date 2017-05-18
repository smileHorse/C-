
#include "stdafx.h"

#include <iostream>
#include <thread>

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
			cout << "Counter " << id << " has value ";
			cout << i << endl;
		}
	}

private:
	int id;
	int numIterations;
};

int main()
{
	// Using uniform initialization syntax
	thread t1{ Counter{ 1, 20} };

	// Using named variable
	Counter c(2, 12);
	thread t2(c);

	// using temporary
	thread t3(Counter(3, 10));

	// wait for threads to finish
	t1.join();
	t2.join();
	t3.join();

	return 0;
};