#include "Player.h"
#include "pch.h"

bool Player::Get_up() { return this->up; };
bool Player::Get_down() { return this->down; };
bool Player::Get_left() { return this->left; };
bool Player::Get_right() { return this->right; };

void Player::Set_up(bool _a) { this->up = _a; };
void Player::Set_down(bool _a) { this->down = _a; };
void Player::Set_left(bool _a) { this->left = _a; };
void Player::Set_right(bool _a) { this->right = _a; };

void Player::Set_X_Y(int _X, int _Y) {
	this->Y = (_Y - this->Size) - 10;
	this->X = (_X / 2) - this->Size;
}
int Player::Get_Size() { return this->Size; };

float Player::Get_R() { return this->R; };
float Player::Get_G() { return this->G; };
float Player::Get_B() { return this->B; };

int Player::Get_X() { return this->X; };
int Player::Get_Y() { return this->Y; };

void Player::Set_height(int _a) {
	this->height = (int)((_a * sqrt(3)) / 2);
};
int Player::Get_height() { return this->height; };

void Player::Update() {
	if (this->up == true) { this->up = false; this->Y -= this->Move; }
	if (this->down == true) { this->down = false; this->Y += this->Move; }
	if (this->left == true) { this->left = false; this->X -= this->Move; }
	if (this->right == true) { this->right = false; this->X += this->Move; }
}

Player::Player(int _X, int _Y) {
	this->up =
		this->down =
		this->left =
		this->right = false;

	this->Move = 10;
	this->Size = 30;
	this->X = this->Y = 50;
	Set_X_Y(_X, _Y);
	Set_height(this->height);
	this->R =
		this->G =
		this->B = 0;
}