#pragma once

struct Vector
{
	void operator+=(Vector const& other);
	void operator-=(Vector const& other);
	Vector operator*(float coefficient) const;
	float x = 0.f;
	float y = 0.f;

	static Vector createFromAngle(float size, float angle);
};

