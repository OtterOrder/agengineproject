#pragma once

#include "AGPostProcess.h"

//------------------------------------------------------------------------------------------------------------------------------
class AGShadowHBlur : public AGPostProcess
{
public:
	AGPTexture		mpTexture;
	AGPTexture		mpBlurCoef;

public:
			AGShadowHBlur	();
			~AGShadowHBlur	();

protected:
			void	Setup	();
			void	End		();
};