#pragma once

#include "AGDeviceManager.h"
#include "AG3DMaterial.h"

//------------------------------------------------------------------------------------------------------------------------------
class AGPostProcess
{
protected:
	static AGPVertexBuffer	_mpVertexBuffer;

	AG3DMaterial			_mMaterial;

public:
					AGPostProcess	();
	virtual			~AGPostProcess	();

	static	void	Initialize		();
	static	void	Destroy			();

protected:
	virtual void	Setup			()	=0;
	virtual void	End				()	{};

public:
			void	Apply			();
};