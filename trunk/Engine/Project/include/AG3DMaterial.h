#pragma once

#include "AGMaterial.h"

class AG3DScene;
class AG3DGraphicEntity;

//------------------------------------------------------------------------------------------------------------------------------
class AG3DMaterial : public AGMaterial
{
public:
					AG3DMaterial	();
	virtual			~AG3DMaterial	();

	virtual	void	Apply (AG3DScene* _pScene, AG3DGraphicEntity* _pEntity);
};