/******************************************************************************
 *
 * Nagios plugins common include file
 *
 * License: GPL
 * Copyright (c) 1999 Ethan Galstad (nagios@nagios.org)
 *
 * Last Modified: 11-05-1999
 *
 * Description:
 *
 * This file contains common include files and defines used in many of
 * the plugins.
 *
 * License Information:
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.
 *
 *****************************************************************************/

#include <stdio.h>							/* obligatory includes */
#include <stdlib.h>
#include <errno.h>

#include "config.h"

#ifdef HAVE_STRINGS_H
#include <strings.h>
#endif
#ifdef HAVE_STRING_H
#include <string.h>
#endif

#ifdef HAVE_UNISTD_H
#include <unistd.h>
#endif

#ifdef TIME_WITH_SYS_TIME
# include <sys/time.h>
# include <time.h>
#else
# ifdef HAVE_SYS_TIME_H
#  include <sys/time.h>
# else
#  include <time.h>
# endif
#endif

#ifdef HAVE_SYS_TYPES_H
#include <sys/types.h>
#endif

#ifdef HAVE_SYS_SOCKET_H
#include <sys/socket.h>
#endif

#ifdef HAVE_SIGNAL_H
#include <signal.h>
#endif

/* TODO: define can be removed when all ifdef in each plugin has been removed */
#define HAVE_GETOPT_H
#include <getopt.h>

#include <ctype.h>

#if HAVE_LWRES_NETDB_H
#include <lwres/netdb.h>
#elif !HAVE_GETADDRINFO
#include "getaddrinfo.h"
#else
#include <netdb.h>
#endif

/*
 *
 * Missing Functions
 *
 */

#ifndef HAVE_STRTOL
# define strtol(a,b,c) atol((a))
#endif

#ifndef HAVE_STRTOUL
# define strtoul(a,b,c) (unsigned long)atol((a))
#endif

#ifndef HAVE_ASPRINTF
int asprintf(char **strp, const char *fmt, ...);
#endif

#ifndef HAVE_VASPRINTF
/* int vasprintf(char **strp, const char *fmt, va_list ap); */
#endif

#ifndef HAVE_SNPRINTF
int snprintf(char *str, size_t size, const  char  *format, ...);
#endif

#ifndef HAVE_VSNPRINTF
int vsnprintf(char *str, size_t size, const char  *format, va_list ap);
#endif

/*
 *
 * Standard Values
 *
 */

#define OK		0
#define ERROR		-1

#define TRUE		1
#define FALSE		0

#define	STATE_CRITICAL 	2				/* service state return codes */
#define STATE_WARNING 	1
#define STATE_OK       	0
#define STATE_UNKNOWN  	3
#define STATE_DEPENDENT	4

#define DEFAULT_SOCKET_TIMEOUT	10	/* timeout after 10 seconds */

#define MAX_INPUT_BUFFER	1024	/* max size of most buffers we use */

#define MAX_HOST_ADDRESS_LENGTH	256	/* max size of a host address */


#ifndef HAVE_SNPRINTF
/*
int snprintf (char *str, size_t n, const char *fmt, ...);
int snprintf (char *str, size_t n, const char *fmt, ...)
{
	char *buf;
	int i;
	int j=0;
	va_list ap;
	int d;
	char c, *p, *s;
	
	if((buf=malloc(n))==NULL){ 
		puts("could not malloc snprintf buffer\n");
		exit(-1);
	}
	va_start(ap,fmt);
	i=strlen(fmt);
	while((jj=index(&fmt[j],'%'))){
		j+=jj+1;
		switch fmt[j]
			{
			case 's':
				s = va_arg(ap, char *);
				i+=strlen(s);
				break;
			case 'd':
				d = va_arg(ap, int);
				i++;
				if (d<0) i++;
				while((d=d/10)>0) i++;
				break;
			case 'c':
				c = va_arg(ap, char);
				i++;
				break;
			}
	}
	va_end(ap);
	vsprintf(buf,fmt,ap);
	strcpy(str,buf[1:n-1]);
	exit(result);
}
*/
#endif