#include <iostream>
#include <cassert>
#include <cmath>

#include "vec3.hpp"

bool Vec3_closeEnough(const Vec3 &v1, const Vec3 &v2) {
	return  fabs(v1.getX() - v2.getX()) < 0.01 &&
		fabs(v1.getY() - v2.getY()) < 0.01 &&
		fabs(v1.getZ() - v2.getZ()) < 0.01;
}

void Vec3_equals_operator_test() {
	std::cout << "Testing Vec3 \"==\" operator...\n";

	assert(Vec3(0.0, -1.0, 2.0) == Vec3(0.0, -1.0, 2.0));
	assert(!(Vec3(0.0, -1.0, 2.0) == Vec3(0.0, 1.0, 2.0)));

	Vec3 v = Vec3(0.0, 2.2, 4.4);
	assert(v == v);

	std::cout << "Vec3 \"==\" operator works!\n";
}

void Vec3_not_equals_operator_test() {
	std::cout << "Testing Vec3 \"!=\" operator...\n";

	assert(Vec3(0.0, 1.0, 2.0) != Vec3(0.0, -1.0, 2.0));
	assert(!(Vec3(0.0, -1.0, 2.0) != Vec3(0.0, -1.0, 2.0)));

	Vec3 v = Vec3(0.0, 2.2, 4.4);
	assert(!(v != v));

	std::cout << "Vec3 \"!=\" operator works!\n";
}

void Vec3_negative_operator_test() {
	std::cout << "Testing Vec3 unary \"-\" operator...\n";

	assert(-Vec3(0.0, -1.0, 2.0) == Vec3(0.0, 1.0, -2.0));
	assert(-Vec3(0.0, 0.0, 0.0) == Vec3(0.0, 0.0, 0.0));
	
	std::cout << "Vec3 unary \"-\" operator works!\n";
}

void Vec3_addition_operator_test() {
	std::cout << "Testing Vec3 \"+\" operator...\n";

	assert(Vec3(0.0, -1.0, 2.0) + Vec3(0.0, 1.0, -2.0) == Vec3(0.0, 0.0, 0.0));
	assert(Vec3(0.0, 1.0, 2.0) + Vec3(0.0, 1.0, 2.0) == Vec3(0.0, 2.0, 4.0));
	assert(Vec3(0.0, 0.0, 0.0) + Vec3(1.0, 1.0, 1.0) + Vec3(1.0, 1.0, 1.0) == Vec3(2.0, 2.0, 2.0));

	std::cout << "Vec3 \"+\" operator works!\n";
}

void Vec3_subtraction_operator_test() {
	std::cout << "Testing Vec3 \"-\" operator...\n";

	assert(Vec3(0.0, -1.0, 2.0) - Vec3(0.0, -1.0, 2.0) == Vec3(0.0, 0.0, 0.0));
	assert(Vec3(0.0, 2.0, 4.0) - Vec3(0.0, 3.0, 2.0) == Vec3(0.0, -1.0, 2.0));
	assert(Vec3(0.0, 0.0, 0.0) - Vec3(1.0, 1.0, 1.0) - Vec3(1.0, 1.0, 1.0) == Vec3(-2.0, -2.0, -2.0));

	std::cout << "Vec3 \"-\" operator works!";
}

void Vec3_multiplication_by_scalar_test() {
	std::cout << "Testing Vec3 \"*\" operator...\n";

	assert(Vec3(0.0, -1.0, 2.0) * 3.0 == Vec3(0.0, -3.0, 6.0));
	assert(3.0 * Vec3(0.0, -1.0, 2.0) == Vec3(0.0, -3.0, 6.0));
	assert(3.0 * Vec3(0.0, -1.0, 2.0) * 3.0 == Vec3(0.0, -9.0, 18.0));

	std::cout << "Vec3 \"*\" operator works!\n";
}

void Vec3_division_by_scalar_test() {
	std::cout << "Testing Vec3 \"/\" operator...\n";

	assert(Vec3(0.0, -3.0, 6.0) / 3.0 == Vec3(0.0, -1.0, 2.0));
	assert(3.0 / Vec3(0.0, -3.0, 6.0) == Vec3(0.0, -1.0, 2.0));
	assert(3.0 / Vec3(0.0, 9.0, 27.0) / 3.0 == Vec3(0.0, 1.0, 3.0));

	std::cout << "Vec3 \"/\" operator works!\n";
}

void Vec3_addition_assignment_operator_test() {
	std::cout << "Testing Vec3 \"+=\" operator...\n";

	Vec3 v = Vec3(0.0, 1.0, 2.0);
	v += Vec3(0.0, 1.0, 2.0);
	assert(v == Vec3(0.0, 2.0, 4.0));

	v += v;
	assert(v == Vec3(0.0, 4.0, 8.0));

	std::cout << "Vec3 \"+=\" operator works!\n";
}

void Vec3_subtraction_assignment_operator_test() {
	std::cout << "Testing Vec3 \"-=\" operator...\n";

	Vec3 v = Vec3(0.0, 1.0, 2.0);
	v -= Vec3(0.0, -1.0, -2.0);
	assert(v == Vec3(0.0, 2.0, 4.0));

	std::cout << "Vec3 \"-=\" operator works!\n";
}

void Vec3_multiplication_by_scalar_assignment_test() {
	std::cout << "Testing Vec3 \"*=\" operator...\n";

	Vec3 v = Vec3(0.0, -1.0, 2.0);
	v *= 6.0;
	assert(v == Vec3(0.0, -6.0, 12.0));

	std::cout << "Vec3 \"*=\" operator works!\n";
}

