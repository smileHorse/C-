/********************************************************************
	created:	2017/12/14
	created:	14:12:2017   9:59
	filename: 	F:\code\GitProject\C-\ThinkingInC++\MemCheck\MemCheck.h
	file path:	F:\code\GitProject\C-\ThinkingInC++\MemCheck
	file base:	MemCheck
	file ext:	h
	author:		Masf
	
	purpose:	�����������new����ĳЩƽ̨�Ͽ����޷�ʹ�ã�����ֻ������
				��ֱ�ӵ���operator new()�����ĳ���
				�ܹ��ػ����ж�new��delete�ĵ��ã�����ͨ���ڳ����е��ú�
				MEM_ON()����ʼ���ڴ���١������й��ڴ������ͷŵ��ټ�
				������ӡ����׼����ϡ�
				������ٶ�̬�洢���Ļʱ���������κ�Դ�ļ��а������
				�ļ����������������б������ļ������һ����
				���ļ����滻new�ĺ꽫��۸Ŀ���Դ������ʹ�õĵ�����new
				�������ʵ�������ܻ���ɱ������
*********************************************************************/
#ifndef MEMCHECK_H
#define MEMCHECK_H
#include <cstddef>

// Usurp the new operator(both scalar and array versions)
void* operator new(std::size_t, const char*, long);
void* operator new[](std::size_t, const char*, long);
#define new new(__FILE__, __LINE__)

extern bool traceFlag;
#define TRACE_ON()	traceFlag = true
#define TRACE_OFF()	traceFlag = false

extern bool activeFlag;
#define MEM_ON()	activeFlag = true
#define MEM_OFF()	activeFlag = false

#endif