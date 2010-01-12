#include "AG3DGraphicEntity.h"

//------------------------------------------------------------------------------------------------------------------------------
//------------------------------------------------------------------------------------------------------------------------------
AG3DGraphicEntity::AG3DGraphicEntity()
{
	_mpMesh		= NULL;
	_mpMaterial	= NULL;
}

//------------------------------------------------------------------------------------------------------------------------------
AG3DGraphicEntity::~AG3DGraphicEntity()
{
	SAFE_DECREF(_mpMesh);
	SAFE_DELETE(_mpMaterial);
}

//------------------------------------------------------------------------------------------------------------------------------
//------------------------------------------------------------------------------------------------------------------------------
void AG3DGraphicEntity::Update ()
{
}

//------------------------------------------------------------------------------------------------------------------------------
void AG3DGraphicEntity::Draw (CFirstPersonCamera* _pCamera)	////.
{
	_mpMaterial->Apply();

	//_mpMaterial->GetVertexShader()->SetMatrix("g_mWorldViewProjection", mWorld * _pCamera->mView * _pCamera->mProj);

	AGMatrix viewProj;
	AGMatrixMultiply(&viewProj, _pCamera->GetViewMatrix(), _pCamera->GetProjMatrix());
	_mpMaterial->GetVertexShader()->SetMatrix("g_mWorldViewProjection", viewProj);

	_mpMesh->Draw();
}