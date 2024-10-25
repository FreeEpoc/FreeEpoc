// Copyright (c) 2003-2009 Nokia Corporation and/or its subsidiary(-ies).
// All rights reserved.
// This component and the accompanying materials are made available
// under the terms of "Eclipse Public License v1.0"
// which accompanies this distribution, and is available
// at the URL "http://www.eclipse.org/legal/epl-v10.html".
//
// Initial Contributors:
// Nokia Corporation - initial contribution.
//
// Contributors:
//
// Description:
//

#ifndef __GIFSCALERMAIN_H__
#define __GIFSCALERMAIN_H__


#include <e32std.h>

// Panic codes for the GifScaler.
enum TGifScalerPanic
	{
	ENoSourceBitmap,
	ENoSourceMaskBitmap,
	ENoDestinationBitmap,
	ENoDestinationMaskBitmap,
	EBadRequestStatus,
	EValueOutOfRange
	};

// Global panic fn. for the GifScaler.
GLDEF_C void Panic(TGifScalerPanic aError);

#endif  // __GIFSCALERMAIN_H__
