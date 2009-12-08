#pragma once

#include "AGEntity.h"

//------------------------------------------------------------------------------------------------------------------------------
class AG2DEntity : public AGEntity
{
public:
	DefineVectorIterator(AG2DEntity, Iterator);

private:
	AG2DEntity*	_mParent;

public:
	AG2DEntity	();
	~AG2DEntity	();
};