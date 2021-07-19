#pragma once
class Shooting {
public:
	/// <summary>
	/// Constructor
	/// </summary>
	/// <param name="_a">hight</param>
	/// <param name="_b">weight</param>
	/// <param name="_c">speed</param>
	/// <param name="_d">X</param>
	/// <param name="_e">Y</param>
	Shooting(int _a,int _b, int _c, Player* _player);
	void Draw(Color _color, Color** _CollorBuffer);
	int X_param(int _x, int _y);
	void Update();
	~Shooting();
private:
	//Size
	int hight;
	int weight;
	//Spedd
	int speed;
	//Status 
	bool Stat_Shot;
	//X_Y
	int X;
	int Y;
	// Size window
	int w_hi;
	int w_we;

};