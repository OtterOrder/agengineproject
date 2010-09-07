#include "AGPRTLightProbe.h"

#include "AGUtilities.h"
#include "AGWDX9.h"

struct SHCubeProj 
{
	float *pRed,*pGreen,*pBlue;
	int iOrderUse; 
	float fConvCoeffs[6]; // convolution coefficients

	void InitDiffCubeMap(float *pR, float *pG, float *pB)
	{
		pRed = pR;
		pGreen = pG;
		pBlue = pB;

		iOrderUse = 3; 
		fConvCoeffs[0] = 1.0f;
		fConvCoeffs[1] = 2.0f/3.0f;
		fConvCoeffs[2] = 1.0f/4.0f;
		fConvCoeffs[3] = fConvCoeffs[5] = 0.0f;
		fConvCoeffs[4] = -6.0f/144.0f; // 
	}

	void Init(float *pR, float *pG, float *pB)
	{
		pRed = pR;
		pGreen = pG;
		pBlue = pB;

		iOrderUse = 6;
		for(int i=0;i<6;i++) fConvCoeffs[i] = 1.0f;
	}
};

//------------------------------------------------------------------------------------------------------------------------------
//------------------------------------------------------------------------------------------------------------------------------
AGPRTLightProbe::AGPRTLightProbe()
: AGSkybox()
{
	
}

//------------------------------------------------------------------------------------------------------------------------------
AGPRTLightProbe::~AGPRTLightProbe()
{
}

//------------------------------------------------------------------------------------------------------------------------------
void AGPRTLightProbe::ComputeSHFromCubeMap(AGPTextureCube _CubeMap)
{
	AGSHProjectCubeMap(6, _CubeMap, _mpSkyBoxLightSH[0], _mpSkyBoxLightSH[1], _mpSkyBoxLightSH[2]);

	// Now compute the SH projection of the skybox...
	AGPTextureCube pSHCubeTex=NULL;
	AGCreateTextureCube(&pSHCubeTex, 256);
}
