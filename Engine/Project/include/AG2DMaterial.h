#pragma once

#include "AGMaterial.h"
#include "AG2DScene.h"

class AG2DGraphicEntity;

//------------------------------------------------------------------------------------------------------------------------------
class AG2DMaterial : public AGMaterial
{
public:
			AG2DMaterial	();
	virtual	~AG2DMaterial	();

	virtual void Apply (AG2DScene* _pScene, AG2DGraphicEntity* _pEntity);
};