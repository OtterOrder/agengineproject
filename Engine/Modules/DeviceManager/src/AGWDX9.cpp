#include "AGWDX9.h"

//------------------------------------------------------------------------------------------------------------------------------
//------------------------------------------------------------------------------------------------------------------------------
bool AGLoadMeshFromX (cStr _FileName,
					  AGMesh* _pMesh,
					  u32& _NbVertices,
					  u32& _NbFaces,
					  AGPVertexBuffer& _pVB,
					  AGPIndexBuffer& _pIB,
					  AGVertexElement* _VertexElements,
					  AGPVertexDeclaration& _pVD,
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

//------------------------------------------------------------------------------------------------------------------------------
bool AGLoadVertexShader (cStr _FileName, cStr _EntryPoint, AGPVertexShader& _VertexShader, AGPConstantTable& _ConstantTable)
{
	LPD3DXBUFFER pErrorBuffer = NULL;
	LPD3DXBUFFER pShaderCode = NULL;

	if ( FAILED(D3DXCompileShaderFromFile(_FileName, NULL, NULL, _EntryPoint, "vs_3_0", 0, &pShaderCode, &pErrorBuffer, &_ConstantTable) ))
	{
		OutputDebugString(reinterpret_cast <char*> (pErrorBuffer->GetBufferPointer()));
		MessageBox (NULL, "Vertex Shader compilation Error", "Shader Error", MB_OK);

		return false;
	}

	if (FAILED(AGDeviceManager::GetSingleton()->GetDevice()->CreateVertexShader( (DWORD*)pShaderCode->GetBufferPointer(), &_VertexShader )))
	{
		OutputDebugString(reinterpret_cast <char*> (pErrorBuffer->GetBufferPointer()));

		return false;
	}

	SAFE_RELEASE(pErrorBuffer);
	SAFE_RELEASE(pShaderCode);

	return true;
}

//------------------------------------------------------------------------------------------------------------------------------
bool AGLoadPixelShader (cStr _FileName, cStr _EntryPoint, AGPPixelShader& _PixelShader, AGPConstantTable& _ConstantTable)
{
	LPD3DXBUFFER pErrorBuffer = NULL;
	LPD3DXBUFFER pShaderCode = NULL;

	if ( FAILED(D3DXCompileShaderFromFile(_FileName, NULL, NULL, _EntryPoint, "ps_3_0", 0, &pShaderCode, &pErrorBuffer, &_ConstantTable) ))
	{
		OutputDebugString(reinterpret_cast <char*> (pErrorBuffer->GetBufferPointer()));
		MessageBox (NULL, "Pixel Shader compilation Error", "Shader Error", MB_OK);

		return false;
	}

	if (FAILED(AGDeviceManager::GetSingleton()->GetDevice()->CreatePixelShader( (DWORD*)pShaderCode->GetBufferPointer(), &_PixelShader )))
	{
		OutputDebugString(reinterpret_cast <char*> (pErrorBuffer->GetBufferPointer()));

		return false;
	}

	SAFE_RELEASE(pErrorBuffer);
	SAFE_RELEASE(pShaderCode);

	return true;
}

//------------------------------------------------------------------------------------------------------------------------------
bool AGLoadTexture (cStr _FileName, AGPTexture& _PTexture, AGImageInfo& _TextureInfo)
{
	if( FAILED( D3DXCreateTextureFromFileEx(AGDeviceManager::GetSingleton()->GetDevice(),
											_FileName,
											D3DX_DEFAULT,
											D3DX_DEFAULT,
											D3DX_DEFAULT,
											0,
											D3DFMT_A8R8G8B8,
											D3DPOOL_MANAGED,
											D3DX_DEFAULT,
											D3DX_DEFAULT,
											0,
											&_TextureInfo,
											NULL,
											&_PTexture ) ) )
	{
		_PTexture = NULL;
		return false;
	}

	return true;
}

//------------------------------------------------------------------------------------------------------------------------------
bool AGLoadTextureCube (cStr _FileName, AGPTextureCube& _PTexture, AGImageInfo& _TextureInfo)
{
	if( FAILED( D3DXCreateCubeTextureFromFile(AGDeviceManager::GetSingleton()->GetDevice(),
		_FileName,
		&_PTexture ) ) )
	{
		_PTexture = NULL;
		return false;
	}

	return true;
}