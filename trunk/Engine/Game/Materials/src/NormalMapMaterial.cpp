#include "NormalMapMaterial.h"

#include "AGLight.h"
#include "AGSpotLight.h"
#include "AG3DCamera.h"

//------------------------------------------------------------------------------------------------------------------------------
//------------------------------------------------------------------------------------------------------------------------------
NormalMapMaterial::NormalMapMaterial()
{
	AG3DMaterial::AG3DMaterial();

	SetShader(".\\Data\\Shaders\\NormalMap.vsh", "VSMain", ".\\Data\\Shaders\\NormalMap.psh", "PSMain");
	_mpDiffuseTex = NULL;
	_mpNormalTex  = NULL;
	mBumpCoef = 1.0f;
}

//------------------------------------------------------------------------------------------------------------------------------
NormalMapMaterial::~NormalMapMaterial()
{
	AG3DMaterial::~AG3DMaterial();
}

//------------------------------------------------------------------------------------------------------------------------------
//------------------------------------------------------------------------------------------------------------------------------
void NormalMapMaterial::Apply (AG3DScene* _pScene, AG3DGraphicEntity* _pEntity)
{
	// Vertex Shader
	AGMatrix WorldMatrix = _pEntity->GetWorldMatrix();
	_mpVertexShader->SetMatrix	("gWorld",			WorldMatrix);
	AGMatrixInverse	 (&WorldMatrix, NULL, &WorldMatrix);
	AGMatrixTranspose(&WorldMatrix, &WorldMatrix);
	_mpVertexShader->SetMatrix	("gWorldIT",		WorldMatrix);

	// Pixel Shader
	_mpPixelShader->SetTexture("DiffuseSampler", _mpDiffuseTex->GetTexture());

	if (_mpNormalTex)
		_mpPixelShader->SetTexture("NormalSampler",  _mpNormalTex->GetTexture() );
	else
		_mpPixelShader->SetTexture("NormalSampler",  NULL );

	_mpPixelShader->SetFloat("gBumpCoef", mBumpCoef);

	vector<AGLight*> Lights = _pScene->GetLights();
	AGLight::Iterator LightIt;

	AGSpotLight* SpotLight;

	for (LightIt = Lights.begin(); LightIt != Lights.end(); LightIt++)
	{
		if ((*LightIt)->GetType() == AGLight::Spot)
		{
			SpotLight = (AGSpotLight*)(*LightIt);
			_mpPixelShader->SetVector3f	("gLightPosition",	SpotLight->mPosition);
			//_mpPixelShader->SetVector3f	("gLightDirection",	SpotLight->mDirection);
			_mpPixelShader->SetVector3f	("gLightDiffuse",	SpotLight->GetDiffuse());
			_mpPixelShader->SetVector3f	("gLightSpecular",	SpotLight->GetSpecular());
			_mpPixelShader->SetVector3f	("gCamPosition",	_pScene->Get3DCamera()->mPosition);

			return;
		}
	}
}

//------------------------------------------------------------------------------------------------------------------------------
//------------------------------------------------------------------------------------------------------------------------------
void NormalMapMaterial::SetDiffuse (cStr _FileName)
{
	SAFE_DECREF(_mpDiffuseTex);
	_mpDiffuseTex = AGResourceManager::GetSingleton()->Load<AGTexture>(_FileName);
}

//------------------------------------------------------------------------------------------------------------------------------
void NormalMapMaterial::SetNormal (cStr _FileName)
{
	SAFE_DECREF(_mpNormalTex);
	_mpNormalTex = AGResourceManager::GetSingleton()->Load<AGTexture>(_FileName);
}