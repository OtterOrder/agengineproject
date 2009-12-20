#pragma once

#include "AGCamera.h"
#include "AG2DEntity.h"

//------------------------------------------------------------------------------------------------------------------------------
class AG2DCamera : public AG2DEntity, public AGCamera
{
public:
	DefineVectorIterator(AG2DCamera, Iterator);

public:
	AG2DCamera	();
	~AG2DCamera	();
};