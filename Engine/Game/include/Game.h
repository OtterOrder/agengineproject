#pragma once

#include "AGGame.h"
#include "AGTypes.h"
#include "AGUtilities.h"

#include "AG3DScene.h"
#include "AG3DCamera.h"
#include "AG3DGraphicEntity.h"


class Game : public AGGame
{
private:
	AG3DScene*			_mScene;
	AG3DCamera*			_mCamera;
	AG3DGraphicEntity*	_mBat;
	AG3DGraphicEntity*	_mBat2;

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