#pragma once

//------------------------------------------------------------------------------------------------------------------------------
class AGTextureFilter
{
public:
	typedef enum _AGFiltering
	{
		None	= 0,
		Point	= 1,
		Linear	= 2
	} AGFiltering;

private:
	AGFiltering	_mMinFilter;
	AGFiltering	_mMagFilter;

public:
								AGTextureFilter		(AGFiltering _MinFilter = Linear, AGFiltering _MagFilter = Linear);
								~AGTextureFilter	();

	inline	void				SetMinFilter		(AGFiltering _Filter)	{ _mMinFilter = _Filter;	}
	inline	AGFiltering			GetMinFilter		()						{ return _mMinFilter;		}
	inline	void				SetMagFilter		(AGFiltering _Filter)	{ _mMagFilter = _Filter;	}
	inline	AGFiltering			GetMagFilter		()						{ return _mMagFilter;		}
};