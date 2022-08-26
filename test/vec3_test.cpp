#include "gtest/gtest.h"

#include <cmath>
#include "vec3.hpp"

const double MAX_ERROR = 0.001;
const double MAX_RANDOM_ERROR = 0.01;
const int RANDOM_ITERATIONS = 1024;

bool closeEnough(const Vec3 &v1, const Vec3 &v2, double maxError) {
	return  fabs(v1.getX() - v2.getX()) < maxError &&
		fabs(v1.getY() - v2.getY()) < maxError &&
		fabs(v1.getZ() - v2.getZ()) < maxError;
}

TEST(Vec3Test, GeneratesZero) {
	EXPECT_EQ(Vec3::zero(), Vec3(0.0, 0.0, 0.0));
}

TEST(Vec3Test, EqualsDifferentInstance) {
	Vec3 v1 = Vec3(0.5, -2.0, 0.125);
	Vec3 v2 = Vec3(0.5, -2.0, 0.125);
	EXPECT_EQ(v1, v2);
}

TEST(Vec3Test, EqualsConstant) {
	Vec3 v1 = Vec3(0.5, -2.0, 0.125);
	EXPECT_EQ(v1, Vec3(0.5, -2.0, 0.125));
	EXPECT_EQ(Vec3(0.5, -2.0, 0.125), v1);
}

TEST(Vec3Test, EqualsItself) {
	Vec3 v = Vec3(0.5, -2.0, 0.125);
	EXPECT_EQ(v, v);
}

TEST(Vec3Test, NotEqualsDifferentInstance) {
	Vec3 v2;
	Vec3 v1 = Vec3(0.5, -2.0, 0.125);

	v2 = Vec3(0.25, -2.0, 0.125);
	EXPECT_NE(v1, v2);
	
	v2 = Vec3(0.5, -2.5, 0.125);
	EXPECT_NE(v1, v2);

	v2 = Vec3(0.5, -2.0, -0.125);
	EXPECT_NE(v1, v2);
}

TEST(Vec3Test, NotEqualsConstant) {
	Vec3 v1 = Vec3(0.5, -2.0, 0.125);

	EXPECT_NE(v1, Vec3(0.25, -2.0, 0.125));
	EXPECT_NE(Vec3(0.25, -2.0, 0.125), v1);

	EXPECT_NE(v1, Vec3(0.5, -2.5, 0.125));
	EXPECT_NE(Vec3(0.5, -2.5, 0.125), v1);

	EXPECT_NE(v1, Vec3(0.5, -2.0, -0.125));
	EXPECT_NE(Vec3(0.5, -2.0, -0.125), v1);
}

TEST(Vec3Test, NotNotEqualsItself) {
	Vec3 v1 = Vec3(0.5, -2.0, 0.125);
	EXPECT_FALSE(v1 != v1);
}

TEST(Vec3Test, NegativeOperator) {
	EXPECT_EQ(Vec3(0.5, -2.0, 0.125), -Vec3(-0.5, 2.0, -0.125));
	EXPECT_EQ(Vec3(0.0, 0.0, 0.0), -Vec3(0.0, 0.0, 0.0));
}

TEST(Vec3Test, AdditionOperator) {
	EXPECT_TRUE(closeEnough(
		Vec3(0.5, -2.0, 0.125) + Vec3(0.123, -21.3, 3.135),
		Vec3(0.623, -23.3, 3.26),
		MAX_ERROR
	));
}

TEST(Vec3Test, SubtractionOperator) {
	EXPECT_TRUE(closeEnough(
		Vec3(0.5, -2.0, 0.125) - Vec3(0.123, -21.3, 3.135),
		Vec3(0.377, 19.3, -3.01),
		MAX_ERROR
	));
}

TEST(Vec3Test, MultiplicationByScalar) {
	EXPECT_TRUE(closeEnough(
		Vec3(0.5, -2.0, 0.125) * 3.1415,
		Vec3(1.571, -6.283, 0.3927),
		MAX_ERROR
	));

	EXPECT_TRUE(closeEnough(
		3.1415 * Vec3(0.5, -2.0, 0.125),
		Vec3(1.571, -6.283, 0.3927),
		MAX_ERROR
	));

	EXPECT_TRUE(closeEnough(
		-3.1415 * Vec3(0.5, -2.0, 0.125),
		Vec3(-1.571, 6.283, -0.3927),
		MAX_ERROR
	));

	EXPECT_TRUE(closeEnough(
		Vec3(0.5, -2.0, 0.125) * -3.1415,
		Vec3(-1.571, 6.283, -0.3927),
		MAX_ERROR
	));
}

TEST(Vec3Test, DivisionByScalar) {
	EXPECT_TRUE(closeEnough(
		Vec3(0.5, -2.0, 0.125) / 3.1415,
		Vec3(0.1592, -0.6366, 0.0398),
		MAX_ERROR
	));

	EXPECT_TRUE(closeEnough(
		Vec3(0.5, -2.0, 0.125) / -3.1415,
		Vec3(-0.1592, 0.6366, -0.0398),
		MAX_ERROR
	));
}

TEST(Vec3Test, AdditionAssignmentOperatorDifferentInstance) {
	Vec3 v1 = Vec3(1.42, 9.23, -12.24);
	Vec3 v2 = Vec3(4.12, -23.1, 3.43);
	v1 += v2;
	EXPECT_TRUE(closeEnough(
		v1, Vec3(5.54, -13.87, -8.81), MAX_ERROR
	));
}

TEST(Vec3Test, AdditionAssignmentOperatorConstant) {
	Vec3 v = Vec3(1.42, 9.23, -12.24);
	v += Vec3(4.12, -23.1, 3.43);
	EXPECT_TRUE(closeEnough(
		v, Vec3(5.54, -13.87, -8.81), MAX_ERROR
	));
}

