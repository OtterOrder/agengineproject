#pragma once

#include <windows.h>

class AGTimer
{
public:
	AGTimer()	{};
	~AGTimer()	{};

	void	Initialize ();
	void	Update ();

	inline	float	GetTime ()		{ return _mTime; };
	inline	float	GetTimeMs ()	{ return GetTime()*1000.f; }

	inline	float	GetDt ()		{ return _mDt; };
	inline	float	GetDtMs ()		{ return GetDt()*1000.f; }

private:
	float			_mFreq;
	LARGE_INTEGER	_mStartTime;
	LARGE_INTEGER	_mCurrentTime;
	float			_mTime;
	float			_mDt;
};
