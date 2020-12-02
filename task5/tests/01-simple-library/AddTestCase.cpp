//
// Created by akhtyamovpavel on 5/1/20.
//

#include "AddTestCase.h"
#include "Functions.h"

TEST(AddFunc, test1) {
    ASSERT_EQ(Add(200, 28), 228);
}

TEST(AddFunc, test2) {
    ASSERT_NE(Add(2, 2), 3);
}