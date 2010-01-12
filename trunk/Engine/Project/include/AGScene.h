#pragma once

#include "AGTypes.h"

#include "AGCamera.h"

#include <vector>
using namespace std;

//------------------------------------------------------------------------------------------------------------------------------
class AGScene
{
public:
	AGScene  ();
	~AGScene ();

	virtual AGCamera*	GetCamera () =0;
	virtual void		Update () =0;
};