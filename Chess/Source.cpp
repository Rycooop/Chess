#include "includes.h"


HWND gameHwnd;
int gameX = 150, gameY = 80, gameWidth = 560, gameHeight = 585;

LRESULT CALLBACK WindowProc(HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam);

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR nCmdLine, int nCmdShow)
{
	WNDCLASSEX wc;
	ZeroMemory(&wc, sizeof(WNDCLASSEX));
	wc.cbSize =				sizeof(WNDCLASSEX);
	wc.style =				CS_HREDRAW | CS_VREDRAW;
	wc.hInstance =			hInstance;
	wc.hCursor =			LoadCursor(hInstance, IDC_ARROW);
	wc.hbrBackground =		(HBRUSH)COLOR_WINDOW;
	wc.lpszClassName =		L"ChessClass";
	wc.lpfnWndProc =		WindowProc;
	RegisterClassEx(&wc);

	gameHwnd = CreateWindowEx(NULL, L"ChessClass", L"Chess!", WS_POPUP, gameX, gameY, gameWidth, gameHeight, NULL, NULL, hInstance, NULL);

	ShowWindow(gameHwnd, nCmdShow);
	
	if (!Game::initGame())
		return 0;

	if (!Renderer::initD3D(gameHwnd))
	{
		return 0;
	}

	MSG msg;

	while (true)
	{
		while (PeekMessage(&msg, NULL, 0, 0, PM_REMOVE))
		{
			TranslateMessage(&msg);
			DispatchMessage(&msg);

			if (msg.message == WM_QUIT)
				return 0;
		}
		MoveWindow(gameHwnd, gameX, gameY, 560, 585, true);

		Renderer::renderFrame();
	}

	return 0;
}

LRESULT CALLBACK WindowProc(HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	switch (message)
	{
	case WM_DESTROY:
	{
		PostQuitMessage(0);
		return 0;
	}break;
	}
	return DefWindowProc(hwnd, message, wParam, lParam);
}