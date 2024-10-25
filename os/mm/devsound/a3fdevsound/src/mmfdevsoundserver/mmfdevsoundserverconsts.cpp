// Copyright (c) 2006-2009 Nokia Corporation and/or its subsidiary(-ies).
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

#include <e32def.h>
#include <e32const.h>

#ifdef SYMBIAN_CURB_SYSTEMSERVER_PRIORITIES
	EXPORT_C extern const TInt KDevsoundServerPriority = EPriorityAbsoluteHigh;
#else
	EXPORT_C extern const TInt KDevsoundServerPriority = EPriorityAbsoluteRealTime1;
#endif

//end of file
