class Player
{
public:
	Player(int _X, int _Y);
	~Player() {};

	// Get player size 
	int Get_Size();

	//Get Coo. player
	int Get_X();
	int Get_Y();

	// Get height (not USe)
	int Get_height();

	//Set all move param to false
	void Set_Movement_False();

	//Get Main Window Param
	int Get_W_H();
	int Get_W_W();


	//Set Status move param
	void Set_up(bool _a);
	void Set_down(bool _a);
	void Set_left(bool _a);
	void Set_right(bool _a);

	//Set Start Coo. when game start
	void Set_X_Y(int _X, int _Y);

	//Height(Not USe)
	void Set_height(int _x);

	//Speed player
	void Set_Move(int _a);

	//Main Function
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