void Vec3_division_by_scalar_assignment_test() {
	std::cout << "Testing Vec3 \"/=\" operator...\n";

	Vec3 v = Vec3(0.0, -9.0, 6.0);
	v /= 3.0;
	assert(v == Vec3(0.0, -3.0, 2.0));

	std::cout << "Vec3 \"/=\" operator works!\n";
}

void Vec3_dot_product_test() {
	std::cout << "Testing Vec3 dot product...\n";

	assert(Vec3(0.0, -1.0, 2.0).dot(Vec3(2.0, -3.0, 4.0)) == 11.0);
	assert(Vec3(0.0, 1.0, 0.0).dot(Vec3(0.0, 0.0, 1.0)) == 0.0);

	std::cout << "Vec3 dot product works!\n";
}

void Vec3_cross_product_test() {
	std::cout << "Testing Vec3 cross product...\n";

	assert(Vec3(0.0, -1.0, 2.0).cross(Vec3(2.0, -3.0, 4.0)) == Vec3(2.0, 4.0, 2.0));
	assert(Vec3(0.0, 1.0, 0.0).cross(Vec3(0.0, -1.0, 0.0)) == Vec3(0.0, 0.0, 0.0));

	std::cout << "Vec3 cross product works!\n";
}

void Vec3_length_squared_test() {
	std::cout << "Testing Vec3 length squared...\n";

	assert(fabs(1.0 - Vec3(0.0, 1.0, 0.0).lengthSquared()) < 0.001);
	assert(fabs(95.18 - Vec3(2.3, 4.2, -8.5).lengthSquared()) < 0.001);
	assert(fabs(24.0773 - Vec3(-1.3, 4.23, -2.12).lengthSquared()) < 0.001);

	std::cout << "Vec3 length squared works!\n";
}

void Vec3_length_test() {
	std::cout << "Testing Vec3 length...\n";

	assert(fabs(1.0 - Vec3(0.0, 1.0, 0.0).length()) < 0.001);
	assert(fabs( 9.756 - Vec3(2.3, 4.2, -8.5).length()) < 0.001);
	assert(fabs(4.9068 - Vec3(-1.3, 4.23, -2.12).length()) < 0.001);

	std::cout << "Vec3 length works!\n";
}

void Vec3_normalized_test() {
	std::cout << "Tesing Vec3 normalization...\n";

	assert(fabs(1.0 - Vec3(0.0, 1.0, 0.0).normalized().length()) < 0.001);
	assert(fabs(1.0 - Vec3(2.3, 4.2, -8.5).normalized().length()) < 0.001);
	assert(fabs(1.0 - Vec3(-1.3, 4.23, -2.12).normalized().length()) < 0.001);

	std::cout << "Vec3 normalization works!\n";
}

void Vec3_reflection_test() {
	std::cout << "Testing Vec3 reflection...\n";

	assert(Vec3(1.0, 1.0, 0.0).reflection(Vec3(0.0, -1.0, 0.0)) == Vec3(1.0, -1.0, 0.0));
	assert(Vec3(1.0, 1.0, 0.0).reflection(Vec3(0.0, 1.0, 0.0)) == Vec3(1.0, -1.0, 0.0));
	assert(Vec3_closeEnough(
		Vec3(3.0, 2.0, 1.0).reflection(Vec3(0.588, 0.784, 0.196)),
		Vec3(-1.153, -3.538, -0.384))
	);

	std::cout << "Vec3 reflection works!\n";
}

void Vec3_random_unit_test() {
	std::cout << "Testing Vec3 random unit generation...\n";

	const int iterations = 1024;
	const double max_error = 0.1;

	Vec3 avg = Vec3::zero();
	for(int i = 0; i < iterations; ++i) {
		Vec3 randomVec = Vec3::randomUnit();
		assert(fabs(1.0 - randomVec.length()) < 0.001);
		avg += randomVec / (double) iterations;
	}
	std::cout << "Vec3 random unit generator average vector length is " << avg.length() << '\n';
	assert(avg.length() < max_error);

	std::cout << "Vec3 random unit generation works!\n";
}

void Vec3_random_in_unit_sphere_test() {
	std::cout << "Testing Vec3 random in unit sphere generation...\n";

	const int iterations = 1024;
	const double max_error = 0.1;

	double avgLength = 0.0;
	Vec3 avgUnit = Vec3::zero();
	for(int i = 0; i < iterations; ++i) {
		Vec3 randomVec = Vec3::randomInUnitSphere();
		assert(randomVec.length() <= 1.0);
		avgUnit += randomVec.normalized() / (double) iterations;
		avgLength += randomVec.length() / (double) iterations;
	}
	std::cout << "Vec3 random in unit sphere generator average vector length is " << avgUnit.length() << '\n';
	std::cout << "Vec3 random in unit sphere generator average length is " << avgLength << '\n';
	assert(avgUnit.length() < max_error);
	assert(fabs(0.7937 - avgLength) < max_error);

	std::cout << "Vec3 random unit generation works!\n";
}

void Vec3_random_in_unit_hemisphere_test() {
}

int main() {
	Vec3_equals_operator_test();
	Vec3_not_equals_operator_test();
	Vec3_negative_operator_test();
	Vec3_addition_operator_test();
	Vec3_subtraction_operator_test();
	Vec3_multiplication_by_scalar_test();
	Vec3_division_by_scalar_test();
	Vec3_addition_assignment_operator_test();
	Vec3_subtraction_assignment_operator_test();
	Vec3_multiplication_by_scalar_assignment_test();
	Vec3_division_by_scalar_assignment_test();
	Vec3_dot_product_test();
	Vec3_cross_product_test();
	Vec3_length_squared_test();
	Vec3_length_test();
	Vec3_normalized_test();
	Vec3_reflection_test();
	Vec3_random_unit_test();
	Vec3_random_in_unit_sphere_test();
	Vec3_random_in_unit_hemisphere_test();
	return 0;
}
