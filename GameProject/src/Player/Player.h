class Player
{
public:
	Player(int _X, int _Y);
	~Player() {};


	bool Get_up();
	bool Get_down();
	bool Get_left();
	bool Get_right();

	int Get_Size();

	float Get_R();
	float Get_G();
	float Get_B();

	int Get_X();
	int Get_Y();

	int Get_height();

	void Set_up(bool _a);
	void Set_down(bool _a);
	void Set_left(bool _a);
	void Set_right(bool _a);
	void Set_X_Y(int _X, int _Y);
	void Set_height(int _x);



	void Update();
private:
	// Move Status
	bool up;
	bool down;
	bool left;
	bool right;

	// Move Size
	int Move;

	// Size 
	int Size;
	int height;

	int X;
	int Y;

	//RGB
	float R, G, B;
};
