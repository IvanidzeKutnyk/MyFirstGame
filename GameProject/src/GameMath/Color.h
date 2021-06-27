#pragma once

class Color
{
public:
	float R;
	float G;
	float B;
public:
	Color();
	Color(float R, float G, float B);
	Color(const Color& other);
	Color& operator=(const Color& other);

	bool operator==(const Color& other) const;
	bool operator!=(const Color& other) const;

	Color& operator+=(const Color& other);
	Color& operator+=(const float value);

	Color& operator-=(const Color& other);
	Color& operator-=(const float value);

	Color& operator/=(const Color& other);
	Color& operator/=(const float value);

	Color& operator*=(const Color& other);
	Color& operator*=(const float value);

	Color operator+(const Color& other) const;
	Color operator+(const float value) const;

	Color operator-(const Color& other) const;
	Color operator-(const float value) const;

	Color operator/(const Color& other) const;
	Color operator/(const float value) const;

	Color operator*(const Color& other) const;
	Color operator*(const float value) const;
};