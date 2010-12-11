#include "Message.h"
#include <stdio.h>
#include <stdlib.h>




Message::Message( void *data, int size ):m_id(0), m_data((unsigned char*)data), m_size(size), m_pos(0), m_managed(false)
{
	// extract id from data
	m_id = readUChar();
}

Message::Message( unsigned char id ):m_id(id), m_data(0), m_size(0), m_pos(0), m_managed(true)
{
	writeUChar( m_id );
}


Message::~Message()
{
	if( m_managed && m_data != 0 )
		free( m_data );
}

void *Message::data()
{
	return m_data;
}

int Message::size()
{
	return m_size;
}

unsigned char Message::id()
{
	return m_id;
}


unsigned char Message::readUChar()
{
	unsigned char c = m_data[m_pos];
	m_pos += 1;
	return c;
}

void Message::writeUChar( unsigned char c )
{
	m_data = (unsigned char *)realloc( m_data, m_size + 1 );
	m_data[m_pos] = c;
	m_pos += 1;
	m_size += 1;
}
