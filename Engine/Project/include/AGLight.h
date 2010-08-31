#pragma once

#include "AG3DEntity.h"

//------------------------------------------------------------------------------------------------------------------------------
class AGLight : public AG3DEntity
{
public:
	DefineVectorIterator(AGLight, Iterator);

	typedef enum Type
	{
		None		= 0,
		Directional	= 1,
		Point		= 2,
		Spot		= 3
	} Type;

private:
	AGLight::Type		_mType;

protected:
	AGVector3f	_mDiffuse;
	AGVector3f	_mSpecular;

public:
						AGLight		(Type _Type = None);
	virtual				~AGLight	();

			void		SetDiffuse  (float _R, float _G, float _B);
			void		SetSpecular (float _R, float _G, float _B);

	inline	AGVector3f	GetDiffuse  ()	{ return _mDiffuse;  }
	inline	AGVector3f	GetSpecular ()	{ return _mSpecular; }

	inline	Type		GetType		()	{ return _mType; }			
};