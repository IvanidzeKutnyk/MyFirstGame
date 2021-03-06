#pragma once
#include "GameMath/Color.h"

class Window
{
private:
	class Windows_WindowClass
	{
	public:
		static const wchar_t* getClassName();
		static HINSTANCE getHinstanse();
	private:
		Windows_WindowClass();
		~Windows_WindowClass();
		Windows_WindowClass(const Windows_WindowClass&) = delete;
		Windows_WindowClass& operator=(const Windows_WindowClass&) = delete;
		static constexpr const wchar_t* _windowClassName = L"MainWindowClass";
		static Windows_WindowClass _windowClass;
		HINSTANCE _hInst;
	};
public:
	Window(int width, int height, const wchar_t* title);
	Window() = delete;
	~Window();
	Window(const Window&) = delete;
	Window& operator=(const Window&) = delete;
private:
	static LRESULT CALLBACK HandleMsgSetup(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam);
	static LRESULT CALLBACK HandleMsgThunk(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam);
	LRESULT HandleMsg(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam);
	void DrawWindow(HDC hdc);
	void FillInColor(const Color& color);
public:
	void initGame();
	int start();
public:


private:
	int _mWidth;
	int _mHeight;
	int _MW_P;
	int _MH_P;
	bool _mIsAlive;
	HWND _mHwnd;
	Color** _mColorBuffer;
	COLORREF* _mPixelMap;

	GameWorld gameworld;
};