
#include "FunctionExecTime.h"

#include <algorithm>
#include <functional>
#include <iostream>
#include <string>
#include <vector>
using namespace std;


struct FepUnitTimeData
{
	string 	fepNode;// 前置机节点号
	vector<short> unitSeq;
	long lastUpdated;
	bool status;
	bool fepCommStatus;
	bool bz;
};

void initData(vector<FepUnitTimeData>& datas)
{
	for (int i = 0; i < 10; ++i)
	{
		FepUnitTimeData data;
		data.fepNode = "test";
		for (int j = 0; j < 10; ++j)
		{
			data.unitSeq.push_back(j);
		}
		data.bz = i % 2 == 0;

		datas.push_back(data);
	}
}

class IsEqualFepNodeData : public binary_function<FepUnitTimeData, string, bool>
{
public:
	vector<short> unitSeqs;

public:
	bool operator()(const FepUnitTimeData& data, const string& fepNode) const 
	{
		if (data.fepNode == fepNode)
		{
			return true;
		}
		return false;
	}
};

int main()
{
	vector<FepUnitTimeData> datas;
	initData(datas);

	datas.erase(remove_if(datas.begin(), datas.end(), bind2nd(IsEqualFepNodeData(), "test")), datas.end());


	return 0;
}