//
// Created by hadasswittow on 9/28/19.
//
#include <gtest/gtest.h>
#include "BigNumber.h"
TEST(operators_tests, cout_operator) {
    BigNumber bn(5121);
    std::cout << bn<< std::endl;
}
TEST(operators_tests, plus_operator) {
    BigNumber bn(5121);
    BigNumber bn1(255);
    BigNumber ans(5376);
    ASSERT_EQ((bn+bn1).get_number_vec(),ans.get_number_vec());
}
//TEST(Constructors_tests, copy_constructor) {
//    //string s="AGCnTAG";
//    DnaSequence dnaSequence("AGCTAG");
//    DnaSequence dnaSequence1=dnaSequence;
//    ASSERT_STREQ(dnaSequence.get_dna_as_string(), dnaSequence1.get_dna_as_string());
//}


