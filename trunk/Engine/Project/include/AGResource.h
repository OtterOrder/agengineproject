#pragma once
#include "AGUtilities.h"

//------------------------------------------------------------------------------------------------------------------------------
class AGResource
{
private:
	cStr	_mName;
	u32		_mRefCount;

public:
			AGResource	();
	virtual	~AGResource	();

	inline	void	AddRef()	{ ++_mRefCount; };
			bool	Release();						// Return true if the resource is deleted

	inline const cStr& GetName() const		{ return _mName; };
};