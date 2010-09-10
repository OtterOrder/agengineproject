#pragma once

//------------------------------------------------------------------------------------------------------------------------------
class AGSamplerState
{
public:
	typedef enum _AGGFiltering
	{
		None	= 0,
		Point	= 1,
		Linear	= 2
	} AGFiltering;

	typedef enum _AGAdressing
	{
		Wrap	= 1,
		Mirror	= 2,
		Clamp	= 3,
		Border	= 4,
	} AGAdressing;

private:
	AGFiltering	_mMinFilter;
	AGFiltering	_mMagFilter;
	AGAdressing _mAdressU;
	AGAdressing	_mAdressV;

public:
								AGSamplerState		(AGFiltering _MinFilter = Linear, AGFiltering _MagFilter = Linear,
													 AGAdressing _AdreesU   = Wrap,   AGAdressing _AdressV   = Wrap);
								~AGSamplerState	();

	inline	void				SetMinFilter		(AGFiltering _Filter)	{ _mMinFilter = _Filter;}
	inline	AGFiltering			GetMinFilter		()						{ return _mMinFilter;	}
	inline	void				SetMagFilter		(AGFiltering _Filter)	{ _mMagFilter = _Filter;}
	inline	AGFiltering			GetMagFilter		()						{ return _mMagFilter;	}

	inline	void				SetAdressU			(AGAdressing _Adress)	{ _mAdressU = _Adress;	}
	inline	AGAdressing			GetAdressU			()						{ return _mAdressU;		}
	inline	void				SetAdressV			(AGAdressing _Adress)	{ _mAdressV = _Adress;	}
	inline	AGAdressing			GetAdressV			()						{ return _mAdressV;		}
};