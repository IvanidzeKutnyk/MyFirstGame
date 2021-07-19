#include "pch.h"
#include "Window.h"
#include <chrono>

Window::Windows_WindowClass Window::Windows_WindowClass::_windowClass;

Window::Windows_WindowClass::Windows_WindowClass()
	: _hInst(GetModuleHandle(nullptr))
{
	// create window class struct
	WNDCLASSEXW wc = { 0 };
	wc.cbSize = sizeof(WNDCLASSEXW);
	wc.style = CS_HREDRAW | CS_VREDRAW;
	wc.lpfnWndProc = HandleMsgSetup;
	wc.cbClsExtra = 0;
	wc.cbWndExtra = 0;
	wc.hInstance = this->getHinstanse();
	wc.hIcon = LoadIconW(nullptr, IDC_ARROW);
	wc.hCursor = LoadCursorW(nullptr, IDI_APPLICATION);
	wc.hbrBackground = CreateSolidBrush(RGB(255, 255, 255));
	wc.hIconSm = LoadIconW(nullptr, IDI_APPLICATION);
	wc.lpszClassName = this->getClassName();
	wc.lpszMenuName = L"";
	// register window class struct
	RegisterClassExW(&wc);
}

Window::Windows_WindowClass::~Windows_WindowClass()
{
	UnregisterClassW(this->getClassName(), this->getHinstanse());
}


const wchar_t* Window::Windows_WindowClass::getClassName()
{
	return _windowClass._windowClassName;
}

HINSTANCE Window::Windows_WindowClass::getHinstanse()
{
	return _windowClass._hInst;
}

Window::Window(int width, int height, const wchar_t* title)
	: _mColorBuffer(nullptr)
	, _mPixelMap(nullptr)
	, _mWidth(width)
	, _mHeight(height)
	, _mIsAlive(true)
{
	RECT wr;
	wr.left = 100;
	wr.right = width + wr.left;
	wr.top = 100;
	wr.bottom = height + wr.top;
	AdjustWindowRect(&wr, WS_OVERLAPPEDWINDOW, FALSE);

	this->_mHwnd = CreateWindowExW(
		0,
		Windows_WindowClass::getClassName(),
		title,
		WS_OVERLAPPEDWINDOW,
		CW_USEDEFAULT,
		CW_USEDEFAULT,
		wr.right - wr.left,
		wr.bottom - wr.top,
		nullptr, nullptr,
		Windows_WindowClass::getHinstanse(),
		this);
	ShowWindow(this->_mHwnd, SW_SHOWDEFAULT);

}

Window::~Window()
{
	DestroyWindow(this->_mHwnd);
	if (this->_mColorBuffer)
	{
		for (int i = 0; i < this->_mHeight; i++)
			delete[] this->_mColorBuffer[i];
		delete[] this->_mColorBuffer;
		this->_mColorBuffer = nullptr;
	}
	if (this->_mPixelMap)
	{
		delete[] this->_mPixelMap;
		this->_mPixelMap = nullptr;
	}
}

