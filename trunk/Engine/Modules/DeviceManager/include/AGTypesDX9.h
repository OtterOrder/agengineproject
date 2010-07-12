#pragma once

#include "AGTypes.h"

#include <d3d9.h>
#include <d3dx9.h>

//------------------------------------------------------------------------------------------------------------------------------
// Defines
#define		AGCLEAR_TARGET					D3DCLEAR_TARGET
#define		AGCLEAR_ZBUFFER					D3DCLEAR_ZBUFFER
#define		AGCOLOR_XRGB					D3DCOLOR_XRGB

//--------------------------------------------------------------
#define		AGDegToRad						D3DXToRadian

//------------------------------------------------------------------------------------------------------------------------------
typedef		LPDIRECT3D9						AGPD3D;
typedef		LPDIRECT3DDEVICE9				AGPDevice;

//--------------------------------------------------------------
typedef		LPDIRECT3DVERTEXBUFFER9			AGPVertexBuffer;
typedef		LPDIRECT3DINDEXBUFFER9			AGPIndexBuffer;
typedef		LPDIRECT3DVERTEXDECLARATION9	AGPVertexDeclaration;
typedef		D3DVERTEXELEMENT9				AGVertexElement;
#define		AGMaxDecLength					MAXD3DDECLLENGTH

//--------------------------------------------------------------
typedef		LPDIRECT3DVERTEXSHADER9			AGPVertexShader;
typedef		LPDIRECT3DPIXELSHADER9			AGPPixelShader;
typedef		LPD3DXCONSTANTTABLE				AGPConstantTable;
typedef		D3DXCONSTANT_DESC				AGConstantDesc;
typedef		D3DXHANDLE						AGHandle;

//--------------------------------------------------------------
typedef		LPDIRECT3DTEXTURE9				AGPtexture;
typedef		LPDIRECT3DSURFACE9				AGPSurface;
typedef		D3DXIMAGE_INFO					AGImageInfo;
typedef		D3DFORMAT						AGFormat;

//--------------------------------------------------------------
typedef		D3DXMATRIX						AGMatrix;
#define 	AGMatrixIdentity				D3DXMatrixIdentity
#define 	AGMatrixMultiply				D3DXMatrixMultiply
#define		AGMatrixInverse					D3DXMatrixInverse
#define		AGMatrixTranspose				D3DXMatrixTranspose

#define		AGMatrixTranslation				D3DXMatrixTranslation

#define		AGMatrixRotationX				D3DXMatrixRotationX
#define		AGMatrixRotationY				D3DXMatrixRotationY
#define		AGMatrixRotationZ				D3DXMatrixRotationZ

#define		AGMatrixPerspectiveFovLH		D3DXMatrixPerspectiveFovLH

//------------------------------------------------------------------------------------------------------------------------------
typedef		D3DXVECTOR2				AGVector2f;
typedef		D3DXVECTOR3				AGVector3f;
typedef		D3DXVECTOR4				AGVector4f;

#define		AGVector3fToColor(vect)		D3DCOLOR_RGBA( (int)(vect.x*255.f), (int)(vect.y*255.f), (int)(vect.z*255.f), 255 )