#include "ray3hittable.hpp"

void Ray3HitRecord::setFaceNormal(const Ray3 &ray, const Vec3 &outwardNormal) {
	this->frontFace = ray.getDirection().dot(outwardNormal);
	this->normal = this->frontFace ? outwardNormal : -outwardNormal;
}
