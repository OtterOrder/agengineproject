#pragma once

#include "AG3DGraphicEntity.h"

//------------------------------------------------------------------------------------------------------------------------------
class AGSkybox : public AG3DGraphicEntity
{
public:
				AGSkybox(const std::string& Name);
				AGSkybox();
	virtual		~AGSkybox();


	virtual	void			Update ();


};