// First Attempt
#ifdef DEBUG
/*
if (_a == true) {
		FillInColor(Color(1, 1, 1));
		for (int i = 0; i < el.Get_R() * 2; i++)
		{
			for (int j = 0; j < el.Get_R() * 2; j++)
			{
				if (sqrt(pow(el.Get_R() - i, 2) + pow(el.Get_R() - j, 2)) <= el.Get_R()
					|| j == el.Get_R() || i == el.Get_R())
				{
					this->_mColorBuffer[el._y + i][el._x + j].R = el.r;
					this->_mColorBuffer[el._y + i][el._x + j].R = el.g;
					this->_mColorBuffer[el._y + i][el._x + j].R = el.b;
				}
			}

		}
	}
*/
//My CoDE
///Rectangle
void Window::MoveRec(Rectang& _rec) {
	FillInColor(Color(0.1, 0.8, 0.6));
	if (CheckSizeR(_rec, _rec._x, _rec._y, 1024, 500))
	{
		GetLastR(_rec);
	}
	else {

		for (int i = 0; i < _rec.height; i++)
		{
			for (int j = 0; j < _rec.weight; j++)
			{
				this->_mColorBuffer[_rec._y + i][_rec._x + j].R = _rec.R;
				this->_mColorBuffer[_rec._y + i][_rec._x + j].G = _rec.G;
				this->_mColorBuffer[_rec._y + i][_rec._x + j].B = _rec.B;
			}
		}
		_rec._x++;
		_rec._y++;
	}
}
bool Window::CheckSizeR(Rectang& _rec, int _x, int _y, int _w, int _h) {
	if (_y + _rec.height == (_h - 1) || _x + _rec.weight == (_w - 1))
	{
		return true;
	}
	else { return false; }
}
void Window::GetLastR(Rectang& _rec) {
	for (int i = 0; i < _rec.height; i++)
	{
		for (int j = 0; j < _rec.weight; j++)
		{
			this->_mColorBuffer[_rec._y + i][_rec._x + j].R = _rec.R;
			this->_mColorBuffer[_rec._y + i][_rec._x + j].G = _rec.G;
			this->_mColorBuffer[_rec._y + i][_rec._x + j].B = _rec.B;
		}
	}
};
///Triangle
////Equilateral
void Window::MoveTr_e(Triang& _tr) {
	_tr.Set_height(_tr.Get_iA());
	FillInColor(Color(0.1, 0.8, 0.6));
	if (CheckSizeT(_tr, _tr.Get_x(), _tr.Get_y(), 1024, 500))
	{
		GetLastT(_tr);
	}
	else {
		//Left_Side
		float _temp1 = _tr.Get_iA() / 2;
		for (int i = 0; i < _tr.Get_height(); i++)
		{
			if (_temp1 == 0)
			{
				break;
			}
			for (int j = _tr.Get_iA() / 2; j > _temp1; j--)
			{
				this->_mColorBuffer[_tr.Get_y() + i][_tr.Get_x() + j].R = _tr.Get_R();
				this->_mColorBuffer[_tr.Get_y() + i][_tr.Get_x() + j].G = _tr.Get_G();
				this->_mColorBuffer[_tr.Get_y() + i][_tr.Get_x() + j].B = _tr.Get_B();
			}
			_temp1--;
		}
#	//Right_Side
		float _temp = _tr.Get_iA() / 2;
		for (int i = 0; i < _tr.Get_height(); i++)
		{
			if (_temp == _tr.Get_iA())
			{
				break;
			}
			for (int j = _tr.Get_iA() / 2; j < _temp; j++)
			{
				this->_mColorBuffer[_tr.Get_y() + i][_tr.Get_x() + j].R = _tr.Get_R();
				this->_mColorBuffer[_tr.Get_y() + i][_tr.Get_x() + j].G = _tr.Get_G();
				this->_mColorBuffer[_tr.Get_y() + i][_tr.Get_x() + j].B = _tr.Get_B();
			}
			_temp++;
		}
		_tr.Plus_X();
		_tr.Plus_Y();

	}
};
bool Window::CheckSizeT(Triang& _tr, int _x, int _y, int _w, int _h) {
	if (_y + _tr.Get_iA() == (_h - 1) || _x + _tr.Get_height() == (_w - 1))
	{
		return true;
	}
	else {
		return false;
	}


}
void Window::GetLastT(Triang& _tr) {
	//Left_Side
	float _temp1 = _tr.Get_iA() / 2;
	for (int i = 0; i < _tr.Get_height(); i++)
	{
		if (_temp1 == 0)
		{
			break;
		}
		for (int j = _tr.Get_iA() / 2; j > _temp1; j--)
		{
			this->_mColorBuffer[_tr.Get_y() + i][_tr.Get_x() + j].R = _tr.Get_R();
			this->_mColorBuffer[_tr.Get_y() + i][_tr.Get_x() + j].G = _tr.Get_G();
			this->_mColorBuffer[_tr.Get_y() + i][_tr.Get_x() + j].B = _tr.Get_B();
		}
		_temp1--;
	}
#	//Right_Side
	float _temp = _tr.Get_iA() / 2;
	for (int i = 0; i < _tr.Get_height(); i++)
	{
		if (_temp == _tr.Get_iA())
		{
			break;
		}
		for (int j = _tr.Get_iA() / 2; j < _temp; j++)
		{
			this->_mColorBuffer[_tr.Get_y() + i][_tr.Get_x() + j].R = _tr.Get_R();
			this->_mColorBuffer[_tr.Get_y() + i][_tr.Get_x() + j].G = _tr.Get_G();
			this->_mColorBuffer[_tr.Get_y() + i][_tr.Get_x() + j].B = _tr.Get_B();
		}
		_temp++;
	}
};

#endif // DEBUG

void Window::Draw()
{
	FillInColor(Color(1, 1, 1));
	this->player->Draw(Color(0, 0, 0), _mColorBuffer);
	for (int i = 0; i < 3; i++)
		this->enemies[i]->Draw(Color(0, 0, 0), _mColorBuffer);

	for (int i = 0; i < this->shoots.size(); i++)
	{
		this->shoots[i]->Draw(Color(0.5,0.7,0.2), _mColorBuffer);
	}
}

void Window::Update()
{
	this->player->Update();
	for (int i = 0; i < 3; i++)
		this->enemies[i]->Update();
	for (int i = 0; i < this->shoots.size(); i++)
	{
		this->shoots[i]->Update();
	}
}

//End My CoDE
int Window::start()
{
	MSG msg;
	// message loop
	while (GetMessageW(&msg, this->_mHwnd, 0, 0) > 0)
	{
		TranslateMessage(&msg);
		DispatchMessageW(&msg);
	}

	return 0;
}

