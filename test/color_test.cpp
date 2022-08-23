#include <iostream>
#include <cassert>
#include <cmath>

#include "color.hpp"

Color_black_test() {
	std::cout << "Testing Color black generator...\n";

	assert(Color::black() == Color(0.0, 0.0, 0.0));

	std::cout << "Color black generator works!\n";
}

Color_white_test() {
	std::cout << "Testing Color white generator...\n";

	assert(Color::white() == Color(0.0, 0.0, 0.0));

	std::cout << "Color white generator works!\n";
}

Color_equals_operator_test() {
	std::cout << "Testing Color \"==\" operator...\n";

	assert(Color(0.23, 0.43, 0.92) == Color(0.23, 0.43, 0.92));
	assert(!(Color(0.53, 0.43, 0.92) == Color(0.23, 0.43, 0.92)));

	Color c = Color(0.23, 0.82, 0.13);
	assert(c == c);

	std::cout << "Color \"==\" operator works!\n";
}

Color_not_equals_operator_test() {
	std::cout << "Testing Color \"!=\" operator...\n";

	assert(Color(0.53, 0.43, 0.92) != Color(0.23, 0.43, 0.92));
	assert(!(Color(0.23, 0.43, 0.92) != Color(0.23, 0.43, 0.92)));

	Color c = Color(0.23, 0.82, 0.13);
	assert(!(c != c));

	std::cout << "Color \"!=\" operator works!\n";
}

Color_addition_operator_test() {
	std::cout << "Testing Color \"+\" operator...\n";

	assert(Color(0.25, 0.5, 1.0) + Color(-0.25, 0.5, -1.0) == Color(0.0, 1.0, 0.0));

	// If Color should clamp
	// assert(Color(1.0, 0.5, 0.25) + Color(0.25, 0.5, 1.0) == Color(1.0, 1.0, 1.0));
	
	// If Color should not clamp
	assert(Color(1.0, 0.5, 0.25) + Color(0.25, 0.5, 1.0) == Color(1.25, 1.0, 1.25));

	std::cout << "Color \"+\" operator works!\n";
}

Color_subtraction_operator_test() {
	std::cout << "Testing Color \"-\" operator...\n";

	assert(Color(0.25, 0.5, 1.0) - Color(-0.25, 0.5, -1.0) == Color(0.5, 0.0, 2.0));

	// If Color should clamp
	// assert(Color(1.0, 0.5, 0.25) + Color(0.25, 0.5, 1.0) == Color(1.0, 1.0, 1.0));
	
	// If Color should not clamp
	assert(Color(1.0, 0.5, 0.25) - Color(0.25, -0.5, 2.0) == Color(0.75, 1.0, -1.75));

	std::cout << "Color \"-\" operator works!\n";
}

Color_multiplication_by_scalar_test() {
}

Color_division_by_scalar_test();
Color_addition_assignment_operator_test();
Color_subraction_assignment_operator_test();
Color_multiplication_by_scalar_assignment_test();
Color_division_by_scalar_assignment_test();

int main() {
	Color_black_test();
	Color_white_test();
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
