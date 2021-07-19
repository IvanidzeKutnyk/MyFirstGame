#include "pch.h"
#include "Shot.h"

Shooting::Shooting(int _a, int _b, int _c, Player* _player) {
	this->hight = _a;
	this->weight = _b;
	this->speed = _c;
	this->Y = _player->Get_Y();
	this->X = X_param(_player->Get_X(), _player->Get_Size());
	this->w_hi = _player->Get_W_H();
	this->w_we = _player->Get_W_W();
	this->Stat_Shot = false;
};
void Shooting::Draw(Color _color, Color** _CollorBuffer) {

	for (int i = 0; i < this->hight; i++)
	{
		for (int j = 0; j < this->weight; j++)
		{
			_CollorBuffer[this->Y + i][X + j] = _color;
		}
	}
}
void Shooting::Update() {
	if (this->X <= 5 || this->X >= this->w_we - 5) {}
	if (this->Y <= 5 || this->Y >= this->w_hi - 5) {}
	else
	{
		this->Y -= this->speed;
	}
}
int Shooting::X_param(int _x, int _y){
	return this->X  = _x+ ((_y / 2) - (this->weight / 2));
}