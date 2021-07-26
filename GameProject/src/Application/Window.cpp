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
	

	this->_mHwnd = CreateWindowExW(
		0,
		Windows_WindowClass::getClassName(),
		title,
		WS_OVERLAPPEDWINDOW,
		CW_USEDEFAULT,
		CW_USEDEFAULT,
		this->_mWidth,
		this->_mHeight,
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
			gameworld.Set_Key(4);
			break;
		case VK_RIGHT:
			gameworld.Set_Key(3);
			break;
		case VK_UP:
			gameworld.Set_Key(1);
			break;
		case VK_DOWN:
			gameworld.Set_Key(2);
			break;
		case VK_SPACE:
			gameworld.Shot();
			break;
		}
		break;
	case WM_KEYUP:
		switch (wParam)
		{
		case VK_LEFT:
			gameworld.UnSet_Key(4);
			break;
		case VK_RIGHT:
			gameworld.UnSet_Key(3);
			break;
		case VK_UP:
			gameworld.UnSet_Key(1);
			break;
		case VK_DOWN:
			gameworld.UnSet_Key(2);
			break;
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
		gameworld.Draw(_mColorBuffer);
		gameworld.Update();
	
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
		RECT rect;
		GetWindowRect(this->_mHwnd,&rect);
		int width = rect.right - rect.left;
		int hight = rect.bottom - rect.top;
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
	
	//gameworld = new GameWorld();

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