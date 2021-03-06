#include "gtest/gtest.h"

#include <boost/algorithm/hex.hpp>
#include <util.h>

TEST(fixed_point, Conversions_tests)
{
    using Int = NTP1Int;

    EXPECT_EQ(FP_DecimalToInt<Int>("987654321", 8), 98765432100000000);
    EXPECT_EQ(FP_DecimalToInt<Int>("87654321", 8), 8765432100000000);
    EXPECT_EQ(FP_DecimalToInt<Int>("7654321", 8), 765432100000000);
    EXPECT_EQ(FP_DecimalToInt<Int>("654321", 8), 65432100000000);
    EXPECT_EQ(FP_DecimalToInt<Int>("54321", 8), 5432100000000);
    EXPECT_EQ(FP_DecimalToInt<Int>("4321", 8), 432100000000);
    EXPECT_EQ(FP_DecimalToInt<Int>("321", 8), 32100000000);
    EXPECT_EQ(FP_DecimalToInt<Int>("21", 8), 2100000000);
    EXPECT_EQ(FP_DecimalToInt<Int>("1", 8), 100000000);
    EXPECT_EQ(FP_DecimalToInt<Int>("1.2", 8), 120000000);
    EXPECT_EQ(FP_DecimalToInt<Int>("1.23", 8), 123000000);
    EXPECT_EQ(FP_DecimalToInt<Int>("1.234", 8), 123400000);
    EXPECT_EQ(FP_DecimalToInt<Int>("1.2345", 8), 123450000);
    EXPECT_EQ(FP_DecimalToInt<Int>("1.23456", 8), 123456000);
    EXPECT_EQ(FP_DecimalToInt<Int>("1.234567", 8), 123456700);
    EXPECT_EQ(FP_DecimalToInt<Int>("1.2345678", 8), 123456780);
    EXPECT_EQ(FP_DecimalToInt<Int>("1.23456789", 8), 123456789);
    EXPECT_EQ(FP_DecimalToInt<Int>("21.23456789", 8), 2123456789);
    EXPECT_EQ(FP_DecimalToInt<Int>("321.23456789", 8), 32123456789);
    EXPECT_EQ(FP_DecimalToInt<Int>("4321.23456789", 8), 432123456789);
    EXPECT_EQ(FP_DecimalToInt<Int>("54321.23456789", 8), 5432123456789);
    EXPECT_EQ(FP_DecimalToInt<Int>("654321.23456789", 8), 65432123456789);
    EXPECT_EQ(FP_DecimalToInt<Int>("7654321.23456789", 8), 765432123456789);
    EXPECT_EQ(FP_DecimalToInt<Int>("87654321.23456789", 8), 8765432123456789);
    EXPECT_EQ(FP_DecimalToInt<Int>("987654321.23456789", 8), 98765432123456789);
    EXPECT_EQ(FP_DecimalToInt<Int>("1987654321.23456789", 8), 198765432123456789);
    EXPECT_EQ(FP_DecimalToInt<Int>("21987654321.23456789", 8), 2198765432123456789);
    EXPECT_EQ(FP_DecimalToInt<Int>("21987654321.2345678", 8), 2198765432123456780);
    EXPECT_EQ(FP_DecimalToInt<Int>("21987654321.234567", 8), 2198765432123456700);
    EXPECT_EQ(FP_DecimalToInt<Int>("21987654321.23456", 8), 2198765432123456000);
    EXPECT_EQ(FP_DecimalToInt<Int>("21987654321.2345", 8), 2198765432123450000);
    EXPECT_EQ(FP_DecimalToInt<Int>("21987654321.234", 8), 2198765432123400000);
    EXPECT_EQ(FP_DecimalToInt<Int>("21987654321.23", 8), 2198765432123000000);
    EXPECT_EQ(FP_DecimalToInt<Int>("21987654321.2", 8), 2198765432120000000);
    EXPECT_EQ(FP_DecimalToInt<Int>("21987654321.", 8), 2198765432100000000);
    EXPECT_EQ(FP_DecimalToInt<Int>("21987654321.0", 8), 2198765432100000000);
    EXPECT_EQ(FP_DecimalToInt<Int>("21987654321.00", 8), 2198765432100000000);
    EXPECT_EQ(FP_DecimalToInt<Int>("21987654321.000", 8), 2198765432100000000);
    EXPECT_EQ(FP_DecimalToInt<Int>("21987654321.0000", 8), 2198765432100000000);
    EXPECT_EQ(FP_DecimalToInt<Int>("21987654321.00000", 8), 2198765432100000000);
    EXPECT_EQ(FP_DecimalToInt<Int>("21987654321.000000", 8), 2198765432100000000);
    EXPECT_EQ(FP_DecimalToInt<Int>("21987654321.0000000", 8), 2198765432100000000);
    EXPECT_EQ(FP_DecimalToInt<Int>("21987654321.00000000", 8), 2198765432100000000);
    EXPECT_EQ(FP_DecimalToInt<Int>("", 8), 0);
    EXPECT_ANY_THROW(FP_DecimalToInt<Int>(" ", 8));
    EXPECT_ANY_THROW(FP_DecimalToInt<Int>("21987654321.000000000", 8));
    EXPECT_ANY_THROW(FP_DecimalToInt<Int>("1.234567891", 8));
    EXPECT_ANY_THROW(FP_DecimalToInt<Int>("1..234567891", 8));
    EXPECT_ANY_THROW(FP_DecimalToInt<Int>("1.234567891,", 8));
    EXPECT_ANY_THROW(FP_DecimalToInt<Int>("1.23a4567891,", 8));
    EXPECT_ANY_THROW(FP_DecimalToInt<Int>("1.23-4567891", 8));
    EXPECT_ANY_THROW(FP_DecimalToInt<Int>("1.23e4567891", 8));

    EXPECT_EQ(FP_DecimalToInt<Int>("-987654321", 8), -98765432100000000);
    EXPECT_EQ(FP_DecimalToInt<Int>("-87654321", 8), -8765432100000000);
    EXPECT_EQ(FP_DecimalToInt<Int>("-7654321", 8), -765432100000000);
    EXPECT_EQ(FP_DecimalToInt<Int>("-654321", 8), -65432100000000);
    EXPECT_EQ(FP_DecimalToInt<Int>("-54321", 8), -5432100000000);
    EXPECT_EQ(FP_DecimalToInt<Int>("-4321", 8), -432100000000);
    EXPECT_EQ(FP_DecimalToInt<Int>("-321", 8), -32100000000);
    EXPECT_EQ(FP_DecimalToInt<Int>("-21", 8), -2100000000);
    EXPECT_EQ(FP_DecimalToInt<Int>("-1", 8), -100000000);
    EXPECT_EQ(FP_DecimalToInt<Int>("-1.2", 8), -120000000);
    EXPECT_EQ(FP_DecimalToInt<Int>("-1.23", 8), -123000000);
    EXPECT_EQ(FP_DecimalToInt<Int>("-1.234", 8), -123400000);
    EXPECT_EQ(FP_DecimalToInt<Int>("-1.2345", 8), -123450000);
    EXPECT_EQ(FP_DecimalToInt<Int>("-1.23456", 8), -123456000);
    EXPECT_EQ(FP_DecimalToInt<Int>("-1.234567", 8), -123456700);
    EXPECT_EQ(FP_DecimalToInt<Int>("-1.2345678", 8), -123456780);
    EXPECT_EQ(FP_DecimalToInt<Int>("-1.23456789", 8), -123456789);
    EXPECT_EQ(FP_DecimalToInt<Int>("-21.23456789", 8), -2123456789);
    EXPECT_EQ(FP_DecimalToInt<Int>("-321.23456789", 8), -32123456789);
    EXPECT_EQ(FP_DecimalToInt<Int>("-4321.23456789", 8), -432123456789);
    EXPECT_EQ(FP_DecimalToInt<Int>("-54321.23456789", 8), -5432123456789);
    EXPECT_EQ(FP_DecimalToInt<Int>("-654321.23456789", 8), -65432123456789);
    EXPECT_EQ(FP_DecimalToInt<Int>("-7654321.23456789", 8), -765432123456789);
    EXPECT_EQ(FP_DecimalToInt<Int>("-87654321.23456789", 8), -8765432123456789);
    EXPECT_EQ(FP_DecimalToInt<Int>("-987654321.23456789", 8), -98765432123456789);
    EXPECT_EQ(FP_DecimalToInt<Int>("-1987654321.23456789", 8), -198765432123456789);
    EXPECT_EQ(FP_DecimalToInt<Int>("-21987654321.23456789", 8), -2198765432123456789);
    EXPECT_EQ(FP_DecimalToInt<Int>("-21987654321.2345678", 8), -2198765432123456780);
    EXPECT_EQ(FP_DecimalToInt<Int>("-21987654321.234567", 8), -2198765432123456700);
    EXPECT_EQ(FP_DecimalToInt<Int>("-21987654321.23456", 8), -2198765432123456000);
    EXPECT_EQ(FP_DecimalToInt<Int>("-21987654321.2345", 8), -2198765432123450000);
    EXPECT_EQ(FP_DecimalToInt<Int>("-21987654321.234", 8), -2198765432123400000);
    EXPECT_EQ(FP_DecimalToInt<Int>("-21987654321.23", 8), -2198765432123000000);
    EXPECT_EQ(FP_DecimalToInt<Int>("-21987654321.2", 8), -2198765432120000000);
    EXPECT_EQ(FP_DecimalToInt<Int>("-21987654321.", 8), -2198765432100000000);
    EXPECT_EQ(FP_DecimalToInt<Int>("-21987654321.0", 8), -2198765432100000000);
    EXPECT_EQ(FP_DecimalToInt<Int>("-21987654321.00", 8), -2198765432100000000);
    EXPECT_EQ(FP_DecimalToInt<Int>("-21987654321.000", 8), -2198765432100000000);
    EXPECT_EQ(FP_DecimalToInt<Int>("-21987654321.0000", 8), -2198765432100000000);
    EXPECT_EQ(FP_DecimalToInt<Int>("-21987654321.00000", 8), -2198765432100000000);
    EXPECT_EQ(FP_DecimalToInt<Int>("-21987654321.000000", 8), -2198765432100000000);
    EXPECT_EQ(FP_DecimalToInt<Int>("-21987654321.0000000", 8), -2198765432100000000);
    EXPECT_EQ(FP_DecimalToInt<Int>("-21987654321.00000000", 8), -2198765432100000000);
    EXPECT_ANY_THROW(FP_DecimalToInt<Int>("-", 8));
    EXPECT_ANY_THROW(FP_DecimalToInt<Int>("-21987654321.000000000", 8));
    EXPECT_ANY_THROW(FP_DecimalToInt<Int>("-1.234567891", 8));
    EXPECT_ANY_THROW(FP_DecimalToInt<Int>("-1..234567891", 8));
    EXPECT_ANY_THROW(FP_DecimalToInt<Int>("-1.234567891,", 8));
    EXPECT_ANY_THROW(FP_DecimalToInt<Int>("-1.23a4567891,", 8));
    EXPECT_ANY_THROW(FP_DecimalToInt<Int>("-1.23-4567891", 8));
    EXPECT_ANY_THROW(FP_DecimalToInt<Int>("-1.23e4567891", 8));

    EXPECT_EQ(FP_DecimalToInt<Int>("987654321", 0), 987654321);
    EXPECT_EQ(FP_DecimalToInt<Int>("87654321", 0), 87654321);
    EXPECT_EQ(FP_DecimalToInt<Int>("7654321", 0), 7654321);
    EXPECT_EQ(FP_DecimalToInt<Int>("654321", 0), 654321);
    EXPECT_EQ(FP_DecimalToInt<Int>("54321", 0), 54321);
    EXPECT_EQ(FP_DecimalToInt<Int>("4321", 0), 4321);
    EXPECT_EQ(FP_DecimalToInt<Int>("321", 0), 321);
    EXPECT_EQ(FP_DecimalToInt<Int>("21", 0), 21);
    EXPECT_EQ(FP_DecimalToInt<Int>("1", 0), 1);
    EXPECT_ANY_THROW(FP_DecimalToInt<Int>("1.2", 0));
    EXPECT_ANY_THROW(FP_DecimalToInt<Int>("1.23", 0));
    EXPECT_ANY_THROW(FP_DecimalToInt<Int>("1.234", 0));
    EXPECT_ANY_THROW(FP_DecimalToInt<Int>("1.2345", 0));
    EXPECT_ANY_THROW(FP_DecimalToInt<Int>("1.23456", 0));
    EXPECT_ANY_THROW(FP_DecimalToInt<Int>("1.234567", 0));
    EXPECT_ANY_THROW(FP_DecimalToInt<Int>("1.2345678", 0));
    EXPECT_ANY_THROW(FP_DecimalToInt<Int>("1.23456789", 0));
    EXPECT_ANY_THROW(FP_DecimalToInt<Int>("21.23456789", 0));
    EXPECT_ANY_THROW(FP_DecimalToInt<Int>("321.23456789", 0));
    EXPECT_ANY_THROW(FP_DecimalToInt<Int>("4321.23456789", 0));
    EXPECT_ANY_THROW(FP_DecimalToInt<Int>("54321.23456789", 0));
    EXPECT_ANY_THROW(FP_DecimalToInt<Int>("654321.23456789", 0));
    EXPECT_ANY_THROW(FP_DecimalToInt<Int>("7654321.23456789", 0));
    EXPECT_ANY_THROW(FP_DecimalToInt<Int>("87654321.23456789", 0));
    EXPECT_ANY_THROW(FP_DecimalToInt<Int>("987654321.23456789", 0));
    EXPECT_ANY_THROW(FP_DecimalToInt<Int>("1987654321.23456789", 0));
    EXPECT_ANY_THROW(FP_DecimalToInt<Int>("21987654321.23456789", 0));
    EXPECT_ANY_THROW(FP_DecimalToInt<Int>("21987654321.2345678", 0));
    EXPECT_ANY_THROW(FP_DecimalToInt<Int>("21987654321.234567", 0));
    EXPECT_ANY_THROW(FP_DecimalToInt<Int>("21987654321.23456", 0));
    EXPECT_ANY_THROW(FP_DecimalToInt<Int>("21987654321.2345", 0));
    EXPECT_ANY_THROW(FP_DecimalToInt<Int>("21987654321.234", 0));
    EXPECT_ANY_THROW(FP_DecimalToInt<Int>("21987654321.23", 0));
    EXPECT_ANY_THROW(FP_DecimalToInt<Int>("21987654321.2", 0));
    EXPECT_EQ(FP_DecimalToInt<Int>("21987654321.", 0), 21987654321);
    EXPECT_ANY_THROW(FP_DecimalToInt<Int>("21987654321.0", 0));
    EXPECT_ANY_THROW(FP_DecimalToInt<Int>("21987654321.00", 0));
    EXPECT_ANY_THROW(FP_DecimalToInt<Int>("21987654321.000", 0));
    EXPECT_ANY_THROW(FP_DecimalToInt<Int>("21987654321.0000", 0));
    EXPECT_ANY_THROW(FP_DecimalToInt<Int>("21987654321.00000", 0));
    EXPECT_ANY_THROW(FP_DecimalToInt<Int>("21987654321.000000", 0));
    EXPECT_ANY_THROW(FP_DecimalToInt<Int>("21987654321.0000000", 0));
    EXPECT_ANY_THROW(FP_DecimalToInt<Int>("21987654321.00000000", 0));
    EXPECT_EQ(FP_DecimalToInt<Int>("", 0), 0);
    EXPECT_ANY_THROW(FP_DecimalToInt<Int>(" ", 0));
    EXPECT_ANY_THROW(FP_DecimalToInt<Int>("21987654321.000000000", 0));
    EXPECT_ANY_THROW(FP_DecimalToInt<Int>("1.234567891", 0));
    EXPECT_ANY_THROW(FP_DecimalToInt<Int>("1..234567891", 0));
    EXPECT_ANY_THROW(FP_DecimalToInt<Int>("1.234567891,", 0));
    EXPECT_ANY_THROW(FP_DecimalToInt<Int>("1.23a4567891,", 0));
    EXPECT_ANY_THROW(FP_DecimalToInt<Int>("1.23-4567891", 0));
    EXPECT_ANY_THROW(FP_DecimalToInt<Int>("1.23e4567891", 0));

    EXPECT_EQ(FP_DecimalToInt<Int>("-987654321", 0), -987654321);
    EXPECT_EQ(FP_DecimalToInt<Int>("-87654321", 0), -87654321);
    EXPECT_EQ(FP_DecimalToInt<Int>("-7654321", 0), -7654321);
    EXPECT_EQ(FP_DecimalToInt<Int>("-654321", 0), -654321);
    EXPECT_EQ(FP_DecimalToInt<Int>("-54321", 0), -54321);
    EXPECT_EQ(FP_DecimalToInt<Int>("-4321", 0), -4321);
    EXPECT_EQ(FP_DecimalToInt<Int>("-321", 0), -321);
    EXPECT_EQ(FP_DecimalToInt<Int>("-21", 0), -21);
    EXPECT_EQ(FP_DecimalToInt<Int>("-1", 0), -1);
    EXPECT_ANY_THROW(FP_DecimalToInt<Int>("-1.2", 0));
    EXPECT_ANY_THROW(FP_DecimalToInt<Int>("-1.23", 0));
    EXPECT_ANY_THROW(FP_DecimalToInt<Int>("-1.234", 0));
    EXPECT_ANY_THROW(FP_DecimalToInt<Int>("-1.2345", 0));
    EXPECT_ANY_THROW(FP_DecimalToInt<Int>("-1.23456", 0));
    EXPECT_ANY_THROW(FP_DecimalToInt<Int>("-1.234567", 0));
    EXPECT_ANY_THROW(FP_DecimalToInt<Int>("-1.2345678", 0));
    EXPECT_ANY_THROW(FP_DecimalToInt<Int>("-1.23456789", 0));
    EXPECT_ANY_THROW(FP_DecimalToInt<Int>("-21.23456789", 0));
    EXPECT_ANY_THROW(FP_DecimalToInt<Int>("-321.23456789", 0));
    EXPECT_ANY_THROW(FP_DecimalToInt<Int>("-4321.23456789", 0));
    EXPECT_ANY_THROW(FP_DecimalToInt<Int>("-54321.23456789", 0));
    EXPECT_ANY_THROW(FP_DecimalToInt<Int>("-654321.23456789", 0));
    EXPECT_ANY_THROW(FP_DecimalToInt<Int>("-7654321.23456789", 0));
    EXPECT_ANY_THROW(FP_DecimalToInt<Int>("-87654321.23456789", 0));
    EXPECT_ANY_THROW(FP_DecimalToInt<Int>("-987654321.23456789", 0));
    EXPECT_ANY_THROW(FP_DecimalToInt<Int>("-1987654321.23456789", 0));
    EXPECT_ANY_THROW(FP_DecimalToInt<Int>("-21987654321.23456789", 0));
    EXPECT_ANY_THROW(FP_DecimalToInt<Int>("-21987654321.2345678", 0));
    EXPECT_ANY_THROW(FP_DecimalToInt<Int>("-21987654321.234567", 0));
    EXPECT_ANY_THROW(FP_DecimalToInt<Int>("-21987654321.23456", 0));
    EXPECT_ANY_THROW(FP_DecimalToInt<Int>("-21987654321.2345", 0));
    EXPECT_ANY_THROW(FP_DecimalToInt<Int>("-21987654321.234", 0));
    EXPECT_ANY_THROW(FP_DecimalToInt<Int>("-21987654321.23", 0));
    EXPECT_ANY_THROW(FP_DecimalToInt<Int>("-21987654321.2", 0));
    EXPECT_EQ(FP_DecimalToInt<Int>("-21987654321.", 0), -21987654321);
    EXPECT_ANY_THROW(FP_DecimalToInt<Int>("-21987654321.0", 0));
    EXPECT_ANY_THROW(FP_DecimalToInt<Int>("-21987654321.00", 0));
    EXPECT_ANY_THROW(FP_DecimalToInt<Int>("-21987654321.000", 0));
    EXPECT_ANY_THROW(FP_DecimalToInt<Int>("-21987654321.0000", 0));
    EXPECT_ANY_THROW(FP_DecimalToInt<Int>("-21987654321.00000", 0));
    EXPECT_ANY_THROW(FP_DecimalToInt<Int>("-21987654321.000000", 0));
    EXPECT_ANY_THROW(FP_DecimalToInt<Int>("-21987654321.0000000", 0));
    EXPECT_ANY_THROW(FP_DecimalToInt<Int>("-21987654321.00000000", 0));
    EXPECT_ANY_THROW(FP_DecimalToInt<Int>("-", 0));
    EXPECT_ANY_THROW(FP_DecimalToInt<Int>("- ", 0));
    EXPECT_ANY_THROW(FP_DecimalToInt<Int>("-21987654321.000000000", 0));
    EXPECT_ANY_THROW(FP_DecimalToInt<Int>("-1.234567891", 0));
    EXPECT_ANY_THROW(FP_DecimalToInt<Int>("-1..234567891", 0));
    EXPECT_ANY_THROW(FP_DecimalToInt<Int>("-1.234567891,", 0));
    EXPECT_ANY_THROW(FP_DecimalToInt<Int>("-1.23a4567891,", 0));
    EXPECT_ANY_THROW(FP_DecimalToInt<Int>("-1.23-4567891", 0));
    EXPECT_ANY_THROW(FP_DecimalToInt<Int>("-1.23e4567891", 0));

    EXPECT_EQ(FP_DecimalToInt<Int>("987654321", 1), 9876543210);
    EXPECT_EQ(FP_DecimalToInt<Int>("87654321", 1), 876543210);
    EXPECT_EQ(FP_DecimalToInt<Int>("7654321", 1), 76543210);
    EXPECT_EQ(FP_DecimalToInt<Int>("654321", 1), 6543210);
    EXPECT_EQ(FP_DecimalToInt<Int>("54321", 1), 543210);
    EXPECT_EQ(FP_DecimalToInt<Int>("4321", 1), 43210);
    EXPECT_EQ(FP_DecimalToInt<Int>("321", 1), 3210);
    EXPECT_EQ(FP_DecimalToInt<Int>("21", 1), 210);
    EXPECT_EQ(FP_DecimalToInt<Int>("1", 1), 10);
    EXPECT_EQ(FP_DecimalToInt<Int>("1.2", 1), 12);
    EXPECT_ANY_THROW(FP_DecimalToInt<Int>("1.23", 1));
    EXPECT_ANY_THROW(FP_DecimalToInt<Int>("1.234", 1));
    EXPECT_ANY_THROW(FP_DecimalToInt<Int>("1.2345", 1));
    EXPECT_ANY_THROW(FP_DecimalToInt<Int>("1.23456", 1));
    EXPECT_ANY_THROW(FP_DecimalToInt<Int>("1.234567", 1));
    EXPECT_ANY_THROW(FP_DecimalToInt<Int>("1.2345678", 1));
    EXPECT_ANY_THROW(FP_DecimalToInt<Int>("1.23456789", 1));
    EXPECT_ANY_THROW(FP_DecimalToInt<Int>("21.23456789", 1));
    EXPECT_ANY_THROW(FP_DecimalToInt<Int>("321.23456789", 1));
    EXPECT_ANY_THROW(FP_DecimalToInt<Int>("4321.23456789", 1));
    EXPECT_ANY_THROW(FP_DecimalToInt<Int>("54321.23456789", 1));
    EXPECT_ANY_THROW(FP_DecimalToInt<Int>("654321.23456789", 1));
    EXPECT_ANY_THROW(FP_DecimalToInt<Int>("7654321.23456789", 1));
    EXPECT_ANY_THROW(FP_DecimalToInt<Int>("87654321.23456789", 1));
    EXPECT_ANY_THROW(FP_DecimalToInt<Int>("987654321.23456789", 1));
    EXPECT_ANY_THROW(FP_DecimalToInt<Int>("1987654321.23456789", 1));
    EXPECT_ANY_THROW(FP_DecimalToInt<Int>("21987654321.23456789", 1));
    EXPECT_ANY_THROW(FP_DecimalToInt<Int>("21987654321.2345678", 1));
    EXPECT_ANY_THROW(FP_DecimalToInt<Int>("21987654321.234567", 1));
    EXPECT_ANY_THROW(FP_DecimalToInt<Int>("21987654321.23456", 1));
    EXPECT_ANY_THROW(FP_DecimalToInt<Int>("21987654321.2345", 1));
    EXPECT_ANY_THROW(FP_DecimalToInt<Int>("21987654321.234", 1));
    EXPECT_ANY_THROW(FP_DecimalToInt<Int>("21987654321.23", 1));
    EXPECT_EQ(FP_DecimalToInt<Int>("21987654321.2", 1), 219876543212);
    EXPECT_EQ(FP_DecimalToInt<Int>("21987654321.", 1), 219876543210);
    EXPECT_EQ(FP_DecimalToInt<Int>("21987654321.0", 1), 219876543210);
    EXPECT_ANY_THROW(FP_DecimalToInt<Int>("21987654321.00", 1));
    EXPECT_ANY_THROW(FP_DecimalToInt<Int>("21987654321.000", 1));
    EXPECT_ANY_THROW(FP_DecimalToInt<Int>("21987654321.0000", 1));
    EXPECT_ANY_THROW(FP_DecimalToInt<Int>("21987654321.00000", 1));
    EXPECT_ANY_THROW(FP_DecimalToInt<Int>("21987654321.000000", 1));
    EXPECT_ANY_THROW(FP_DecimalToInt<Int>("21987654321.0000000", 1));
    EXPECT_ANY_THROW(FP_DecimalToInt<Int>("21987654321.00000000", 1));
    EXPECT_EQ(FP_DecimalToInt<Int>("", 1), 0);
    EXPECT_ANY_THROW(FP_DecimalToInt<Int>(" ", 1));
    EXPECT_ANY_THROW(FP_DecimalToInt<Int>("21987654321.000000000", 1));
    EXPECT_ANY_THROW(FP_DecimalToInt<Int>("1.234567891", 1));
    EXPECT_ANY_THROW(FP_DecimalToInt<Int>("1..234567891", 1));
    EXPECT_ANY_THROW(FP_DecimalToInt<Int>("1.234567891,", 1));
    EXPECT_ANY_THROW(FP_DecimalToInt<Int>("1.23a4567891,", 1));
    EXPECT_ANY_THROW(FP_DecimalToInt<Int>("1.23-4567891", 1));
    EXPECT_ANY_THROW(FP_DecimalToInt<Int>("1.23e4567891", 1));

    EXPECT_EQ(FP_DecimalToInt<Int>("-987654321", 1), -9876543210);
    EXPECT_EQ(FP_DecimalToInt<Int>("-87654321", 1), -876543210);
    EXPECT_EQ(FP_DecimalToInt<Int>("-7654321", 1), -76543210);
    EXPECT_EQ(FP_DecimalToInt<Int>("-654321", 1), -6543210);
    EXPECT_EQ(FP_DecimalToInt<Int>("-54321", 1), -543210);
    EXPECT_EQ(FP_DecimalToInt<Int>("-4321", 1), -43210);
    EXPECT_EQ(FP_DecimalToInt<Int>("-321", 1), -3210);
    EXPECT_EQ(FP_DecimalToInt<Int>("-21", 1), -210);
    EXPECT_EQ(FP_DecimalToInt<Int>("-1", 1), -10);
    EXPECT_EQ(FP_DecimalToInt<Int>("-1.2", 1), -12);
    EXPECT_ANY_THROW(FP_DecimalToInt<Int>("-1.23", 1));
    EXPECT_ANY_THROW(FP_DecimalToInt<Int>("-1.234", 1));
    EXPECT_ANY_THROW(FP_DecimalToInt<Int>("-1.2345", 1));
    EXPECT_ANY_THROW(FP_DecimalToInt<Int>("-1.23456", 1));
    EXPECT_ANY_THROW(FP_DecimalToInt<Int>("-1.234567", 1));
    EXPECT_ANY_THROW(FP_DecimalToInt<Int>("-1.2345678", 1));
    EXPECT_ANY_THROW(FP_DecimalToInt<Int>("-1.23456789", 1));
    EXPECT_ANY_THROW(FP_DecimalToInt<Int>("-21.23456789", 1));
    EXPECT_ANY_THROW(FP_DecimalToInt<Int>("-321.23456789", 1));
    EXPECT_ANY_THROW(FP_DecimalToInt<Int>("-4321.23456789", 1));
    EXPECT_ANY_THROW(FP_DecimalToInt<Int>("-54321.23456789", 1));
    EXPECT_ANY_THROW(FP_DecimalToInt<Int>("-654321.23456789", 1));
    EXPECT_ANY_THROW(FP_DecimalToInt<Int>("-7654321.23456789", 1));
    EXPECT_ANY_THROW(FP_DecimalToInt<Int>("-87654321.23456789", 1));
    EXPECT_ANY_THROW(FP_DecimalToInt<Int>("-987654321.23456789", 1));
    EXPECT_ANY_THROW(FP_DecimalToInt<Int>("-1987654321.23456789", 1));
    EXPECT_ANY_THROW(FP_DecimalToInt<Int>("-21987654321.23456789", 1));
    EXPECT_ANY_THROW(FP_DecimalToInt<Int>("-21987654321.2345678", 1));
    EXPECT_ANY_THROW(FP_DecimalToInt<Int>("-21987654321.234567", 1));
    EXPECT_ANY_THROW(FP_DecimalToInt<Int>("-21987654321.23456", 1));
    EXPECT_ANY_THROW(FP_DecimalToInt<Int>("-21987654321.2345", 1));
    EXPECT_ANY_THROW(FP_DecimalToInt<Int>("-21987654321.234", 1));
    EXPECT_ANY_THROW(FP_DecimalToInt<Int>("-21987654321.23", 1));
    EXPECT_EQ(FP_DecimalToInt<Int>("-21987654321.2", 1), -219876543212);
    EXPECT_EQ(FP_DecimalToInt<Int>("-21987654321.", 1), -219876543210);
    EXPECT_EQ(FP_DecimalToInt<Int>("-21987654321.0", 1), -219876543210);
    EXPECT_ANY_THROW(FP_DecimalToInt<Int>("-21987654321.00", 1));
    EXPECT_ANY_THROW(FP_DecimalToInt<Int>("-21987654321.000", 1));
    EXPECT_ANY_THROW(FP_DecimalToInt<Int>("-21987654321.0000", 1));
    EXPECT_ANY_THROW(FP_DecimalToInt<Int>("-21987654321.00000", 1));
    EXPECT_ANY_THROW(FP_DecimalToInt<Int>("-21987654321.000000", 1));
    EXPECT_ANY_THROW(FP_DecimalToInt<Int>("-21987654321.0000000", 1));
    EXPECT_ANY_THROW(FP_DecimalToInt<Int>("-21987654321.00000000", 1));
    EXPECT_ANY_THROW(FP_DecimalToInt<Int>("-", 1));
    EXPECT_ANY_THROW(FP_DecimalToInt<Int>("- ", 1));
    EXPECT_ANY_THROW(FP_DecimalToInt<Int>("-21987654321.000000000", 1));
    EXPECT_ANY_THROW(FP_DecimalToInt<Int>("-1.234567891", 1));
    EXPECT_ANY_THROW(FP_DecimalToInt<Int>("-1..234567891", 1));
    EXPECT_ANY_THROW(FP_DecimalToInt<Int>("-1.234567891,", 1));
    EXPECT_ANY_THROW(FP_DecimalToInt<Int>("-1.23a4567891,", 1));
    EXPECT_ANY_THROW(FP_DecimalToInt<Int>("-1.23-4567891", 1));
    EXPECT_ANY_THROW(FP_DecimalToInt<Int>("-1.23e4567891", 1));

    EXPECT_EQ(FP_DecimalToInt<Int>("-1", 0), -1);
    EXPECT_EQ(FP_DecimalToInt<Int>("-12", 0), -12);
    EXPECT_EQ(FP_DecimalToInt<Int>("-123", 0), -123);
    EXPECT_EQ(FP_DecimalToInt<Int>("-123.", 0), -123);
    EXPECT_ANY_THROW(FP_DecimalToInt<Int>("-123.0", 0));
    EXPECT_ANY_THROW(FP_DecimalToInt<Int>("-123.01", 0));
    EXPECT_ANY_THROW(FP_DecimalToInt<Int>("-123.012", 0));

    EXPECT_EQ(FP_DecimalToInt<Int>("1", 0), 1);
    EXPECT_EQ(FP_DecimalToInt<Int>("12", 0), 12);
    EXPECT_EQ(FP_DecimalToInt<Int>("123", 0), 123);
    EXPECT_EQ(FP_DecimalToInt<Int>("123.", 0), 123);
    EXPECT_ANY_THROW(FP_DecimalToInt<Int>("123.0", 0));
    EXPECT_ANY_THROW(FP_DecimalToInt<Int>("123.01", 0));
    EXPECT_ANY_THROW(FP_DecimalToInt<Int>("123.012", 0));

    EXPECT_EQ(FP_DecimalToInt<Int>("-1", 1), -10);
    EXPECT_EQ(FP_DecimalToInt<Int>("-12", 1), -120);
    EXPECT_EQ(FP_DecimalToInt<Int>("-123", 1), -1230);
    EXPECT_EQ(FP_DecimalToInt<Int>("-123.", 1), -1230);

    EXPECT_EQ(FP_DecimalToInt<Int>("1", 1), 10);
    EXPECT_EQ(FP_DecimalToInt<Int>("12", 1), 120);
    EXPECT_EQ(FP_DecimalToInt<Int>("123", 1), 1230);
    EXPECT_EQ(FP_DecimalToInt<Int>("123.", 1), 1230);

    EXPECT_EQ(FP_IntToDecimal<Int>(0, 8), "0");
    EXPECT_EQ(FP_IntToDecimal<Int>(1, 8), "0.00000001");
    EXPECT_EQ(FP_IntToDecimal<Int>(12, 8), "0.00000012");
    EXPECT_EQ(FP_IntToDecimal<Int>(123, 8), "0.00000123");
    EXPECT_EQ(FP_IntToDecimal<Int>(1234, 8), "0.00001234");
    EXPECT_EQ(FP_IntToDecimal<Int>(12345, 8), "0.00012345");
    EXPECT_EQ(FP_IntToDecimal<Int>(123456, 8), "0.00123456");
    EXPECT_EQ(FP_IntToDecimal<Int>(1234567, 8), "0.01234567");
    EXPECT_EQ(FP_IntToDecimal<Int>(12345678, 8), "0.12345678");
    EXPECT_EQ(FP_IntToDecimal<Int>(112345678, 8), "1.12345678");
    EXPECT_EQ(FP_IntToDecimal<Int>(2112345678, 8), "21.12345678");
    EXPECT_EQ(FP_IntToDecimal<Int>(32112345678, 8), "321.12345678");
    EXPECT_EQ(FP_IntToDecimal<Int>(432112345678, 8), "4321.12345678");
    EXPECT_EQ(FP_IntToDecimal<Int>(5432112345678, 8), "54321.12345678");
    EXPECT_EQ(FP_IntToDecimal<Int>(65432112345678, 8), "654321.12345678");
    EXPECT_EQ(FP_IntToDecimal<Int>(765432112345678, 8), "7654321.12345678");
    EXPECT_EQ(FP_IntToDecimal<Int>(8765432112345678, 8), "87654321.12345678");
    EXPECT_EQ(FP_IntToDecimal<Int>(98765432112345678, 8), "987654321.12345678");
    EXPECT_EQ(FP_IntToDecimal<Int>(10, 8), "0.0000001");
    EXPECT_EQ(FP_IntToDecimal<Int>(120, 8), "0.0000012");
    EXPECT_EQ(FP_IntToDecimal<Int>(1230, 8), "0.0000123");
    EXPECT_EQ(FP_IntToDecimal<Int>(12340, 8), "0.0001234");
    EXPECT_EQ(FP_IntToDecimal<Int>(123450, 8), "0.0012345");
    EXPECT_EQ(FP_IntToDecimal<Int>(1234560, 8), "0.0123456");
    EXPECT_EQ(FP_IntToDecimal<Int>(12345670, 8), "0.1234567");
    EXPECT_EQ(FP_IntToDecimal<Int>(123456780, 8), "1.2345678");
    EXPECT_EQ(FP_IntToDecimal<Int>(1123456780, 8), "11.2345678");
    EXPECT_EQ(FP_IntToDecimal<Int>(100, 8), "0.000001");
    EXPECT_EQ(FP_IntToDecimal<Int>(1200, 8), "0.000012");
    EXPECT_EQ(FP_IntToDecimal<Int>(12300, 8), "0.000123");
    EXPECT_EQ(FP_IntToDecimal<Int>(123400, 8), "0.001234");
    EXPECT_EQ(FP_IntToDecimal<Int>(1234500, 8), "0.012345");
    EXPECT_EQ(FP_IntToDecimal<Int>(12345600, 8), "0.123456");
    EXPECT_EQ(FP_IntToDecimal<Int>(123456700, 8), "1.234567");
    EXPECT_EQ(FP_IntToDecimal<Int>(1234567800, 8), "12.345678");
    EXPECT_EQ(FP_IntToDecimal<Int>(11234567800, 8), "112.345678");

    EXPECT_EQ(FP_IntToDecimal<Int>(-0, 8), "0");
    EXPECT_EQ(FP_IntToDecimal<Int>(-1, 8), "-0.00000001");
    EXPECT_EQ(FP_IntToDecimal<Int>(-12, 8), "-0.00000012");
    EXPECT_EQ(FP_IntToDecimal<Int>(-123, 8), "-0.00000123");
    EXPECT_EQ(FP_IntToDecimal<Int>(-1234, 8), "-0.00001234");
    EXPECT_EQ(FP_IntToDecimal<Int>(-12345, 8), "-0.00012345");
    EXPECT_EQ(FP_IntToDecimal<Int>(-123456, 8), "-0.00123456");
    EXPECT_EQ(FP_IntToDecimal<Int>(-1234567, 8), "-0.01234567");
    EXPECT_EQ(FP_IntToDecimal<Int>(-12345678, 8), "-0.12345678");
    EXPECT_EQ(FP_IntToDecimal<Int>(-112345678, 8), "-1.12345678");
    EXPECT_EQ(FP_IntToDecimal<Int>(-2112345678, 8), "-21.12345678");
    EXPECT_EQ(FP_IntToDecimal<Int>(-32112345678, 8), "-321.12345678");
    EXPECT_EQ(FP_IntToDecimal<Int>(-432112345678, 8), "-4321.12345678");
    EXPECT_EQ(FP_IntToDecimal<Int>(-5432112345678, 8), "-54321.12345678");
    EXPECT_EQ(FP_IntToDecimal<Int>(-65432112345678, 8), "-654321.12345678");
    EXPECT_EQ(FP_IntToDecimal<Int>(-765432112345678, 8), "-7654321.12345678");
    EXPECT_EQ(FP_IntToDecimal<Int>(-8765432112345678, 8), "-87654321.12345678");
    EXPECT_EQ(FP_IntToDecimal<Int>(-98765432112345678, 8), "-987654321.12345678");
    EXPECT_EQ(FP_IntToDecimal<Int>(-10, 8), "-0.0000001");
    EXPECT_EQ(FP_IntToDecimal<Int>(-120, 8), "-0.0000012");
    EXPECT_EQ(FP_IntToDecimal<Int>(-1230, 8), "-0.0000123");
    EXPECT_EQ(FP_IntToDecimal<Int>(-12340, 8), "-0.0001234");
    EXPECT_EQ(FP_IntToDecimal<Int>(-123450, 8), "-0.0012345");
    EXPECT_EQ(FP_IntToDecimal<Int>(-1234560, 8), "-0.0123456");
    EXPECT_EQ(FP_IntToDecimal<Int>(-12345670, 8), "-0.1234567");
    EXPECT_EQ(FP_IntToDecimal<Int>(-123456780, 8), "-1.2345678");
    EXPECT_EQ(FP_IntToDecimal<Int>(-1123456780, 8), "-11.2345678");
    EXPECT_EQ(FP_IntToDecimal<Int>(-100, 8), "-0.000001");
    EXPECT_EQ(FP_IntToDecimal<Int>(-1200, 8), "-0.000012");
    EXPECT_EQ(FP_IntToDecimal<Int>(-12300, 8), "-0.000123");
    EXPECT_EQ(FP_IntToDecimal<Int>(-123400, 8), "-0.001234");
    EXPECT_EQ(FP_IntToDecimal<Int>(-1234500, 8), "-0.012345");
    EXPECT_EQ(FP_IntToDecimal<Int>(-12345600, 8), "-0.123456");
    EXPECT_EQ(FP_IntToDecimal<Int>(-123456700, 8), "-1.234567");
    EXPECT_EQ(FP_IntToDecimal<Int>(-1234567800, 8), "-12.345678");
    EXPECT_EQ(FP_IntToDecimal<Int>(-11234567800, 8), "-112.345678");

    EXPECT_EQ(FP_IntToDecimal<Int>(1, 0), "1");
    EXPECT_EQ(FP_IntToDecimal<Int>(12, 0), "12");
    EXPECT_EQ(FP_IntToDecimal<Int>(123, 0), "123");
    EXPECT_EQ(FP_IntToDecimal<Int>(1234, 0), "1234");
    EXPECT_EQ(FP_IntToDecimal<Int>(12345, 0), "12345");
    EXPECT_EQ(FP_IntToDecimal<Int>(123456, 0), "123456");
    EXPECT_EQ(FP_IntToDecimal<Int>(1234567, 0), "1234567");
    EXPECT_EQ(FP_IntToDecimal<Int>(12345678, 0), "12345678");
    EXPECT_EQ(FP_IntToDecimal<Int>(123456789, 0), "123456789");
    EXPECT_EQ(FP_IntToDecimal<Int>(1234567890, 0), "1234567890");
    EXPECT_EQ(FP_IntToDecimal<Int>(12345678901, 0), "12345678901");
    EXPECT_EQ(FP_IntToDecimal<Int>(123456789012, 0), "123456789012");
    EXPECT_EQ(FP_IntToDecimal<Int>(1234567890123, 0), "1234567890123");
    EXPECT_EQ(FP_IntToDecimal<Int>(10, 0), "10");
    EXPECT_EQ(FP_IntToDecimal<Int>(120, 0), "120");
    EXPECT_EQ(FP_IntToDecimal<Int>(1230, 0), "1230");
    EXPECT_EQ(FP_IntToDecimal<Int>(12340, 0), "12340");
    EXPECT_EQ(FP_IntToDecimal<Int>(123450, 0), "123450");
    EXPECT_EQ(FP_IntToDecimal<Int>(1234560, 0), "1234560");
    EXPECT_EQ(FP_IntToDecimal<Int>(12345670, 0), "12345670");
    EXPECT_EQ(FP_IntToDecimal<Int>(123456780, 0), "123456780");
    EXPECT_EQ(FP_IntToDecimal<Int>(1234567890, 0), "1234567890");
    EXPECT_EQ(FP_IntToDecimal<Int>(12345678900, 0), "12345678900");
    EXPECT_EQ(FP_IntToDecimal<Int>(123456789010, 0), "123456789010");
    EXPECT_EQ(FP_IntToDecimal<Int>(1234567890120, 0), "1234567890120");
    EXPECT_EQ(FP_IntToDecimal<Int>(12345678901230, 0), "12345678901230");
    EXPECT_EQ(FP_IntToDecimal<Int>(100, 0), "100");
    EXPECT_EQ(FP_IntToDecimal<Int>(1200, 0), "1200");
    EXPECT_EQ(FP_IntToDecimal<Int>(12300, 0), "12300");
    EXPECT_EQ(FP_IntToDecimal<Int>(123400, 0), "123400");
    EXPECT_EQ(FP_IntToDecimal<Int>(1234500, 0), "1234500");
    EXPECT_EQ(FP_IntToDecimal<Int>(12345600, 0), "12345600");
    EXPECT_EQ(FP_IntToDecimal<Int>(123456700, 0), "123456700");
    EXPECT_EQ(FP_IntToDecimal<Int>(1234567800, 0), "1234567800");
    EXPECT_EQ(FP_IntToDecimal<Int>(12345678900, 0), "12345678900");
    EXPECT_EQ(FP_IntToDecimal<Int>(123456789000, 0), "123456789000");
    EXPECT_EQ(FP_IntToDecimal<Int>(1234567890100, 0), "1234567890100");
    EXPECT_EQ(FP_IntToDecimal<Int>(12345678901200, 0), "12345678901200");
    EXPECT_EQ(FP_IntToDecimal<Int>(123456789012300, 0), "123456789012300");

    EXPECT_EQ(FP_IntToDecimal<Int>(-1, 0), "-1");
    EXPECT_EQ(FP_IntToDecimal<Int>(-12, 0), "-12");
    EXPECT_EQ(FP_IntToDecimal<Int>(-123, 0), "-123");
    EXPECT_EQ(FP_IntToDecimal<Int>(-1234, 0), "-1234");
    EXPECT_EQ(FP_IntToDecimal<Int>(-12345, 0), "-12345");
    EXPECT_EQ(FP_IntToDecimal<Int>(-123456, 0), "-123456");
    EXPECT_EQ(FP_IntToDecimal<Int>(-1234567, 0), "-1234567");
    EXPECT_EQ(FP_IntToDecimal<Int>(-12345678, 0), "-12345678");
    EXPECT_EQ(FP_IntToDecimal<Int>(-123456789, 0), "-123456789");
    EXPECT_EQ(FP_IntToDecimal<Int>(-1234567890, 0), "-1234567890");
    EXPECT_EQ(FP_IntToDecimal<Int>(-12345678901, 0), "-12345678901");
    EXPECT_EQ(FP_IntToDecimal<Int>(-123456789012, 0), "-123456789012");
    EXPECT_EQ(FP_IntToDecimal<Int>(-1234567890123, 0), "-1234567890123");
    EXPECT_EQ(FP_IntToDecimal<Int>(-10, 0), "-10");
    EXPECT_EQ(FP_IntToDecimal<Int>(-120, 0), "-120");
    EXPECT_EQ(FP_IntToDecimal<Int>(-1230, 0), "-1230");
    EXPECT_EQ(FP_IntToDecimal<Int>(-12340, 0), "-12340");
    EXPECT_EQ(FP_IntToDecimal<Int>(-123450, 0), "-123450");
    EXPECT_EQ(FP_IntToDecimal<Int>(-1234560, 0), "-1234560");
    EXPECT_EQ(FP_IntToDecimal<Int>(-12345670, 0), "-12345670");
    EXPECT_EQ(FP_IntToDecimal<Int>(-123456780, 0), "-123456780");
    EXPECT_EQ(FP_IntToDecimal<Int>(-1234567890, 0), "-1234567890");
    EXPECT_EQ(FP_IntToDecimal<Int>(-12345678900, 0), "-12345678900");
    EXPECT_EQ(FP_IntToDecimal<Int>(-123456789010, 0), "-123456789010");
    EXPECT_EQ(FP_IntToDecimal<Int>(-1234567890120, 0), "-1234567890120");
    EXPECT_EQ(FP_IntToDecimal<Int>(-12345678901230, 0), "-12345678901230");
    EXPECT_EQ(FP_IntToDecimal<Int>(-100, 0), "-100");
    EXPECT_EQ(FP_IntToDecimal<Int>(-1200, 0), "-1200");
    EXPECT_EQ(FP_IntToDecimal<Int>(-12300, 0), "-12300");
    EXPECT_EQ(FP_IntToDecimal<Int>(-123400, 0), "-123400");
    EXPECT_EQ(FP_IntToDecimal<Int>(-1234500, 0), "-1234500");
    EXPECT_EQ(FP_IntToDecimal<Int>(-12345600, 0), "-12345600");
    EXPECT_EQ(FP_IntToDecimal<Int>(-123456700, 0), "-123456700");
    EXPECT_EQ(FP_IntToDecimal<Int>(-1234567800, 0), "-1234567800");
    EXPECT_EQ(FP_IntToDecimal<Int>(-12345678900, 0), "-12345678900");
    EXPECT_EQ(FP_IntToDecimal<Int>(-123456789000, 0), "-123456789000");
    EXPECT_EQ(FP_IntToDecimal<Int>(-1234567890100, 0), "-1234567890100");
    EXPECT_EQ(FP_IntToDecimal<Int>(-12345678901200, 0), "-12345678901200");
    EXPECT_EQ(FP_IntToDecimal<Int>(-123456789012300, 0), "-123456789012300");

    EXPECT_EQ(FP_IntToDecimal<Int>(1, 1), "0.1");
    EXPECT_EQ(FP_IntToDecimal<Int>(12, 1), "1.2");
    EXPECT_EQ(FP_IntToDecimal<Int>(123, 1), "12.3");
    EXPECT_EQ(FP_IntToDecimal<Int>(1234, 1), "123.4");
    EXPECT_EQ(FP_IntToDecimal<Int>(12345, 1), "1234.5");
    EXPECT_EQ(FP_IntToDecimal<Int>(123456, 1), "12345.6");
    EXPECT_EQ(FP_IntToDecimal<Int>(1234567, 1), "123456.7");
    EXPECT_EQ(FP_IntToDecimal<Int>(12345678, 1), "1234567.8");
    EXPECT_EQ(FP_IntToDecimal<Int>(123456789, 1), "12345678.9");
    EXPECT_EQ(FP_IntToDecimal<Int>(1234567890, 1), "123456789");
    EXPECT_EQ(FP_IntToDecimal<Int>(12345678901, 1), "1234567890.1");
    EXPECT_EQ(FP_IntToDecimal<Int>(123456789012, 1), "12345678901.2");
    EXPECT_EQ(FP_IntToDecimal<Int>(1234567890123, 1), "123456789012.3");
    EXPECT_EQ(FP_IntToDecimal<Int>(10, 1), "1");
    EXPECT_EQ(FP_IntToDecimal<Int>(120, 1), "12");
    EXPECT_EQ(FP_IntToDecimal<Int>(1230, 1), "123");
    EXPECT_EQ(FP_IntToDecimal<Int>(12340, 1), "1234");
    EXPECT_EQ(FP_IntToDecimal<Int>(123450, 1), "12345");
    EXPECT_EQ(FP_IntToDecimal<Int>(1234560, 1), "123456");
    EXPECT_EQ(FP_IntToDecimal<Int>(12345670, 1), "1234567");
    EXPECT_EQ(FP_IntToDecimal<Int>(123456780, 1), "12345678");
    EXPECT_EQ(FP_IntToDecimal<Int>(1234567890, 1), "123456789");
    EXPECT_EQ(FP_IntToDecimal<Int>(12345678900, 1), "1234567890");
    EXPECT_EQ(FP_IntToDecimal<Int>(123456789010, 1), "12345678901");
    EXPECT_EQ(FP_IntToDecimal<Int>(1234567890120, 1), "123456789012");
    EXPECT_EQ(FP_IntToDecimal<Int>(12345678901230, 1), "1234567890123");
    EXPECT_EQ(FP_IntToDecimal<Int>(100, 1), "10");
    EXPECT_EQ(FP_IntToDecimal<Int>(1200, 1), "120");
    EXPECT_EQ(FP_IntToDecimal<Int>(12300, 1), "1230");
    EXPECT_EQ(FP_IntToDecimal<Int>(123400, 1), "12340");
    EXPECT_EQ(FP_IntToDecimal<Int>(1234500, 1), "123450");
    EXPECT_EQ(FP_IntToDecimal<Int>(12345600, 1), "1234560");
    EXPECT_EQ(FP_IntToDecimal<Int>(123456700, 1), "12345670");
    EXPECT_EQ(FP_IntToDecimal<Int>(1234567800, 1), "123456780");
    EXPECT_EQ(FP_IntToDecimal<Int>(12345678900, 1), "1234567890");
    EXPECT_EQ(FP_IntToDecimal<Int>(123456789000, 1), "12345678900");
    EXPECT_EQ(FP_IntToDecimal<Int>(1234567890100, 1), "123456789010");
    EXPECT_EQ(FP_IntToDecimal<Int>(12345678901200, 1), "1234567890120");
    EXPECT_EQ(FP_IntToDecimal<Int>(123456789012300, 1), "12345678901230");

    EXPECT_EQ(FP_IntToDecimal<Int>(-1, 1), "-0.1");
    EXPECT_EQ(FP_IntToDecimal<Int>(-12, 1), "-1.2");
    EXPECT_EQ(FP_IntToDecimal<Int>(-123, 1), "-12.3");
    EXPECT_EQ(FP_IntToDecimal<Int>(-1234, 1), "-123.4");
    EXPECT_EQ(FP_IntToDecimal<Int>(-12345, 1), "-1234.5");
    EXPECT_EQ(FP_IntToDecimal<Int>(-123456, 1), "-12345.6");
    EXPECT_EQ(FP_IntToDecimal<Int>(-1234567, 1), "-123456.7");
    EXPECT_EQ(FP_IntToDecimal<Int>(-12345678, 1), "-1234567.8");
    EXPECT_EQ(FP_IntToDecimal<Int>(-123456789, 1), "-12345678.9");
    EXPECT_EQ(FP_IntToDecimal<Int>(-1234567890, 1), "-123456789");
    EXPECT_EQ(FP_IntToDecimal<Int>(-12345678901, 1), "-1234567890.1");
    EXPECT_EQ(FP_IntToDecimal<Int>(-123456789012, 1), "-12345678901.2");
    EXPECT_EQ(FP_IntToDecimal<Int>(-1234567890123, 1), "-123456789012.3");
    EXPECT_EQ(FP_IntToDecimal<Int>(-10, 1), "-1");
    EXPECT_EQ(FP_IntToDecimal<Int>(-120, 1), "-12");
    EXPECT_EQ(FP_IntToDecimal<Int>(-1230, 1), "-123");
    EXPECT_EQ(FP_IntToDecimal<Int>(-12340, 1), "-1234");
    EXPECT_EQ(FP_IntToDecimal<Int>(-123450, 1), "-12345");
    EXPECT_EQ(FP_IntToDecimal<Int>(-1234560, 1), "-123456");
    EXPECT_EQ(FP_IntToDecimal<Int>(-12345670, 1), "-1234567");
    EXPECT_EQ(FP_IntToDecimal<Int>(-123456780, 1), "-12345678");
    EXPECT_EQ(FP_IntToDecimal<Int>(-1234567890, 1), "-123456789");
    EXPECT_EQ(FP_IntToDecimal<Int>(-12345678900, 1), "-1234567890");
    EXPECT_EQ(FP_IntToDecimal<Int>(-123456789010, 1), "-12345678901");
    EXPECT_EQ(FP_IntToDecimal<Int>(-1234567890120, 1), "-123456789012");
    EXPECT_EQ(FP_IntToDecimal<Int>(-12345678901230, 1), "-1234567890123");
    EXPECT_EQ(FP_IntToDecimal<Int>(-100, 1), "-10");
    EXPECT_EQ(FP_IntToDecimal<Int>(-1200, 1), "-120");
    EXPECT_EQ(FP_IntToDecimal<Int>(-12300, 1), "-1230");
    EXPECT_EQ(FP_IntToDecimal<Int>(-123400, 1), "-12340");
    EXPECT_EQ(FP_IntToDecimal<Int>(-1234500, 1), "-123450");
    EXPECT_EQ(FP_IntToDecimal<Int>(-12345600, 1), "-1234560");
    EXPECT_EQ(FP_IntToDecimal<Int>(-123456700, 1), "-12345670");
    EXPECT_EQ(FP_IntToDecimal<Int>(-1234567800, 1), "-123456780");
    EXPECT_EQ(FP_IntToDecimal<Int>(-12345678900, 1), "-1234567890");
    EXPECT_EQ(FP_IntToDecimal<Int>(-123456789000, 1), "-12345678900");
    EXPECT_EQ(FP_IntToDecimal<Int>(-1234567890100, 1), "-123456789010");
    EXPECT_EQ(FP_IntToDecimal<Int>(-12345678901200, 1), "-1234567890120");
    EXPECT_EQ(FP_IntToDecimal<Int>(-123456789012300, 1), "-12345678901230");
}
