#pragma once
#include "AGResource.h"

#include "AGTypesDX9.h"

//------------------------------------------------------------------------------------------------------------------------------
class AGShader : public AGResource
{
private:
	AGPVertexShader		_mpVertexShader;
	AGPPixelShader		_mpPixelShader;

	AGPConstantTable	_mpVertexConstantTable;
	AGPConstantTable	_mpPixelConstantTable;

public:
	AGShader	();
	~AGShader	();

	AGResourceResult	Load (cStr _FileName, void* _Parameters = NULL);
	void				Release ();
};