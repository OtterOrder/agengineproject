#pragma once

#include "AG3DMaterial.h"

#include "AG3DScene.h"
#include "AG3DGraphicEntity.h"

//------------------------------------------------------------------------------------------------------------------------------
class NormalMapZMaterial : public AG3DMaterial
{
public:
					NormalMapZMaterial		();
	virtual			~NormalMapZMaterial	();

	virtual	void	Apply (AG3DScene* _pScene, AG3DGraphicEntity* _pEntity);
};