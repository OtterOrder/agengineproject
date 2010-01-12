#pragma once

#include "AGSingleton.h"

#include "AG3DGraphicEntity.h"

#include "AG3DCamera.h"
#include "AGDebugCamera.h"		////.

//------------------------------------------------------------------------------------------------------------------------------
class AGRenderer : public AGSingleton<AGRenderer>
{
friend class AGSingleton<AGRenderer>;

protected:
	AGRenderer	();
	~AGRenderer	();

public:
	CFirstPersonCamera 	mCamera;		////.

	void Render (AG3DGraphicEntity* _3DGraphicEntity, AG3DCamera* _pCamera);	////. ToDo : Change parameters
};