#pragma once

#include "AGEntity.h"

//------------------------------------------------------------------------------------------------------------------------------
class AGGraphicEntity : virtual public AGEntity
{
public:
	DefineVectorIterator(AGGraphicEntity, Iterator);

public:
	AGGraphicEntity		();
	~AGGraphicEntity	();
};