#pragma once

#include "AGSingleton.h"

#include "AGScene.h"
#include "AG3DScene.h"

//------------------------------------------------------------------------------------------------------------------------------
class AGSceneManager : public AGSingleton<AGSceneManager>
{
friend class AGSingleton<AGSceneManager>;

vector<AGScene*>	_mpScenes;

protected:
			AGSceneManager		();
			~AGSceneManager		();
	void	Destroy				();

public:
			void				Update	();
			void				Draw ();

			AG3DScene*			GetNew3DScene ();
};