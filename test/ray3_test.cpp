#include <iostream>
#include <cassert>

#include "ray3.hpp"

void Ray3_set_direction_test() {
	std::cout << "Testing Ray3 direction setter...\n";

	// Ray3 direction setter should normalize before setting
	
	Ray3 r;

	r.setDirection(Vec3(1.0, 1.0, 1.0));
	assert(r.getDirection() == Vec3(1.0, 1.0, 1.0).normalized());

	r.setDirection(Vec3(0.1, 0.1, 0.1));
	assert(r.getDirection() == Vec3(0.1, 0.1, 0.1).normalized());
	

	std::cout << "Ray3 direction setter works!\n";
}

void Ray3_at_test() {
	std::cout << "Testing Ray3 at...\n";

	Ray3 r;

	r = Ray3(Vec3(0.0, 0.0, 0.0), Vec3(0.0, 1.0, 0.0));
	assert(r.at(4.0) == Vec3(0.0, 4.0, 0.0));

	// Ray3 should normalize direction automatically
	r = Ray3(Vec3(3.59, 9.23, 19.32), Vec3(93.4, 123.2, 84.4));
	assert(r.at(2.43).distanceTo(Vec3(4.878, 10.929, 20.484)) < 0.001);

	std::cout << "Ray3 at works!\n";
}

int main() {
	Ray3_set_direction_test();
	Ray3_at_test();
	return 0;
}
