#ifndef SPHERE_H
#define SPHERE_H

#include <memory>

#include "vec3.hpp"
#include "ray3hittable.hpp"

class Sphere : public Ray3Hittable {
	public:
		Sphere();
		Sphere(const Vec3 &center, double radius, std::shared_ptr<Material> materialPtr);

		virtual bool hit(const Ray3 &ray, double minDist, double maxDist, Ray3HitRecord &hitRecord) const override;

	private:
		Vec3 center;
		double radius;
		std::shared_ptr<Material> materialPtr;
};

#endif