LRESULT CALLBACK Window::HandleMsgSetup(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
	if (msg == WM_NCCREATE)
	{
		const CREATESTRUCTW* const pCreate = reinterpret_cast<CREATESTRUCTW*>(lParam);
		Window* const pWnd = static_cast<Window*>(pCreate->lpCreateParams);
		SetWindowLongPtrW(hWnd, GWLP_USERDATA, reinterpret_cast<LONG_PTR>(pWnd));
		SetWindowLongPtrW(hWnd, GWLP_WNDPROC, reinterpret_cast<LONG_PTR>(&Window::HandleMsgThunk));
		return pWnd->HandleMsg(hWnd, msg, wParam, lParam);
	}
	return DefWindowProcW(hWnd, msg, wParam, lParam);
}

LRESULT CALLBACK Window::HandleMsgThunk(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
	Window* const pWnd = reinterpret_cast<Window*>(GetWindowLongPtrW(hWnd, GWLP_USERDATA));
	return pWnd->HandleMsg(hWnd, msg, wParam, lParam);
}

LRESULT Window::HandleMsg(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
	switch (msg)
	{

	case WM_CREATE:
		SetTimer(hWnd, 1, 20, NULL);
		break;
	case WM_KEYDOWN:
		switch (wParam)
		{
				case VK_LEFT:
				{
					this->player->Set_left(true);
					break;
				}
				case VK_RIGHT:
				{
					this->player->Set_right(true);
					break;
				}
				case VK_UP:
				{
					this->player->Set_up(true);
					break;
				}
				case VK_DOWN:
				{
					this->player->Set_down(true);
					break;
				}
				case VK_TAB:
				{
					this->shoots.push_back(new Shooting(10,5,5, player));
					break;
				}

		}

		break;
	case WM_TIMER:
		InvalidateRect(hWnd, NULL, FALSE);
		break;
	case WM_PAINT:
	{
		PAINTSTRUCT ps;
		HDC hdc = BeginPaint(hWnd, &ps);
		//CODE

		Update();
		Draw();

		//CODE
		this->DrawWindow(hdc);
		EndPaint(hWnd, &ps);
		break;
	}
	case WM_GETMINMAXINFO:
		((MINMAXINFO*)lParam)->ptMinTrackSize.x = this->_mWidth;
		((MINMAXINFO*)lParam)->ptMinTrackSize.y = this->_mHeight;
		((MINMAXINFO*)lParam)->ptMaxTrackSize.x = this->_mWidth;
		((MINMAXINFO*)lParam)->ptMaxTrackSize.y = this->_mHeight;
		((MINMAXINFO*)lParam)->ptMaxSize.x = this->_mWidth;
		((MINMAXINFO*)lParam)->ptMaxSize.y = this->_mHeight;
		break;
	case WM_CLOSE:
		PostQuitMessage(0);
		break;
	}
	return DefWindowProcW(hWnd, msg, wParam, lParam);
}

void Window::initGame()
{
	this->_mColorBuffer = new Color * [this->_mHeight];
	for (int i = 0; i < this->_mHeight; i++)
		this->_mColorBuffer[i] = new Color[this->_mWidth];

	this->_mPixelMap = new COLORREF[this->_mWidth * this->_mHeight];
	
	//Create Enemy
	for (int i = 0; i < 3; i++)
		this->enemies.push_back(new Enemy(i * 300,i * 100, 1024, 500));
	//Create Player
	this->player = new Player(1024, 500);

	this->FillInColor(Color(0.8, 0.4, 0.2));
}

void Window::DrawWindow(HDC hdc)
{
	unsigned int texel = 0;
	for (int i = 0; i < this->_mHeight; i++)
	{
		for (int j = 0; j < this->_mWidth; j++)
		{
			this->_mPixelMap[texel++] = RGB(
				this->_mColorBuffer[i][j].B * 255.0f,
				this->_mColorBuffer[i][j].G * 255.0f,
				this->_mColorBuffer[i][j].R * 255.0f
			);
		}
	}

	HBITMAP hBitmap = CreateBitmap(this->_mWidth, this->_mHeight, 1, 32, this->_mPixelMap);
	HDC hLocalDC = CreateCompatibleDC(hdc);
	HBITMAP hOldBmp = (HBITMAP)SelectObject(hLocalDC, hBitmap);
	BitBlt(hdc, 0, 0, this->_mWidth, this->_mHeight, hLocalDC, 0, 0, SRCCOPY);
	SelectObject(hLocalDC, hOldBmp);
	DeleteDC(hLocalDC);
	DeleteObject(hBitmap);
}

void Window::FillInColor(const Color& color)
{
	for (int i = 0; i < this->_mHeight; i++)
	{
		for (int j = 0; j < this->_mWidth; j++)
		{
			this->_mColorBuffer[i][j] = color;
		}
	}
}