TEST(Vec3Test, AdditionAssignmentOperatorItself) {
	Vec3 v = Vec3(1.42, 9.23, -12.24);
	v += v;
	EXPECT_TRUE(closeEnough(
		v, Vec3(2.84, 18.46, -24.48), MAX_ERROR
	));
}

TEST(Vec3Test, SubtractionAssignmentOperatorDifferentInstance) {
	Vec3 v1 = Vec3(1.42, 9.23, -12.24);
	Vec3 v2 = Vec3(4.12, -23.1, 3.43);
	v1 -= v2;
	EXPECT_TRUE(closeEnough(
		v1, Vec3(-2.7, 32.33, -15.67), MAX_ERROR
	));
}

TEST(Vec3Test, SubtractionAssignmentOperatorConstant) {
	Vec3 v = Vec3(1.42, 9.23, -12.24);
	v -= Vec3(4.12, -23.1, 3.43);
	EXPECT_TRUE(closeEnough(
		v, Vec3(-2.7, 32.33, -15.67), MAX_ERROR
	));
}

TEST(Vec3Test, MultiplicationByScalarAssignmentOperator) {
	Vec3 v;

	v = Vec3(3.12, -4.23, 9.21);
	v *= 3.1415;
	EXPECT_TRUE(closeEnough(
		v, Vec3(9.801, -13.288, 28.933), MAX_ERROR
	));

	v = Vec3(3.12, -4.23, 9.21);
	v *= -3.1415;
	EXPECT_TRUE(closeEnough(
		v, Vec3(-9.801, 13.288, -28.933), MAX_ERROR
	));
}

TEST(Vec3Test, DivisionByScalarAssignmentOperator) {
	Vec3 v;

	v = Vec3(3.12, -4.23, 9.21);
	v /= 3.1415;
	EXPECT_TRUE(closeEnough(
		v, Vec3(0.9931, -1.346, 2.9317), MAX_ERROR
	));

	v = Vec3(3.12, -4.23, 9.21);
	v /= -3.1415;
	EXPECT_TRUE(closeEnough(
		v, Vec3(-0.9931, 1.346, -2.9317), MAX_ERROR
	));
}

TEST(Vec3Test, DotProduct) {
	EXPECT_DOUBLE_EQ(
		Vec3(0.34, -2.12, 4.23).dot(Vec3(0.43, -5.23, -3.84)), -5.0094
	);
}

TEST(Vec3Test, CrossProduct) {
	EXPECT_TRUE(closeEnough(
		Vec3(3.43, -4.32, 0.03).cross(Vec3(-9.23, -7.48, -2.35)),
		Vec3(10.3764, 7.7836, -65.53),
		MAX_ERROR
	));

	EXPECT_TRUE(closeEnough(
		Vec3(-9.23, -7.48, -2.35).cross(Vec3(3.43, -4.32, 0.03)),
		Vec3(-10.3764, -7.7836, 65.53),
		MAX_ERROR
	));
}

TEST(Vec3Test, LengthSquared) {
	EXPECT_DOUBLE_EQ(Vec3(8.23, 9.43, -2.38).lengthSquared(), 162.3222);
	EXPECT_DOUBLE_EQ(Vec3(0.0, 0.0, 0.0).lengthSquared(), 0.0);
}

TEST(Vec3Test, Length) {
	EXPECT_NEAR(Vec3(8.23, 9.43, -2.38).length(), 12.74057299, MAX_ERROR);
	EXPECT_DOUBLE_EQ(Vec3(0.0, 0.0, 0.0).length(), 0.0);
}

TEST(Vec3Test, Normalization) {
	EXPECT_TRUE(closeEnough(
		Vec3(7.34, -9.28, 7.37).normalized(),
		Vec3(0.52656, -0.66573, 0.52871),
		MAX_ERROR
	));

	// User must make sure that Vec3::zero()
	//EXPECT_ANY_THROW(Vec3(0.0, 0.0, 0.0).normalized());
}

TEST(Vec3Test, DistanceTo) {
	EXPECT_NEAR(
		Vec3(4.24, -9.48, 1.44).distanceTo(Vec3(0.23, -4.12, -8.54)),
		12.01707535,
		MAX_ERROR
	);

	Vec3 v = Vec3(4.24, -9.48, 1.44);
	EXPECT_DOUBLE_EQ(v.distanceTo(v), 0.0);
}

TEST(Vec3Test, Reflection) {
	Vec3 normal = Vec3(0.0362084247, 0.8860414516, -0.4621898918);

	EXPECT_TRUE(closeEnough(
		Vec3(8.12, 9.34, -2.83).reflection(normal),
		Vec3(7.40469, -8.16399, 6.30069),
		MAX_ERROR
	));

	EXPECT_TRUE(closeEnough(
		Vec3(8.12, 9.34, -2.83).reflection(normal),
		Vec3(7.40469, -8.16399, 6.30069),
		MAX_ERROR
	));

	// User must make sure that the normal parameter is normalized
	//EXPECT_TRUE(closeEnough(
	//	Vec3(8.12, 9.34, -2.83).reflection(Vec3(normal * 3.1415)),
	//	Vec3(7.40469, -8.16399, 6.30069),
	//	MAX_ERROR
	//));
}

TEST(Vec3Test, RandomUnitGeneration) {
	
}

TEST(Vec3Test, RandomInUnitSphereGeneration) {
}

TEST(Vec3Test, RandomInUnitHemisphereGeneration) {
}

int main(int argc, char** argv) {
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}
