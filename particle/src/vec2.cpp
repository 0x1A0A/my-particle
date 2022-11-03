#include "vec2.h"

vec2f::vec2f() : x(0), y(0) {}
vec2f::vec2f(float x, float y) : x(x), y(y) {}
vec2f::vec2f(const vec2f &other) : x(other.x), y(other.y) {}
vec2f::~vec2f() {};

float& vec2f::operator[](const size_t i) { return i%2 ? x: y; }

vec2f vec2f::operator+() const
{
	return {x,y};
}

vec2f vec2f::operator-() const
{
	return {-x,-y};
}

vec2f vec2f::operator=(const vec2f &other)
{
	this->x = other.x;
	this->y = other.y;

	return *this;
}

vec2f vec2f::operator+(const vec2f &other) const
{
	return { x + other.x, y + other.y };
}

vec2f vec2f::operator+(const float &val) const
{
	return operator+({val,val});
}

vec2f vec2f::operator-(const vec2f &other) const
{
	return operator+( -other);
}

vec2f vec2f::operator-(const float &val) const
{
	return operator+(-val);
}

vec2f vec2f::operator*(const float &val) const
{
	return {x*val, y*val};
}

vec2f vec2f::operator/(const float &val) const
{
	return operator*(1/val);
}

vec2f& vec2f::operator+=(const vec2f &other)
{
	this->x += other.x;
	this->y += other.y;
	return *this;
}

vec2f& vec2f::operator+=(const float &val)
{
	return operator+=({val,val});
}

vec2f& vec2f::operator-=(const vec2f &other)
{
	return operator+=(-other.y);
}

vec2f& vec2f::operator-=(const float &val)
{
	return operator+=(-val);
}

float vec2f::length() const { return sqrt( x*x + y*y ); }

vec2f vec2f::normalized() const
{ 
	const float mag = length();
	return { x/mag, y/mag };
}

float vec2f::distance_squared(const vec2f &other) const
{
	return pow(x - other.x, 2) + pow(y - other.y, 2);
}

float vec2f::distance(const vec2f &other) const
{
	return sqrt( distance_squared(other) );
}