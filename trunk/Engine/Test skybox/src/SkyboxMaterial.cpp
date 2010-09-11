#include "SkyboxMaterial.h"

#include "AGLight.h"
#include "AGSpotLight.h"
#include "AG3DCamera.h"

//------------------------------------------------------------------------------------------------------------------------------
//------------------------------------------------------------------------------------------------------------------------------
SkyboxMaterial::SkyboxMaterial()
{
	AG3DMaterial::AG3DMaterial();

	SetShader(".\\Data\\Shaders\\Skybox.vsh", "VSMain", ".\\Data\\Shaders\\Skybox.psh", "PSMain");
	_mpCubeTex = NULL;
}

//------------------------------------------------------------------------------------------------------------------------------
SkyboxMaterial::~SkyboxMaterial()
{
	AG3DMaterial::~AG3DMaterial();
	SAFE_RELEASE(_mpCubeTex);
}

//------------------------------------------------------------------------------------------------------------------------------
//------------------------------------------------------------------------------------------------------------------------------
void SkyboxMaterial::Apply (AG3DScene* _pScene, AG3DGraphicEntity* _pEntity)
{
	// Vertex Shader
	AGMatrix WorldMatrix = _pEntity->GetWorldMatrix();
	_mpVertexShader->SetMatrix	("gWorld",			WorldMatrix);

	// Pixel Shader
	_mpPixelShader->SetTexture("DiffuseSampler", _mpCubeTex->GetTexture());
}

//------------------------------------------------------------------------------------------------------------------------------
//------------------------------------------------------------------------------------------------------------------------------
void SkyboxMaterial::SetCubeMapFromFile (cStr _FileName)
{
	SAFE_DECREF(_mpCubeTex);
	_mpCubeTex = AGResourceManager::GetSingleton()->Load<AGTextureCube>(_FileName);
}
