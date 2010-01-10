#include "Game.h"
#include "AgSystem.h"
#include "AGResource.h"

#include "AGWindowManager.h"
#include "AGResourceManager.h"

#include "AGMesh.h"

#include <iostream>
using namespace std;

#include <Windows.h>

//------------------------------------------------------------------------------------------------------------------------------
//------------------------------------------------------------------------------------------------------------------------------
void Game::InitEngine()
{
	cout << "Game Init Engine" << endl;

	AGWindowManager::GetSingleton()->SetSize(1024, 512);
}

//------------------------------------------------------------------------------------------------------------------------------
void Game::Init()
{
	AGMesh* Bat = NULL;

	Bat = AGResourceManager::GetSingleton()->Load<AGMesh>(".\\Data\\bat.x", "Bat");

	Bat->DecRefCount();
}

//------------------------------------------------------------------------------------------------------------------------------
void Game::Destroy()
{
	cout << "Game Destroy" << endl;
}

//------------------------------------------------------------------------------------------------------------------------------
void Game::Update()
{
/*
	cout << "Game Update" << endl;
	
	AGResource* pRes = new AGResource();

	u32 RefCount;

	pRes->IncRefCount();
	pRes->IncRefCount();
	RefCount = pRes->DecRefCount();
	RefCount = pRes->DecRefCount();
	

	cout << CRC::GetCRC("Toto") << endl;
	cout << CRC::GetCRC("Fifou")<< endl;

	//cout << "Dt = " << AGSystem::GetSingleton()->mTimer.GetDtMs() << "; Time = " << AGSystem::GetSingleton()->mTimer.GetTimeMs() << endl;
*/
	if ( AGSystem::GetSingleton()->mTimer.GetDtMs() > 2000 )
		AGSystem::GetSingleton()->ShutDown();
}