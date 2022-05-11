#include "Vector.h"
#define M_PIF 3.141592653589793238462643383279502884e+00F
#include <cmath>
#include <numbers>

void Vector::operator+=(Vector const& other) {
	x += other.x;
	y += other.y;
}

void Vector::operator-=(Vector const& other) {
	x -= other.x;
	y -= other.y;
}

Vector Vector::operator*(float coeff) const {
	return { x * coeff, y * coeff };
}

Vector Vector::createFromAngle(float size, float angle) {
	return {size*cos(angle/180.f*M_PIF), size*sin(angle/180.f*M_PIF)};
}