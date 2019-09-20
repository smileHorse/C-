
#include "fastdb.h"
#include "tableDefine.h"

#include <iostream>
#include <sstream>
#include <vector>
using namespace std;

string toString(int iValue) {
	stringstream stream;
	stream << iValue;
	return stream.str();
}

void insertData() {
	for (int i = 0; i < 200000; ++i){
		string index = toString(i);
		Song song;
		song.id = "songggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggg" + index;
		song.name = "songgggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggggnameeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeee" + index;
		song.producer = "producerrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrr" + index;
		insert(song);

		Singer singer;
		singer.id = "singerrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrr" + index;
		singer.firstName = "firstNameeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeee" + index;
		singer.secondName = "secondNameeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeee" + index;
		singer.age = 100;
		singer.sex = false;
		insert(singer);
	}
}

void updateData() {
	dbCursor<Song> songCursor(dbCursorForUpdate);
	songCursor.select();
	if (!songCursor.isEmpty())
	{
		do 
		{
			songCursor->name = "U-" + songCursor->name;
			songCursor->producer = "U-" + songCursor->producer;
			songCursor.update();
		} while (songCursor.next());
	}

	dbCursor<Singer> singerCursor(dbCursorForUpdate);
	singerCursor.select();
	if (!singerCursor.isEmpty())
	{
		do 
		{
			singerCursor->firstName = "U-" + singerCursor->firstName;
			singerCursor->secondName = "U-" + singerCursor->secondName;
			singerCursor->sex = false;
			singerCursor.update();
		} while (singerCursor.next());
	}
}

void selectSongData()
{
	dbCursor<Song> songCursor;
	songCursor.select();
	if (songCursor.isEmpty())
	{
		cout << "Song table is empty!!!" << endl;
		return;
	}
	int count = 0;
	do 
	{
		if (count++ >= 100)
		{
			cout << "press 'b' to break select; press other key to continue: " << endl;
			char key = 'a';
			cin >> key;
			if (key == 'b')
			{
				break;
			}
		}
		cout << "song name: " << songCursor->name << "song producer: " << songCursor->producer << endl;
	} while (songCursor.next());
}

void reopenDatabase(dbDatabase* pDb)
{
	if (pDb->isOpen())
	{
		pDb->close();
	}
	if (!pDb->open("song")) 
	{
		cerr << "database open failed!!!";
	}
	cout << "database reopen successed!!!" << endl;
}

void removeAllData()
{
	dbCursor<Song> songCursor(dbCursorForUpdate);
	songCursor.removeAll();
	dbCursor<Singer> singerCursor(dbCursorForUpdate);
	singerCursor.removeAll();
}

void testMemeory()
{
	dbSmallBuffer buffer;
	for (int i = 0; i < 100000; ++i)
	{
		string srcString = "bbbbbbbbbbbbbbb";
		int length = srcString.length();

		{
			buffer.put(6000);
			memset(buffer.base(), 0, 6000);
			for (int j = 0; j < 10; j++)
			{
				//((std::string*)(buffer.base() + j * length))->reserve(16);

				((std::string*)(buffer.base() + j * length))->assign(srcString.c_str(), length);

				((std::string*)(buffer.base() + j * length))->erase();
				((std::string*)(buffer.base() + j * length))->reserve(0);
			}
		}
	}
}

int main()
{
	dbDatabase db;
	if (!db.open("song")) {
		cerr << "database open failed!!!";
		return -1;
	}
	//dbFileTransactionLogger logger;
	//logger.open("./logger.log", dbFile::truncate);
	//db.setTransactionLogger(&logger);

	char command = 'a';
	do 
	{
		cout << "please input command to exec" << endl 
			<< "('b' to backup; 'c' to close database; 'd' to delete; " 
			<< "'i' to insert; 'o' to reopen; 'q' to quit; " 
			<< "'r' to restore; 's' to select; 't' to test; 'u' to update;): " << endl;
		cin >> command;
		if (command == 'q')
		{
			break;
		}

		switch (command) {
		case 'b':
			{
				if (db.isOpen())
				{
					db.backup("./backup.fdb", true);
				}
				break;
			}
		case 'c':
			{
				if (db.isOpen())
				{
					db.close();
				}
				break;
			}
		case 'd':
			{
				removeAllData();
				db.commit();
				break;
			}
		case 'i':
			{
				// insert data
				insertData();
				db.commit();
				break;
			}
		case 'o':
			{
				// reopen
				reopenDatabase(&db);
				break;
			}
		case 'r':
			{
				// restore
				//logger.close();
				db.setTransactionLogger(NULL);

				dbFileTransactionLogger restoreLogger;
				if (!restoreLogger.open("./logger.log", dbFile::read_only | dbFile::delete_on_close))
				{
					cerr << "logger file open failed!!!" << endl;
					break;
				}
				size_t n;
				dbFileTransactionLogger::RestoreStatus status = restoreLogger.restore(db, n);
				if (status == dbFileTransactionLogger::rsOK)
				{
					cout << "database restore successed, transactions count: " << n << endl;
				}
				else
				{
					cout << "database restore failed, transactions count: " << n << endl;
				}

				restoreLogger.close();

				//logger.open("./logger.log", dbFile::no_sync);
				//db.setTransactionLogger(&logger);
				break;
			}
		case 's':
			{
				// select
				selectSongData();
				break;
			}
		case 't':
			{
				testMemeory();
				break;
			}
		case 'u':
			{
				// update data
				updateData();
				db.commit();
				break;
			}
		default:
			break;
		}
	} while (true);

	return 0;
}