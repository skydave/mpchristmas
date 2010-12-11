#include "Server.h"
#include <iostream>







int Server::init()
{
	std::cout << "Server::init\n";

	// register message callbacks
	m_message_callbacks[ MSG_CLIENT_JOINGAME ] = &Server::client_join_game;

	m_server=grapple_server_init("testgame","1");
	grapple_server_ip_set(m_server,"127.0.0.1");   //OPTIONAL FUNCTION
	grapple_server_port_set(m_server,1234);
	grapple_server_protocol_set(m_server,GRAPPLE_PROTOCOL_UDP);
	grapple_server_session_set(m_server,"Play my game");
	grapple_server_start(m_server);

	std::cout << grapple_error_text(grapple_server_error_get(m_server)) << std::endl;

	return 0;
}

bool Server::update()
{


	if (grapple_server_messages_waiting(m_server))
	{
		grapple_message *message = grapple_server_message_pull(m_server);
		switch (message->type)
		{
		case GRAPPLE_MSG_NEW_USER:
			//Your code to handle this message
			std::cout << "new user!\n";
			break;
		case GRAPPLE_MSG_USER_NAME:
			//Your code to handle this message
			std::cout << "user name!\n";
			break;
		case GRAPPLE_MSG_USER_MSG:
		{
			grapple_user origin = message->USER_MSG.id;
			Message m( message->USER_MSG.data, message->USER_MSG.length );
			if( m_message_callbacks.find( m.id() ) != m_message_callbacks.end() )
			{
				// callback
				MessageCallback t = m_message_callbacks[m.id()];//( &m );
				(this->*t)( origin, &m );
			}
			else
				std::cerr << "Server::update: unable to handle message " << m.id() << std::endl;
		}break;
		case GRAPPLE_MSG_USER_DISCONNECTED:
			//Your code to handle this message
			std::cout << "user disconnected!\n";
			break;
		}
		grapple_message_dispose(message);
	}



	return false;
}

void Server::shutdown()
{
	std::cout << "Server::shutdown\n";
	grapple_server_destroy(m_server);
}

bool Server::client_join_game( grapple_user origin, Message *m )
{
	std::cout << "Server::client_join_game\n";
	// update server worldstate
	m_game.m_state.addPlayer( (int)origin );

	// update all clients
	grapple_confirmid cid = grapple_server_send( m_server, GRAPPLE_EVERYONE, GRAPPLE_RELIABLE, m->data(), m->size() );
}

