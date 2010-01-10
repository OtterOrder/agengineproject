#pragma once

#include "AGTypesDX9.h"
#include "AGSingleton.h"

//------------------------------------------------------------------------------------------------------------------------------
class AGDeviceManager : public AGSingleton <AGDeviceManager>
{
private:
	AGPD3D		_mpD3d;
	AGPDevice	_mpDevice;

public:
	AGDeviceManager		();
	~AGDeviceManager	();

	bool	Initialize	();
	bool	Destroy		();

	inline const AGPDevice&	GetDevice	()	const	{ return _mpDevice; };
};