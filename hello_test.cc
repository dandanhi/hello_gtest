#include "gtest/gtest.h"
#include "add.h"

namespace {
    TEST(MyTest, Add) {
        EXPECT_EQ(2,add(1,1));
    }
}