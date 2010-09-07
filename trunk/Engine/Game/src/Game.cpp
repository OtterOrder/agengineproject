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

////.
#include "NormalMapZMaterial.h"
#include "NormalMapShadowMaterial.h"
////.

#include "AGShadowManager.h"

#include "AGTypesDX9.h"

#include <iostream>
using namespace std;

#include "MouseInputs.h"

//------------------------------------------------------------------------------------------------------------------------------
//------------------------------------------------------------------------------------------------------------------------------
void Game::InitEngine()
{
	cout << "Game Init Engine" << endl;

	AGWindowManager::GetSingleton()->SetSize(1920, 1000);
}

//------------------------------------------------------------------------------------------------------------------------------
void Game::Init()
{
	_mScene = AGSceneManager::GetSingleton()->GetNew3DScene();

	NormalMapMaterial*			pMaterial;
	NormalMapZMaterial*			pZMaterial;
	NormalMapShadowMaterial*	pShadowMaterial;
	AG3DGraphicEntity*			pGraphicEntity;

	
	// Floor
	pGraphicEntity = _mScene->GetNewGraphicEntity();
	pGraphicEntity->SetMesh(".\\Data\\Floor.x");
	pMaterial = new NormalMapMaterial();
	pMaterial->SetDiffuse	(".\\Data\\Floor_Diff.dds");
	pMaterial->SetNormal	(".\\Data\\Floor_Normal.dds");
	pMaterial->SetSpecular	(".\\Data\\Floor_Spec.dds");
	pGraphicEntity->SetMaterial(pMaterial);
	pZMaterial = new NormalMapZMaterial();
	pGraphicEntity->SetZMaterial(pZMaterial);
	pShadowMaterial = new NormalMapShadowMaterial();
	pGraphicEntity->SetShadowMaterial(pShadowMaterial);

	// Walls
	pGraphicEntity = _mScene->GetNewGraphicEntity();
	pGraphicEntity->SetMesh(".\\Data\\Walls.x");
	pMaterial = new NormalMapMaterial();
	pMaterial->SetDiffuse	(".\\Data\\Walls_Diff.dds");
	pMaterial->SetNormal	(".\\Data\\Walls_Normal.dds");
	pMaterial->SetSpecular	(".\\Data\\Walls_Spec.dds");
	pGraphicEntity->SetMaterial(pMaterial);
	pZMaterial = new NormalMapZMaterial();
	pGraphicEntity->SetZMaterial(pZMaterial);
	pShadowMaterial = new NormalMapShadowMaterial();
	pGraphicEntity->SetShadowMaterial(pShadowMaterial);

	// Columns
	float NbColumns = 10.f;
	float Distance = 240.f;

	for (float i = 0.f; i < NbColumns; ++i)
	{
		pGraphicEntity = _mScene->GetNewGraphicEntity();
		pGraphicEntity->SetMesh(".\\Data\\Column.x");
		pMaterial = new NormalMapMaterial();
		pMaterial->SetDiffuse	(".\\Data\\Column_Diff.dds"  );
		pMaterial->SetNormal	(".\\Data\\Column_Normal.dds");
		pMaterial->SetSpecular	(".\\Data\\Column_Spec.dds");
		pMaterial->mBumpCoef = 2.f;
		pGraphicEntity->SetMaterial(pMaterial);
		pZMaterial = new NormalMapZMaterial();
		pGraphicEntity->SetZMaterial(pZMaterial);
		pShadowMaterial = new NormalMapShadowMaterial();
		pGraphicEntity->SetShadowMaterial(pShadowMaterial);
		pGraphicEntity->mPosition = AGVector3f( (i - (NbColumns-1.f)/2.f) * Distance , -10.f, -412.f);
	}

	//Light
	AGSpotLight* pSpotLight = _mScene->GetNewSpotLight();
	pSpotLight->mPosition = AGVector3f(0.f, 150.f, -550.f);
	pSpotLight->SetDiffuse (0.7f, 0.7f, 0.7f);
	pSpotLight->SetSpecular(1.0f, 1.0f, 1.0f);
	/*AGVector3f Direction = AGVector3f(0.f, 0.f, 0.f) - pSpotLight->mPosition;
	AGVector3fNormalize(Direction);
	pSpotLight->mDirection = Direction;*/
	pSpotLight->mDirection = AGVector3f(0.f, 0.f, 1.f);
	pSpotLight->mInHalfAngle  = AGPi / 4.f;
	pSpotLight->mOutHalfAngle = AGPi / 3.f;

	//ShadowMap
	AGShadowManager::GetSingleton()->AddNewShadowMap(pSpotLight, 100.f, 1200.f, _mScene);

	_mCamera = new AG3DCamera ();
	_mCamera->mFOV = AGDegToRad (45.f);
	_mCamera->mRatio = 1.f;
	_mCamera->mZNear = 1.f;
	_mCamera->mZFar  = 1000.f;

	_mCamera->mPosition = AGVector3f(0.f, 0.f, -10.f);

	_mMouseInputsId = AGInputManager::GetSingleton()->AddInputs(new MouseInputs());

	AGRenderer::GetSingleton()->mCamera.SetProjParams(AGDegToRad(45.f), 1920.f / 1080.f, 10.f, 10000.f);
	D3DXVECTOR3 Eye    (572.883f, 281.734f, -745.927f);
	D3DXVECTOR3 LookAt (572.398f, 281.624f, -745.059f);
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