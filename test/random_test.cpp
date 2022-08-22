#include <iostream>
#include <cassert>
#include <cmath>

#include "random.hpp"

void Random_in_range_test() {
	std::cout << "Testing Random in range generator...\n";

	const int iterations = 1024;
	const double max_error = 0.25;

	double avg = 0.0;
	for(int i = 0; i < iterations; ++i) {
		double random = Random::inRange(-1.0, 1.0);
		assert(random >= -1.0 && random <= 1.0);
		avg += random / (double) iterations;
	}
	std::cout << "Random generator from -1.0 to 1.0 average is " << avg << '\n';
	assert(fabs(avg) < max_error);

	for(int i = 0; i < iterations; ++i) {
		double random = Random::inRange(0.0, 1.0);
		assert(random >= 0.0 && random <= 1.0);
		avg += random / (double) iterations;
	}
	std::cout << "Random generator from 0.0 to 1.0 average is " << avg << '\n';
	assert(fabs(0.5 - avg) < max_error);

	std::cout << "Random in range generator works!\n";
}

int main() {
	Random_in_range_test();
	return 0;
}
