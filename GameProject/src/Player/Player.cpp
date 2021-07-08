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

void Player::Update() {
	if (this->up == true) { this->up = false; this->Y -= this->Move; }
	if (this->down == true) { this->down = false; this->Y += this->Move; }
	if (this->left == true) { this->left = false; this->X += this->Move; }
	if (this->right == true) { this->right = false; this->X -= this->Move; }
}

Player::Player() {
	this->up =
		this->down =
		this->left =
		this->right = false;

	this->Move = 10;
	this->Size = 30;
	this->X = this->Y = 50;

}