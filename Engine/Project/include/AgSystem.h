#pragma once

//------------------------------------------------------------------------------------------------------------------------------
#include "AGSingleton.h"

//------------------------------------------------------------------------------------------------------------------------------
class AGSystem : public AGSingleton<AGSystem>
{
friend class AGSingleton<AGSystem>;

protected:
	AGSystem	()	{};
	~AGSystem	()	{};

private:
	bool	_mDestroy;

public:
	void	Init		();
	void	Destroy		();
	void	MainLoop	();
};