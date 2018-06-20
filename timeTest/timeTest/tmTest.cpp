#include <ctime>
#include <iostream>
#include <string>

using namespace std;

void outputTM(tm* time)
{
	const string DATE_SEPARATOR = "-";
	const string TIME_SEPARATOR = ":";
	cout << time->tm_year + 1900 << DATE_SEPARATOR
		<< time->tm_mon + 1 << DATE_SEPARATOR
		<< time->tm_mday << " "
		<< time->tm_hour << TIME_SEPARATOR
		<< time->tm_min << TIME_SEPARATOR
		<< time->tm_sec << endl;
}

int main()
{
	time_t tTime = time(NULL);
	cout << "current time: " << tTime << endl;

	tm* localTime = localtime(&tTime);
	cout << "localTime: ";
	outputTM(localTime);

	tm* gmTime = gmtime(&tTime);
	cout << "gmTime: ";
	outputTM(gmTime);

	return 0;
}