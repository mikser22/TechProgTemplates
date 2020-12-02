//
// Created by akhtyamovpavel on 5/1/20.
//

#include "LeapTestCase.h"

#include <Functions.h>


TEST(IsLeapFunc, test1) {
    ASSERT_TRUE(IsLeap(2020));
}

TEST(IsLeapFunc, test2) {
    ASSERT_FALSE(IsLeap(2100));
}

TEST(IsLeapFunc, test3) {
    ASSERT_FALSE(IsLeap(2021));
}

TEST(IsLeapFunc, test4) {
    ASSERT_THROW(IsLeap(-2020), std::invalid_argument);
}

TEST(IsLeapFunc, test5) {
    ASSERT_TRUE(IsLeap(2000));
}