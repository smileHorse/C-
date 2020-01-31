#ifndef DATABASE_H
#define DATABASE_H

#include <iostream>
#include <stdexcept>
#include <string>
using namespace std;

struct DatabaseError : std::runtime_error {
	DatabaseError(const string& msg) : runtime_error(msg) {}
};

class Database {
	string dbid;
public:
	Database(const string& dbStr) : dbid(dbStr) {}
	virtual ~Database() {}
	void open() throw(DatabaseError) {
		cout << "Connected to " << dbid << endl;
	}

	void close() {
		cout << dbid << " closed" << endl;
	}
	// other database functions...
};

#endif