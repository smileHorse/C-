#ifndef EXCEPT_H
#define EXCEPT_H

#include <exception>
#include <string>
// 为保证引入一个数字而使用的宏技巧
#define str_(x) #x
#define xstr_(x) str_(x)
// 为方便异常抛出而使用的宏
// (包含标准信息、文件、行#)
#define Throw(Type, cod)\
	throw Type##_Exception(Type##_Exception::##cod, \
	std::string(__FILE__## " : Line " ##xstr_(__LINE__)))

#define Throw2(Type, cod, extra)\
	throw Type##_Exception(Type##_Exception::##cod, \
	std::string(extra## " : " ##__FILE__## " : Line " ##xstr_(__LINE__)))


#endif