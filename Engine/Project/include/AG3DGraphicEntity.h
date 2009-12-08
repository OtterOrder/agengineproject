#pragma once

#include "AGGraphicEntity.h"
#include "AG3DEntity.h"

//------------------------------------------------------------------------------------------------------------------------------
class AG3DGraphicEntity : public AG3DEntity, public AGGraphicEntity
{
public:
	AG3DGraphicEntity	();
	~AG3DGraphicEntity	();
};