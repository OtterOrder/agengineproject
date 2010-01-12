#pragma once

#include "AGScene.h"

#include "AG3DCamera.h"
#include "AG3DGraphicEntity.h"
#include "AGLight.h"

//------------------------------------------------------------------------------------------------------------------------------
class AG3DScene : public AGScene
{
private:
	AG3DCamera*		_mpCamera;
	vector<AG3DGraphicEntity*>	_mpGraphicEntites;
	vector<AGLight*>			_mpLights;

public:
	AG3DScene  ();
	~AG3DScene ();

	inline	AGCamera*	GetCamera ()	{ return (AGCamera*)_mpCamera; };

	void	Update ();
};