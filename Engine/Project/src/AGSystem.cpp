#include "AGSystem.h"
#include "AGGame.h"

#include "AGDeviceManager.h"
#include "AGInputManager.h"
#include "AGSceneManager.h"
#include "AGShadowManager.h"
#include "AGPostProcess.h"

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
	AGShadowManager::GetSingleton()->Initialize();
	AGPostProcess::Initialize();

	gGame->Init();
}

//------------------------------------------------------------------------------------------------------------------------------
void AGSystem::Destroy( void )
{
	gGame->Destroy();
	SAFE_DELETE(gGame);

	AGInputManager::DestroySingleton	();
	AGPostProcess::Destroy				();
	AGShadowManager::DestroySingleton	();
	AGSceneManager::DestroySingleton	();
	AGDeviceManager::DestroySingleton	();
	AGWindowManager::DestroySingleton	();
}

//------------------------------------------------------------------------------------------------------------------------------
void AGSystem::MainLoop( void )
{
	while (!_mShutDown)
	{
		mTimer.Update();
		AGWindowManager::GetSingleton()->Update();
		AGInputManager::GetSingleton()->Update();

		gGame->Update();

		AGSceneManager::GetSingleton()->Update();

		AGShadowManager::GetSingleton()->Update();

		AGSceneManager::GetSingleton()->Draw();
	}
}



//------------------------------------------------------------------------------------------------------------------------------
//------------------------------------------------------------------------------------------------------------------------------
int APIENTRY WinMain (HINSTANCE, HINSTANCE, LPSTR, int)
{
	AGSystem::GetSingleton()->Initialize();
	AGSystem::GetSingleton()->MainLoop();
	AGSystem::DestroySingleton();

	return 0;
}
