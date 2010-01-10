#include "AGSystem.h"
#include "AGGame.h"

extern	AGGame* gGame;

//------------------------------------------------------------------------------------------------------------------------------
//------------------------------------------------------------------------------------------------------------------------------
void AGSystem::Initialize( void )
{
	// Attributes
	_mShutDown = false;

	// 
	mTimer.Initialize();

	CRC::Initialize();

	// Default Parameters
	AGWindowManager::GetSingleton()->SetSize(__DefaultWndWidth, __DefaultWndHeight);
	AGWindowManager::GetSingleton()->SetName(__DefaultWndName);

	// Game
	gGame->Init();

	// Managers
	AGWindowManager::GetSingleton()->Initialize();
}

//------------------------------------------------------------------------------------------------------------------------------
void AGSystem::Destroy( void )
{
	gGame->Destroy();
	SAFE_DELETE(gGame);
}

//------------------------------------------------------------------------------------------------------------------------------
//------------------------------------------------------------------------------------------------------------------------------
void AGSystem::MainLoop( void )
{
	while (!_mShutDown)
	{
		mTimer.Update();

		gGame->Update();
	}
}



//------------------------------------------------------------------------------------------------------------------------------
//------------------------------------------------------------------------------------------------------------------------------
int APIENTRY WinMain (HINSTANCE, HINSTANCE, LPSTR, int)
{
	AGSystem::GetSingleton()->Initialize();
	AGSystem::GetSingleton()->MainLoop();
	AGSystem::GetSingleton()->Destroy();

	AGSystem::DestroySingleton();

	return 0;
}
