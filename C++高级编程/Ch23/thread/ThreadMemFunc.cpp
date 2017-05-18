#include "stdafx.h"

#include <iostream>
#include <thread>

using namespace std;

class Request
{
public:
	Request(int id) : id(id)
	{}

	void process()
	{
		cout << "Processing request " << id << endl;
	}

private:
	int id;
};

int main()
{
	Request req(100);
	thread t(&Request::process, &req);

	t.join();

	return 0;
};