#pragma once

#include "AGEntity.h"

//------------------------------------------------------------------------------------------------------------------------------
class AG3DEntity : public AGEntity
{
public:
	DefineVectorIterator(AG3DEntity, Iterator);

private:
	AG3DEntity*	_mParent;

public:
	AG3DEntity	();
	~AG3DEntity	();
};