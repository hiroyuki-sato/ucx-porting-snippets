#include "gtest/gtest.h"

#include <string>
using std::string;

const char *actualValTrue2  = "hello gtest2";
const char *actualValFalse2 = "hello world2";
const char *expectVal2      = "hello gtest2";

TEST(StrCompare2, CStrEqual) {
    EXPECT_STREQ(expectVal2, actualValTrue2);
}

TEST(StrCompare2, CStrNotEqual) {
    EXPECT_STREQ(expectVal2, actualValFalse2);
}
