#pragma once

#include "AGUtilities.h"
#include "AGLight.h"
#include "AG3DScene.h"

//------------------------------------------------------------------------------------------------------------------------------
class AGShadowMap
{
public:
	DefineVectorIterator(AGShadowMap, Iterator);

private:
	AGLight*	_mpLight;
	AGVector2f	_mZRange;
	AG3DScene*	_mpScene;
	AGMatrix	_mView;
	AGMatrix	_mProjection;
	AGMatrix	_mViewProj;

public:
								AGShadowMap		(AGLight* _pLight = NULL, float _ZNear = 1.f, float _ZFar = 1000.f, AG3DScene* _pScene = NULL);
	virtual						~AGShadowMap	();

	inline	const AGLight*		GetLight		()	const	{ return _mpLight;		}
	inline	const float&		GetZNear		()	const	{ return _mZRange.x;	}
	inline	const float&		GetZFar			()	const	{ return _mZRange.y;	}
	inline	const AG3DScene*	GetScene		()	const	{ return _mpScene;		}
	inline	const AGMatrix&		GetView			()	const	{ return _mView;		}
	inline	const AGMatrix&		GetProjection	()	const	{ return _mProjection;	}
	inline	const AGMatrix&		GetViewProj		()	const	{ return _mViewProj;	}
			
			void				Update			();
};