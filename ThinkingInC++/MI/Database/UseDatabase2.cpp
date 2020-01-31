#include <cassert>
#include "DBConnection.h"

class DBClient {
	DBConnection* db;
public:
	DBClient(DBConnection* dbCon) {
		db = dbCon;
		db->attach();
	}
	~DBClient() { db->detach(); }
	// Other database requests using db
};

//int main() {
//	DBConnection* db = DBConnection::create("MyDatabase");
//	assert(db->refCount() == 1);
//	DBClient c1(db);
//	assert(db->refCount() == 2);
//	DBClient c2(db);
//	assert(db->refCount() == 3);
//	// Use database, then release attach from original create
//	db->detach();
//	assert(db->refCount() == 2);
//}