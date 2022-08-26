#ifndef TRIANGLE_H
#define TRIANGLE_H

#include <memory>

#include "vec3.hpp"
#include "ray3hittable.hpp"

class Triangle : public Ray3Hittable {
	public:
		Triangle();
		Triangle(const Vec3 &a, const Vec3 &b, const Vec3 &c, std::shared_ptr<Material> materialPtr);

		virtual bool hit(const Ray3 &ray, double minDist, double maxDist, Ray3HitRecord &hitRecord) const override;

	private:
		Vec3 a;
		Vec3 b;
		Vec3 c;
		Vec3 normal;
		std::shared_ptr<Material> materialPtr;
};

#endif
