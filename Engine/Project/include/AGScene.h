#pragma once

#include "AGTypes.h"

#include "AGCamera.h"

#include <vector>
using namespace std;

//------------------------------------------------------------------------------------------------------------------------------
class AGScene
{
public:
	DefineVectorIterator(AGScene, Iterator);

public:
						AGScene  ();
	virtual				~AGScene ();

	virtual AGCamera*	GetCamera () =0;
	virtual void		Update () =0;
	virtual void		Draw () =0;
};