#ifndef LAMBERTIAN_MATERIAL_H
#define LAMBERTIAN_MATERIAL_H

#include "material.hpp"

class LambertianMat : public Material {
	public:
		LambertianMat(const Color &albedo);

		virtual bool scatter(const Ray3 &rayIn, const Ray3HitRecord &hitRecord, Color &attenuation, Ray3 &scattered) const override;
	
	private:
		Color albedo;
};

#endif
