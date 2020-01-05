#include "test.h"
#include <QtWidgets/QApplication>

#include <string>
#include <vector>
using namespace std;

struct TestData 
{
	int id;
	string name;
	string desc;
};

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);

	vector<TestData> datas;
	for (int i = 0; i < 1000; ++i)
	{
		datas.push_back(TestData());
	}
	vector<TestData> data1s;
	data1s.assign(datas.begin(), datas.end());

	Test w;
	w.show();
	return a.exec();
}
