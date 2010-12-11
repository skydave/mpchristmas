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

#ifndef GRAPPLE_CLIENT_H
#define GRAPPLE_CLIENT_H

#include <sys/types.h>

#include "grapple_callback.h"
#include "grapple_error.h"
#include "grapple_protocols.h"
#include "grapple_message.h"
#include "grapple_types.h"
#include "grapple_certificate.h"

#ifdef __cplusplus
extern "C" {
#endif

  extern grapple_client grapple_client_init(const char *,const char *);
  extern int grapple_client_address_set(grapple_client,const char *);
  extern int grapple_client_port_set(grapple_client,int);
  extern int grapple_client_sourceport_set(grapple_client,int);
  extern int grapple_client_protocol_set(grapple_client,grapple_protocol);
  extern int grapple_client_password_set(grapple_client,const char *);
  extern int grapple_client_encryption_enable(grapple_client,
					      const char *,const char *,
					      const char *,const char *);

  extern int grapple_client_nattrav_address(grapple_client,
					    const char *,int);

  extern int grapple_client_protectionkey_set(grapple_client,const char *);
  extern int grapple_client_start(grapple_client,int);
  extern int grapple_client_stop(grapple_client);
  extern int grapple_client_destroy(grapple_client);

  extern int grapple_client_connected(grapple_client);

  extern int grapple_client_name_set(grapple_client,const char *);

  extern int grapple_client_messagecount_get(grapple_client);
  extern int grapple_client_messages_waiting(grapple_client);

  extern char *grapple_client_session_get(grapple_client);

  extern int grapple_client_sequential_set(grapple_client,int);
  extern int grapple_client_sequential_get(grapple_client);

  extern int grapple_client_notified_set(grapple_client,int);

  extern grapple_message *grapple_client_message_pull(grapple_client);

  extern grapple_confirmid grapple_client_send(grapple_client,
					       grapple_user,
					       int,const void *,size_t);

  extern grapple_user *grapple_client_userlist_get(grapple_client);

  extern int grapple_client_callback_set(grapple_client,
					 grapple_messagetype,
					 grapple_callback,
					 void *);
  extern int grapple_client_callback_setall(grapple_client,
					    grapple_callback,
					    void *);
  extern int grapple_client_callback_unset(grapple_client,
					   grapple_messagetype);


  extern grapple_client grapple_client_default_get(void);
  extern char *grapple_client_name_get(grapple_client,grapple_user);

  extern int grapple_client_enumusers(grapple_client,
				      grapple_user_enum_callback,
				      void *);
  extern int grapple_client_enumgroup(grapple_client,
				      grapple_user,
				      grapple_user_enum_callback,
				      void *);
  extern int grapple_client_enumgrouplist(grapple_client,
					  grapple_user_enum_callback,
					  void *);

  extern int grapple_client_ping(grapple_client);
  extern double grapple_client_ping_get(grapple_client,grapple_user);
  extern grapple_user grapple_client_serverid_get(grapple_client);

  extern grapple_user grapple_client_group_create(grapple_client,const char *,
						  const char *);
  extern int grapple_client_group_add(grapple_client,grapple_user,
				      grapple_user,const char *);
  extern int grapple_client_group_remove(grapple_client,grapple_user,
					 grapple_user);
  extern int grapple_client_group_delete(grapple_client,grapple_user);
  extern int grapple_client_group_passwordneeded(grapple_client,grapple_user);

  extern grapple_user grapple_client_group_from_name(grapple_client,
						     const char *);
  extern grapple_user *grapple_client_groupusers_get(grapple_client,
						     grapple_user);
  extern grapple_user *grapple_client_grouplist_get(grapple_client);
  extern char *grapple_client_groupname_get(grapple_client,grapple_user);

  extern void grapple_client_intvar_set(grapple_client,const char *,int);
  extern int grapple_client_intvar_get(grapple_client,const char *);
  extern void grapple_client_doublevar_set(grapple_client,const char *,double);
  extern double grapple_client_doublevar_get(grapple_client,const char *);
  extern void grapple_client_datavar_set(grapple_client,const char *,void *,size_t);
  extern int grapple_client_datavar_get(grapple_client,const char *,void *,size_t *);

  extern grapple_error grapple_client_error_get(grapple_client);

  extern grapple_certificate *grapple_client_certificate_get(grapple_client);

  extern grapple_protocol grapple_client_protocol_get(grapple_client);
  extern int grapple_client_dispatchers_set(grapple_client,int);

#ifdef __cplusplus
}
#endif

#endif
