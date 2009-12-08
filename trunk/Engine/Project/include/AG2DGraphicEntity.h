#pragma once

#include "AGGraphicEntity.h"
#include "AG2DEntity.h"

//------------------------------------------------------------------------------------------------------------------------------
class AG2DGraphicEntity : public AG2DEntity, public AGGraphicEntity
{
public:
	AG2DGraphicEntity	();
	~AG2DGraphicEntity	();
};