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

public:
	AGVector3f	mPosition;
	AGVector3f	mOrientation;
	AGVector3f	mScale;

	AGMatrix	mWorld;

public:
	AG3DEntity	();
	~AG3DEntity	();

	void	Update ();
};