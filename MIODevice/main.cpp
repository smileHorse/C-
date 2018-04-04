
#include "MFile.h"
#include "MTime.h"

#include <boost/timer.hpp>
#include <ctime>
#include <iostream>

using namespace boost;
using namespace std;

int main(int argc, char* argv[])
{
	if (argc < 3)
	{
		cerr << "argv required at least 3 arguments";
		return -1;
	}
	
	timer mt;

	char* readFilePath = argv[1];
	cout << "read file path: " << readFilePath << endl;
	MFile readFile(readFilePath);
	if(!readFile.open("rb"))
	{
		cout << "open read file failed: " << readFile.getError() << endl;
		return -1;
	}
	CharVector content = readFile.readAll();

	cout << "read file spend time: " << mt.elapsed() << " s" << endl;

	mt.restart();
	char* writeFilePath = argv[2];
	cout << "write file path: " << writeFilePath << endl;
	MFile writeFile(writeFilePath);
	if(!writeFile.open("wb"))
	{
		cout << "open write file failed: " << writeFile.getError() << endl;
		return -1;
	}
	writeFile.write(content);

	cout << "write file spend time: " << mt.elapsed() << " s" << endl;


	return 0;
}