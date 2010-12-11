#pragma once

#include <map>


struct Player
{
	int id;
};

//
// represents the world, will be syncronised between client/server
//
class GameState
{
public:
	~GameState();

	void addPlayer( int id = 0 );
	void removePlayer( int id );
	Player *getPlayer( int id );



	std::map<int, Player *>  m_players;

};
