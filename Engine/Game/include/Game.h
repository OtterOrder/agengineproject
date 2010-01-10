#pragma once

#include "AGGame.h"
#include "AGTypes.h"
#include "AGUtilities.h"


class Game : public AGGame
{
private:

public:
	Game	()	{};
	~Game	()	{};

	void	InitEngine	();
	void	Init		();
	void	Destroy		();
	void	Update		();
};

AGGame* gGame = new Game;