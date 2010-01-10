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

	i = 0;
}

//------------------------------------------------------------------------------------------------------------------------------
void Game::Init()
{
	AGMesh* Bat = NULL;

	Bat = AGResourceManager::GetSingleton()->Load<AGMesh>(".\\Data\\bat.x", "Bat");
/*
	FILE* pFile = NULL;
	fopen_s(&pFile, ".\\Data\\bat.x", "r");

	if (pFile)
		fclose(pFile);
*/
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
	*/

	i++;

	//cout << "Dt = " << AGSystem::GetSingleton()->mTimer.GetDtMs() << "; Time = " << AGSystem::GetSingleton()->mTimer.GetTimeMs() << endl;


	if ( i >= 20000000 )
	{
		//Sleep (10000);
		AGSystem::GetSingleton()->ShutDown();
	}
}
/*
int APIENTRY WinMain (HINSTANCE, HINSTANCE, LPSTR, int)
{
	return 0;
}*/