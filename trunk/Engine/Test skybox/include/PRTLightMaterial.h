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

public:
	PRTLightMaterial		();
	virtual					~PRTLightMaterial	();

	virtual	void			Apply (AG3DScene* _pScene, AG3DGraphicEntity* _pEntity);
			void			SetDiffuse	(cStr _FileName);
			void			SetNormal	(cStr _FileName);
};

void WINAPI myFillBF(AGVector4f* pOut, 
					 CONST AGVector3f* pTexCoord, 
					 CONST AGVector3f* pTexelSize, 
					 LPVOID pData);