#pragma once

#include "AGDeviceManager.h"
#include <d3dx9.h>

#include "AGMesh.h"

//------------------------------------------------------------------------------------------------------------------------------
bool AGLoadMeshFromX (cStr _FileName,
					  AGMesh* _pMesh,
					  u32& _NbVertices,
					  u32& _NbFaces,
					  AGPVertexBuffer& _pVB,
					  AGPIndexBuffer& _pIB,
					  AGVertexElement* _VertexElements,
					  AGPVertexDeclaration& _pVD,
					  u32& _VertexSize);

//------------------------------------------------------------------------------------------------------------------------------
bool AGLoadVertexShader (cStr _FileName, cStr _EntryPoint, AGPVertexShader& _VertexShader, AGPConstantTable& _ConstantTable);

//------------------------------------------------------------------------------------------------------------------------------
bool AGLoadPixelShader (cStr _FileName, cStr _EntryPoint, AGPPixelShader& _PixelShader, AGPConstantTable& _ConstantTable);

//------------------------------------------------------------------------------------------------------------------------------
bool AGLoadTexture (cStr _FileName, AGPTexture& _PTexture, AGImageInfo& _TextureInfo);

//------------------------------------------------------------------------------------------------------------------------------
bool AGLoadTextureCube (cStr _FileName, AGPTextureCube& _PTexture, AGImageInfo& _TextureInfo);

//------------------------------------------------------------------------------------------------------------------------------
bool AGCreateVertexBuffer (UINT _Lenght, DWORD _FVF, AGPVertexBuffer& _VertexBuffer);

//------------------------------------------------------------------------------------------------------------------------------
bool AGLockVertexBuffer (UINT _Offset, AGPVertexBuffer _VertexBuffer, UINT _SizeToLock, void** _Data);

//------------------------------------------------------------------------------------------------------------------------------
bool AGUnlockVertexBuffer (AGPVertexBuffer _VertexBuffer);

//------------------------------------------------------------------------------------------------------------------------------
bool AGDrawVertexBuffer (UINT _Lenght, DWORD _FVF, AGPVertexBuffer& _VertexBuffer, UINT _StartVertex, UINT _PrimitiveCount);