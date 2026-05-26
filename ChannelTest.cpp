#include <gtest/gtest.h>
#include "Channel.h"
#include <vector>
#include <chrono>

struct ChannelFixture : public ::testing::Test {
    std::vector<double> inputs{ 1.0, 2.0, 3.0, 4.0, 1.5, 1.99, 2.5, 3.5, 4.5, 4.99 };
    int bits{ 16 };
    std::chrono::milliseconds clock_rate{ 100 };
    double rangeMin{ -5.0 };
    double rangeMax{ 5.0 };
    double sensitivity{ 1.0 };
    double trigger_level{ 2.0 };

    ADC<short, 4> adc{ bits, clock_rate, rangeMin, rangeMax, sensitivity, trigger_level, {} };
    Channel<short, 4> channel{ std::move(adc) };
};

TEST_F(ChannelFixture, Initialization) {
    EXPECT_EQ(bits, channel.get_adc().bits);
    EXPECT_EQ(rangeMin, channel.get_adc().rangeMin);
    EXPECT_EQ(rangeMax, channel.get_adc().rangeMax);
    EXPECT_EQ(sensitivity, channel.get_adc().sensitivity);
    EXPECT_EQ(trigger_level, channel.get_adc().trigger_level);
}

TEST_F(ChannelFixture, RunEquivalencePartitionValidInputs) {
    std::vector<double> valid_inputs{ 3.0, 4.0, 5.0 };
    size_t processed = channel.run(valid_inputs);

    EXPECT_EQ(processed, 3);
    EXPECT_EQ(channel.get_values().size(), 3);
}

TEST_F(ChannelFixture, RunEquivalencePartitionInvalidInputs) {
    std::vector<double> invalid_inputs{ 0.0, 1.0, 1.5, 1.99 };
    size_t processed = channel.run(invalid_inputs);

    EXPECT_EQ(processed, 0);
    EXPECT_EQ(channel.get_values().size(), 0);
}

TEST_F(ChannelFixture, RunBoundaryEmptyInput) {
    std::vector<double> empty_inputs{};
    size_t processed = channel.run(empty_inputs);

    EXPECT_EQ(processed, 0);
    EXPECT_EQ(channel.get_values().size(), 0);
}

TEST_F(ChannelFixture, RunBoundaryExactTriggerLevel) {
    std::vector<double> boundary_inputs{ 2.0 };
    size_t processed = channel.run(boundary_inputs);

    EXPECT_EQ(processed, 1);
    EXPECT_DOUBLE_EQ(channel.get_values()[0], 2.0);
}

TEST_F(ChannelFixture, RunBoundaryCapacityLimit) {
    std::vector<double> heavy_inputs{ 2.5, 3.0, 3.5, 4.0, 4.5, 5.0 };
    size_t processed = channel.run(heavy_inputs);

    EXPECT_EQ(processed, 4);
    EXPECT_EQ(channel.get_values().size(), 4);
}

TEST_F(ChannelFixture, GetValuesEquivalenceAndBoundary) {
    std::vector<double> mixed_inputs{ -10.0, 1.99, 2.0, 6.0 };
    channel.run(mixed_inputs);
    std::vector<double> vals = channel.get_values();

    ASSERT_EQ(vals.size(), 2);
    EXPECT_DOUBLE_EQ(vals[0], 2.0);
    EXPECT_DOUBLE_EQ(vals[1], 5.0);
}

TEST_F(ChannelFixture, ToStringIntegration) {
    std::string str = channel.to_string();
    EXPECT_NE(str.find("Channel"), std::string::npos);
    EXPECT_NE(str.find("ADC"), std::string::npos);
}