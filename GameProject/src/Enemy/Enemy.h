#pragma once
class Enemy {
public:
	//Set size Enemy
	void SetSize(int _a);

	//Get Size Enemy
	int Get_Size();

	//Set X_Y
	void Set_X_Y(int _x, int _y);

	//Coo. Get
	int Get_X();
	int Get_Y();

	//Move Obj
	void AddOne(bool _a, bool _b);

	//Main fun
	void Draw(Color _color, Color** _ColorBuffer);
	void Update();
	
	// Num of en
	int Get_Amount();
	
	//Get Status
	void Get_Stat();

	// Default Constructor
	Enemy();
	Enemy(int _x, int _y, int w, int h);
	~Enemy() {};
private:
	// Enemy size
	int Size;

	// Coordinates
	int X;
	int Y;

	// Window Size
	int _mWidth;
	int _mHeight;

	// Game
	bool death;

	int speed;
	bool start_point;
	int amount;
	
	// Status border
	bool up;
	bool down;
	bool left;
	bool right;
};