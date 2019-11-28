//
// Created by hadasswittow on 9/28/19.
//
#include <gtest/gtest.h>
#include "BigNumber.h"
TEST(operators_tests, cout_operator) {
    BigNumber bn(5121,0);
    std::cout << bn<< std::endl;
}
TEST(operators_tests, plus_operator) {
    BigNumber bn(5121,0);
    BigNumber bn1(255,0);
    BigNumber ans(5376,0);
    ASSERT_EQ((bn+bn1).get_number_vec(),ans.get_number_vec());
}
TEST(bitwise_operation, unary_minus_operator) {
    BigNumber bn(5121,0);
    bn=-bn;
    std::cout << bn<< std::endl;
}


