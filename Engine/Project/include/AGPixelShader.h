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

	inline void			Activate ()		{ AGDeviceManager::GetSingleton()->SetPixelShader(_mpPixelShader); };

	inline void	SetMatrix	(cStr _VarName, AGMatrix   _Matrix)		{ AGDeviceManager::GetSingleton()->SetMatrix (_mpConstantTable, _VarName, _Matrix);  }
	inline void	SetTexture	(cStr _VarName, AGPTexture _Texture)	{ AGDeviceManager::GetSingleton()->SetTexture(_mpConstantTable, _VarName, _Texture); }
};