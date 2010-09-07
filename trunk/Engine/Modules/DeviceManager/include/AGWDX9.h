#pragma once

#ifdef UNICODE
	#undef UNICODE
#endif

#include "AGDeviceManagerDX9.h"
#include <d3dx9.h>

class AGMesh;

//------------------------------------------------------------------------------------------------------------------------------
bool AGLoadMeshFromX		(cStr _FileName,
							 AGMesh* _pMesh,
							 u32& _NbVertices,
							 u32& _NbFaces,
							 AGPVertexBuffer& _pVB,
							 AGPIndexBuffer& _pIB,
							 AGVertexElement* _VertexElements,
							 AGPVertexDeclaration& _pVD,
							 u32& _VertexSize);

//------------------------------------------------------------------------------------------------------------------------------
bool AGLoadVertexShader		(cStr _FileName, cStr _EntryPoint, AGPVertexShader& _VertexShader, AGPConstantTable& _ConstantTable);

//------------------------------------------------------------------------------------------------------------------------------
bool AGLoadPixelShader		(cStr _FileName, cStr _EntryPoint, AGPPixelShader& _PixelShader, AGPConstantTable& _ConstantTable);

//------------------------------------------------------------------------------------------------------------------------------
bool AGLoadTexture			(cStr _FileName, AGPTexture& _PTexture, AGImageInfo& _TextureInfo);

//------------------------------------------------------------------------------------------------------------------------------
bool AGLoadTextureCube (cStr _FileName, AGPTextureCube& _PTexture, AGImageInfo& _TextureInfo);

//------------------------------------------------------------------------------------------------------------------------------
bool AGCreateTextureCube (AGPTextureCube* _PTexture, UINT _Size);

//------------------------------------------------------------------------------------------------------------------------------
bool AGCreateVertexBuffer (UINT _Lenght, DWORD _FVF, AGPVertexBuffer& _VertexBuffer);

//------------------------------------------------------------------------------------------------------------------------------
bool AGLockVertexBuffer (UINT _Offset, AGPVertexBuffer _VertexBuffer, UINT _SizeToLock, void** _Data);

//------------------------------------------------------------------------------------------------------------------------------
bool AGUnlockVertexBuffer (AGPVertexBuffer _VertexBuffer);

//------------------------------------------------------------------------------------------------------------------------------
bool AGDrawVertexBuffer (UINT _Lenght, DWORD _FVF, AGPVertexBuffer& _VertexBuffer, UINT _StartVertex, UINT _PrimitiveCount);

//------------------------------------------------------------------------------------------------------------------------------
bool AGCreateRenderTarget	(AGVector2u _Size, AGTextureFormat _Format,AGPTexture& _PTexture);

//------------------------------------------------------------------------------------------------------------------------------
bool AGCreateStencilSurface (AGVector2u _Size, AGTextureFormat _Format, AGPSurface& _PSurface);

//------------------------------------------------------------------------------------------------------------------------------
bool AGSHProjectCubeMap (UINT _Order, AGPTextureCube& _PTexture, float* _pROut, float* _pGOut, float* _pBOut);
