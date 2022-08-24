#include <iostream>

#include "vec3.hpp"
#include "color.hpp"
#include "ray3.hpp"
#include "ray3hittable.hpp"
#include "sphere.hpp"

Color ray_color(const Ray3 &ray);
void write_color_ppm(std::ostream &out, Color color);

int main() {
	// Image
	const double aspect_ratio = 16.0 / 9.0;
	const int image_width = 400;
	const int image_height = static_cast<int>(image_width / aspect_ratio);
	
	//Camera
	double viewport_height = 2.0;
	double viewport_width = aspect_ratio * viewport_height;
	double focal_length = 1.0;

	Vec3 origin = Vec3(0.0, 0.0, 0.0);
	Vec3 horizontal = Vec3(viewport_width, 0.0, 0.0);
	Vec3 vertical = Vec3(0.0, viewport_height, 0.0);
	Vec3 lower_left_corner = origin - horizontal / 2.0 - vertical / 2.0 - Vec3(0.0, 0.0, focal_length);

	std::cout << "P3\n" << image_width << ' ' << image_height << "\n255\n";

	for(int j = image_height - 1; j >= 0; --j) {
		std::cerr << "\rScanlines remaining: " << j << ' ' << std::flush;
		for(int i = 0; i < image_width; ++i) {
			double u = i / static_cast<double>(image_width - 1);
			double v = j / static_cast<double>(image_height - 1);

			Ray3 ray(origin, lower_left_corner + u * horizontal + v * vertical - origin);

			Color pixel_color = ray_color(ray);

			write_color_ppm(std::cout, pixel_color);
		}
	}

	std::cerr << "\nDone.\n" << std::flush;

	return 0;
}

Color ray_color(const Ray3 &ray) {
	Sphere sphere(Vec3(0.0, 0.0, -1.0), 0.5);

	Ray3HitRecord hitRecord;
	if(sphere.hit(ray, 0.0001, 100000.0, hitRecord))
		return Color(1.0, 0.0, 0.0);

	double t = 0.5 * (ray.getDirection().getY() + 1.0);
	return (1.0 - t) * Color(1.0, 1.0, 1.0) + t * Color(0.5, 0.7, 1.0);
}

void write_color_ppm(std::ostream &out, Color color) {
	out 	<< static_cast<int>(255.999 * color.getR()) << ' '
		<< static_cast<int>(255.999 * color.getG()) << ' '
		<< static_cast<int>(255.999 * color.getB()) << '\n';
}
