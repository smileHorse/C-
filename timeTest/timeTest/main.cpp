
#include <ctime>
#include <iostream>
#include <math.h>
#include <windows.h>

using namespace std;

DWORD WINAPI thread1(LPVOID lpParam) {
	cout << endl;

	time_t timeT = time(NULL);
	//tm* pTm = localtime(&timeT);

	tm* pTm = new tm;
	localtime_s(pTm, &timeT);

	timeT += 2000;
	localtime_s(pTm, &timeT);
	
	char buffer[1024] = { 0 };


	strftime(buffer, 1024, "%Y-%m-%d %H:%M:%S", pTm);
	cout << "thread1 " << buffer << endl;

	return 0;
}

DWORD WINAPI thread2(LPVOID lpParam) {
	cout << endl;
	
	time_t timeT = time(NULL);
	//tm* pTm = localtime(&timeT);

	tm* pTm = new tm;
	localtime_s(pTm, &timeT);

	char buffer[1024] = { 0 };
	strftime(buffer, 1024, "%Y-%m-%d %H:%M:%S", pTm);
	cout << "thread2 " << buffer << endl;

	return 0;
}

//int main()
//{
//	DWORD id1;
//	CreateThread(NULL, 0, thread1, 0, 0, &id1);
//	
//	DWORD id2;
//	CreateThread(NULL, 0, thread2, 0, 0, &id2);
//
//	while(true) {
//
//	}
//	return 0;
//}