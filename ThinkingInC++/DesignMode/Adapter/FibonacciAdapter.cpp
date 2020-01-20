// Adapting an interface to something you already have
#include <iostream>
#include <numeric>
#include "FibonacciGenerator.h"
using namespace std;

class FibonacciAdapter {
	FibonacciGenerator f;
	int length;
public:
	FibonacciAdapter(int size) : length(size) {}
	class iterator;
	friend class iterator;
	class iterator : public std::iterator<std::input_iterator_tag, FibonacciAdapter, ptrdiff_t> {
		FibonacciAdapter& ap;
	public:
		typedef int value_type;
		iterator(FibonacciAdapter& a) : ap(a) {}
		bool operator==(const iterator&) const {
			return ap.f.count() == ap.length;
		}
		bool operator!=(const iterator& x) const {
			return !(*this == x);
		}
		int operator*() const { return ap.f(); }
		iterator& operator++() { return *this; }
		iterator& operator++(int) { return *this; } 
	};
	iterator begin() { return iterator(*this); }
	iterator end() { return iterator(*this); }
};

int main() {
	const int SZ = 20;
	FibonacciAdapter a1(SZ);
	cout << "accumulate: " << accumulate(a1.begin(), a1.end(), 0) << endl;
	FibonacciAdapter a2(SZ), a3(SZ);
	cout << "inner product: " << inner_product(a2.begin(), a2.end(), a3.begin(), 0) << endl;
	FibonacciAdapter a4(SZ);
	int r1[SZ] = {0};
	int* end = partial_sum(a4.begin(), a4.end(), r1);
	FibonacciAdapter a5(SZ);
	int r2[SZ] = {0};
	end = adjacent_difference(a5.begin(), a5.end(), r2);
}