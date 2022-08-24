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
#include "material.hpp"
#include "lambertian.hpp"

Color ray_color(const Ray3 &ray, const Ray3Hittable &objects, int depth);
void write_color_ppm(std::ostream &out, Color color);

int main() {
	// Image
	const double aspect_ratio = 16.0 / 9.0;
	const int image_width = 640;
	const int image_height = static_cast<int>(image_width / aspect_ratio);
	const double gammaCorrection = 0.5;
	const int samples_per_pixel = 128;
	const int max_bounces = 32;
	
	//Camera
	Camera camera(Vec3(0.0, 0.0, 0.0), 2.0 * aspect_ratio, 2.0, degToRad(35.0));

	// Scene
	//auto material_left = make_shared<LambertianMat>(Color(0.584, 0.322, 0.651));
	//auto material_right = make_shared<LambertianMat>(Color(0.733, 0.235, 0.741));
	//auto material_ground = make_shared<LambertianMat>(Color(0.384, 0.235, 0.408));
	auto material_left = make_shared<LambertianMat>(Color(1.0, 0.0, 0.0));
	auto material_right = make_shared<LambertianMat>(Color(0.0, 1.0, 0.0));
	auto material_ground = make_shared<LambertianMat>(Color(0.0, 0.0, 1.0));

	Ray3HittableList objects;
	objects.add(make_shared<Sphere>(Vec3(0.0, -0.45, -5.0), 0.5, material_left));
	objects.add(make_shared<Sphere>(Vec3(0.6, -0.15, -5.2), 0.4, material_right));
	objects.add(make_shared<Sphere>(Vec3(0.0,-100.5,-10.0), 100, material_ground));

	std::cout << "P3\n" << image_width << ' ' << image_height << "\n255\n";

	for(int j = image_height - 1; j >= 0; --j) {
		std::cerr << "\rScanlines remaining: " << j << ' ' << std::flush;
		for(int i = 0; i < image_width; ++i) {
			Color pixel_color(0.0, 0.0, 0.0);
			for(int s = 0; s < samples_per_pixel; ++s) {
				double u = (i + Random::inRange(0.0, 1.0))/ static_cast<double>(image_width - 1);
				double v = (j + Random::inRange(0.0, 1.0)) / static_cast<double>(image_height - 1);

				Ray3 ray = camera.getRay(u, v);
				pixel_color += ray_color(ray, objects, max_bounces);
			}

			pixel_color /= static_cast<double>(samples_per_pixel);
			pixel_color = pixel_color.gammaCorrected(gammaCorrection);
			write_color_ppm(std::cout, pixel_color);
		}
	}

	std::cerr << "\nDone.\n" << std::flush;

	return 0;
}

Color ray_color(const Ray3 &ray, const Ray3Hittable &objects, int depth) {
	if(depth <= 0)
		return Color::black();

	Ray3HitRecord hitRecord;
	if(objects.hit(ray, 0.001, infinity, hitRecord)) {
		Ray3 scattered;
		Color attenuation;
		if(hitRecord.materialPtr->scatter(ray, hitRecord, attenuation, scattered))
			return attenuation * ray_color(scattered, objects, depth - 1);
		return Color::black();
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
