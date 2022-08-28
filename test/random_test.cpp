#include "gtest/gtest.h"

#include <cmath>
#include "random.hpp"

const int RANDOM_ITERATIONS = 4096;

TEST(RandomTest, InRangeHasUniformDistributionMean) {
	const double MAX_ERROR = 0.01;

	double avg = 0.0;

	for(int i = 0; i < RANDOM_ITERATIONS; ++i) {
		avg += Random::inRange(0.0, 1.0) / RANDOM_ITERATIONS;
	}


	// 0.5 = \frac{1}{2} (1 - 0)
	EXPECT_NEAR(avg, 0.5, MAX_ERROR);
}

TEST(RandomTest, InRangeHasUniformDistributionDeviation) {
	const double MAX_ERROR = 0.01;

	double variance = 0.0;

	for(int i = 0; i < RANDOM_ITERATIONS; ++i) {
		double error =  0.5 - Random::inRange(0.0, 1.0);
		variance += error * error / RANDOM_ITERATIONS;
	}

	double deviation = sqrt(variance);

	// 0.288675 = \sqrt{\frac{1}{12}(1 - 0)^2}
	EXPECT_NEAR(deviation, 0.288675, MAX_ERROR);
}

TEST(RandomTest, InRangeIsWithinRangeOverZero) {
	for(int i = 0; i < RANDOM_ITERATIONS; ++i) {
		double randNum = Random::inRange(1.0, 3.0);
		EXPECT_TRUE(randNum >= 1.0 && randNum <= 3.0);
	}
}

TEST(RandomTest, InRangeIsWithinRangeUnderZero) {
	for(int i = 0; i < RANDOM_ITERATIONS; ++i) {
		double randNum = Random::inRange(-10.0, -2.0);
		EXPECT_TRUE(randNum >= -10.0 && randNum <= -2.0);
	}
}

TEST(RandomTest, InRangeIsWithinRangeAroundZero) {
	for(int i = 0; i < RANDOM_ITERATIONS; ++i) {
		double randNum = Random::inRange(-7.0, 5.0);
		EXPECT_TRUE(randNum >= -7.0 && randNum <= 5.0);
	}
}

int main(int argc, char** argv) {
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}
