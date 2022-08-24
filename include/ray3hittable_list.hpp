#ifndef RAY3HITTABLE_LIST_H
#define RAY3HITTABLE_LIST_H

#include "ray3hittable.hpp"

#include <memory>
#include <vector>

using std::shared_ptr;
using std::make_shared;

class Ray3HittableList : public Ray3Hittable {
	public:
		Ray3HittableList();

		void clear();
		void add(shared_ptr<Ray3Hittable> object);

		virtual bool hit(const Ray3 &ray, double minDist, double maxDist, Ray3HitRecord &hitRecord) const override;

	private:
		std::vector<shared_ptr<Ray3Hittable>> objects;
};

#endif
