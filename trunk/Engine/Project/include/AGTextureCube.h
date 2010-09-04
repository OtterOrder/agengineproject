#pragma once
#include "AGResource.h"

//------------------------------------------------------------------------------------------------------------------------------
class AGTextureCube : public AGResource
{
private:
	AGImageInfo		_mTextureInfo;
	AGPTextureCube	_mPTexture;

public:
	AGTextureCube	();
	~AGTextureCube	();

	AGResourceResult	Load (cStr _FileName, void* _Parameters = NULL);
	void				Release ();

	inline	AGPTextureCube			GetTexture ()	{ return _mPTexture; }
};