#ifndef DIELECTRIC_MATERIAL_H
#define DIELECTRIC_MATERIAL_H

#include "material.hpp"

class DielectricMat : public Material {
	public:
		DielectricMat(const double refractionIndex);

		virtual bool scatter(const Ray3 &rayIn, const Ray3HitRecord &hitRecord, Color &attenuation, Ray3 &scattered) const override;
	
	private:
		double refractionIndex;
};

#endif
