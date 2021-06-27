#pragma once
#include "GameMath/Color.h"
class Triang
{
public:
	int tA;
	int tB;
	int tC;
	int _x;
	int _y;
	float R, G, B;
public:
	Triang();
	Triang(int _tA, int _tB, int _tC, int _x, int _y, float _R, float _G, float _B);
	~Triang();

};
