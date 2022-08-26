#include "dielectric.hpp"

#include <cmath>

#include "random.hpp"

DielectricMat::DielectricMat(const double refractionIndex)
	: refractionIndex(refractionIndex) {}

static double reflectance(double cosine, double refractionIndex) {
	// Use Schlick's approximation for reflectance.
	auto r0 = (1 - refractionIndex) / (1 + refractionIndex);
	r0 = r0*r0;
	return r0 + (1 - r0)*pow((1 - cosine), 5);
}

bool DielectricMat::scatter(const Ray3 &rayIn, const Ray3HitRecord &hitRecord, Color &attenuation, Ray3 &scattered) const {
	attenuation = Color(1.0, 1.0, 1.0);
	double refractionRatio = hitRecord.frontFace ? 1.0 / this->refractionIndex : this->refractionIndex;
	
	double cosTheta = fmin(-rayIn.getDirection().dot(hitRecord.normal), 1.0);
	double sinTheta = sqrt(1.0 - cosTheta * cosTheta);

	bool cannotRefract = refractionRatio * sinTheta > 1.0;

	Vec3 newDir;
	if(cannotRefract || reflectance(cosTheta, refractionRatio) > Random::inRange(0.0, 1.0))
		newDir = rayIn.getDirection().reflection(hitRecord.normal);
	else
		newDir = rayIn.getDirection().refraction(hitRecord.normal, refractionRatio);

	scattered = Ray3(hitRecord.position, newDir);
	return true;
}
