#pragma once

#include "AGTexture.h"
#include "AG3DMaterial.h"

#include "AG3DScene.h"
#include "AG3DGraphicEntity.h"

//------------------------------------------------------------------------------------------------------------------------------
class NormalMapMaterial : public AG3DMaterial
{
private:
	AGTexture*		_mpDiffuseTex;
	AGTexture*		_mpNormalTex;
	AGTexture*		_mpSpecularTex;

public:
	float			mBumpCoef;

public:
	NormalMapMaterial		();
	virtual			~NormalMapMaterial	();

	virtual	void	Apply (AG3DScene* _pScene, AG3DGraphicEntity* _pEntity);

	void	SetDiffuse	(cStr _FileName);
	void	SetNormal	(cStr _FileName);
	void	SetSpecular	(cStr _FileName);
};