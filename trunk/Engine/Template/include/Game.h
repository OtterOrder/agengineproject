#include "AGGame.h"

class Game : public AGGame
{
public:
	Game	()	{};
	~Game	()	{};

	void	Init	();
	void	Destroy	();
	void	Update	();
};

AGGame* gGame = new Game;