#include <iostream>

#include "vec3.hpp"
#include "color.hpp"

void write_color_ppm(std::ostream &out, Color color);

int main() {
	const int image_width = 256;
	const int image_height = 256;

	std::cout << "P3\n" << image_width << ' ' << image_height << "\n255\n";

	for(int j = image_height - 1; j >= 0; --j) {
		std::cerr << "\rScanlines remaining: " << j << ' ' << std::flush;
		for(int i = 0; i < image_width; ++i) {
			Color pixel_color(
				i / static_cast<double>(image_width - 1),
				j / static_cast<double>(image_height - 1),
				0.5
			);

			write_color_ppm(std::cout, pixel_color);
		}
	}

	std::cerr << "\nDone.\n" << std::flush;

	return 0;
}

void write_color_ppm(std::ostream &out, Color color) {
	out 	<< static_cast<int>(255.999 * color.getR()) << ' '
		<< static_cast<int>(255.999 * color.getG()) << ' '
		<< static_cast<int>(255.999 * color.getB()) << '\n';
}
