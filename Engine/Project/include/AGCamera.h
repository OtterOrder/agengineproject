#pragma once

#include "AGEntity.h"
#include "AGDeviceManager.h"

//------------------------------------------------------------------------------------------------------------------------------
class AGCamera : virtual public AGEntity
{
public:
	DefineVectorIterator(AGCamera, Iterator);

public:
	AGMatrix	mView;
	AGMatrix	mProj;

public:
	AGCamera	();
	~AGCamera	();
};