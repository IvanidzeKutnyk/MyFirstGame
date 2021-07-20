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

	//Shoot
	void Shot();
	GameWorld();

private:
	//Size
	int _mHeight;
	int _mWidth;
	
	// Shot
	int speed;

	// Enemy
	int num;

	//Color Window
	Color _color;

	//Game objects
	std::vector<Enemy*> enemies;
	Player* player;
	std::vector <Shooting*> shoots;
};