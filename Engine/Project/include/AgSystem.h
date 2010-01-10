#pragma once

#include "AGSingleton.h"
#include "AGTimer.h"

#include "AGWindowManager.h"

#define __DefaultWndWidth		512
#define __DefaultWndHeight		512
#define __DefaultWndName	"AGEngine"

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
	void	Initialize	();
	void	Destroy		();
	void	MainLoop	();

	void	ShutDown	()	{ _mShutDown = true; };
};