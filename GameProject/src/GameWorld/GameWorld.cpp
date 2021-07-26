#include "pch.h"
#include "GameWorld.h"
char buff[100];
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
void GameWorld::UnSet_Key(int _a) {

	switch (_a)
	{
	case 1: {
		player->Set_up(false);
		break;
	}
	case 2: {
		player->Set_down(false);
		break;
	}
	case 3: {
		player->Set_right(false);
		break;
	}
	case 4: {
		player->Set_left(false);
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
		this->shoots[i].Draw(Color(1, 1, 1), _colorBuffer);
	}

}
void GameWorld::Shot() 
{
	this->shoots.push_back(Shooting(10, 5, 5, player));
}
int GameWorld::Rand_X() 
{
	int X = 1 + rand() % this->_mWidth;
	if (X < enemies[1]->Get_Size())
		X += enemies[1]->Get_Size();
	if (X > this->_mWidth - enemies[1]->Get_Size())
		X -= enemies[1]->Get_Size();

	return X;
}
int GameWorld::Rand_Y()
{
	int Y = 1 + rand() % this->_mHeight;
	if (Y < enemies[1]->Get_Size())
		Y += enemies[1]->Get_Size();
	if (Y > this->_mHeight - enemies[1]->Get_Size())
		Y -= enemies[1]->Get_Size();

	return Y;
}
void GameWorld::Update()
{
	//Check amount of enemies
	if (this->num <= 3)
	{
		this->enemies.push_back(new Enemy(Rand_X(), Rand_Y(), _mWidth, _mHeight));//1024;500

		this->num += 1;
	}
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
		this->shoots[i].Update();
	}
	//Delete shoot objects
	for(int i = 0; i < shoots.size(); i++)
	{
		if (this->shoots[i].Get_Y() < 10)
		{
			//snprintf(buff, sizeof(buff), " Vector: %d", shoots.size());
			//OutputDebugStringA(buff);

			shoots.erase(shoots.begin() + i);
			i--;
		}
	}
	//Delete shoot with enemy objects
	for (int i = 0; i < enemies.size(); i++)
	{
		
		for (int j = 0; j < shoots.size(); j++)
		{
			if (shoots[j].Get_X() > enemies[i]->Get_X() 
				&& shoots[j].Get_X() < enemies[i]->Get_X() + enemies[i]->Get_Size()
				&& shoots[j].Get_Y() < enemies[i]->Get_Y() + enemies[i]->Get_Size())
			{
				//snprintf(buff, sizeof(buff), "Enemy %d \n",a);
				//OutputDebugStringA(buff);

				shoots.erase(shoots.begin() + j);
				enemies.erase(enemies.begin() + i);
				this->num -= 1;
				i = 0;
				j = 0;
			}
		}
	}


}
GameWorld::GameWorld()
{
	//Size
	this->_mHeight = 500;
	this->_mWidth = 1024;

	//Number of enemies
	this->num = 5;
	this->max = 5;
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