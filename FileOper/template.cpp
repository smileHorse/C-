
#ifndef USE_CPLUSPLUS

#include <stdio.h>
#include <stdlib.h>

int mainT(int argc, char* argv[])
{

	return EXIT_SUCCESS;
}

#else

#include <iostream>
#include <fstream>
using namespace std;

int main(int argc, char* argv[])
{

	return EXIT_SUCCESS;
}

#endif