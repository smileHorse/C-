
#include <QtCore/QCoreApplication>

#include "FunctionExecTime.h"

#include <iostream>
#include <string>
#include <vector>
#include <QVector>
using namespace std;

typedef vector<int> DiscreteSeq;

const int DATA_NUMS = 60000;
const int VALUE_NUMS = 100;

//ң������
struct DiscreteData
{
	string 	fepNode;// ǰ�û��ڵ��
	vector<string>  values;
	short			unitNo;		// ��Ԫ��
	DiscreteSeq		discretes;	// ң��
};

void initDatas(QVector<DiscreteData>& datas)
{
	FUNCTION_EXEC_TIME;

	datas.clear();
	datas.reserve(DATA_NUMS);

	for (int i = 0; i < DATA_NUMS; ++i)
	{
		DiscreteData data;
		data.fepNode = "AAAAAAAAAAAAAAAAAAAAAAAAAAA";
		data.values.reserve(VALUE_NUMS);
		for (int j = 0; j < VALUE_NUMS; ++j)
		{
			//data.values.push_back("BBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBB");
		}

		datas.push_back(data);
	}
}

int main(int argc, char *argv[])
{
	QCoreApplication a(argc, argv);

	vector<DiscreteData> datas;
	//initDatas(datas);

	char command = ' ';
	do 
	{
		cout << "����������(q to exit): " << endl;
		cin >> command;

		switch(command)
		{
		case 'i':
			{
				CFunctionExecTime time1("data destroy", true);
				{
					QVector<DiscreteData> tempDatas1;
					initDatas(tempDatas1);
				}
			}
			break;
		default:
			break;
		}
	} while (command != 'q');

	return a.exec();
}
