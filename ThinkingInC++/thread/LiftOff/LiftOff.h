#ifndef LIFTOFF_H
#define LIFTOFF_H

#include <iostream>
#include "zthread/Runnable.h"

class LiftOff : public ZThread::Runnable
{
	int countDown;
	int id;

public:
	LiftOff(int count, int ident = 0)
		: countDown(count), id(ident)
	{}

	~LiftOff()
	{
		std::cout << id << " completed" << std::endl;
	}

	void run() 
	{
		while (countDown--)
		{
			std::cout << id << ":" << countDown << std::endl;
		}
		std::cout << "LiftOff!" << std::endl;
	}
};
#endif