#pragma once

#include "AGUtilities.h"

//------------------------------------------------------------------------------------------------------------------------------
//------------------------------------------------------------------------------------------------------------------------------
template< typename T >
class AGSingleton
{
private:
	static T	_mInstance;

protected:
					AGSingleton		()	{};
	virtual			~AGSingleton	()	{};

	virtual	void	Destroy			()	=0;

public:
	static inline T* GetSingleton()
	{
		return &_mInstance;
	};

	static void DestroySingleton()
	{
		_mInstance.Destroy();
	};
};

//------------------------------------------------------------------------------------------------------------------------------
template< typename T >
T AGSingleton< T >::_mInstance;
