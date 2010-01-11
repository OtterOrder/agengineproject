#pragma once
#include "AGResource.h"

#include "AGTypesDX9.h"

//------------------------------------------------------------------------------------------------------------------------------
class AGPixelShader : public AGResource
{
private:
	AGPPixelShader		_mpPixelShader;
	AGPConstantTable	_mpConstantTable;

public:
	AGPixelShader	();
	~AGPixelShader	();

	AGResourceResult	Load (cStr _FileName, void* _Parameters = NULL);
	void				Release ();
};