#pragma once

#include "AGInputs.h"
#include "AGInputManager.h"
#include "AGUtilities.h"

//------------------------------------------------------------------------------------------------------------------------------
class MouseInputs : public AGInputs
{
private:
	AGVector2s	_mPosition;

public:
	MouseInputs	();
	~MouseInputs	();

	void	Update ();

	inline static MouseInputs*	Get	(u32 _Id)	{ return (MouseInputs*)(AGGetInputs(_Id)); };

	inline AGVector2s GetPosition ()	{ return _mPosition; };
};