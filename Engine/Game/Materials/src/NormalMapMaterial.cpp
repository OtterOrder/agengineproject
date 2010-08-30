#include "NormalMapMaterial.h"

#include "AG3DGraphicEntity.h"

//------------------------------------------------------------------------------------------------------------------------------
//------------------------------------------------------------------------------------------------------------------------------
NormalMapMaterial::NormalMapMaterial()
{
	AG3DMaterial::AG3DMaterial();

	SetShader(".\\Data\\Shaders\\NormalMap.vsh", "VSMain", ".\\Data\\Shaders\\NormalMap.psh", "PSMain");
	_mpDiffuseTex = NULL;
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
	_mpPixelShader->SetTexture("DiffuseSampler", _mpDiffuseTex->GetTexture());
}

//------------------------------------------------------------------------------------------------------------------------------
//------------------------------------------------------------------------------------------------------------------------------
void NormalMapMaterial::SetDiffuse (cStr _FileName)
{
	SAFE_DECREF(_mpDiffuseTex);
	_mpDiffuseTex = AGResourceManager::GetSingleton()->Load<AGTexture>(_FileName);
}