#include <gtest/gtest.h>
#include "pokerHand.h"

TEST(pokerTests, Test1) {
    EXPECT_EQ(bestPokerHand("2H 3D 5S 9C KD", "4C 6H 7S JH AC"), "4C 6H 7S JH AC");
}

TEST(pokerTests, Test2) {
    EXPECT_EQ(bestPokerHand("2H 3D 5S 9C KD", "4C 4H 7S JH AC"), "4C 4H 7S JH AC");
}

TEST(pokerTests, Test3) {
    EXPECT_EQ(bestPokerHand("2H 3D 5S 9C KD", "4C 4H 7S 7H AC"), "4C 4H 7S 7H AC");
}

TEST(pokerTests, Test4) {
    EXPECT_EQ(bestPokerHand("2H 3D 5S 9C KD", "4C 4H 4S 7H AC"), "4C 4H 4S 7H AC");
}

TEST(pokerTests, Test5) {
    EXPECT_EQ(bestPokerHand("2H 3D 4S 5C 6D", "4C 5H 6S 7H 8C"), "4C 5H 6S 7H 8C");
}

TEST(pokerTests, Test6) {
    EXPECT_EQ(bestPokerHand("2H 3H 5H 9H KH", "4C 6C 7C JC AC"), "4C 6C 7C JC AC");
}

TEST(pokerTests, Test7) {
    EXPECT_EQ(bestPokerHand("2H 2D 5S 5C 5D", "4C 4H 7S 7H 7C"), "4C 4H 7S 7H 7C");
}

TEST(pokerTests, Test8) {
    EXPECT_EQ(bestPokerHand("2H 2D 2S 2C KD", "4C 4H 4S 4H AC"), "4C 4H 4S 4H AC");
}

TEST(pokerTests, Test9) {
    EXPECT_EQ(bestPokerHand("2H 3H 4H 5H 6H", "4C 5C 6C 7C 8C"), "4C 5C 6C 7C 8C");
}

TEST(pokerTests, Test10) {
    EXPECT_EQ(bestPokerHand("10H JH QH KH AH", "10C JC QC KC AC"), "10C JC QC KC AC");
}
