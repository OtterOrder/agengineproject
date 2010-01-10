#pragma once

#include "AGGame.h"
#include "AGTypes.h"
#include "AGUtilities.h"


class Game : public AGGame
{
private:
	u32 i;

public:
	Game	()	{};
	~Game	()	{};

	void	Init	();
	void	Destroy	();
	void	Update	();
};

AGGame* gGame = new Game;