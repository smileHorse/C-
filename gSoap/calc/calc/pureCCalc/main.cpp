
#include "soapH.h"
#include "calc.nsmap"

int main()
{
	struct soap soap;
	double sum = 0.0;
	double val[] = {5.0, 3.5, 7.1, 1.2};
	int i;
	for (i = 0; i < 4; ++i)
	{
		soap_init1(&soap, SOAP_IO_KEEPALIVE);
		if (soap_call_ns2__add(&soap, NULL, NULL, sum, val[i], &sum))
		{
			return soap.error;
		}
	}
	printf("Sum = %lg\n", sum);
	soap_end(&soap);
	soap_done(&soap);
	return 0;
}