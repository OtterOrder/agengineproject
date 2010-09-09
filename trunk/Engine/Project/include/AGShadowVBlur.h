#pragma once

#include "AGPostProcess.h"

//------------------------------------------------------------------------------------------------------------------------------
class AGShadowVBlur : public AGPostProcess
{
public:
	AGPTexture		mpTexture;
	AGPTexture		mpBlurCoef;

public:
			AGShadowVBlur	();
			~AGShadowVBlur	();

protected:
			void	Setup	();
			void	End		();
};