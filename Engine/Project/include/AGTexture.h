#pragma once
#include "AGResource.h"

//------------------------------------------------------------------------------------------------------------------------------
class AGTexture : public AGResource
{
private:
	AGImageInfo	_mTextureInfo;
	AGPTexture	_mPTexture;

public:
								AGTexture	();
								~AGTexture	();

			AGResourceResult	Load (cStr _FileName, void* _Parameters = NULL);
			void				Release ();

	inline	AGPTexture			GetTexture ()	{ return _mPTexture; }
};