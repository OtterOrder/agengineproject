#include "AGWDX9.h"

//------------------------------------------------------------------------------------------------------------------------------
bool AGLoadMeshFromX (cStr _FileName,
					  AGMesh* _pMesh,
					  u32& _NbVertices,
					  u32& _NbFaces,
					  AGPVertexBuffer& _pVB,
					  AGPIndexBuffer& _pIB,
					  AGVertexElement* _VertexElements,
					  AGPVertexDeclaration _pVD,
					  u32& _VertexSize)
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

		pMesh->GetVertexBuffer(&_pVB);
		_NbVertices = pMesh->GetNumVertices();

		pMesh->GetIndexBuffer(&_pIB);
		_NbFaces = pMesh->GetNumFaces();

		_VertexSize = pMesh->GetNumBytesPerVertex();

		pMesh->GetDeclaration(_VertexElements);
		AGDeviceManager::GetSingleton()->GetDevice()->CreateVertexDeclaration(_VertexElements, &_pVD);
	}

	SAFE_RELEASE(pMesh);

	return true;
}