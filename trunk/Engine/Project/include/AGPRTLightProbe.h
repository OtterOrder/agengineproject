#pragma once

#include "AGTextureCube.h"
#include "AGSkybox.h"

//------------------------------------------------------------------------------------------------------------------------------
class AGPRTLightProbe : public AGSkybox
{
protected:
	float			_mpSkyBoxLightSH[3][AGSHMaxOrder*AGSHMaxOrder]; 
	AGPTextureCube	_mpSHCubeTex;

public:
				AGPRTLightProbe(const std::string& Name);
				AGPRTLightProbe();
	virtual		~AGPRTLightProbe();

	void			ComputeSHFromCubeMap(AGPTextureCube _CubeMap);
	AGPTextureCube	GetSHCubeMap() {return _mpSHCubeTex;}

};

void WINAPI SHCubeFill(AGVector4f* pOut, 
					   CONST AGVector3f* pTexCoord, 
					   CONST AGVector3f* pTexelSize, 
					   LPVOID pData);