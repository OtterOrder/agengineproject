#pragma once

#include "AGScene.h"

#include "AG3DGraphicEntity.h"
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

	inline	AGCamera*					GetCamera	()	{ return (AGCamera*)_mpCamera; }
	inline	vector<AG3DGraphicEntity*>	GetEntities	()	{ return _mpGraphicEntites; }

			void						Update	();

	inline	void						Draw	()		{ AGRenderer::GetSingleton()->Render(this); }

			AG3DGraphicEntity*			GetNewGraphicEntity ();
			void						RemoveGraphicObject (AG3DGraphicEntity* _pGraphicEntity);
	inline	void						DeleteGraphicEntity (AG3DGraphicEntity* _pGraphicEntity)	{ RemoveGraphicObject(_pGraphicEntity); SAFE_DELETE(_pGraphicEntity); }
};