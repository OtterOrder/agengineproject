#pragma once
#include "AGResource.h"

#include "AGTextureFilter.h"

//------------------------------------------------------------------------------------------------------------------------------
class AGTexture : public AGResource
{
private:
	AGImageInfo		_mTextureInfo;
	AGPTexture		_mPTexture;
	AGTextureFilter	_mFiltering;

public:
								AGTexture	();
								~AGTexture	();

			AGResourceResult	Load (cStr _FileName, void* _Parameters = NULL);
			void				Release ();

	inline	AGPTexture			GetTexture		()	{ return _mPTexture;	}
	inline	AGTextureFilter*	GetFilter		()	{ return &_mFiltering;	}
};