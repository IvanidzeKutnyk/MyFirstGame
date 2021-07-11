#pragma once
class ellipse {
	public:
		int Get_R();
		
		int _x;
		int _y;
	
		float r;
		float g;
		float b;

		ellipse();
		void Update(bool _u, bool _d, bool _r, bool l, int _b);
		void Draw(int _x, int _y, Color _color, Color** _ColorBuffer);
		int CheckIfDraw(int _R, int _x, int _y);
private:
		int R;

		bool up;
		bool down;
		bool left;
		bool right;

		int move;
};