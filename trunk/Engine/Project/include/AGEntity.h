#pragma once
#include "AGUtilities.h"

#include "AGDeviceManager.h"

//------------------------------------------------------------------------------------------------------------------------------
class AGEntity
{
public:
	DefineVectorIterator(AGEntity, Iterator);

private:
	cStr	_mName;

public:
	AGEntity	();
	virtual ~AGEntity	();

	virtual void	Update () =0;
};