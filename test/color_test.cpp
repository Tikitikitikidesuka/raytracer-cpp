#include "gtest/gtest.h"

#include "vec3.hpp"
#include "color.hpp"

TEST(ColorTest, BlackGenerator) {
	EXPECT_EQ(Color::black(), Color(0.0, 0.0, 0.0));
}

TEST(ColorTest, WhiteGenerator) {
	EXPECT_EQ(Color::white(), Color(1.0, 1.0, 1.0));
}

TEST(ColorTest, FromVec3Generator) {
	EXPECT_EQ(Color(0.5, 0.25, 0.125), Color(Vec3(0.5, 0.25, 0.125)));
}

TEST(ColorTest, FromVec3GeneratorOutsideColorRange) {
	EXPECT_EQ(Color(-0.5, -2.0, 4.0), Color(Vec3(-0.5, -2.0, 4.0)));
}

TEST(ColorTest, EqualsDifferentInstance) {
	Color c1 = Color(0.5, 0.25, 0.125);
	Color c2 = Color(0.5, 0.25, 0.125);
	EXPECT_TRUE(c1 == c2);
	EXPECT_TRUE(c2 == c1);

	Color c3;
	c3 = Color(0.3, 0.25, 0.125);
	EXPECT_FALSE(c1 == c3);
	c3 = Color(0.5, 0.05, 0.125);
	EXPECT_FALSE(c1 == c3);
	c3 = Color(0.5, 0.25, 0.25);
	EXPECT_FALSE(c1 == c3);
}

TEST(ColorTest, EqualsConstant) {
	Color c = Color(0.5, 0.25, 0.125);
	EXPECT_TRUE(c == Color(0.5, 0.25, 0.125));
	EXPECT_TRUE(Color(0.5, 0.25, 0.125) ==  c);

	EXPECT_FALSE(c == Color(0.3, 0.25, 0.125));
	EXPECT_FALSE(c == Color(0.3, 0.25, 0.125));
	EXPECT_FALSE(c == Color(0.3, 0.25, 0.125));
}

TEST(ColorTest, EqualsItself) {
	Color c = Color(0.5, 0.25, 0.125);
	EXPECT_EQ(c, c);
}

TEST(ColorTest, NotEqualsDifferentInstance) {
	Color c2;
	Color c1 = Color(0.5, 0.25, 0.125);

	c2 = Color(0.25, 0.25, 0.125);
	EXPECT_TRUE(c1 != c2);
	EXPECT_TRUE(c2 != c1);
	c2 = Color(0.5, 0.5, 0.125);
	EXPECT_TRUE(c1 != c2);
	EXPECT_TRUE(c2 != c1);
	c2 = Color(0.5, 0.25, 0.25);
	EXPECT_TRUE(c1 != c2);
	EXPECT_TRUE(c2 != c1);

	Color c3 = Color(0.5, 0.25, 0.125);
	EXPECT_FALSE(c1 != c3);
}

TEST(ColorTest, NotEqualsConstant) {
	Color c1 = Color(0.5, 0.25, 0.125);

	EXPECT_TRUE(c1 != Color(0.25, 0.25, 0.125));
	EXPECT_TRUE(Color(0.25, 0.25, 0.125) != c1);
	EXPECT_TRUE(c1 != Color(0.5, 0.5, 0.125));
	EXPECT_TRUE(Color(0.5, 0.5, 0.125) != c1);
	EXPECT_TRUE(c1 != Color(0.5, 0.25, 0.25));
	EXPECT_TRUE(Color(0.5, 0.25, 0.25) != c1);

	EXPECT_FALSE(c1 != Color(0.5, 0.25, 0.125));
}

TEST(ColorTest, NotNotEqualsItself) {
	Color c = Color(0.5, 0.25, 0.125);
	EXPECT_FALSE(c != c);
}

TEST(ColorTest, AdditionOperator) {
	EXPECT_EQ(Color(0.5, 0.25, 0.125) + Color(0.5, 0.25, 0.125), Color(1.0, 0.5, 0.25));
	EXPECT_EQ(Color(0.5, 0.25, 0.125) + Color(-0.5, -0.25, -0.125), Color(0.0, 0.0, 0.0));
}

