#include <gtest/gtest.h>
#include "tree.h"


// checks everything
TEST(TreeTest, EvaluationCheck) {

  std::string INPUT = "( ( ( 1.000 + ( 2 * 9 ) ) - ( ( 9 / 3 ) * ( 2 - 1 ) ) ) - 32.4 )";

  ExpressionTree ex(INPUT);
  bool check = true;

  if(ex.Evaluate() != -16.4) check = false;

  EXPECT_TRUE(check);

}

TEST(TreeTest, EvaluationCheck2) {

  std::string INPUT = "( 4 + ( 5 * 2 ) )";

  ExpressionTree ex(INPUT);
  bool check = true;

  if(ex.Evaluate() != 14) check = false;

  EXPECT_TRUE(check);

}


//TEST(TreeTest, ToSeeTheConsole) {
//  system("pause");
//}

