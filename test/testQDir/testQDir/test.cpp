
#include <limits>
#include "sample1.h"
#include "gtest/gtest.h"

namespace {
	TEST(FactorialTest, Negative) {
		EXPECT_EQ(1, Factorial(-5));
		EXPECT_EQ(1, Factorial(-1));
		EXPECT_GT(Factorial(-10), 0);
	}
}