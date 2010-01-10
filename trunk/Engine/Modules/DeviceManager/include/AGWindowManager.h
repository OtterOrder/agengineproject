#pragma once

#include "AGTypes.h"
#include "AGSingleton.h"

#ifdef AGDX9
#include "AGTypesDX9.h"
#endif

#include <Windows.h>


//------------------------------------------------------------------------------------------------------------------------------
class AGWindowManager : public AGSingleton<AGWindowManager>
{
friend class AGSingleton<AGWindowManager>;

private:
	AGVector2u	_mSize;
	cStr		_mName;
	HWND		_mWindow;


protected:
	AGWindowManager		()	{};
	~AGWindowManager	()	{};

public:
	//
	void	Initialize ();

	// Resolution
	inline	const u32&			GetWidth	()	const	{ return _mSize.x; };
	inline	const u32&			GetHeight	()	const	{ return _mSize.y; };
	inline	const AGVector2u&	GetSize		()	const	{ return _mSize; };

	inline void		SetWidth	(u32 _x)			{ _mSize.x = _x; };
	inline void		SetHeight	(u32 _y)			{ _mSize.x = _y; };
	inline void		SetSize		(AGVector2u _Size)	{ _mSize = _Size; };
	inline void		SetSize		(u32 _x, u32 _y)	{ _mSize.x = _x; _mSize.y = _y; };

	// Name
	inline const cStr&	GetName ()	const		{ return _mName; };
	inline void			SetName	(cStr _Name)	{ _mName = _Name; };

	// Window
	inline const HWND&	GetWindow	()			{ return _mWindow; };
};