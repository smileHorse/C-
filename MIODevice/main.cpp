
#include "MFile.h"
#include "MTime.h"

#include <ctime>
#include <iostream>
using namespace std;

int main(int argc, char* argv[])
{
	if (argc < 3)
	{
		cerr << "argc required at least 3 arguments";
		return -1;
	}

	MTime mt;
	mt.start();
	
	char* readFilePath = argv[1];
	cout << "read file path: " << readFilePath << endl;
	MFile readFile(readFilePath);
	if(!readFile.open("r"))
	{
		cout << "open read file failed: " << readFile.getError() << endl;
		return -1;
	}
	CharVector content = readFile.readAll();

	cout << "read file spend time: " << mt.restart() << " ms" << endl;


	char* writeFilePath = argv[2];
	cout << "write file path: " << writeFilePath << endl;
	MFile writeFile(writeFilePath);
	if(!writeFile.open("w"))
	{
		cout << "open write file failed: " << writeFile.getError() << endl;
		return -1;
	}
	writeFile.write(content);

	cout << "write file spend time: " << mt.restart() << " ms" << endl;


	return 0;
}