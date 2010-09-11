#pragma once

#include "AGTextureCube.h"
#include "AGSkybox.h"

//------------------------------------------------------------------------------------------------------------------------------
class AGPRTLightProbe : public AGSkybox
{
protected:
	float**			_mpSkyBoxLightSH; 
	AGPTextureCube  _mpYlmCoeff0;
	AGPTextureCube  _mpYlmCoeff4;
	AGPTextureCube  _mpYlmCoeff8;
	AGPTextureCube  _mpYlmCoeff12;

public:
				AGPRTLightProbe(const std::string& Name);
				AGPRTLightProbe();
	virtual		~AGPRTLightProbe();

	float**			ComputeSHFromCubeMap(AGPTextureCube _CubeMap);
	AGPTextureCube  GetYlmCoeff0();
	AGPTextureCube  GetYlmCoeff4();
	AGPTextureCube  GetYlmCoeff8();
	AGPTextureCube  GetYlmCoeff12();

};

void WINAPI myFillBF(AGVector4f* pOut, 
					 CONST AGVector3f* pTexCoord, 
					 CONST AGVector3f* pTexelSize, 
					 LPVOID pData);