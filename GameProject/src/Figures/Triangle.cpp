#include "Triangle.h"
#include "pch.h"
#include "Application/Window.h"

Triang::Triang() {}
Triang::Triang(int _tA, int _tB, int _tC, int _x, int _y, float _R, float _G, float _B) {
	this->tA = _tA;
	this->tB = _tB;
	this->tC = _tC;
	this->_x = _x;
	this->_y = _y;
	this->R = _R;
	this->G = _G;
	this->B = _B;
}
Triang::~Triang() {}