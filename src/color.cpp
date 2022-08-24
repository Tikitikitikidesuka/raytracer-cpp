#include "color.hpp"

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

void Color::clamp() {
	if(this->getR() > 1.0) this->setR(1.0);
	else if(this->getR() < 0.0) this->setR(0.0);

	if(this->getG() > 1.0) this->setG(1.0);
	else if(this->getG() < 0.0) this->setG(0.0);

	if(this->getB() > 1.0) this->setB(1.0);
	else if(this->getB() < 0.0) this->setB(0.0);
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
