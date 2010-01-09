#pragma once

#include "AGUtilities.h"
#include "AGDeviceManager.h"

//------------------------------------------------------------------------------------------------------------------------------
class AGResource
{
private:
	cStr	_mName;
	u32		_mRefCount;

public:
			AGResource	();
	virtual	~AGResource	();

	inline	void	IncRefCount()	{ ++_mRefCount; };
			u32		DecRefCount();						// Return the remaining number of references
	inline	u32		GetRefCount()	{ return _mRefCount; };

	virtual	void	Release	() =0;

	inline const cStr& GetName() const		{ return _mName; };
};