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
	AG3DEntity::Update();
}

//------------------------------------------------------------------------------------------------------------------------------
void AG3DGraphicEntity::Draw (CFirstPersonCamera* _pCamera, AG3DScene* _pScene)	////.
{
	_mpMaterial->Activate();

	//_mpMaterial->GetVertexShader()->SetMatrix("g_mWorldViewProjection", mWorld * _pCamera->mView * _pCamera->mProj);
	_mpMaterial->Apply(_pScene, this);

	AGMatrix viewProj;
	AGMatrixMultiply(&viewProj, &_mWorld,  _pCamera->GetViewMatrix());
	AGMatrixMultiply(&viewProj, &viewProj, _pCamera->GetProjMatrix());
	_mpMaterial->GetVertexShader()->SetMatrix("g_mWorldViewProjection", viewProj);

	_mpMesh->Draw();
}