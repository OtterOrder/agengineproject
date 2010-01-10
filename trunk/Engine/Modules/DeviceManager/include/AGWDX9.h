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
					  AGPVertexDeclaration _pVD,
					  u32& _VertexSize);