#ifndef METAL_MATERIAL_H
#define METAL_MATERIAL_H

#include "material.hpp"

class MetalMat : public Material {
	public:
		MetalMat(const Color &albedo, const double roughness);

		virtual bool scatter(const Ray3 &rayIn, const Ray3HitRecord &hitRecord, Color &attenuation, Ray3 &scattered) const override;
	
	private:
		Color albedo;
		double roughness;
};

#endif
