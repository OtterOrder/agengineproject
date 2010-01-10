#include "AGWindowManager.h"

//------------------------------------------------------------------------------------------------------------------------------
void AGWindowManager::Initialize()
{
	WNDCLASSEX WindowClass = { sizeof(WNDCLASSEX), CS_CLASSDC, NULL/*MsgProc*/, 0L, 0L, GetModuleHandle(NULL), NULL, NULL, NULL, NULL, _mName, NULL };	// ToDo : Set MsgProc to InputManager
	RegisterClassEx( &WindowClass );

	_mWindow = CreateWindow( _mName, _mName, WS_OVERLAPPED, 0, 0, _mSize.x, _mSize.y, NULL, NULL, WindowClass.hInstance, NULL );

	ShowWindow( _mWindow, SW_NORMAL );
	UpdateWindow( _mWindow );
}