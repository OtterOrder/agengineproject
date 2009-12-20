#pragma once

#include "AGResource.h"
#include "AGDeviceManager.h"

//------------------------------------------------------------------------------------------------------------------------------
class AGMesh : public AGResource
{
private:
	u32						_mNbVertices;
	u32						_mNbFaces;

	AGPVertexBuffer			_mpVB;
	AGPIndexBuffer			_mpIB;
	AGVertexElement			_mVertexElements[AGMaxDecLength];	
	AGPVertexDeclaration	_mpVD;

	u32						_mVertexSize;

public:
	AGMesh		();
	~AGMesh		();
};