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
	SAFE_DELETE	 (_mpShadowHBlur);
	SAFE_DELETE	 (_mpShadowVBlur);
}

//------------------------------------------------------------------------------------------------------------------------------
//------------------------------------------------------------------------------------------------------------------------------
void AGShadowManager::Initialize ()
{
	AGVector2u _ShadowMapSize (__SHADOW_MAP_SIZE__, __SHADOW_MAP_SIZE__);
	AGCreateStencilSurface(_ShadowMapSize, AG_D16, _mPStencil);
	_mShadowMap.Create(_ShadowMapSize, AG_R32F);
	_mBlurCoef.Create(AGWindowManager::GetSingleton()->GetSize(), AG_R32F);
	_mShadows0.Create(AGWindowManager::GetSingleton()->GetSize(), AG_R32F);
	_mShadows1.Create(AGWindowManager::GetSingleton()->GetSize(), AG_R32F);

	_mpShadowHBlur = new AGShadowHBlur();
	_mpShadowVBlur = new AGShadowVBlur();
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

	BlurShadows();

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
	AGDeviceManager::GetSingleton()->SetRenderTarget(0, _mShadows0.GetSurface());
	AGDeviceManager::GetSingleton()->SetRenderTarget(1, _mBlurCoef.GetSurface());
	AGDeviceManager::GetSingleton()->SetDepthStencilSurface(AGDeviceManager::GetSingleton()->GetStencilBuffer());

	AGRenderer::GetSingleton()->RenderShadow((AG3DScene*)_pShadowMap->GetScene(), _pShadowMap->GetViewProj(), _mShadowMap.GetTexture());

	AGDeviceManager::GetSingleton()->SetRenderTarget(1, NULL);
}

//------------------------------------------------------------------------------------------------------------------------------
void AGShadowManager::BlurShadows ()
{
	AGDeviceManager::GetSingleton()->SetRenderTarget(0, _mShadows1.GetSurface());
	AGDeviceManager::GetSingleton()->SetDepthStencilSurface(AGDeviceManager::GetSingleton()->GetStencilBuffer());

	_mpShadowHBlur->mpTexture  = _mShadows0.GetTexture();
	_mpShadowHBlur->mpBlurCoef = _mBlurCoef.GetTexture();
	_mpShadowHBlur->Apply();

	AGDeviceManager::GetSingleton()->SetRenderTarget(0, _mShadows0.GetSurface());
	AGDeviceManager::GetSingleton()->SetDepthStencilSurface(AGDeviceManager::GetSingleton()->GetStencilBuffer());

	_mpShadowVBlur->mpTexture = _mShadows1.GetTexture();
	_mpShadowVBlur->mpBlurCoef = _mBlurCoef.GetTexture();
	_mpShadowVBlur->Apply();
}