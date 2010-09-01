#include "AGWindowManager.h"

#include "AgSystem.h"

#include "AGDebugCamera.h"	////.
#include "AGRenderer.h"		////.

//------------------------------------------------------------------------------------------------------------------------------
//------------------------------------------------------------------------------------------------------------------------------
AGWindowManager::~AGWindowManager()
{
	PostQuitMessage( 0 );
	DestroyWindow(_mWindow);

	UnregisterClass(_mName, _mWndClassEx.hInstance);
}

//------------------------------------------------------------------------------------------------------------------------------
//------------------------------------------------------------------------------------------------------------------------------
LRESULT CALLBACK WndProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
	switch( msg )
	{
		case WM_DESTROY:
			AGSystem::GetSingleton()->ShutDown();
			return 0;

		case WM_KEYDOWN:
		{
			switch( wParam )
			{
				case VK_ESCAPE:
				{
					AGSystem::GetSingleton()->ShutDown();
					return 0;
				}
			}
		}
	}

	AGRenderer::GetSingleton()->mCamera.HandleMessages(hWnd, msg, wParam, lParam);	////.

	return DefWindowProc(hWnd, msg, wParam, lParam);
}

//------------------------------------------------------------------------------------------------------------------------------
void AGWindowManager::Initialize()
{
	ZeroMemory( &_mMsg, sizeof(_mMsg) );

	_mWndClassEx.cbSize			= sizeof(WNDCLASSEX);
	_mWndClassEx.style			= CS_CLASSDC;
	_mWndClassEx.lpfnWndProc	= WndProc;
	_mWndClassEx.cbClsExtra		= 0;
	_mWndClassEx.cbWndExtra		= 0;
	_mWndClassEx.hInstance		= GetModuleHandle(NULL);
	_mWndClassEx.hIcon			= NULL;
	_mWndClassEx.hCursor		= LoadCursor( NULL, IDC_ARROW );
	_mWndClassEx.hbrBackground	= NULL;
	_mWndClassEx.lpszMenuName	= NULL;
	_mWndClassEx.lpszClassName	= _mName;
	_mWndClassEx.hIconSm		= NULL;

	RegisterClassEx(&_mWndClassEx);

	_mWindow = CreateWindow( _mName, _mName, WS_OVERLAPPEDWINDOW, 0, 0, (s32)(_mSize.x), (s32)(_mSize.y), NULL, NULL, _mWndClassEx.hInstance, NULL );

	ShowWindow( _mWindow, SW_NORMAL);
	UpdateWindow( _mWindow );
}

//------------------------------------------------------------------------------------------------------------------------------
void AGWindowManager::Update()
{
	if ( PeekMessage(&_mMsg, NULL, 0U, 0U, PM_REMOVE) )
	{
		TranslateMessage( &_mMsg );
		DispatchMessage( &_mMsg );
	}

	if (_mMsg.message == WM_QUIT)
		AGSystem::GetSingleton()->ShutDown();
}