#include <iostream>
#include <limits>

#include <SDL.h>

#include "utils.hpp"
#include "vec3.hpp"
#include "ray3.hpp"
#include "color.hpp"
#include "camera.hpp"
#include "ray3hittable.hpp"
#include "ray3hittable_list.hpp"
#include "hittables/sphere.hpp"
#include "random.hpp"
#include "material.hpp"
#include "materials/lambertian.hpp"
#include "materials/metal.hpp"
#include "materials/dielectric.hpp"
#include "hittables/triangle.hpp"

Color ray_color(const Ray3 &ray, const Ray3Hittable &objects, int depth);
unsigned char colorToByte(double color);

int main() {
	// Image
	const double aspect_ratio = 16.0 / 9.0;
	const int image_width = 640;//256;
	const int image_height = static_cast<int>(image_width / aspect_ratio);
	const double gammaCorrection = 0.5;
	const int samples_per_pixel = 128;
	const int max_bounces = 32;

	// Camera
	Camera camera(Vec3(0.0, 0.0, 0.0), 2.0 * aspect_ratio, 2.0, degToRad(35.0));

	// Scene materials
	auto material_mirror = make_shared<MetalMat>(Color(0.8, 0.8, 0.8), 0.0);
	auto material_left = make_shared<MetalMat>(Color(1.0, 0.5, 0.5), 0.01);
	auto material_right = make_shared<MetalMat>(Color(0.5, 1.0, 0.5), 0.7);
	auto material_ground = make_shared<LambertianMat>(Color(0.5, 0.5, 1.0));

	// Scene objects
	Ray3HittableList objects;
	objects.add(make_shared<Triangle>(Vec3(-0.2, 0.0, -3.0), Vec3(0.0, 0.0, -2.5), Vec3(-0.1, 1.0, -3.0), material_left));
	objects.add(make_shared<Triangle>(Vec3(-0.2, 0.0, -6.0), Vec3(0.0, 0.3, -4.0), Vec3(0.2, 0.0, -5.0), material_left));
	objects.add(make_shared<Sphere>(Vec3(-0.3, -0.15, -5.0), 0.5, material_left));
	objects.add(make_shared<Sphere>(Vec3(0.6, -0.15, -5.2), 0.4, material_right));
	objects.add(make_shared<Sphere>(Vec3(0.0,-100.5,-10.0), 100, material_ground));

	// Initialize SDL and create window
	SDL_Init(SDL_INIT_VIDEO);
	SDL_Window *window = SDL_CreateWindow(
		"Raytracer", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
		image_width, image_height, 0
	);

	// Create SDL renderer
	SDL_Renderer *renderer = SDL_CreateRenderer(window, -1, 0);

	// Clear window
	SDL_SetRenderDrawColor(renderer, 0.0, 0.0, 0.0, 0.0);
	SDL_RenderClear(renderer);

	// SDL event data
	bool quit = false;
	SDL_Event event;

	for(int j = image_height - 1; !quit && j >= 0; --j) {
		for(int i = 0; !quit && i < image_width; ++i) {
			SDL_WaitEvent(&event);

			switch (event.type) {
				case SDL_QUIT:
					quit = true;
					break;
			}

			Color pixel_color(0.0, 0.0, 0.0);
			for(int s = 0; !quit && s < samples_per_pixel; ++s) {
				double u = (i + Random::inRange(0.0, 1.0))/ static_cast<double>(image_width - 1);
				double v = (j + Random::inRange(0.0, 1.0)) / static_cast<double>(image_height - 1);

				Ray3 ray = camera.getRay(u, v);
				pixel_color += ray_color(ray, objects, max_bounces);
			}

			pixel_color /= static_cast<double>(samples_per_pixel);
			pixel_color = pixel_color.gammaCorrected(gammaCorrection);

			SDL_SetRenderDrawColor(
				renderer,
				255,//colorToByte(pixel_color.getR()),
				255,//colorToByte(pixel_color.getG()),
				255,//colorToByte(pixel_color.getB()),
				255	
			);
			SDL_RenderDrawPoint(renderer, j, i);
			SDL_RenderPresent(renderer);
		}
	}

	// Free SDL resources
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);

	// Terminate SDL
	SDL_Quit();







	return 0;
}

Color ray_color(const Ray3 &ray, const Ray3Hittable &objects, int depth) {
	if(depth <= 0)
		return Color::black();

	Ray3HitRecord hitRecord;
	if(objects.hit(ray, 0.0001, infinity, hitRecord)) {
		Ray3 scattered;
		Color attenuation;
		if(hitRecord.materialPtr->scatter(ray, hitRecord, attenuation, scattered))
			return attenuation * ray_color(scattered, objects, depth - 1);
		return Color::black();
	}

	double t = 0.5 * (ray.getDirection().getY() + 1.0);
	return (1.0 - t) * Color(1.0, 1.0, 1.0) + t * Color(0.5, 0.7, 1.0);
}

unsigned char colorToByte(double color) {
	return static_cast<unsigned char>(255.999 * color);
}
