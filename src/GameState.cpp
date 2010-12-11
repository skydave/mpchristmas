#include "GameState.h"
#include <iostream>






GameState::~GameState()
{
}

void GameState::addPlayer( int id )
{
	std::cout << "GameState::addPlayer " << id << std::endl;
	Player *p = new Player();
	p->id = id;
	m_players[id] = p;
}


void GameState::removePlayer( int id )
{
}



Player *GameState::getPlayer( int id )
{
}
