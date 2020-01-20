#ifndef FIBONACCIGENERATOR_H
#define FIBONACCIGENERATOR_H

class FibonacciGenerator {
	int n;
	int val[2];
public:
	FibonacciGenerator() : n(0) { val[0] = val[1] = 0; }
	int operator()() {
		int result = n > 2 ? val[0] + val[1] : n > 0 ? 1 : 0;
		++n;
		val[0] = val[1];
		val[1] = result;
		return result;
	}
	int count() { return n; }
};
#endif