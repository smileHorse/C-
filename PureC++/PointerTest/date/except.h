#ifndef EXCEPT_H
#define EXCEPT_H

#include <exception>
#include <string>
// Ϊ��֤����һ�����ֶ�ʹ�õĺ꼼��
#define str_(x) #x
#define xstr_(x) str_(x)
// Ϊ�����쳣�׳���ʹ�õĺ�
// (������׼��Ϣ���ļ�����#)
#define Throw(Type, cod)\
	throw Type##_Exception(Type##_Exception::##cod, \
	std::string(__FILE__## " : Line " ##xstr_(__LINE__)))

#define Throw2(Type, cod, extra)\
	throw Type##_Exception(Type##_Exception::##cod, \
	std::string(extra## " : " ##__FILE__## " : Line " ##xstr_(__LINE__)))


#endif