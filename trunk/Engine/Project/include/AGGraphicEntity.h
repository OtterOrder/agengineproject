#pragma once

#include "AGEntity.h"
#include "AGScene.h"

#include "AGDebugCamera.h"	////.

//------------------------------------------------------------------------------------------------------------------------------
class AGGraphicEntity : virtual public AGEntity
{
public:
	DefineVectorIterator(AGGraphicEntity, Iterator);

public:
	AGGraphicEntity		();
	virtual ~AGGraphicEntity	();

	virtual void Draw (CFirstPersonCamera* _pCamera, AGScene* _pScene) =0;	////.
};