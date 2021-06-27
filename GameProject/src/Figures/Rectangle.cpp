#include "pch.h"
#include "Rectangle.h"
#include "Application/Window.h"

Rectang::Rectang() {
	this->_x = 0;
	this->_y = 0;
	this->R = 0;
	this->G = 0;
	this->B = 0;
	this->height = 100;
	this->weight = 100;

}
Rectang::Rectang(int x, int y, int _height, int _weight, float _R, float _G, float _B) {
	this->_x = x;
	this->_y = y;
	this->R = _R;
	this->G = _G;
	this->B = _B;
	this->height = _height;
	this->weight = _weight;
}
Rectang::~Rectang() {}
/*
void Rectang::Move(int _x, int _y, int height, int weight, const Color& color1) {


	for (int i = 0; i < height; i++)
	{
		for (int j = 0; j < weight; j++)
		{
			this->_mColorBuffer[_y + i][_x + j].R = color1.R;
			this->_mColorBuffer[_y + i][_x + j].G = color1.G;
			this->_mColorBuffer[_y + i][_x + j].B = color1.B;
		}
	}
}
void Rectang::Move(const Color& color1) {


	for (int i = 0; i < this->height; i++)
	{
		for (int j = 0; j < this->weight; j++)
		{
			this->_mColorBuffer[this->_y + i][this->_x + j].R = color1.R;
			this->_mColorBuffer[this->_y + i][this->_x + j].G = color1.G;
			this->_mColorBuffer[this->_y + i][this->_x + j].B = color1.B;
		}
	}
}
*/
