#include "gtest/gtest.h"
#include "add.h"
#include "hex.h"

namespace {
    TEST(MyTest, Add) {
        EXPECT_EQ(2,add(1,1));
    }

    TEST(HexTest, hexStringToInt16) {
        int16_t *res = hex2int16("0000000000010000000100010001000100010001000100010001000100010001000100010001000100010001000100010001000100010001000100010001");
        EXPECT_EQ(0, res[0]);
        EXPECT_EQ(0, res[1]);
        EXPECT_EQ(1, res[2]);
        EXPECT_EQ(0, res[3]);
        EXPECT_EQ(1, res[15]);
        EXPECT_EQ(1, res[30]);
        if (res) free(res);
    }
}