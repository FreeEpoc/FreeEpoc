/*-
 * � Portions copyright (c) 2006 Nokia Corporation.  All rights reserved.
 * 
 * Copyright (c) 2002-2004 Tim J. Robbins.
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 *
 * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND
 * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE
 * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
 * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS
 * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
 * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
 * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY
 * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF
 * SUCH DAMAGE.
 */

#include <sys/cdefs.h>
__FBSDID("$FreeBSD: src/lib/libc/locale/mbsnrtowcs.c,v 1.1 2004/07/21 10:54:57 tjr Exp $");

#include <errno.h>
#include <limits.h>
#include <stdlib.h>
#include <wchar.h>
#ifndef __SYMBIAN32__
#include "mblocal.h"
#endif //__SYMBIAN32__

#if (defined(__SYMBIAN32__) && (defined(__WINSCW__) || defined(__WINS__)))
#include "libc_wsd_defs.h"
#endif 

#ifdef EMULATOR

GET_STATIC_VAR_FROM_TLS(mbsnrtowcs_mbs, mbstate_t)
#define mbs (*GET_WSD_VAR_NAME(mbsnrtowcs_mbs, s)())
#endif //EMULATOR

#ifdef __SYMBIAN32__
size_t __mbsnrtowcs_std(wchar_t * __restrict, const char ** __restrict,
   size_t, size_t, mbstate_t * __restrict);
#endif //__SYMBIAN32__

EXPORT_C size_t
mbsnrtowcs(wchar_t * __restrict dst, const char ** __restrict src,
    size_t nms, size_t len, mbstate_t * __restrict ps)
{
#ifndef EMULATOR	
	static mbstate_t mbs;
#endif //EMULATOR	

	if (ps == NULL)
		ps = &mbs;
#ifndef __SYMBIAN32__	
	return (__mbsnrtowcs(dst, src, nms, len, ps));
#else //__SYMBIAN32__
	return (__mbsnrtowcs_std(dst, src, nms, len, ps));
#endif //__SYMBIAN32__
}

size_t
__mbsnrtowcs_std(wchar_t * __restrict dst, const char ** __restrict src,
    size_t nms, size_t len, mbstate_t * __restrict ps)
{
	const char *s;
	size_t nchr;
	wchar_t wc;
	size_t nb;

	s = *src;
	nchr = 0;

	if (dst == NULL) {
		for (;;) {
#ifndef __SYMBIAN32__			
			if ((nb = __mbrtowc(&wc, s, nms, ps)) == (size_t)-1)
#else //__SYMBIAN32__
			if ((nb = mbrtowc(&wc, s, nms, ps)) == (size_t)-1)
#endif //__SYMBIAN32__
				/* Invalid sequence - mbrtowc() sets errno. */
				return ((size_t)-1);
			else if (nb == 0 || nb == (size_t)-2)
				return (nchr);
			s += nb;
			nms -= nb;
			nchr++;
		}
		/*NOTREACHED*/
	}

	while (len-- > 0) {
#ifndef __SYMBIAN32__		
		if ((nb = __mbrtowc(dst, s, nms, ps)) == (size_t)-1) 
#else //__SYMBIAN32__
		if ((nb = mbrtowc(dst, s, nms, ps)) == (size_t)-1) 
#endif //__SYMBIAN32__
		{
			*src = s;
			return ((size_t)-1);
		} else if (nb == (size_t)-2) {
			*src = s + nms;
			return (nchr);
		} else if (nb == 0) {
			*src = NULL;
			return (nchr);
		}
		s += nb;
		nms -= nb;
		nchr++;
		dst++;
#ifdef __SYMBIAN32__		
		if(nms == 0)
		{
			*src = s;
			return (nchr);
		}
#endif //__SYMBIAN32__		
	}
	*src = s;
	return (nchr);
}