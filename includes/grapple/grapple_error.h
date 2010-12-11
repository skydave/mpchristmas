/*
    Grapple - A fully featured network layer with a simple interface
    Copyright (C) 2006 Michael Simms

    This library is free software; you can redistribute it and/or
    modify it under the terms of the GNU Lesser General Public
    License as published by the Free Software Foundation; either
    version 2.1 of the License, or (at your option) any later version.

    This library is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
    Lesser General Public License for more details.

    You should have received a copy of the GNU Lesser General Public
    License along with this library; if not, write to the Free Software
    Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA

    Michael Simms
    michael@linuxgamepublishing.com
*/

#ifndef GRAPPLE_ERROR_H
#define GRAPPLE_ERROR_H

typedef enum
  {
    GRAPPLE_NO_ERROR=0,
    GRAPPLE_ERROR_NOT_INITIALISED,
    GRAPPLE_ERROR_SERVER_CONNECTED,
    GRAPPLE_ERROR_SERVER_NOT_CONNECTED,
    GRAPPLE_ERROR_SERVER_NOT_CONNECTABLE,
    GRAPPLE_ERROR_CLIENT_CONNECTED,
    GRAPPLE_ERROR_CLIENT_NOT_CONNECTED,
    GRAPPLE_ERROR_ADDRESS_NOT_SET,
    GRAPPLE_ERROR_PORT_NOT_SET,
    GRAPPLE_ERROR_NAME_NOT_SET,
    GRAPPLE_ERROR_NAME_NOT_UNIQUE,
    GRAPPLE_ERROR_SESSION_NOT_SET,
    GRAPPLE_ERROR_PROTOCOL_NOT_SET,
    GRAPPLE_ERROR_CANNOT_CONNECT,
    GRAPPLE_ERROR_NO_SUCH_USER,
    GRAPPLE_ERROR_SERVER_CANNOT_BIND_SOCKET,
    GRAPPLE_ERROR_BAD_PASSWORD,
    GRAPPLE_ERROR_NO_SUCH_GROUP,
#define GRAPPLE_ERROR_NO_SUCH_ROOM GRAPPLE_ERROR_NO_SUCH_GROUP
    GRAPPLE_ERROR_NO_SUCH_VARIABLE,
    GRAPPLE_ERROR_INCORRECT_VARIABLE_TYPE,
    GRAPPLE_ERROR_INSUFFICIENT_SPACE,
    GRAPPLE_ERROR_NO_MESSAGES,
    GRAPPLE_ERROR_NO_SUCH_GAME
  } grapple_error;

#ifdef __cplusplus
extern "C" {
#endif

extern const char *grapple_error_text(grapple_error);

#ifdef __cplusplus
}
#endif

#endif
