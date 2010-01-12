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
void AGDeviceManager::SetMatrix (AGPConstantTable& _ConstTable, cStr _VarName, AGMatrix& _Matrix)
{
	assert(_ConstTable);

	AGHandle varHdl = _ConstTable->GetConstantByName(0, _VarName);
	AGWarningReturn(varHdl != NULL, "Set Matrix. Variable handle not found.");

	_ConstTable->SetMatrix(_mpDevice, varHdl, &_Matrix);
}