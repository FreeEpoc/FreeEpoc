/*--------------------------------------------------------------------
 *� Portions copyright (c) 2006 Nokia Corporation.  All rights reserved.
 *--------------------------------------------------------------------
*/
#include <sys/cdefs.h>
#ifndef __SYMBIAN32__
__FBSDID("$FreeBSD: src/lib/msun/src/s_llround.c,v 1.2 2005/04/08 00:52:27 das Exp $");
#endif //__SYMBIAN32__

#define type		double
#define	roundit		round
#define dtype		long long
#define	DTYPE_MIN	LLONG_MIN
#define	DTYPE_MAX	LLONG_MAX
#define	fn		llround

#include "s_lround.c"
