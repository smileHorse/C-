
#include "soapH.h"
#include "calc.nsmap"

#include <iostream>
using namespace std;

int main()
{
	double sum;
	struct soap soap;	// the gSoap runtime context
	soap_init(&soap);	// initialize the context(only once)
	if (soap_call_ns2__add(&soap, NULL, NULL, 1.0, 2.0, sum) == SOAP_OK)
	{
		std::cout << "Sum = " << sum << endl;
	}
	else
	{
		soap_print_fault(&soap, stderr);	//display the SOAP fault message on the stderr stream
	}
	soap_destroy(&soap);
	soap_end(&soap);
	soap_done(&soap);
	return 0;
}