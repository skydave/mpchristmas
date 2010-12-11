#pragma once


#include "GameState.h"


//
//
//
class Game
{
public:


	void render();
	void renderPlayer( Player* );



	GameState m_state;
};
