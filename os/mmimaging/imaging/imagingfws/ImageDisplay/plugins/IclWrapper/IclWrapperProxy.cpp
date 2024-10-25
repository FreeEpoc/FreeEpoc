// Copyright (c) 2005-2009 Nokia Corporation and/or its subsidiary(-ies).
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

/** 	@file
	@internalComponent */
#include <ecom/ecom.h>
#include <ecom/implementationproxy.h>
#include <icl/imagedisplay.hrh>
#include <icl/exifimagedisplay.hrh>

#include "GenericIclWrapper.h"
#include "ExifImageDisplay.h"

// Exported proxy for instantiation method resolution

// Define the Implementation UIDs for Test transformer
const TImplementationProxy ImplementationTable[] =
	{
	IMPLEMENTATION_PROXY_ENTRY(KUidImageDisplayExifPluginImplUid, CExifImageDisplayPlugin::NewL),
	IMPLEMENTATION_PROXY_ENTRY(KUidImageDisplayIclWrapperPluginImplUid,	CGenericImageDisplayPlugin::NewL),
	};

EXPORT_C const TImplementationProxy* ImplementationGroupProxy(TInt& aTableCount)
	{
	aTableCount = sizeof(ImplementationTable) / sizeof(TImplementationProxy);
	return ImplementationTable;
	}

