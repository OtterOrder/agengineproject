#pragma once

#include "AGTextureCube.h"
#include "AG3DGraphicEntity.h"

//------------------------------------------------------------------------------------------------------------------------------
class AGSkybox : public AG3DGraphicEntity
{
protected:
	AGTextureCube*	_mpCubeTex;
	AGPVertexBuffer	_mpSkyVB;
	float			_mpSizeVB;
public:
					AGSkybox(const std::string& Name);
					AGSkybox();
	virtual			~AGSkybox();


	virtual	void	Update ();
	virtual	void	Draw (CFirstPersonCamera* _pCamera, AG3DScene* _pScene);
			void	SetTexture (cStr _FileName);
};