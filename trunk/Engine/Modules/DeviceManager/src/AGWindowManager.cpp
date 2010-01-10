#include "AGWindowManager.h"

//------------------------------------------------------------------------------------------------------------------------------
//------------------------------------------------------------------------------------------------------------------------------
AGWindowManager::~AGWindowManager()
{
	UnregisterClass(_mName, _mWndClassEx.hInstance);
}

//------------------------------------------------------------------------------------------------------------------------------
//------------------------------------------------------------------------------------------------------------------------------
LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	return DefWindowProc(hWnd, message, wParam, lParam);
}

//------------------------------------------------------------------------------------------------------------------------------
void AGWindowManager::Initialize()
{
	_mWndClassEx.cbSize			= sizeof(WNDCLASSEX);
	_mWndClassEx.style			= CS_CLASSDC;
	_mWndClassEx.lpfnWndProc	= WndProc;
	_mWndClassEx.cbClsExtra		= 0;
	_mWndClassEx.cbWndExtra		= 0;
	_mWndClassEx.hInstance		= GetModuleHandle(NULL);
	_mWndClassEx.hIcon			= NULL;
	_mWndClassEx.hCursor		= NULL;
	_mWndClassEx.hbrBackground	= NULL;
	_mWndClassEx.lpszMenuName	= NULL;
	_mWndClassEx.lpszClassName	= _mName;
	_mWndClassEx.hIconSm		= NULL;

	RegisterClassEx(&_mWndClassEx);

	_mWindow = CreateWindow( _mName, _mName, WS_OVERLAPPEDWINDOW, 0, 0, (s32)(_mSize.x), (s32)(_mSize.y), NULL, NULL, _mWndClassEx.hInstance, NULL );

	ShowWindow( _mWindow, SW_NORMAL);
	UpdateWindow( _mWindow );
}