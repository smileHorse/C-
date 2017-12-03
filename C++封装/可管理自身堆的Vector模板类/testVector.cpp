// 测试Vector类
#include <iostream>
#include "Vector.h"

using namespace std;

// 用于测试向量的用户自定义类
class Foo
{
	long x;

public:
	Foo() : x(0)
	{
		cout << "Foo::Foo()\n";
	}

	Foo(int i) : x(i)
	{
		cout << "Foo::Foo(int)\n";
	}

	Foo(const Foo& f) : x(f.x)
	{
		cout << "Foo::Foo(const Foo&)\n";
	}

	~Foo()
	{
		cout << "Foo::~Foo()\n";
	}

	friend ostream& operator<<(ostream& os, const Foo& f)
	{
		os << f.x;
		return os;
	}
};

int main()
{
	// 实例化整型向量
	Vector<int> v(5);
	for (size_t i = 0; i < 11; ++i)
	{
		v += i;
	}
	for (size_t i = 0; i < v.length(); ++i)
	{
		cout << v[i] << endl;
	}

	// 实例化Foo向量
	Vector<Foo> v2;
	v2 += 0;
	v2 += 1;
	v2 += 2;
	for (size_t i = 0; i < v2.length(); ++i)
	{
		cout << v2[i] << endl;
	}
}