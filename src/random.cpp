#include "random.hpp"

#include <random>

static std::random_device rand_dev;
static std::mt19937 generator(rand_dev());
static std::uniform_real_distribution<double> distr(0.0, 1.0);

double Random::inRange(double min, double max) {
	return distr(generator) * (max - min) + min;
}
