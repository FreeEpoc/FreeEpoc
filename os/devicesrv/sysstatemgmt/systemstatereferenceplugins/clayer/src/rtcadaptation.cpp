// Copyright (c) 2007-2009 Nokia Corporation and/or its subsidiary(-ies).
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
// saartcadaptation.cpp
// 
//

#include "startupadaptationadapter.h"

/*
 * Exported function for DLL ordinal for creation of this adaptation class
 * 
 * @internalComponent
 */
EXPORT_C MRtcAdaptation* CreateRtcAdaptationL() //lint -esym(714, CreateRtcAdaptationL) Suppress symbol not referenced
{
	return CStartupAdaptationAdapter::NewRtcAdaptationL();
}
