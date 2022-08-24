#include "color.hpp"

#include <cmath>

Color::Color()
	: rgbData(Vec3()) {}

Color::Color(const Vec3 &v)
	: rgbData(v) {}

Color::Color(double r, double g, double b)
	: rgbData(Vec3(r, g, b)) {}

Color Color::black() {
	return Color(0.0, 0.0, 0.0);
}

Color Color::white() {
	return Color(1.0, 1.0, 1.0);
}

Vec3 Color::toVec3() const {
	return this->rgbData;
}

double Color::getR() const {
	return this->rgbData.getX();
}

double Color::getG() const {
	return this->rgbData.getY();
}

double Color::getB() const {
	return this->rgbData.getZ();
}

void Color::setR(double r) {
	this->rgbData.setX(r);
}

void Color::setG(double g) {
	this->rgbData.setY(g);
}

void Color::setB(double b) {
	this->rgbData.setZ(b);
}

Color Color::clamped() const {
	Color color = (*this);

	if(color.getR() > 1.0) color.setR(1.0);
	else if(color.getR() < 0.0) color.setR(0.0);

	if(color.getG() > 1.0) color.setG(1.0);
	else if(color.getG() < 0.0) color.setG(0.0);

	if(color.getB() > 1.0) color.setB(1.0);
	else if(color.getB() < 0.0) color.setB(0.0);

	return color;
}

Color Color::gammaCorrected(double gamma) const {
	Color color = (*this);

	color.setR(pow(color.getR(), gamma));
	color.setG(pow(color.getG(), gamma));
	color.setB(pow(color.getB(), gamma));

	return color;
}

bool operator==(const Color &c1, const Color &c2) {
	return c1.rgbData == c2.rgbData;
}

bool operator!=(const Color &c1, const Color &c2) {
	return !(c1 == c2);
}

Color operator+(const Color &c1, const Color &c2) {
	return Color(c1.rgbData + c2.rgbData);
}

Color operator-(const Color &c1, const Color &c2) {
	return Color(c1.rgbData - c2.rgbData);
}

Color operator*(const Color &c, const double t) {
	return Color(c.rgbData * t);
}

Color operator*(const double t, const Color &c) {
	return Color(c.rgbData * t);
}

Color operator*(const Color &c1, const Color &c2) {
	return Color(
		c1.getR() * c2.getR(),
		c1.getG() * c2.getG(),
		c1.getB() * c2.getB()
	);
}

Color operator/(const Color &c, const double t) {
	return Color(c.rgbData / t);
}

std::ostream& operator<<(std::ostream &out, const Color &c) {
	return out << c.rgbData;
}

Color& Color::operator+=(const Color &c) {
	this->rgbData += c.rgbData;
	return *(this);
}

Color& Color::operator-=(const Color &c) {
	this->rgbData -= c.rgbData;
	return *(this);
}

Color& Color::operator*=(const double t) {
	this->rgbData *= t;
	return *(this);
}

Color& Color::operator/=(const double t) {
	this->rgbData /= t;
	return *(this);
}
