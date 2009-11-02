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

/* service_tcp
 * 
 * Purpose:
 *
 * This file eats an *IP-packet and tcp-header and adds/enter
 * a service to asset if any match is made, and the fingerprint.
 *
 * Arguments:
 *   
 * *IP-packet, tcp-header
 *
 * Effect:
 *
 * Adds a fingerprint match and the fingerprint it matched
 * to the asset
 *
 * Comments:
 *
 * Old school...
 */

#include <pcre.h>

//if (ret != -1) {
//   study = pcre_study (regex, 0, &err);
//   if (err != NULL)
//      printf("Unable to study signature:  %s", err);
//}


/* service_tcp(*ip6,*tcph)*/
void service_tcp4 (ip4_header *ip4, tcp_header *tcph, char *payload,int plen) {

   pcre       *regex;
   pcre_extra *study;
   const char *err = NULL;     /* PCRE */
   int        erroffset,ret,rc;   /* PCRE */
   int        ovector[15];
   const char *stringr = "Server: Apache";

   if ( (regex = pcre_compile (stringr, 0, &err, &erroffset, NULL)) == NULL) {
      printf("Unable to compile signature.");
      ret = -1;
   }

   if (ret != -1) {
      study = pcre_study (regex, 0, &err);
      if (err != NULL)
         printf("Unable to study signature:  %s", err);
   }

   rc = pcre_exec(regex, study, payload, plen, 0, 0, ovector, 15);

   if (rc != -1) {
      printf("MATCH: %s\n",stringr);
      return ;
   }
   //else {
   //   printf("%s",payload);
   //}
   return;
}

void service_tcp6 (ip6_header *ip6, tcp_header *tcph) {
   return;
}

