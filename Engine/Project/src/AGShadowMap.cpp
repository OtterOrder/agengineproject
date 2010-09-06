#include "AGShadowMap.h"

//------------------------------------------------------------------------------------------------------------------------------
//------------------------------------------------------------------------------------------------------------------------------
AGShadowMap::AGShadowMap(AGLight* _pLight, float _ZNear, float _ZFar, AG3DScene* _pScene)
{
	_mpLight	= _pLight;
	_mZRange.x	= _ZNear;
	_mZRange.y	= _ZFar;
	_mpScene	= _pScene;
	if (_mpLight->GetType() == AGLight::Spot)
		AGMatrixPerspectiveFovLH(&_mProjection, ((AGSpotLight*)_mpLight)->mOutHalfAngle * 2.f, 1.f, _mZRange.x, _mZRange.y);
}

//------------------------------------------------------------------------------------------------------------------------------
AGShadowMap::~AGShadowMap()
{
}

//------------------------------------------------------------------------------------------------------------------------------
//------------------------------------------------------------------------------------------------------------------------------
void AGShadowMap::Update()
{
	if (_mpLight->GetType() == AGLight::Spot)
	{
		AGVector3f Eye = _mpLight->mPosition;
		AGVector3f At  = Eye + ((AGSpotLight*)_mpLight)->mDirection;
		AGVector3f Up  = AGVector3f(0.f, 0.f, 1.f);		////.

		AGMatrixLookAtLH(&_mView, &Eye, &At, &Up);
		AGMatrixMultiply(&_mViewProj, &_mView, &_mProjection);
	}
}