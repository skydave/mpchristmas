

#include "Client.h"
#include <iostream>

#include "Message.h"





int Client::init()
{
	std::cout << "Client::init\n";

	// register message callbacks
	m_message_callbacks[ MSG_CLIENT_JOINGAME ] = &Client::client_join_game;

	m_client=0;
	m_client=grapple_client_init("testgame","1");
	grapple_client_address_set(m_client,NULL);
	grapple_client_port_set(m_client,1234);
	grapple_client_protocol_set(m_client,GRAPPLE_PROTOCOL_UDP);
	grapple_client_start(m_client,0);
	grapple_client_name_set(m_client,"mutti");

	std::cout << grapple_error_text(grapple_client_error_get(m_client)) << std::endl;

	// ping
	grapple_client_ping(m_client);

	// temp: immediately join game
	join_game();



	return 0;
}

bool Client::update()
{


	while (grapple_client_messages_waiting(m_client))
	{
		grapple_message *message = grapple_client_message_pull(m_client);

		switch (message->type)
		{
		case GRAPPLE_MSG_NEW_USER:
			//Your code to handle this message
			std::cout << "new user!\n";
			break;
		case GRAPPLE_MSG_NEW_USER_ME:
			//Your code to handle this message
			std::cout << "new user ME!\n";
			break;
		case GRAPPLE_MSG_USER_NAME:
			//Your code to handle this message
			std::cout << "user name!\n";
			break;
		case GRAPPLE_MSG_SESSION_NAME:
			//Your code to handle this message
			std::cout << "session name!\n";
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
				std::cerr << "Client::update: unable to handle message " << m.id() << std::endl;
		}break;
		case GRAPPLE_MSG_USER_DISCONNECTED:
			//Your code to handle this message
			std::cout << "user disconnected!\n";
			break;
		case GRAPPLE_MSG_SERVER_DISCONNECTED:
			//Your code to handle this message
			std::cout << "server disconnected!\n";
			break;
		case GRAPPLE_MSG_CONNECTION_REFUSED:
			//Your code to handle this message
			std::cout << "server connection refused!\n";
			break;
		case GRAPPLE_MSG_PING:
			//Your code to handle this message
			std::cout << "ping:" << message->PING.id << " " << message->PING.pingtime <<  std::endl;
			break;
		}
		grapple_message_dispose(message);
	}



	return false;
}

void Client::shutdown()
{
	std::cout << "Client::shutdown\n";
	grapple_client_destroy(m_client);
}


void Client::join_game()
{
	// send message to server that we now are joining the game
	Message m( MSG_CLIENT_JOINGAME );
	grapple_confirmid cid = grapple_client_send( m_client, GRAPPLE_SERVER, GRAPPLE_RELIABLE, m.data(), m.size() );
}

void Client::join_spectators()
{
	// send message to server that we now are not a player anymore
}




bool Client::client_join_game( grapple_user origin, Message *m )
{
	std::cout << "Client::client_join_game\n";
	// update client worldstate
	m_game.m_state.addPlayer( (int)origin );

	// if we are the origin then we have to setup the inputcontrols
	// TODO
}








