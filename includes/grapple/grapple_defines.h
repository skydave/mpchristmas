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

#ifndef GRAPPLE_DEFINES_H
#define GRAPPLE_DEFINES_H

//Transmit flags for messages
#define GRAPPLE_RELIABLE    (0x0001)
#define GRAPPLE_CONFIRM     (0x0002)
#define GRAPPLE_WAIT        (0x0004)

//A define to mean 'the server gets this message'
#define GRAPPLE_SERVER (1)
//A define to mean 'everyone gets this message'
#define GRAPPLE_EVERYONE (2)
#define GRAPPLE_EVERYONEELSE (3)

//Return values
#define GRAPPLE_OK (1)
#define GRAPPLE_FAILED (-1)

//Open or closed state
#define GRAPPLE_SERVER_OPEN (0)
#define GRAPPLE_SERVER_CLOSED (1)

//Sequential ON or OFF
#define GRAPPLE_SEQUENTIAL (1)
#define GRAPPLE_NONSEQUENTIAL (2)

//The unknown player ID
#define GRAPPLE_USER_UNKNOWN (0)

//Whether to notify the client of other clients
#define GRAPPLE_NOTIFY_STATE_ON (1)
#define GRAPPLE_NOTIFY_STATE_OFF (0)

//Grapple group number limiting
#define GRAPPLE_GROUPS_UNLIMITED (0)
#define GRAPPLE_GROUPS_DISABLED (-1)


typedef enum
  {
    GRAPPLE_NAT_UNKNOWN          = 0,
    GRAPPLE_NAT_OPEN             = 1,
    GRAPPLE_NAT_FULL_CONE        = 2,
    GRAPPLE_NAT_PORT_RESTRICTED  = 3,
    GRAPPLE_NAT_HOST_RESTRICTED  = 4,
    GRAPPLE_NAT_SYMMETRIC        = 5
  } grapple_nat_type;


#endif
