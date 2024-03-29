#include "AGWDX9.h"

#include "AGMesh.h"

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
		HRESULT hr = pMeshTemp->CloneMesh(D3DXMESH_VB_MANAGED, vertDecl, AGDeviceManager::GetSingleton()->GetDevice(), &pMesh);

		SAFE_RELEASE(pMeshTemp);
		pMeshTemp = pMesh;
		pMesh = NULL;

		HRESULT hr2 = D3DXComputeTangentFrameEx(	pMeshTemp, D3DDECLUSAGE_TEXCOORD, 0, D3DDECLUSAGE_TANGENT, 0,
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

//------------------------------------------------------------------------------------------------------------------------------
bool AGCreateTextureCube (AGPTextureCube* _PTexture, UINT _Size)
{
	if( FAILED( D3DXCreateCubeTexture( AGDeviceManager::GetSingleton()->GetDevice(), _Size, 1, 0, D3DFMT_A16B16G16R16F, D3DPOOL_MANAGED, _PTexture )))
		return false;

	return true;
}

//------------------------------------------------------------------------------------------------------------------------------
bool AGCreateVertexBuffer (UINT _Lenght, DWORD _FVF, AGPVertexBuffer& _VertexBuffer)
{
	if( FAILED( AGDeviceManager::GetSingleton()->GetDevice()->CreateVertexBuffer(
		_Lenght,
		D3DUSAGE_WRITEONLY,
		_FVF,
		D3DPOOL_DEFAULT,
		&_VertexBuffer,
		NULL)
		) )
	{
		_VertexBuffer = NULL;
		return false;
	}

	return true;
}

//------------------------------------------------------------------------------------------------------------------------------
bool AGLockVertexBuffer (UINT _Offset, AGPVertexBuffer _VertexBuffer, UINT _SizeToLock, void** _Data)
{
	if( FAILED(_VertexBuffer->Lock(_Offset, _SizeToLock, _Data, 0)))
		return false;

	return true;
}

//------------------------------------------------------------------------------------------------------------------------------
bool AGUnlockVertexBuffer (AGPVertexBuffer _VertexBuffer)
{
	if( FAILED(_VertexBuffer->Unlock()))
		return false;

	return true;
}

//------------------------------------------------------------------------------------------------------------------------------
bool AGDrawVertexBuffer (UINT _Lenght, DWORD _FVF, AGPVertexBuffer& _VertexBuffer, UINT _StartVertex, UINT _PrimitiveCount)
{
	AGDeviceManager::GetSingleton()->GetDevice()->SetFVF(_FVF);

	AGDeviceManager::GetSingleton()->GetDevice()->SetStreamSource(0, _VertexBuffer, 0, _Lenght);

	AGDeviceManager::GetSingleton()->GetDevice()->DrawPrimitive( D3DPT_TRIANGLESTRIP, _StartVertex, _PrimitiveCount );

	return true;
}

//------------------------------------------------------------------------------------------------------------------------------
bool AGCreateRenderTarget	(AGVector2u _Size, AGTextureFormat _Format,AGPTexture& _PTexture)
{
	if( FAILED( D3DXCreateTexture(	AGDeviceManager::GetSingleton()->GetDevice(),
									_Size.x,
									_Size.y,
									1,
									D3DUSAGE_RENDERTARGET,
									(D3DFORMAT)_Format,
									D3DPOOL_DEFAULT,
									&_PTexture ) ) )
	{
		_PTexture = NULL;
		return false;
	}

	return true;
}

//------------------------------------------------------------------------------------------------------------------------------
bool AGCreateStencilSurface(AGVector2u _Size, AGTextureFormat _Format, AGPSurface& _PSurface)
{
	if( FAILED( AGDeviceManager::GetSingleton()->GetDevice()->CreateDepthStencilSurface(
					_Size.x,
					_Size.y,
					(D3DFORMAT)_Format,
					D3DMULTISAMPLE_NONE,
					0,
					TRUE,
					&_PSurface,
					NULL) ) )
	{
		_PSurface = NULL;
		return false;
	}

	return true;
}

//------------------------------------------------------------------------------------------------------------------------------
bool AGSHProjectCubeMap (UINT _Order, AGPTextureCube& _PTexture, float* _pROut, float* _pGOut, float* _pBOut)
{
	if( FAILED(D3DXSHProjectCubeMap( _Order, _PTexture, _pROut,_pGOut, _pBOut)))
		return false;

	return true;
}

//------------------------------------------------------------------------------------------------------------------------------
bool AGFillCubeTexture (AGPTextureCube _PTexture, AGFill3D _PFunction, LPVOID _Data)
{
	if( FAILED(D3DXFillCubeTexture(_PTexture,_PFunction,_Data)))
		return false;
	return true;
}
