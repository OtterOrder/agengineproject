#include "AG3DGraphicEntity.h"

#include "AG3DScene.h"
#include "AG3DCamera.h"

//------------------------------------------------------------------------------------------------------------------------------
//------------------------------------------------------------------------------------------------------------------------------
AG3DGraphicEntity::AG3DGraphicEntity()
{
	_mpMesh			= NULL;
	_mpMaterial		= NULL;

	////.
	_mpZMaterial		= NULL;
	_mpShadowMaterial	= NULL;
	////.

	mShadowed		= false;	////.
	mScale		= AGVector3f(1.f, 1.f, 1.f);
}

//------------------------------------------------------------------------------------------------------------------------------
AG3DGraphicEntity::~AG3DGraphicEntity()
{
	SAFE_DECREF(_mpMesh);
	SAFE_DELETE(_mpMaterial);

	////.
	SAFE_DELETE(_mpZMaterial);
	SAFE_DELETE(_mpShadowMaterial);
	////.
}

//------------------------------------------------------------------------------------------------------------------------------
//------------------------------------------------------------------------------------------------------------------------------
void AG3DGraphicEntity::Update ()
{
	AG3DEntity::Update();
	AGMatrix Scale;
	AGMatrixScaling(&Scale, mScale.x, mScale.y, mScale.z);
	AGMatrixMultiply(&_mWorld, &_mWorld, &Scale);
}

//------------------------------------------------------------------------------------------------------------------------------
void AG3DGraphicEntity::Draw (CFirstPersonCamera* _pCamera, AG3DScene* _pScene)	////.
{
	_pScene->Get3DCamera()->mPosition = *(_pCamera->GetEyePt());	////.

	_mpMaterial->Activate();
	_mpMaterial->Apply(_pScene, this);

	////.
	AGMatrix viewProj;
	AGMatrixMultiply(&viewProj, _pCamera->GetViewMatrix(), _pCamera->GetProjMatrix());
	AGMatrixMultiply(&viewProj, &_mWorld, &viewProj);
	_mpMaterial->GetVertexShader()->SetMatrix("g_mWorldViewProjection", viewProj);
	////.

	_mpMesh->Draw();
}

//------------------------------------------------------------------------------------------------------------------------------
void AG3DGraphicEntity::DrawZ (AGMatrix& _ViewMatrix, AGMatrix& _ProjMatrix, AGMatrix& _ViewProjMatrix)
{
	_mpZMaterial->Activate();
	_mpZMaterial->Apply(NULL, this);

	////.
	AGMatrix viewProj;
	AGMatrixMultiply(&viewProj, &_ViewMatrix, &_ProjMatrix);
	AGMatrixMultiply(&viewProj, &_mWorld, &viewProj);
	_mpZMaterial->GetVertexShader()->SetMatrix("g_mWorldViewProjection", viewProj);
	////.

	_mpMesh->Draw();
}

//------------------------------------------------------------------------------------------------------------------------------
void AG3DGraphicEntity::DrawShadow (CFirstPersonCamera* _pCamera, AGMatrix& _LightViewProjMatrix, AGPTexture& _ShadowMap)
{
	_mpShadowMaterial->Activate();
	_mpShadowMaterial->Apply(NULL, this);

	////.
	AGMatrix viewProj;
	AGMatrixMultiply(&viewProj, _pCamera->GetViewMatrix(), _pCamera->GetProjMatrix());
	AGMatrixMultiply(&viewProj, &_mWorld, &viewProj);
	_mpShadowMaterial->GetVertexShader()->SetMatrix("g_mWorldViewProjection", viewProj);
	_mpShadowMaterial->GetVertexShader()->SetMatrix("gWorld", _mWorld);
	_mpShadowMaterial->GetVertexShader()->SetMatrix("gLightViewProj", _LightViewProjMatrix);
	AGSamplerState SampState (AGSamplerState::Point, AGSamplerState::Point);
	_mpShadowMaterial->GetPixelShader()->SetTexture("gShadowMap", _ShadowMap, &SampState);
	////.

	_mpMesh->Draw();

	////.
	_mpShadowMaterial->GetPixelShader()->SetTexture("gShadowMap", NULL, &SampState);
	////.
}