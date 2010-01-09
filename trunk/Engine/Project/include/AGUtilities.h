#pragma once

#include "AGTypes.h"

//------------------------------------------------------------------------------------------------------------------------------
#define SAFE_DELETE(p)		\
{							\
	if (p)					\
	{						\
		delete p;			\
		p = NULL;			\
	}						\
}

//------------------------------------------------------------------------------------------------------------------------------
#define SAFE_RELEASE(p)		\
{							\
	if (p)					\
	{						\
		p->Release();		\
		p = NULL;			\
	}						\
}

//------------------------------------------------------------------------------------------------------------------------------
#define SAFE_NEW(p, type)	\
{							\
	if (!p)					\
	{						\
		p = new type;		\
	}						\
}

//------------------------------------------------------------------------------------------------------------------------------
#include <vector>
#include <map>

#define DefineVectorIterator(type, name)	typedef std::vector< type* >::iterator name
#define DefineMapIterator(IdType, type, name)	typedef std::map<IdType, type* >::iterator name

//------------------------------------------------------------------------------------------------------------------------------
#ifdef UNICODE
#undef UNICODE
#endif

bool Warning(bool _test, cStr _str);

#define WarningReturn(test, msg)	\
{									\
	if (Warning(test, msg))			\
	{								\
		return;						\
	}								\
}


//------------------------------------------------------------------------------------------------------------------------------
//------------------------------------------------------------------------------------------------------------------------------
class CRC
{
private:
	static u32	_mUlTable[256];

public:
	static void	Initialize	(void);
	static u32	GetCRC		(cStr sData);

private:
	static void	PartialCRC	(u32* ulCRC, cStr sData, u32 ulDataLength);
	static u32	Reflect		(u32 ulReflect, const s8 cChar);
};