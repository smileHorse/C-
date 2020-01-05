
#include "sample2.h"
#include "gtest/gtest.h"

namespace {
	TEST(MyString, DefaultConstructor) {
		const MyString s;

		EXPECT_STREQ(NULL, s.c_string());

		EXPECT_EQ(0u, s.Length());
	}
}