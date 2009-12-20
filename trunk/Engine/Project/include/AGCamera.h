#pragma once

#include "AGEntity.h"
#include "AGDeviceManager.h"

//------------------------------------------------------------------------------------------------------------------------------
class AGCamera : virtual public AGEntity
{
public:
	DefineVectorIterator(AGCamera, Iterator);

protected:
	AGMatrix	_mView;
	AGMatrix	_mProj;

public:
	AGCamera	();
	~AGCamera	();

	inline const AGMatrix*		GetView()	{ return &_mView; };
	inline const AGMatrix*		GetProj()	{ return &_mProj; };
};