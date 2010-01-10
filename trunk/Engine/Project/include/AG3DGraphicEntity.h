#pragma once

#include "AGGraphicEntity.h"
#include "AG3DEntity.h"

#include "AGMesh.h"
#include "AGMaterial.h"

//------------------------------------------------------------------------------------------------------------------------------
class AG3DGraphicEntity : public AG3DEntity, public AGGraphicEntity
{
private:
	AGMesh*		_mpMesh;
	AGMaterial*	_mpMaterial;

public:
	AG3DGraphicEntity	();
	~AG3DGraphicEntity	();
};