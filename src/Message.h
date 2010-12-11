#pragma once
#include <iostream>
#include <string>

#define MSG_CLIENT_JOINGAME 1



struct Message
{
	Message( void *data, int size );
	Message( unsigned char id );
	~Message();

	//
	void *data();
	int size();
	unsigned char id();

	//
	unsigned char readUChar();
	void writeUChar( unsigned char c );
	//int readInt();
	//float readFloat();
	//std::string readString();



	unsigned char m_id;
	unsigned char *m_data;
	int m_size;
	int m_pos;


	bool m_managed; // indicates if m_data is owns m_data and therefore frees it when the message is deconstructed
};
