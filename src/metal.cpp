#include "metal.hpp"

MetalMat::MetalMat(const Color &albedo, const double roughness)
	: albedo(albedo), roughness(roughness) {}

bool MetalMat::scatter(const Ray3 &rayIn, const Ray3HitRecord &hitRecord, Color &attenuation, Ray3 &scattered) const {
	Vec3 reflectedDir = rayIn.getDirection().reflection(hitRecord.normal);
	scattered = Ray3(hitRecord.position, reflectedDir + this->roughness * Vec3::randomInUnitSphere()); 
	attenuation = albedo;
	return scattered.getDirection().dot(hitRecord.normal) > 0.0;
}
