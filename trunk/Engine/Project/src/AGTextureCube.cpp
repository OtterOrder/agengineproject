#include "AGTextureCube.h"

#include "AGWDX9.h"

//------------------------------------------------------------------------------------------------------------------------------
//------------------------------------------------------------------------------------------------------------------------------
AGTextureCube::AGTextureCube()
{
	_mPTexture = NULL;
}

//------------------------------------------------------------------------------------------------------------------------------
AGTextureCube::~AGTextureCube()
{
}

//------------------------------------------------------------------------------------------------------------------------------
//------------------------------------------------------------------------------------------------------------------------------
AGResource::AGResourceResult AGTextureCube::Load (cStr _FileName, void* _Parameters)
{
	Release();

	AGLoadTextureCube(_FileName, _mPTexture, _mTextureInfo);

	return RES_SUCCEED;
}

//------------------------------------------------------------------------------------------------------------------------------
void AGTextureCube::Release ()
{
	SAFE_RELEASE(_mPTexture);
}