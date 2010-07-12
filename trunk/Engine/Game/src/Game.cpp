#include "Game.h"
#include "AgSystem.h"
#include "AGResource.h"

#include "AGWindowManager.h"
#include "AGResourceManager.h"
#include "AGInputManager.h"
#include "AGRenderer.h"

#include "AGTypesDX9.h"

#include <iostream>
using namespace std;

#include "MouseInputs.h"

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
	_mBat = new AG3DGraphicEntity();

	_mBat->SetMesh(".\\Data\\bat.x");

	AGMaterial* pMaterial = new AGMaterial();
	pMaterial->SetShader();
	_mBat->SetMaterial(pMaterial);


	_mCamera = new AG3DCamera ();
	_mCamera->mFOV = AGDegToRad (45.f);
	_mCamera->mRatio = 1.f;
	_mCamera->mZNear = 1.f;
	_mCamera->mZFar  = 1000.f;

	_mCamera->mPosition = AGVector3f(0.f, 0.f, -10.f);

	_mMouseInputsId = AGInputManager::GetSingleton()->AddInputs(new MouseInputs());
}

//------------------------------------------------------------------------------------------------------------------------------
void Game::Destroy()
{
	cout << "Game Destroy" << endl;

	SAFE_DELETE(_mBat);
	SAFE_DELETE(_mCamera);
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
//*/

	AGVector2s lMousePosition = MouseInputs::Get(_mMouseInputsId)->GetPosition();
	AGDebugPrint("Mouse position : %i; %i", lMousePosition.x, lMousePosition.y);

	_mBat->Update();
	//_mCamera->Update();

	AGRenderer::GetSingleton()->Render(_mBat, _mCamera, NULL);
}