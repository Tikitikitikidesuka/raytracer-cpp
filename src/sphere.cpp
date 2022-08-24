#include "sphere.hpp"

#include <cmath>

Sphere::Sphere()
	: center(Vec3(0.0, 0.0, 0.0)), radius(1.0) {}

Sphere::Sphere(const Vec3 &center, double radius)
	: center(center), radius(radius) {}

bool Sphere::hit(const Ray3 &ray, double minDist, double maxDist, Ray3HitRecord &hitRecord) const {
	double t = (this->center - ray.getOrigin()).dot(ray.getDirection());
	double tToCenterSquared = (ray.at(t) - this->center).lengthSquared();

	double radiusSquared = this->radius * this->radius;

	// Stop if no collision
	if(tToCenterSquared > radiusSquared)
		return false;

	double error = sqrt(radiusSquared - tToCenterSquared);
	hitRecord.distance = t - error;

	// Stop if collision not in range
	if(hitRecord.distance < minDist || hitRecord.distance > maxDist)
		return false;

	hitRecord.position = ray.at(hitRecord.distance);

	hitRecord.normal = (hitRecord.position - this->center) / this->radius;
	if(ray.getOrigin().distanceTo(this->center) < this->radius)
		hitRecord.normal = -hitRecord.normal;

	return true;
}
