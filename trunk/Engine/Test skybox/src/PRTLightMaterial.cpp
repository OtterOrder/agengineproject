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

	_mpTransmitColor = AGVector3f(1.0f, 1.0f, 1.0f);
	_mpLightContribution = 5.0f;
	_mpEnvironmentContribution = 0.6f;
}

//------------------------------------------------------------------------------------------------------------------------------
PRTLightMaterial::~PRTLightMaterial()
{
	AG3DMaterial::~AG3DMaterial();
	SAFE_RELEASE(_mpDiffuseTex);
	SAFE_RELEASE(_mpNormalTex);
}

//------------------------------------------------------------------------------------------------------------------------------
//------------------------------------------------------------------------------------------------------------------------------
void PRTLightMaterial::Apply (AG3DScene* _pScene, AG3DGraphicEntity* _pEntity)
{
	// Vertex Shader
	AGMatrix WorldMatrix = _pEntity->GetWorldMatrix();
	_mpVertexShader->SetMatrix	("gWorld",			WorldMatrix);
	AGMatrixInverse	 (&WorldMatrix, NULL, &WorldMatrix);
	AGMatrixTranspose(&WorldMatrix, &WorldMatrix);
	_mpVertexShader->SetMatrix	("gWorldIT",		WorldMatrix);

	_mpPixelShader->SetTexture("DiffuseSampler", _mpDiffuseTex);
	_mpPixelShader->SetTexture("NormalSampler",  _mpNormalTex);

	_mpPixelShader->SetTexture("YlmCoeff0Sampler", _mpYlmCoeff0);
	_mpPixelShader->SetTexture("YlmCoeff4Sampler", _mpYlmCoeff4);
	_mpPixelShader->SetTexture("YlmCoeff8Sampler", _mpYlmCoeff8);
	_mpPixelShader->SetTexture("YlmCoeff12Sampler", _mpYlmCoeff12);

	vector<AGLight*> Lights = _pScene->GetLights();
	AGLight::Iterator LightIt;

	AGSpotLight* SpotLight;

	for (LightIt = Lights.begin(); LightIt != Lights.end(); LightIt++)
	{
		if ((*LightIt)->GetType() == AGLight::Spot)
		{
			SpotLight = (AGSpotLight*)(*LightIt);

			// Create the spotlight
			D3DXSHEvalConeLight( D3DXSH_MAXORDER, &SpotLight->mDirection, D3DX_PI/8.0f, 
				_mpLightContribution, _mpLightContribution, _mpLightContribution, 
				_mpFRLC, _mpFGLC, _mpFBLC);

			float fSkybox[3][D3DXSH_MAXORDER*D3DXSH_MAXORDER];  

			// Scale the light probe environment contribution based on input options    
			D3DXSHScale( fSkybox[0], D3DXSH_MAXORDER, _mpSHCoef[0], _mpEnvironmentContribution);
			D3DXSHScale( fSkybox[1], D3DXSH_MAXORDER, _mpSHCoef[1], _mpEnvironmentContribution);
			D3DXSHScale( fSkybox[2], D3DXSH_MAXORDER, _mpSHCoef[2], _mpEnvironmentContribution);

			// Combine the environment and the spotlight
			D3DXSHAdd( _mpFRLC, D3DXSH_MAXORDER, _mpFRLC, fSkybox[0] );
			D3DXSHAdd( _mpFGLC, D3DXSH_MAXORDER, _mpFGLC, fSkybox[1] );
			D3DXSHAdd( _mpFBLC, D3DXSH_MAXORDER, _mpFBLC, fSkybox[2] );

			_mpPixelShader->SetVector3f("gTransmitColor", _mpTransmitColor);
			_mpPixelShader->SetFloatArray("gLightCoeffsR", _mpFRLC, 4 * sizeof(float));
			_mpPixelShader->SetFloatArray("gLightCoeffsG", _mpFGLC, 4 * sizeof(float));
			_mpPixelShader->SetFloatArray("gLightCoeffsB", _mpFBLC, 4 * sizeof(float));

			return;
		}
	}

	
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
void PRTLightMaterial::SetSHCoefFromCubeMap (float** _Data)
{
	_mpSHCoef = _Data;
}

//------------------------------------------------------------------------------------------------------------------------------
void PRTLightMaterial::SetTransmitColor (AGVector3f _Color)
{
	_mpTransmitColor = _Color;
}

//------------------------------------------------------------------------------------------------------------------------------
void PRTLightMaterial::SetLightContribution (float _Contrib)
{
	_mpLightContribution = _Contrib;
}

//------------------------------------------------------------------------------------------------------------------------------
void PRTLightMaterial::SetEnvironmentContribution (float _Contrib)
{
	_mpEnvironmentContribution = _Contrib;
}

