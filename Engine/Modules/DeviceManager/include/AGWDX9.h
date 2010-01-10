#pragma once

#include "AGDeviceManager.h"
#include <d3dx9.h>


//------------------------------------------------------------------------------------------------------------------------------
bool AGLoadMeshFromX (cStr _FileName, AGMesh* _pMesh)
{
	HRESULT result;

	LPD3DXMESH pMesh = NULL;

	result = D3DXLoadMeshFromX( _FileName,
		D3DXMESH_MANAGED,
		AGDeviceManager::GetSingleton()->GetDevice(),
		NULL,				// Adjacency
		NULL,				// Materials
		NULL,				// EffectInstances
		NULL,				// NumMaterials
		&pMesh );			// Mesh

	if( SUCCEEDED(result) )
	{
		_pMesh->Release ();

		//create a new vertex declaration
		AGVertexElement vertDecl[] = 
		{
			{ 0, 0,  D3DDECLTYPE_FLOAT3, D3DDECLMETHOD_DEFAULT, D3DDECLUSAGE_POSITION, 0 },
			{ 0, 12, D3DDECLTYPE_FLOAT3, D3DDECLMETHOD_DEFAULT, D3DDECLUSAGE_NORMAL,   0 },
			{ 0, 24, D3DDECLTYPE_FLOAT2, D3DDECLMETHOD_DEFAULT, D3DDECLUSAGE_TEXCOORD, 0 },
			{ 0, 32, D3DDECLTYPE_FLOAT3, D3DDECLMETHOD_DEFAULT, D3DDECLUSAGE_TANGENT,  0 },
			{ 0, 44, D3DDECLTYPE_FLOAT3, D3DDECLMETHOD_DEFAULT, D3DDECLUSAGE_BINORMAL, 0 },
			D3DDECL_END()
		};

		LPD3DXMESH pMeshTemp = pMesh;
		pMesh = NULL;
		pMeshTemp->CloneMesh(D3DXMESH_VB_MANAGED, vertDecl, AGDeviceManager::GetSingleton()->GetDevice(), &pMesh);

		SAFE_RELEASE(pMeshTemp);
		pMeshTemp = pMesh;
		pMesh = NULL;

		D3DXComputeTangentFrameEx(	pMeshTemp, D3DDECLUSAGE_TEXCOORD, 0, D3DDECLUSAGE_TANGENT, 0,
			D3DX_DEFAULT, 0, D3DDECLUSAGE_NORMAL, 0,
			D3DXTANGENT_CALCULATE_NORMALS,
			NULL, -1, 0, -1, &pMesh, NULL );

		SAFE_RELEASE(pMeshTemp);

		pMesh->GetVertexBuffer(&_pMesh->_mpVB);
		_pMesh->_mNbVertices = pMesh->GetNumVertices();

		pMesh->GetIndexBuffer(&_pMesh->_mpIB);
		_pMesh->_mNbFaces = pMesh->GetNumFaces();

		_pMesh->_mVertexSize = pMesh->GetNumBytesPerVertex();

		pMesh->GetDeclaration(_pMesh->_mVertexElements);
		AGDeviceManager::GetSingleton()->GetDevice()->CreateVertexDeclaration(_pMesh->_mVertexElements, &_pMesh->_mpVD);
	}

	SAFE_RELEASE(pMesh);

	return true;
}