#include <gtest/gtest.h>

// Demonstrate some basic assertions.
TEST(HelloTest, BasicAssertions) {
  // Expect two strings not to be equal.
  EXPECT_STRNE("world", "world");
  // Expect equality.
  EXPECT_EQ(5 * 6, 42);

  system("pause");
}
