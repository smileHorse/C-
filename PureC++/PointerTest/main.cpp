
#include <iostream>
using namespace std;

int main1()
{
	cout << "__DATE__ == " << __DATE__ << endl;
	cout << "__FILE__ == " << __FILE__ << endl;
	cout << "__LINE__ == " << __LINE__ << endl;
	cout << "__TIME__ == " << __TIME__ << endl;
	cout << "__TIMESTAMP__ == " << __TIMESTAMP__ << endl;
	cout << "__cplusplus == " << __cplusplus << endl;

	while(true)
	{}
}