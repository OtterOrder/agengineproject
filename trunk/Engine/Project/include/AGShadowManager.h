#pragma once

#include "AGSingleton.h"

#include "AGShadowMap.h"
#include "AGRenderTarget.h"

#define __NB_SHADOWMAP_MAX__	4
#define __SHADOW_MAP_SIZE__		1024

//------------------------------------------------------------------------------------------------------------------------------
class AGShadowManager : public AGSingleton<AGShadowManager>
{
friend class AGSingleton<AGShadowManager>;

private:
	std::vector <AGShadowMap*>	_mpShadowMaps;
	AGPSurface					_mPStencil;
	AGRenderTarget				_mShadowMap;
	AGRenderTarget				_mShadows;

protected:
						AGShadowManager		();
						~AGShadowManager	();
			void		Destroy				();

public:
			void		Initialize	();
			void		Update		();

			void		AddNewShadowMap (AGLight* _pLight, float _ZNear, float _ZFar, AG3DScene* _pScene);

	inline	AGPTexture	GetShadows		()		{ return _mShadows.GetTexture(); }

private:
			void		RenderShadowMap (AGShadowMap* _pShadowMap, AGSpotLight* _pLight);
			void		RenderShadows	(AGShadowMap* _pShadowMap);
};