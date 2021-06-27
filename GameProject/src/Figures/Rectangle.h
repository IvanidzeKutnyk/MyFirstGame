#pragma once
#include "GameMath/Color.h"
class Rectang
{
public:
	int _x;
	int _y;
	int height;
	int weight;
	float R, G, B;
public:
	//Full x = y = 0: h and w = 10
	Rectang();
	//Fill class variables
	Rectang(int x, int y, int _height, int _weight, float _R, float _G, float _B);
	//Destructor
	~Rectang();


};
