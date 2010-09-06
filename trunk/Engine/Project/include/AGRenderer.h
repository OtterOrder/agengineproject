#pragma once

#include "AGSingleton.h"
#include "AGDeviceManager.h"

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

			void	Destroy	();

public:
	CFirstPersonCamera 	mCamera;		////.

	void Render			(AG3DScene* _pScene);

	////.
	void RenderZ		(AG3DScene* _pScene, AGMatrix _ViewMatrix, AGMatrix _ProjMatrix, AGMatrix _ViewProjMatrix);
	void RenderShadow	(AG3DScene* _pScene, AGMatrix _LightViewProjMatrix, AGPTexture _ShadowMap);
	////.

	void Render			(AG2DScene* _pScene);
};