TEST(ColorTest, AdditionOperatorOutsideColorRange) {
	EXPECT_EQ(Color(0.5, 0.75, -1.0) + Color(-1.0, 0.5, -1.0), Color(-0.5, 1.25, -2.0));
}

TEST(ColorTest, SubtractionOperator) {
	EXPECT_EQ(Color(0.5, 0.25, 0.125) - Color(0.25, 0.125, 0.0), Color(0.25, 0.125, 0.125));
}

TEST(ColorTest, SubtractionOperatorOutsideColorRange) {
	EXPECT_EQ(Color(0.5, 0.25, 0.125) - Color(2.0, 1.0, 0.5), Color(-1.5, -0.75, -0.375));
}

TEST(ColorTest, MultiplicationByScalarOperator) {
	EXPECT_EQ(Color(0.0, 0.25, 0.5) * 2.0, Color(0.0, 0.5, 1.0));
	EXPECT_EQ(2.0 * Color(0.0, 0.25, 0.5), Color(0.0, 0.5, 1.0));
}

TEST(ColorTest, MultiplicationByScalarOperatorOutsideColorRange) {
	EXPECT_EQ(Color(0.0, 1.0, 2.5) * 2.0, Color(0.0, 2.0, 5.0));
	EXPECT_EQ(2.0 * Color(0.0, 1.0, 2.5), Color(0.0, 2.0, 5.0));
}

TEST(ColorTest, MultiplicationOperator) {
	EXPECT_EQ(Color(1.0, 0.5, 0.25) * Color(1.0, 0.5, 0.25), Color(1.0, 0.25, 0.0625));
}

TEST(ColorTest, MultiplicationOperatorOutsideColorRange) {
	EXPECT_EQ(Color(2.0, 1.0, -3.0) * Color(0.5, 0.25, 1.0), Color(1.0, 0.25, -3.0));
}

TEST(ColorTest, DivisionByScalarOperator) {
	EXPECT_EQ(Color(0.0, 0.5, 1.0) / 2.0, Color(0.0, 0.25, 0.5));
}

TEST(ColorTest, DivisionByScalarOperatorOutsideColorRange) {
	EXPECT_EQ(Color(4.0, 2.0, 1.0) / 0.5, Color(8.0, 4.0, 2.0));
}

TEST(ColorTest, AdditionAssignmentOperator) {
	Color c = Color(0.0, 0.25, 0.5);
	c += Color(1.0, 0.25, 0.5);
	EXPECT_EQ(c, Color(1.0, 0.5, 1.0));

	c = Color(0.0, 0.5, 0.25);
	c += c;
	EXPECT_EQ(c, Color(0.0, 1.0, 0.5));
}

TEST(ColorTest, SubtractionAssignment) {
	Color c = Color(1.0, 0.25, 0.5);
	c -= Color(0.0, 0.25, 0.5);
	EXPECT_EQ(c, Color(1.0, 0.0, 0.0));
}

TEST(ColorTest, MultiplicationAssignmentConstant) {
	Color c = Color(1.0, 0.5, 0.25);
	c *= Color(0.25, 0.5, 1.0);
	EXPECT_EQ(c, Color(0.25, 0.25, 0.25));
}

TEST(ColorTest, MultiplicationAssignmentDifferentInstance) {
	Color c = Color(1.0, 0.5, 0.25);
	Color aux = Color(0.25, 0.5, 1.0);
	c *= aux;
	EXPECT_EQ(c, Color(0.25, 0.25, 0.25));
}

TEST(ColorTest, MultiplicationAssignmentItself) {
	Color c = Color(1.0, 0.5, 0.25);
	c *= c;
	EXPECT_EQ(c, Color(1.0, 0.25, 0.0625));
}

TEST(ColorTest, MultiplicationByScalarAssignment) {
	Color c = Color(0.0, 0.5, 0.25);
	c *= 2.0;
	EXPECT_EQ(c, Color(0.0, 1.0, 0.5));
}

TEST(ColorTest, DivisionByScalarAssignment) {
	Color c = Color(0.0, 0.5, 0.25);
	c /= 2.0;
	EXPECT_EQ(c, Color(0.0, 0.25, 0.125));
}
