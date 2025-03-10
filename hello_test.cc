#include <gtest/gtest.h>
#include "input.h"



// Demonstrate some basic assertions.
TEST(InputTest, EmptyExpression) {
  // Expect equality.
  //EXPECT_EQ(5 * 6, 42);
  std::string INPUT1 = "1.000000+2*9-8/3*(2-1)-32.4";
  std::string EXPECT1 = "( ( ( 1.000000 + ( 2 * 9 ) ) - ( ( 8 / 3 ) * ( 2 - 1 ) ) ) - 32.4 )";

  Input input1(INPUT1);
  std::string expression = input1.result();

  // Expect two strings to be equal.
  EXPECT_EQ(expression, EXPECT1) << "\n\t NOT good\n";

  system("pause");
}
