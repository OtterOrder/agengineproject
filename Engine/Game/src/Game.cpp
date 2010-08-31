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
	Material->SetNormal (".\\Data\\Floor_Normal.dds");
	pGraphicEntity->SetMaterial(Material);

	// Columns
	float NbColumns = 10.f;
	float Distance = 240.f;

	for (float i = 0.f; i < NbColumns; ++i)
	{
		pGraphicEntity = _mScene->GetNewGraphicEntity();
		pGraphicEntity->SetMesh(".\\Data\\Column.x");
		Material = new NormalMapMaterial();
		Material->SetDiffuse(".\\Data\\Column_Diff.dds"  );
		Material->SetNormal (".\\Data\\Column_Normal.dds");
		Material->mBumpCoef = 2.f;
		pGraphicEntity->SetMaterial(Material);
		pGraphicEntity->mPosition = AGVector3f( (i - (NbColumns-1.f)/2.f) * Distance , 0.f, -412.f);
	}

	//Light
	AGSpotLight* pSpotLight = _mScene->GetNewSpotLight();
	pSpotLight->mPosition = AGVector3f(0.f, 300.f, 0.f);
	pSpotLight->SetDiffuse (0.7f, 0.7f, 0.7f);
	pSpotLight->SetSpecular(1.0f, 1.0f, 1.0f);
	pSpotLight->mDirection = AGVector3f(0.f, -1.f, 0.f);
	pSpotLight->mInHalfAngle  = AGPi / 4.f;
	pSpotLight->mOutHalfAngle = AGPi / 3.f;

	_mCamera = new AG3DCamera ();
	_mCamera->mFOV = AGDegToRad (45.f);
	_mCamera->mRatio = 1.f;
	_mCamera->mZNear = 1.f;
	_mCamera->mZFar  = 1000.f;

	_mCamera->mPosition = AGVector3f(0.f, 0.f, -10.f);

	_mMouseInputsId = AGInputManager::GetSingleton()->AddInputs(new MouseInputs());

	AGRenderer::GetSingleton()->mCamera.SetProjParams(AGDegToRad(45.f), 1920.f / 1080.f, 10.f, 100000.f);
	D3DXVECTOR3 Eye    (-1193.999756f, 292.999969f, 191.999969f);
	D3DXVECTOR3 LookAt (-1193.118530f, 292.629089f, 191.707870f);
	AGRenderer::GetSingleton()->mCamera.SetViewParams(&Eye, &LookAt);

	_mScene->Get3DCamera()->mPosition  = AGVector3f(-1193.999756f, 292.999969f, 191.999969f);
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
/*
	if (false)
	{
		D3DXVECTOR3* Vector;
		Vector = (D3DXVECTOR3*)(AGRenderer::GetSingleton()->mCamera.GetEyePt());
		AGDebugPrint("Eye     = %f, %f, %f", Vector->x, Vector->y, Vector->z);
		Vector = (D3DXVECTOR3*)(AGRenderer::GetSingleton()->mCamera.GetLookAtPt());
		AGDebugPrint("Look At = %f, %f, %f", Vector->x, Vector->y, Vector->z);
	}
*/
}