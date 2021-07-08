class Player
{
public:
	Player();
	~Player() {};


	bool Get_up();
	bool Get_down();
	bool Get_left();
	bool Get_right();

	void Set_up(bool _a);
	void Set_down(bool _a);
	void Set_left(bool _a);
	void Set_right(bool _a);

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

	int X;
	int Y;
};
