#pragma once

#include "AGScene.h"

#include "AG2DCamera.h"
#include "AG2DGraphicEntity.h"

//------------------------------------------------------------------------------------------------------------------------------
class AG2DScene : public AGScene
{
private:
	AG2DCamera*		_mpCamera;
	vector<AG2DGraphicEntity*>	_mpGraphicEntites;

public:
	AG2DScene  ();
	~AG2DScene ();

	inline	AGCamera*	GetCamera ()	{ return (AGCamera*)_mpCamera; };

	void	Update ();
};