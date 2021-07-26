#pragma once
class GameWorld {
public:
	//Main method
	void Draw(Color** _colorBuffer);
	void Update();

	//Fill Color
	void FillColor(Color _color, Color** _colorBuffer);
	
	//Shoots_key_logic
	void Set_Key(int _a);
	void UnSet_Key(int _b);

	//Shoot
	void Shot();

	//Rand COo

	int Rand_X();
	int Rand_Y();

	GameWorld();

private:
	//Size
	int _mHeight;
	int _mWidth;
	
	// Shot
	int speed;

	// Enemy
	int num;
	int max;

	// Player
	int speed_p;

	//Color Window
	Color _color;

	//Game objects
	std::vector<Enemy*> enemies;
	Player* player;
	std::vector <Shooting> shoots;
};