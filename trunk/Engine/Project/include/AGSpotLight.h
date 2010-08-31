#pragma once

#include "AGLight.h"

//------------------------------------------------------------------------------------------------------------------------------
class AGSpotLight : public AGLight
{
public:
	AGVector3f	mDirection;
	float		mInHalfAngle;		// Radians	[0.0 , Pi]
	float		mOutHalfAngle;		// Radians	[0.0 , Pi]

public:
					AGSpotLight		();
					~AGSpotLight	();

			void	Update ();
};