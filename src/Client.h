#pragma once
#include <stdlib.h>
#include <grapple.h>
#include "Message.h"
#include "Game.h"


//
//
//
class Client
{
public:
	typedef bool (Client::*MessageCallback)(grapple_user origin, Message *);

	int init();
	bool update();
	void shutdown();

	void join_game();
	void join_spectators();


	bool client_join_game( grapple_user origin, Message *m ); // another peer (or we ourselfs) has joined the game


	grapple_client m_client;
	Game             m_game;

	std::map<char, MessageCallback> m_message_callbacks;
};



