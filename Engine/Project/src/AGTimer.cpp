#include	"AGTimer.h"

//------------------------------------------------------------------------------------------------------------------------------
//------------------------------------------------------------------------------------------------------------------------------
void AGTimer::Initialize()
{
	LARGE_INTEGER freq;
	QueryPerformanceFrequency( &freq );
	QueryPerformanceCounter( &_mStartTime );

	_mFreq			= (float)freq.QuadPart;
	_mCurrentTime	= _mStartTime;
	_mTime			= 0.f;
	_mDt			= 0.f;
}

//------------------------------------------------------------------------------------------------------------------------------
void AGTimer::Update()
{
	LARGE_INTEGER currentTime;
	QueryPerformanceCounter( &currentTime );

	_mDt			= (float)(currentTime.QuadPart-_mCurrentTime.QuadPart) / _mFreq;
	_mCurrentTime	= currentTime;
	_mTime			= (float)(_mCurrentTime.QuadPart-_mStartTime.QuadPart) / _mFreq;
}
