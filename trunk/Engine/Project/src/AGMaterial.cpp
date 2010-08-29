#include "AGMaterial.h"

#include "AGResourceManager.h"

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

void AGMaterial::Activate()
{
	_mpVertexShader->Activate();
	_mpPixelShader->Activate();
}