#ifndef CAMERA_H
#define CAMERA_H

#include "vec3.hpp"
#include "ray3.hpp"

class Camera {
	public:
		Camera(const Vec3 &origin, double viewportWidth, double viewportHeight, double fov);

		Ray3 getRay(double u, double v);

	private:
		Vec3 origin;
		Vec3 lowerLeftCorner;
		Vec3 horizontal;
		Vec3 vertical;
};

#endif
