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
	bool	_mShutDown;

public:
	void	Init		();
	void	Destroy		();
	void	MainLoop	();

	void	ShutDown	()	{ _mShutDown = true; };
};