#include <iostream>
using namespace std;

class Top {
	int x;
public:
	Top(int n) : x(n) {}
};

class Left : public Top {
	int y;
public:
	Left(int m, int n) : Top(m) { y = n; }
};

class Right : public Top {
	int z;
public:
	Right(int m, int n) : Top(m) { z = n; }
};

class Bottom : public Left, public Right {
	int w;
public:
	Bottom(int i, int j, int k, int m)
		: Left(i, k), Right(j, k) { w = m; }
};

int main() {
	Bottom b(1, 2, 3, 4);
	cout << sizeof b << endl;
}