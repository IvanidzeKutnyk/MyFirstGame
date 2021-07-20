#include "pch.h"
#include "GameWorld.h"

void GameWorld::FillColor(Color _color, Color** _colorBuffer) 
{
	for (int i = 0; i < this->_mHeight; i++)
	{
		for (int j = 0; j < this->_mWidth; j++)
		{
			_colorBuffer[i][j] = _color;
		}
	}
}
/// <summary>
/// 1 = up
/// 2 = down
/// 3 = right
/// 4 = left
/// </summary>
/// <param name="_a">Stat</param>
void GameWorld::Set_Key(int _a) {
	
	switch (_a)
	{
	case 1: {
		player->Set_up(true);
		break;
	}
	case 2: {
		player->Set_down(true);
		break; 
	}
	case 3: {
		player->Set_right(true);
		break;
	}
	case 4: {
		player->Set_left(true);
		break;
	}
	}
}
void GameWorld::Draw(Color** _colorBuffer)
{
	//Fill Color
	FillColor(_color, _colorBuffer);

	//Draw Player
	this->player->Draw(Color(0, 0, 0), _colorBuffer);

	//Draw enemies
	for (int i = 0; i < this->num; i++)
	{
		this->enemies[i]->Draw(Color(0, 0, 0), _colorBuffer);
	}
	//Draw shoots
	for (int i = 0; i < this->shoots.size(); i++)
	{
		this->shoots[i]->Draw(Color(0.5, 0.7, 0.2), _colorBuffer);
	}

}
void GameWorld::Shot() 
{
	this->shoots.push_back(new Shooting(10, 5, 5, player));
}
void GameWorld::Update()
{
	//Update Player
	this->player->Update();

	//Update Enemies
	for (int i = 0; i < this->num; i++)
	{
		this->enemies[i]->Update();
	}
	//Update Shoots
	for (int i = 0; i < this->shoots.size(); i++)
	{
		this->shoots[i]->Update();
	}
	//Delete shoot objects
	for (auto itr = shoots.begin(); itr != shoots.end(); ++itr)
	{
			shoots.erase(itr);
	}
}


GameWorld::GameWorld()
{
	//Size
	this->_mHeight = 500;
	this->_mWidth = 1024;

	//Number of enemies
	this->num = 5;
	//Speed
	this->speed = 5;

	//Color
	this->_color = Color(0.3, 0.9, 0.1);

	//Create Enemy
	for (int i = 0; i < this->num; i++)
	{
		this->enemies.push_back(new Enemy(i * 200, i * 100, _mWidth, _mHeight));//1024;500
	}

	//Create Player
	this->player = new Player(_mWidth, _mHeight);//1024;500

}