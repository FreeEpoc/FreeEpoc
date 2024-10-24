
// Copyright (c) 1999-2009 Nokia Corporation and/or its subsidiary(-ies).
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

#ifndef __PPM2Panic_h__
#define __PPM2Panic_h__

GLREF_C void Panic(TInt aError);

enum
	{
	EFrameNumberOutOfRange=1,
	EIllegalCall=2
	};

#endif // __PPM2Panic_h__
