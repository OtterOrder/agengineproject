#include "AGRenderer.h"

#include "AG2DScene.h"
#include "AG3DScene.h"

#include "AGSystem.h"	////.

//------------------------------------------------------------------------------------------------------------------------------
//------------------------------------------------------------------------------------------------------------------------------
AGRenderer::AGRenderer()
{
	mCamera.SetProjParams(D3DX_PI/4.f, 1.f, 0.5f, 300.f);
	mCamera.SetViewParams(&D3DXVECTOR3(-100.f, 100.f, -100.f), &D3DXVECTOR3(0.f, 0.f, 0.f));
}

//------------------------------------------------------------------------------------------------------------------------------
AGRenderer::~AGRenderer()
{
}

//------------------------------------------------------------------------------------------------------------------------------
void AGRenderer::Destroy()
{
}

//------------------------------------------------------------------------------------------------------------------------------
//------------------------------------------------------------------------------------------------------------------------------
void AGRenderer::Render (AG3DScene* _pScene)
{
	mCamera.FrameMove(AGSystem::GetSingleton()->mTimer.GetDt());	////.

	AGDeviceManager* pDeviceManager = AGDeviceManager::GetSingleton();
	
	if (pDeviceManager->BeginScene())
	{
		pDeviceManager->Clear( AGCLEAR_TARGET|AGCLEAR_ZBUFFER, AGCOLOR_XRGB(0, 0, 0), 1.f );

		AG3DCamera* pCamera = (AG3DCamera*)(_pScene->GetCamera());

		//AG3DGraphicEntity::Iterator GEntityIt;	// erreur de compilation. ?
		std::vector<AG3DGraphicEntity*>::iterator GEntityIt;	////.

		std::vector<AG3DGraphicEntity*> Entities = _pScene->GetEntities();

		for (GEntityIt = Entities.begin(); GEntityIt != Entities.end(); GEntityIt++)
		{
			(*GEntityIt)->Draw(&mCamera, _pScene);	////.
		}

		pDeviceManager->EndScene();
	}

	pDeviceManager->Present();
}

////.
//------------------------------------------------------------------------------------------------------------------------------
//------------------------------------------------------------------------------------------------------------------------------
void AGRenderer::RenderZ (AG3DScene* _pScene, AGMatrix _ViewMatrix, AGMatrix _ProjMatrix, AGMatrix _ViewProjMatrix)
{
	AGDeviceManager* pDeviceManager = AGDeviceManager::GetSingleton();

	if (pDeviceManager->BeginScene())
	{
		pDeviceManager->Clear( AGCLEAR_TARGET|AGCLEAR_ZBUFFER, AGCOLOR_XRGB(255, 255, 255), 1.f );

		//AG3DGraphicEntity::Iterator GEntityIt;	// erreur de compilation. ?
		std::vector<AG3DGraphicEntity*>::iterator GEntityIt;	////.

		std::vector<AG3DGraphicEntity*> Entities = _pScene->GetEntities();

		for (GEntityIt = Entities.begin(); GEntityIt != Entities.end(); GEntityIt++)
		{
			(*GEntityIt)->DrawZ(_ViewMatrix, _ProjMatrix, _ViewProjMatrix);
		}

		pDeviceManager->EndScene();
	}
}

//------------------------------------------------------------------------------------------------------------------------------
void AGRenderer::RenderShadow (AG3DScene* _pScene, AGMatrix _LightViewProjMatrix, AGPTexture _ShadowMap)
{
	mCamera.FrameMove(AGSystem::GetSingleton()->mTimer.GetDt());	////.

	AGDeviceManager* pDeviceManager = AGDeviceManager::GetSingleton();

	if (pDeviceManager->BeginScene())
	{
		pDeviceManager->Clear( AGCLEAR_TARGET|AGCLEAR_ZBUFFER, AGCOLOR_XRGB(0, 0, 0), 1.f );

		//AG3DGraphicEntity::Iterator GEntityIt;	// erreur de compilation. ?
		std::vector<AG3DGraphicEntity*>::iterator GEntityIt;	////.

		std::vector<AG3DGraphicEntity*> Entities = _pScene->GetEntities();

		for (GEntityIt = Entities.begin(); GEntityIt != Entities.end(); GEntityIt++)
		{
			(*GEntityIt)->DrawShadow(&mCamera, _LightViewProjMatrix, _ShadowMap);
		}

		pDeviceManager->EndScene();
	}
}
////.

//------------------------------------------------------------------------------------------------------------------------------
void AGRenderer::Render (AG2DScene* _pScene)
{
}