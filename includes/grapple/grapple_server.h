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

#ifndef GRAPPLE_SERVER_H
#define GRAPPLE_SERVER_H

#include "grapple_callback.h"
#include "grapple_protocols.h"
#include "grapple_message.h"
#include "grapple_error.h"
#include "grapple_defines.h"
#include "grapple_types.h"
#include "grapple_certificate.h"

#ifdef __cplusplus
extern "C" {
#endif

  typedef enum
    {
      GRAPPLE_NAMEPOLICY_NONE = 0,
      GRAPPLE_NAMEPOLICY_REQUIRED,
      GRAPPLE_NAMEPOLICY_UNIQUE
    } grapple_namepolicy;

  typedef enum
    {
      GRAPPLE_PROTECTIONKEYPOLICY_NONE = 0,
      GRAPPLE_PROTECTIONKEYPOLICY_UNIQUE
    } grapple_protectionkeypolicy;

  extern grapple_server grapple_server_init(const char *,const char *);
  extern int grapple_server_port_set(grapple_server,int);
  extern int grapple_server_port_get(grapple_server);
  extern int grapple_server_remote_port_get(grapple_server);
  extern int grapple_server_ip_set(grapple_server,const char *);
  extern const char *grapple_server_ip_get(grapple_server);
  extern int grapple_server_protocol_set(grapple_server,grapple_protocol);
  extern grapple_protocol grapple_server_protocol_get(grapple_server);
  extern int grapple_server_session_set(grapple_server,const char *);
  extern const char *grapple_server_session_get(grapple_server);
  extern int grapple_server_description_set(grapple_server,const void *,
					    size_t);
  extern int grapple_server_description_get(grapple_server,
						    void *,size_t *);
  extern int grapple_server_encryption_enable(grapple_server,const char *,
					      const char *,const char *,
					      const char *);

  extern int grapple_server_start(grapple_server);
  extern int grapple_server_running(grapple_server);
  extern int grapple_server_stop(grapple_server);
  extern int grapple_server_destroy(grapple_server);

  extern int grapple_server_namepolicy_set(grapple_server,grapple_namepolicy);
  extern grapple_namepolicy grapple_server_namepolicy_get(grapple_server);

  extern int grapple_server_protectionkeypolicy_set(grapple_server,
						    grapple_protectionkeypolicy);
  extern grapple_protectionkeypolicy grapple_server_ganekeypolicy_get(grapple_server);

  extern int grapple_server_enumgrouplist(grapple_server,
					  grapple_user_enum_callback,
					  void *);
  extern int grapple_server_enumgroup(grapple_server,
				      grapple_user,
				      grapple_user_enum_callback,
				      void *);
  extern int grapple_server_enumusers(grapple_server,
				      grapple_user_enum_callback,
				      void *);


  extern int grapple_server_sequential_set(grapple_server,int);
  extern int grapple_server_sequential_get(grapple_server);

  extern int grapple_server_failover_set(grapple_server,int);
  extern int grapple_server_failover_get(grapple_server);

  extern int grapple_server_maxusers_set(grapple_server,int);
  extern int grapple_server_maxusers_get(grapple_server);
  extern int grapple_server_currentusers_get(grapple_server);

  extern int grapple_server_password_set(grapple_server,const char *);
  extern int grapple_server_passwordhandler_set(grapple_server,
						grapple_password_callback,
						void *);
  extern int grapple_server_password_required(grapple_server);

  extern int grapple_server_connectionhandler_set(grapple_server,
						  grapple_connection_callback,
						  void *);

  extern int grapple_server_messagecount_get(grapple_server);
  extern int grapple_server_messages_waiting(grapple_server);

  extern grapple_message *grapple_server_message_pull(grapple_server);

  extern grapple_confirmid grapple_server_send(grapple_server,grapple_user,
					       int,const void *,size_t);

  extern grapple_user *grapple_server_userlist_get(grapple_server);

  extern int grapple_server_callback_set(grapple_server,
					 grapple_messagetype,
					 grapple_callback,
					 void *);
  extern int grapple_server_callback_setall(grapple_server,
					    grapple_callback,
					    void *);
  extern int grapple_server_callback_unset(grapple_server,
					   grapple_messagetype);

  extern grapple_server grapple_server_default_get(void);

  extern int grapple_server_closed_get(grapple_server);
  extern void grapple_server_closed_set(grapple_server,int);

  extern int grapple_server_disconnect_client(grapple_server,grapple_user);

  extern int grapple_server_ping(grapple_server,grapple_user);
  extern double grapple_server_ping_get(grapple_server,grapple_user);
  extern int grapple_server_autoping(grapple_server,double);

  extern grapple_user grapple_server_group_create(grapple_server,const char *,
						  const char *);
  extern int grapple_server_group_add(grapple_server,grapple_user,
				      grapple_user,const char *);
  extern int grapple_server_group_remove(grapple_server,grapple_user,
					 grapple_user);
  extern int grapple_server_group_delete(grapple_server,grapple_user);
  extern grapple_user grapple_server_group_from_name(grapple_server,const char *);
  extern grapple_user *grapple_server_groupusers_get(grapple_server,
						     grapple_user);

  extern grapple_user *grapple_server_grouplist_get(grapple_server);

  extern int grapple_server_maxgroups_set(grapple_server,int);
  extern int grapple_server_maxgroups_get(grapple_server);

  extern int grapple_server_notified_set(grapple_server,int);

  extern char *grapple_server_client_address_get(grapple_server,
						 grapple_user);
  extern int grapple_server_client_port_get(grapple_server,grapple_user);
  extern int grapple_server_client_sending_port_get(grapple_server,
						    grapple_user);
  extern char *grapple_server_groupname_get(grapple_server,grapple_user);

  extern int grapple_server_nattrav_address(grapple_server,const char *,int);

  extern int grapple_server_set_as_nattrav_server(grapple_server,
						  const char *,int,int,int);

  grapple_nat_type grapple_server_nattrav_type_get(grapple_server);
  const char *grapple_server_nattrav_type_string_get(grapple_server);

  extern grapple_error grapple_server_error_get(grapple_server);

  extern int grapple_server_dummystart(grapple_server);
  extern int grapple_server_dummystop(grapple_server);

  extern void grapple_server_intvar_set(grapple_server,const char *,int);
  extern int grapple_server_intvar_get(grapple_server,const char *);
  extern void grapple_server_doublevar_set(grapple_server,const char *,double);
  extern double grapple_server_doublevar_get(grapple_server,const char *);
  extern void grapple_server_datavar_set(grapple_server,const char *,
					 void *,size_t);
  extern int grapple_server_datavar_get(grapple_server,const char *,
					void *,size_t *);
 
  extern grapple_certificate *grapple_server_user_certificate_get(grapple_server,grapple_user);

  extern char *grapple_server_user_name_get(grapple_server,grapple_user);
  extern int grapple_server_dispatchers_set(grapple_server,int);


#ifdef __cplusplus
}
#endif

#endif
