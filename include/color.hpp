#ifndef COLOR_H
#define COLOR_H

#include "vec3.hpp"

class Color {
	public:
		Color();
		Color(double r, double g, double b);

		static Color black();
		static Color white();

		double getR() const;
		double getG() const;
		double getB() const;

		void setR(double r);
		void setG(double g);
		void setB(double b);

		Color& operator+=(const Color &c);
		Color& operator-=(const Color &c);
		Color& operator*=(const double t);
		Color& operator/=(const double t);
	
	private:
		Vec3 rgbData;
	
	friend bool operator==(const Color &c1, const Color &c2);
	friend bool operator!=(const Color &c1, const Color &c2);
	friend Color operator+(const Color &c1, const Color &c2);
	friend Color operator-(const Color &c1, const Color &c2);
	friend Color operator*(const Color &c1, const double t);
	friend Color operator*(const double t, const Color &c1);
	friend Color operator/(const Color &c1, const double t);
	friend Color operator/(const double t, const Color &c1);
	friend std::ostream& operator<<(std::ostream &out, const Color &c);
};

#endif
