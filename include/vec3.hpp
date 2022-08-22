#ifndef VEC3_H
#define VEC3_H

#include <iostream>

class Vec3 {
	public:
		Vec3();
		Vec3(double x, double y, double z);

		static Vec3 zero();

		static Vec3 randomUnit();
		static Vec3 randomInUnitSphere();
		static Vec3 randomInUnitHemisphere(Vec3 &normal);
		
		double getX() const;
		double getY() const;
		double getZ() const;

		void setX(double x);
		void setY(double y);
		void setZ(double z);

		Vec3 operator-() const;

		Vec3& operator+=(const Vec3 &v);
		Vec3& operator-=(const Vec3 &v);
		Vec3& operator*=(const double t);
		Vec3& operator/=(const double t);


		double dot(const Vec3 &v) const;
		Vec3 cross(const Vec3 &v) const;
		
		Vec3 normalized() const;

		Vec3 reflection(const Vec3 &normal) const;

		double length() const;
		double lengthSquared() const;

	private:
		double x;
		double y;
		double z;

	friend bool operator==(const Vec3 &v1, const Vec3 &v2);
	friend bool operator!=(const Vec3 &v1, const Vec3 &v2);
	friend Vec3 operator+(const Vec3 &v1, const Vec3 &v2);
	friend Vec3 operator-(const Vec3 &v1, const Vec3 &v2);
	friend Vec3 operator*(const Vec3 &v, const double t);
	friend Vec3 operator*(const double t, const Vec3 &v);
	friend Vec3 operator/(const Vec3 &v, const double t);
	friend Vec3 operator/(const double t, const Vec3 &v);
	friend std::ostream& operator<<(std::ostream &out, const Vec3 &v); 
};


#endif
