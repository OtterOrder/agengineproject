#pragma once

#include "AGSingleton.h"

#include "AGDebugCamera.h"		////.

class AG2DScene;
class AG3DScene;

//------------------------------------------------------------------------------------------------------------------------------
class AGRenderer : public AGSingleton<AGRenderer>
{
friend class AGSingleton<AGRenderer>;

protected:
	AGRenderer	();
	~AGRenderer	();

public:
	CFirstPersonCamera 	mCamera;		////.

	void Render (AG3DScene* _pScene);
	void Render (AG2DScene* _pScene);
};