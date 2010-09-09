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
	_mpSHCubeTex=NULL;
	AGCreateTextureCube(&_mpSHCubeTex, 256);

	SHCubeProj projData;
	projData.Init(_mpSkyBoxLightSH[0],_mpSkyBoxLightSH[1],_mpSkyBoxLightSH[2]);

	AGFillCubeTexture(_mpSHCubeTex,SHCubeFill,&projData);
}

void WINAPI SHCubeFill(AGVector4f* pOut, 
					   CONST AGVector3f* pTexCoord, 
					   CONST AGVector3f* pTexelSize, 
					   LPVOID pData)
{
	SHCubeProj* pCP = (SHCubeProj*) pData;
	D3DXVECTOR3 vDir;

	AGVec3Normalize(&vDir,pTexCoord);

	float fVals[36];
	AGSHEvalDirection( fVals, pCP->iOrderUse, &vDir );

	(*pOut) = AGVector4f(0,0,0,0); // just clear it out...

	int l, m, uIndex = 0;
	for( l=0; l<pCP->iOrderUse; l++ ) 
	{
		const float fConvUse = pCP->fConvCoeffs[l];
		for( m=0; m<2*l+1; m++ ) 
		{
			pOut->x += fConvUse*fVals[uIndex]*pCP->pRed[uIndex];
			pOut->y += fConvUse*fVals[uIndex]*pCP->pGreen[uIndex];
			pOut->z += fConvUse*fVals[uIndex]*pCP->pBlue[uIndex];
			pOut->w = 1;

			uIndex++;
		}
	}
}
