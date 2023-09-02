// Example test file
#include <gtest/gtest.h>
#include "txtformat/txtformat.h"

// Demonstrate some basic assertions.
TEST(TXTFormatTests, BasicAssertions)
{
    // Expect two strings not to be equal.
    EXPECT_STRNE("hello", "world");
    // Expect equality.
    EXPECT_EQ(7 * 6, 42);
}

// // Demonstrate failure
// TEST(TXTFormatTests, NotWorkingTests)
// {
//     // This should fail
//     EXPECT_STREQ("hello", "world");
// }
