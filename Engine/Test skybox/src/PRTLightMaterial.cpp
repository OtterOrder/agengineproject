#include "PRTLightMaterial.h"

#include "AGLight.h"
#include "AGSpotLight.h"
#include "AG3DCamera.h"

//------------------------------------------------------------------------------------------------------------------------------
//------------------------------------------------------------------------------------------------------------------------------
PRTLightMaterial::PRTLightMaterial()
{
	AG3DMaterial::AG3DMaterial();
	_mpDiffuseTex	= NULL;
	_mpNormalTex	= NULL;

	SetShader(".\\Data\\Shaders\\PRTLight.vsh", "VSMain", ".\\Data\\Shaders\\PRTLight.psh", "PSMain");

	AGCreateTextureCube(&_mpYlmCoeff0, 32);
	AGFillCubeTexture(_mpYlmCoeff0,myFillBF,(LPVOID)(INT_PTR)(0*4));

	AGCreateTextureCube(&_mpYlmCoeff4, 32);
	AGFillCubeTexture(_mpYlmCoeff4,myFillBF,(LPVOID)(INT_PTR)(1*4));

	AGCreateTextureCube(&_mpYlmCoeff8, 32);
	AGFillCubeTexture(_mpYlmCoeff8,myFillBF,(LPVOID)(INT_PTR)(2*4));

	AGCreateTextureCube(&_mpYlmCoeff12, 32);
	AGFillCubeTexture(_mpYlmCoeff12,myFillBF,(LPVOID)(INT_PTR)(3*4));
}

//------------------------------------------------------------------------------------------------------------------------------
PRTLightMaterial::~PRTLightMaterial()
{
	AG3DMaterial::~AG3DMaterial();
	/*SAFE_RELEASE(_mpYlmCoeff0);
	SAFE_RELEASE(_mpYlmCoeff4);
	SAFE_RELEASE(_mpYlmCoeff8);
	SAFE_RELEASE(_mpYlmCoeff12);*/
}

//------------------------------------------------------------------------------------------------------------------------------
//------------------------------------------------------------------------------------------------------------------------------
void PRTLightMaterial::Apply (AG3DScene* _pScene, AG3DGraphicEntity* _pEntity)
{
	// Vertex Shader
	AGMatrix WorldMatrix = _pEntity->GetWorldMatrix();
	_mpVertexShader->SetMatrix	("gWorld",			WorldMatrix);

	_mpPixelShader->SetTexture("DiffuseSampler", _mpDiffuseTex);
	_mpPixelShader->SetTexture("NormalSampler",  _mpNormalTex);

	_mpPixelShader->SetTexture("YlmCoeff0Sampler", _mpYlmCoeff0);
	_mpPixelShader->SetTexture("YlmCoeff0Sampler", _mpYlmCoeff4);
	_mpPixelShader->SetTexture("YlmCoeff0Sampler", _mpYlmCoeff8);
	_mpPixelShader->SetTexture("YlmCoeff0Sampler", _mpYlmCoeff12);
}

//------------------------------------------------------------------------------------------------------------------------------
//------------------------------------------------------------------------------------------------------------------------------
void PRTLightMaterial::SetDiffuse (cStr _FileName)
{
	SAFE_DECREF(_mpDiffuseTex);
	_mpDiffuseTex = AGResourceManager::GetSingleton()->Load<AGTexture>(_FileName);
}

//------------------------------------------------------------------------------------------------------------------------------
void PRTLightMaterial::SetNormal (cStr _FileName)
{
	SAFE_DECREF(_mpNormalTex);
	_mpNormalTex = AGResourceManager::GetSingleton()->Load<AGTexture>(_FileName);
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