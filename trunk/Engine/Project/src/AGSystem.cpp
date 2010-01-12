#include "AGSystem.h"
#include "AGGame.h"

#include "AGDeviceManager.h"

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
	gGame->InitEngine();

	// Managers
	AGWindowManager::GetSingleton()->Initialize();
	AGDeviceManager::GetSingleton()->Initialize();


	gGame->Init();
}

//------------------------------------------------------------------------------------------------------------------------------
void AGSystem::Destroy( void )
{
	gGame->Destroy();
	SAFE_DELETE(gGame);

	AGDeviceManager::DestroySingleton();
	AGWindowManager::DestroySingleton();
}

//------------------------------------------------------------------------------------------------------------------------------
void AGSystem::MainLoop( void )
{
	while (!_mShutDown)
	{
		mTimer.Update();
		AGWindowManager::GetSingleton()->Update();

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
