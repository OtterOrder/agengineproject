#pragma once

#include "AGScene.h"

#include "AG3DGraphicEntity.h"
#include "AGSpotLight.h"
#include "AGPRTLightProbe.h"
class AG3DCamera;
class AGLight;

#include "AGRenderer.h"

//------------------------------------------------------------------------------------------------------------------------------
class AG3DScene : public AGScene
{
private:
	AG3DCamera*					_mpCamera;
	vector<AG3DGraphicEntity*>	_mpGraphicEntites;
	vector<AGLight*>			_mpLights;

public:
										AG3DScene  ();
										~AG3DScene ();

	inline	AGCamera*					GetCamera	()	{ return (AGCamera*)_mpCamera;	}
	inline	AG3DCamera*					Get3DCamera	()	{ return _mpCamera; }
	inline	vector<AG3DGraphicEntity*>	GetEntities	()	{ return _mpGraphicEntites;		}
	inline	vector<AGLight*>			GetLights	()	{ return _mpLights;				}

			void						Update	();

	inline	void						Draw	()		{ AGRenderer::GetSingleton()->Render(this); }

			AG3DGraphicEntity*			GetNewGraphicEntity ();
			void						RemoveGraphicEntity (AG3DGraphicEntity* _pGraphicEntity);
	inline	void						DeleteGraphicEntity (AG3DGraphicEntity* _pGraphicEntity)	{ RemoveGraphicEntity(_pGraphicEntity); SAFE_DELETE(_pGraphicEntity); }

			AGSpotLight*				GetNewSpotLight		();
			void						RemoveLight			(AGLight* _pLight);
	inline	void						DeleteLight			(AGLight* _pLight)					{ RemoveLight(_pLight); SAFE_DELETE(_pLight); }

			AGSkybox*					GetNewSkybox		();
			AGPRTLightProbe*			GetNewPRTSkybox		();
};