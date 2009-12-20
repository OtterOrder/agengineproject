#pragma once

#include "AGEntity.h"
#include "AGDeviceManager.h"

//------------------------------------------------------------------------------------------------------------------------------
class AG3DEntity : public AGEntity
{
public:
	DefineVectorIterator(AG3DEntity, Iterator);

private:
	AG3DEntity*	_mpParent;

protected:
	AGVector3f	_mPosition;
	AGVector3f	_mRight;
	AGVector3f	_mUp;
	AGVector3f	_mFront;

public:
	AG3DEntity	();
	~AG3DEntity	();
};