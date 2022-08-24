#include <iostream>
#include <cassert>
#include <cmath>

#include "vec3.hpp"
#include "random.hpp"

bool Vec3_closeEnough(const Vec3 &v1, const Vec3 &v2, double maxError) {
	return  fabs(v1.getX() - v2.getX()) < maxError &&
		fabs(v1.getY() - v2.getY()) < maxError &&
		fabs(v1.getZ() - v2.getZ()) < maxError;
}

void Vec3_zero_test() {
	std::cout << "Testing Vec3 zero generator...\n";

	assert(Vec3::zero() == Vec3(0.0, 0.0, 0.0));

	std::cout << "Vec3 zero generator works!\n";
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
		Vec3(-1.153, -3.538, -0.384),
		0.01
	));

	std::cout << "Vec3 reflection works!\n";
}

void Vec3_random_unit_test() {
	std::cout << "Testing Vec3 random unit generation...\n";

	const int iterations = 1024;
	const double max_error = 0.1;

	Vec3 avg = Vec3::zero();
	for(int i = 0; i < iterations; ++i) {
		Vec3 randomVec = Vec3::randomUnit();
		avg += randomVec / (double) iterations;
		assert(fabs(1.0 - randomVec.length()) < 0.001);
	}

	const double error = (Vec3(0.0, 0.0, 0.0) - avg).length();
	std::cout << "Vec3 random unit generator average error is " << error << '\n';
	assert(error < max_error);

	std::cout << "Vec3 random unit generation works!\n";
}

void Vec3_random_in_unit_sphere_test() {
	std::cout << "Testing Vec3 random in unit sphere generation...\n";

	const int iterations = 1024;
	const double max_error = 0.1;

	Vec3 avg = Vec3::zero();

	for(int i = 0; i < iterations; ++i) {
		Vec3 randomVec = Vec3::randomInUnitSphere();
		avg += randomVec / (double) iterations;
		assert(randomVec.length() <= 1.0);
	}

	const double error = (Vec3(0.0, 0.0, 0.0) - avg).length();
	std::cout << "Vec3 random in unit sphere generator average error is " << error << '\n';
	assert(error < max_error);

	std::cout << "Vec3 random unit in unit shpere generation works!\n";
}

void Vec3_random_in_unit_hemisphere_test() {
	std::cout << "Testing Vec3 random in unit hemisphere generation...\n";

	const int tests = 32;
	const int iterations = 1024;
	const double max_error = 0.1;

	double avgError = 0.0;
	for(int n = 0; n < tests; ++n) {
		Vec3 avg = Vec3::zero();

		const Vec3 normalTest = Vec3(
				Random::inRange(-1.0, 1.0),
				Random::inRange(-1.0, 1.0),
				Random::inRange(-1.0, 1.0)
			).normalized();

		for(int i = 0; i < iterations; ++i) {
			Vec3 randomVec = Vec3::randomInUnitHemisphere(normalTest);
			avg += randomVec.normalized() / (double) iterations;
			assert(randomVec.length() <= 1.0);
		}

		// 0.5236 = \int_0^1 \frac{\pi \cdot \sqrt{1 - x^2})}{2} \cdot x dx
		const double error = (normalTest * 0.5236 - avg).length();
		avgError += error / (double) iterations;
		assert(error < max_error);
	}
	std::cout << "Vec3 random in unit hemisphere generator average error is " << avgError << '\n';

	std::cout << "Vec3 random unit in hemisphere generation works!\n";
}

int main() {
	Vec3_zero_test();
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
