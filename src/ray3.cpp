#include "ray3.hpp"

Ray3::Ray3()
	: origin(Vec3(0.0, 0.0, 0.0)), direction(Vec3(0.0, 0.0, -1.0)) {}

Ray3::Ray3(const Vec3 &origin, const Vec3 &direction)
	: origin(origin), direction(direction.normalized()) {}

Vec3 Ray3::getOrigin() const {
	return this->origin;
}

Vec3 Ray3::getDirection() const {
	return this->direction;
}

void Ray3::setOrigin(const Vec3 &origin) {
	this->origin = origin;
}

void Ray3::setDirection(const Vec3 &direction) {
	this->direction = direction;
}

Vec3 Ray3::at(double t) const {
	return this->origin + this->direction * t;
}
