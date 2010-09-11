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

	AG3DGraphicEntity* pGraphicEntity;

	
	// Skybox
	SkyboxMaterial* pSkyMaterial = new SkyboxMaterial();
	//pSkyMaterial->SetCubeMapFromFile(".\\Data\\rnl_cross.dds");
	pSkyMaterial->SetCubeMapFromFile(".\\Data\\galileo_cross.dds");
	//pSkyMaterial->SetCubeMapFromFile(".\\Data\\uffizi_cross.dds");

	AGPRTLightProbe* pLightProbe = _mScene->GetNewPRTSkybox();
	pLightProbe->mScale = AGVector3f(1000.f, 1000.f, 1000.f);
	pLightProbe->SetMaterial(pSkyMaterial);
	float** SHCoef = pLightProbe->ComputeSHFromCubeMap(pSkyMaterial->GetCubeMap());
	pLightProbe->Update();

	// Object
	pGraphicEntity = _mScene->GetNewGraphicEntity();
	pGraphicEntity->SetMesh(".\\Data\\bunny.x");

	PRTLightMaterial* pPRTMaterial = new PRTLightMaterial();
	pGraphicEntity->SetMaterial(pPRTMaterial);
	pPRTMaterial->SetDiffuse(".\\Data\\marble.dds");
	pPRTMaterial->SetNormal	(".\\Data\\marble_normal.dds");
	pPRTMaterial->SetSHCoefFromCubeMap(SHCoef);
	pPRTMaterial->SetYlmCoef0(pLightProbe->GetYlmCoeff0());
	pPRTMaterial->SetYlmCoef4(pLightProbe->GetYlmCoeff4());
	pPRTMaterial->SetYlmCoef8(pLightProbe->GetYlmCoeff8());
	pPRTMaterial->SetYlmCoef12(pLightProbe->GetYlmCoeff12());
	pPRTMaterial->SetTransmitColor(AGVector3f(1.0f, 1.0f, 1.0f));
	pPRTMaterial->SetLightContribution(2.0f);
	pPRTMaterial->SetEnvironmentContribution(0.3f);

	// Light
	AGSpotLight* pSpotLight = _mScene->GetNewSpotLight();
	pSpotLight->mPosition = AGVector3f(0.f, 300.f, 0.f);
	pSpotLight->SetDiffuse (0.7f, 0.7f, 0.7f);
	pSpotLight->SetSpecular(1.0f, 1.0f, 1.0f);
	pSpotLight->mDirection = AGVector3f(-0.7f, 0.5f, 0.3f);
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
	D3DXVECTOR3 Eye    (0.0f, 0.0f, -70.0f);
	D3DXVECTOR3 LookAt (0.0f, 0.0f, 0.0f);
	AGRenderer::GetSingleton()->mCamera.SetViewParams(&Eye, &LookAt);
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