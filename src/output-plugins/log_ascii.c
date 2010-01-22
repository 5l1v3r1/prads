/*
** Copyright (C) 2009 Redpill Linpro, AS.
** Copyright (C) 2009 Edward Fjellskål <edward.fjellskaal@redpill-linpro.com>
**
** This program is free software; you can redistribute it and/or modify
** it under the terms of the GNU General Public License Version 2 as
** published by the Free Software Foundation.  You may not use, modify or
** distribute this program under any other version of the GNU General
** Public License.
**
** This program is distributed in the hope that it will be useful,
** but WITHOUT ANY WARRANTY; without even the implied warranty of
** MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
** GNU General Public License for more details.
**
** You should have received a copy of the GNU General Public License
** along with this program; if not, write to the Free Software
** Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.
*/

/* $Id$ */

/* log_ascii
 *
 * Purpose:
 *
 * This output module provides the default packet logging funtionality
 *
 * Arguments:
 *
 * none
 *
 * Effect:
 *
 * Logs are written to a text output file
 *
 * Comments:
 * Format should be something like this:
 * [N|U]||IP||ASSET
 * N=NEW U=UPDATED
 * 
 * N||192.168.0.5||[client:User Agent: lwp-request/5.818 libwww-perl/5.820:80:6]
 * N||192.168.0.5||[syn:S4:64:1:60:M1460,S,T,N,W7:!:Linux:something]
 * N||192.168.0.1||[service:Server: Apache:80:6]
 * U||192.168.0.1||[synack:5792:55:1:60:M1460,S,T,N,W5:ZAT!:Linux:something else]
 * U||192.168.0.1||[uptime:300hrs]
 *
 * Old school...
 */
