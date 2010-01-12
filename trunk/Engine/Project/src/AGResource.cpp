#include "AGResource.h"

//------------------------------------------------------------------------------------------------------------------------------
//------------------------------------------------------------------------------------------------------------------------------
AGResource::AGResource()
{
	_mRefCount = 0;
	_mName = "";
}

//------------------------------------------------------------------------------------------------------------------------------
AGResource::~AGResource()
{
	Release ();
}

//------------------------------------------------------------------------------------------------------------------------------
//------------------------------------------------------------------------------------------------------------------------------
u32 AGResource::DecRefCount()
{
	--_mRefCount;

	if(_mRefCount<=0)
		delete this;

	return _mRefCount;
}

void AGResource::SetName(cStr _Name)
{
	AGWarning(_mName != "", "Resource name already setted. \"%s\"", _mName);

	_mName = _Name;
}