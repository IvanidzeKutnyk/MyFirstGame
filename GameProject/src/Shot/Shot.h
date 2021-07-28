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

	int X_param(int _x, int _y);

	//Ñoordinates
	int Get_X();
	int Get_Y();
	
	//Main function
	void Draw(Color _color, Color** _CollorBuffer);
	void Update();

private:
	//Size
	int hight;
	int weight;

	//Speed
	int speed;
	
	//X_Y
	int X;
	int Y;

	// Size window
	int w_hi;
	int w_we;

};