#pragma once
#include "AGUtilities.h"

//------------------------------------------------------------------------------------------------------------------------------
class AGEntity
{
public:
	DefineVectorIterator(AGEntity, Iterator);

private:
	cStr	_mName;

public:
	AGEntity	();
	~AGEntity	();
};