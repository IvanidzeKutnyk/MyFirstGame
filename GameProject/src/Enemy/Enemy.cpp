#include "Enemy.h"
#include "pch.h"
void Enemy::SetSize(int _a) { this->Size = _a; };
int Enemy::Get_Size() { return this->Size; };
int Enemy::Get_Amount() { return this->amount; }
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

bool Enemy::Get_Stat_D() { return this->death; };
void Enemy::Set_Stat_D() { this->death = true; };

void Enemy::Update() {
	/// Start area
	//Down ->
	if (this->X < this->_mWidth / 2 && this->Y < this->_mHeight / 2 && this->start_point == false) {
		this->down = true;
		this->right = true;
		this->start_point = true;
	}
	//Down <-
	if (this->X > this->_mWidth / 2 && this->Y < this->_mHeight / 2 && this->start_point == false) {
		this->down = true;
		this->left = true;
		this->start_point = true;
	}
	//Up ->
	if (this->X < this->_mWidth / 2 && this->Y > this->_mHeight / 2 && this->start_point == false) {
		this->up = true;
		this->right = true;
		this->start_point = true;
	}
	//Up <-
	if (this->X > this->_mWidth / 2 && this->Y > this->_mHeight / 2 && this->start_point == false) {
		this->up = true;
		this->left = true;
		this->start_point = true;
	}
	
	///border_kick
	//Right
	if (this->X + this->Size >= this->_mWidth - 5) { this->right = false; this->left = true; }
	//Left
	if (this->X <= 5) { this->left = false; this->right = true;}
	//Down
	if (this->Y + this->Size >= this->_mHeight - 5) { this->down = false; this->up = true; }
	//UP
	if (this->Y <= 5) { this->up = false; this->down = true;}
}
void Enemy::Get_Stat() {
	//down ->
	if (this->down == true && this->right == true)
	{
		this->X += this->speed;
		this->Y += this->speed;
	}
	//Down <-
	if (this->down == true && this->left == true)
	{
		this->X -= this->speed;
		this->Y += this->speed;
	}
	//up ->
	if (this->up == true && this->right == true)
	{
		this->X += this->speed;
		this->Y -= this->speed;
	}
	//up <-
	if (this->up == true && this->left == true)
	{
		this->X -= this->speed;
		this->Y -= this->speed;
	}
	
}
void Enemy::Draw(Color _color, Color** _CollorBuffer) 
{
	
	for (int i = 0; i < Size; i++)
	{
		for (int j = 0; j < Size; j++)
		{
			_CollorBuffer[this->Y + i][X + j] = _color;
		}
	}
	Get_Stat();
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
	this->speed = 2;
	this->death = false;
	this->start_point = false;
	this->amount = 3;
	this->_mWidth = _w;
	this->_mHeight = _h;
	this->up =
		this->down =
		this->left =
		this->right = false;
	//snprintf(buff, sizeof(buff), "ddddd\n", 0);
	//OutputDebugStringA(buff);
	
}