#pragma once

#include "AGSingleton.h"

//------------------------------------------------------------------------------------------------------------------------------
class AGSystem : public AGSingleton<AGSystem>
{
friend class AGSingleton<AGSystem>;

private:
	bool	_mShutDown;

protected:
	AGSystem	()	{};
	~AGSystem	()	{};

public:
	void	Initializze	();
	void	Destroy		();
	void	MainLoop	();

	void	ShutDown	()	{ _mShutDown = true; };
};