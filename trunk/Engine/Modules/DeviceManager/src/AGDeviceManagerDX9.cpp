#pragma once

#include "AGDeviceManagerDX9.h"
#include "AGWindowManager.h"

#include <assert.h>

//------------------------------------------------------------------------------------------------------------------------------
//------------------------------------------------------------------------------------------------------------------------------
AGDeviceManager::AGDeviceManager ()
{
	_mpD3d		= NULL;
	_mpDevice	= NULL;
}

//------------------------------------------------------------------------------------------------------------------------------
AGDeviceManager::~AGDeviceManager()
{
	Destroy();
}

//------------------------------------------------------------------------------------------------------------------------------
//------------------------------------------------------------------------------------------------------------------------------
bool AGDeviceManager::Initialize()
{
	if( NULL == ( _mpD3d = Direct3DCreate9( D3D_SDK_VERSION ) ) )
		return false;

	D3DPRESENT_PARAMETERS d3dpp;
	ZeroMemory( &d3dpp, sizeof(d3dpp) );
	d3dpp.BackBufferWidth  = (s32) (AGWindowManager::GetSingleton()->GetWidth());
	d3dpp.BackBufferHeight = (s32) (AGWindowManager::GetSingleton()->GetHeight());
	d3dpp.Windowed = true;
	d3dpp.SwapEffect = D3DSWAPEFFECT_DISCARD;
	d3dpp.EnableAutoDepthStencil = true;
	d3dpp.AutoDepthStencilFormat = D3DFMT_D16;
	d3dpp.BackBufferFormat = D3DFMT_X8R8G8B8;
	d3dpp.PresentationInterval = D3DPRESENT_INTERVAL_IMMEDIATE;

	if( FAILED( _mpD3d->CreateDevice( D3DADAPTER_DEFAULT, D3DDEVTYPE_HAL, AGWindowManager::GetSingleton()->GetWindow(),
		D3DCREATE_HARDWARE_VERTEXPROCESSING | D3DCREATE_PUREDEVICE,
		&d3dpp, &_mpDevice ) ) )
	{
		return false;
	}

	_mpDevice->SetRenderState( D3DRS_CULLMODE, D3DCULL_NONE );

	_mpDevice->SetRenderState( D3DRS_ZENABLE, TRUE );

	_mpDevice->SetRenderState( D3DRS_LIGHTING, FALSE);

	return true;
}

//------------------------------------------------------------------------------------------------------------------------------
void AGDeviceManager::Destroy()
{
	SAFE_RELEASE(_mpDevice);
	SAFE_RELEASE(_mpD3d);
}

//------------------------------------------------------------------------------------------------------------------------------
//------------------------------------------------------------------------------------------------------------------------------
void AGDeviceManager::DrawMesh (AGPVertexDeclaration& _VertDelc, AGPVertexBuffer& _VB, u32& _VertexSize, AGPIndexBuffer& _IB, u32& _NbVertices, u32& _NbFaces)
{
	_mpDevice->SetVertexDeclaration(_VertDelc);

	_mpDevice->SetStreamSource(0, _VB, 0, _VertexSize);
	_mpDevice->SetIndices(_IB);

	_mpDevice->DrawIndexedPrimitive( D3DPT_TRIANGLELIST, 0, 0, _NbVertices, 0, _NbFaces);
}

//------------------------------------------------------------------------------------------------------------------------------
//------------------------------------------------------------------------------------------------------------------------------
void AGDeviceManager::SetInt (AGPConstantTable& _ConstTable, cStr _VarName, s32& _Int)
{
	assert(_ConstTable);

	AGHandle varHdl = _ConstTable->GetConstantByName(0, _VarName);

	if( AGWarning(varHdl == NULL, "Set Int. Variable handle not found. Variable : %s", _VarName) )
		return;

	_ConstTable->SetInt(_mpDevice, varHdl, _Int);
}

//------------------------------------------------------------------------------------------------------------------------------
void AGDeviceManager::SetFloat (AGPConstantTable& _ConstTable, cStr _VarName, float& _Float)
{
	assert(_ConstTable);

	AGHandle varHdl = _ConstTable->GetConstantByName(0, _VarName);

	if( AGWarning(varHdl == NULL, "Set Float. Variable handle not found. Variable : %s", _VarName) )
		return;

	_ConstTable->SetFloat(_mpDevice, varHdl, _Float);
}

//------------------------------------------------------------------------------------------------------------------------------
void AGDeviceManager::SetVector2f (AGPConstantTable& _ConstTable, cStr _VarName, AGVector2f& _Vector)
{
	assert(_ConstTable);

	AGHandle varHdl = _ConstTable->GetConstantByName(0, _VarName);

	if( AGWarning(varHdl == NULL, "Set Vector2. Variable handle not found. Variable : %s", _VarName) )
		return;

	_ConstTable->SetFloatArray(_mpDevice, varHdl, &(_Vector.x), 2);
}

//------------------------------------------------------------------------------------------------------------------------------
void AGDeviceManager::SetVector3f (AGPConstantTable& _ConstTable, cStr _VarName, AGVector3f& _Vector)
{
	assert(_ConstTable);

	AGHandle varHdl = _ConstTable->GetConstantByName(0, _VarName);

	if( AGWarning(varHdl == NULL, "Set Vector3. Variable handle not found. Variable : %s", _VarName) )
		return;

	_ConstTable->SetFloatArray(_mpDevice, varHdl, &(_Vector.x), 3);
}

//------------------------------------------------------------------------------------------------------------------------------
void AGDeviceManager::SetVector4f (AGPConstantTable& _ConstTable, cStr _VarName, AGVector4f& _Vector)
{
	assert(_ConstTable);

	AGHandle varHdl = _ConstTable->GetConstantByName(0, _VarName);

	if( AGWarning(varHdl == NULL, "Set Vector4. Variable handle not found. Variable : %s", _VarName) )
		return;

	_ConstTable->SetFloatArray(_mpDevice, varHdl, &(_Vector.x), 4);
}

//------------------------------------------------------------------------------------------------------------------------------
void AGDeviceManager::SetMatrix (AGPConstantTable& _ConstTable, cStr _VarName, AGMatrix& _Matrix)
{
	assert(_ConstTable);

	AGHandle varHdl = _ConstTable->GetConstantByName(0, _VarName);

	if( AGWarning(varHdl == NULL, "Set Matrix. Variable handle not found. Variable : %s", _VarName) )
		return;

	_ConstTable->SetMatrix(_mpDevice, varHdl, &_Matrix);
}

//------------------------------------------------------------------------------------------------------------------------------
void AGDeviceManager::SetTexture(AGPConstantTable& _ConstTable, cStr _VarName, AGPTexture& _Texture)
{
	assert(_ConstTable);

	AGHandle textureHdl = _ConstTable->GetConstantByName(0, _VarName);
	if (AGWarning(textureHdl == NULL, "Set Sampler. Variable handle not found."))
		return;

	AGConstantDesc textureDesc;
	u32 count;

	_ConstTable->GetConstantDesc(textureHdl, &textureDesc, &count);
	_mpDevice->SetTexture(textureDesc.RegisterIndex, _Texture);
}