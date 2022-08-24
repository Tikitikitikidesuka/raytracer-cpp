#include <iostream>
#include <limits>

#include "utils.hpp"
#include "vec3.hpp"
#include "ray3.hpp"
#include "color.hpp"
#include "camera.hpp"
#include "ray3hittable.hpp"
#include "ray3hittable_list.hpp"
#include "sphere.hpp"
#include "random.hpp"

Color ray_color(const Ray3 &ray, const Ray3Hittable &objects);
void write_color_ppm(std::ostream &out, Color color);

int main() {
	// Image
	const double aspect_ratio = 16.0 / 9.0;
	const int image_width = 1920;
	const int image_height = static_cast<int>(image_width / aspect_ratio);
	const int samples_per_pixel = 32;
	
	//Camera
	Camera camera(Vec3(0.0, 0.0, 0.0), 2.0 * aspect_ratio, 2.0, degToRad(35.0));

	Ray3HittableList objects;
	objects.add(make_shared<Sphere>(Vec3(0.0, 0.0, -10.0), 0.5));
	objects.add(make_shared<Sphere>(Vec3(0.0,-100.5,-10.0), 100));

	std::cout << "P3\n" << image_width << ' ' << image_height << "\n255\n";

	for(int j = image_height - 1; j >= 0; --j) {
		std::cerr << "\rScanlines remaining: " << j << ' ' << std::flush;
		for(int i = 0; i < image_width; ++i) {
			Color pixel_color(0.0, 0.0, 0.0);
			for(int s = 0; s < samples_per_pixel; ++s) {
				double u = (i + Random::inRange(0.0, 1.0))/ static_cast<double>(image_width - 1);
				double v = (j + Random::inRange(0.0, 1.0)) / static_cast<double>(image_height - 1);

				Ray3 ray = camera.getRay(u, v);
				pixel_color += ray_color(ray, objects);
			}

			write_color_ppm(std::cout, pixel_color / static_cast<double>(samples_per_pixel));
		}
	}

	std::cerr << "\nDone.\n" << std::flush;

	return 0;
}

Color ray_color(const Ray3 &ray, const Ray3Hittable &objects) {
	Ray3HitRecord hitRecord;
	if(objects.hit(ray, 0.0001, std::numeric_limits<double>::infinity(), hitRecord)) {
		return Color(0.5 * (hitRecord.normal + Color::white().toVec3()));
	}

	double t = 0.5 * (ray.getDirection().getY() + 1.0);
	return (1.0 - t) * Color(1.0, 1.0, 1.0) + t * Color(0.5, 0.7, 1.0);
}

void write_color_ppm(std::ostream &out, Color color) {
	color = color.clamped();

	out 	<< static_cast<int>(255.999 * color.getR()) << ' '
		<< static_cast<int>(255.999 * color.getG()) << ' '
		<< static_cast<int>(255.999 * color.getB()) << '\n';
}
