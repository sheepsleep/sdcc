/*-------------------------------------------------------------------------
   _memmove.c - part of string library functions

   Copyright (C) 1999, Sandeep Dutta . sandeep.dutta@usa.net
   Adapted By -  Erik Petrich  . epetrich@users.sourceforge.net
   from _memcpy.c which was originally

   This library is free software; you can redistribute it and/or modify it
   under the terms of the GNU General Public License as published by the
   Free Software Foundation; either version 2.1, or (at your option) any
   later version.

   This library is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License 
   along with this library; see the file COPYING. If not, write to the
   Free Software Foundation, 51 Franklin Street, Fifth Floor, Boston,
   MA 02110-1301, USA.

   As a special exception, if you link this library with other files,
   some of which are compiled with SDCC, to produce an executable,
   this library does not by itself cause the resulting executable to
   be covered by the GNU General Public License. This exception does
   not however invalidate any other reasons why the executable file
   might be covered by the GNU General Public License.
-------------------------------------------------------------------------*/
#include "string.h" 
#include <sdcc-lib.h>

#ifndef _SDCC_PORT_PROVIDES_MEMMOVE
#define _SDCC_PORT_PROVIDES_MEMMOVE 0
#endif

#if !_SDCC_PORT_PROVIDES_MEMMOVE

void * memmove (
	void * dst,
	void * src,
	size_t acount
	) 
{
	void * ret = dst;
	char * d;
	char * s;

	if (((int)src < (int)dst) && ((((int)src)+acount) > (int)dst)) {
		/*
		 * copy from higher addresses to lower addresses
		 */
		d = ((char *)dst)+acount-1;
		s = ((char *)src)+acount-1;
		while (acount--) {
			*d-- = *s--;
		}
	}
	else {
		/*
		 * copy from lower addresses to higher addresses
		 */
		d = dst;
		s = src;
		while (acount--) {
			*d++ = *s++;
		}
	}

	return(ret);
}
#endif

