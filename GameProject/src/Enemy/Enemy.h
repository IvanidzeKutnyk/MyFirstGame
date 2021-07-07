#pragma once
class Enemy {
public:
	void SetSize(int _a);
	int Get_Size();

	void Set_X_Y(int _x, int _y);
	int Get_X();
	int Get_Y();
	void AddOne(bool _a, bool _b);

	void Set_R_G_B(float R, float G, float B);

	float Get_R();
	float Get_G();
	float Get_B();

	int Get_Count();
	Enemy();
	~Enemy() {};
private:
	// Enemy size
	int Size;

	// Coordinates
	int X;
	int Y;

	// Color
	float R, G, B;

	static int couter;
};