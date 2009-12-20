#pragma once

#include "AGCamera.h"
#include "AG3DEntity.h"

//------------------------------------------------------------------------------------------------------------------------------
class AG3DCamera : public AG3DEntity, public AGCamera
{
public:
	DefineVectorIterator(AG3DCamera, Iterator);

public:
	AG3DCamera	();
	~AG3DCamera	();
};