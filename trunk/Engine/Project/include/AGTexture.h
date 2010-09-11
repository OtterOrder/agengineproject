#pragma once
#include "AGResource.h"

#include "AGSamplerState.h"

//------------------------------------------------------------------------------------------------------------------------------
class AGTexture : public AGResource
{
private:
	AGImageInfo		_mTextureInfo;
	AGPTexture		_mPTexture;
	AGSamplerState	_mSampState;

public:
								AGTexture	();
								~AGTexture	();

			AGResourceResult	Load (cStr _FileName, void* _Parameters = NULL);
			void				Release ();

	inline	AGPTexture			GetTexture		()	{ return _mPTexture;	}
	inline	AGSamplerState*		GetSamplerState	()	{ return &_mSampState;	}
};