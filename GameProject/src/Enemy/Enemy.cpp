#include "Enemy.h"
#include "pch.h"

void Enemy::SetSize(int _a) { this->Size = _a; };
int Enemy::Get_Size() { return this->Size; };

void Enemy::Set_X_Y(int _x, int _y) {
	this->X = _x;
	this->Y = _y;
};
int Enemy::Get_X() { return this->X; };
int Enemy::Get_Y() { return this->Y; };
void Enemy::AddOne(bool _a, bool _b) {
	if (_a == true)
	{
		this->X++;
	}
	if (_b == true)
	{
		this->Y++;
	}
};

void Enemy::Set_R_G_B(float R, float G, float B){
	this->R = R;
	this->G = G;
	this->B = B;
}
float Enemy::Get_R() { return this->R; };
float Enemy::Get_G() { return this->G; };
float Enemy::Get_B() { return this->B; };

Enemy::Enemy() {
	this->Size = 10;
	this->X = 0;
	this->Y = 0;
	this->R =
		this->G =
		this->B = 0;
};