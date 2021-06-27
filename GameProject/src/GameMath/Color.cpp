#include "pch.h"
#include "Color.h"

Color::Color()
	: R(0.0f)
	, G(0.0f)
	, B(0.0f)
{
}

Color::Color(float fR, float fG, float fB)
	: R(fR)
	, G(fG)
	, B(fB)
{
}

Color::Color(const Color& other)
	: R(other.R)
	, G(other.G)
	, B(other.B)
{
}

Color& Color::operator=(const Color& other)
{
	if (this != &other)
	{
		this->R = other.R;
		this->G = other.G;
		this->B = other.B;
	}
	return *this;
}

bool Color::operator==(const Color& other) const
{
	return this->R == other.R && this->G == other.G && this->B == other.B;
}

bool Color::operator!=(const Color& other) const
{
	return !this->operator==(other);
}

Color& Color::operator+=(const Color& other)
{
	this->R += other.R;
	this->G += other.G;
	this->B += other.B;
	return *this;
}

Color& Color::operator+=(const float value)
{
	this->R += value;
	this->G += value;
	this->B += value;
	return *this;
}

Color& Color::operator-=(const Color& other)
{
	this->R -= other.R;
	this->G -= other.G;
	this->B -= other.B;
	return *this;
}

Color& Color::operator-=(const float value)
{
	this->R -= value;
	this->G -= value;
	this->B -= value;
	return *this;
}

Color& Color::operator/=(const Color& other)
{
	this->R /= other.R;
	this->G /= other.G;
	this->B /= other.B;
	return *this;
}

Color& Color::operator/=(const float value)
{
	this->R /= value;
	this->G /= value;
	this->B /= value;
	return *this;
}

Color& Color::operator*=(const Color& other)
{
	this->R *= other.R;
	this->G *= other.G;
	this->B *= other.B;
	return *this;
}

Color& Color::operator*=(const float value)
{
	this->R *= value;
	this->G *= value;
	this->B *= value;
	return *this;
}


Color Color::operator+(const Color& other)const
{
	return Color(this->R + other.R, this->G + other.G, this->B + other.B);
}

Color Color::operator+(const float value)const
{
	return Color(this->R + value, this->G + value, this->B + value);
}


Color Color::operator-(const Color& other)const
{
	return Color(this->R - other.R, this->G + -other.G, this->B - other.B);
}

Color Color::operator-(const float value)const
{
	return Color(this->R - value, this->G - value, this->B - value);
}

Color Color::operator/(const Color& other)const
{
	return Color(this->R / other.R, this->G / other.G, this->B / other.B);
}

Color Color::operator/(const float value)const
{
	return Color(this->R / value, this->G / value, this->B / value);
}

Color Color::operator*(const Color& other)const
{
	return Color(this->R * other.R, this->G * other.G, this->B * other.B);
}

Color Color::operator*(const float value)const
{
	return Color(this->R * value, this->G * value, this->B * value);
}