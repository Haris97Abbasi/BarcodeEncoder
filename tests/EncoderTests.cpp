#include "Encoder.h"
#include <gtest/gtest.h>

#include <stdexcept>
#include <vector>

using barcode::Encoder;

TEST(EncodeTest, EncodesSampleInput) {
    Encoder encoder;
    EXPECT_EQ(encoder.encode("HELLO123"), (std::vector<int>{104, 40, 37, 44, 44, 47, 17, 18, 19, 8, 106}));
}