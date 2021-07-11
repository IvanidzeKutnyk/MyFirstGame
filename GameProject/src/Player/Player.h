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

	int Get_X();
	int Get_Y();

	int Get_height();

	void Set_Movement_False();

	void Set_up(bool _a);
	void Set_down(bool _a);
	void Set_left(bool _a);
	void Set_right(bool _a);
	void Set_X_Y(int _X, int _Y);
	void Set_height(int _x);
	void Set_Move(int _a);


	void Draw(Color color, Color ** _ColorBuffer);
	void Update();
private:
	// Move Status
	bool up;
	bool down;
	bool left;
	bool right;

	// Move Size
	int Move;

	// Size Object
	int Size;
	int height;
	
	// Window Size
	int _mWidth;
	int _mHeight;

	int X;
	int Y;

};
