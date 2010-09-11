#pragma once

#include "AGTextureCube.h"
#include "AG3DMaterial.h"

#include "AG3DScene.h"
#include "AG3DGraphicEntity.h"

//------------------------------------------------------------------------------------------------------------------------------
class SkyboxMaterial : public AG3DMaterial
{
private:
	AGTextureCube*	_mpCubeTex;

public:
	SkyboxMaterial		();
	virtual			~SkyboxMaterial	();

	virtual	void			Apply (AG3DScene* _pScene, AG3DGraphicEntity* _pEntity);
			void			SetCubeMapFromFile	(cStr _FileName);
			AGPTextureCube	GetCubeMap() {return _mpCubeTex->GetTexture();}
};