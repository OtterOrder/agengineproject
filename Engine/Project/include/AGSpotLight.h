#pragma once

#include "AGLight.h"

//------------------------------------------------------------------------------------------------------------------------------
class AGSpotLight : public AGLight
{
public:
	AGVector3f	mDirection;
	float		mHalfAngle;		// Radians	[0.0 , Pi]

public:
					AGSpotLight		();
					~AGSpotLight	();

			void	Update ();
};