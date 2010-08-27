#pragma once

#include "AGUtilities.h"

//------------------------------------------------------------------------------------------------------------------------------
class AGInputs
{
public:
	DefineVectorIterator(AGInputs, Iterator);

private:

public:
	AGInputs	();
	virtual ~AGInputs	();

	virtual void	Update () =0;
};