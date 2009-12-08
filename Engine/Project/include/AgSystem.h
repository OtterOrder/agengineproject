#pragma once

//------------------------------------------------------------------------------------------------------------------------------
#include "AGSingleton.h"

//------------------------------------------------------------------------------------------------------------------------------
class AGSystem : public AGSingleton
{
DeclareSingleton(AGSystem);

public:
	void	Init		();
	void	Shutdown	();
	void	MainLoop	();
};

InitSingleton(AGSystem);
