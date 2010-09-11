#pragma once

#include "AGTextureCube.h"
#include "AG3DMaterial.h"

#include "AG3DScene.h"
#include "AG3DGraphicEntity.h"

//------------------------------------------------------------------------------------------------------------------------------
class PRTLightMaterial : public AG3DMaterial
{
private:
	AGPTextureCube _mpYlmCoeff0;
	AGPTextureCube _mpYlmCoeff4;
	AGPTextureCube _mpYlmCoeff8;
	AGPTextureCube _mpYlmCoeff12;

	AGTexture*	   _mpDiffuseTex;
	AGTexture*	   _mpNormalTex;
	float**		   _mpSHCoef;
	FLOAT          _mpFRLC[D3DXSH_MAXORDER*D3DXSH_MAXORDER];
	FLOAT          _mpFGLC[D3DXSH_MAXORDER*D3DXSH_MAXORDER];
	FLOAT          _mpFBLC[D3DXSH_MAXORDER*D3DXSH_MAXORDER];
	AGVector3f	   _mpTransmitColor;
	float		   _mpLightContribution;
	float		   _mpEnvironmentContribution;

public:
	PRTLightMaterial		();
	virtual					~PRTLightMaterial	();

	virtual	void			Apply (AG3DScene* _pScene, AG3DGraphicEntity* _pEntity);
			void			SetDiffuse (cStr _FileName);
			void			SetNormal (cStr _FileName);
			void			SetSHCoefFromCubeMap (float** _Data);
			void			SetTransmitColor (AGVector3f _Color);
			void			SetLightContribution (float _Contrib);
			void			SetEnvironmentContribution (float _Contrib);
			void			SetYlmCoef0(AGPTextureCube _CubeMap) {_mpYlmCoeff0 = _CubeMap;}
			void			SetYlmCoef4(AGPTextureCube _CubeMap) {_mpYlmCoeff4 = _CubeMap;}
			void			SetYlmCoef8(AGPTextureCube _CubeMap) {_mpYlmCoeff8 = _CubeMap;}
			void			SetYlmCoef12(AGPTextureCube _CubeMap) {_mpYlmCoeff12 = _CubeMap;}
};
