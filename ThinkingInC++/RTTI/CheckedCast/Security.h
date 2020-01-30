#ifndef SECURITY_H
#define SECURITY_H

#include <iostream>
using namespace std;

class Security {
public:
	virtual ~Security() {}
};

class Stock : public Security {};
class Bond : public Security {};

class Investment : public Security {
public:
	void special() {
		cout << "special Investment	function" << endl;
	}
};

class Metal : public Investment {};
#endif