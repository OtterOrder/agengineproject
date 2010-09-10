#include "AGSamplerState.h"

//------------------------------------------------------------------------------------------------------------------------------
//------------------------------------------------------------------------------------------------------------------------------
AGSamplerState::AGSamplerState(AGFiltering _MinFilter, AGFiltering _MagFilter,
							   AGAdressing _AdreesU,   AGAdressing _AdressV)
{
	SetMinFilter(_MinFilter);
	SetMagFilter(_MagFilter);
	SetAdressU  (_AdreesU);
	SetAdressV  (_AdressV);
}

//------------------------------------------------------------------------------------------------------------------------------
AGSamplerState::~AGSamplerState()
{
}