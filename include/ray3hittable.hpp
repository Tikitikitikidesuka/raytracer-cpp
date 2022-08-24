#ifndef RAY3_HITTABLE_H
#define RAY3_HITTABLE_H

#include <memory>

#include "vec3.hpp"
#include "ray3.hpp"

class Material;

struct Ray3HitRecord {
	Vec3 position;
	Vec3 normal;
	double distance;
	bool frontFace;
	std::shared_ptr<Material> materialPtr;

	void setFaceNormal(const Ray3 &ray, const Vec3 &outwardNormal);
};

class Ray3Hittable {
	public:
		virtual bool hit(const Ray3 &ray, double minDist, double maxDist, Ray3HitRecord &hitRecord) const = 0;
		virtual ~Ray3Hittable() = default;
};

#endif
