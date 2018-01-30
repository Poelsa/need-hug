#include <gtest/gtest.h>

TEST(pointerTests, check64Bit)
{
	ASSERT_EQ(8, sizeof(void*));
}