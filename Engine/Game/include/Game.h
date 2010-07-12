#pragma once

#include "AGGame.h"
#include "AGTypes.h"
#include "AGUtilities.h"

#include "AG3DCamera.h"
#include "AG3DGraphicEntity.h"


class Game : public AGGame
{
private:
	AG3DCamera*			_mCamera;
	AG3DGraphicEntity*	_mBat;

	u32					_mMouseInputsId;

public:
	Game	()	{};
	~Game	()	{};

	void	InitEngine	();
	void	Init		();
	void	Destroy		();
	void	Update		();
};

AGGame* gGame = new Game;