#pragma once
#include "GameMath/Color.h"
class Triang
{
private:
	//(1)
	// Rectangular
	int tA;
	int tB;
	int tC;
	//(2)
	// Equilateral
	int iA;
	int height;

	int _x;
	int _y;
	float R, G, B;
public:
	void Set_Tr_E_2(int _ia, int x, int y, float r, float g, float b);

	int Get_tA();
	int Get_tB();
	int Get_tC();

	int Get_iA();
	float Get_height();
	void Set_height(int _a);
	

	float Get_R();
	float Get_G();
	float Get_B();

	int Get_x();
	int Get_y();
	void Set_X(int _x);
	void Set_Y(int _y);
	void Plus_X();
	void Plus_Y();

	Triang();
	Triang(int _ia, int x, int y, float r, float g, float b);
	Triang(int _tA, int _tB, int _tC, int _x, int _y, float _R, float _G, float _B);
	~Triang();

};
