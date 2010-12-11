#pragma once
#include <stdlib.h>
#include <grapple.h>
#include <map>

#include "Game.h"
#include "Message.h"


//
//
//
class Server
{
public:
	typedef bool (Server::*MessageCallback)(grapple_user origin, Message *);

	int init();
	bool update();
	void shutdown();


	bool client_join_game( grapple_user origin, Message *m );


	grapple_server m_server;
	Game             m_game;

	std::map<char, MessageCallback> m_message_callbacks;
};
