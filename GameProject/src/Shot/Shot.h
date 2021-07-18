#pragma once
class Shooting {
public:
	/// <summary>
	/// Constructor
	/// </summary>
	/// <param name="_a">size</param>
	/// <param name="_b">speed</param>
	Shooting(int _a,int _b);

	~Shooting();
private:
	int size;
	int speed;
	bool Stat_Shot;
};