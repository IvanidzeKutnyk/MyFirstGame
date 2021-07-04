#include "Triangle.h"
#include "pch.h"
#include "Application/Window.h"

void Triang::Set_Tr_E_2(int _ia, int x, int y, float r, float g, float b) {

	this->iA = _ia;
	this->_x = x;
	this->_y = y;
	this->R = r;
	this->G = g;
	this->B = b;
};

int Triang::Get_tA() { return this->tA; };
int Triang::Get_tB() { return this->tB; };
int Triang::Get_tC() { return this->tC; };

int Triang::Get_iA() { return this->iA; };
float Triang::Get_height() { return this->height; };


void Triang::Set_height(int _a) {
	this->height = (int)((_a * sqrt(3)) / 2);
};

float Triang::Get_R() { return this->R; };
float Triang::Get_G() { return this->G; };
float Triang::Get_B() { return this->B; };

int Triang::Get_x() { return this->_x; };
int Triang::Get_y() { return this->_y; };
void Triang::Set_X(int _x) { this->_x = _x; };
void Triang::Set_Y(int _y) { this->_y = _y; };
void Triang::Plus_X() { this->_x++; };
void Triang::Plus_Y() { this->_y++; };

Triang::Triang() {}
Triang::Triang(int _ia, int x, int y, float r, float g, float b) {
	this->iA = _ia;
	this->_x = x;
	this->_y = y;
	this->R = r;
	this->G = g;
	this->B = b;
	Set_height(iA);
}
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