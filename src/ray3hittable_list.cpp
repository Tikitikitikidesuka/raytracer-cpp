#include "ray3hittable_list.hpp"

Ray3HittableList::Ray3HittableList() {}

void Ray3HittableList::clear() {
	this->objects.clear();
}

void Ray3HittableList::add(shared_ptr<Ray3Hittable> object) {
	this->objects.push_back(object);
}

bool Ray3HittableList::hit(const Ray3 &ray, double minDist, double maxDist, Ray3HitRecord &hitRecord) const {
	bool hitAnything = false;
	double closestDistance = maxDist;

	for(const auto &object : this->objects) {
		Ray3HitRecord tempHitRecord;
		if(object->hit(ray, minDist, closestDistance, tempHitRecord)) {
			closestDistance = tempHitRecord.distance;
			hitRecord = tempHitRecord;
			hitAnything = true;
		}
	}

	return hitAnything;
}
