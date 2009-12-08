#pragma once

#include "AGUtilities.h"

//------------------------------------------------------------------------------------------------------------------------------
//------------------------------------------------------------------------------------------------------------------------------
template< typename T >
class AGSingleton
{
private:
	static T*	_mInstance;

protected:
			 AGSingleton	()	{};
	virtual ~AGSingleton	()	{};

public:
	static inline T* GetSingleton()
	{
		SAFE_NEW(_mInstance, T);
		return _mInstance;
	};

	static void DestroySingleton()
	{
		SAFE_DELETE(_mInstance);
	};
};

//------------------------------------------------------------------------------------------------------------------------------
template< typename T >
T* AGSingleton< T >::_mInstance = NULL;
