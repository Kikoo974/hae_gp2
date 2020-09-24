#pragma once

template<typename T>

class Vec3T
{
public:
	T x;
	T y;
	T z;
	Vec3T<T>()
	{
		x = {};
		y = {};
		z = {};
	}
	Vec3T<T>(T x, T y, T z) {
		this->x = x;
		this->y = y;
		this->z = z;
	};
	Vec3T<T> add(Vec3T v)
	{
		Vec3T<T> xyz;
		xyz.x = this->x + v.x;
		xyz.y = this->y + v.y;
		xyz.z = this->z + v.z;
		return xyz;
	}
	Vec3T<T> mul(Vec3T v)
	{
		Vec3T<T> xyz;
		xyz.x = this->x * v.x;
		xyz.y = this->y * v.y;
		xyz.z = this->z * v.z;
		return xyz;
	}
};