#pragma once

#include "AGSingleton.h"
#include "AGTimer.h"

//------------------------------------------------------------------------------------------------------------------------------
class AGSystem : public AGSingleton<AGSystem>
{
friend class AGSingleton<AGSystem>;

private:
	bool	_mShutDown;

public:
	AGTimer	mTimer;

protected:
	AGSystem	()	{};
	~AGSystem	()	{};

public:
	void	Initializze	();
	void	Destroy		();
	void	MainLoop	();

	void	ShutDown	()	{ _mShutDown = true; };
};