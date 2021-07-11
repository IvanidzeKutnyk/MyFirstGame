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

char buff[100];

void Enemy::Update() {
	//if (this->X + this->Size == this->_mWidth - 1) { this->right = true; }


};
void Enemy::Draw(Color _color, Color** _CollorBuffer) 
{
	
	for (int i = 0; i < Size; i++)
	{
		for (int j = 0; j < Size; j++)
		{
			_CollorBuffer[this->Y + i][X + j] = _color;
		}
	}
	
	//snprintf(buff, sizeof(buff), "LOOL\n", 0);
	//OutputDebugStringA(buff);
};

Enemy::Enemy() {
	this->Size = 40;
	this->X = 0;
	this->Y = 0;
	this->death = false;
};

Enemy::Enemy(int _x, int _y, int _w, int _h) {
	this->Size = 40;
	this->X = _x;
	this->Y = _y;
	this->death = false;
	this->_mWidth = _w;
	this->_mHeight = _h;
	snprintf(buff, sizeof(buff), "ddddd\n", 0);
	OutputDebugStringA(buff);
	
}