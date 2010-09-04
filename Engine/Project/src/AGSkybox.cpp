#include "AGSkybox.h"

#include "AGUtilities.h"
#include "AGWDX9.h"

struct SKYBOX_VERTEX
{
	FLOAT x,y,z;
};
#define SKYBOX_FVF (AGFVF_XYZ)

//------------------------------------------------------------------------------------------------------------------------------
//------------------------------------------------------------------------------------------------------------------------------
AGSkybox::AGSkybox()
: AG3DGraphicEntity ()
{
	_mpCubeTex = NULL;
	_mpSizeVB = 1.0f;

	SKYBOX_VERTEX sommets[24]=
	{
		// Front quad, NOTE: All quads face inward
		{-_mpSizeVB, -_mpSizeVB,  _mpSizeVB},
		{-_mpSizeVB,  _mpSizeVB,  _mpSizeVB},
		{ _mpSizeVB, -_mpSizeVB,  _mpSizeVB},
		{ _mpSizeVB,  _mpSizeVB,  _mpSizeVB},

		// Back quad
		{ _mpSizeVB, -_mpSizeVB, -_mpSizeVB},
		{ _mpSizeVB,  _mpSizeVB, -_mpSizeVB},
		{-_mpSizeVB, -_mpSizeVB, -_mpSizeVB},
		{-_mpSizeVB,  _mpSizeVB, -_mpSizeVB},

		// Left quad
		{-_mpSizeVB, -_mpSizeVB, -_mpSizeVB},
		{-_mpSizeVB,  _mpSizeVB, -_mpSizeVB},
		{-_mpSizeVB, -_mpSizeVB,  _mpSizeVB},
		{-_mpSizeVB,  _mpSizeVB,  _mpSizeVB},

		// Right quad
		{ _mpSizeVB, -_mpSizeVB,  _mpSizeVB},
		{ _mpSizeVB,  _mpSizeVB,  _mpSizeVB},
		{ _mpSizeVB, -_mpSizeVB, -_mpSizeVB},
		{ _mpSizeVB,  _mpSizeVB, -_mpSizeVB},

		// Top quad
		{-_mpSizeVB,  _mpSizeVB,  _mpSizeVB},
		{-_mpSizeVB,  _mpSizeVB, -_mpSizeVB},
		{ _mpSizeVB,  _mpSizeVB,  _mpSizeVB},
		{ _mpSizeVB,  _mpSizeVB, -_mpSizeVB},

		// Bottom quad
		{-_mpSizeVB, -_mpSizeVB, -_mpSizeVB},
		{-_mpSizeVB, -_mpSizeVB,  _mpSizeVB},
		{ _mpSizeVB, -_mpSizeVB, -_mpSizeVB},
		{ _mpSizeVB, -_mpSizeVB,  _mpSizeVB}


	};

	AGCreateVertexBuffer(sizeof(sommets), SKYBOX_FVF, _mpSkyVB);

	void * psommets;

	AGLockVertexBuffer(0, _mpSkyVB, sizeof(sommets), (void **)&psommets);

	memcpy(psommets,sommets,sizeof(sommets));

	AGUnlockVertexBuffer(_mpSkyVB);
}

//------------------------------------------------------------------------------------------------------------------------------
AGSkybox::~AGSkybox()
{
}

//------------------------------------------------------------------------------------------------------------------------------
//------------------------------------------------------------------------------------------------------------------------------
void AGSkybox::Update()
{
	AG3DGraphicEntity::Update();	
}

//------------------------------------------------------------------------------------------------------------------------------
void AGSkybox::Draw (CFirstPersonCamera* _pCamera, AG3DScene* _pScene)	////.
{
	_mpMaterial->Activate();
	_mpMaterial->Apply(_pScene, this);

	AGMatrix viewProj;
	AGMatrixMultiply(&viewProj, &_mWorld,  _pCamera->GetViewMatrix());
	AGMatrixMultiply(&viewProj, &viewProj, _pCamera->GetProjMatrix());
	_mpMaterial->GetVertexShader()->SetMatrix("g_mWorldViewProjection", viewProj);

	for ( ULONG i = 0; i < 6; ++i )
	{
		AGDrawVertexBuffer(sizeof(SKYBOX_VERTEX), SKYBOX_FVF, _mpSkyVB, i * 4, 2 );
	}
}

//------------------------------------------------------------------------------------------------------------------------------
void AGSkybox::SetTexture (cStr _FileName)
{
	SAFE_DECREF(_mpCubeTex);
	_mpCubeTex = AGResourceManager::GetSingleton()->Load<AGTextureCube>(_FileName);
}



