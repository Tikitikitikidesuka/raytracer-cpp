#include "camera.hpp"

#include <cmath>

Camera::Camera(const Vec3 &origin, double viewportWidth, double viewportHeight, double fov) {
	double diagonal = sqrt(viewportHeight * viewportHeight + viewportWidth * viewportWidth);
	double focalLength = diagonal / (2.0 * tan(fov / 2.0));

	this->origin = origin;
	this->horizontal = Vec3(viewportWidth, 0.0, 0.0);
	this->vertical = Vec3(0.0, viewportHeight, 0.0);
	this->lowerLeftCorner = 
		origin -
		0.5 * this->vertical - 
		0.5 * this->horizontal -
		Vec3(0.0, 0.0, focalLength);
}

Ray3 Camera::getRay(double u, double v) {
	Vec3 dir =
		this->lowerLeftCorner +
		u * this->horizontal + v * this->vertical -
		this->origin;

	return Ray3(this->origin, dir);
}
