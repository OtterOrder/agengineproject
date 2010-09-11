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
	_mpSkyBoxLightSH = new float* [3]; 
	for ( int i=0 ; i < 3 ; i++) 
		_mpSkyBoxLightSH[i] = new float [AGSHMaxOrder*AGSHMaxOrder];
}

//------------------------------------------------------------------------------------------------------------------------------
AGPRTLightProbe::~AGPRTLightProbe()
{
	for ( int i=0 ; i < 3 ; i++) 
		delete _mpSkyBoxLightSH [i]; 
	delete _mpSkyBoxLightSH; 

	SAFE_RELEASE(_mpYlmCoeff0);
	SAFE_RELEASE(_mpYlmCoeff4);
	SAFE_RELEASE(_mpYlmCoeff8);
	SAFE_RELEASE(_mpYlmCoeff12);
}

//------------------------------------------------------------------------------------------------------------------------------
float** AGPRTLightProbe::ComputeSHFromCubeMap(AGPTextureCube _CubeMap)
{
	AGSHProjectCubeMap(6, _CubeMap, _mpSkyBoxLightSH[0], _mpSkyBoxLightSH[1], _mpSkyBoxLightSH[2]);

	SHCubeProj projData;
	projData.Init(_mpSkyBoxLightSH[0],_mpSkyBoxLightSH[1],_mpSkyBoxLightSH[2]);

	return _mpSkyBoxLightSH;
}

//------------------------------------------------------------------------------------------------------------------------------
AGPTextureCube AGPRTLightProbe::GetYlmCoeff0()
{
	AGCreateTextureCube(&_mpYlmCoeff0, 32);
	AGFillCubeTexture(_mpYlmCoeff0,myFillBF,(LPVOID)(INT_PTR)(0*4));

	return _mpYlmCoeff0;
}

//------------------------------------------------------------------------------------------------------------------------------
AGPTextureCube AGPRTLightProbe::GetYlmCoeff4()
{
	AGCreateTextureCube(&_mpYlmCoeff4, 32);
	AGFillCubeTexture(_mpYlmCoeff4,myFillBF,(LPVOID)(INT_PTR)(1*4));

	return _mpYlmCoeff4;
}

//------------------------------------------------------------------------------------------------------------------------------
AGPTextureCube AGPRTLightProbe::GetYlmCoeff8()
{
	AGCreateTextureCube(&_mpYlmCoeff8, 32);
	AGFillCubeTexture(_mpYlmCoeff8,myFillBF,(LPVOID)(INT_PTR)(2*4));

	return _mpYlmCoeff8;
}

//------------------------------------------------------------------------------------------------------------------------------
AGPTextureCube AGPRTLightProbe::GetYlmCoeff12()
{
	AGCreateTextureCube(&_mpYlmCoeff12, 32);
	AGFillCubeTexture(_mpYlmCoeff12,myFillBF,(LPVOID)(INT_PTR)(3*4));

	return _mpYlmCoeff12;
}

//------------------------------------------------------------------------------------------------------------------------------
//------------------------------------------------------------------------------------------------------------------------------
void WINAPI myFillBF(AGVector4f* pOut, 
					 CONST AGVector3f* pTexCoord, 
					 CONST AGVector3f* pTexelSize, 
					 LPVOID pData)
{
	AGVector3f vDir;

	int iBase = (int)(INT_PTR)pData;

	AGVec3Normalize(&vDir,pTexCoord);

	float fVals[16];
	AGSHEvalDirection( fVals, 4, &vDir );

	(*pOut) = AGVector4f(fVals[iBase+0],fVals[iBase+1],fVals[iBase+2],fVals[iBase+3]);
}