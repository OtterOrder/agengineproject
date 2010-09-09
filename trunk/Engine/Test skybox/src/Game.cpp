#include "Game.h"
#include "AgSystem.h"
#include "AGResource.h"

#include "AGWindowManager.h"
#include "AGResourceManager.h"
#include "AGInputManager.h"
#include "AGSceneManager.h"
#include "AGRenderer.h"
#include "AG3DDefaultMaterial.h"
#include "AGPRTLightProbe.h"

#include "NormalMapMaterial.h"
#include "SkyboxMaterial.h"
#include "PRTLightMaterial.h"

#include "AGTypesDX9.h"

#include <iostream>
using namespace std;

#include "MouseInputs.h"

//------------------------------------------------------------------------------------------------------------------------------
//------------------------------------------------------------------------------------------------------------------------------
void Game::InitEngine()
{
	cout << "Game Init Engine" << endl;

	AGWindowManager::GetSingleton()->SetSize(1280, 1024);
}

//------------------------------------------------------------------------------------------------------------------------------
void Game::Init()
{
	_mScene = AGSceneManager::GetSingleton()->GetNew3DScene();

	PRTLightMaterial* Material;
	AG3DGraphicEntity* pGraphicEntity;

	// Object
	pGraphicEntity = _mScene->GetNewGraphicEntity();
	pGraphicEntity->SetMesh(".\\Data\\bat.x");
	Material = new PRTLightMaterial();
	pGraphicEntity->SetMaterial(Material);
	Material->SetDiffuse(".\\Data\\batalbedo.dds");
	Material->SetNormal	(".\\Data\\BatNormalMap.dds");

	/*NormalMapMaterial*			pMaterial;
	pGraphicEntity = _mScene->GetNewGraphicEntity();
	pGraphicEntity->SetMesh(".\\Data\\dragon.x");
	pMaterial = new NormalMapMaterial();
	pMaterial->SetDiffuse	(".\\Data\\Floor_Diff.dds");
	pMaterial->SetNormal	(".\\Data\\Floor_Normal.dds");
	pMaterial->SetSpecular	(".\\Data\\Floor_Spec.dds");
	pGraphicEntity->SetMaterial(pMaterial);*/

	SkyboxMaterial* Material_0 = new SkyboxMaterial();
	Material_0->SetCubeMapFromFile(".\\Data\\uffizi_cross.dds");

	AGPRTLightProbe* pSkybox = _mScene->GetNewPRTSkybox();
	pSkybox->mScale = AGVector3f(1000.f, 1000.f, 1000.f);
	pSkybox->SetMaterial(Material_0);
	pSkybox->ComputeSHFromCubeMap(Material_0->GetCubeMap());
	pSkybox->Update();

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

	AGRenderer::GetSingleton()->mCamera.SetProjParams(AGDegToRad(45.f), 1280.f / 1024.f, 0.1f, 100000.f);
	D3DXVECTOR3 Eye    (100.0f, 100.0f, 100.0f);
	D3DXVECTOR3 LookAt (0.0f, 0.0f, 0.0f);
	AGRenderer::GetSingleton()->mCamera.SetViewParams(&Eye, &LookAt);

	//_mScene->Get3DCamera()->mPosition  = AGVector3f(-1193.999756f, 292.999969f, 191.999969f);
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