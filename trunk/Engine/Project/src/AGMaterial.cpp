#include "AGMaterial.h"

#include "AGResourceManager.h"

#define		DEFAULT_VS_PATH		".\\Data\\Shaders\\Defaults\\DefaultVS.vsh"
#define		DEFAULT_PS_PATH		".\\Data\\Shaders\\Defaults\\DefaultPS.psh"

#define		DEFAULT_VS_ENTRY	"VSMain"
#define		DEFAULT_PS_ENTRY	"PSMain"

//------------------------------------------------------------------------------------------------------------------------------
//------------------------------------------------------------------------------------------------------------------------------
AGMaterial::AGMaterial()
{
	_mpVertexShader	= NULL;
	_mpPixelShader	= NULL;
}

//------------------------------------------------------------------------------------------------------------------------------
AGMaterial::~AGMaterial()
{
	SAFE_DECREF(_mpVertexShader);
	SAFE_DECREF(_mpPixelShader);
}

//------------------------------------------------------------------------------------------------------------------------------
//------------------------------------------------------------------------------------------------------------------------------
void AGMaterial::SetShader (cStr _VertexShaderFileName, cStr _VertexEntryPoint, cStr _PixelShaderFileName, cStr _PixelEntryPoint)
{
	if (!_VertexShaderFileName)
	{
		_VertexShaderFileName	= DEFAULT_VS_PATH;
		_VertexEntryPoint		= DEFAULT_VS_ENTRY;
	}

	if (!_PixelShaderFileName)
	{
		_PixelShaderFileName	= DEFAULT_PS_PATH;
		_PixelEntryPoint		= DEFAULT_PS_ENTRY;
	}

	SAFE_DECREF(_mpVertexShader);
	SAFE_DECREF(_mpPixelShader);

	_mpVertexShader = AGResourceManager::GetSingleton()->Load<AGVertexShader>(_VertexShaderFileName, (void*)_VertexEntryPoint);
	_mpPixelShader  = AGResourceManager::GetSingleton()->Load<AGPixelShader> (_PixelShaderFileName,  (void*)_PixelEntryPoint);
}

//------------------------------------------------------------------------------------------------------------------------------
void AGMaterial::SetVertexShader (cStr _FileName, cStr _EntryPoint)
{
	_mpVertexShader = AGResourceManager::GetSingleton()->Load<AGVertexShader>(_FileName, (void*)_EntryPoint);
}

//------------------------------------------------------------------------------------------------------------------------------
void AGMaterial::SetPixelShader (cStr _FileName, cStr _EntryPoint)
{
	_mpPixelShader = AGResourceManager::GetSingleton()->Load<AGPixelShader>(_FileName, (void*)_EntryPoint);
}

void AGMaterial::Apply(AGScene* _pScene)
{
	if (_mpVertexShader)
		_mpVertexShader->Activate();

	if (_mpPixelShader)
		_mpPixelShader->Activate();
}