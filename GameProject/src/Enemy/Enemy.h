#pragma once
class Enemy {
public:
	void SetSize(int _a);
	int Get_Size();

	void Set_X_Y(int _x, int _y);
	int Get_X();
	int Get_Y();
	void AddOne(bool _a, bool _b);


	void Draw(Color _color, Color** _ColorBuffer);
	void Update();
	int Get_Amount();
	void Get_Stat();

	void Set_Stat_D();
	bool Get_Stat_D();
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