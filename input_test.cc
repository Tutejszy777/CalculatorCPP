#include <gtest/gtest.h>
#include "input.h"


// checks every function
TEST(InputTest, ExpressionConversion) {

  std::string INPUT1 = "1.000+2*9-8/3*(2-1)-32.4";
  std::string EXPECT1 = "( ( ( 1.000 + ( 2 * 9 ) ) - ( ( 8 / 3 ) * ( 2 - 1 ) ) ) - 32.4 )";

  Input input1(INPUT1);
  std::string expression = input1.result();

  // Expect equality.
  EXPECT_EQ(expression, EXPECT1) << "\n\t NOT good\n";

}

//checks read from user
TEST(InputTest, ReadFunctionCheck) {

  std::string INPUT1 = "x+5";
  std::string EXPECT1 = "( 1.000000 + 5 )";

  std::cout << "Enter 1 \n";
  Input input1(INPUT1);
  std::string expression = input1.result();

  // Expect equality.
  EXPECT_EQ(expression, EXPECT1) << "\n\t NOT good\n";

}


TEST(InputTest, ToSeeTheConsole) {
  system("pause");
}

