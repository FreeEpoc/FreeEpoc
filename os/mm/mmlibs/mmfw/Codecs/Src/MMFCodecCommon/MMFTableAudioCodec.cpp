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

#include "MMFTableAudioCodec.h"

/**
*
* Convert
* @param aSrc
* @param aDst
* @param aSamples
*/
 EXPORT_C void TMMFTableAudioCodec::Convert(TUint8* aSrc, TUint8* aDst, TInt aSamples)
	{
	if (iTablePtr)
		ConvertFast(aSrc,aDst,aSamples);
	else
		ConvertSlow(aSrc,aDst,aSamples);
	}
