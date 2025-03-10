#include <gtest/gtest.h>
#include "input.h"


// checks everything
TEST(InputTest, ExpressionConversion) {

  std::string INPUT1 = "1.000+2*9-8/3*(2-1)-32.4";
  std::string EXPECT1 = "( ( ( 1.000 + ( 2 * 9 ) ) - ( ( 8 / 3 ) * ( 2 - 1 ) ) ) - 32.4 )";

  Input input1(INPUT1);
  std::string expression = input1.result();

  // Expect equality.
  EXPECT_EQ(expression, EXPECT1) << "\n\t NOT good\n";

}

TEST(InputTest, WhiteSpaceFunction) {

  std::string INPUT1 = "1+2*9-8/3*(2-1)-32.4";
  std::string INVALID1 = "(((1.000+(2*9))-((8/3)*(2-1)))-32.4)";



  Input input1(INPUT1);
  std::string expression = input1.result();
  
  bool result1 = true;
  if(expression == INVALID1) result1 = false;

  EXPECT_TRUE(result1);

}

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

