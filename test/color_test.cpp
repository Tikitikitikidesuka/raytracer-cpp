#include <iostream>
#include <cassert>

#include "color.hpp"

void Color_black_test() {
	std::cout << "Testing Color black generator...\n";

	assert(Color::black() == Color(0.0, 0.0, 0.0));

	std::cout << "Color black generator works!\n";
}

void Color_white_test() {
	std::cout << "Testing Color white generator...\n";

	assert(Color::white() == Color(1.0, 1.0, 1.0));

	std::cout << "Color white generator works!\n";
}

void Color_from_Vec3_test() {
	std::cout << "Testing Color from Vec3 generator...\n";

	Vec3 v = Vec3(1.0, 1.0, 1.0);
	Color c = Color(v);
	assert(c == Color(1.0, 1.0, 1.0));
	
	v.setX(0.0);
	assert(c == Color(1.0, 1.0, 1.0));

	std::cout << "Color from Vec3 generator works!\n";
}

void Color_equals_operator_test() {
	std::cout << "Testing Color \"==\" operator...\n";

	assert(Color(0.23, 0.43, 0.92) == Color(0.23, 0.43, 0.92));
	assert(!(Color(0.53, 0.43, 0.92) == Color(0.23, 0.43, 0.92)));

	Color c = Color(0.23, 0.82, 0.13);
	assert(c == c);

	std::cout << "Color \"==\" operator works!\n";
}

void Color_not_equals_operator_test() {
	std::cout << "Testing Color \"!=\" operator...\n";

	assert(Color(0.53, 0.43, 0.92) != Color(0.23, 0.43, 0.92));
	assert(!(Color(0.23, 0.43, 0.92) != Color(0.23, 0.43, 0.92)));

	Color c = Color(0.23, 0.82, 0.13);
	assert(!(c != c));

	std::cout << "Color \"!=\" operator works!\n";
}

void Color_addition_operator_test() {
	std::cout << "Testing Color \"+\" operator...\n";

	assert(Color(0.25, 0.5, 1.0) + Color(-0.25, 0.5, -1.0) == Color(0.0, 1.0, 0.0));

	// If Color should clamp
	// assert(Color(1.0, 0.5, 0.25) + Color(0.25, 0.5, 1.0) == Color(1.0, 1.0, 1.0));
	
	// If Color should not clamp
	assert(Color(1.0, 0.5, 0.25) + Color(0.25, 0.5, 1.0) == Color(1.25, 1.0, 1.25));

	std::cout << "Color \"+\" operator works!\n";
}

void Color_subtraction_operator_test() {
	std::cout << "Testing Color \"-\" operator...\n";

	assert(Color(0.25, 0.5, 1.0) - Color(-0.25, 0.5, -1.0) == Color(0.5, 0.0, 2.0));

	// If Color should clamp
	// assert(Color(1.0, 0.5, 0.25) + Color(0.25, 0.5, 1.0) == Color(1.0, 1.0, 1.0));
	
	// If Color should not clamp
	assert(Color(1.0, 0.5, 0.25) - Color(0.25, -0.5, 2.0) == Color(0.75, 1.0, -1.75));

	std::cout << "Color \"-\" operator works!\n";
}

void Color_multiplication_by_scalar_test() {
	std::cout << "Testing Color \"*\" operator...\n";

	assert(Color(0.0, 0.25, 0.5) * 2.0 == Color(0.0, 0.5, 1.0));
	assert(2.0 * Color(0.0, 0.25, 0.5) == Color(0.0, 0.5, 1.0));

	std::cout << "Vec3 \"*\" operator works!\n";
}

void Color_division_by_scalar_test() {
	std::cout << "Testing Color \"/\" operator...\n";

	assert(Color(0.0, 0.5, 1.0) / 2.0 == Color(0.0, 0.25, 0.5));

	std::cout << "Vec3 \"/\" operator works!\n";
}

void Color_addition_assignment_operator_test() {
	std::cout << "Testing Color \"+=\" operator...\n";

	Color c = Color(0.0, 0.5, 0.25);
	c += Color(1.0, 0.5, 0.25);
	assert(c == Color(1.0, 1.0, 0.5));

	c = Color(0.0, 0.5, 0.25);
	c += c;
	assert(c == Color(0.0, 1.0, 0.5));

	std::cout << "Color \"+=\" operator works!\n";
}

void Color_subraction_assignment_operator_test() {
	std::cout << "Testing Color \"-=\" operator...\n";

	Color c = Color(1.0, 0.5, 0.25);
	c -= Color(0.0, 0.5, 0.125);
	assert(c == Color(1.0, 0.0, 0.125));

	std::cout << "Color \"-=\" operator works!\n";
}

void Color_multiplication_by_scalar_assignment_test() {
	std::cout << "Testing Color \"*=\" operator...\n";

	Color c = Color(0.0, 0.5, 0.25);
	c *= 2.0;
	assert(c == Color(0.0, 1.0, 0.5));

	std::cout << "Color \"*=\" operator works! \n";
}

void Color_division_by_scalar_assignment_test() {
	std::cout << "Testing Color \"/=\" operator...\n";

	Color c = Color(0.0, 0.5, 0.25);
	c /= 2.0;
	assert(c == Color(0.0, 0.25, 0.125));

	std::cout << "Color \"/=\" operator works!\n";
}

int main() {
	Color_black_test();
	Color_white_test();
	Color_from_Vec3_test();
	Color_equals_operator_test();
	Color_not_equals_operator_test();
	Color_addition_operator_test();
	Color_subtraction_operator_test();
	Color_multiplication_by_scalar_test();
	Color_division_by_scalar_test();
	Color_addition_assignment_operator_test();
	Color_subraction_assignment_operator_test();
	Color_multiplication_by_scalar_assignment_test();
	Color_division_by_scalar_assignment_test();
	return 0;
}
