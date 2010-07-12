#include "MouseInputs.h"

#include <Windows.h>

//------------------------------------------------------------------------------------------------------------------------------
//------------------------------------------------------------------------------------------------------------------------------
MouseInputs::MouseInputs()
{
}

//------------------------------------------------------------------------------------------------------------------------------
MouseInputs::~MouseInputs()
{
}

//------------------------------------------------------------------------------------------------------------------------------
//------------------------------------------------------------------------------------------------------------------------------
void MouseInputs::Update()
{
	POINT lPosition;
	if(GetCursorPos(&lPosition))
	{
		_mPosition.x = lPosition.x;
		_mPosition.y = lPosition.y;
	}
}