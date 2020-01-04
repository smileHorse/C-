
#include <algorithm>
#include <ctime>
#include <iostream>
#include <string>
#include <vector>
#include <list>
using namespace std;

#include "FunctionExecTime.h"

typedef vector<int> DiscreteSeq;

const int DATA_NUMS = 60000;
const int VALUE_NUMS = 100;

//遥信数据
struct DiscreteData
{
	string 	fepNode;// 前置机节点号
	vector<string>  values;
	short			unitNo;		// 单元号
	DiscreteSeq		discretes;	// 遥信
};


void pushBackData(vector<DiscreteData>& datas)
{
	DiscreteData data;
	data.fepNode = "AAAAAAAAAAAAAAAAAAAAAAAAAAA";
	data.values.reserve(VALUE_NUMS);
	for (int j = 0; j < VALUE_NUMS; ++j)
	{
		data.values.push_back("BBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBB");
	}
	datas.push_back(data);
}

void initDatas(vector<DiscreteData>& datas)
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

void initDatas(list<DiscreteData>& datas)
{
	FUNCTION_EXEC_TIME;

	datas.clear();
	DiscreteData data;
	data.fepNode = "AAAAAAAAAAAAAAAAAAAAAAAAAAA";
	data.values.reserve(VALUE_NUMS);
	for (int j = 0; j < VALUE_NUMS; ++j)
	{
		//data.values.push_back("BBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBB");
	}

	for (int i = 0; i < DATA_NUMS; ++i)
	{
		datas.push_back(data);
	}
}

void initDatas(vector<DiscreteData*>& datas)
{
	FUNCTION_EXEC_TIME;

	datas.clear();
	datas.reserve(DATA_NUMS);

	for (int i = 0; i < DATA_NUMS; ++i)
	{
		DiscreteData* pData = new DiscreteData;
		pData->fepNode = "AAAAAAAAAAAAAAAAAAAAAAAAAAA";
		pData->values.reserve(VALUE_NUMS);
		for (int j = 0; j < VALUE_NUMS; ++j)
		{
			//pData->values.push_back("BBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBB");
		}

		datas.push_back(pData);
	}
}

// 测试往vector中插入数据的效率
void testPushBack(vector<DiscreteData> datas)
{
	FUNCTION_EXEC_TIME;
	vector<DiscreteData> innerDatas;
	innerDatas.reserve(DATA_NUMS);
	
	for (int i = 0; i < DATA_NUMS; ++i)
	{
		innerDatas.push_back(datas[i]);
	}
}

// 测试通过函数调用往vector中插入数据的效率
void testFunPushBack()
{
	FUNCTION_EXEC_TIME;
	vector<DiscreteData> innerDatas;
	innerDatas.reserve(DATA_NUMS);
	for (int i = 0; i < DATA_NUMS; ++i)
	{
		pushBackData(innerDatas);
	}
}

// 测试assign
void testAssign(const vector<DiscreteData>& datas)
{
	vector<DiscreteData> innerDatas;
	innerDatas.resize(DATA_NUMS);
	{
		FUNCTION_EXEC_TIME;
		innerDatas.assign(datas.begin(), datas.end());
	}
}

// 测试swap
void testSwap(const vector<DiscreteData>& datas)
{
	vector<DiscreteData> tempDatas(datas);

	FUNCTION_EXEC_TIME;
	vector<DiscreteData> innerDatas;
	innerDatas.reserve(DATA_NUMS);
	innerDatas.swap(tempDatas);
}

int main() 
{
	vector<DiscreteData> datas;
	//initDatas(datas);

	vector<DiscreteData> tempDatas1;
	char command = ' ';
	do 
	{
		cout << "请输入命令(q to exit): " << endl;
		cin >> command;

		switch(command)
		{
		case 'i':
			{
				vector<DiscreteData*> tempDatas;
				initDatas(tempDatas);
				for (size_t i = 0; i < tempDatas.size(); ++i)
				{
					delete tempDatas[i];
					tempDatas[i] = NULL;
				}
			}
			break;
		case 'l':
			{
				CFunctionExecTime time1("data destroy", true);
				{
					initDatas(tempDatas1);
				}
			}
			break;
		case 'p': // 测试往vector中插入数据的效率
			testPushBack(datas);
			break;
		case 'f': // 测试通过函数调用往vector中插入数据的效率
			testFunPushBack();
			break;
		case 'a':
			testAssign(datas);
			break;
		case 's':
			testSwap(datas);
			break;
		default:
			break;
		}
	} while (command != 'q');
	return 0;
}