#pragma once


#include "GameState.h"
#include "gfx/Camera.h"


//
//
//
class Game
{
public:


	void render();
	void renderPlayer( Player* );



	GameState m_state;
	Camera   m_camera;
};
