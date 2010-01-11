#pragma once
#include "AGResource.h"

#include "AGTypesDX9.h"

//------------------------------------------------------------------------------------------------------------------------------
class AGVertexShader : public AGResource
{
private:
	AGPVertexShader		_mpVertexShader;
	AGPConstantTable	_mpConstantTable;

public:
	AGVertexShader	();
	~AGVertexShader	();

	AGResourceResult	Load (cStr _FileName, void* _Parameters = NULL);
	void				Release ();
};