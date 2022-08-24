#ifndef RAY3_H
#define RAY3_H

#include "vec3.hpp"

class Ray3 {
	public:
		Ray3();
		Ray3(Vec3 origin, Vec3 dir);

		Vec3 getOrigin() const;
		Vec3 getDirection() const;

		void setOrigin(const Vec3 &v);
		void setDirection(const Vec3 &v);

		Vec3 at(double t);

	private:
		Vec3 origin;
		Vec3 direction;
};

#endif
