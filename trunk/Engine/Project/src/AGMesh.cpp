#include "AGMesh.h"

//------------------------------------------------------------------------------------------------------------------------------
//------------------------------------------------------------------------------------------------------------------------------
AGMesh::AGMesh()
{
	_mNbVertices = 0;
	_mNbFaces = 0;

	_mpVB = NULL;
	_mpIB = NULL;
	_mpVD = NULL;
}

//------------------------------------------------------------------------------------------------------------------------------
AGMesh::~AGMesh()
{
}

//------------------------------------------------------------------------------------------------------------------------------
AGResource::AGResourceResult AGMesh::Load (cStr _FileName, void* _Parameters)
{
	return RES_SUCCEED;
}