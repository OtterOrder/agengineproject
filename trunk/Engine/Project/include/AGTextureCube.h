#pragma once
#include "AGResource.h"

//------------------------------------------------------------------------------------------------------------------------------
class AGTextureCube : public AGResource
{
private:
	AGImageInfo	_mTextureInfo;
	AGPTexture	_mPTexture;

public:
	AGTextureCube	();
	~AGTextureCube	();

	AGResourceResult	Load (cStr _FileName, void* _Parameters = NULL);
	void				Release ();

	inline	AGPTexture			GetTexture ()	{ return _mPTexture; }
};