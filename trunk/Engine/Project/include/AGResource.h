#pragma once

#include "AGUtilities.h"
#include "AGDeviceManager.h"

//------------------------------------------------------------------------------------------------------------------------------
class AGResource
{
public:
	enum AGResourceResult
	{
		RES_SUCCEED,
		RES_FAILED
	};

private:
	cStr	_mName;
	u32		_mRefCount;

public:
			AGResource	();
	virtual	~AGResource	();

	inline	void	IncRefCount ()	{ ++_mRefCount; };
			u32		DecRefCount ();						// Return the remaining number of references
	inline	u32		GetRefCount ()	{ return _mRefCount; };

	virtual AGResourceResult	Load (cStr _FileName, void* _Parameters = NULL) =0;
	virtual	void				Release	()		{ _mName = ""; _mRefCount = 0; };

	inline const cStr&	GetName () const		{ return _mName; };
	void				SetName (cStr _Name);
};