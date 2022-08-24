#ifndef RAY3_H
#define RAY3_H

#include "vec3.hpp"

class Ray3 {
	public:
		Ray3();
		Ray3(const Vec3 &origin, const Vec3 &dir);

		Vec3 getOrigin() const;
		Vec3 getDirection() const;

		void setOrigin(const Vec3 &origin);
		void setDirection(const Vec3 &direction);

		Vec3 at(double t) const;

	private:
		Vec3 origin;
		Vec3 direction;
};

#endif
