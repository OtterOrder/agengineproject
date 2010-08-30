#pragma once

#include "AG3DMaterial.h"
#include "AGTexture.h"

//------------------------------------------------------------------------------------------------------------------------------
class NormalMapMaterial : public AG3DMaterial
{
private:
	AGTexture*		_mpDiffuseTex;
public:
					NormalMapMaterial		();
	virtual			~NormalMapMaterial	();

	virtual	void	Apply (AG3DScene* _pScene, AG3DGraphicEntity* _pEntity);

			void	SetDiffuse (cStr _FileName);
};