
#include <iostream>
#include <string>
#include <vector>
#include <list>
using namespace std;

#include "DataStruct.h"
#include "FunctionExecTime.h"

#define MAX_NUMBER	23500
#define ATTRIBUTE_COUNT	30
#define DEFINE_EXEC_TIME	CFunctionExecTime execTime(__FUNCTION__)


// 在堆上分配对象
void allocObjectInHeap(bool reserved = false, bool insert = false);
// 在堆上分配对象
void allocObjectInHeap_array();
// 在栈上分配对象
void allocObjectInStack(bool reserved = false);


int main()
{
	for (int i = 0; i < 10; ++i)
	{
		if (i != 0)
		{
			cout << endl << endl;
		}
		cout << "Round " << i << endl;

		allocObjectInHeap();
		allocObjectInHeap(true);
		allocObjectInHeap(true, true);

		allocObjectInHeap_array();

		//allocObjectInStack();
		//allocObjectInStack(true);
	}
	return 0;
}

// 在堆上分配对象
void allocObjectInHeap(bool reserved, bool insert)
{
	DEFINE_EXEC_TIME;

	vector<CDataStruct*> dataVct;
	if (reserved)
	{
		dataVct.reserve(MAX_NUMBER);
	}

	for (int i = 0; i < MAX_NUMBER; ++i)
	{
		CDataStruct* pData = new CDataStruct();

		pData->id = i;
		pData->name = "gasdgadsgas";
		pData->code = "gasdgadsgas";
		pData->desc = "gasdgadsgas";
		pData->address = "gasdgadsgas";
		pData->phone = "gasdgadsgas";

		if (!insert)
		{
			if (reserved)
			{
				pData->attributes.reserve(ATTRIBUTE_COUNT);
			}
			for (int j = 0; j < ATTRIBUTE_COUNT; ++j)
			{
				pData->attributes.push_back("gdsgsdgsadgs");
			}
		}
		else
		{
			string strArray[ATTRIBUTE_COUNT];
			for (int j = 0; j < ATTRIBUTE_COUNT; ++j)
			{
				strArray[j] = "gdsgsdgsadgs";
			}
			pData->attributes.insert(pData->attributes.end(), strArray, strArray + ATTRIBUTE_COUNT);
		}

		dataVct.push_back(pData);

		delete pData;
		pData = NULL;
	}
}

// 在堆上分配对象
void allocObjectInHeap_array()
{
	DEFINE_EXEC_TIME;

	vector<CDataStruct*> dataVct;
	CDataStruct* pDataArray[MAX_NUMBER];

	for (int i = 0; i < MAX_NUMBER; ++i)
	{
		CDataStruct* pData = new CDataStruct();

		pData->id = i;
		pData->name = "gasdgadsgas";
		pData->code = "gasdgadsgas";
		pData->desc = "gasdgadsgas";
		pData->address = "gasdgadsgas";
		pData->phone = "gasdgadsgas";

		string strArray[ATTRIBUTE_COUNT];
		for (int j = 0; j < ATTRIBUTE_COUNT; ++j)
		{
			strArray[j] = "gdsgsdgsadgs";
		}
		pData->attributes.insert(pData->attributes.end(), strArray, strArray + ATTRIBUTE_COUNT);

		pDataArray[i] = pData;
	}
	dataVct.insert(dataVct.end(), pDataArray, pDataArray + MAX_NUMBER);

	for (int i = 0; i < MAX_NUMBER; ++i)
	{
		delete pDataArray[i];
		pDataArray[i] = NULL;
	}
}

// 在栈上分配对象
void allocObjectInStack(bool reserved)
{
	DEFINE_EXEC_TIME;

	vector<CDataStruct> dataVct;
	if (reserved)
	{
		dataVct.reserve(MAX_NUMBER);
	}

	for (int i = 0; i < MAX_NUMBER; ++i)
	{
		CDataStruct data;

		data.id = i;
		data.name = "gasdgadsgas";
		data.code = "gasdgadsgas";
		data.desc = "gasdgadsgas";
		data.address = "gasdgadsgas";
		data.phone = "gasdgadsgas";

		if (reserved)
		{
			data.attributes.reserve(ATTRIBUTE_COUNT);
		}
		for (int j = 0; j < ATTRIBUTE_COUNT; ++j)
		{
			//data.attributes.push_back("gdsgsdgsadgs");
			data.array[j] = "gdsgsdgsadgs";
		}

		dataVct.push_back(data);
	}
}