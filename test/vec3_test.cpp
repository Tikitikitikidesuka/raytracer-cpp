#include <iostream>
#include <cassert>

#include "vec3.hpp"

void Vec3_equals_operator_test() {
	std::cout << "Testing Vec3 \"==\" operator...\n";

	assert(Vec3(0.0, -1.0, 2.0) == Vec3(0.0, -1.0, 2.0));

	std::cout << "Vec3 \"==\" operator works!\n";
}

void Vec3_negative_operator_test() {
	std::cout << "Testing Vec3 unary \"-\" operator...\n";

	assert(-Vec3(0.0, -1.0, 2.0) == Vec3(0.0, 1.0, -2.0));
	
	std::cout << "Vec3 unary \"-\" operator works!\n";
}

void Vec3_addition_operator_test() {
	std::cout << "Testing Vec3 \"+\" operator...\n";

	assert(Vec3(0.0, -1.0, 2.0) + Vec3(0.0, 1.0, -2.0) == Vec3(0.0, 0.0, 0.0));

	std::cout << "Vec3 \"+\" operator works!\n";
}

void Vec3_subtraction_operator_test() {
	std::cout << "Testing Vec3 \"-\" operator...\n";

	assert(Vec3(0.0, -1.0, 2.0) - Vec3(0.0, -1.0, 2.0) == Vec3(0.0, 0.0, 0.0));

	std::cout << "Vec3 \"-\" operator works!";
}

void Vec3_multiplication_by_scalar_test() {
	std::cout << "Testing Vec3 \"*\" operator...\n";

	assert(Vec3(0.0, -1.0, 2.0) * 3.0 == Vec3(0.0, -3.0, 6.0));
	assert(3.0 * Vec3(0.0, -1.0, 2.0) == Vec3(0.0, -3.0, 6.0));

	std::cout << "Vec3 \"*\" operator works!\n";
}

void Vec3_division_by_scalar_test() {
	std::cout << "Testing Vec3 \"/\" operator...\n";

	assert(Vec3(0.0, -3.0, 6.0) / 3.0 == Vec3(0.0, -1.0, 2.0));
	assert(3.0 / Vec3(0.0, -3.0, 6.0) == Vec3(0.0, -1.0, 2.0));

	std::cout << "Vec3 \"/\" operator works!\n";
}

void Vec3_dot_product_test() {
	std::cout << "Testing Vec3 dot product...\n";

	assert(Vec3(0.0, -1.0, 2.0).dot(Vec3(2.0, -3.0, 4.0)) == 11.0);

	std::cout << "Vec3 dot product works!\n";
}

void Vec3_cross_product_test() {
	std::cout << "Testing Vec3 cross product...\n";

	assert(Vec3(0.0, -1.0, 2.0).cross(Vec3(2.0, -3.0, 4.0)) == Vec3(2.0, 4.0, 2.0));

	std::cout << "Vec3 cross product works!\n";
}

void Vec3_length_squared_test() {
	std::cout << "Testing Vec3 length squared...\n";

	assert(abs(1.0 - Vec3(0.0, 1.0, 0.0).lengthSquared()) < 0.001);
	assert(abs(95.18 - Vec3(2.3, 4.2, -8.5).lengthSquared()) < 0.001);
	assert(abs(24.0773 - Vec3(-1.3, 4.23, -2.12).lengthSquared()) < 0.001);

	std::cout << "Vec3 length squared works!\n";
}

void Vec3_length_test() {
	std::cout << "Testing Vec3 length...\n";

	assert(abs(1.0 - Vec3(0.0, 1.0, 0.0).length()) < 0.001);
	assert(abs( 9.756 - Vec3(2.3, 4.2, -8.5).length()) < 0.001);
	assert(abs(4.9068 - Vec3(-1.3, 4.23, -2.12).length()) < 0.001);

	std::cout << "Vec3 length works!\n";
}

void Vec3_normalized_test() {
	std::cout << "Tesing Vec3 normalization...\n";

	assert(abs(1.0 - Vec3(0.0, 1.0, 0.0).normalized().length()) < 0.001);
	assert(abs(1.0 - Vec3(2.3, 4.2, -8.5).normalized().length()) < 0.001);
	assert(abs(1.0 - Vec3(-1.3, 4.23, -2.12).normalized().length()) < 0.001);

	std::cout << "Vec3 normalization works!\n";
}

int main() {
	Vec3_equals_operator_test();
	Vec3_negative_operator_test();
	Vec3_addition_operator_test();
	Vec3_subtraction_operator_test();
	Vec3_multiplication_by_scalar_test();
	Vec3_division_by_scalar_test();
	Vec3_dot_product_test();
	Vec3_cross_product_test();
	Vec3_length_squared_test();
	Vec3_length_test();
	Vec3_normalized_test();
	return 0;
}
