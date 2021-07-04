#include "Figures/Ellipse.h"
#include "pch.h"

int ellipse::Get_R() { return this->R; };
int ellipse::CheckIfDraw(int _R, int _x, int _y) {
	int temp = pow((_R - _x), 2) + pow((_R - _x), 2);
	temp = sqrt(temp);
	return temp;
}
/// <summary>
/// 
/// </summary>
/// <param name="_u">Status UP</param>
/// <param name="_d">Status DOWN</param>
/// <param name="_r">Status RIGHT</param>
/// <param name="_l">Status LEFT</param>
/// <param name="_b">Move count</param>
void ellipse::Update(bool _u, bool _d, bool _r, bool _l, int _b) {
	this->move = _b;
	if (_u == true) { this->up = false; _y -= _b; }
	if (_d == true) { this->down = false; _y += _b; }
	if (_r == true) { this->right = false; _x += _b; }
	if (_l == true) { this->left = false; _x -= _b; }
}

ellipse::ellipse() {
	this->R = 200;
	this->_x = 10;
	this->_y = 10;
	this->r = 0;
	this->g = 0;
	this->b = 0;
	this->move = 5;

	this->up = false;
	this->down = false;
	this->left = false;
	this->right = false;
}