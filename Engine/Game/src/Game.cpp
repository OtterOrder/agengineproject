#include "Game.h"
#include "AgSystem.h"
#include "AGResource.h"

#include "AGWindowManager.h"
#include "AGResourceManager.h"
#include "AGInputManager.h"
#include "AGSceneManager.h"
#include "AGRenderer.h"
#include "AG3DDefaultMaterial.h"

#include "NormalMapMaterial.h"

#include "AGTypesDX9.h"

#include <iostream>
using namespace std;

#include "MouseInputs.h"

//------------------------------------------------------------------------------------------------------------------------------
//------------------------------------------------------------------------------------------------------------------------------
void Game::InitEngine()
{
	cout << "Game Init Engine" << endl;

	AGWindowManager::GetSingleton()->SetSize(1920, 1080);
}

//------------------------------------------------------------------------------------------------------------------------------
void Game::Init()
{
	_mScene = AGSceneManager::GetSingleton()->GetNew3DScene();

	NormalMapMaterial* Material;
	AG3DGraphicEntity* pGraphicEntity;

	// Floor
	pGraphicEntity = _mScene->GetNewGraphicEntity();
	pGraphicEntity->SetMesh(".\\Data\\Floor.x");
	Material = new NormalMapMaterial();
	Material->SetDiffuse(".\\Data\\Floor_Diff.dds");
	pGraphicEntity->SetMaterial(Material);

	// Columns
	float NbColumns = 10.f;
	float Distance = 240.f;

	for (float i = 0.f; i < NbColumns; ++i)
	{
		pGraphicEntity = _mScene->GetNewGraphicEntity();
		pGraphicEntity->SetMesh(".\\Data\\Column.x");
		Material = new NormalMapMaterial();
		Material->SetDiffuse(".\\Data\\Column_Diff.dds");
		pGraphicEntity->SetMaterial(Material);
		pGraphicEntity->mPosition = AGVector3f( (i - (NbColumns-1.f)/2.f) * Distance , 0.f, -412.f);
	}
	

	_mCamera = new AG3DCamera ();
	_mCamera->mFOV = AGDegToRad (45.f);
	_mCamera->mRatio = 1.f;
	_mCamera->mZNear = 1.f;
	_mCamera->mZFar  = 1000.f;

	_mCamera->mPosition = AGVector3f(0.f, 0.f, -10.f);

	_mMouseInputsId = AGInputManager::GetSingleton()->AddInputs(new MouseInputs());

	AGRenderer::GetSingleton()->mCamera.SetProjParams(AGDegToRad(45.f), 1920.f / 1080.f, 10.f, 100000.f);
}

//------------------------------------------------------------------------------------------------------------------------------
void Game::Destroy()
{
	cout << "Game Destroy" << endl;

	SAFE_DELETE(_mCamera);
}

//------------------------------------------------------------------------------------------------------------------------------
void Game::Update()
{
	AGVector2s lMousePosition = MouseInputs::Get(_mMouseInputsId)->GetPosition();
	//AGDebugPrint("Mouse position : %i; %i", lMousePosition.x, lMousePosition.y);

	//_mBat->mPosition.x += 0.005f;
}