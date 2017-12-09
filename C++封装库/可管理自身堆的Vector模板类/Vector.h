/********************************************************************
	created:	2017/12/03
	created:	3:12:2017   20:09
	filename: 	E:\GitProject\C-\PureC++\PointerTest\Vector.h
	file path:	E:\GitProject\C-\PureC++\PointerTest
	file base:	Vector
	file ext:	h
	author:		Masf
	
	purpose:	一个能管理自身堆的Vector模板类
*********************************************************************/
#ifndef VECTOR_H
#define VECTOR_H

#include <iostream>
#include <stddef.h>
#include <stdlib.h>
#include <new>

using namespace std;

// 以下两个函数正好是为了追踪执行
inline void* operator new(size_t siz)
{
	cout << ">>> operator new (" << siz << " bytes)" << endl;
	return malloc(siz);
}

inline void operator delete(void* p)
{
	cout << ">>> operator delete: " << (void*)p << endl;
	free(p);
}

template<class T>
class Vector
{
public:
	Vector();
	Vector(size_t);
	~Vector();

	// 搜索路径和下标
	Vector<T>& operator+=(const T&);
	T& operator[](size_t);

	// 与长度相关的函数
	size_t length() const;
	void resize(size_t);
	size_t capacity() const;
	void reserve(size_t);

private:
	T* arena;	// 特殊类存储区域
	size_t	length_;
	size_t	capacity_;

	enum {CHUNK = 10};

	// 不允许复制和赋值
	Vector(const Vector<T>&);
	Vector<T>& operator=(const Vector<T>&);
	static size_t next_chunk(size_t n);
};

template<class T>
Vector<T>::Vector()
{
	// 初始化空的向量
	arena = 0;
	length_ = capacity_ = 0;
}

template<class T>
Vector<T>::Vector(size_t n)
{
	// 分派多重CHUNK元素>= n
	length_ = 0;
	capacity_ = next_chunk(n);
	arena = (T*)::operator new(sizeof(T) * capacity_);
	cout << ">>> area created at " << (void*)arena << endl;
}

template<class T>
Vector<T>::~Vector()
{
	// 为每个元素执行析构函数
	for (size_t i = 0; i < length_; ++i)
	{
		(arena + i)->T::~T();
	}

	::operator delete(arena);
}

template<class T>
Vector<T>& Vector<T>::operator+=( const T& x )
{
	if (length_ == capacity_)
	{
		reserve(length_ + 1);
	}
	(void) new (arena + length_++) T(x);
	return *this;
}

template<class T>
T& Vector<T>::operator[]( size_t pos )
{
	if (pos >= length_)
	{
		throw "bad index in Vector<T>::operator[]";
	}
	return arena[pos];
}

template<class T>
size_t Vector<T>::length() const
{
	return length_;
}

template<class T>
void Vector<T>::resize( size_t new_length )
{
	// 只允许减少
	if (new_length < length_)
	{
		// 只销毁结尾元素
		// 不要改变容量
		for (size_t i = new_length; i < length_; ++i)
		{
			(arena + i)->T::~T();
		}
		length_ = new_length;
	}
}

template<class T>
size_t Vector<T>::capacity() const
{
	return capacity_;
}

template<class T>
void Vector<T>::reserve( size_t new_capacity )
{
	// 只允许增加
	if (new_capacity > capacity_)
	{
		new_capacity = next_chunk(new_capacity);
		if (new_capacity > capacity_)
		{
			// 复制元素到新的空间
			T* new_arena = (T*)::operator new(sizeof(T) * new_capacity);
			cout << ">>> new arena created at " << (void*)new_arena << endl;
			for (size_t i = 0; i < length_; ++i)
			{
				(void) new (new_arena + i) T(arena[i]);
			}

			// 破坏旧的向量
			for (size_t i = 0; i < length_; ++i)
			{
				(arena + i)->T::~T();
			}
			delete arena;

			// 更新状态
			arena = new_arena;
			capacity_ = new_capacity;
		}
	}
}

template<class T>
size_t Vector<T>::next_chunk( size_t n )
{
	return ((n + CHUNK - 1) / CHUNK) * CHUNK;
}

#endif