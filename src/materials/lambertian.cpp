#include "materials/lambertian.hpp"

LambertianMat::LambertianMat(const Color &albedo)
	: albedo(albedo) {}

bool LambertianMat::scatter(const Ray3 &rayIn, const Ray3HitRecord &hitRecord, Color &attenuation, Ray3 &scattered) const {
	Vec3 scatterDir = hitRecord.normal + Vec3::randomUnit();

	if(scatterDir.lengthSquared() < 0.00000001)
		scatterDir = hitRecord.normal;

	scattered = Ray3(hitRecord.position, scatterDir);
	attenuation = albedo;
	return true;
}
