#include "NormalMapShadowMaterial.h"

//------------------------------------------------------------------------------------------------------------------------------
//------------------------------------------------------------------------------------------------------------------------------
NormalMapShadowMaterial::NormalMapShadowMaterial()
{
	AG3DMaterial::AG3DMaterial();

	SetShader(".\\Data\\Shaders\\NormalMapShadow.vsh", "VSMain", ".\\Data\\Shaders\\NormalMapShadow.psh", "PSMain");
}

//------------------------------------------------------------------------------------------------------------------------------
NormalMapShadowMaterial::~NormalMapShadowMaterial()
{
	AG3DMaterial::~AG3DMaterial();
}

//------------------------------------------------------------------------------------------------------------------------------
//------------------------------------------------------------------------------------------------------------------------------
void NormalMapShadowMaterial::Apply (AG3DScene* _pScene, AG3DGraphicEntity* _pEntity)
{
}