#include "AGPRTLightProbe.h"

#include "AGUtilities.h"
#include "AGWDX9.h"

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
	D3DXSHProjectCubeMap( 6, _CubeMap, _mpSkyBoxLightSH[0], _mpSkyBoxLightSH[1], _mpSkyBoxLightSH[2] );
}
