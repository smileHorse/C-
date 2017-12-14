#include <iostream>
#include <fstream>
using namespace std;

#define TRACEON
#include "Trace.h"

int main()
{
	ifstream f("Tracetest.cpp");

	cout << f.rdbuf();
}