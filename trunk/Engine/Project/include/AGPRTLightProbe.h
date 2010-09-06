#pragma once

#include "AGTextureCube.h"
#include "AGSkybox.h"

//------------------------------------------------------------------------------------------------------------------------------
class AGPRTLightProbe : public AGSkybox
{
protected:
	float	_mpSkyBoxLightSH[3][AGSHMaxOrder*AGSHMaxOrder]; 

public:
				AGPRTLightProbe(const std::string& Name);
				AGPRTLightProbe();
	virtual		~AGPRTLightProbe();

	void		ComputeSHFromCubeMap(AGPTextureCube _CubeMap);

};