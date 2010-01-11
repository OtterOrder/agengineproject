#include "AGVertexShader.h"

#include "AGWDX9.h"

//------------------------------------------------------------------------------------------------------------------------------
//------------------------------------------------------------------------------------------------------------------------------
AGVertexShader::AGVertexShader()
{
	_mpVertexShader	 = NULL;
	_mpConstantTable = NULL;
}

//------------------------------------------------------------------------------------------------------------------------------
AGVertexShader::~AGVertexShader()
{
	Release();
}

//------------------------------------------------------------------------------------------------------------------------------
//------------------------------------------------------------------------------------------------------------------------------
AGResource::AGResourceResult AGVertexShader::Load (cStr _FileName, void* _Parameters)
{
	Release();

	AGLoadVertexShader(_FileName, (cStr)_Parameters, _mpVertexShader, _mpConstantTable);

	return RES_SUCCEED;
}

//------------------------------------------------------------------------------------------------------------------------------
void AGVertexShader::Release ()
{
	SAFE_RELEASE(_mpVertexShader);
	SAFE_RELEASE(_mpConstantTable);
}