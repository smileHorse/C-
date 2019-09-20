#ifndef TABLEDEFINE_H
#define TABLEDEFINE_H

#include "fastdb.h"

#include <string>
using namespace std;

class Song
{
public:
	string id;
	string name;
	string producer;

	TYPE_DESCRIPTOR((KEY(id, INDEXED|HASHED),
		KEY(name,INDEXED|HASHED),
		FIELD(producer)));
};

class Singer
{
public:
	string id;
	string firstName;
	string secondName;
	int age;
	bool sex;

	TYPE_DESCRIPTOR((KEY(id, INDEXED|HASHED),
		FIELD(firstName),
		FIELD(secondName),
		FIELD(age),
		FIELD(sex)));
};

#endif