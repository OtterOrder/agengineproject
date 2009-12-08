#pragma once

#include "Utilities.h"

//------------------------------------------------------------------------------------------------------------------------------
//------------------------------------------------------------------------------------------------------------------------------
class AGSingleton
{
public:
	AGSingleton				()	{};
	virtual ~AGSingleton	()	{};
};

//------------------------------------------------------------------------------------------------------------------------------
//------------------------------------------------------------------------------------------------------------------------------
#define DeclareSingleton(Singleton)			\
private :									\
	static Singleton*	_mInstance;			\
	Singleton	() {};						\
	~Singleton	() { DestroySingleton(); };	\
											\
public :									\
	inline static Singleton* GetSingleton()	\
	{										\
		SAFE_NEW(_mInstance, Singleton);	\
		return _mInstance;					\
	}										\
											\
	static void DestroySingleton()			\
	{										\
		SAFE_DELETE(_mInstance);			\
	}

//------------------------------------------------------------------------------------------------------------------------------
#define InitSingleton(Singleton)			\
Singleton* Singleton::_mInstance = NULL;
