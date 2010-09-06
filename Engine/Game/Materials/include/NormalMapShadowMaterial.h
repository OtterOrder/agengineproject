#pragma once

#include "AG3DMaterial.h"

#include "AG3DScene.h"
#include "AG3DGraphicEntity.h"

//------------------------------------------------------------------------------------------------------------------------------
class NormalMapShadowMaterial : public AG3DMaterial
{
public:
					NormalMapShadowMaterial		();
	virtual			~NormalMapShadowMaterial	();

	virtual	void	Apply (AG3DScene* _pScene, AG3DGraphicEntity* _pEntity);
};