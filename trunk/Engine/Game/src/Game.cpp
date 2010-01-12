#include "Game.h"
#include "AgSystem.h"
#include "AGResource.h"

#include "AGWindowManager.h"
#include "AGResourceManager.h"
#include "AGRenderer.h"

#include "AGTypesDX9.h"

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
	_mBat.SetMesh(".\\Data\\bat.x");

	AGMaterial* pMaterial = new AGMaterial();
	pMaterial->SetShader();
	_mBat.SetMaterial(pMaterial);

	_mCamera.mFOV = AGDegToRad (45.f);
	_mCamera.mRatio = 1.f;
	_mCamera.mZNear = 1.f;
	_mCamera.mZFar  = 1000.f;

	_mCamera.mPosition = AGVector3f(0.f, 0.f, -10.f);
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
	_mBat.Update();
	_mCamera.Update();

	AGRenderer::GetSingleton()->Render(&_mBat, &_mCamera);
}