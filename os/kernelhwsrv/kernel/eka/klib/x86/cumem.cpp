// Copyright (c) 1997-2009 Nokia Corporation and/or its subsidiary(-ies).
// All rights reserved.
// This component and the accompanying materials are made available
// under the terms of the License "Eclipse Public License v1.0"
// which accompanies this distribution, and is available
// at the URL "http://www.eclipse.org/legal/epl-v10.html".
//
// Initial Contributors:
// Nokia Corporation - initial contribution.
//
// Contributors:
//
// Description:
// e32\klib\x86\cumem.cpp
// 
//

#include <x86.h>

extern "C" {


void kumemget_no_paging_assert(TAny* aKernAddr, const TAny* aAddr, TInt aLength)
	{
	kumemget(aKernAddr,aAddr,aLength);
	}


void kumemput_no_paging_assert(TAny* aAddr, const TAny* aKernAddr, TInt aLength)
	{
	kumemput(aAddr,aKernAddr,aLength);
	}


}
