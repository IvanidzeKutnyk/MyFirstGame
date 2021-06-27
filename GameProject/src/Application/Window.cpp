#include "pch.h"
#include "Window.h"
#include <chrono>


Rectang rec;

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

//My CoDE
///Rectangle
void Window::MoveRec(Rectang& _rec) {
	FillInColor(Color(0.1, 0.8, 0.6));
	if (CheckSize(_rec, _rec._x, _rec._y, 1024, 500))
	{
		GetLast(_rec);
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
bool Window::CheckSize(Rectang& _rec, int _x, int _y, int _w, int _h) {
	if (_y + _rec.height == (_h - 1) || _x + _rec.weight == (_w - 1))
	{
		return true;
	}
	else { return false; }
}
void Window::GetLast(Rectang& _rec) {
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

	case WM_TIMER:
		InvalidateRect(hWnd, NULL, FALSE);
		break;

	case WM_PAINT:
	{
		PAINTSTRUCT ps;
		HDC hdc = BeginPaint(hWnd, &ps);

		//CODE
		MoveRec(rec);
		//CODE
			// don`t touch THIS!!!
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
	// creatign new bitmap with size of screen
	HBITMAP hBitmap = CreateBitmap(this->_mWidth, this->_mHeight, 1, 32, this->_mPixelMap);

	// creating local DC( in GDI+ it's called 'Graphics' )
	HDC hLocalDC = CreateCompatibleDC(hdc);

	// selecting our bitmap in GDI+'s Graphics
	HBITMAP hOldBmp = (HBITMAP)SelectObject(hLocalDC, hBitmap);

	// copy from localDC( Graphics ) to our window one
	BitBlt(hdc, 0, 0, this->_mWidth, this->_mHeight, hLocalDC, 0, 0, SRCCOPY);

	// selecting literaly nothing( or system's value )
	// to aviod memory linked resources( can be kind of leak )
	SelectObject(hLocalDC, hOldBmp);

	// dropping localDC(Grapchics )
	DeleteDC(hLocalDC);

	// dropping bitmap
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