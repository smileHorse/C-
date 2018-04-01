/********************************************************************
	created:	2018/04/01
	created:	1:4:2018   11:03
	filename: 	E:\GitProject\C-\MIODevice\MFile.cpp
	file path:	E:\GitProject\C-\MIODevice
	file base:	MFile
	file ext:	cpp
	author:		Masf
	
	purpose:	file operation
*********************************************************************/

#include "MFile.h"

MFile::MFile( const string& filePath )
	: filePath(filePath), isOpen(false), error("")
{

}

MFile::~MFile()
{
	close();
}

// open the file
bool MFile::open(const char* mode)
{
	filePtr = fopen(filePath.c_str(), mode);
	if (filePtr != NULL)
	{
		isOpen = true;
		return true;
	}
	else
	{
		setError("open file failed");
		return false;
	}
}

// close the pointer of file
void MFile::close()
{
	if (isOpened())
	{
		fclose(filePtr);
		isOpen = false;
	}
}

// judge pointer of file is opened
bool MFile::isOpened() const
{
	return isOpen;
}

// get the error meesage
std::string MFile::getError() const
{
	return error;
}

// set the error message
void MFile::setError( const string& error )
{
	this->error = error;
}

// read the file
int MFile::read( char* data, int maxlen )
{
	if (!isOpened())
	{
		setError("file has not opened");
		return -1;
	}

	int readBytes = fread(data, sizeof(char), maxlen, filePtr);
	if (readBytes != 0)
	{
		return readBytes;
	}

	if(ferror(filePtr) != 0)
	{
		setError("read file happend error");
		return -1;
	}
	else
	{
		return 0;
	}
}

CharVector MFile::read( int maxlen )
{
	if (!isOpened())
	{
		setError("file has not opened");
		return CharVector();
	}

	CharVector result;
	char* data = new char[maxlen];
	int readBytes = read(data, maxlen);
	if (readBytes != -1)
	{
		result.reserve(readBytes);
		for (int i = 0; i < readBytes; ++i)
		{
			result.push_back(data[i]);
		}
	}
	delete[] data;
	return result;
}

CharVector MFile::readAll()
{
	if (!isOpened())
	{
		setError("file has not opened");
		return CharVector();
	}

	CharVector result;
	int start = 0;
	int totalBytes = 0;
	int maxlen = 100000;
	char* data = new char[maxlen];
	int readBytes = read(data, maxlen);
	while(readBytes != 0) 
	{
		totalBytes += readBytes;
		result.resize(totalBytes);
		for (int i = 0; i < readBytes; ++i)
		{
			result[i + start] = data[i];
		}
		start += readBytes;
		readBytes = read(data, maxlen);
	}
	if (readBytes == -1)
	{
		result.clear();
	}
	delete[] data;
	return result;
}

// write the file
int MFile::write( const char* data, int len )
{
	if (!isOpened())
	{
		setError("file has not opened");
		return -1;
	}

	int writeBytes = fwrite(data, sizeof(char), len, filePtr);
	if (writeBytes != len)
	{
		return -1;
	}
	else
	{
		return writeBytes;
	}
}

int MFile::write( const char* data )
{
	return write(data, strlen(data));
}

int MFile::write( const CharVector& data )
{
	int len = data.size();
	char* tmpData = new char[len];
	for (int i = 0; i < len; ++i)
	{
		tmpData[i] = data.at(i);
	}
	return write(tmpData, len);
}
