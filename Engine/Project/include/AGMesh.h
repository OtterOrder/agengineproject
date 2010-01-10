#pragma once

#include "AGResource.h"

//------------------------------------------------------------------------------------------------------------------------------
class AGMesh : public AGResource
{
public:
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

	AGResourceResult	Load (cStr _FileName, void* _Parameters = NULL);
	void				Release ();
};