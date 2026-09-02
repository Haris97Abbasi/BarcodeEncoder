#include "Encoder.h"
#include <gtest/gtest.h>

#include <stdexcept>
#include <vector>

using barcode::Encoder;

TEST(EncodeTest, EncodesSampleInput) {
    Encoder encoder;
    EXPECT_EQ(encoder.encode("HELLO123"), (std::vector<int>{104, 40, 37, 44, 44, 47, 17, 18, 19, 8, 106}));
}

TEST(EncodeTest, EncodesSingleCharacter) {
    Encoder encoder;
    EXPECT_EQ(encoder.encode("A"), (std::vector<int>{104, 33, 34, 106}));
}

TEST(EncodeTest, EncodesMessageWithSpace) {
    Encoder encoder;
    EXPECT_EQ(encoder.encode("A B"), (std::vector<int>{104, 33, 0, 34, 33, 106}));
}

TEST(EncodeTest, EncodesMessageWithSpecialCharacter) {
    Encoder encoder;
    EXPECT_EQ(encoder.encode("A.B"), (std::vector<int>{104, 33, 14, 34, 61, 106}));
}

TEST(EncodeTest, ThrowsOnEmptyString) {
    Encoder encoder;
    EXPECT_THROW(encoder.encode(""), std::invalid_argument);
}

TEST(EncodeTest, ThrowsOnInvalidCharacter) {
    Encoder encoder;
    EXPECT_THROW(encoder.encode("Schlüssel"), std::invalid_argument);
    EXPECT_THROW(encoder.encode("Bär"), std::invalid_argument);
}

TEST(ChecksumTest, CalculatesChecksum) {
    Encoder encoder;
    EXPECT_EQ(encoder.calculateChecksum({40, 37, 44, 44, 47, 17, 18, 19}), 8);
}