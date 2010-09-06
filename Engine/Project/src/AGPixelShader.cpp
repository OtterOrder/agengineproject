#include "AGPixelShader.h"

#include "AGDeviceManager.h"

//------------------------------------------------------------------------------------------------------------------------------
//------------------------------------------------------------------------------------------------------------------------------
AGPixelShader::AGPixelShader()
{
	_mpPixelShader	 = NULL;
	_mpConstantTable = NULL;

}

//------------------------------------------------------------------------------------------------------------------------------
AGPixelShader::~AGPixelShader()
{
	Release();
}

//------------------------------------------------------------------------------------------------------------------------------
//------------------------------------------------------------------------------------------------------------------------------
AGResource::AGResourceResult AGPixelShader::Load (cStr _FileName, void* _Parameters)
{
	Release();

	AGLoadPixelShader(_FileName, (cStr)_Parameters, _mpPixelShader, _mpConstantTable);

	return RES_SUCCEED;
}

//------------------------------------------------------------------------------------------------------------------------------
void AGPixelShader::Release ()
{
	AGResource::Release();

	SAFE_RELEASE(_mpPixelShader );
	SAFE_RELEASE(_mpConstantTable);
}