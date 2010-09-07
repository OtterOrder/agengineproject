#pragma once
#include "AGResource.h"

#include "AGTexture.h"

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

	inline void			Activate ()		{ AGDeviceManager::GetSingleton()->SetVertexShader(_mpVertexShader); };

	inline	void	SetInt		(cStr _VarName, int _Int)											{ AGDeviceManager::GetSingleton()->SetInt		(_mpConstantTable, _VarName, _Int);				}
	inline	void	SetFloat	(cStr _VarName, float _Float)										{ AGDeviceManager::GetSingleton()->SetFloat		(_mpConstantTable, _VarName, _Float);			}
	inline	void	SetVector2f	(cStr _VarName, AGVector2f _Vector)									{ AGDeviceManager::GetSingleton()->SetVector2f	(_mpConstantTable, _VarName, _Vector);			}
	inline	void	SetVector3f	(cStr _VarName, AGVector3f _Vector)									{ AGDeviceManager::GetSingleton()->SetVector3f	(_mpConstantTable, _VarName, _Vector);			}
	inline	void	SetVector4f	(cStr _VarName, AGVector4f _Vector)									{ AGDeviceManager::GetSingleton()->SetVector4f	(_mpConstantTable, _VarName, _Vector);			}
	inline	void	SetMatrix	(cStr _VarName, AGMatrix _Matrix)									{ AGDeviceManager::GetSingleton()->SetMatrix	(_mpConstantTable, _VarName, _Matrix);			}
	inline	void	SetTexture	(cStr _VarName, AGPTexture _Texture, AGTextureFilter* _Filter)		{ AGDeviceManager::GetSingleton()->SetTexture	(_mpConstantTable, _VarName, _Texture, _Filter);}
	inline	void	SetTexture	(cStr _VarName, AGTexture* _Texture)								{ SetTexture(_VarName, _Texture->GetTexture(), _Texture->GetFilter());							}
};