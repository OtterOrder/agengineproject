#include "AGShadowManager.h"

#include "AGWindowManager.h"

//------------------------------------------------------------------------------------------------------------------------------
//------------------------------------------------------------------------------------------------------------------------------
AGShadowManager::AGShadowManager()
{
}

//------------------------------------------------------------------------------------------------------------------------------
AGShadowManager::~AGShadowManager()
{
	Destroy();
}

//------------------------------------------------------------------------------------------------------------------------------
void AGShadowManager::Destroy()
{
	SAFE_RELEASE (_mPStencil);
}

//------------------------------------------------------------------------------------------------------------------------------
//------------------------------------------------------------------------------------------------------------------------------
void AGShadowManager::Initialize ()
{
	AGVector2u _ShadowMapSize (__SHADOW_MAP_SIZE__, __SHADOW_MAP_SIZE__);
	AGCreateStencilSurface(_ShadowMapSize, AG_D16, _mPStencil);
	_mShadowMap.Create(_ShadowMapSize, AG_R32F);
	_mShadows.Create(AGWindowManager::GetSingleton()->GetSize(), AG_R32F);
}

//------------------------------------------------------------------------------------------------------------------------------
//------------------------------------------------------------------------------------------------------------------------------
void AGShadowManager::Update ()
{
	AGShadowMap::Iterator ShadowMapIt;

	for (ShadowMapIt = _mpShadowMaps.begin(); ShadowMapIt != _mpShadowMaps.end(); ShadowMapIt++)
	{
		AGShadowMap* pShadowMap = (*ShadowMapIt);
		pShadowMap->Update();
		AGLight* pLight = (AGLight*)(pShadowMap->GetLight());
		if (pLight->GetType() == AGLight::Spot)
		{
			RenderShadowMap(pShadowMap, (AGSpotLight*)pLight);
			RenderShadows(pShadowMap);
		}
	}

	AGDeviceManager::GetSingleton()->RestoreBackBuffer();
}

//------------------------------------------------------------------------------------------------------------------------------
//------------------------------------------------------------------------------------------------------------------------------
void AGShadowManager::AddNewShadowMap (AGLight* _pLight, float _ZNear, float _ZFar, AG3DScene* _pScene)
{
	_mpShadowMaps.push_back(new AGShadowMap(_pLight, _ZNear, _ZFar, _pScene));
}

//------------------------------------------------------------------------------------------------------------------------------
//------------------------------------------------------------------------------------------------------------------------------
void AGShadowManager::RenderShadowMap (AGShadowMap* _pShadowMap, AGSpotLight* _pLight)
{
	AGDeviceManager::GetSingleton()->SetRenderTarget(0, _mShadowMap.GetSurface());
	AGDeviceManager::GetSingleton()->SetDepthStencilSurface(_mPStencil);

	AGRenderer::GetSingleton()->RenderZ((AG3DScene*)_pShadowMap->GetScene(), _pShadowMap->GetView(), _pShadowMap->GetProjection(), _pShadowMap->GetViewProj());
}

//------------------------------------------------------------------------------------------------------------------------------
void AGShadowManager::RenderShadows (AGShadowMap* _pShadowMap)
{
	AGDeviceManager::GetSingleton()->SetRenderTarget(0, _mShadows.GetSurface());
	AGDeviceManager::GetSingleton()->SetDepthStencilSurface(AGDeviceManager::GetSingleton()->GetStencilBuffer());

	AGDeviceManager::GetSingleton()->RestoreBackBuffer();	////.

	AGRenderer::GetSingleton()->RenderShadow((AG3DScene*)_pShadowMap->GetScene(), _pShadowMap->GetViewProj(), _mShadowMap.GetTexture());
}