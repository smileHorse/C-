
#include "fastdb.h"
#include "tableDefine.h"

#include <iostream>
#include <sstream>
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

int main()
{
	dbDatabase db;
	if (!db.open("song")) {
		cerr << "database open failed!!!";
		return -1;
	}
	dbFileTransactionLogger logger;
	//logger.open("./logger.log", dbFile::no_sync | dbFile::truncate);
	//db.setTransactionLogger(&logger);

	char command = 'a';
	do 
	{
		cout << "please input command to exec" << endl 
			<< "('i' to insert; 'u' to update; 's' to select; 'r' to restore; 'o' to reopen; 'q' to quit): " << endl;
		cin >> command;
		if (command == 'q')
		{
			break;
		}

		switch (command) {
		case 'i':
			{
				// insert data
				insertData();
				db.commit();
				break;
			}
		case 'u':
			{
				// update data
				updateData();
				db.commit();
				break;
			}
		case 's':
			{
				// select
				dbCursor<Song> songCursor;
				songCursor.select();
				if (songCursor.isEmpty())
				{
					cout << "Song table is empty!!!" << endl;
					break;
				}
				do 
				{
					cout << "song name: " << songCursor->name << "song producer: " << songCursor->producer << endl;
				} while (songCursor.next());
				break;
			}
		case 'r':
			{
				// restore
				//logger.close();
				//db.setTransactionLogger(NULL);

				dbFileTransactionLogger restoreLogger;
				if (!restoreLogger.open("./logger.log", dbFile::read_only))
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
		case 'o':
			{
				// reopen
				if (db.isOpen())
				{
					db.close();
				}
				if (!db.open("song")) {
					cerr << "database open failed!!!";
				}
				break;
			}
		default:
			break;
		}
	} while (true);

	return 0;
}