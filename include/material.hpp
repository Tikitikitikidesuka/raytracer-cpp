#ifndef MATERIAL_H
#define MATERIAL_H

#include "vec3.hpp"
#include "ray3.hpp"
#include "color.hpp"
#include "ray3hittable.hpp"

class Material {
	public:
		virtual bool scatter(const Ray3 &rayIn, const Ray3HitRecord &hitRecord, Color &attenuation, Ray3 &scattered) const = 0;

		virtual ~Material() = default;
};

#endif
