#include "Player.h"
#include "pch.h"
//Set Status Move
void Player::Set_up(bool _a) { this->up = _a; };
void Player::Set_down(bool _a) { this->down = _a; };
void Player::Set_left(bool _a) { this->left = _a; };
void Player::Set_right(bool _a) { this->right = _a; };

// coordinates
void Player::Set_X_Y(int _X, int _Y) 
{
	this->_mWidth = _X;
	this->_mHeight = _Y;
	this->Y = (_Y - this->Size) - 10;
	this->X = (_X / 2) - this->Size;
}

//Get Coo. player
int Player::Get_X() { return this->X; };
int Player::Get_Y() { return this->Y; };

//Get Main Window Param
int Player::Get_W_H() { return this->_mHeight; };
int Player::Get_W_W() { return this->_mWidth; };

// Object Size
int Player::Get_Size() { return this->Size; };

// Set movement params to false
void Player::Set_Movement_False() {
	this->up =
		this->down =
		this->left =
		this->right = false;
}

// Part of object
void Player::Set_height(int _a)
{
	this->height = (int)((_a * sqrt(3)) / 2);
};

// Get height (not USe)
int Player::Get_height() { return this->height; };

// Move object
void Player::Set_Move(int _a) { this->Move = _a; };

//Main Function
void Player::Update() {
	// Check End_Window
	if (this->X + this->Size > this->_mWidth - this->Move - 5)
	{
		this->right = false;
	}
	if (this->X < this->Move + 3)
	{
		this->left = false;
	}
	if (this->Y + this->Size > this->_mHeight - this->Move - 5) 
	{
		this->down = false;
	}
	if (this->Y < this->Move + 3)
	{
		this->up = false;
	}

	//Move
	if (this->up == true) {this->Y -= this->Move; }
	if (this->down == true) {this->Y += this->Move; }
	if (this->left == true) {this->X -= this->Move; }
	if (this->right == true) {this->X += this->Move; }


}

void Player::FiilMass() {

	mass[0][0] = { 0 }; mass[0][1] = { 1 };
	mass[1][0] = { 0 }; mass[1][1] = { 1 };
}

void Player::Draw(Color _color, Color** _ColorBuffer) {
	float temp = Size / 2;
	for (int i = 0; i < Size; i++)
	{
		if (temp == 0)
		{
			break;
		}
		for (int j = 0; j < Size; j++)
		{
			_ColorBuffer[Y + i][X + j] = _color;
		}

	}
}

Player::Player(int _X, int _Y)//1024 500 
{
	Set_Movement_False();

	this->Move = 5;
	this->Size = 30;
	this->X = this->Y = 50;
	Set_X_Y(_X, _Y);
	Set_height(this->height);
}