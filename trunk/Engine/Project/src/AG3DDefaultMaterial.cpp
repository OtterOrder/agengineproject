#include "AG3DDefaultMaterial.h"

#include "AG3DGraphicEntity.h"

#define		DEFAULT_VS_PATH		".\\Data\\Shaders\\Defaults\\DefaultVS.vsh"
#define		DEFAULT_PS_PATH		".\\Data\\Shaders\\Defaults\\DefaultPS.psh"

#define		DEFAULT_VS_ENTRY	"VSMain"
#define		DEFAULT_PS_ENTRY	"PSMain"

//------------------------------------------------------------------------------------------------------------------------------
//------------------------------------------------------------------------------------------------------------------------------
AG3DDefaultMaterial::AG3DDefaultMaterial()
{
	AG3DMaterial::AG3DMaterial();

	SetShader(DEFAULT_VS_PATH, DEFAULT_VS_ENTRY, DEFAULT_PS_PATH, DEFAULT_PS_ENTRY);
}

//------------------------------------------------------------------------------------------------------------------------------
AG3DDefaultMaterial::~AG3DDefaultMaterial()
{
	AG3DMaterial::~AG3DMaterial();
}

//------------------------------------------------------------------------------------------------------------------------------
//------------------------------------------------------------------------------------------------------------------------------
void AG3DDefaultMaterial::Apply (AG3DScene* _pScene, AG3DGraphicEntity* _pEntity)
{

}