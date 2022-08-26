#include "triangle.hpp"

#include <cmath>

Triangle::Triangle()
	: a(Vec3(0.0, 0.0, 0.0)), b(Vec3(1.0, 0.0, 0.0)), c(Vec3(0.0, 1.0, 0.0)), normal((a-b).cross(a-c).normalized()) {}

Triangle::Triangle(const Vec3 &a, const Vec3 &b, const Vec3 &c, std::shared_ptr<Material> materialPtr)
	: a(a), b(b), c(c), normal((b-a).cross(c-a).normalized()), materialPtr(materialPtr) {}

bool Triangle::hit(const Ray3 &ray, double minDist, double maxDist, Ray3HitRecord &hitRecord) const {
	// End if plane is parallel to ray
	if(ray.getDirection().dot(this->normal) == 0.0)
		return false;

	double d = this->normal.dot(this->a);
	double t = (d - this->normal.dot(ray.getOrigin())) / ray.getDirection().dot(this->normal);

	Vec3 point = ray.at(t);

	// End if collision not in range
	if(t < minDist || t > maxDist)
		return false;

	// End if point of collision is behind ray
	if((point - ray.getOrigin()).dot(ray.getDirection()) < 0.0)
		return false;

	double areaAB = (point - this->a).cross(this->b - this->a).length();
	double areaAC = (point - this->a).cross(this->c - this->a).length();
	double areaBC = (point - this->b).cross(this->c - this->b).length();

	// End if point is in the triangle's plane but not in the triangle
	if(areaAB + areaAC + areaBC - (this->b - this->a).cross(this->c - this->a).length() > 0.00001)
		return false;

	if(this->normal.dot(ray.getDirection()) < 0.0)
		hitRecord.setFaceNormal(ray, this->normal);
	else
		hitRecord.setFaceNormal(ray, -this->normal);

	hitRecord.position = point;
	hitRecord.materialPtr = this->materialPtr;
	hitRecord.distance = t;

	return true;
}
