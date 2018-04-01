/********************************************************************
	created:	2018/04/01
	created:	1:4:2018   11:03
	filename: 	E:\GitProject\C-\MIODevice\MFile.h
	file path:	E:\GitProject\C-\MIODevice
	file base:	MFile
	file ext:	h
	author:		Masf
	
	purpose:	file operation
*********************************************************************/
#ifndef MFILE_H
#define MFILE_H

#include <string>
#include <vector>
using namespace std;

typedef vector<char> CharVector;

class MFile
{
public:
	MFile(const string& filePath);
	~MFile();

public:
	// open the file
	bool open(const char* mode);

	// close the pointer of file
	void close();

	// judge pointer of file is opened
	bool isOpened() const;

	// get the error meesage
	string getError() const;

	// set the error message
	void setError(const string& error);

	// read the file
	int read(char* data, int maxlen);
	CharVector read(int maxlen);
	CharVector readAll();

	// write the file
	int write(const char* data, int len);
	int write(const char* data);
	int write(const CharVector& data);

private:
	FILE*	filePtr;	// pointer of file
	string	filePath;	// operated file's path
	bool	isOpen;		// pointer of file is opened
	string	error;		// error message
};

#endif