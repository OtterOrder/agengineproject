#include "AGRenderer.h"

#include "AGDeviceManager.h"

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
//------------------------------------------------------------------------------------------------------------------------------
void AGRenderer::Render (AG3DScene* _pScene)
{
	mCamera.FrameMove(AGSystem::GetSingleton()->mTimer.GetDt());	////.

	AGDeviceManager* pDeviceManager = AGDeviceManager::GetSingleton();
	
	if (pDeviceManager->BeginScene())
	{
		pDeviceManager->Clear( AGCLEAR_TARGET|AGCLEAR_ZBUFFER, AGCOLOR_XRGB(0, 0, 125), 1.f );

		//_3DGraphicEntity->Draw(&mCamera, _pScene);	////.

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

//------------------------------------------------------------------------------------------------------------------------------
void AGRenderer::Render (AG2DScene* _pScene)
{
}