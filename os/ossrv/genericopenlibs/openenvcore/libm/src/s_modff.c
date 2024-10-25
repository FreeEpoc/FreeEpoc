/*--------------------------------------------------------------------
 *� Portions copyright (c) 2006 Nokia Corporation.  All rights reserved.
 *--------------------------------------------------------------------
*/
/* s_modff.c -- float version of s_modf.c.
 * Conversion to float by Ian Lance Taylor, Cygnus Support, ian@cygnus.com.
 */

/*
 * ====================================================
 * Copyright (C) 1993 by Sun Microsystems, Inc. All rights reserved.
 *
 * Developed at SunPro, a Sun Microsystems, Inc. business.
 * Permission to use, copy, modify, and distribute this
 * software is freely granted, provided that this notice
 * is preserved.
 * ====================================================
 */
#ifndef __SYMBIAN32__
#ifndef lint
static char rcsid[] = "$FreeBSD: src/lib/msun/src/s_modff.c,v 1.7 2002/05/28 18:15:04 alfred Exp $";
#endif
#endif //__SYMBIAN32__

#include <math.h>
#include "math_private.h"

static const float one = 1.0;

EXPORT_C float
modff(float x, float *iptr)
{
	int32_t i0,j0;
	u_int32_t i;
	GET_FLOAT_WORD(i0,x);
	/*if x is NAN, return NAN with iptr = NAN*/
	#ifdef __SYMBIAN32__	
	if ( (i0&0x7FFFFFFF) == 0x7FC00000)
	{	*iptr = x;
	 	return x;
	}
	#endif //__SYMBIAN32__
	j0 = ((i0>>23)&0xff)-0x7f;	/* exponent of x */
	if(j0<23) {			/* integer part in x */
	    if(j0<0) {			/* |x|<1 */
	        SET_FLOAT_WORD(*iptr,i0&0x80000000);	/* *iptr = +-0 */
		return x;
	    } else {
		i = (0x007fffff)>>j0;
		if((i0&i)==0) {			/* x is integral */
		    u_int32_t ix;
		    *iptr = x;
		    GET_FLOAT_WORD(ix,x);
		    SET_FLOAT_WORD(x,ix&0x80000000);	/* return +-0 */
		    return x;
		} else {
		    SET_FLOAT_WORD(*iptr,i0&(~i));
		    return x - *iptr;
		}
	    }
	} else {			/* no fraction part */
	    u_int32_t ix;
	    *iptr = x*one;
	    GET_FLOAT_WORD(ix,x);
	    SET_FLOAT_WORD(x,ix&0x80000000);	/* return +-0 */
	    return x;
	}
}
