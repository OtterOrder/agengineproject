#pragma once

#include "AG3DMaterial.h"

//------------------------------------------------------------------------------------------------------------------------------
class AG3DDefaultMaterial : public AG3DMaterial
{
public:
					AG3DDefaultMaterial		();
	virtual			~AG3DDefaultMaterial	();

	virtual	void	Apply (AG3DScene* _pScene, AG3DGraphicEntity* _pEntity);
};