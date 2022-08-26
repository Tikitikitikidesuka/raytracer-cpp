#include "vec3.hpp"

#include <cmath>
#include <iostream>

#include "random.hpp"

Vec3::Vec3()
	: x(0.0), y(0.0), z(0.0) {}

Vec3::Vec3(double x, double y, double z)
	: x(x), y(y), z(z) {}

Vec3 Vec3::zero() {
	return Vec3(0.0, 0.0, 0.0);
}

Vec3 Vec3::randomUnit() {
	return Vec3::randomInUnitSphere().normalized();
}

Vec3 Vec3::randomInUnitSphere() {
	Vec3 randomVec;

	do {
		randomVec = Vec3(
			Random::inRange(-1.0, 1.0),
			Random::inRange(-1.0, 1.0),
			Random::inRange(-1.0, 1.0)
		);
	} while(randomVec.lengthSquared() > 1.0);

	return randomVec;
}

Vec3 Vec3::randomInUnitHemisphere(const Vec3 &normal) {
	Vec3 inUnitSphereVec = Vec3::randomInUnitSphere();

	if(inUnitSphereVec.dot(normal) < 0.0)
		return -inUnitSphereVec;
	return inUnitSphereVec;
}

double Vec3::getX() const {
	return this->x;
}

double Vec3::getY() const {
	return this->y;
}

double Vec3::getZ() const {
	return this->z;
}

void Vec3::setX(double x) {
	this->x = x;
}

void Vec3::setY(double y) {
	this->y = y;
}

void Vec3::setZ(double z) {
	this->z = z;
}

Vec3 Vec3::operator-() const {
	return Vec3(-this->x, -this->y, -this->z);
}

bool operator==(const Vec3 &v1, const Vec3 &v2) {
	return  v1.x == v2.x &&
		v1.y == v2.y &&
		v1.z == v2.z;
}

bool operator!=(const Vec3 &v1, const Vec3 &v2) {
	return !(v1 == v2);
}

Vec3 operator+(const Vec3 &v1, const Vec3 &v2) {
	return Vec3(v1.x + v2.x, v1.y + v2.y, v1.z + v2.z);
}

Vec3 operator-(const Vec3 &v1, const Vec3 &v2) {
	return Vec3(v1.x - v2.x, v1.y - v2.y, v1.z - v2.z);
}

Vec3 operator*(const Vec3 &v, const double t) {
	return Vec3(v.x * t, v.y * t, v.z * t);
}

Vec3 operator*(const double t, const Vec3 &v) {
	return Vec3(v.x * t, v.y * t, v.z * t);
}

Vec3 operator/(const Vec3 &v, const double t) {
	return Vec3(v.x / t, v.y / t, v.z / t);
}

std::ostream& operator<<(std::ostream &out, const Vec3 &v) {
	return out << "(" << v.x << ", " << v.y << ", " << v.z << ")";
}

Vec3& Vec3::operator+=(const Vec3 &v) {
	this->x += v.x;
	this->y += v.y;
	this->z += v.z;

	return *this;
}

Vec3& Vec3::operator-=(const Vec3 &v) {
	this->x -= v.x;
	this->y -= v.y;
	this->z -= v.z;

	return *this;
}

Vec3& Vec3::operator*=(const double t) {
	this->x *= t;
	this->y *= t;
	this->z *= t;

	return *this;
}

Vec3& Vec3::operator/=(const double t) {
	this->x /= t;
	this->y /= t;
	this->z /= t;

	return *this;
}

double Vec3::dot(const Vec3 &v) const {
	return  this->x * v.x +
		this->y * v.y +
		this->z * v.z;
}

Vec3 Vec3::cross(const Vec3 &v) const {
	Vec3 result;
	
	result.x = this->y * v.z - this->z * v.y;
	result.y = -(this->x * v.z - this->z * v.x);
	result.z = this->x * v.y - this->y * v.x;

	return result;
}

Vec3 Vec3::normalized() const {
	return *this / (*this).length();
}

double Vec3::distanceTo(const Vec3 &v) const {
	return (v - (*this)).length();
}

Vec3 Vec3::reflection(const Vec3 &normal) const {
	double dotProduct = (*this).dot(normal);

	if(dotProduct < 0.0) 
		dotProduct = -dotProduct;

	return *this - 2.0 * dotProduct * normal;
}

Vec3 Vec3::refraction(const Vec3 &normal, const double n1OverN2) const {
	double cosTheta = fmin(-(*this).dot(normal), 1.0);
	Vec3 outPerpendicular = n1OverN2 * ((*this) + cosTheta * normal);
	Vec3 outParallel = -sqrt(fabs(1.0 - outPerpendicular.lengthSquared())) * normal;
	return outPerpendicular + outParallel;
}

double Vec3::length() const {
	return sqrt(this->lengthSquared());
}

double Vec3::lengthSquared() const {
	return  this->x * this->x +
		this->y * this->y +
		this->z * this->z;
}
