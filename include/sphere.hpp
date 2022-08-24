#ifndef SPHERE_H
#define SPHERE_H

#include "vec3.hpp"
#include "ray3hittable.hpp"

class Sphere : public Ray3Hittable {
	public:
		Sphere();
		Sphere(const Vec3 &center, double radius);

		virtual bool hit(const Ray3 &ray, double minDist, double maxDist, Ray3HitRecord &hitRecord) const override;

	private:
		Vec3 center;
		double radius;
};

#endif
