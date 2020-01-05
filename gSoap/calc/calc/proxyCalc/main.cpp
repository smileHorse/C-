
#include "soapcalcProxy.h"
#include "calc.nsmap"

#include <iostream>
using namespace std;

//int main() 
//{
//	calcProxy calc(SOAP_XML_INDENT);
//	double sum;
//	if (calc.add(1.0, 2.0, sum) == SOAP_OK)
//	{
//		cout << "Sum: " << sum << endl;
//	}
//	else
//	{
//		calc.soap_stream_fault(cerr);
//	}
//}

int main() 
{
	calcProxy calc(SOAP_IO_KEEPALIVE);
	double sum = 0;
	double val[] = { 5.0, 3.5, 7.1, 1.2 };
	for (int i = 0; i < 4; ++i)
	{
		if (calc.add(sum, val[i], sum))
		{
			return calc.error;
		}
		calc.destroy();
	}
	cout << "Sum = " << sum << endl;
	return 0;
}