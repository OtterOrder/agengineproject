#pragma once

#include "AGSingleton.h"

//------------------------------------------------------------------------------------------------------------------------------
class AGSceneManager : public AGSingleton<AGSceneManager>
{
friend class AGSingleton<AGSceneManager>;

protected:
	AGSceneManager		();
	~AGSceneManager		();
};