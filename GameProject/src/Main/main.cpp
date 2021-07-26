#include "pch.h"
#include "Application/Window.h"

int CALLBACK WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR pCmdLine, int pCmdMode)
{
	Window gameWindow(1024+15, 500+40, L"Game Application");
	gameWindow.initGame();
	return gameWindow.start();
}
