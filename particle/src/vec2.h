#ifndef __VEC2F_H__
#define __VEC2F_H__

#include <stddef.h>
#include <math.h>

struct vec2f {
	union {float x, a;};
	union {float y, b;};

	vec2f();
	vec2f(float x, float y);
	vec2f(const vec2f &other);
	~vec2f();

	float& operator[](const size_t i);
	
	vec2f operator+() const;
	vec2f operator-() const;
	vec2f operator=(const vec2f &other);

	vec2f operator+(const vec2f &other) const;
	vec2f operator+(const float &val) const;
	vec2f operator-(const vec2f &other) const;
	vec2f operator-(const float &val) const;
	vec2f operator*(const float &val) const;
	vec2f operator/(const float &val) const;

	vec2f& operator+=(const vec2f &other);
	vec2f& operator+=(const float &val);
	vec2f& operator-=(const vec2f &other);
	vec2f& operator-=(const float &val);

	float length() const;
	vec2f normalized() const;
	float distance_squared(const vec2f &other) const;
	float distance(const vec2f &other) const;
};

#endif