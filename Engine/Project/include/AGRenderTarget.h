#pragma once

#include "AGUtilities.h"
#include "AGDeviceManager.h"

//------------------------------------------------------------------------------------------------------------------------------
class AGRenderTarget
{
	AGVector2u	_mSize;

	AGPTexture	_mpTexture;
	AGPSurface	_mpSurface;

public:
						AGRenderTarget	();
	virtual				~AGRenderTarget	();

			void		Release			();
	bool				Create			(AGVector2u _Size, AGTextureFormat _Format = AG_A8R8G8B8);

	inline	AGPTexture GetTexture		()	{ return _mpTexture; };
	inline	AGPSurface GetSurface		()	{ return _mpSurface; };

			void		operator =		(const AGRenderTarget& _RenderTarget);
};