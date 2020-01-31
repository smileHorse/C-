// DBConnection.h
#ifndef DBCONNECTION_H
#define DBCONNECTION_H

#include <cassert>
#include <string>
#include "Countable.h"
#include "Database.h"
using namespace std;

class DBConnection : public Database, public Countable {
	DBConnection(const DBConnection&);	// Disallow copy
	DBConnection& operator=(const DBConnection&);
protected:
	DBConnection(const string& dbStr) throw (DatabaseError)
		: Database(dbStr) { open(); }
	~DBConnection() { close(); }
public:
	static DBConnection* create(const string& dbStr) throw(DatabaseError) {
		DBConnection* con = new DBConnection(dbStr);
		con->attach();
		assert(con->refCount() == 1);
		return con;
	}
	// Other added functionality as desired...
};

#endif