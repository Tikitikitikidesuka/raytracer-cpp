#include "gtest/gtest.h"

#include "ray3.hpp"
#include "vec3.hpp"

TEST(Ray3Test, SetDirectionNormalizes) {
	Ray3 r;
	
	r.setDirection(Vec3(1.0, 1.0, 1.0));
	EXPECT_EQ(r.getDirection(), Vec3(1.0, 1.0, 1.0).normalized());

	r.setDirection(Vec3(0.1, 0.1, 0.1));
	EXPECT_EQ(r.getDirection(), Vec3(0.1, 0.1, 0.1).normalized());
}

TEST(Ray3Test, RayAt) {
	Ray3 r;

	r = Ray3(Vec3(0.0, 0.0, 0.0), Vec3(0.0, 1.0, 0.0));
	EXPECT_EQ(r.at(4.0), Vec3(0.0, 4.0, 0.0));

	r = Ray3(Vec3(3.59, 9.23, 19.32), Vec3(93.4, 123.2, 84.4));
	EXPECT_LT(r.at(2.43).distanceTo(Vec3(4.878, 10.929, 20.484)), 0.001);
}

int main(int argc, char** argv) {
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}
