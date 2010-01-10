#include "AGWindowManager.h"

//------------------------------------------------------------------------------------------------------------------------------
//------------------------------------------------------------------------------------------------------------------------------
LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	return DefWindowProc(hWnd, message, wParam, lParam);
}

//------------------------------------------------------------------------------------------------------------------------------
void AGWindowManager::Initialize()
{
	WNDCLASSEX wcex;

	wcex.cbSize			= sizeof(WNDCLASSEX);
	wcex.style			= CS_CLASSDC;
	wcex.lpfnWndProc	= WndProc;
	wcex.cbClsExtra		= 0;
	wcex.cbWndExtra		= 0;
	wcex.hInstance		= GetModuleHandle(NULL);
	wcex.hIcon			= NULL;
	wcex.hCursor		= NULL;
	wcex.hbrBackground	= NULL;
	wcex.lpszMenuName	= NULL;
	wcex.lpszClassName	= _mName;
	wcex.hIconSm		= NULL;

	RegisterClassEx(&wcex);

	_mWindow = CreateWindow( _mName, _mName, WS_OVERLAPPEDWINDOW, 0, 0, (s32)(_mSize.x), (s32)(_mSize.y), NULL, NULL, wcex.hInstance, NULL );

	ShowWindow( _mWindow, SW_NORMAL);
	UpdateWindow( _mWindow );
}