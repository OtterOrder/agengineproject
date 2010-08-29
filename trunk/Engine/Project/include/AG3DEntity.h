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
	AGMatrix	_mWorld;

public:
	AGVector3f	mPosition;

public:
			AG3DEntity	();
			~AG3DEntity	();

	virtual	void	Update ();
};