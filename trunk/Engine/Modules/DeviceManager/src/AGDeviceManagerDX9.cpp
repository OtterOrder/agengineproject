#pragma once

#include "AGDeviceManagerDX9.h"
#include "AGWindowManager.h"

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
bool AGDeviceManager::Destroy()
{
	SAFE_RELEASE(_mpDevice);
	SAFE_RELEASE(_mpD3d);

	return true;
}