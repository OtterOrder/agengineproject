#pragma once

#include "AGCamera.h"
#include "AG3DEntity.h"

#include "AGDeviceManager.h"

//------------------------------------------------------------------------------------------------------------------------------
class AG3DCamera : public AG3DEntity, public AGCamera
{
public:
	DefineVectorIterator(AG3DCamera, Iterator);

public:
	float		mFOV;
	float		mRatio;
	float		mZNear;
	float		mZFar;

	AGVector3f	mOrientation;

public:
			AG3DCamera	();
			~AG3DCamera	();

	void	Update ();
};