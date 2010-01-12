#include "AGRenderer.h"

#include "AGDeviceManager.h"

#include "AgSystem.h"	////.

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
void AGRenderer::Render (AG3DGraphicEntity* _3DGraphicEntity, AG3DCamera* _pCamera)
{
	mCamera.FrameMove(AGSystem::GetSingleton()->mTimer.GetDt());	////.

	AGDeviceManager* pDeviceManager = AGDeviceManager::GetSingleton();
	
	if (pDeviceManager->BeginScene())
	{
		pDeviceManager->Clear( AGCLEAR_TARGET|AGCLEAR_ZBUFFER, AGCOLOR_XRGB(0, 0, 125), 1.f );

		_3DGraphicEntity->Draw(&mCamera);	////.

		pDeviceManager->EndScene();
	}

	pDeviceManager->Present();
}